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
    MLV_init_audio();
    MLV_Music * menu_music = MLV_load_music("./data/sounds/menu-principal.mp3");
    MLV_play_music(menu_music, 1.0, -1);
    MLV_Image * background_image = MLV_load_image("./data/images/credits.png");
    int choice = display_menu(background_image);
    
    while(choice != PLAY){
        if(choice == QUIT) {
            MLV_free_image(background_image);
            MLV_free_window();
            return 0;
        }
        if(choice == CREDITS){
            choice = display_credits(background_image);
        }
        if(choice == BACK_TO_MENU){
            choice = display_menu(background_image);
        }
        MLV_actualise_window();
    }
    MLV_stop_music();
    MLV_free_music(menu_music);
    MLV_free_audio();
    MLV_free_image(background_image);
    MLV_free_window();
    gameloop();

    return 0;
}
