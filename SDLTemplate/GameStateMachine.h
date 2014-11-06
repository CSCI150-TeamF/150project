#include "GameState.h"
#include "SDL.h"

class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void handleEvents(SDL_Event *e);
	void update();
	void render();
private:
	vector<GameState*> m_gameStates;
};