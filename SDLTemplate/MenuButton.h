#include"GameObject.h"
#include "LoaderParams.h"

class MenuButton : public GameObject
{
public:
	MenuButton(const LoaderParams* pParams);
	virtual void draw();
	virtual void update(SDL_Event* event, int x, int y);
	virtual void clean();
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2 
	};

};