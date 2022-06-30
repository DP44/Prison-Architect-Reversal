template <typename T> class HashTable
{
public:
    ~HashTable();

    void Grow();
    void Rebuild();

    void Empty();
    void EmptyAndDelete();
    
    unsigned long GetInsertPos(const char *a1, char **a2, unsigned int a3);
    unsigned long PutData(const char *a1, T *a2);
    unsigned long GetIndex(const char *a1);
};