#include <SDL.h>
#include "Level.h"
#include "includes.h"

#ifndef __LevelParser__
#define __LevelParser__

class LevelParser
{
public:
	Level* parseLevel(const char* levelFile);

private:
	//void parseTilesets(TiXmlElement* pTilesetRoot, vector<Tileset>* pTilesets);

	//void parseTileLayer(TiXmlElement* pTileElement, vector<Layer*> *pLayers, const vector<Tileset>* pTilesets);

	int m_tileSize;
	int m_width;
	int m_height;
};

#endif