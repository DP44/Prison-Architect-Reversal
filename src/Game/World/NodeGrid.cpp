#include "NodeGrid.h"

int NodeGrid::LookupEdgeId(int a1, int a2)
{
    for (int i = 0; i < m_edges.size; i++)
    {
        Edge *edge = m_edges.items[i];

        if ((edge->m_node1 == a1 && edge->m_node2 == a2) ||
            (edge->m_node2 == a1 && edge->m_node1 == a2))
        {
            return i;
        }
    }

    return -1;
}

bool NodeGrid::IsOuterEdge(int edgeIndex)
{
    // TODO: Reverse engineer sanity checks.
    return m_edges.items[edgeIndex]->m_outer;
}

int NodeGrid::LookupEdgeId(int a1, int a2)
{
    for (int i = 0; i < m_edges.size; i++)
    {
        Edge *edge = m_edges.items[i];

        if (edge->m_node1 == a1 && edge->m_node2 == a2)
        {
            return i;
        }

        if (edge->m_node2 == a1 && edge->m_node1 == a2)
        {
            return i;
        }
    }
    
    return -1;
}

float NodeGrid::GetEdgeLength(int edgeIndex)
{
    // Check for invalid index values.
    if (edgeIndex > m_edges.size || edgeIndex < -1)
    {
        return -1f;
    }

    Edge *edge = m_edges.items[edgeIndex];

    if ((edge->m_node1 < -1 || edge->m_node1 > m_nodes.size) ||
        (edge->m_node2 < -1 || edge->m_node2 > m_nodes.size))
    {
        return -1f;
    }

    Vector3 firstNodePosition = m_nodes.items[edge->m_node1]->m_position;
    Vector3 secondNodePosition = m_nodes.items[edge->m_node2]->m_position;
    
    Vector3 diff = new Vector3(
        firstNodePosition.x - secondNodePosition.x,
        firstNodePosition.y - secondNodePosition.y,
        firstNodePosition.z - secondNodePosition.z,
    )

    return diff.Mag();
}

void NodeGrid::GetNearestNode(const Vector3 &pos, float out_closestDist, int out_nodeId)
{
    for (int i = 0; i < m_nodes.size; i++)
    {
        Node *node = m_nodes.items[i];

        float xdiff = node->m_position.x - pos.x;
        float zdiff = node->m_position.z - pos.z;

        float dist = fsqrt((zdiff * zdiff) + (xdiff * xdiff));

        if (out_nodeId != i && dist <= out_closestDist)
        {
            out_closestDist = dist;
            out_nodeId = i;
        }
    }
}