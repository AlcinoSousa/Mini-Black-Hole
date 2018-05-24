#include "minigame.h"

//initializes library components
bool initLibs()
{
	bool initialized = true;
	//initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		initialized = false;
	}
	else
	{
		//creating the window
		if(!gWindow.init())
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			initialized = false;
		}
		else
		{
			//creating vsynced renderer for window
			gRenderer = gWindow.createRenderer();
			if(gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				initialized = false;
			}
			else
			{
				//initializing PNG loading
				int imgFlags = IMG_INIT_PNG;
				if(IMG_Init(imgFlags) != imgFlags)
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					initialized = false;
				}
				 //initializing SDL_ttf to use fonts
				if(TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					initialized = false;
				}
			}
		}
	}
	return initialized;
}

bool createArrayOfTextures()
{
	bool success = true;
	//filling the array with paths to files for textures
	gObjectTexturesNames[0] = "media/images/objects/meteor_1.png";
	gObjectTexturesNames[1] = "media/images/objects/meteor_2.png";
	gObjectTexturesNames[2] = "media/images/objects/meteor_3.png";
	gObjectTexturesNames[3] = "media/images/objects/meteor_4.png";
	gObjectTexturesNames[4] = "media/images/objects/meteor_5.png";
	gObjectTexturesNames[5] = "media/images/objects/planet_1.png";
	gObjectTexturesNames[6]	= "media/images/objects/planet_2.png";
	gObjectTexturesNames[7]	= "media/images/objects/planet_3.png";
	gObjectTexturesNames[8] = "media/images/objects/planet_4.png";
	gObjectTexturesNames[9] = "media/images/objects/planet_5.png";
	gObjectTexturesNames[10] = "media/images/objects/planet_6.png";
	gObjectTexturesNames[11] = "media/images/objects/planet_7.png";
	gObjectTexturesNames[12] = "media/images/objects/spaceship_1.png";
	gObjectTexturesNames[13] = "media/images/objects/spaceship_2.png";
	gObjectTexturesNames[14] = "media/images/objects/star_1.png";
	gObjectTexturesNames[15] = "media/images/objects/star_2.png";
	gObjectTexturesNames[16] = "media/images/objects/star_3.png";
	gObjectTexturesNames[17] = "media/images/objects/star_4.png";
	gObjectTexturesNames[18] = "media/images/objects/star_5.png";
	gObjectTexturesNames[19] = "media/images/objects/star_6.png";
	gObjectTexturesNames[20] = "media/images/objects/star_7.png";
	gObjectTexturesNames[21] = "media/images/objects/star_8.png";
	gObjectTexturesNames[22] = "media/images/objects/star_9.png";
	gObjectTexturesNames[23] = "media/images/objects/star_10.png";
	gObjectTexturesNames[24] = "media/images/objects/sun_1.png";
	
	srand(SDL_GetTicks());
	//loads a random texture for each one of the animated objects
	for(int indexObj = 0; indexObj < TOTAL_ANIMATED_OBJECTS; ++indexObj)
	{
		//random index for random file path
		int randomIndex = rand() % TOTAL_OBJECT_TEXTURES; 
		if(!gObjectTextures[indexObj].load(gObjectTexturesNames[randomIndex], gRenderer))
		{
			printf( "Unable to load the object texture!\n" );
			success = false;
		}
	}
	return success;
}

bool loadObjects()
{
	bool success = true;

	//Creating the array of textures
	success = createArrayOfTextures();
	//Setting the scene objects with predetermined properties
	for(int indexObj = 0; indexObj < TOTAL_ANIMATED_OBJECTS; ++indexObj)
	{
		gAnimatedObjects[indexObj].setOriginalVelocityX(300);
		gAnimatedObjects[indexObj].setOriginalVelocityY(60);
		gAnimatedObjects[indexObj].setVelocityX(300);
		gAnimatedObjects[indexObj].setVelocityY(60);
		gAnimatedObjects[indexObj].setOriginalPosition(100,150);
		gAnimatedObjects[indexObj].setPosition(100,150);
		gAnimatedObjects[indexObj].setObjectTexture(&gObjectTextures[indexObj]);
	}

	return success;
}

