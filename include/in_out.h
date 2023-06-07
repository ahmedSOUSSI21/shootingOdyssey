#ifndef __IN_OUT_H__
#define __IN_OUT_H__

#include <stdio.h>
#include <stdlib.h>
#include "./ship.h"
#define MAX_SCORES 1024

/**
* @brief Reads the player's ship from a file

* @param file_name The name of the file to read from
* @param ennemy_ships The array of ennemy ships
* @param max_enemy_ships The maximum number of ennemy ships
*/
void read_enemies(const char * file_name, Ship ** enemy_ships, int max_enemy_ships);

/**
 * @brief écrit le score du joueur dans le fichier file_name
 * 
 * @param file_name le chemin vers le fichier d'écriture
 * @param player_name le nom du joueur
 * @param score le score du joueur
 */
void write_score(const char * file_name, const char * player_name, float score);

/**
 * @brief écrit les scores dans un fichier
 *
 * @param player_name le nom du joueur
* @param score le score du joueur
 */
typedef struct score{
    char player_name[32];
    float score;
} Score;

/**
 * @brief Lit les scores dans un fichier
 * 
 * @param file le fichier à lire
 * @param size la taille du tableau de scores
 * @return Score* le tableau de scores
 */
Score * fread_score(const char * file, int * size);

#endif