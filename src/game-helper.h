/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gamehelper
 * Copyright (C) 2012 Amal Bose <axatrikx@gmail.com>
 * 
gamehelper is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gamehelper is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GAME_HELPER_H_
#define _GAME_HELPER_H_

#include "SDL/SDL.h"
#include "define.h"
#include "axa-surface.h"
#include "axa-event.h"

class GameHelper : public AxaEvent {
public:
	GameHelper();
	
protected:
	virtual void update();
	virtual void render();

private:
	SDL_Surface*    Surf_Display;
	
	bool isRunning;

	//Main methods
	int mainLoop();
	bool init();
	void handleEvents(SDL_Event* Event);
	void cleanUp();

	//Events
	void onExit();
};

#endif // _GAME_HELPER_H_

