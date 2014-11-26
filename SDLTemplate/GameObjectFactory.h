#include <string>
#include <map>
#include "GameObject.h"

#ifndef __GameObjectFactory__
#define __GameObjectFactory__

class BaseCreator
{
public:
	virtual GameObject* createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

class GameObjectFactory
{
public:
	static GameObjectFactory* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new GameObjectFactory();
		}
		return pInstance;
	}
	bool registerType(string typeID, BaseCreator* pCreator)
	{
		map<string, BaseCreator*>::iterator it = m_creators.find(typeID);

		if (it != m_creators.end())
		{
			delete pCreator;
			return false;
		}
		m_creators[typeID] = pCreator;
		return true;
	}
	GameObject* create(std::string typeID)
	{
		map<string, BaseCreator*>::iterator it = m_creators.find(typeID);
		if (it == m_creators.end())
		{
			cout << "could not find type: " << typeID << "\n";
			return NULL;
		}
		BaseCreator* pCreator = (*it).second;
		return pCreator->createGameObject();
	}
private:
	GameObjectFactory() {}
	~GameObjectFactory() {}

	map<string, BaseCreator*> m_creators;

	static GameObjectFactory* pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif