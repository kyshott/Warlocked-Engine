#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <SDL.h>
#include "player.hpp"
#include "gamearea.hpp"
#include "controller.hpp"

/**
 * @brief Class to contain the "Game" itself.
 * 
 * The backbone for the engine - contains all logic for the game loop which includes delta time calculations and game state. All relevant persistent classes and objects (renderer, controller, etc)
 * are instantiated and owned by this class. Only one Game object may exist at a time unless you want the engine to blow up in your face. 
 * 
 * Has no constructor as it is not needed. May add one later? Constructor is currently unnecessary as the Game class should not be called or instantiated anywhere other than in the main method.
 * 
 */
class Game {
public:

	// The main renderer for the game. Used virtually EVERYWHERE for drawing to the screen. Only one renderer is allowed
	// as per the SDL documentation. Single-thread rendering only.
	SDL_Renderer* renderer;

	// The main window for the game. Another very important piece of the engine.
	SDL_Window* mainScreen;

	/**
	* @brief Default constructor for the game class.
	* 
	* Initializes the game class. Currently does not do anything as all initialization is handled in initSDL() method.
	*/
	Game();

	/**
	 * @brief Initializes all necessary SDL objects.
	 * 
	 * Initializes SDL by creating the renderer, window and window size. Calls SDL_Init() to spin everything up. 
	 */
	void initSDL();

	/**
	 * @brief The game loop.
	 * 
	 * The aptly named "game loop" that handles the process of the engine as things are rendered. Delta time is calculated and implemented here, contained
	 * within a loop that persists until the "quit" flag is received from the instantiated controller class. 
	 */
	void gameloop();

	/**
	 * @brief Closes the game.
	 * 
	 * The ultimate method to close everything should the user wish to end the program. Basically the (safe) "self destruct" button that is called when the quit flag is received
	 * from the controller class. Causes a chain reaction that closes all objects on screen (the current game area) and frees manually allocated objects and automatically frees anything
	 * assigned to smart pointers.
	 */
	void close();

private:
    
	// The screen width in pixels.
	int SCREEN_WIDTH;

	// The screen height in pixels.
	int SCREEN_HEIGHT;
	
};

#endif