bool loadButtons()
{
	bool success = true;
	//creating the window buttons
	//setting the credits in button with predetermined properties
	gButtons[CREDITS_IN_BUTTON].setButtonHeight(80);
	gButtons[CREDITS_IN_BUTTON].setButtonWidth(150);
	gButtons[CREDITS_IN_BUTTON].setPos(225,680);
	gButtons[CREDITS_IN_BUTTON].setSprite(MOUSE_OUT_SPRITE);
	gButtons[CREDITS_IN_BUTTON].setButtonType(CREDITS_IN_BUTTON);
	buttonCreditsInTexture = Texture();
	if(!buttonCreditsInTexture.load("media/images/buttons/credits_in.png", gRenderer))
	{
		printf( "Unable to load the Credits In button texture!\n" );
		success = false;
	}
	gButtons[CREDITS_IN_BUTTON].setButtonTexture(&buttonCreditsInTexture);	
	gButtons[CREDITS_IN_BUTTON].setMClips();

	//the start button
	gButtons[START_BUTTON].setButtonHeight(80);
	gButtons[START_BUTTON].setButtonWidth(150);
	gButtons[START_BUTTON].setPos(425,680);
	gButtons[START_BUTTON].setSprite(MOUSE_OUT_SPRITE);
	gButtons[START_BUTTON].setButtonType(START_BUTTON);
	buttonStartTexture = Texture();
	if(!buttonStartTexture.load("media/images/buttons/start.png", gRenderer))
	{
		printf( "Unable to load the Start button texture!\n" );
		success = false;
	}
	gButtons[START_BUTTON].setButtonTexture(&buttonStartTexture);
	gButtons[START_BUTTON].setMClips();

	//the credits out button
	gButtons[CREDITS_OUT_BUTTON].setButtonHeight(80);
	gButtons[CREDITS_OUT_BUTTON].setButtonWidth(150);
	gButtons[CREDITS_OUT_BUTTON].setPos(625,680);
	gButtons[CREDITS_OUT_BUTTON].setSprite(MOUSE_OUT_SPRITE);
	gButtons[CREDITS_OUT_BUTTON].setButtonType(CREDITS_OUT_BUTTON);
	buttonCreditsOutTexture = Texture();
	if(!buttonCreditsOutTexture.load("media/images/buttons/credits_out.png", gRenderer))
	{
		printf( "Unable to load the Credits Out button texture!\n" );
		success = false;
	}
	gButtons[CREDITS_OUT_BUTTON].setButtonTexture(&buttonCreditsOutTexture);
	gButtons[CREDITS_OUT_BUTTON].setMClips();

	return success;
}

bool loadDisplays()
{
	bool success = true;

    //text of the plays display
	std::string plays = "Plays";
	//rendering text to texture
	if(!gPlaysTextTexture.loadText(plays, gRenderer))
    {
        printf("Unable to load the plays display!\n");
		success = false;
    }
	//text of the credits display
	std::string credits = "Credits";
	//rendering text to texture
	if(!gCreditsTextTexture.loadText(credits, gRenderer))
	{
        printf("Unable to load the credits display!\n");
		success = false;
    }
	//text of the removed credits display
	std::string removedCredits = "Removed";
	//rendering text to texture
	if(!gRemovedCreditsTextTexture.loadText(removedCredits, gRenderer))
    {
        printf("Unable to load the removed credits display!\n");
		success = false;
    }
	//rendering text for exit instructions in texture
	if(!gExitTextTexture.loadText("Press 'ESC' to exit!", gRenderer))
    {
        printf("Unable to load the exit instructions text!\n");
		success = false;
    }

	return success;
}

bool loadMedia()
{
	bool success = true;
	
	//loading the background texture
	gPNGTextureBackground = Texture();
	if(!gPNGTextureBackground.load("media/images/background/background_3.png", gRenderer))
	{
		printf( "Unable to load the background texture!\n" );
		success = false;
	}

	//loading displays, buttons and objects
	if(!loadDisplays() || !loadButtons() || !loadObjects())
	{
		success = false;
	}

	return success;
}

