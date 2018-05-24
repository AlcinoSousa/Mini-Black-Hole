#include "sceneObject.h"

//default constructor
sceneObject::sceneObject()
{
	//velocities of the object
	mVelocityX = 0;
	mVelocityY = 0;
	//the actual position of the object
	mPosition.x = 0;
	mPosition.y = 0;
	//pointer to the texture of the object
	mObjectTexture = NULL;
	//the dimensions of the object
	mWidth = 20;
	mHeight = 20;
	mOriginalPosition.x = 0;
	mOriginalPosition.y = 0;
	mOriginalVelocityX = 0;
	mOriginalVelocityY = 0;
	mAnimationState = BEFORE_ANIMATION;
	mAnimationStartTime = 0;
};

//free resources
void sceneObject::destroySceneObject()
{
	mVelocityX = 0;
	mVelocityY = 0;
	mPosition.x = 0;
	mPosition.y = 0;
	mOriginalPosition.x = 0;
	mOriginalPosition.y = 0;
	mOriginalVelocityX = 0;
	mOriginalVelocityY = 0;
	mWidth = 0;
	mHeight = 0;
	//destroying texture and respective pointer
	if(mObjectTexture)
	{
		mObjectTexture->destroyTexture();
	}
	mAnimationState = BEFORE_ANIMATION;
	mAnimationStartTime = 0;
}

//get methods
int sceneObject::getVelocityX()
{
	return mVelocityX;
};
int sceneObject::getVelocityY()
{
	return mVelocityY;
};
SDL_Point sceneObject::getPosition()
{
	return mPosition;
};
SDL_Point sceneObject::getOriginalPosition()
{
	return mOriginalPosition;
};
Texture* sceneObject::getObjectTexture()
{
	return mObjectTexture;
};
int sceneObject::getObjectWidth()
{
	return mWidth;
};
int sceneObject::getObjectHeight()
{
	return mHeight;
};
animationState sceneObject::getAnimationState()
{
	return mAnimationState;
};
int sceneObject::getOriginalVelocityX()
{
	return mOriginalVelocityX;
}
int sceneObject::getOriginalVelocityY()
{
	return mOriginalVelocityY;
}
float sceneObject::getAnimationStartTime()
{
	return mAnimationStartTime;
}

//set methods
void sceneObject::setVelocityX(int velocityX)
{
	mVelocityX = velocityX;
};
void sceneObject::setVelocityY(int velocityY)
{
	mVelocityY = velocityY;
};
void sceneObject::setPosition(int posX, int posY)
{
	mPosition.x = posX;
	mPosition.y = posY;
};
void sceneObject::setOriginalPosition(int posX, int posY)
{
	mOriginalPosition.x = posX;
	mOriginalPosition.y = posY;
};
void sceneObject::setObjectTexture(Texture* texture)
{
	mObjectTexture = texture;
};
void sceneObject::setObjectWidth(int objectWidth)
{
	mWidth = objectWidth;
};
void sceneObject::setObjectHeight(int objectHeight)
{
	mHeight = objectHeight;
};
void sceneObject::setAnimationState(animationState objectAnimationState)
{
	mAnimationState = objectAnimationState;
};
void sceneObject::setOriginalVelocityX(int originalVelocityX)
{
	mOriginalVelocityX = originalVelocityX;
}
void sceneObject::setOriginalVelocityY(int originalVelocityY)
{
	mOriginalVelocityY = originalVelocityY;
}
void sceneObject::setAnimationStartTime(float currentAnimationTime)
{
	mAnimationStartTime = currentAnimationTime;
}

//updates the position of the object in the animation using a time step
void sceneObject::update(float timeStep)
{	
	//reached the screen border on right. invert velocity on X
	if(mPosition.x > 880) 
	{
		//avoid bugging jumps
		mPosition.x = 879;
		mVelocityX =-mVelocityX;
	}
	//reached the screen border on left. invert velocity on X
	if(mPosition.x < 125)
	{
		//avoid bugging jumps
		mPosition.x = 126;
		mVelocityX =-mVelocityX;
	}	

	//adjust current position with timeStep
	mPosition.x = mPosition.x + mVelocityX*timeStep;
	mPosition.y = mPosition.y + mVelocityY*timeStep;
};

//renders the object
void sceneObject::render(SDL_Renderer* renderer)
{
	mObjectTexture->render(renderer, mPosition.x, mPosition.y, NULL);
}

//resets the properties of the object
void sceneObject::reset()
{
	mPosition.x = mOriginalPosition.x;
	mPosition.y = mOriginalPosition.y;
	mVelocityX = mOriginalVelocityX;
	mVelocityY = mOriginalVelocityY;
	mAnimationStartTime = 0;
	mAnimationState = BEFORE_ANIMATION;
};