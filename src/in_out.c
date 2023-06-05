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

/**
 * @brief Compare deux scores
 * 
 * @param a le premier score
 * @param b le deuxième score
 * @return int 
 */
int more(float a, float b) {
	return a > b;
}

/**
 * @brief Echange deux scores
 * 
 * @param a le premier score
 * @param b le deuxième score
 */
void swap(Score *a, Score *b) {
	Score tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief Tri par sélection
 * 
 * @param t le tableau à trier
 * @param size la taille du tableau
 */
void selection_sort(Score t[], int size) {
	int index, i, j;
	for(i = 0; i < size; i++){
		index = i;
		for(j = i+1; j < size; j++){
			if(more(t[j].score, t[index].score)){
				index = j;
			}
		}
		if(index != i){
			swap(&t[index], &t[i]);
		}
	}
}

 /** @brief Lit les scores dans un fichier
 * 
 * @param file le fichier à lire
 * @param size la taille du tableau de scores
 * @return Score* le tableau de scores
 */
Score * fread_score(const char * file, int * size){
    FILE * f;
    int i = 0;

    f = fopen(file, "r");
    if(f == NULL){
        fprintf(stderr, "Erreur d'ouverture du fichier %s\n", file);
        return NULL;
    }
    Score * tab = malloc(sizeof(Score) * MAX_SCORES);
    if(tab == NULL) return NULL;

    while(fscanf(f, "%s %f", tab[i].player_name, &tab[i].score) != EOF && i < MAX_SCORES){
        i++;
    }
    selection_sort(tab, i);
    *size = i;
    return tab;
}