template <typename T>
class Array
{
public:
    T *field0_0x0;
    int field1_0x8;
    int size;

    Array(int a1);
};

template <typename T>
class DArray
{
public:
    int m_0;    
    int size;          // offset=0x4, len=0x4
    T *items;          // offset=0x8, len=0x8
    T *current;        // offset=0x10, len=0x8
};

template <typename T>
class FastDArray
{
public:
    DArray<T> __DArray;
    int field4_0x18;
    int field5_0x1c;
    T *field6_0x20;
    int field7_0x28;
};

template <typename T>
class LList
{
public:
    T *m_0;
    T *m_8;
    int field2_0x10;
    int size;

    void Empty();
    void RemoveData(int a1);
    void PutDataAtEnd(const T &a1);
};

template <typename T>
class FastList
{
public:
    T *__first_item;
    int m_8;
    int size; // 0xc

    ~FastList() {}

    void Empty();
    void EmptyAndDelete();

    void EnsureSpace();
    void EnsureSpace(int a1);

    int PutDataAtIndex(const T &data, int index);
    unsigned int PutDataUnique(const T &a1);

    void Append(const FastList<T> &a1);
    void Copy(const FastList<T> &a1);
    void MoveLeft(int a1);

    const int FindData(const T &a1);
};

template <typename T, typename U>
void CopyMatching(const FastList<T> &a1, const FastList<T> &a2, U a3)
{
    // TODO
}

namespace Utils
{
    bool IsLeapYear(int year);
}