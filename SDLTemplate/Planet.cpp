#include "Planet.h"
#include "includes.h"

void Planet::load(const LoaderParams *pParams)
{
	GameObject::load(pParams);
}
void Planet::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw();
}


void Planet::update()
{

}

void Planet::clean()
{
	
}