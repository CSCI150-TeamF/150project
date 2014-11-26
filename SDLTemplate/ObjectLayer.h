#include <SDL.h>
#include "includes.h"


#ifndef __ObjectLayer__
#define __ObjectLayer__

class ObjectLayer : public Layer
{
public:
	virtual void update();
	virtual void render();

	vector<GameObject*>* getGameObjects()
	{
		return &m_gameObjects;
	}
private:
	vector<GameObject*> m_gameObjects;
};


#endif