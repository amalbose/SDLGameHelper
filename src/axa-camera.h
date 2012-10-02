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

#ifndef _AXA_CAMERA_H_
#define _AXA_CAMERA_H_

#include <SDL.h>
 
#include "define.h"
 
enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};
 
class AxaCamera {
    public:
        static AxaCamera CameraControl;
 
    private:
        int X;
        int Y;
 
        int* TargetX;
        int* TargetY;
 
    public:
        int TargetMode;
 
    public:
        AxaCamera();
 
    public:
        void onMove(int MoveX, int MoveY);
 
    public:
        int getX();
        int getY();
 
    public:
        void setPos(int X, int Y);
 
        void setTarget(int* X, int* Y);
};

#endif // _AXA_CAMERA_H_

