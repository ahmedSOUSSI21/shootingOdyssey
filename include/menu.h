#ifndef __MENU_H__
#define __MENU_H__

#include "interface.h"

#define PLAY 1
#define CREDITS 2
#define QUIT 3 
#define BACK_TO_MENU 4
/**
 * @brief affiche le menu principal du jeu
 * 
 * @return int Le choix du joueur
 */
int display_menu(MLV_Image * background);

/**
 * @brief affiche credits
 * 
 */
int display_credits(MLV_Image * image);

#endif