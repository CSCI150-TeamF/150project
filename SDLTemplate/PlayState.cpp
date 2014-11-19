#include "PlayState.h"
#include "Game.h"
#include "MenuObject.h"
const string PlayState::s_playID = "PLAY";

//*****************************************************************************************//
// SPECIAL NOTE: GAME OBJECT AND VECTOR 2D GET/SET FUNCTIONS USE/RETURN FLOAT and NOT INT! //
// IF YOU HAVE PROBLEMS CHECK THAT THE TYPES MATCH! Cast as Needed.                        //
//*****************************************************************************************//

void PlayState::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{


		currentObject = m_gameObjects[i];
		currentObject->collision();


	}
}

void PlayState::render() //moved from game render
{
	SDL_RenderClear(TheGame::Instance()->getRenderer()); // clear to the draw colour
	// loop through our objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i !=m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(TheGame::Instance()->getRenderer()); // draw to the screen
}

void PlayState::handleEvents(SDL_Event *event) //handle gameObject Input
{
	
	
			if (event->type == SDL_KEYDOWN)
			{
				//get the x-value (m_x)
				float x = currentObject->getX();
				switch (event->key.keysym.sym)
				{
				//update m_x, update direction, animate
				case SDLK_LEFT: {currentObject->setX(x -= 10); currentObject->updateDirection(-1); currentObject->update(); } break;
				case SDLK_RIGHT: {currentObject->setX(x += 10); currentObject->updateDirection(1); currentObject->update(); } break;
				case SDLK_SPACE: {TheGame::Instance()->m_pGameStateMachine->changeState(new MenuState()); } break;
				}
			}	
			else if (event->type == SDL_KEYUP)
			{

				switch (event->key.keysym.sym)
				{
					//reset the sprite frame
				case SDLK_LEFT: currentObject->reset(); break;
				case SDLK_RIGHT: currentObject->reset(); break;
				}
			}
}

bool PlayState::onEnter() //setup the Playstate
{
	cout << "entering playstate.\n";

	GameObject* m_enemy;
	if (!TheTextureManager::Instance()->load("animate-alpha.png",
		"animate", Game::Instance()->m_pRenderer))
	{
		return false;
	}

	cout << "1";
	m_enemy = new Enemy();
	cout << "3";
	m_enemy->load(0.0, 480.0, 128, 82, "animate");
	cout << "2";
	m_gameObjects.push_back(m_enemy);

	return true;
}

bool PlayState::onExit()
{
	cout << "exiting playstate.\n";
	return true;
}

