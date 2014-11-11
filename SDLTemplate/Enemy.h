#include "GameObject.h"

class Enemy : public GameObject
{
public:

	//Enemy(const LoaderParams* pParams);  // Enemy inherit from GameObject
	
	void load(int x, int y, int width, int height, std::string
		textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();

	/*Enemy::Enemy(const LoaderParams* pParams) :
		GameObject(pParams)
	{

	}
	*/
};