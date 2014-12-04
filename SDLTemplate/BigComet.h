#include "GameObject.h"
#include "GameObjectFactory.h"
class BigComet : public GameObject
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

class BigCometCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new BigComet();
	}
};
