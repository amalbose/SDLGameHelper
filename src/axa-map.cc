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

#include "axa-map.h"

AxaMap::AxaMap() {
    Surf_Tileset = NULL;
}
 
bool AxaMap::onLoad(char* File) {
    TileList.clear();
 
    FILE* FileHandle = fopen(File, "r");
 
    if(FileHandle == NULL) {
        return false;
    }
 
    for(int Y = 0;Y < MAP_HEIGHT;Y++) {
        for(int X = 0;X < MAP_WIDTH;X++) {
            AxaTile tempTile;
 
            fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);
 
            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }
 
    fclose(FileHandle);
 
    return true;
}
 
void AxaMap::onRender(SDL_Surface* Surf_Display, int MapX, int MapY) {
    if(Surf_Tileset == NULL) return;
 
    int TilesetWidth  = Surf_Tileset->w / TILE_SIZE;
    int TilesetHeight = Surf_Tileset->h / TILE_SIZE;
 
    int ID = 0;
 
    for(int Y = 0;Y < MAP_HEIGHT;Y++) {
        for(int X = 0;X < MAP_WIDTH;X++) {
            if(TileList[ID].TypeID == TILE_TYPE_NONE) {
                ID++;
                continue;
            }
 
            int tX = MapX + (X * TILE_SIZE);
            int tY = MapY + (Y * TILE_SIZE);
 
            int TilesetX = (TileList[ID].TileID % TilesetWidth) * TILE_SIZE;
            int TilesetY = (TileList[ID].TileID / TilesetWidth) * TILE_SIZE;
 
            AxaSurface::onDraw(Surf_Display, Surf_Tileset, tX, tY, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);
 
            ID++;
        }
    }
}

