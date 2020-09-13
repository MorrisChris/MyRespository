#pragma once

#include <GameDev2D.h>

namespace GameDev2D
{
	class Particle
	{
	public:
		Particle();
		Particle(Vector2 position, float radius, Color color, std::string name);
		~Particle();

		void Update(float deltaTime);
		void Draw();

		void SetPosition(Vector2 position) { m_Position = position; }
		Vector2 GetPosition() { return m_Position; }

		void SetName(std::string name) { m_Name = name; }
		std::string GetName() { return m_Name; }

		void ResetPosition();

	private:
		Vector2 m_Position;
		Vector2 m_InitialPosition;
		float m_Radius;
		Color m_Color;
		std::string m_Name;
		Vector2 m_TravelDirection;
	};
}