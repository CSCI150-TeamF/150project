#include "includes.h"
#include "GameState.h"
#include "SDL.h"

//state used for inventory/pause
class MenuState : public GameState
{
public:
	virtual void update();
	virtual void handleEvents(SDL_Event *event);
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;
};