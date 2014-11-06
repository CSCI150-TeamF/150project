#include "PlayState.h"
#include "Game.h"
const string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		m_gameObjects[i]->collision();
		m_gameObjects[i]->handleInput();
	}
}

void PlayState::render() //moved from game render
{
	SDL_RenderClear(TheGame::Instance()->getRenderer()); // clear to the draw colour
	// loop through our objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(TheGame::Instance()->getRenderer());
	}
	SDL_RenderPresent(TheGame::Instance()->getRenderer()); // draw to the screen
}

bool PlayState::onEnter() //setup the Playstate
{
	cout << "entering playstate.\n";

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	if (!TheTextureManager::Instance()->load("animate.png",
		"animate", Game::Instance()->m_pRenderer))
	{
		return false;
	}

	m_go = new GameObject();
	m_player = new Player();
	m_enemy = new Enemy();

	m_go->load(100, 100, 128, 82, "animate");
	m_player->load(300, 300, 128, 82, "animate");
	m_enemy->load(0, 0, 128, 82, "animate");

	m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_enemy);
	return true;
}

bool PlayState::onExit()
{
	cout << "exiting playstate.\n";
	return true;
}

