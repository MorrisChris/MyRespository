#include "Particle.h"

#include <time.h>

namespace GameDev2D
{
	Particle::Particle()
	{

	}

	Particle::Particle(Vector2 position, float radius, Color color, std::string name)
	{
		m_Position = position;
		m_InitialPosition = position;
		m_Radius = radius;
		m_Color = color;
		m_Name = name;

		m_TravelDirection = Vector2(rand() % 19 + (-9), rand() % 19 + (-9));
	}

	Particle::~Particle()
	{

	}

	void Particle::Update(float deltaTime)
	{
		m_Position += m_TravelDirection * 5 * deltaTime;

		if (m_Position.Distance(m_InitialPosition) > 200)
		{
			ResetPosition();
		}
	}

	void Particle::Draw()
	{
		DrawCircle(m_Position.x, m_Position.y, m_Radius, m_Color, true);
	}

	void Particle::ResetPosition()
	{
		m_Position = m_InitialPosition;
		m_TravelDirection = Vector2(rand() % 19 + (-9), rand() % 19 + (-9));
	}
}