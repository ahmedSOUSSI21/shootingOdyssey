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

Bullet * init_bullet(int type, int x, int y, int damage, int speed, float angle);
void free_bullet(Bullet * bullet);
void move_bullet(Bullet * bullet);

#endif