#include "GameObject.h"
#include "GameObjectFactory.h"
class Stars : public GameObject
{
public:

	void load(const LoaderParams *pParams);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	bool touchingGround;
};

class StarsCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Stars();
	}
};
