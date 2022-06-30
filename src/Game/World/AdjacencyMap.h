class AdjacencyMap
{
private:
    void *m_fastlist_0x0 = NULL;
    int m_fastlist_0x8 = 0;
    int m_fastlist_length = 0;
    int m_numVertices = 0;

public:
    AdjacencyMap();

    void Connect(int a1, int a2);
    void Initialise(int numVertices);
    
    const int NumVertices();
    const bool IsAdjacent(int a1, int a2);
    const void DebugPrint();
};