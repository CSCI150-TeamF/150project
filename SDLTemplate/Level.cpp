#include "Level.h"
#include "includes.h"


void Level::render()
{
	for (size_t i = 0; i < m_layers.size(); ++i)
	{
		m_layers[i]->render();
	}
}

void Level::update()
{
	for (size_t i = 0; i < m_layers.size(); ++i)
	{
		m_layers[i]->update();
	}
}