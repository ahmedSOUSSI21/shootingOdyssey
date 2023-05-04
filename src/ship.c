#include "../include/ship.h"
#include "../include/bullet.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Ship * init_player_ship(int x, int y, int speed){
    int i;
    Ship * ship;
    ship = malloc(sizeof(Ship));
    ship->x = x;
    ship->y = y;
    ship->speed = speed;
    ship->ammo = 15;
    ship->pv = 100;
    ship->bullets = malloc(sizeof(Bullet*) * ship->ammo);
    ship->type = PLAYER_SHIP_TYPE;
    for(i = 0; i < ship->ammo; i++){
        ship->bullets[i] = init_bullet(PLAYER_BULLET_TYPE, x + 10, y, 34, 5, -PI/2);
    }
    ship->last_fire = 0.0f;
    return ship;
}

void player_reload(Ship * ship){
    int i;
    ship->ammo = 15;
    for(i = 0; i < ship->ammo; i++){
        ship->bullets[i] = init_bullet(PLAYER_BULLET_TYPE, ship->x+10, ship->y, 34, 5, -PI/2);
    }
}

Ship * init_flashing_ship(int x, int y, int speed){
    int i;
    Ship * ship;
    ship = malloc(sizeof(Ship));
    ship->x = x;
    ship->y = y;
    ship->speed = speed;
    ship->ammo = 1200;
    ship->pv = 100;
    ship->type = FLASHING_ENEMY_SHIP_TYPE;
    ship->bullets = malloc(sizeof(Bullet*) * ship->ammo);
    for(i = 0; i < ship->ammo; i++){
        ship->bullets[i] = init_bullet(FLASHING_ENEMY_BULLET_TYPE, x, y, 25, 5, 3*PI/2);
    }
    ship->last_fire = 1.0;
    return ship;
}

Ship * init_normal_enemy_ship(int x, int y, int speed){
    int i;
    Ship * ship;
    ship = malloc(sizeof(Ship));
    ship->x = x;
    ship->y = y;
    ship->speed = speed;
    ship->ammo = 1200;
    ship->pv = 100;
    ship->bullets = malloc(sizeof(Bullet*) * ship->ammo);
    ship->type = NORMAL_ENEMY_SHIP_TYPE;
    for(i = 0; i < ship->ammo; i++){
        ship->bullets[i] = init_bullet(NORMA_ENEMY_BULLET_TYPE, x, y, 15, 6, 3*PI/2);
    }
    ship->last_fire = 1.0;
    return ship;
}

void free_ship(Ship * ship){
    int i;
    for(i = 0; i < ship->ammo; i++){
        free_bullet(ship->bullets[i]);
    }
    free(ship); 
    ship = NULL;
}

void move_ship(Ship * ship, int direction, int width, int height){
    int i;
    if(direction == UP){
        ship->y -= ship->speed;
        if(ship->y < 0){
            ship->y = 0;
        }
    }
    if(direction == DOWN){
        ship->y += ship->speed;
        if(ship->y > (height - SHIP_HEIGHT)){
            ship->y = height - SHIP_HEIGHT;
        }
    }
    if(direction == LEFT){
        ship->x -= ship->speed;
        if(ship->x < 0){
            ship->x = 0;
        }
    }
    if(direction == RIGHT){
        ship->x += ship->speed;
        if(ship->x > (width - SHIP_WIDTH)){
            ship->x = width - SHIP_WIDTH;
        }
    }

    for(i = 0; i < ship->ammo; i++){
        ship->bullets[i]->x = ship->x+10;
        ship->bullets[i]->y = ship->y;
    }
    
}

Bullet * player_fire(Ship * ship){
    if(ship->ammo == 0){
        return NULL;
    }

    Bullet * res = init_bullet(
        PLAYER_BULLET_TYPE,
        ship->bullets[ship->ammo-1]->x, 
        ship->bullets[ship->ammo-1]->y, 
        ship->bullets[ship->ammo-1]->damage, 
        ship->bullets[ship->ammo-1]->speed, 
        ship->bullets[ship->ammo-1]->angle
    );
    free_bullet(ship->bullets[ship->ammo - 1]);
    ship->ammo--;
    ship->last_fire = 0.0;
    return res;
}

float calculate_angle(Ship* ship, Ship* player_ship) {
    int dx = player_ship->x - ship->x;
    int dy = player_ship->y - ship->y;
    
    float angle = atan2(dy, dx);
    
    return angle;
}

Bullet * enemy_fire(Ship * ship, Ship * player_ship){
    if(ship->ammo == 0){
        return NULL;
    }
    if(ship->last_fire <= LAST_FIRE_ENEMY){
        return NULL;
    }

    float angle = calculate_angle(ship, player_ship);

    Bullet * res = init_bullet(
        ship->bullets[ship->ammo-1]->type,
        ship->bullets[ship->ammo-1]->x, 
        ship->bullets[ship->ammo-1]->y, 
        ship->bullets[ship->ammo-1]->damage, 
        ship->bullets[ship->ammo-1]->speed, 
        angle
    );
    free_bullet(ship->bullets[ship->ammo - 1]);
    ship->ammo--;
    ship->last_fire = 0.0;
    return res;
}

Bullet * enemy_fire_normal(Ship * ship){
    if(ship->ammo == 0){
        return NULL;
    }
    if(ship->last_fire <= LAST_FIRE_ENEMY){
        return NULL;
    }
    Bullet * res = init_bullet(
        ship->bullets[ship->ammo-1]->type,
        ship->bullets[ship->ammo-1]->x, 
        ship->bullets[ship->ammo-1]->y, 
        ship->bullets[ship->ammo-1]->damage, 
        ship->bullets[ship->ammo-1]->speed, 
        PI/2
    );
    free_bullet(ship->bullets[ship->ammo - 1]);
    ship->ammo--;
    ship->last_fire = 0.0;
    return res;
}

void take_damage_from_bullet(Ship * ship, Bullet * bullet){
    ship->pv -= bullet->damage;
}