#include <stdio.h>
#include <stdlib.h>
#include "../include/in_out.h"

void read_enemies(const char * file_name, Ship ** enemy_ships, int max_enemy_ships){
    int type, x, y, speed, j;
    Ship * new_enemy;
    FILE * f = fopen(file_name, "r");
    if(f == NULL){
        fprintf(stderr, "Erreur d'ouverture du fichier %s", file_name);
        return ;
    }
    while(fscanf(f, "%d %d %d %d", &type, &x, &y, &speed) != EOF){
        if(type == NORMAL_ENEMY_SHIP_TYPE){
            new_enemy = init_normal_enemy_ship(x, y, speed);
        }
        else{
            new_enemy = init_flashing_ship(x, y, speed);
        }
        for(j = 0; j < max_enemy_ships; j++){
            if(enemy_ships[j] == NULL){
                enemy_ships[j] = new_enemy;
                break;
            }
        }
    }
    fclose(f);
}

void write_score(const char * file_name, const char * player_name, float score){
    FILE * f = fopen(file_name, "a");
    if(f == NULL){
        fprintf(stderr, "Erreur d'ouverture du fichier %s", file_name);
        return ;
    }
    fprintf(f, "%s %.2f\n", player_name, score);
    fclose(f);
}