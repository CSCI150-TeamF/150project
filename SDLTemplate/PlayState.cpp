#include "PlayState.h"
#include "Game.h"
#include "MenuObject.h"
#include "math.h"

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
		currentObject->clean();
		
		


	}
	PlayState::CollisionCheck();
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
	
	float x = currentObject->getX();
	float y = currentObject->getY();
			if (event->type == SDL_KEYDOWN)
			{
				//get the x-value (m_x)
				
				switch (event->key.keysym.sym)
				{
				//update m_x, update direction, animate
				case SDLK_LEFT: {currentObject->setX(x -= 10); currentObject->updateDirection(-1); currentObject->update(); } break;
				case SDLK_RIGHT: {currentObject->setX(x += 10); currentObject->updateDirection(1); currentObject->update(); } break;
				case SDLK_UP:{currentObject->jumpFx();}break;
				case SDLK_BACKSPACE: {TheGame::Instance()->m_pGameStateMachine->changeState(new MenuState());} break;
				}
			}	
			else if (event->type == SDL_KEYUP)
			{

				switch (event->key.keysym.sym)
				{

					//reset the sprite frame
				case SDLK_LEFT: currentObject->reset(); break;
				case SDLK_RIGHT: currentObject->reset(); break;
				case SDLK_UP: currentObject->reset(); break;
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

void PlayState::CollisionCheck()
{
	GameObject* pPlayer;
	GameObject* nextObject;
	GameObject* nextObject2;
	GameObject* nextObject3;
	

	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		if (pPlayer = dynamic_cast<Player*>(currentObject));
			
	}
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		if (nextObject3 = dynamic_cast<BigComet*>(m_gameObjects[i]))
		{
			
			bigcometObject = m_gameObjects[i];
		}
	}
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		if (nextObject2 = dynamic_cast<Comet*>(m_gameObjects[i]))
		{
			
			cometObject = m_gameObjects[i];
		}
	}
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		if (nextObject = dynamic_cast<Bullet*>(m_gameObjects[i]))
		{
			
			bulletObject = m_gameObjects[i];
		}
	}


	
	
	
	plyRect.x = currentObject->getX() +25;
	plyRect.y = currentObject->getY() +25;
	plyRect.w = currentObject->m_width -50;
	plyRect.h = currentObject->m_height -10;

	plyDestRect.x = bulletObject->getX() + 3;
	plyDestRect.y = bulletObject->getY();
	plyDestRect.w = bulletObject->m_width-3;
	plyDestRect.h = bulletObject->m_height;
	
	comDestRect.x = cometObject->getX() + 3;
	comDestRect.y = cometObject->getY();
	comDestRect.w = cometObject->m_width - 3;
	comDestRect.h = cometObject->m_height;

	bigcomDestRect.x = bigcometObject->getX() + 3;
	bigcomDestRect.y = bigcometObject->getY();
	bigcomDestRect.w = bigcometObject->m_width - 3;
	bigcomDestRect.h = bigcometObject->m_height;

	if (SDL_HasIntersection(&plyRect,
		&plyDestRect))
	{
		cout << "Collision";
		
		TheGame::Instance()->m_pGameStateMachine->changeState(new MenuState());
	}
	if (SDL_HasIntersection(&plyRect,
		&comDestRect))
	{
		cout << "Collision";

		TheGame::Instance()->m_pGameStateMachine->changeState(new MenuState());
	}
	if (SDL_HasIntersection(&plyRect,
		&bigcomDestRect))
	{
		cout << "Collision";

		TheGame::Instance()->m_pGameStateMachine->changeState(new MenuState());
	}

	
	
}

