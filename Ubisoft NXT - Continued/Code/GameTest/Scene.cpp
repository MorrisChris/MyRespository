#include "stdafx.h"
#include "Scene.h"
#include "World.h"


Scene::Scene()
{
    m_pWorld = new World();
}


Scene::~Scene()
{
    delete m_pWorld;
}

void Scene::Update(float deltaTime)
{
    m_pWorld->Update(deltaTime);
}

void Scene::Render()
{
    m_pWorld->Render();
}