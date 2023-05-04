#include "../include/bullet.h"
#include <stdlib.h>
#include <math.h>

Bullet * init_bullet(int type, int x, int y, int damage, int speed, float angle){
    Bullet * res = malloc(sizeof(Bullet));
    res->type = type;
    res->x = x;
    res->y = y;
    res->damage = damage;
    res->speed = speed;
    res->angle = angle;
    return res;
}

void free_bullet(Bullet * bullet){
    free(bullet);
}

void move_bullet(Bullet* bullet) {
    float dx = bullet->speed * cos(bullet->angle);
    float dy = bullet->speed * sin(bullet->angle);
    
    bullet->x += (int)dx;
    bullet->y += (int)dy;
}