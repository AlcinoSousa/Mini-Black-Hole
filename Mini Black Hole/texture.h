#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <sstream>

/**
	the Texture class represents the textures of the objects to be rendered
*/

class Texture
{
	private:
		//the actual SDL texture
		SDL_Texture* mTexture;
		//the texture dimensions
		int mWidth;
		int mHeight;

	public:
		//default constructor
		Texture();

		//used to free resources. Destroys the used texture and respective pointer.
		void destroyTexture();

		//get methods
		int getWidth();
		int getHeight();
		SDL_Texture* getTexture();

		//set methods
		void setWidth(int width);
		void setHeight(int height);
		void setTexture(SDL_Texture* sdl_texture);

		/**
			loads texture from file
			@param path path to file
			@param renderer current rendering context
			@return bool that represents the success of the operation
		*/
		bool load(std::string path, SDL_Renderer* renderer);

		/**
			creates texture with given text
			@param textureText the text to be written in the texture
			@param renderer current rendering context
			@return bool that represents the success of the operation
		*/
		bool loadText(std::string textureText, SDL_Renderer* renderer);
		
		/**
			renders texture at given point. 
			@param renderer current rendering context
			@param x coordinate x of rendering point
			@param y coordinate y of rendering point
			@param part pointer to rectangle that determines the sprite to use from the sprite sheet, if appliable.
		*/
		void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* part);
};

#endif