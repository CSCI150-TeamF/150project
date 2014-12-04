#include "GameObject.h"
#include "includes.h"
#include "SDL.h"
#include "Game.h"
void GameObject::load(const LoaderParams* pParams) //load game object
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_position = new Vector2D(pParams->getX(), pParams->getY());
	m_velocity = new Vector2D(0, 0);
	// Acceleration?
	m_currentRow = 1;
	m_currentFrame = 0;
}
void GameObject::draw() //draw game object
{
	SDL_Renderer* pRenderer = TheGame::Instance()->getRenderer();
	
	if (m_direction > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position->getX(), (int)m_position->getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
		
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position->getX(), (int)m_position->getY(), m_width, m_height, m_currentRow, m_currentFrame, pRenderer, SDL_FLIP_HORIZONTAL);
		
	}
}

void GameObject::jumpFx()
{

}



void GameObject::update()
{
	
}

void GameObject::updateDirection(int dirSign)//update direction
{
	m_direction = dirSign;
}

void GameObject::setX(float x)
{
	m_position->setX(x);
}


float GameObject::getX()
{
	return m_position->getX();
}

void GameObject::setY(float y)
{
	m_position->setY(y);
}


float GameObject::getY()
{
	return m_position->getY();
}

void GameObject::reset()
{
	m_currentFrame = 2;
}
void GameObject::clean(){

}
void GameObject::collision()

{
	if ((int)m_position->getX() < 0)
	{
		m_position->setX(0);
		m_currentFrame = 2;
	}
	if ((int)m_position->getX() > 640 - m_width)
	{
		m_position->setX(640 - m_width);
		m_currentFrame = 2;
	}
	if ((int)m_position->getY() < 0)
	{
		m_position->setY(0);
		m_currentFrame = 2;
	}
	if ((int)m_position->getY() > 480 - m_height)
	{
		m_position->setY(480 - m_height);
		m_currentFrame = 2;
	}

}