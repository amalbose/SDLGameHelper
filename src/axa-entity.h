/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * tictactoegame
 * Copyright (C) 2012 Amal Bose <amalbose@axahome>
 * 
tictactoegame is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * tictactoegame is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _AXA_ENTITY_H_
#define _AXA_ENTITY_H_

#include <vector>

#include "axa-animation.h"
#include "axa-surface.h"

class AxaEntity {
    public:
        static std::vector<AxaEntity*>    EntityList;

    protected:
        AxaAnimation      Anim_Control;

        SDL_Surface*    Surf_Entity;

    public:
        float           X;
        float           Y;

        int             Width;
        int             Height;

        int             AnimState;

    public:
        AxaEntity();

        virtual ~AxaEntity();

    public:
        virtual bool onLoad(char* File, int Width, int Height, int MaxFrames);

        virtual void onLoop();

        virtual void onRender(SDL_Surface* Surf_Display);

        virtual void onCleanup();
};

#endif // _AXA_ENTITY_H_

