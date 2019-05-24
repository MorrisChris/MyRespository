#ifndef _PATHFINDER_H
#define _PATHFINDER_H

#include "stdafx.h"

struct Node
{
    enum PathStatus
    {
        Unchecked,
        Open,
        Closed
    };

    int parentIndex;
    PathStatus status;

    float f;
    float g;
    float h;
};

class CSimpleTileMap;

class Pathfinder
{
protected:
    int m_mapSize;
    CSimpleTileMap* m_TileMap;

    Node* m_Nodes;
    int m_NumNodes;

    int* m_OpenNodes;
    int m_NumOpen;

    void AddToOpen(int nodeIndex);
    void RemoveFromOpen(int nodeIndex);
    int FindLowestFInList();

    int CalculateNodeIndex(int tx, int ty);
    int CheckIfNodeIsClearAndReturnIndex(int tx, int ty);
    void AddNeighboursToOpenList(int nodeIndex, int endNodeIndex);

    float CalculateH(int nodeIndex1, int nodeIndex2);

public:
    Pathfinder(CSimpleTileMap* tileMap, int mapSize);
    virtual ~Pathfinder();

    void Reset();

    bool FindPath(int sx, int sy, int ex, int ey);

    int GetPath(int* path, int maxDistance, int ex, int ey);
};

#endif // !_PATHFINDER_H
