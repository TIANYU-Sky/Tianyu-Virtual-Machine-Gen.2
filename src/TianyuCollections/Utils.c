#include<tianyufile/tyfile.h>
#include<tianyufile/tyexepredefine.h>

byte __VAR__ TYGetFileType
(
    CStructString __PTR__ str
    )
{
    char __PTR__ extension = str->String(str);
    byte __VAR__ result = TianyuFile_NON;
    int __VAR__ index = 1;
    int __VAR__ state = 0;
    while (index < str->Length(str))
    {
        switch (state)
        {
        case 0:
            if ('t' == extension[index] || 'T' == extension[index])
                state = 1;
            else
                goto over_label;
            break;

        case 1:
            if ('y' == extension[index] || 'Y' == extension[index])
                state = 2;
            else
                goto over_label;
            break;

        case 2:
            switch (extension[index])
            {
            case 'm':case 'M':
                result = TianyuFile_TYM;
                break;
            case 'l':case 'L':
                result = TianyuFile_TYL;
                break;
            case 'y':case 'Y':
                result = TianyuFile_TYY;
                break;
            case 'k':case 'K':
                result = TianyuFile_TYK;
                break;
            case 'd':case 'D':
                result = TianyuFile_TYD;
                break;
            default:
                break;
            }
            state = 3;
            break;

        case 3:
            result = TianyuFile_NON;
            goto over_label;
            break;

        default:
            break;
        }
        ++index;
    }

over_label:
    return result;
}

TYFileInfo   __VAR__ TYGetFileInfo
(
    CStructString __PTR__ file
    )
{
    TYFileInfo __VAR__ info;
    info.FileType = TianyuFile_NON;
    info.FullName = null;
    info.Extension = null;
    info.FileName = null;
    info.Directory = null;
    info.Root = null;

    if (!file->IsNull(file))
    {
        info.FullName = CreateCStructStringFromCSS(file);

        char __PTR__ str = file->String(file);
        int32 __VAR__ index = file->Length(file) - 1;

        // 读取后缀名
        for (; index >= 0; --index)
        {
            if ('.' == str[index])
            {
                info.Extension = CreateCStructStringFromCharsIndex
                (
                    str,
                    index,
                    file->Length(file)
                    );
                info.FileType = TYGetFileType(info.Extension);
                break;
            }
            else if ('/' == str[index] || '\\' == str[index])
                break;
        }

        // 读取文件名
        for (; index >= 0; --index)
        {
            if ('/' == str[index] || '\\' == str[index])
                break;
        }
        info.FileName = CreateCStructStringFromCharsIndex
        (
            str,
            index + 1,
            file->Length(file)
            );

        if ('/' == str[index] || '\\' == str[index])
        {
            info.Root = CreateCStructStringFromChars(str, index);

            int i = index - 1;
            for (; i >= 0; --i)
            {
                if ('/' == str[i] || '\\' == str[i])
                    break;
            }
            info.Directory = CreateCStructStringFromCharsIndex
            (
                str,
                i + 1,
                index
                );
        }
    }

    if (null == info.FullName)
        info.FullName = CreateCStructString();
    if (null == info.Extension)
        info.Extension = CreateCStructString();
    if (null == info.FileName)
        info.FileName = CreateCStructString();
    if (null == info.Directory)
        info.Directory = CreateCStructString();
    if (null == info.Root)
        info.Root = CreateCStructString();

    return info;
}