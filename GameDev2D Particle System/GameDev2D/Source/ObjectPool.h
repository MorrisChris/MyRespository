#pragma once

#include <GameDev2D.h>

namespace GameDev2D
{
	template<class Object> class ObjectPool
	{
		std::vector<Object> m_InactiveObjects;

	public:
		ObjectPool()
		{

		}

		virtual ~ObjectPool()
		{
			for (int i = 0; i < m_InactiveObjects.size(); i++)
			{
				delete m_InactiveObjects.back();
				m_InactiveObjects.pop_back();
			}
		}

		void AddObjectToPool(Object object)
		{
			m_InactiveObjects.push_back(object);
		}

		Object GetObjectFromPool()
		{
			if (m_InactiveObjects.size() == 0)
				return 0;

			Object object = m_InactiveObjects.back();
			if (object != 0)
			{
				m_InactiveObjects.pop_back();
			}

			return object;
		}

		void ReturnObjectToPool(Object object)
		{
			m_InactiveObjects.push_back(object);
		}

		int GetNumObjectsInPool()
		{
			return m_InactiveObjects.size();
		}
	};
}