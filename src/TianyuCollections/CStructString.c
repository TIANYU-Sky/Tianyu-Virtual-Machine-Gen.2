#include<define.h>
#include<basedatatype.h>
#include<string.h>

typedef struct redefine_cstruct_string
{
    CStructString __VAR__ Base;

    char          __PTR__ _String;
    int32         __VAR__ _Length;
}StructString;

int32   __VAR__ CStructString_GetLength
(
    struct c_struct_string  __PTR__ str
    )
{
    if (null == str)
        return __C_STRUCT_STRING_INVAILD_LENGTH__;

    return ((StructString __PTR__)str)->_Length;
}
char    __PTR__ CStructString_GetString
(
    struct c_struct_string  __PTR__ str
    )
{
    if (null == str)
        return "";

    return null == ((StructString __PTR__)str)->_String ? "" : ((StructString __PTR__)str)->_String;
}
bool   __VAR__ CStructString_SetString
(
    struct c_struct_string  __PTR__ str,
    char                    __PTR__ cstr,
    int32                   __VAR__ length
    )
{
    if (null == str)
        return false;

    if (null == cstr || 0 > length)
        return false;

    StructString __PTR__ nstr = (StructString __PTR__)str;
    
    free(nstr->_String);
    nstr->_Length = '\0' == cstr[length - 1] ? length - 1 : length;
    nstr->_String = (char __PTR__)malloc((uint32)sizeof(char) * (nstr->_Length + 1));

    if (null == nstr->_String)
        return false;

    for (int i = 0; i < nstr->_Length; ++i)
        nstr->_String[i] = cstr[i];
    nstr->_String[nstr->_Length] = '\0';

    return true;
}
bool   __VAR__ CStructString_IsNull
(
    struct c_struct_string  __PTR__ str
    )
{
    if (null == str)
        return true;

    return null == ((StructString __PTR__)str)->_String || 0 == ((StructString __PTR__)str)->_Length;
}

CStructString __PTR__ CreateCStructString()
{
    StructString __PTR__ str = (StructString __PTR__)malloc(sizeof(StructString));

    if (null != str)
    {
        str->_String = null;
        str->_Length = 0;

        str->Base.IsNull = CStructString_IsNull;
        str->Base.Length = CStructString_GetLength;
        str->Base.Set = CStructString_SetString;
        str->Base.String = CStructString_GetString;
    }

    return (CStructString __PTR__)str;
}
CStructString __PTR__ CreateCStructStringFromCSS
(
    CStructString __PTR__ cstr
    )
{
    StructString __PTR__ nstr = (StructString __PTR__)malloc(sizeof(StructString));

    if (null != nstr)
    {
        nstr->Base.IsNull = CStructString_IsNull;
        nstr->Base.Length = CStructString_GetLength;
        nstr->Base.Set = CStructString_SetString;
        nstr->Base.String = CStructString_GetString;

        nstr->_String = null;
        nstr->_Length = 0;

        if (null != cstr)
        {
            nstr->_Length = cstr->Length(cstr);
            nstr->_String = (char __PTR__)malloc((uint32)sizeof(char) * (nstr->_Length + 1));

            char __PTR__ temp = cstr->String(cstr);
            if (null != nstr->_String)
            {
                for (int i = 0; i < nstr->_Length; ++i)
                    nstr->_String[i] = temp[i];
                nstr->_String[nstr->_Length] = '\0';
            }
        }
    }

    return (CStructString __PTR__)nstr;
}
CStructString __PTR__ CreateCStructStringFromChars
(
    char    __PTR__ str,
    int32   __VAR__ length
    )
{
    StructString __PTR__ nstr = (StructString __PTR__)malloc(sizeof(StructString));

    if (null != str)
    {
        nstr->Base.IsNull = CStructString_IsNull;
        nstr->Base.Length = CStructString_GetLength;
        nstr->Base.Set = CStructString_SetString;
        nstr->Base.String = CStructString_GetString;

        nstr->_String = null;
        nstr->_Length = 0;

        if (null != str)
        {
            nstr->_Length = '\0' == str[length - 1] ? length - 1 : length;
            nstr->_String = (char __PTR__)malloc((uint32)sizeof(char) * (nstr->_Length + 1));

            if (null != nstr->_String)
            {
                for (int i = 0; i < nstr->_Length; ++i)
                    nstr->_String[i] = str[i];
                nstr->_String[nstr->_Length] = '\0';
            }
        }
    }

    return (CStructString __PTR__)nstr;
}
CStructString __PTR__ CreateCStructStringFromCharA
(
    char    __VAR__ str[],
    int32   __VAR__ length
    )
{
    StructString __PTR__ nstr = (StructString __PTR__)malloc(sizeof(StructString));

    if (null != str)
    {
        nstr->Base.IsNull = CStructString_IsNull;
        nstr->Base.Length = CStructString_GetLength;
        nstr->Base.Set = CStructString_SetString;
        nstr->Base.String = CStructString_GetString;

        nstr->_String = null;
        nstr->_Length = 0;

        if (null != str)
        {
            nstr->_Length = '\0' == str[length - 1] ? length - 1 : length;
            nstr->_String = (char __PTR__)malloc((uint32)sizeof(char) * (nstr->_Length + 1));

            if (null != nstr->_String)
            {
                for (int i = 0; i < nstr->_Length; ++i)
                    nstr->_String[i] = str[i];
                nstr->_String[nstr->_Length] = '\0';
            }
        }
    }

    return (CStructString __PTR__)nstr;
}
CStructString __PTR__ CreateCStructStringFromCharsIndex
(
    char    __PTR__ str,
    int32   __VAR__ index,
    int32   __VAR__ length
    )
{
    StructString __PTR__ nstr = (StructString __PTR__)malloc(sizeof(StructString));

    if (null != str)
    {
        nstr->Base.IsNull = CStructString_IsNull;
        nstr->Base.Length = CStructString_GetLength;
        nstr->Base.Set = CStructString_SetString;
        nstr->Base.String = CStructString_GetString;

        nstr->_String = null;
        nstr->_Length = 0;

        if (null != str && 0 <= index && index < length)
        {
            nstr->_Length = '\0' == str[length - 1] ? length - index - 1 : length - index;
            nstr->_String = (char __PTR__)malloc((uint32)sizeof(char) * (nstr->_Length + 1));

            if (null != nstr->_String)
            {
                for (int i = 0; i < nstr->_Length; ++i)
                    nstr->_String[i] = str[i + index];
                nstr->_String[nstr->_Length] = '\0';
            }
        }
    }

    return (CStructString __PTR__)nstr;
}

void          __VAR__ DestroyCStructString
(
    CStructString __PTR__ cstr
    )
{
    if (null != cstr)
        free((StructString __PTR__)cstr);
}