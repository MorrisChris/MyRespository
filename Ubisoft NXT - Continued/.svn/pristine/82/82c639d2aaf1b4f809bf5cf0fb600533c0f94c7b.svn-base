#include "stdafx.h"
#include "Ghost.h"
#include "GameObject.h"
#include "SimpleTileMap.h"

Ghost::Ghost(Vector2 pos)
    : GameObject(pos)
{
}


Ghost::~Ghost()
{
}

void Ghost::Update(float deltaTime)
{

}

void Ghost::Draw()
{

}

void Ghost::MoveToNearestValidTile()
{
    Vector2Int tilePos = Vector2Int(m_TileMapRef->GetTilePosForWorldPos(m_Position - 32).x,
        m_TileMapRef->GetTilePosForWorldPos(m_Position).y);
    int count = 0;
    while (m_TileMapRef->IsTileWalkableForTilePos(tilePos) == false)
    {
        Vector2Int neighbours[4];
        neighbours[0] = Vector2Int(tilePos.x + 1, tilePos.y);
        neighbours[1] = Vector2Int(tilePos.x, tilePos.y + 1);
        neighbours[2] = Vector2Int(tilePos.x - 1, tilePos.y);
        neighbours[3] = Vector2Int(tilePos.x, tilePos.y - 1);

        if (m_TileMapRef->IsTileWalkableForTilePos(neighbours[count]))
        {
            tilePos = neighbours[count];
            m_Position = m_TileMapRef->GetWorldPosForTilePos(tilePos) + 32;
            break;
        }
        if (count == 3)
        {
            for (int i = 0; i < 4; i++)
            {
                if (neighbours[i].x < 0 || neighbours[i].x >= m_TileMapRef->GetMapSize()
                    || neighbours[i].y < 0 || neighbours[i].y >= m_TileMapRef->GetMapSize())
                {
                    continue;
                }
                tilePos = neighbours[i];
            }
            count = 0;
            continue;
        }
        count++;
    }
}

bool Ghost::CheckMapCollision(Vector2 worldPosition)
{
    Vector2 adjustedPosition = worldPosition;

    //Bottom Left
    adjustedPosition.x = worldPosition.x - m_Radius * 1100;
    adjustedPosition.y = worldPosition.y - m_Radius * 500;
    if (m_TileMapRef->IsTileWalkableForWorldPos(adjustedPosition) == false)
        return false;

    //Bottom Right
    adjustedPosition.x = worldPosition.x;
    adjustedPosition.y = worldPosition.y - m_Radius * 500;
    if (m_TileMapRef->IsTileWalkableForWorldPos(adjustedPosition) == false)
        return false;

    //Top Left
    adjustedPosition.x = worldPosition.x - m_Radius * 1100;
    adjustedPosition.y = worldPosition.y + m_Radius * 500;
    if (m_TileMapRef->IsTileWalkableForWorldPos(adjustedPosition) == false)
        return false;

    //Top Right
    adjustedPosition.x = worldPosition.x;
    adjustedPosition.y = worldPosition.y + m_Radius * 500;
    if (m_TileMapRef->IsTileWalkableForWorldPos(adjustedPosition) == false)
        return false;

    return true;
}