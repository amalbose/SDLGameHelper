#include "game-helper.h"

/*
 *  Handle the events 
 */
void GameHelper::cleanUp () {
    SDL_FreeSurface(Surf_Display);
	SDL_Quit();
}

