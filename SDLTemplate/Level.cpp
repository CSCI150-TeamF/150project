#include "Level.h"
#include "includes.h"

//render for levels using the layers
void Level::render()
{
	for (size_t i = 0; i < m_layers.size(); ++i)
	{
		m_layers[i]->render();
	}
}
//updates the level using the layers
void Level::update()
{
	for (size_t i = 0; i < m_layers.size(); ++i)
	{
		m_layers[i]->update();
	}
}