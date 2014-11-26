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
	m_currentFrame = int(((SDL_GetTicks() / 60) % 6));
}

void Enemy::clean()
{

}