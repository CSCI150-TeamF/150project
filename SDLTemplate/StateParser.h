#include "tinyxml.h"
#include "includes.h"
class GameObject;

#ifndef __StateParser__
#define __StateParser__
class StateParser
{
public:
	bool parseState(const char* stateFile, string stateID, vector<GameObject*> *pObjects, std::vector<std::string> *pTextureIDs);
private:
	void parseObjects(TiXmlElement* pStateRoot, vector<GameObject*> *pObjects);
	void parseTextures(TiXmlElement* pStateRoot, vector<string> *pTextureIDs);
};
#endif