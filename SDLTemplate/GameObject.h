#include <SDL.h>
#include "TextureManager.h"
#include "includes.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "StateParser.h"


// All objects that are rendered should inherit this class

//*****************************************************************************************//
// SPECIAL NOTE: GAME OBJECT AND VECTOR 2D GET/SET FUNCTIONS USE/RETURN FLOAT and NOT INT! //
// IF YOU HAVE PROBLEMS CHECK THAT THE TYPES MATCH! Cast as Needed.                        //
//*****************************************************************************************//


#ifndef __GameObject__
#define __GameObject__
class GameObject
{
public:
	GameObject(const LoaderParams* pParams)
	{
		
		m_width = pParams->getWidth();
		m_height = pParams->getHeight();
		m_textureID = pParams->getTextureID();
		m_currentRow = 1;
		m_currentFrame = 1;
		m_position = new Vector2D(pParams->getX(), pParams->getY());
	}
	GameObject(){}
	virtual void collision();
	virtual void load(const LoaderParams* pParams);
	virtual void draw(); //No longer requires SDL renderer. renderer is inside function
	virtual void updateDirection(int dirSign);
	virtual void update();
	virtual void update(SDL_Event* event, int x, int y){}
	virtual void jumpFx();
	virtual void reset();
	virtual void clean();
	static const int speed = 10;
	virtual void setX(float x);
	virtual float getX();
	virtual void setY(float y);
	virtual float getY();
	int flipFlag;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	
	bool isJump = false;
	bool isFall = false;
	int jump = 0;
	const int jumpH = 10;

protected:
	string m_textureID;
	
	int m_direction = 0;
	
	bool left;
	bool right;
	Vector2D* m_position;
	Vector2D* m_velocity;
	
};
#endif