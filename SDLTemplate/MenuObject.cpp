#include "MenuObject.h"

void MenuObject::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}
void MenuObject::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw();
}
void MenuObject::update()
{
	GameObject::update();
}