void freeResources()
{
	//destroying background
	gPNGTextureBackground.destroyTexture();
	//destroying the buttons
	for(int indexButton = 0; indexButton < TOTAL_BUTTONS; ++indexButton)
	{
		gButtons[indexButton].destroyButton();
	}
	//destroying the renderer
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	//destroying the scene objects, which also destroys the object textures
	for(int indexSceneObjects = 0; indexSceneObjects < TOTAL_ANIMATED_OBJECTS; indexSceneObjects++)
	{
		gAnimatedObjects[indexSceneObjects].destroySceneObject();
	}

	//destroying the displays textures
	gPlaysTextTexture.destroyTexture();
	gPlaysTexture.destroyTexture();
	gCreditsTextTexture.destroyTexture();
	gCreditsTexture.destroyTexture();
	gRemovedCreditsTextTexture.destroyTexture();
	gRemovedCreditsTexture.destroyTexture();

	//destroying the window
	gWindow.destroyWindow();

	//quitting the SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();
}

void updateDisplay(std::stringstream* displayText, int* display, Texture* texture, SDL_Renderer* renderer)
{
	//text to be rendered - counter on plays, credits or removed credits
	displayText->str( "" );
	*displayText << *display; 
	//if large number then print text
	if(*display > 99)
	{
		std::string tempText = "+99!";
		if(!texture->loadText(tempText, renderer))
		{
			printf( "Unable to load the display!\n" );
		}
	}
	else
	{
		if(!texture->loadText(displayText->str(), renderer))
		{
			printf( "Unable to load the display!\n" );
		}
	}
	
}

//calback function called on animation ending
Uint32 callbackAnimationEnded(Uint32 interval, void* param)
{	
	//setting object states to animation ended
    for(int indexSceneObject = 0; indexSceneObject < TOTAL_ANIMATED_OBJECTS; indexSceneObject++)
	{
		gAnimatedObjects[indexSceneObject].setAnimationState(ANIMATION_ENDED);
	}
	//updating gamestate
	gGameState = BEFORE_PLAY;
	return 0;
}

//callback function called when new object needs to be animated
Uint32 callbackNewSceneObject(Uint32 interval, void* param)
{
	//setting the object to animated state
	if(indexObject < TOTAL_ANIMATED_OBJECTS)
	{	
		gAnimatedObjects[indexObject].setAnimationState(ANIMATION_GOING);
		//storing time information to know when this object animation will end
		gAnimatedObjects[indexObject].setAnimationStartTime(animationTimer.getTicks());
		++indexObject;
		//new timer to callback needs to be set
		callbackNewObject = true;		
	}
	return 0;
}

void draw(int* initialPlays, bool* primaryRenderOfDisplays, std::stringstream* displayPlaysText,
	int* initialCredits, std::stringstream* displayCreditsText, int* initialRemovedCredits, std::stringstream* displayRemovedCreditsText)
{
	//means that there was an update on the plays counter value or display will be rendered for the first time
	if(*initialPlays != gPlays || *primaryRenderOfDisplays)
	{
		updateDisplay(displayPlaysText,&gPlays,&gPlaysTexture,gRenderer);
		*initialPlays = gPlays;
	}
	//means that there was an update on the credits counter value or display will be rendered for the first time
	if(*initialCredits != gCredits || *primaryRenderOfDisplays)
	{
		updateDisplay(displayCreditsText,&gCredits,&gCreditsTexture,gRenderer);
		*initialCredits = gCredits;
	}
	//means that there was an update on the removed credits counter value or display will be rendered for the first time
	if(*initialRemovedCredits != gRemovedCredits || *primaryRenderOfDisplays)
	{
		updateDisplay(displayRemovedCreditsText,&gRemovedCredits,&gRemovedCreditsTexture,gRenderer);
		*initialRemovedCredits = gRemovedCredits;
		//when this is reached for the first time means that all displays were rendered at least once
		*primaryRenderOfDisplays = false;
	}

	//rendering
	//clearing screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	//rendering the background
	gPNGTextureBackground.render(gRenderer, 0, 0, NULL);

	//rendering the exit instruction
	gExitTextTexture.render(gRenderer, 380, 65, NULL);

	//rendering the display of plays 
	gPlaysTextTexture.render(gRenderer, 13,200, NULL);
	gPlaysTexture.render(gRenderer, 45, 225, NULL);

	//rendering the display of credits
	gCreditsTextTexture.render(gRenderer,13,350, NULL);
	gCreditsTexture.render(gRenderer, 45, 375, NULL);

	//rendering the display of removed credits
	gRemovedCreditsTextTexture.render(gRenderer,13,500, NULL);
	gCreditsTextTexture.render(gRenderer,13,525, NULL);
	gRemovedCreditsTexture.render(gRenderer, 45, 550, NULL);

	//rendering the buttons
	for(int indexButtons = 0; indexButtons < TOTAL_BUTTONS; ++indexButtons)
	{
		gButtons[indexButtons].renderWithSprite(gRenderer);
	}
	//rendering the scene objects
	for(int indexSceneObjects = 0; indexSceneObjects < TOTAL_ANIMATED_OBJECTS; indexSceneObjects++)
	{
		//objects are only rendered if they are animated or in pause
		if(gAnimatedObjects[indexSceneObjects].getAnimationState() == ANIMATION_GOING || gAnimatedObjects[indexSceneObjects].getAnimationState() == ANIMATION_PAUSED)
		{
			gAnimatedObjects[indexSceneObjects].render(gRenderer);
		}
	}
	//render
	SDL_RenderPresent(gRenderer);
}

