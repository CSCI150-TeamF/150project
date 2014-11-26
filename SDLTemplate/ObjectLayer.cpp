#include "ObjectLayer.h"
#include "includes.h"

void ObjectLayer::update()
{
	for (int i = 0; i < m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->update();
	}
}

void ObjectLayer::render()
{
	for (int i = 0; i < m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->draw();
	}
}