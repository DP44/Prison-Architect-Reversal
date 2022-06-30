// #include "PrisonArchitectLinux.h"
#include "Math.h"
#include "Utils.h"

class Node
{
public:
    Vector3 m_position;
    char gap_14[4];
    FastList<int> m_18;
    FastList<int> m_28;

    Node();
    virtual ~Node();
    virtual ~Node();

    virtual void Copy(Node *other);
    virtual void Read(Directory *directory);
    virtual void Write(Directory *directory);
};

class Edge
{
public:
    int m_node1, m_node2;
    int m_sector1, m_sector2;
    float m_thickness;
    bool m_validSectorEdge;
    char gap_1d[3];
    // Directory m_20;

    Edge()
    {
        m_node1 = -1;
        m_node2 = -1;
        m_sector1 = -1;
        m_sector2 = -1;
        m_thickness = 0f;
        m_validSectorEdge = true;
        m_20 = new Directory();
    }

    virtual ~Edge();
    virtual ~Edge();

    virtual void Copy(Edge *other);
    virtual void Clone(Edge *other);
    virtual void Read(Directory *directory);
    virtual void Write(Directory *directory);
};

class SectorNode
{
public:
    int m_nodeId;
    Vector3 m_offset;
    bool m_fake;
    
    SectorNode();

    virtual void Copy(SectorNode *other);
    virtual void Read(Directory *directory);
    virtual void Write(Directory *directory);
};

class NodeGridSector
{
public:
    FastList<SectorNode *> m_nodes;
    FastList<int> m_subSectors;
    Vector3 m_center;
    Vector3 m_34;
    Vector3 m_40;
    bool m_outer;
    bool m_convex;
    bool m_4e;
    bool m_4f;

    NodeGridSector();
    ~NodeGridSector();
};

class NodeGrid
{
public:
    DArray<Node *> m_nodes;
    DArray<Edge *> m_edges;
    DArray<NodeGridSector *> m_sectors;
    DArray<NodeGridSector *> m_50;
    int m_68;
    char gap_6c[4];

    NodeGrid();
    ~NodeGrid();
    
    bool IsOuterEdge(int edgeIndex);
    int LookupEdgeId(int a1, int a2);
    float GetEdgeLength(int edgeIndex);
    void GetNearestNode(const Vector3 &pos, float out_closestDist, int out_nodeId);
};