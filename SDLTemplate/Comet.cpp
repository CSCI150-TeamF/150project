#include "Comet.h"
#include "includes.h"

void Comet::load(const LoaderParams *pParams)
{
	GameObject::load(pParams);
}
void Comet::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw();
}


void Comet::update()
{

}

void Comet::clean()
{
	if ((int)m_position->getY() >  600)
	{

		m_position->setY(0);
		m_position->setX(rand() % 630);


	}
	else
		m_position->setY(m_position->getY() + 12);

	m_currentFrame = int(((SDL_GetTicks() / 240) % 3));
}

void Comet::collision()
{

}