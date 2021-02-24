#include<define.h>
#include<basedatatype.h>
#include<tianyuvm/tvmcpu.h>
#include<tianyufile/tyexestruct.h>
#include<tianyufile/tyexepredefine.h>
#include<tianyufile/tyfile.h>

#include"tvmsysreal.h"
#include"tvmcpureal.h"

#include<map>
#include<string>
#include<iostream>

#define __TVMS_THREAD__ tianyuvm_thread

#define __LIB__	tianyuvm_thread_lib

namespace __TVMS_THREAD__
{
	namespace __LIB__
	{
		class LibraryItem
		{
			_Private std::map<std::string, TYTableItem>	__VAR__ Symbols;
			_Private byte								__PTR__ VarRaw;
			_Private int32								__VAR__ Refences;

			_Public LibraryItem
			(
				__IN_Param__ TYYFilePackage __PTR__ file
			) :Symbols(), VarRaw(null), Refences(0)
			{
				if (null == file)
				{
					VarRaw = new byte[0];
					return;
				}
				Load(file);
			}
			_Public ~LibraryItem()
			{
				delete[] VarRaw;
			}

			_Private void __VAR__ Load
			(
				__IN_Param__ TYYFilePackage __PTR__ file
			)
			{
				bool __VAR__ error = false;
				// 完成数据读取
				try
				{
					VarRaw = file->ReadFile();
					for (int i = 0; i < file->GetSignsCount(); ++i)
					{
						TYTableItem __REF__ temp = file->GetSignItem(i);

						Symbols.insert({ std::string(file->GetStringTable() + temp.StringIndex), temp });
					}
				}
				catch (std::exception)
				{
					error = true;
				}

				// 进行代码数据的重定位
				if (!error)
				{
					for (auto it = Symbols.begin(); it != Symbols.end(); ++it)
					{
						TYTableItem __REF__ temp = it->second;

						uint64 __VAR__ rel_count = BytesToUint64(VarRaw + temp.ItemLocation, 8);

						if (0 < rel_count)
						{
							uint64 __VAR__ locate = temp.ItemLocation + temp.ItemLength + 8;

							for (uint64 i = 0; i < rel_count; ++i)
							{
								uint64 __VAR__ offset = i * __TianyuRelocationItem_Struct_Length__;
								TYRelocationItem __VAR__ rel;
								rel.Type = VarRaw[locate + offset + 0];
								rel.State = VarRaw[locate + offset + 1];
								rel.LocateLength = VarRaw[locate + offset + 2];

								rel.Offset = BytesToUint64(VarRaw + locate + offset + 3, 8);
								rel.StringIndex = BytesToUint64(VarRaw + locate + offset + 11, 8);

								if (__TianyuRelocateTableGroup_State_ABS__ == rel.State)
								{
									std::string __VAR__ sign(file->GetStringTable() + rel.StringIndex);
									auto iter = Symbols.find(sign);
									if (Symbols.end() != iter)
										Uint64ToBytes
										(
											iter->second.ItemLocation + (uint64)VarRaw,
											VarRaw + temp.ItemLocation + rel.Offset,
											rel.LocateLength
										);
									else
									{
										std::cout << "无法定位的符号：" << sign << std::endl;
										error = true;
									}
								}
							}
						}
					}
				}

				Symbols.clear();
				Refences = 0;
				delete[] VarRaw;
			}

			_Public void	__VAR__ LoadLib() { ++Refences; }
			_Public void	__VAR__ UnloadLib() { --Refences; }
			_Public int32	__VAR__ Refence() { return Refences; }
			_Public uint64	__VAR__ LoadSymbol
			(
				__IN_Param__ std::string __VAR__ sym
			)
			{
				auto iter = Symbols.find(sym);
				if (Symbols.end() != iter)
					return iter->second.ItemLocation + (uint64)VarRaw;
				return -1;
			}
		};

		class Librarys
		{
			_Private uint64						   __VAR__ LibraryCodeTemp;
			_Private std::map<std::string, uint64> __VAR__ LibraryCode;
			_Private std::map<uint64, LibraryItem> __VAR__ Items;

			_Public Librarys()
				: LibraryCodeTemp(0), LibraryCode(), Items()
			{

			}
			_Public ~Librarys() {  }

