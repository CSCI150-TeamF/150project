#include <SDL.h>
#include "includes.h"

#ifndef __Layer__
#define __Layer__

class Layer
{
public:
	Layer();
	~Layer(){}

	void render();
	void update();
};

#endif