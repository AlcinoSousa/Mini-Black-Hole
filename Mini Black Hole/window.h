#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

/**
	Class Window represents the window of the game.
	Has methods to initialize it properly and create the rendering context
*/

//fixed window size
enum windowSize
{
	WINDOW_WIDTH = 1024,
	WINDOW_HEIGHT = 768
};

class Window
{
	private:
		//the actual SDL window
		SDL_Window* mWindow;

		//the window dimensions
		int mWidth;
		int mHeight;

	public:
		//default constructor
		Window();
		
		//used to free resources
		void destroyWindow();

		//get methods
		int getWindowWidth();
		int getWindowHeight();
		SDL_Window* getWindow();

		//set methods
		void setWindowHeight(int windowHeight);
		void setWindowWidth(int windowWidth);

		//initiates the window with the defined dimensions
		bool init();

		//creates a vsynced renderer for the window
		SDL_Renderer* createRenderer();
};


#endif