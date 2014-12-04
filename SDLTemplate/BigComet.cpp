#include "BigComet.h"
#include "includes.h"

void BigComet::load(const LoaderParams *pParams)
{
	GameObject::load(pParams);
}
void BigComet::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw();
}


void BigComet::update()
{

}

void BigComet::clean()
{
	if ((int)m_position->getY() >  600)
	{

		m_position->setY(0);
		m_position->setX(rand() % 640);


	}
	else
		m_position->setY(m_position->getY() + 4);

	m_currentFrame = int(((SDL_GetTicks() / 240) % 3));
}

void BigComet::collision()
{

}