#include "MenuState.h"
#include "Game.h"
#include "MenuButton.h"
//implement menu
const std::string MenuState::s_menuID = "MENU";
void MenuState::update()
{
/*	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		MenuState::m_gameObjects[i]->update();
	} */
}

void MenuState::render()
{
	/*SDL_RenderClear(TheGame::Instance()->getRenderer()); // clear to the draw colour
	// loop through our objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(TheGame::Instance()->getRenderer()); // draw to the screen
	*/
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void MenuState::handleEvents(SDL_Event *event)
{

	if (event->type == SDL_KEYDOWN)
	{
		//get the x-value (m_x)

		switch (event->key.keysym.sym)
		{
			//update m_x, update direction, animate
		case SDLK_UP: {} break;
		case SDLK_DOWN: {} break;
		case SDLK_SPACE: {TheGame::Instance()->m_pGameStateMachine->changeState(new PlayState()); } break;
		}
	}

	if (event->type == SDL_MOUSEMOTION)
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		m_gameObjects[i]->update(event, event->motion.x, event->motion.y); 
	}
	
}
bool MenuState::onEnter()
{
	cout << "Entering MenuState\n";
	if (!TheTextureManager::Instance()->load("button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100,
		400, 100, "playbutton"));
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300,
		400, 100, "exitbutton"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	cout << "entering MenuState\n";
	return true;
}
bool MenuState::onExit()
{
	std::cout << "exiting MenuState\n";
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}