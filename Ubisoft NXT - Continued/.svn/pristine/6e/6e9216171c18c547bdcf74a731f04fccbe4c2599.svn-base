#include "stdafx.h"

#include "App/app.h"
#include "World.h"
#include "SimpleTileMap.h"
#include "GameObject.h"
#include "Player.h"
#include "RedGhost.h"
#include "BlueGhost.h"
#include "Pathfinder.h"


World::World()
{
    m_pTileMap = new CSimpleTileMap(MAP_SIZE);
    m_pTileMap->RandomMap(TUNNEL_FILL_PERCENT, TUNNEL_LEN);

    m_pPathfinder = new Pathfinder(m_pTileMap, MAP_SIZE);

    m_pPlayer = new Player(Vector2(0, 0));
    m_pPlayer->SetTileMapRef(m_pTileMap);
    m_pPlayer->RespositionOnValidTile();

    m_pRedGhost = new RedGhost(Vector2(500, 500));
    m_pRedGhost->SetTileMapRef(m_pTileMap);
    m_pRedGhost->MoveToNearestValidTile();
    m_pRedGhost->SetPathfinder(m_pPathfinder);
    m_pRedGhost->SetPlayer(m_pPlayer);
    m_pRedGhost->SetDestination();

    m_pBlueGhost = new BlueGhost(Vector2(800, 800));
    m_pBlueGhost->SetTileMapRef(m_pTileMap);
    m_pBlueGhost->MoveToNearestValidTile();

}


World::~World()
{
    delete m_pTileMap;
    delete m_pPathfinder;
    delete m_pPlayer;
    delete m_pRedGhost;
    delete m_pBlueGhost;
}

void World::Update(float deltaTime)
{
    if (App::GetController().CheckButton(VK_PAD_A, true))
    {
        m_pTileMap->RandomMap(TUNNEL_FILL_PERCENT, TUNNEL_LEN);
        m_pPathfinder->Reset();
        m_pPlayer->SetPosition(Vector2(0, 0));
        m_pPlayer->RespositionOnValidTile();
        m_pPlayer->SetMoveDir(Vector2(0, 0));
        m_pRedGhost->SetPosition(Vector2(500, 500));
        m_pRedGhost->MoveToNearestValidTile();
        m_pRedGhost->SetPlayer(m_pPlayer);
        m_pRedGhost->SetDestination();
        m_pBlueGhost->SetPosition(Vector2(800, 800));
        m_pBlueGhost->MoveToNearestValidTile();
    }
    m_pPlayer->Update(deltaTime);
    m_pRedGhost->SetPlayer(m_pPlayer);
    m_pRedGhost->Update(deltaTime);
    m_pBlueGhost->Update(deltaTime);
}

void World::Render()
{
    m_pTileMap->Render();
    m_pPlayer->Draw();
    m_pRedGhost->Draw();
    m_pBlueGhost->Draw();
}
