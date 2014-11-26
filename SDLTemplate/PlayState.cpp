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
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{


		currentObject = m_gameObjects[i];
		currentObject->collision();


	}
}

void PlayState::render() //moved from game render
{
	SDL_RenderClear(TheGame::Instance()->getRenderer()); // clear to the draw colour
	// loop through our objects and draw them
	for (vector<GameObject*>::size_type i = 0; i !=m_gameObjects.size(); i++)
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

	StateParser stateParser;
	stateParser.parseState("play.xml", s_playID, &m_gameObjects, &m_textureIDList);

	return true;
}

bool PlayState::onExit()
{
	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	cout << "exiting playstate.\n";
	return true;
}

