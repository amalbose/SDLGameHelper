#include "game-helper.h"

/*
 *  Initializes the game setting resolution etc.
 */
bool GameHelper::init () {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 
    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    return true;
}