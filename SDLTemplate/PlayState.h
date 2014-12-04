#include "GameState.h"
#include "GameObject.h"
#include "LevelParser.h"
#include "StateParser.h"

//state we use to render the game
#ifndef __PlayState__
#define __PlayState__
class PlayState : public GameState
{
public:

	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event *event);
	virtual bool onEnter();
	virtual bool onExit();
	virtual void CollisionCheck();
	float playerPos;
	virtual string getStateID() const { return s_playID; }


	SDL_Rect plyRect;
	SDL_Rect plyDestRect;
	SDL_Rect comDestRect;
	SDL_Rect bigcomDestRect;
	static const string s_playID;
	vector<GameObject*> m_gameObjects;
	GameObject *currentObject;
	GameObject *bulletObject;
	GameObject *cometObject;
	GameObject *bigcometObject;
	const Uint8 *keystate = NULL;

};
#endif