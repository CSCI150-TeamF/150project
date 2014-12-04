#include "GameObject.h"
#include "GameObjectFactory.h"
class Comet : public GameObject
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

class CometCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Comet();
	}
};
