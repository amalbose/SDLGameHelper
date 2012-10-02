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

#include "axa-area.h"

AxaArea AxaArea::AreaControl;
 
AxaArea::AxaArea() {
    AreaSize = 0;
}
 
bool AxaArea::onLoad(char* File) {
    MapList.clear();
 
    FILE* FileHandle = fopen(File, "r");
 
    if(FileHandle == NULL) {
        return false;
    }
 
    char TilesetFile[255];
 
    fscanf(FileHandle, "%s\n", TilesetFile);
 
    if((Surf_Tileset = AxaSurface::onLoad(TilesetFile)) == false) {
        fclose(FileHandle);
 
        return false;
    }
 
    fscanf(FileHandle, "%d\n", &AreaSize);
 
    for(int X = 0;X < AreaSize;X++) {
        for(int Y = 0;Y < AreaSize;Y++) {
            char MapFile[255];
 
            fscanf(FileHandle, "%s ", MapFile);
 
            AxaMap tempMap;
            if(tempMap.onLoad(MapFile) == false) {
                fclose(FileHandle);
 
                return false;
            }
 
            tempMap.Surf_Tileset = Surf_Tileset;
 
            MapList.push_back(tempMap);
        }
        fscanf(FileHandle, "\n");
    }
 
    fclose(FileHandle);
 
    return true;
}
 
void AxaArea::onRender(SDL_Surface* Surf_Display, int CameraX, int CameraY) {
    int MapWidth  = MAP_WIDTH * TILE_SIZE;
    int MapHeight = MAP_HEIGHT * TILE_SIZE;
 
    int FirstID = -CameraX / MapWidth;
        FirstID = FirstID + ((-CameraY / MapHeight) * AreaSize);
 
    for(int i = 0;i < 4;i++) {
        int ID = FirstID + ((i / 2) * AreaSize) + (i % 2);
 
        if(ID < 0 || ID >= MapList.size()) continue;
 
        int X = ((ID % AreaSize) * MapWidth) + CameraX;
        int Y = ((ID / AreaSize) * MapHeight) + CameraY;
 
        MapList[ID].onRender(Surf_Display, X, Y);
    }
}
 
void AxaArea::onCleanup() {
    if(Surf_Tileset) {
        SDL_FreeSurface(Surf_Tileset);
    }
 
    MapList.clear();
}

