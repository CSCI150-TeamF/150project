#include "GameObject.h"
#include "includes.h"
#include "GameObjectFactory.h"
#ifndef __Player__
#define __Player__
class Player : public GameObject
{
public:
	
	void load(const LoaderParams *pParams);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	void handleInput();
};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};
#endif