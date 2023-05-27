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

#define LAST_FIRE_PLAYER 200
#define LAST_FIRE_ENEMY 400
#define PLAYER_MINIMUM_RELOAD_TIME 2000
#define PLAYER_SHIP_TYPE 1
#define NORMAL_ENEMY_SHIP_TYPE 2
#define FLASHING_ENEMY_SHIP_TYPE 3

/**
* @struct Ship
* @brief Structure représentant un vaisseau
*
* @param type le type du vaisseau
* @param x la position x du vaisseau
* @param y la position y du vaisseau
* @param pv les points de vie du vaisseau
* @param ammo le nombre de balles du vaisseau
* @param speed la vitesse de déplacement du vaisseau
* @param bullets les balles du vaisseau
* @param last_fire le temps écoulé depuis le dernier tir du vaisseau
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

/**
 * @brief 
 * 
 * @param ship 
 * @param ship2 
 */
void damage_between_ships(Ship * ship, Ship * ship2);
#endif