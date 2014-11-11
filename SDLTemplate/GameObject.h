#include <SDL.h>
#include "TextureManager.h"
#include "includes.h"
#include "Vector2D.h"
#include "LoaderParams.h"

// All objects that are rendered should inherit this class


#ifndef __GameObject__
#define __GameObject__

class GameObject 
{
public:
	virtual void collision();
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();
	/*
	SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
		GameObject(pParams), m_position(pParams->getX(), pParams->getY())
	{
		m_width = pParams->getWidth();
		m_height = pParams->getHeight();
		m_textureID = pParams->getTextureID();

		m_currentRow = 1;
		m_currentFrame = 1;
	}
	*/
protected:


	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	
	Vector2D m_position;  
	Vector2D m_velocity;

	int m_x;
	int m_y;
	int m_width;
	int m_height;

	GameObject(const LoaderParams* pParams){}
	virtual ~GameObject() {}

};




#endif