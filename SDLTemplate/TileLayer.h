#include <SDL.h>
#include "Level.h"
#include "includes.h"

#ifndef __TileLayer__
#define __TileLayer__

class TileLayer : public Layer
{
public:
	TileLayer(int tileSize, const vector<Tileset> &tilesets);

	virtual void update();
	virtual void render();

	void setTileIDs(const vector<vector<int>> &data)
	{
		m_tileIDs = data;
	}

	void setTileSize(int tileSize)
	{
		m_tileSize = tileSize;
	}

	Tileset getTilesetByID(int tileID);

private:

	int m_numColumns;
	int m_numRows;
	int m_tileSize;

	//needed to scroll map used later
	//Vector2D m_position;
	//Vector2D m_velocity;

	const vector<Tileset> &m_tilesets;
	vector<vector<int>> m_tileIDs;
};

#endif