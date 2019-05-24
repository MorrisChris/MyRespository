#include "stdafx.h"

#include "App\app.h"
#include "BlueGhost.h"
#include "GameObject.h"
#include "SimpleTileMap.h"

BlueGhost::BlueGhost(Vector2 pos) :
    Ghost(pos)
{
    m_Position = pos;
    SetMoveDir(Vector2(0, 1));
    m_MovementSpeed = 0.25f;
    m_Radius = 0.05f;
}

BlueGhost::~BlueGhost()
{
}

void BlueGhost::Update(float deltaTime)
{
    if (m_MoveDir.y < 0)
    {
        if (CheckMapCollision(m_Position + Vector2(0.0f, m_MoveDir.y)) == false)
        {
            m_MoveDir.y = 1;
        }
    }
    if (m_MoveDir.y > 0)
    {
        if (CheckMapCollision(m_Position + Vector2(0.0f, m_MoveDir.y)) == false)
        {
            m_MoveDir.y = -1;
        }
    }

    m_Position += m_MoveDir * m_MovementSpeed * deltaTime;
}

void BlueGhost::Draw()
{
    App::DrawCircle(m_Position, m_Radius, Vector3(0, 0, 1));
}
