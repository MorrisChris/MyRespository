#include "stdafx.h"

#include "App\app.h"
#include "RedGhost.h"
#include "GameObject.h"
#include "SimpleTileMap.h"
#include "Pathfinder.h"
#include "Player.h"

RedGhost::RedGhost(Vector2 pos) :
    Ghost(pos)
{
    m_Position = pos;
    SetMoveDir(Vector2(0, 0));
    m_MovementSpeed = 0.2f;
    m_Radius = 0.05f;
    m_FinalDestination = Vector2Int(0, 0);
    m_Destination = Vector2(0,0);
}

RedGhost::~RedGhost()
{

}

void RedGhost::Update(float deltaTime)
{
    m_Destination = Vector2(m_PlayerObj->GetPosition().x, m_PlayerObj->GetPosition().y);
    m_FinalDestination = m_TileMapRef->GetTilePosForWorldPos(m_PlayerObj->GetPosition());

    Vector2 dir = Vector2(0,0);

    if (m_Destination.y > m_Position.y)
    {
        dir.y = 1 * m_MovementSpeed * deltaTime;

        if (dir.y > (m_Destination.y - m_Position.y))
            dir.y = m_Destination.y - m_Position.y;
    }
    if (m_Destination.y < m_Position.y)
    {
        dir.y = -1 * m_MovementSpeed * deltaTime;

        if (dir.y < (m_Destination.y - m_Position.y))
            dir.y = m_Destination.y - m_Position.y;
    }
    if (m_Destination.x < m_Position.x)
    {
        dir.x = -1 * m_MovementSpeed * deltaTime;

        if (dir.x < (m_Destination.x - m_Position.x))
            dir.x = m_Destination.x - m_Position.x;
    }
    if (m_Destination.x > m_Position.x)
    {
        dir.x = 1 * m_MovementSpeed * deltaTime;

        if (dir.x > (m_Destination.x - m_Position.x))
            dir.x = m_Destination.x - m_Position.x;
    }

    if (CheckMapCollision(m_Position + Vector2(0.0f, dir.y)) == false)
    {
        dir.y = 0;
    }
    if (CheckMapCollision(m_Position + Vector2(dir.x, 0.0f)) == false)
    {
        dir.x = 0;
    }

    m_Position += dir;
}

void RedGhost::Draw()
{
    App::DrawCircle(m_Position, m_Radius, Vector3(1, 0, 0));
}

void RedGhost::SetDestination()
{
    m_Destination = m_Position;

    int currentTileIndex = -1;
    int nextTileIndex = -1;

    Vector2Int currentTilePos = m_TileMapRef->GetTilePosForWorldPos(m_Position);

    bool Found = m_Pathfinder->FindPath(currentTilePos.x, currentTilePos.y, m_FinalDestination.x, m_FinalDestination.y);

    if (Found)
    {
        int path[255];
        int length = m_Pathfinder->GetPath(path, 255, m_FinalDestination.x, m_FinalDestination.y);

        if (length > 1)
        {
            currentTileIndex = path[length - 1];
            nextTileIndex = path[length - 2];

            m_Destination = m_TileMapRef->GetWorldPosForTileIndex(nextTileIndex);
            m_Destination.x -= 32;
        }
    }
    else
    {
        m_Destination = m_TileMapRef->GetWorldPosForTilePos(currentTilePos);
        m_Destination.x -= 32;
        m_FinalDestination = currentTilePos;
    }
}