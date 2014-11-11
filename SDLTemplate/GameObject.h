#include <SDL.h>
#include "TextureManager.h"
#include "includes.h"
#include "LoaderParams.h"
// All objects that are rendered should inherit this class
#ifndef __GameObject__
#define __GameObject__
class GameObject
{
public:
	GameObject(const LoaderParams* pParams)
	{
		m_x = pParams->getX();
		m_y = pParams->getY();
		m_width = pParams->getWidth();
		m_height = pParams->getHeight();
		m_textureID = pParams->getTextureID();
		m_currentRow = 1;
		m_currentFrame = 1;
	}
	GameObject(){}
	virtual void collision();
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(); //No longer requires SDL renderer. renderer is inside function
	virtual void updateDirection(int dirSign);
	virtual void update();
	virtual void update(SDL_Event* event, int x, int y){}
	virtual void reset();
	virtual void clean();
	static const int speed = 10;
	virtual void setX(int &x);
	virtual int getX();
	int flipFlag;
	
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_direction = 0;
	int m_width;
	int m_height;
	bool left;
	bool right;
};
#endif