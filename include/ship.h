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

Ship * init_player_ship(int x, int y, int speed);
void player_reload(Ship * ship);
Ship * init_flashing_ship(int x, int y, int speed);
Ship * init_normal_enemy_ship(int x, int y, int speed);
void free_ship(Ship * ship);
void move_ship(Ship * ship, int direction, int width, int height);
Bullet * player_fire(Ship * ship);
Bullet * enemy_fire(Ship * ship, Ship * player_ship);
Bullet * enemy_fire_normal(Ship * ship);
void take_damage_from_bullet(Ship * ship, Bullet * bullet);

#endif