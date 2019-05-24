#ifndef _REDGHOST_H
#define _REDGHOST_H_

#include "stdafx.h"
#include "GameObject.h"
#include "Player.h"
#include "Ghost.h"

class GameObject;
class CSimpleTileMap;
class Pathfinder;
class Player;
class Ghost;

class RedGhost : public Ghost
{
public:
    RedGhost(Vector2 pos);
    ~RedGhost();

    virtual void Update(float deltaTime);
    virtual void Draw();

    void SetPathfinder(Pathfinder* pathfinder) { m_Pathfinder = pathfinder; }
    void SetFinalDestination(Vector2Int destination) { m_FinalDestination = destination; }

    void SetDestination();

    void SetPlayer(Player* player) { m_PlayerObj = player; }

private:
    Pathfinder * m_Pathfinder;
    Vector2 m_Destination;
    Vector2Int m_FinalDestination;

    Player* m_PlayerObj;
};

#endif // !_REDGHOST_H
