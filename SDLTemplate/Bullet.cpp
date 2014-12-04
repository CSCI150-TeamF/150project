#include "Bullet.h"
#include "includes.h"

void Bullet::load(const LoaderParams *pParams)
{
	GameObject::load(pParams);
}
void Bullet::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw();
}


void Bullet::update()
{
	
}

void Bullet::clean()
{
	if ((int)m_position->getY() >  600)
	{
		
		m_position->setY(0);
		m_position->setX(rand() % 640);
			
	
	}
	else
	m_position->setY(m_position->getY() + 5);

	m_currentFrame = int(((SDL_GetTicks() / 240) % 3));
}

void Bullet::collision()
{

}