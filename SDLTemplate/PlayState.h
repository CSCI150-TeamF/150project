#include "GameState.h"
#include "GameObject.h"
//state we use to render the game
#ifndef __PlayState__
#define __PlayState__
class PlayState : public GameState
{
public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual string getStateID() const { return s_playID; }
private:
	static const string s_playID;
	vector<GameObject*> m_gameObjects;

};
#endif