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

#include "axa-animation.h"

AxaAnimation::AxaAnimation() {
    currentFrame    = 0;
    maxFrames       = 0;
    frameInc        = 1;
 
    frameRate       = 100; //Milliseconds
    oldTime         = 0;
 
    oscillate       = false;
}
 
void AxaAnimation::onAnimate() {
    if(oldTime + frameRate > SDL_GetTicks()) {
        return;
    }
 
    oldTime = SDL_GetTicks();
 
    currentFrame += frameInc;
 
    if(oscillate) {
        if(frameInc > 0) {
            if(currentFrame >= maxFrames) {
                frameInc = -frameInc;
            }
        }else{
            if(currentFrame <= 0) {
                frameInc = -frameInc;
            }
        }
    }else{
        if(currentFrame >= maxFrames) {
            currentFrame = 0;
        }
    }
}
 
void AxaAnimation::setFrameRate(int rate) {
    frameRate = rate;
}
 
void AxaAnimation::setCurrentFrame(int frame) {
    if(frame < 0 || frame >= maxFrames) return;
 
    currentFrame = frame;
}
 
int AxaAnimation::getCurrentFrame() {
    return currentFrame;
}


