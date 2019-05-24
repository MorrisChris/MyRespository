#ifndef _Player_H
#define _Player_H

#include "stdafx.h"
#include "GameObject.h"

class GameObject;
class CSimpleTileMap;

class Player : public GameObject
{
public:
    Player(Vector2 position);
    ~Player();

    virtual void Update(float deltaTime);
    virtual void Draw();

    float GetRadius() { return m_Radius; }
    void RespositionOnValidTile();

private:
    ValidDirections m_ValidDirections;
};

#endif // !_Player_H
