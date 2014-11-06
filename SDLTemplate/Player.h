#include "GameObject.h"
#include "includes.h"

#ifndef __Player__
#define __Player__
class Player : public GameObject
{
public:
	
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	void handleInput();
};
#endif