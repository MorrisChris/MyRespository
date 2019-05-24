#ifndef _WORLD_H_
#define _WORLD_H_

static const int MAP_SIZE = 16;
static const int TUNNEL_LEN = 12;
static const float TUNNEL_FILL_PERCENT = 80;

class CSimpleTileMap;
class GameObject;
class Player;
class RedGhost;
class BlueGhost;
class Pathfinder;

class World
{
public:
    World();
    ~World();

    void Update(float deltaTime);
    void Render();

private:
    CSimpleTileMap * m_pTileMap;
    Player* m_pPlayer;
    RedGhost* m_pRedGhost;
    BlueGhost* m_pBlueGhost;
    Pathfinder* m_pPathfinder;
};

#endif // !_WORLD_H_

