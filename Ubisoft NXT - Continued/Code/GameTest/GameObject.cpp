#include "stdafx.h"

#include "App/app.h"
#include "GameObject.h"
#include "SimpleTileMap.h"

GameObject::GameObject(Vector2 position)
{
    m_Position = position;
    m_MoveDir = Vector2(0, 0);
}

GameObject::~GameObject()
{

}

void GameObject::Update(float deltaTime)
{

}