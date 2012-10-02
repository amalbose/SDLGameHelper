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

#include "axa-camera.h"

AxaCamera AxaCamera::CameraControl;
 
AxaCamera::AxaCamera() {
    X = Y = 0;
 
    TargetX = TargetY = NULL;
 
    TargetMode = TARGET_MODE_NORMAL;
}
 
void AxaCamera::onMove(int MoveX, int MoveY) {
    X += MoveX;
    Y += MoveY;
}
 
int AxaCamera::getX() {
    if(TargetX != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
            return *TargetX - (WWIDTH / 2);
        }
 
        return *TargetX;
    }
 
    return X;
}
 
int AxaCamera::getY() {
    if(TargetY != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
            return *TargetY - (WHEIGHT / 2);
        }
 
        return *TargetY;
    }
 
    return Y;
}
 
void AxaCamera::setPos(int X, int Y) {
    this->X = X;
    this->Y = Y;
}
 
void AxaCamera::setTarget(int* X, int* Y) {
    TargetX = X;
    TargetY = Y;
}

