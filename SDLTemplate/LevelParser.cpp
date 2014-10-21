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

*/