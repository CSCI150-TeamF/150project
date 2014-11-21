#include "Player.h"
#include "includes.h"

//......Change arrows to dots......//

bool keyisRight = false;

void Player::load(float x, float y, int width, int height, std::string textureID) //load player sprite
{
	GameObject::load(x, y, width, height, textureID);
}
void Player::draw(SDL_Renderer* pRenderer) //draw player
{
	GameObject::draw();
}
void Player::update() //update player position
{
	m_position.setX(m_position.getX() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_velocity.setX(1);
	m_acceleration.setX(1);
	GameObject::update();
}
void Player::clean()
{

}
void Player::handleInput()
{
 //here
}
