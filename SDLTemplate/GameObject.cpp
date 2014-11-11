#include "GameObject.h"
#include "includes.h"
#include "SDL.h"
#include "Game.h"
void GameObject::load(int x, int y, int width, int height, std::string textureID) //load game object
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;

	m_currentRow = 1;
	m_currentFrame = 1;
}
void GameObject::draw() //draw game object
{
	SDL_Renderer* pRenderer = TheGame::Instance()->getRenderer();
	
	if (m_direction > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
		
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer, SDL_FLIP_HORIZONTAL);
		
	}
}
void GameObject::update()
{
	
}

void GameObject::updateDirection(int dirSign)//update direction
{
	m_direction = dirSign;
}

void GameObject::setX(int &x)
{
	m_x = x;
}


int GameObject::getX()
{
	return m_x;
}

void GameObject::reset()
{
	m_currentFrame = 2;
}
void GameObject::clean(){

}
void GameObject::collision()

{
	if (m_x < 0)
	{
		m_x = 0;
		m_currentFrame = 2;
	}
	if (m_x > 640 - m_width)
	{
		m_x = 640 - m_width;
		m_currentFrame = 2;
	}
	if (m_y < 0)
	{
		m_y = 0;
		m_currentFrame = 2;
	}
	if (m_y > 480 - m_height)
	{
		m_y = 480 - m_height;
		m_currentFrame = 2;
	}

}