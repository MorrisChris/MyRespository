#include "stdafx.h"

#include "App\app.h"
#include "Player.h"
#include "GameObject.h"
#include "SimpleTileMap.h"

Player::Player(Vector2 position) :
    GameObject(position)
{
    m_Position = position;
    SetMoveDir(Vector2(0, 0));
    m_MovementSpeed = 5;
    m_Radius = 0.05f;

    m_ValidDirections.down = true;
    m_ValidDirections.up = true;
    m_ValidDirections.right = true;
    m_ValidDirections.left = true;
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
    Vector2 playerTopRight = Vector2(m_Position.x, m_Position.y + m_Radius * 500);
    Vector2 playerBottomRight = Vector2(m_Position.x, m_Position.y - m_Radius * 500);
    Vector2 playerTopLeft = Vector2(m_Position.x - m_Radius * 1100, m_Position.y + m_Radius * 500);
    Vector2 playerBottomLeft = Vector2(m_Position.x - m_Radius * 1100, m_Position.y - m_Radius * 500);

    if (m_TileMapRef != nullptr)
    {
        if (m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerTopRight.x, playerTopRight.y - 10)) == false
            || m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerBottomRight.x, playerBottomRight.y + 10)) == false)
        {
            SetMoveDir(Vector2(0, GetMoveDir().y));
            m_ValidDirections.right = false;
        }
        else
        {
            m_ValidDirections.right = true;
        }

        if (m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerTopLeft.x, playerTopRight.y - 10)) == false
            || m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerBottomLeft.x, playerBottomLeft.y + 10)) == false)
        {
            SetMoveDir(Vector2(0, GetMoveDir().y));
            m_ValidDirections.left = false;
        }
        else
        {
            m_ValidDirections.left = true;
        }

        if (m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerTopLeft.x + 10, playerTopLeft.y)) == false
            || m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerTopRight.x - 10, playerTopRight.y)) == false)
        {
            SetMoveDir(Vector2(GetMoveDir().x, 0));
            m_ValidDirections.up = false;
        }
        else
        {
            m_ValidDirections.up = true;
        }

        if (m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerBottomLeft.x + 10, playerBottomLeft.y)) == false
            || m_TileMapRef->IsTileWalkableForWorldPos(Vector2(playerBottomRight.x - 10, playerBottomRight.y)) == false)
        {
            SetMoveDir(Vector2(GetMoveDir().x, 0));
            m_ValidDirections.down = false;
        }
        else
        {
            m_ValidDirections.down = true;
        }
    }

    if (App::IsKeyPressed('A') && m_ValidDirections.left)
    {
        m_MoveDir = Vector2(-1, 0);
    }
    if (App::IsKeyPressed('D') && m_ValidDirections.right)
    {
        m_MoveDir = Vector2(1, 0);
    }
    if (App::IsKeyPressed('W') && m_ValidDirections.up)
    {
        m_MoveDir = Vector2(0, 1);
    }
    if (App::IsKeyPressed('S') && m_ValidDirections.down)
    {
        m_MoveDir = Vector2(0, -1);
    }
    m_Position.x += m_MoveDir.x * deltaTime / 5;
    m_Position.y += m_MoveDir.y * deltaTime / 5;
}

void Player::Draw()
{
    App::DrawCircle(m_Position, m_Radius, Vector3(1, 1, 0));
}

void Player::RespositionOnValidTile()
{
    int count = 0;
    while (m_TileMapRef->IsTileWalkableForWorldPos(m_Position + 32) == false)
    {
        Vector2Int tilePos = m_TileMapRef->GetTilePosForTileIndex(count);

        if (m_TileMapRef->IsTileWalkableForTilePos(tilePos))
        {
            SetPosition(m_TileMapRef->GetWorldPosForTilePos(tilePos) + 32);
            break;
        }
        count++;
    }
}