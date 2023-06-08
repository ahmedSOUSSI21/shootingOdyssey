#ifndef __MENU_H__
#define __MENU_H__

#include "interface.h"

#define PLAY 1
#define CREDITS 2
#define QUIT 3 
#define BACK_TO_MENU 4
#define HOW_TO_PLAY 5

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

/**
 * @brief affiche le tutoriel
 * 
 * @param background L'image de fond 
 * @param zqsd L'image des touches zqsd
 * @param space L'image de la touche espace
 * @return int Le choix du joueur
 */
int display_how_to_play(MLV_Image * background, MLV_Image * zqsd, MLV_Image * space);

#endif