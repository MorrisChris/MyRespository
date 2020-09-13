#include "Game.h"
#include "Particle.h"


namespace GameDev2D
{
	Game::Game()
	{
		m_ParticleSystem = new ParticleSystem(Vector2(GetScreenWidth() / 2, GetScreenHeight() / 2), 100);
	}

	Game::~Game()
	{
		delete m_ParticleSystem;
	}

	void Game::Update(double delta)
	{
		m_ParticleSystem->Update(delta);
	}

	void Game::Draw()
	{
		m_ParticleSystem->Draw();
	}

	void Game::HandleLeftMouseClick(float mouseX, float mouseY)
	{
		
	}

	void Game::HandleRightMouseClick(float mouseX, float mouseY)
	{

	}

	void Game::HandleKeyPress(Keyboard::Key key)
	{

	}
}