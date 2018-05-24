#ifndef MINIGAME_H
#define MINIGAME_H

#include "button.h"
#include "sceneObject.h"
#include "timer.h"
#include "window.h"

/**
	the total number of objects in the scene
	3 buttons
	50 objects in animation
	25 different textures
*/
enum gTotalObjects
{
	TOTAL_BUTTONS = 3,
	TOTAL_ANIMATED_OBJECTS = 50,
	TOTAL_OBJECT_TEXTURES = 25
};

/**
	time definitions
	the animation takes 33 seconds
	each object is animated for 8 seconds
	there is an interval of 0,5 seconds between objects starting the animation
*/
enum gAnimationTimes
{
	ANIMATION_TIME = 33000,
	NEXT_OBJECT_TIME = 500,
	OBJECT_ANIMATION_TIME = 8000
};

/**
	there are 3 possible game states
	BEFORE_PLAY, before a play takes place (the same as right after one ends)
	RUNNING, when the game is running
	PAUSED, when the game is paused
*/
enum gGameState
{
	BEFORE_PLAY = 0,
	RUNNING = 1,
	PAUSED = 2
};

//the actual game state
int gGameState; 

//the window to render
Window gWindow;

//the window renderer
SDL_Renderer* gRenderer;

//the background texture
Texture gPNGTextureBackground;

//the buttons textures
Texture buttonCreditsInTexture;
Texture buttonStartTexture;
Texture buttonCreditsOutTexture;

//the buttons
Button gButtons[TOTAL_BUTTONS];

//the animated objects
sceneObject gAnimatedObjects[TOTAL_ANIMATED_OBJECTS];

//the textures for the animated objects
Texture gObjectTextures[TOTAL_ANIMATED_OBJECTS];

//an array of strings with names to possible textures
std::string gObjectTexturesNames[TOTAL_OBJECT_TEXTURES];

//textures to render the display of plays
Texture gPlaysTextTexture;
Texture gPlaysTexture;

//textures to render the display of credits
Texture gCreditsTextTexture;
Texture gCreditsTexture;

//textures to render the display of removed credits
Texture gRemovedCreditsTextTexture;
Texture gRemovedCreditsTexture;

//texture to render the exit information
Texture gExitTextTexture;

//counters
int gPlays; //on plays
int gCredits; //on credits
int gRemovedCredits; //on removed credits

//timer for the new object callback function
SDL_TimerID timerNewObjectCallbackID;

//timer to end the animation through a callback
SDL_TimerID timerAnimationEndID;

//timer to use as step in the animation
//Timer stepTimer;

//timer to control the animation time
Timer animationTimer;

//determines if there is the need to set a timer to a callback function that creates a new object 
bool callbackNewObject;

//index for the list of the animated objects
int indexObject;

/**
	initilizes library components
	@return bool that determines the success of the operation

*/
bool initLibs();

//Frees up the used resources
void freeResources();

/**
	creates the textures for the objects from png files
	@return bool that determines the successful creation of the array
*/
bool createArrayOfTextures();

/**
	initializes the animated objects with predetermined properties
	@return bool that determines the successful initialization
*/
bool loadObjects();

/**
	initializes the button objects with predetermined properties
	@return bool that determines the successful initialization
*/
bool loadButtons();

/**
	initializes the display objects with predetermined properties
	@return bool that determines the successful initialization
*/
bool loadDisplays();

//loads the needed assets
bool loadMedia();

//called on ending. Frees the used resources
void freeResources();

//updates the display text of a given counter (plays, credits, removed credits)
void updateDisplay(std::stringstream* displayText, int* display, Texture* texture, SDL_Renderer* renderer);

//callback function used to end the animation after the animation time has ended
Uint32 callbackAnimationEnded(Uint32 interval, void* param);

//callback function used to create a new object for the animation after time to creation has passed
Uint32 callbackNewSceneObject(Uint32 interval, void* param);

/**
	draws on screen all the elements of the window.
	@param initialPlays previous count on plays
	@param firstRenderOfDisplays determines if first time drawing the displays
	@param displayPlaysText text of the plays display
	@param initialCredits previous count on credits
	@param displayCreditsText text of the credits display
	@param initialRemovedCredits previous count on removed credits
	@param displayRemovedCreditsText text of the removed credits display
*/
void draw(int* initialPlays, bool* firstRenderOfDisplays, std::stringstream* displayPlaysText,
	int* initialCredits, std::stringstream* displayCreditsText, int* initialRemovedCredits, std::stringstream* displayRemovedCreditsText);

#endif