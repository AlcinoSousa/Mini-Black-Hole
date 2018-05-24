#include "button.h"

//default constructor
Button::Button()
{
	mButtonType = CREDITS_IN_BUTTON;
	mButtonPosition.x = 0;
	mButtonPosition.y = 0;
	mCurrentButtonSprite = MOUSE_OUT_SPRITE;
	mButtonTexture = NULL;
	mButtonWidth = 200; 
	mButtonHeight = 200;
	//sets the sprite clips automatically
	setMClips();
};

//free resources
void Button::destroyButton()
{
	//Calls the texture method to free resources
	if(mButtonTexture)
	{
		mButtonTexture->destroyTexture();
	}
	mButtonType = CREDITS_IN_BUTTON;
	mButtonPosition.x = 0;
	mButtonPosition.y = 0;
	mCurrentButtonSprite = MOUSE_OUT_SPRITE;
	//Sets the pointer to NULL
	mButtonTexture = NULL;
	mButtonWidth = 0; 
	mButtonHeight = 0;
}

//get methods
SDL_Point Button::getButtonPosition()
{
	return mButtonPosition;
};
buttonSprite Button::getCurrentButtonSprite()
{
	return mCurrentButtonSprite;
};
buttonType Button::getButtonType()
{
	return mButtonType;
}
Texture* Button::getButtonTexture()
{
	return mButtonTexture;
};
int Button::getButtonWidth()
{
	return mButtonWidth;
};
int Button::getButtonHeight()
{
	return mButtonHeight;
};

//set methods
void Button::setButtonType(buttonType buttonT)
{
	mButtonType = buttonT;
}
void Button::setButtonHeight(int buttonHeight)
{
	mButtonHeight = buttonHeight;
};
void Button::setButtonWidth(int buttonWidth)
{
	mButtonWidth = buttonWidth;
};
void Button::setPos(int x_coord, int y_coord)
{
	mButtonPosition.x = x_coord;
	mButtonPosition.y = y_coord;
};
void Button::setSprite(buttonSprite sprite)
{
	mCurrentButtonSprite = sprite;
};
void Button::setButtonTexture(Texture* texture)
{
	mButtonTexture = texture;
};
void Button::setMClips(){
	//Each button sprite sheet has three possible sprites
	for(int sprite = 0; sprite < 3; ++sprite)
	{
		//Each sprite is defined by the top left point (x,y) and a width (w) and height (h)
		mClips[sprite].x = 0; 
		mClips[sprite].y = sprite * mButtonHeight;; 
		mClips[sprite].w = mButtonWidth; 
		mClips[sprite].h = mButtonHeight; 
	}

};


//rendering button with the desired sprite
void Button::renderWithSprite(SDL_Renderer* renderer)
{
	//Renders the button texture in the rendering context (renderer) in the button position with the current sprite.
	mButtonTexture->render(renderer, mButtonPosition.x, mButtonPosition.y, &mClips[mCurrentButtonSprite]);
};

void Button::handleEvent(SDL_Event* e, int* gPlays, int* gCredits, int* gRemovedCredits,  int* currentGameState)
{
	//if the event corresponds to a mouse event (movement or pressing button)
	if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//actual position of the mouse
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		//determines if the mouse is inside or outside the button
		bool inside = true;

		//mouse is left of the button
		if(mouseX < mButtonPosition.x)
		{
			inside = false;
		}
		//mouse is right of the button
		else if(mouseX >  mButtonPosition.x + mButtonWidth)
		{
			inside = false;
		}
		//mouse is above the button
		else if(mouseY <  mButtonPosition.y)
		{
			inside = false;
		}
		//mouse is below the button
		else if(mouseY > mButtonPosition.y + mButtonHeight)
		{
			inside = false;
		}

		//mouse is outside button
		if(!inside)
		{
			//updating the sprite
			mCurrentButtonSprite = MOUSE_OUT_SPRITE;
		}
		//mouse is inside button
		else
		{
			switch( e->type )
			{
				//if the mouse is moving
				case SDL_MOUSEMOTION:
					//updating the sprite
					mCurrentButtonSprite = MOUSE_OVER_SPRITE;
				break;
				//if the mouse is pressed
				case SDL_MOUSEBUTTONDOWN:
					//updating the sprite
					mCurrentButtonSprite = MOUSE_DOWN_SPRITE;
					switch(mButtonType) 
					{
						//button pressed was the credits in button
						case CREDITS_IN_BUTTON:
							++*gCredits;
							break;
						//button pressed was the start button
						case START_BUTTON :
							//according to current game state
							switch(*currentGameState)
							{
								//not running
								case BEFORE_PLAY_STATE:
									//if the player has at least one credit
									if(*gCredits > 0)
									{	
										//starts game
										*currentGameState = RUNNING_STATE;
										--*gCredits;
									}
									break;
								//game is already running
								case RUNNING_STATE:
									//pauses the game
									*currentGameState = PAUSED_STATE;
									break;
								case PAUSED_STATE:
									//unpauses the game
									*currentGameState = RUNNING_STATE;
									break;
							}
						  break;
						//button pressed is the credits out button
						case CREDITS_OUT_BUTTON :
							//if there are credits to remove
							if(*gCredits > 0)
							{
								//removes credit and increases removed credits
								--*gCredits;
								++*gRemovedCredits;
							}
						  break;
					}
				break;
			}
		}
		
	}
};
