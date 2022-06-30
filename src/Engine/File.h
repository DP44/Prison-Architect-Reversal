#include "PrisonArchitectLinux.h"

class File
{
private:
    void **_vtbl;

    FILE *m_handle;
    FILE_HANDLETYPE m_handleType;

public:
    File();
    ~File();

    void AddFileToList(_IO_FILE *a1);
    void PutByte(unsigned char byte);
    unsigned long Create(const char *a1, const wchar_t *a2);
    unsigned char GetByte();
    void SetCloseFileTime(RarTime *a1, RarTime *a2);
    unsigned long IsDevice();
    void Tell();
    void operator=(File &rhs);
    unsigned long DirectRead(void *a1, int a2);
    unsigned long RawSeek(long long a1, int a2);
    __off_t FileLength();
    unsigned long WCreate(const char *a1, const wchar_t *a2);
    void SetCloseFileStat(RarTime *a1, RarTime *a2, unsigned int a3);
    int8_t Delete();
    void SetHandleType(FILE_HANDLETYPE a1);
    bool Open(const char *a1, const wchar_t *a2, bool a3, bool a4);
    int8_t Rename(const char *a1);
    void GetOpenFileTime(RarTime *a1);
    void Write(const void *a1, int a2);
    bool WOpen(const char *a1, const wchar_t *a2);
    int Read(void *a1, int a2);
    void TOpen(const char *a1, const wchar_t *a2);
    void Flush();
    void TCreate(const char *a1, const wchar_t *a2);
    long Copy(File &original, long long a2);
    void Seek(long long a1, int a2);
    int8_t Close();
};

namespace _File
{
    void fprintf(const char *msg, ...);

    void Prealloc(long long a1);
    void Truncate();
    void SetCloseFileTimeByName(const char *a1, RarTime *a2, RarTime *a3);
    void RemoveCreated();
    void SetOpenFileTime(RarTime *a1, RarTime *a2, RarTime *a3);
    void SetOpenFileStat(RarTime *a1, RarTime *a2, RarTime *a3);
}