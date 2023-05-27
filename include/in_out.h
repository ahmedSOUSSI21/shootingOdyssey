#ifndef __IN_OUT_H__
#define __IN_OUT_H__

#include <stdio.h>
#include <stdlib.h>
#include "./ship.h"

void read_enemies(const char * file_name, Ship ** enemy_ships, int max_enemy_ships);

#endif