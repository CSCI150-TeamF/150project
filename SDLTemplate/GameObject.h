#include <SDL.h>
#include "TextureManager.h"
#include "includes.h"
// All objects that are rendered should inherit this class
#ifndef __GameObject__
#define __GameObject__
class GameObject
{
public:
	virtual void collision();
	virtual void handleEvents();
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void reset();
	virtual void clean();
	static const int speed = 10;
	int m_x;
	int m_y;
	int mVel_x = 0;
	int mVel_y = 0;
	int hspeed;
	int flipFlag;
	
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	
	int m_width;
	int m_height;
	bool left;
	bool right;
};
#endif