#include "game-helper.h"

/*
 *  Draws the updated images on screen.
 */
void GameHelper::render() {

	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = WWIDTH;
	Rect.h = WHEIGHT;

	SDL_FillRect(Surf_Display, &Rect, 0);

	AxaArea::AreaControl.onRender(Surf_Display, AxaCamera::CameraControl.getX(), AxaCamera::CameraControl.getY());

    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < AxaEntity::EntityList.size();i++) {
        if(!AxaEntity::EntityList[i]) continue;

        AxaEntity::EntityList[i]->onRender(Surf_Display);
    }

	SDL_Flip(Surf_Display);
}