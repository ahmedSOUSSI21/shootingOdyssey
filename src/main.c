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
    MLV_create_window("Menu", NULL, WIDTH, HEIGHT);
    MLV_Image * background_image = MLV_load_image("./data/images/credits.png");
    int choice = display_menu(background_image);
    if(choice == QUIT){
        MLV_free_image(background_image);
        MLV_free_window();
        return 0;
    }
    if(choice == CREDITS){
        display_credits(background_image);
        MLV_actualise_window();
        MLV_wait_seconds(5);
        MLV_free_image(background_image);
        MLV_free_window();
        return 0;
    }
    else{
        MLV_free_image(background_image);
        MLV_free_window();
        gameloop();
    } 
    return 0;
}