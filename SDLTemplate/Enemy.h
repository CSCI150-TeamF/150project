#include "GameObject.h"
#include "GameObjectFactory.h"
class Enemy : public GameObject
{
public:
	
	void load(const LoaderParams *pParams);
	void draw(SDL_Renderer* pRenderer);
	void jumpFx();
	void update();
	void clean(); 
	void collision();
	bool touchingGround;
};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};