			_Public uint64 __VAR__ LoadFile
			(
				__IN_Param__ std::string __VAR__ path
			)
			{
				CStructString __PTR__ cpath = CreateCStructStringFromChars
				(
					const_cast<char __PTR__>(path.c_str()),
					path.length
				);
				TYYFilePackage __VAR__ file(cpath);
				DestroyCStructString(cpath);

				if (__TYEXEFILE_STATE_OK__ == file.GetFileState())
				{
					LibraryCode.insert({ path, LibraryCodeTemp });
					Items.insert({ LibraryCodeTemp, LibraryItem(__V_To_P__ file) });
					return LibraryCodeTemp++;
				}

				if (__TYEXEFILE_STATE_FERR__ == file.GetFileState())
				{
					std::cout << "无法打开文件：" << path << std::endl;
					std::cout << "\t请检查文件是否存在并且可读" << std::endl;
					return 0;
				}
				else
				{
					std::cout << "无法解析的文件：" << path << std::endl;
					std::cout << "\t请检查文件格式是否正确" << std::endl;
					return 0;
				}
			}
			_Public void  __VAR__ UnloadFile
			(
				__IN_Param__ uint64		 __VAR__ lib_code
			) 
			{
				std::map<uint64, LibraryItem>::iterator item = Items.find(lib_code);
				if (Items.end() != item)
				{
					item->second.UnloadLib();
					if (0 >= item->second.Refence())
					{
						Items.erase(item);
						for (auto it = LibraryCode.begin(); it != LibraryCode.end(); ++it)
						{
							if (it->second == lib_code)
							{
								LibraryCode.erase(it);
								break;
							}
						}
					}
				}
			}
			_Public uint64 __VAR__ LoadFunc
			(
				__IN_Param__ uint64		 __VAR__ lib_code,
				__IN_Param__ std::string __VAR__ func
			)
			{
				std::map<uint64, LibraryItem>::iterator item = Items.find(lib_code);
				if (Items.end() != item)
					return item->second.LoadSymbol(func);
				return 0;
			}
		};
	}

	__LIB__::Librarys __VAR__ LoadLibrarys;
}

#ifdef __cplusplus
__C__
{
#endif // __cplusplus

extern PTW32_DLLPORT int PTW32_CDECL pthread_create
(
	pthread_t* tid,
	const pthread_attr_t* attr,
	void* (PTW32_CDECL* start) (void*),
	void* arg
);

extern void		__VAR__ Interrupt_CreateThread
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ mem
)
{
	byte __PTR__ stack = (byte __PTR__)malloc(sizeof(byte) * 4194304);
	CPU __PTR__ excpu = CreateCPU(sys, 0, 0, mem, (uint64)stack, 4194304);

	pthread_create
	(
		__V_To_P__((TVMCPU __PTR__)excpu)->Thread, 
		null, 
		ExcuteEnter, 
		excpu
	);
}
extern uint64	__VAR__ Interrupt_LoadLibrary
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ lib_path
)
{
	if (0 != lib_path)
	{
		char __PTR__ c_str = (char __PTR__)lib_path;
		try
		{
			std::string path(c_str);

			return __TVMS_THREAD__::LoadLibrarys.LoadFile(path);
		}
		catch (std::exception)
		{
			return 0;
		}
	}
	return 0;
}
extern void 	__VAR__ Interrupt_UnloadLibrary
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ lib
)
{
	__TVMS_THREAD__::LoadLibrarys.UnloadFile(lib);
}
extern uint64	__VAR__ Interrupt_LoadFunc
(
	TVMSystem	__PTR__ sys,
	uint64		__VAR__ lib
)
{
	if (0 != lib)
	{
		char __PTR__ c_str = (char __PTR__)BytesToUint64
		(
			(byte __PTR__)lib,
			8
		);
		try
		{
			std::string func(c_str);

			return __TVMS_THREAD__::LoadLibrarys.LoadFunc
			(
				BytesToUint64
				(
					(byte __PTR__)(lib + 8),
					8
				),
				func
			);
		}
		catch (std::exception)
		{
			return 0;
		}
	}
	return 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus