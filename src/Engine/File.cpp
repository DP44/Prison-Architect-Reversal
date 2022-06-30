#include "File.h"
#include "Unknown.h"

File::File()
{
    _vtbl = &File_VTABLE;
    m_handle = NULL;
    m_handleType = 0;

    field_0x1e = 0;
    field1039_0x420 = 0;
    field_0x1a = 0;
    field_0x10 = 0;
    field_0x18 = 0;
    field_0x19 = 0;
    *(undefined4 *)&this[4].field_0x390 = 0;
    field_0x1d = 0;
    field_0x1b = 1;
    *(undefined4 *)&this[4].field_0x394 = 0;
    field_0x1c = 1;
}

File::~File()
{
    _vtbl = &File_VTABLE;

    if ((m_handle != NULL) && (field_0x18 == '\0'))
    {
        if (field_0x1a == '\0')
        {
            this->Close();
            return;
        }

        if ((m_handleType == 0) && (field_0x1b != '\0'))
        {
            FUN_00e1ac90();
        }
    }
}

void File::AddFileToList(_IO_FILE *a1)
{
    int iVar1;
    long *plVar2;

    if (a1 != NULL)
    {
        if (DAT_014bdf80 == 0)
        {
            iVar1 = 0;
        LAB_00e1aae2:
            (&DAT_014bdf80)[iVar1] = (long)this;
            return;
        }

        plVar2 = &DAT_014bdf88;
        iVar1 = 1;

        do
        {
            if (*plVar2++ == 0)
            {
                goto LAB_00e1aae2;
            }

            iVar1++;
        }
        while (iVar1 != 32);
    }
}

void File::PutByte(unsigned char byte);
{
    unsigned char local_c[12];

    local_c[0] = byte;
    FUN_00e1a5e0(this, local_c, 1);
}

int8_t File::Create(const char *a1, const wchar_t *a2)
{
    int iVar1;
    FILE *pFVar2;
    unsigned long uVar3;
    long *plVar4;

    m_handle = fopen(a1, "w+");
    field_0x1a = 1;
    m_handleType = 0;
    field_0x18 = 0;

    if (a2 == NULL)
    {
        field1039_0x420 = 0;
    }
    else
    {
        strcpyw((wchar_t *)&field1039_0x420, a2);
    }
    
    if (a1 == NULL)
    {
        uVar3 = WideToChar(a2, &field_0x1e, 0x10000000);
    }
    else
    {
        uVar3 = __strcpy_chk(&field_0x1e, a1, 0x400);
    }

    m_handle = m_handle;

    if (m_handle != NULL)
    {
        if (DAT_014bdf80 == 0)
        {
            iVar1 = 0;
        LAB_00e1aa62:
            uVar3 = (unsigned long)iVar1;
            (&DAT_014bdf80)[uVar3] = (long)this;
        }
        else
        {
            plVar4 = &DAT_014bdf88;
            uVar3 = 1;
            
            do
            {
                iVar1 = (int)uVar3;
                
                if (*plVar4++ == 0)
                {
                    goto LAB_00e1aa62;
                }

                uVar3 = (unsigned long)(iVar1 + 1U);
            }
            while (iVar1 + 1U != 32);
        }
    }

    return uVar3 & 0xFFFFFFFFFFFFFF00 | (unsigned long)(m_handle != NULL);
}

bool File::GetByte()
{
    // TODO
    return false;
}

void File::SetCloseFileTime(RarTime *a1, RarTime *a2)
{
    SetCloseFileTimeByName(&field_0x1e, a1, a2);
}

unsigned long File::IsDevice()
{
    int iVar1;

    if (m_handle != NULL)
    {
        iVar1 = fileno(m_handle);
        iVar1 = isatty(iVar1);
        return CONCAT44(extraout_var, iVar1) & 0xFFFFFFFFFFFFFF00 | (unsigned long)(iVar1 != 0);
    }

    return 0;
}

void File::Tell()
{
    ftello(m_handle);
}

void File::operator=(File *rhs)
{
    m_handle = rhs->m_handle;
    __strcpy_chk(&field_0x1e, &rhs->field_0x1e, 0x400);
    field_0x1a = rhs->field_0x1a;
    field_0x10 = rhs->field_0x10;
    m_handleType = rhs->m_handleType;
    rhs->field_0x18 = 1;
    return;
}

unsigned long File::DirectRead(void *a1, int a2)
{
    char cVar1;
    FILE *handle = stdin;
    
    if (this->m_handleType == 1)
    {
        cVar1 = this->field_0x10;
        this->m_handle = stdin;
    }
    else
    {
        cVar1 = this->field_0x10;
        handle = this->m_handle;
    }

    if (cVar1 == '\0')
    {
        clearerr(handle);
        handle = this->m_handle;
    }
    else
    {
        fflush(handle);
        this->field_0x10 = 0;
        clearerr(this->m_handle);
        handle = this->m_handle;
    }

    size_t fread_result = fread(a1, 1, (long)a2, handle);
    int errcode = ferror(this->m_handle);

    return errcode == 0 ? fread_result & 0xFFFFFFFF : 0xFFFFFFFF;
}

unsigned long File::RawSeek(long long a1, int a2)
{
    int iVar1;
    int extraout_var;
    FILE *__stream;

    __stream = m_handle;
    
    if (__stream != NULL)
    {
        if ((a1 < 0) && (a2 != 0))
        {
            __stream = m_handle;
            a1 += a2 == 1 ? ftello(__stream) : this->FileLength();
            a2 = 0;
        }

        field_0x10 = 0;
        iVar1 = fseeko(__stream, a1, a2);
        return CONCAT44(extraout_var, iVar1) & 0xffffffffffffff00 | (unsigned long)(iVar1 == 0);
    }

    return 1;
}

__off_t File::FileLength()
{
    // TODO
    return -1;
}

unsigned long File::WCreate(const char *a1, const wchar_t *a2)
{
    unsigned long result = this->Create(a1, a2);

    if (!result)
    {
        ErrorHandler::SetErrorCode((ErrorHandler *)ErrHandler, 9);
        ErrorHandler::CreateErrorMsg(ErrHandler);
        result &= 0xFF;
    }

    return result;
}

void File::SetCloseFileStat(RarTime *a1, RarTime *a2, unsigned int a3);
{
    SetCloseFileTimeByName(&field_0x1e, a1, a2);
    chmod(&field_0x1e, a3);
    return;
}

int8_t File::Delete()
{
    if (m_handleType == 0 && !field_0x1b)
    {
        return FUN_00e1ac90();
    }

    return 0;
}

void File::SetHandleType(FILE_HANDLETYPE newtype)
{
    m_handleType = newtype;
}

bool File::Open(const char *a1, const wchar_t *a2, bool a3, bool a4)
{
    // TODO
    return false;
}

int8_t File::Rename(const char *a1);
{
    char *__s1 = &field_0x1e;

    if (strcmp(__s1, a1) != 0)
    {
        if (rename(__s1, a1) != 0)
        {
            return 0;
        }
    }

    __strcpy_chk(__s1, a1, 0x400);
    field1039_0x420 = 0;
    return 1;
}

void File::GetOpenFileTime(RarTime *a1)
{
    int __fildes = fileno(m_handle);

    stat sStack168;
    __fxstat(1, __fildes, &sStack168);

    a1 = sStack168.st_mtim.tv_sec;
}

void File::Write(const void *a1, int a2)
{
    if (a2 != 0)
    {
        FUN_00e1a5e0();
    }
}

bool File::WOpen(const char *a1, const wchar_t *a2)
{
    bool result;

    result = this->Open(a1, a2, false, false);

    if (!result)
    {
        ErrorHandler::OpenErrorMsg(ErrHandler);
    }

    return result;
}