#include "LevelParser.h"
#include "Base64.h"
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
}

void LevelParser::parseTileLayer(TiXmlElement* pTileElement, vector<Layer*> *pLayers, const vector<Tileset>* pTilesets)
{
	TileLayer* pTileLayer = new TileLayer(m_Tilesize, *pTilesets);

	//data of the tile
	vector<vector<int>> data;
	string decodedIDs;
	TiXmlElement* pDataNode;

	for (TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("data"))
		{
			pDataNode = e;
		}
	}

	for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
	{
		TiXmlText* text = e->ToText();
		string t = text->Value();
		decodedIDs = base64_decode(t);
	}
	//zlib needed for functions

	uLongf numGids = m_width * m_height * sizeof(int);
	vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

	vector<int> layerRow(m_width);

	for (int j = 0; j < m_height; ++j)
	{
		data.push_back(layerRow);
	}

	for (int rows = 0; rows < m_height; ++rows)
	{
		for (int cols = 0; cols < m_width; ++cols)
		{
			data[rows][cols] = gids[rows * m_width + cols];
		}
	}

	pTileLayer->setTileIDs(data);

	pLayers->push_back(pTileLayer);
}

void LevelParser::parseTextures(TiXmlElement* pTextureRoot)
{
TextureManager::Instance()->load(pTextureRoot->Attribute("value"),pTextureRoot->Attribure("name"),Game::Instance()->getRenderer();
}

void LevelParser::parseObjectLayer(TiXmlElement* pObjectElement,vector<Layer*> *pLayers)
{
//creat an object layer
ObjectLayer* pObjectLayer = new ObjectLayer();

cout<< pObjectElement->FirstChildElement();e!=NULL; e=e->NextSiblingElement())
{
cout<<e->Value();
if(e->Value() == string("object"))
{
  int x, y, width, height, numFrames, callbackID, animSpeed;
  string textureID;

  //get the initial node values type, x and y
  e->Attribute("x", &x);
  e->Attribute("y", &y);
                            //factory
  GameObject* pGameObject = GameObject::Instance()->create(e->Attribute("type"));

  //get the property values
  for(TiXmlElement* properties = e->FirstChildElement(); properties != NULL; properties = properties->NextSiblingElement())
  {
    if(properties->Value() == string("properties"))
	{
	   for(TiXmlElement* property = properties->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
	   {
	     if(property->Value() == string("property"))
		 {
		   if(property->Attribue("name") == string("numFrames"))
		   {
		     property->Attribute("value", &numFrames);
		   }
		   else if(property->Attribute("name") == string("textureHeight"))
		   {
		     property->Attribute("value",&height);
		   }
		   else if(property->Attribute("name") == string("textureID"))
		   {
		     textureID = property->Attribute("value");
		   }
		   else if(property->Attribute("name") == string("textureWidth"))
		   {
		     property->Attribute("value", &width);
		   }
		   else if(property->Attribute("name") == string("callbackID))
		   {
		     property->Attribute("value", &callbackID);
		   }
		   else if(e->Attribute("name") == string("animSpeed"))
		   {
		     property->Attribute("value", &animeSpeed);
		   }
		  }
	     }
        }
       }
       pGameObject->load(new LoaderParams(x,y,width,height,textureID,numFrames, callbackID, animSpeed));
       pObjectLayer->getGameObjects()->push_back(pGameObject);
      }
     }
     pLayers->push_back(pObjectLayer);
}
*/