#include "Player.h"
#include "includes.h"

bool keyisRight = false;

void Player::load(const LoaderParams *pParams) //load player sprite
{
	GameObject::load(pParams);
}
void Player::draw(SDL_Renderer* pRenderer) //draw player
{
	GameObject::draw();
}
void Player::update() //update player position
{
	m_position->setX(m_position->getX() + 1);
}
void Player::clean()
{

}
void Player::handleInput()
{
 //here
}
