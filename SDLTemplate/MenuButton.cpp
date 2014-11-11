#include "MenuButton.h"

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
	if (x < (m_x + m_width)
		&& x > m_x
		&& y < (m_y + m_height)
		&& y > m_y)
	{
		m_currentFrame = MOUSE_OVER;
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			m_currentFrame = CLICKED;
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