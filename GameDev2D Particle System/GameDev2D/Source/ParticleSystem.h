#pragma once

#include <GameDev2D.h>
#include "ObjectPool.h"
#include "Particle.h"

namespace GameDev2D
{
	class ParticleSystem
	{
	public:
		ParticleSystem(Vector2 position, int numParticles);
		~ParticleSystem();

		void Update(float deltaTime);
		void Draw();

		void AddObjectToGame(Particle* particle);

	private:
		ObjectPool<Particle*> m_ParticlePool;

		Vector2 m_Position;

		std::map<std::string, Particle*> m_Particles;
	};
}