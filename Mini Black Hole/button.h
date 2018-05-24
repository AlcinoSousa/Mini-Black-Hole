#ifndef BUTTON_H
#define BUTTON_H

#include "texture.h"

/*
	class Button represents the in-game buttons.
	the Credits In button -> adds credits to game
	the Start button -> starts/pauses the game
	the Credits Out button -> subtracts credits to game
*/


/**
	sprite to be used to draw the button. 
	the button sprite changes according to mouse position.
*/
enum buttonSprite 
{
	MOUSE_OUT_SPRITE = 0,
	MOUSE_DOWN_SPRITE = 1,
	MOUSE_OVER_SPRITE = 2
};

/**
	the three types of buttons.
*/
enum buttonType
{
	CREDITS_IN_BUTTON = 0,
	START_BUTTON = 1,
	CREDITS_OUT_BUTTON = 2,
};

/**
	the three possible game states.
*/
enum gameState
{
	BEFORE_PLAY_STATE = 0, 
	RUNNING_STATE = 1,
	PAUSED_STATE = 2
};


class Button
{
	private: 
		//the type of the button
		buttonType mButtonType;

		//the current sprite of the button
		buttonSprite mCurrentButtonSprite;

		//SDL_Point(int x, int y) representing the position of the button
		SDL_Point mButtonPosition; 

		//the texture of the button with which he will be drawn
		Texture* mButtonTexture;

		/**
			SDL Rect contains the definition of a rectangle. 
			each button has a sprite sheet with three possible sprites. 
			the mClips defines the position of the possible sprites inside the sprite sheet.
		*/
		SDL_Rect mClips[3];

		//the width of the button.
		int mButtonWidth; 

		//the height of the button.
		int mButtonHeight;

	public:
		//default constructor
		Button();

		//used to free resources. Destroys the used texture and respective pointer.
		void destroyButton();

		//get methods
		SDL_Point getButtonPosition();
		buttonSprite getCurrentButtonSprite();
		buttonType getButtonType();
		Texture* getButtonTexture();
		int getButtonWidth();
		int getButtonHeight();

		//set methods
		void setButtonType(buttonType buttonT);
		void setButtonWidth(int buttonWidth);
		void setButtonHeight(int buttonHeight);
		void setPos(int x_coord, int y_coord);
		void setSprite(buttonSprite sprite);
		void setButtonTexture(Texture* texture);
		void setMClips();

		/**
			renders the button to the rendering target 
			@param renderer the rendering context
		*/
		void renderWithSprite(SDL_Renderer* renderer);

		/**
			handles the button events.
			Sets the sprite to use. Changes game state and number of credits and removed credits

			@param e pointer to the event being handled
			@param gPlays pointer to the current number of plays
			@param gCredits pointer to the current number of credits
			@param gRemovedCredits pointer to the current number of removed credits
			@param currentGameState pointer to the current game state
		*/
		void handleEvent(SDL_Event* e,int* gPlays ,int* gCredits , int* gRemovedCredits, int* currentGameState);
};


#endif





