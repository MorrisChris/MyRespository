#pragma once

#include <GameDev2D.h>
#include "Particle.h"
#include "ParticleSystem.h"

namespace GameDev2D
{
	//Class definition
	class Game
	{
	public:
		Game();  //Constructor
		~Game(); //Destructor

		void Update(double delta);
		void Draw();

		void HandleLeftMouseClick(float mouseX, float mouseY);
		void HandleRightMouseClick(float mouseX, float mouseY);

		void HandleKeyPress(Keyboard::Key key);

	private:
		//Member variables should go here
		//Particle* m_Particle;

		ParticleSystem* m_ParticleSystem;
	};
}
