#include "game-helper.h"

/*
 *  Handle the events 
 */
void GameHelper::handleEvents (SDL_Event* Event) {
	AxaEvent::onEvent (Event);
}

void GameHelper::onExit() {
    isRunning = false;
}