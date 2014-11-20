#include "GameObject.h"

class Enemy : public GameObject
{
public:
	
	void load(float x, float y, int width, int height, std::string
		textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};