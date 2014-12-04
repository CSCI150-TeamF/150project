#include "Enemy.h"
#include "includes.h"

void Enemy::load(const LoaderParams *pParams)
{
	GameObject::load(pParams);
}
void Enemy::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw();
}



void Enemy::update()
{
	
}

void Enemy::jumpFx()
{

}

void Enemy::clean()
{
	if ((int)m_position->getX() >  640 - 100)
	{
		m_position->setX(0);
	}
	else
		m_position->setX(m_position->getX() + 1);
}

void Enemy::collision()
{
	if ((int)m_position->getX() < 0)
	{
		m_position->setX(0);
		m_currentFrame = 2;
	}
	if ((int)m_position->getX() > 380 - m_width / 2+10)
	{
		m_position->setX(380 - m_width / 2+10);
		m_currentFrame = 2;
	}
}