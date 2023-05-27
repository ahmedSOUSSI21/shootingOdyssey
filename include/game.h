#ifndef __GAME_H__
#define __GAME_H__
#include "../include/bullet.h"
#include "../include/ship.h"
#include "../include/interface.h"

/**
 * @brief Fonction qui permet de bouger toutes les balles du jeu

    * @param bullets tableau de balles

 */
void move_bullets(BulletWithImage ** bullets);

/**
 * @brief Boucle du jeu

    * @param void
 */
void gameloop();

#endif