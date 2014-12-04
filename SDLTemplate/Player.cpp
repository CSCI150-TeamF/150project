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
	
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::jumpFx()
{

	if (isJump != true)
	{
		isJump = true;
	}

	float y = getY();
	if (isJump == true)
	{
		if (jump >= jumpH || isFall == true)
		{
			jump--;
			if (jump == 0)
			{
				isJump = false;
				isFall = false;
				
			}
			m_position->setY(++y);
			isFall = true;
		}
		else if (jump <= 0 && isFall == true)
		{
			jump - 0;
			isFall = false;
			isJump = false;
		}
		else
		{
			jump++;
			setY(--y);
		}
	}
}

void Player::clean()
{
	
	
}
void Player::handleInput()
{
 //here
}
