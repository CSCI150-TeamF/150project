#include "Player.h"
#include "includes.h"

bool keyisRight = false;

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
	m_x -= 1;
}
void Player::clean()
{

}
void Player::handleInput()
{
 //here
}
