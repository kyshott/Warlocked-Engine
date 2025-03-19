/*
A general class made specifically to create basic function definitions for some SDL stuff.
Followed on the Lazy Foo productions site. Props to the site for actually providing useful
and comprehensive SDL materials.
*/

#include <SDL.h>
#include <stdio.h>
#include <string>

//Enumeration for the various surfaces available, and which ones to switch between
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//Starts SDL and creates window
bool init();

//Loads media
bool loadmedia();

//Frees media and shuts down SDL
void close();

SDL_Surface* loadSurface(std::string path);

//Window to render to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Array of images that correspond to key presses with size equal to the last element of the enum, which is evidently the number of enums
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//The image to load and show on the screen
SDL_Surface* gCurrentSurface = NULL;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Surface* loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at the specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	
	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	else
	{
		//Use convert surface to make the 24 bit image scaled up to our screen resolution - this ultimately
		//increases performance, as the image does not have to be upscaled every time. Very useful...
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create the window, checking for SDL error first:
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL error: %s\n", SDL_GetError());
		}
		else
		{
			//Get the window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	//Return the success flag, which allows for us to determine if SDL was successfully initialized.
	return success;

}

bool loadmedia()
{
	//Loading success flag
	bool success = true;

	//Load the default surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("Resources/press.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load image!\n");
		success = false;
	}

	//Load the up surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("Resources/up.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load image!\n");
		success = false;
	}

	//Load the down surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("Resources/down.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{ 
		printf("Failed to load image!\n");
		success = false;
	}

	//Load the left surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("Resources/left.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load image!\n");
		success = false;
	}

	//Load the right surface
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("Resources/right.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load image!\n");
		success = false;
	}

	//Return the success flag, which allows for us to determine if the images/media was loaded correctly
	return success;
}

void close()
{
	//Deallocate surface - freeing memory
	SDL_FreeSurface(gCurrentSurface);

	gCurrentSurface = NULL;

	//Destroy the window - freeing memory
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit out all SDL subsystems
	SDL_Quit();
}

int main2(int argc, char* args[])
{
	//Start up SDL and create window - then, check for boolean values returned from init() and loadMedia() and go from there
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!loadmedia())
		{
			printf("Failed to load bitmap file!\n");
		}
		else
		{
			//Exiting via the "X" button
			SDL_Event e;

			bool quit = false;

			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			while (!quit)
			{
				//Keep checking as long as the event stack is not empty
				while (SDL_PollEvent(&e) != 0)
				{
					//If event is the "quit" function, then break the loop
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
							case SDLK_UP:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							break;

							case SDLK_DOWN:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							break;

							case SDLK_LEFT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
							break;

							case SDLK_RIGHT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
							break;

							default:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;

						}
					}
				}

				//Stretch the screens to a sized SDL_Rect that allows for resizing of SDL_Surfaces... interestingly useful...
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled(gCurrentSurface, NULL, gScreenSurface, &stretchRect);
				SDL_UpdateWindowSurface(gWindow);
			}
		}

	}

	//Use the close function to close out and free all resources used
	close();

	return 0;
}





