#include "GameObject.h"
#include "includes.h"

#ifndef __Player__
#define __Player__
class Player : public GameObject
{
public:

	//Player(const LoaderParams* pParams); // Player inherit from GameObject

	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();

	/*Player::Player(const LoaderParams* pParams) :
		GameObject(pParams)
	{

	}
	*/
};
#endif