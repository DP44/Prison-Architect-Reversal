#include "Unknown.h"
#include "AdjacencyMap.h"

AdjacencyMap::AdjacencyMap()
{
    m_fastlist_0x0 = NULL;
    m_fastlist_0x8 = 0;
    m_fastlist_length = 0;
    m_numVertices = 0;
}

void AdjacencyMap::Connect(int a1, int a2)
{
    *(int *)((long)m_fastlist_0x0 + (long)(a2 + a1 * m_numVertices)) = 1;
}

const int AdjacencyMap::NumVertices()
{
    return m_numVertices;
}

const bool AdjacencyMap::IsAdjacent(int from, int to)
{
    int vertexCount = m_numVertices;

    if (from < 0 || to < 0 || vertexCount <= to || from >= vertexCount)
    {
        AppDebugOut("Failed assertion, to = %d, from = %d, m_numVertices = %d\n", to, from, vertexCount);
        // vertexCount = m_numVertices;
    }
    
    return *(m_fastlist_0x0 + from * vertexCount + to);
}

const void AdjacencyMap::DebugPrint()
{
    if (0 < m_numVertices)
    {
        for (int i = 0; m_numVertices != i && i <= m_numVertices; i++)
        {
            for (int j = 0; m_numVertices != j && j <= m_numVertices; j++)
            {
                AppDebugOut("%c ", IsAdjacent(this, i, j) == 0 ? 32 : 88);
            }

            AppDebugOut("\n");
        }
    }
}

void AdjacencyMap::Initialise(int numVertices)
{
    /*
    void *pvVar1;
    int iVar2;
    void *pvVar3;
    int vertexCountSqr;
    long lVar4;
    unsigned long uVar5;

    vertexCountSqr = numVertices * numVertices;
    iVar2 = m_fastlist_0x8;
    m_numVertices = numVertices;
    m_fastlist_length = vertexCountSqr;
    
    if (vertexCountSqr < iVar2)
    {
        goto cleanup;
    }

    if (iVar2 < 10)
    {
        if (9 < vertexCountSqr)
        {
            iVar2 = 10;
            goto jmp_to_loop;
        }

        uVar5 = 10;
        iVar2 = 10;
    }
    else
    {
    jmp_to_loop:
        while (iVar2 <= vertexCountSqr)
        {
            iVar2 *= 2;
        }

        uVar5 = (unsigned long)iVar2;
    }

    pvVar3 = operator.new[](uVar5);
    pvVar1 = m_fastlist_0x0;

    if (pvVar1 != NULL)
    {
        vertexCountSqr = m_fastlist_0x8;
        lVar4 = 0;
        
        if (0 < vertexCountSqr)
        {
            do
            {
                *(undefined *)((long)pvVar3 + lVar4) = *(undefined *)((long)pvVar1 + lVar4);
                lVar4 += 1;
            } while ((int)lVar4 < vertexCountSqr);
        }
        operator.delete[](pvVar1);
    }
    vertexCountSqr = m_fastlist_length;
    m_fastlist_0x0 = pvVar3;
    m_fastlist_0x8 = iVar2;

cleanup:
    if (vertexCountSqr == 0)
    {
        return;
    }

    memset(m_fastlist_0x0, 0, (long)numVertices * (long)numVertices);
    return;
    */
}