#include "texture.h"

//default constructor
Texture::Texture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
};

//free resources
void Texture::destroyTexture()
{
	//destroys actual SDL texture
	if(mTexture)
	{
		SDL_DestroyTexture(mTexture);
	}
	mWidth = 0;
	mHeight = 0;
};

//get methods
int Texture::getWidth()
{
	return mWidth;
};
int Texture::getHeight()
{
	return mHeight;
};
SDL_Texture* Texture::getTexture()
{
	return mTexture;
};

//set methods
void Texture::setWidth(int width)
{
	mWidth = width;
};
void Texture::setHeight(int height)
{
	mHeight = height;
};
void Texture::setTexture(SDL_Texture* sdl_texture)
{
	mTexture = sdl_texture;
};

//loads texture from file
bool Texture::load(std::string path, SDL_Renderer* renderer){
	
	//destroy current texture
	if(mTexture)
	{
		SDL_DestroyTexture(mTexture);
	}
	
	//the new texture
	SDL_Texture* newTexture = NULL;

	//load surface from image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//create texture from surface
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if(newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//set texture dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//destroy old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	mTexture = newTexture;
	
	if(mTexture != NULL)
	{
		return true;
	}
	else 
		return false;
};

//creates texture with given text
bool Texture::loadText(std::string textureText, SDL_Renderer* renderer)
{
	//destroy current texture
	if(mTexture)
	{
		SDL_DestroyTexture(mTexture);
	}

	//set text color to black
	SDL_Color gTextColor = {0, 0, 0};
	//load font
	TTF_Font *gFont = TTF_OpenFont("media/font/Action_Man_Shaded.ttf", 22);
	//create surface with text
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), gTextColor);
	if(textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//create texture from surface
        mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if(mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//set texture dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//destroy old surface
		SDL_FreeSurface(textSurface);
	}
	
	if(mTexture != NULL)
	{
		return true;
	}
	else 
		return false;
}

//renders texture at given point. 
void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* part){
	//set rendering rectangle on screen 
	SDL_Rect renderQuad = {x, y, this->mWidth, this->mHeight};
	//if a sprite is used then the screen rectangle may need adjustment
	if(part != NULL)
	{
		renderQuad.h = part->h;
		renderQuad.w = part->w;
	}
	//render to screen
	SDL_RenderCopy(renderer, mTexture, part, &renderQuad);
};