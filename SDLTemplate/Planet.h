#include "GameObject.h"
#include "GameObjectFactory.h"
class Planet : public GameObject
{
public:

	void load(const LoaderParams *pParams);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	bool touchingGround;
};

class PlanetCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Planet();
	}
};
