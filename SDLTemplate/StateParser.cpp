#include "StateParser.h"
#include "Game.h"

GameObjectFactory* GameObjectFactory::pInstance = 0;

bool StateParser::parseState(const char *stateFile, string stateID, vector<GameObject *> *objctPtr, vector<string> *pTextureIDs)
{
	
	// create the XML document (object that interfaces with XML Document)
	TiXmlDocument xmlDoc;
	
	// load the state file
	if (!xmlDoc.LoadFile(stateFile))
	{
		cerr << xmlDoc.ErrorDesc() << "\n";
		return false;
	}
	
	// get the root element
	TiXmlElement* Rootpointer = xmlDoc.RootElement();
	// pre declare the states root node
	
	TiXmlElement* StateRoot = 0;
	
	for (TiXmlElement* e = Rootpointer->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == stateID)
		{
			StateRoot = e;
		}
	}
	
	TiXmlElement* TextureRoot = 0;
	
	// get the root of the texture elements
	for (TiXmlElement* e = StateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("TEXTURES"))
		{
			TextureRoot = e;
		}
	}
	
	// now parse the textures
	parseTextures(TextureRoot, pTextureIDs);
	
	// pre declare the object root node
	TiXmlElement* ObjectRoot = 0;
	
	// get the root node and assign it to pObjectRoot
	for (TiXmlElement* e = StateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if (e->Value() == string("OBJECTS"))
		{
			ObjectRoot = e;
		}
	}

	// now parse the objects
	parseObjects(ObjectRoot, objctPtr);
	
	return true;
}

void StateParser::parseTextures(TiXmlElement* StateRoot, vector<string> *TextIDPtr)
{
	for (TiXmlElement* e = StateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		string filenameAttribute = e->Attribute("filename");
		string idAttribute = e->Attribute("ID");
		TextIDPtr->push_back(idAttribute); // push into list
		TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheGame::Instance()->getRenderer()); // load texture into Txture manager
	}
}

void StateParser::parseObjects(TiXmlElement *StateRoot, vector<GameObject *> *objctPtr)
{
	for (TiXmlElement* e = StateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackID, animSpeed;
		string textureID;
		e->Attribute("x", &x);
		e->Attribute("y", &y);
		e->Attribute("width", &width);
		e->Attribute("height", &height);

		textureID = e->Attribute("textureID");
		GameObject* gameObjptr = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
		
		for (int i = 0; i < 1; i++)
		{
			gameObjptr->load(new LoaderParams(x, y, width, height, textureID)); //here
			objctPtr->push_back(gameObjptr);
		}
	}
}