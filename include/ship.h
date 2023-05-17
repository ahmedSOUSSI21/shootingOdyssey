#ifndef __SHIP_H__
#define __SHIP_H__
#include <stdlib.h>
#include "bullet.h"
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SHIP_WIDTH 32
#define SHIP_HEIGHT 32
#define PI		3.14159265358979323846

#define LAST_FIRE_PLAYER 0.6
#define LAST_FIRE_ENEMY 0.8
#define PLAYER_MINIMUM_RELOAD_TIME 5.0
#define PLAYER_SHIP_TYPE 1
#define NORMAL_ENEMY_SHIP_TYPE 2
#define FLASHING_ENEMY_SHIP_TYPE 3

/**
* @struct Ship
* @brief Represente les vaisseaux.
*/
typedef struct ship{
    int type;
    int x;
    int y;
    int pv;
    int ammo;
    int speed;
    Bullet ** bullets;
    float last_fire;
}Ship;

/**
 * @brief initialise le vaissau du joueur
 * 
 * @param x position x du vaissau du joueur
 * @param y position y du vaissau du joueur
 * @param speed la vitesse de déplacement du vaissau du joueur
 * @return Ship* le vaissau du joueur initialisé avec les paramètres passés en argument
 */
Ship * init_player_ship(int x, int y, int speed);

/**
 * @brief recharge les balles du vaissau
 *  
 * @param ship le vaissau à recharger 
 */
void player_reload(Ship * ship);

/**
 * @brief initialise le vaissau d'un flashing enemy
 * 
 * @param x position x du vaissau de l'ennemi
 * @param y position y du vaissau de l'ennemi
 * @param speed la vitesse de déplacement du vaissau de l'ennemi
 * @return Ship* le vaissau de l'ennemi initialisé avec les paramètres passés en argument
 */
Ship * init_flashing_ship(int x, int y, int speed);

/**
 * @brief initialise le vaissau d'un normal enemy
 * 
 * @param x position x du vaissau de l'ennemi
 * @param y position y du vaissau de l'ennemi
 * @param speed la vitesse de déplacement du vaissau de l'ennemi
 * @return Ship* le vaissau de l'ennemi initialisé avec les paramètres passés en argument
 */
Ship * init_normal_enemy_ship(int x, int y, int speed);

/**
 * @brief Libère toute la mémoire occupée par le vaissau
 * 
 * @param ship Le vaissau dont il faut libérer la mémoire
 */
void free_ship(Ship * ship);

/**
 * @brief déplace le vaissau en se basant sur sa vitesse et la direction passée en argument
 * 
 * @param ship le vaissau à déplacer
 * @param direction la direction du déplacement
 * @param width la largeur de l'ecran
 * @param height la longueur de l'ecran
 */
void move_ship(Ship * ship, int direction, int width, int height);

/**
 * @brief Enlève une balle du vaissau et la renvoie
 * 
 * @param ship Le vaissau sensé tirer la balle
 * @return Bullet* la balle tirée
 */
Bullet * player_fire(Ship * ship);

/**
 * @brief Enlève une balle du vaissau et la renvoie
 * 
 * @param ship Le vaissau sensé tirer la balle
 * @param player_ship Le vaissau du joueur (pour pouvoir tirer de balles pouvant suivre le joueur)
 * @return Bullet* la balle tirée
 */
Bullet * enemy_fire(Ship * ship, Ship * player_ship);

/**
 * @brief Enlève une balle du vaissau et la renvoie
 * 
 * @param ship Le vaissau sensé tirer la balle
 * @return Bullet* la balle tirée
 */
Bullet * enemy_fire_normal(Ship * ship);

/**
 * @brief Décremente les pv du vaissau de la valeur de damage de la balle
 * 
 * @param ship Le vaissau touché par la balle
 * @param bullet La balle touchant le vaissau
 */
void take_damage_from_bullet(Ship * ship, Bullet * bullet);

#endif