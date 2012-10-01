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

#include "axa-entity.h"

std::vector<AxaEntity*> AxaEntity::EntityList;

AxaEntity::AxaEntity() {
    Surf_Entity = NULL;

    X = Y = 0.0f;

    Width = Height = 0;

    AnimState = 0;
}

AxaEntity::~AxaEntity() {
}

bool AxaEntity::onLoad(char* File, int Width, int Height, int maxFrames) {
    if((Surf_Entity = AxaSurface::onLoad(File)) == NULL) {
        return false;
    }

    AxaSurface::makeTransparent(Surf_Entity, 255, 0, 255);

    this->Width = Width;
    this->Height = Height;

    Anim_Control.maxFrames = maxFrames;

    return true;
}

void AxaEntity::onLoop() {
    Anim_Control.onAnimate();
}

void AxaEntity::onRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    AxaSurface::onDraw(Surf_Display, Surf_Entity, X, Y, AnimState * Width, Anim_Control.getCurrentFrame() * Height, Width, Height);
}

void AxaEntity::onCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}

