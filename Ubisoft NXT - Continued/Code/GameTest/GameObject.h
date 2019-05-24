#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "stdafx.h"

class CSimpleTileMap;

struct ValidDirections
{
    bool up;
    bool down;
    bool left;
    bool right;
};

class GameObject
{
public:
    GameObject(Vector2 pos);
    GameObject() {}
    virtual ~GameObject();

    virtual void Update(float deltaTime);
    virtual void Draw() = 0;

    virtual Vector2 GetPosition() { return m_Position; }
    virtual void SetPosition(Vector2 position) { m_Position = position; }
    virtual Vector2 GetMoveDir() { return m_MoveDir; }
    virtual void SetMoveDir(Vector2 moveDir) { m_MoveDir = moveDir; }

    virtual void SetTileMapRef(CSimpleTileMap* tileMapRef) { m_TileMapRef = tileMapRef; }
protected:
    Vector2 m_Position;
    Vector2 m_MoveDir;

    float m_MovementSpeed;
    float m_Radius;

    CSimpleTileMap* m_TileMapRef;
};

#endif // !_GAME_OBJECT_H
