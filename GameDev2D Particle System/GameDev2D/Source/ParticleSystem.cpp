#include "ParticleSystem.h"
#include "ObjectPool.h"
#include "Particle.h"

namespace GameDev2D
{
	ParticleSystem::ParticleSystem(Vector2 position, int numParticles)
	{
		m_Position = position;

		for (int i = 0; i < numParticles; i++)
		{
			Particle* particle = new Particle(position, 5.0f, Color::RedColor(), std::to_string(i));
			m_ParticlePool.AddObjectToPool(particle);
		}

		Particle* particle;
		while (particle = m_ParticlePool.GetObjectFromPool())
		{
			if (particle)
			{
				particle->SetPosition(position);
				AddObjectToGame(particle);
			}
		}
	}

	ParticleSystem::~ParticleSystem()
	{

	}

	void ParticleSystem::Update(float deltaTime)
	{
		for (auto object : m_Particles)
		{
			object.second->Update(deltaTime);
		}
	}

	void ParticleSystem::Draw()
	{
		DrawCircle(m_Position.x, m_Position.y, 10.0f, Color::BlackColor(), false);

		for (auto object : m_Particles)
		{
			object.second->Draw();
		}
	}

	void ParticleSystem::AddObjectToGame(Particle* particle)
	{
		m_Particles[particle->GetName()] = particle;
	}

	
}