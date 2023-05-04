#ifndef __GAME_H__
#define __GAME_H__
#include "../include/bullet.h"
#include "../include/ship.h"
#include "../include/interface.h"

void move_bullets(BulletWithImage ** bullets);
void gameloop();

#endif