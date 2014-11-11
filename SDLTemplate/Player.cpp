#include "Player.h"
#include "includes.h"

void Player::load(int x, int y, int width, int height, std::string textureID) //load player sprite
{
	GameObject::load(x, y, width, height, textureID);
}
void Player::draw(SDL_Renderer* pRenderer) //draw player
{
	GameObject::draw(pRenderer);  
}
void Player::update() //update player position
{
	//m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	m_velocity.setX(1);

	GameObject::update();

}
void Player::clean()
{

}