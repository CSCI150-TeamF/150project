#include "GameObject.h"
#include "includes.h"
#include "Vector2D.h"
#include "LoaderParams.h"





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
void GameObject::draw(SDL_Renderer* pRenderer) //draw game object
{   
	
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);

}


void GameObject::update()
{
	//m_x += 1;

	m_position += m_velocity;

}


void GameObject::clean(){

}


void GameObject::collision()

{
	if (m_x < 0)
	{
		m_x = 0;
	}
	if (m_x > 640 - m_width)
	{
		m_x = 640 - m_width;
	}
	if (m_y < 0)
	{
		m_y = 0;
	}
	if (m_y > 480 - m_height)
	{
		m_y = 480 - m_height;
	}

}


