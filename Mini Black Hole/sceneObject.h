#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "texture.h"

/** 
	Class sceneObject represents the animated objects in the scene.
	All of them have the same properties and behaviour
*/

/**
	Each object has 3 possible animation states
*/
enum animationState
{
	BEFORE_ANIMATION = 0, 
	ANIMATION_GOING = 1,
	ANIMATION_ENDED = 2,
	ANIMATION_PAUSED = 3,
	
};

class sceneObject
{
	private:
		//the velocities used to animate the object
		int mVelocityX;
		int mVelocityY;

		//the actual position of the object
		SDL_Point mPosition;

		//the original position of the object
		SDL_Point mOriginalPosition;

		//the original velocity of the object 
		int mOriginalVelocityX;
		int mOriginalVelocityY;	

		//the dimensions of the object
		int mWidth;
		int mHeight;

		//the texture of the object
		Texture* mObjectTexture;

		//the state of the object
		animationState mAnimationState;

		//time when the animation started 
		float mAnimationStartTime;
		
	public:
		//default constructor
		sceneObject();

		//used to free resources. Destroys the used texture and respective pointer.
		void destroySceneObject();
		
		//get methods
		int getVelocityX();
		int getVelocityY();
		SDL_Point getPosition();
		SDL_Point getOriginalPosition();
		Texture* getObjectTexture();
		int getObjectWidth();
		int getObjectHeight();
		int getOriginalVelocityX();
		int getOriginalVelocityY();
		animationState getAnimationState();
		float getAnimationStartTime();

		//set methods
		void setVelocityX(int velocityX);
		void setVelocityY(int velocityY);
		void setPosition(int posX, int posY);
		void setOriginalPosition(int posX, int posY);
		void setObjectTexture(Texture* texture);
		void setObjectWidth(int objectWidth);
		void setObjectHeight(int objectHeight);
		void setOriginalVelocityX(int originalVelocityX);
		void setOriginalVelocityY(int originalVelocityY);
		void setAnimationState(animationState objectAnimationState);
		void setAnimationStartTime(float currentAnimationTime);

		/**
			updates the position of the object in the animation using a time step
			@param timeStep used to adjust the position of the object
		*/
		void update(float timeStep);

		/**
			renders the object
			@param randerer pointer to the rendering context
		*/
		void render(SDL_Renderer* renderer);

		//resets the properties of the object in the end of the animation
		void reset();
};

#endif