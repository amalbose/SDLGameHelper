/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gamehelper
 * Copyright (C) 2012 Amal Bose <amalbose@axahome>
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

#ifndef _AXA_AREA_H_
#define _AXA_AREA_H_

#include "axa-map.h"

class AxaArea {
    public:
        static AxaArea  AreaControl;
 
    public:
        std::vector<AxaMap>  MapList;
 
    private:
        int  AreaSize;
 
        SDL_Surface* Surf_Tileset;
 
    public:
        AxaArea();
 
        bool  onLoad(char* File);
 
        void  onRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
 
        void  onCleanup();
};

#endif // _AXA_AREA_H_

