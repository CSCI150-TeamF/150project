#include <SDL.h>
#include "Layer.h"
#include "includes.h"

#ifndef __Level__
#define __Level__

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	string name;
};

class Level
{
public:
	~Level(){}

	void update();
	void render();
	vector<Tileset>* getTilesets(){ return &m_tilesets; }
	vector<Layer*>* getLayers(){ return &m_layers; }
private:
	friend class LevelParser;
	Level();

	vector<Tileset> m_tilesets;
	vector<Layer*> m_layers;
};


#endif