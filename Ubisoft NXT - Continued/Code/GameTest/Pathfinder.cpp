#include "stdafx.h"

#include "Pathfinder.h"
#include "SimpleTileMap.h"

Pathfinder::Pathfinder(CSimpleTileMap* tileMap, int mapSize)
{
    m_TileMap = tileMap;
    m_NumNodes = mapSize * mapSize;

    m_Nodes = new Node[m_NumNodes];
    m_OpenNodes = new int[m_NumNodes];

    m_mapSize = mapSize;

    Reset();
}

Pathfinder::~Pathfinder()
{
    delete[] m_Nodes;
    delete[] m_OpenNodes;
}

void Pathfinder::Reset()
{
    m_NumOpen = 0;

    for (int i = 0; i < m_NumNodes; i++)
    {
        m_Nodes[i].parentIndex = -1;
        m_Nodes[i].status = Node::Unchecked;

        m_Nodes[i].f = 0;
        m_Nodes[i].g = FLT_MAX;
        m_Nodes[i].h = -1;
    }
}

bool Pathfinder::FindPath(int sx, int sy, int ex, int ey)
{
    Reset();

    int CurrentNodeIndex = CalculateNodeIndex(sx, sy);
    int DestinationNodeIndex = CalculateNodeIndex(ex, ey);

    m_Nodes[CurrentNodeIndex].g = 0;
    AddToOpen(CurrentNodeIndex);

    while (true)
    {
        CurrentNodeIndex = FindLowestFInList();
        RemoveFromOpen(CurrentNodeIndex);

        if (CurrentNodeIndex == DestinationNodeIndex)
        {
            return true;
        }

        m_Nodes[CurrentNodeIndex].status = Node::Closed;

        AddNeighboursToOpenList(CurrentNodeIndex, DestinationNodeIndex);

        if (m_NumOpen == 0)
        {
            return false;
        }
    }
    return false;
}

int Pathfinder::GetPath(int* path, int maxDistance, int ex, int ey)
{
    int nodeIndex = CalculateNodeIndex(ex, ey);

    int length = 0;

    while (true)
    {
        if (path != nullptr && length >= maxDistance)
        {
            return -1;
        }

        if (path != nullptr)
        {
            path[length] = nodeIndex;
        }
        length++;

        nodeIndex = m_Nodes[nodeIndex].parentIndex;

        if (nodeIndex == -1)
        {
            return length;
        }
    }

    return -1;
}

void Pathfinder::AddToOpen(int nodeIndex)
{
    if (m_Nodes[nodeIndex].status == Node::Closed)
    {
        return;
    }
    if (m_Nodes[nodeIndex].status != Node::Open)
    {
        m_OpenNodes[m_NumOpen] = nodeIndex;
        m_NumOpen++;
        m_Nodes[nodeIndex].status = Node::Open;
    }
}

void Pathfinder::RemoveFromOpen(int nodeIndex)
{
    for (int i = 0; i < m_NumOpen; i++)
    {
        if (m_OpenNodes[i] == nodeIndex)
        {
            m_NumOpen--;
            m_OpenNodes[i] = m_OpenNodes[m_NumOpen];
            return;
        }
    }
}

int Pathfinder::FindLowestFInList()
{
    float LowestF = FLT_MAX;
    int LowestIndex = 0;
    for (int i = 0; i < m_NumOpen; i++)
    {
        if (m_Nodes[m_OpenNodes[i]].f < LowestF)
        {
            LowestF = m_Nodes[m_OpenNodes[i]].f;
            LowestIndex = m_OpenNodes[i];
        }
    }
    return LowestIndex;
}

int Pathfinder::CalculateNodeIndex(int tx, int ty)
{
    if (tx < 0 && tx >= m_mapSize &&
        ty < 0 && ty >= m_mapSize)
        return -1;

    return ty + m_mapSize + tx;
}

int Pathfinder::CheckIfNodeIsClearAndReturnIndex(int tx, int ty)
{
    if (tx < 0 || tx >= m_mapSize ||
        ty < 0 || ty >= m_mapSize)
        return -1;

    int nodeIndex = CalculateNodeIndex(tx, ty);

    if (m_Nodes[nodeIndex].status == Node::Closed)
        return -1;

    if (m_TileMap->IsTileWalkableForTilePos(Vector2Int(tx, ty)) == false)
        return -1;

    return nodeIndex;
}

void Pathfinder::AddNeighboursToOpenList(int nodeIndex, int endNodeIndex)
{
    int tx = nodeIndex % m_mapSize;
    int ty = nodeIndex / m_mapSize;

    Vector2Int nodesToAdd[4];
    nodesToAdd[0] = Vector2Int(tx, ty + 1);
    nodesToAdd[1] = Vector2Int(tx + 1, ty);
    nodesToAdd[2] = Vector2Int(tx, ty - 1);
    nodesToAdd[3] = Vector2Int(tx - 1, ty);

    for (int i = 0; i < 4; i++)
    {
        int nodeToAdd = CalculateNodeIndex(nodesToAdd[i].x, nodesToAdd[i].y);

        if (nodeToAdd == CheckIfNodeIsClearAndReturnIndex(nodesToAdd[i].x, nodesToAdd[i].y))
        {
            AddToOpen(nodeToAdd);

            if (m_Nodes[nodeIndex].g + 1 < m_Nodes[nodeToAdd].g)
            {
                m_Nodes[nodeToAdd].parentIndex = nodeIndex;

                m_Nodes[nodeToAdd].g = m_Nodes[nodeIndex].g + 1;

                if (m_Nodes[nodeToAdd].h == -1)
                {
                    m_Nodes[nodeToAdd].h = CalculateH(nodeToAdd, endNodeIndex);
                }
            }
        }
    }
}

float Pathfinder::CalculateH(int nodeIndex1, int nodeIndex2)
{
    int tx1 = nodeIndex1 % m_mapSize;
    int ty1 = nodeIndex1 / m_mapSize;

    int tx2 = nodeIndex2 % m_mapSize;
    int ty2 = nodeIndex2 / m_mapSize;

    return abs(tx1 - tx2) + abs(ty1 - ty2);
}
