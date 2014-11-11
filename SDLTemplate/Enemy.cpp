#include "Enemy.h"
#include "includes.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
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