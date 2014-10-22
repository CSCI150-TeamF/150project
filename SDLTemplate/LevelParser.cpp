#include "LevelParser.h"
#include "includes.h"
/* //Needs TiXmlDocument in order to Run correctly

Level* LevelParser::parseLevel(const char *levelFile)
{
//create and load map XML
TiXmlDocument levelDocument;
levelDocument.LoadFile(levelFile);

//create level object
Level* pLevel = new Level();

//get root
TiXmlElement* pRoot = levelDocument.RootElement();

pRoot->Attribute("tilewidth", &m_tileSize);
pRoot->Attribute("width", &m_width);
pRoot->Attribute("height", &m_height);

//parse tilesets
for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
{
if (e->Value() == string("tileset"))
{
parseTilesets(e, pLevel->getTilesets());
}
}

//parse object layers
for (TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
{
if (e->Value() == ("layer"))
{
parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
}
}

return pLevel;
}


void LevelParser::parseTilesets(TiXmlElement* pTilesetRoot,vector<Tileset>* pTilesets)
{
	//adding tileset to the texture manager
	TextureManager::Instance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"), pTilesetRoot->Attribute("name"), Game::Instance()->getRenderer());

	//create a Tileset object
	Tileset tileset;
	pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
	pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
	pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
	pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
	pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
	pTilesetRoot->Attribute("spacing", &tileset.spacing);
	pTilesetRoot->Attribute("margin", &tileset.margin);
	tileset.name = pTilesetRoot->Attribute("name");

	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

	pTilesets->push_back(tileset);
}*/