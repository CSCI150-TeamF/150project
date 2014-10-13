#include "Game.h"
#include "includes.h"
// our Game object
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
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
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
	
	if (!TheTextureManager::Instance()->load("animate.png",
		"animate", m_pRenderer))
	{
		return false;
	}
	
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());
	m_pGameStateMachine->changeState(new PlayState());
	

	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully, start the main loop
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
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
		case SDL_SCANCODE_RETURN:
			m_pGameStateMachine->changeState(new PlayState());
		default:
			break;
		}
		
	}
}
void Game::update()
{
	m_pGameStateMachine->update();
}