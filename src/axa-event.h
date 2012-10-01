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

#ifndef _AXA_EVENT_H_
#define _AXA_EVENT_H_

#include <SDL.h>
 
class AxaEvent {
    public:
        AxaEvent();
 
        virtual ~AxaEvent();
 
        virtual void onEvent(SDL_Event* Event);
 
        virtual void onInputFocus();
 
        virtual void onInputBlur();
 
        virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
 
        virtual void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
 
        virtual void onMouseFocus();
 
        virtual void onMouseBlur();
 
        virtual void onMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
 
        virtual void onMouseWheel(bool Up, bool Down);    //Not implemented
 
        virtual void onLButtonDown(int mX, int mY);
 
        virtual void onLButtonUp(int mX, int mY);
 
        virtual void onRButtonDown(int mX, int mY);
 
        virtual void onRButtonUp(int mX, int mY);
 
        virtual void onMButtonDown(int mX, int mY);
 
        virtual void onMButtonUp(int mX, int mY);
 
        virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
 
        virtual void onJoyButtonDown(Uint8 which, Uint8 button);
 
        virtual void onJoyButtonUp(Uint8 which, Uint8 button);
 
        virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
 
        virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
 
        virtual void onMinimize();
 
        virtual void onRestore();
 
        virtual void onResize(int w,int h);
 
        virtual void onExpose();
 
        virtual void onExit();
 
        virtual void onUser(Uint8 type, int code, void* data1, void* data2);
};

#endif // _AXA_EVENT_H_

