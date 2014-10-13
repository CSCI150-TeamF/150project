#include <SDL.h>
#include <SDL_image.h>
#include "GameState.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"


#ifndef __Game__
#define __Game__

class Game
{
public:
	~Game() {}
	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	SDL_Renderer* getRenderer(){ return m_pRenderer; }
	// a function to access the private running variable
	bool running() { return m_bRunning; }
	//std::vector<GameObject*> m_gameObjects;
	GameStateMachine* m_pGameStateMachine;
	SDL_Renderer* m_pRenderer;
	
	static Game* Instance() //create only one instance of game
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	SDL_Window* m_pWindow;
	int m_currentFrame;
	bool m_bRunning;
	static Game* s_pInstance;
	Game() {}
};
typedef Game TheGame;
#endif