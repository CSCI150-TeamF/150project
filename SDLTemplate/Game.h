#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include "Player.h"

GameObject m_go;
Player m_player;

#ifndef __Game__
#define __Game__
class Game
{
public:
	Game() {}
	~Game() {}
	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	// a function to access the private running variable
	bool running() { return m_bRunning; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int m_currentFrame;
	bool m_bRunning;
};
#endif