int main( int argc, char* args[])
{
	//starting up SDL and create window
	if(!initLibs())
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//loading media
		if(!loadMedia())
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//event handler
			SDL_Event e;

			//initializing the string for the plays display
			std::stringstream displayPlaysText;

			//initializing the string for the plays display
			std::stringstream displayCreditsText;

			//initializing the string for the plays display
			std::stringstream displayRemovedCreditsText;

			//sets the render of the displays on the first run
			bool firstRenderOfDisplays = true;

			int previousGameState = BEFORE_PLAY;
			gGameState = BEFORE_PLAY;

			//initializing counters
			gPlays = 0;
			gCredits = 0;
			gRemovedCredits = 0;
			//initializing object index
			indexObject = 0;

			//Main game loop
			while(!quit)
			{
				//auxiliary ints to know when to re-render the displays
				int initialPlays = gPlays;
				int initialCredits = gCredits;
				int initialRemovedCredits = gRemovedCredits;

				//handling events on queue
				while(SDL_PollEvent(&e) != 0)
				{
					//user requests to end through the ESCAPE key
					if(e.type ==  SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
					}
					
					//handling input on buttons
					for(int indexButtons = 0; indexButtons < TOTAL_BUTTONS; ++indexButtons)
					{
						gButtons[indexButtons].handleEvent(&e, &gPlays, &gCredits, &gRemovedCredits, &gGameState);
					}
					
				}
				
				//timestep to adjust the position of the objects
				//float timeStep = stepTimer.getTicks() / 1000.f;
				//set predetermined timestep for more stability
				float timeStep = 0.017;
				
				
				//dealing with game state changes
				switch(gGameState)
				{
					//game is running
					case RUNNING:
						//came from pause state
						if(previousGameState == PAUSED)
						{
							//set every object that was paused to continue the animation
							//only indexObject-1 objects were paused because the others didn't start the animation process yet
							for(int indexObjectAux = indexObject-1; indexObjectAux >= 0; --indexObjectAux)
							{
								if(gAnimatedObjects[indexObjectAux].getAnimationState() == ANIMATION_PAUSED)
								{
									gAnimatedObjects[indexObjectAux].setAnimationState(ANIMATION_GOING);
								}
							}
							//unpause timers
							//stepTimer.unpause();
							animationTimer.unpause();

							//setting new timer to callback the end of the animation since pausing deleted the previous callback
							timerAnimationEndID = SDL_AddTimer(ANIMATION_TIME - animationTimer.getTicks(), callbackAnimationEnded, NULL);
							
							//calculating the remaining time to generate a new object for the animation
							double tempCalc = animationTimer.getTicks()/NEXT_OBJECT_TIME;
							tempCalc = floor(tempCalc);
							tempCalc = tempCalc * NEXT_OBJECT_TIME;
							tempCalc = tempCalc + NEXT_OBJECT_TIME;
							tempCalc = tempCalc - animationTimer.getTicks();
							SDL_RemoveTimer(timerNewObjectCallbackID);
							//Setting new timer to generate a new object for the animation in the right time
							timerNewObjectCallbackID = SDL_AddTimer(tempCalc, callbackNewSceneObject, NULL);
						}

						//animation just started
						if(previousGameState == BEFORE_PLAY)
						{
							//set callback to end animation
							timerAnimationEndID = SDL_AddTimer(ANIMATION_TIME, callbackAnimationEnded, NULL);
							//start timer
							animationTimer.start();
							//starting first object animation
							gAnimatedObjects[indexObject].setAnimationState(ANIMATION_GOING);
							gAnimatedObjects[indexObject].setAnimationStartTime(animationTimer.getTicks());
							++indexObject;
							//set callback to add new object to scene in given time
							timerNewObjectCallbackID = SDL_AddTimer(NEXT_OBJECT_TIME, callbackNewSceneObject, NULL);
						}

						//setting new timer callback to create an object if needed
						//callbackNewObject is set to true when the last callback function is called
						if(callbackNewObject)
						{
							SDL_RemoveTimer(timerNewObjectCallbackID);
							timerNewObjectCallbackID = SDL_AddTimer(NEXT_OBJECT_TIME, callbackNewSceneObject, NULL);
							callbackNewObject = false;
						}
						
						//updating the objects coordinates
						for(int indexSceneObject = 0; indexSceneObject < TOTAL_ANIMATED_OBJECTS; indexSceneObject++)
						{
							//if animation time for the object has passed then set its state accordingly
							if(animationTimer.getTicks() - gAnimatedObjects[indexSceneObject].getAnimationStartTime() >= OBJECT_ANIMATION_TIME )
							{
								gAnimatedObjects[indexSceneObject].setAnimationState(ANIMATION_ENDED);
							}
							//if the object is currently being animated then update its position
							if(gAnimatedObjects[indexSceneObject].getAnimationState() == ANIMATION_GOING)
							{
								gAnimatedObjects[indexSceneObject].update(timeStep);
							}
						}
						previousGameState = RUNNING;
						break;
					//game is paused
					case PAUSED:
						//came from animation
						if(previousGameState == RUNNING)
						{
							for(int indexSceneObjects = 0; indexSceneObjects < TOTAL_ANIMATED_OBJECTS; indexSceneObjects++)
							{
								//if the object was animated then set it to pause
								if(gAnimatedObjects[indexSceneObjects].getAnimationState() == ANIMATION_GOING)
								{
									gAnimatedObjects[indexSceneObjects].setAnimationState(ANIMATION_PAUSED);
								}
							}
							//pause timers
							//stepTimer.pause();
							animationTimer.pause();

							//when paused callbacks should not be invoked
							SDL_RemoveTimer(timerAnimationEndID);
							SDL_RemoveTimer(timerNewObjectCallbackID);
						}
						previousGameState = PAUSED;
						break;
					//if before animation
					case BEFORE_PLAY:
						//animation has just ended
						if(previousGameState == RUNNING)
						{
							//increase plays
							++gPlays;
							//setting the objects to assume original properties
							for(int indexSceneObjects = 0; indexSceneObjects < TOTAL_ANIMATED_OBJECTS; indexSceneObjects++)
							{
								gAnimatedObjects[indexSceneObjects].reset();
							}
							//reseting the index of the new object in animation
							indexObject = 0;
							//removing the timers to callback if they exist
							SDL_RemoveTimer(timerAnimationEndID);
							SDL_RemoveTimer(timerNewObjectCallbackID);
						}
						previousGameState = BEFORE_PLAY;
						break;
					default: 
						break;
					
				}

				//draw objects to screen
				draw(&initialPlays, &firstRenderOfDisplays, &displayPlaysText, &initialCredits,&displayCreditsText, &initialRemovedCredits, &displayRemovedCreditsText);
			}
		}
	}

	//free resources and close SDL
	freeResources();

	return 0;
}
