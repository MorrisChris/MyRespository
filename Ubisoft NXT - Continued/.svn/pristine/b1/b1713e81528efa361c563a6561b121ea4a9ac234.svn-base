#ifndef _GHOST_H_
#define _GHOST_H_

#include "stdafx.h"
#include "GameObject.h"

class GameObject;
class CSimpleTileMap;

class Ghost : public GameObject
{
public:
    Ghost(Vector2 pos);
    virtual ~Ghost();

    virtual void Update(float deltaTime);
    virtual void Draw();

    virtual void MoveToNearestValidTile();
    virtual bool CheckMapCollision(Vector2 worldPosition);
};

#endif // !_GHOST_H_

