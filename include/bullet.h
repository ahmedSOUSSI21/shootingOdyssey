#ifndef __BULLET_H__
#define __BULLET_H__
#include <stdlib.h>
#define PLAYER_BULLET_TYPE 1
#define NORMA_ENEMY_BULLET_TYPE 2
#define FLASHING_ENEMY_BULLET_TYPE 3

typedef struct bullet{
    int type;
    int x;
    int y;
    int damage;
    int speed;
    float angle;
}Bullet;
/**
 * @brief initialise une balle 
 * 
 * @param type le type de la balle (player bullet, normal enemy bullet, flashing enemy bullet)
 * @param x position x de la balle
 * @param y position y de la balle
 * @param damage la quantité de dégats que la balle inflige en hurtant un vaissau
 * @param speed la vitesse de déplacement de la balle
 * @param angle l'angle de tir de la balle
 * @return Bullet* une balle initialisée avec les paramètres donnés en argument
 */
Bullet * init_bullet(int type, int x, int y, int damage, int speed, float angle);

/**
 * @brief libère toute la mémoire occupée par une balle
 * 
 * @param bullet la balle dont il faut libèrer la mémoire
 */
void free_bullet(Bullet * bullet);

/**
 * @brief déplace la balle en se basant sur sa vitesse et l'angle de tir
 * 
 * @param bullet la balle à déplacer
 */
void move_bullet(Bullet * bullet);

#endif