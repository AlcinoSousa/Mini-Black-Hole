#include "window.h"

//default constructor
Window::Window()
{
	mWindow = NULL;
	mWidth = 0;
	mHeight = 0;
}

//used to free resources
void Window::destroyWindow()
{
	//destroy the SDL window
	SDL_DestroyWindow(mWindow);
	mWidth = 0;
	mHeight = 0;
}

//get methods
int Window::getWindowWidth()
{
	return mWidth;
}
int Window::getWindowHeight()
{
	return mHeight;
}
SDL_Window* Window::getWindow()
{
	return mWindow;
}

//set methods
void Window::setWindowHeight(int windowHeight)
{
	mHeight = windowHeight;
}
void Window::setWindowWidth(int windowWidth)
{
	mWidth = windowWidth;
}

//initiates the window
bool Window::init()
{
	//creates a SDL window with position undefined, pre-defined dimensions, at front and without borders
	mWindow = SDL_CreateWindow("Mini Black Hole", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	if(mWindow != NULL)
	{
		//setting the object dimensions
		mWidth = WINDOW_WIDTH;
		mHeight = WINDOW_HEIGHT;
		return true;
	}
	else
		return false;
}

//creates a vsynced renderer for the window
SDL_Renderer* Window::createRenderer()
{
	//creating renderer for window, 
	//-1 parameter initializes the rendering driver support the requested flags
	//uses hardware accleration and is synchronized with refresh rate
	return SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

