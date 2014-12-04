#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton(const LoaderParams* pParams) :
GameObject(pParams)
{
	m_currentFrame = MOUSE_OUT; // start at frame 0
	updateDirection(1);
}
void MenuButton::draw()
{
	GameObject::draw(); // use the base class drawing
}
void MenuButton::update(SDL_Event* event, int x, int y)
{
	

	if (x < ((int)m_position->getX() + m_width)
		&& x >(int)m_position->getX()
		&& y < ((int)m_position->getY() + m_height)
		&& y >(int)m_position->getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			m_currentFrame = CLICKED;
			if (getY() < 300)
			{
				TheGame::Instance()->m_pGameStateMachine->changeState(new PlayState());
			}
			else
				TheGame::Instance()->m_bRunning = false;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}
void MenuButton::clean()
{
	GameObject::clean();
}