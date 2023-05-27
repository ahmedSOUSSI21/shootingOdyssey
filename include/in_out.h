#ifndef __IN_OUT_H__
#define __IN_OUT_H__

#include <stdio.h>
#include <stdlib.h>
#include "./ship.h"

/*
* @brief Reads the player's ship from a file

* @param file_name The name of the file to read from
* @param ennemy_ships The array of ennemy ships
* @param max_enemy_ships The maximum number of ennemy ships
*/
void read_enemies(const char * file_name, Ship ** enemy_ships, int max_enemy_ships);

#endif