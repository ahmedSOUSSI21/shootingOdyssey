#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>
#include <time.h>

#include "../include/bullet.h"
#include "../include/ship.h"
#include "../include/interface.h"
#include "../include/game.h"
#include "../include/menu.h"


int main(int argc, char * argv[]){
    MLV_create_window("Credits", NULL, WIDTH, HEIGHT);
    MLV_Image * background_image = MLV_load_image("./data/images/credits.png");
    display_credits(background_image);
    MLV_actualise_window();
    MLV_wait_seconds(5);
    MLV_free_window();
    gameloop();    
    return 0;
}