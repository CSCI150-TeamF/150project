#include "includes.h"
#include "SDL.h"

//general form for all game states

#ifndef __GameState__
#define __GameState__
class GameState
{
public:
	
	virtual void update() = 0;
	virtual void handleEvents(SDL_Event *event) = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual string getStateID() const = 0;

protected:
	vector<string> m_textureIDList;
};
#endif