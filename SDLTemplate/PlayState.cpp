#include "PlayState.h"
#include "Game.h"
const string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{

		currentObject = m_gameObjects[i];
		m_gameObjects[i]->collision();
		

	}
}

void PlayState::render() //moved form game render
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

void PlayState::handleEvents(SDL_Event *event) //handle gameObject Input
{
	
			if (event->type == SDL_KEYDOWN)
			{
				
				switch (event->key.keysym.sym)
				{
				case SDLK_LEFT: {currentObject->mVel_x -= 10; currentObject->update(); currentObject->hspeed -= 10; } break;
				case SDLK_RIGHT: {currentObject->mVel_x += 10; currentObject->update(); currentObject->hspeed += 10; } break;
				case SDLK_UP: {currentObject->mVel_y -= 10; } break;
				case SDLK_DOWN: {currentObject->mVel_y += 10; } break;
				}
			}	
			else if (event->type == SDL_KEYUP)
			{

				switch (event->key.keysym.sym)
				{
				case SDLK_LEFT: {currentObject->reset(); currentObject->hspeed = 0; } break;
				case SDLK_RIGHT: {currentObject->reset(); currentObject->hspeed = 0; } break;
				/*case SDLK_UP: {currentObject->m_y -= 5; } break;
				case SDLK_DOWN: {currentObject->m_y += 5; } break;*/
				}
			}
}

bool PlayState::onEnter() //setup the Playstate
{
	cout << "entering playstate.\n";

	/*GameObject* m_go;
	GameObject* m_player;*/
	GameObject* m_enemy;
	if (!TheTextureManager::Instance()->load("animate.png",
		"animate", Game::Instance()->m_pRenderer))
	{
		return false;
	}

	/*m_go = new GameObject();
	m_player = new Player();*/
	m_enemy = new Enemy();

	/*m_go->load(100, 100, 128, 82, "animate");
	m_player->load(300, 300, 128, 82, "animate");*/
	m_enemy->load(0, 0, 128, 82, "animate");

	/*m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);*/
	m_gameObjects.push_back(m_enemy);
	return true;
}

bool PlayState::onExit()
{
	cout << "exiting playstate.\n";
	return true;
}

