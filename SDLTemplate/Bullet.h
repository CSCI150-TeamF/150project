#include "GameObject.h"
#include "GameObjectFactory.h"
class Bullet : public GameObject
{
public:

	void load(const LoaderParams *pParams);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	void collision();
	bool touchingGround;
	int x = 0;
};

class BulletCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Bullet();
	}
};
