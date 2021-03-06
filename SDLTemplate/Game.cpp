#include "Game.h"
#include "includes.h"
// our Game object
//Game is static. all references to game are now refering to the same Single Game object
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	
	//Create GameState Machine
	m_pGameStateMachine = new GameStateMachine();
	//create and Push initial Gamestates
	m_pGameStateMachine->changeState(new MenuState());
	
	TheGameObjectFactory::Instance()->registerType("Stars", new StarsCreator());
	TheGameObjectFactory::Instance()->registerType("Planet", new PlanetCreator());
	TheGameObjectFactory::Instance()->registerType("BigComet", new BigCometCreator());
	TheGameObjectFactory::Instance()->registerType("Comet", new CometCreator());
	TheGameObjectFactory::Instance()->registerType("Bullet", new BulletCreator());
	TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	
	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully, start the main loop
	return true;
}



void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear Renderer
	m_pGameStateMachine->render(); //prepare render current state
	SDL_RenderPresent(m_pRenderer); //render the stuff set up by GameStateMachine
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	IMG_Quit();
	SDL_Quit();
}
void Game::handleEvents()
{
	
	//needs update
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_SCANCODE_RETURN: //NOTE: This does nothing. Why?
			m_pGameStateMachine->changeState(new PlayState());
			break;
		default:
			break;
		}

		//current GameState -> handleEvents
		m_pGameStateMachine->handleEvents(&event);
		

	}
}
void Game::update()
{
	m_pGameStateMachine->update(); //update the current state
}
