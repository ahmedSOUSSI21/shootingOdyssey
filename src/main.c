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
    MLV_create_window("Shooting Odyssey", NULL, WIDTH, HEIGHT);
    MLV_init_audio();
    MLV_Music * menu_music = MLV_load_music("./data/sounds/menu-principal.mp3");
    MLV_play_music(menu_music, 1.0, -1);
    MLV_Image * background_image = MLV_load_image("./data/images/credits.png");
    MLV_Image * zqsd = MLV_load_image("./data/images/zqsd.png");
    MLV_Image * space = MLV_load_image("./data/images/space.png");

    int choice = display_menu(background_image);
    
    while(choice != QUIT){
        if(choice == QUIT) {
            break;
        }
        if(choice == CREDITS){
            choice = display_credits(background_image);
        }
        if(choice == BACK_TO_MENU){
            choice = display_menu(background_image);
        }
        if(choice == PLAY){
            MLV_stop_music();
            gameloop();
            MLV_play_music(menu_music, 1.0, -1);
            choice = BACK_TO_MENU;
        }
        if(choice == HOW_TO_PLAY){
            choice = display_how_to_play(background_image, zqsd, space);
        }
        MLV_actualise_window();
    }

    MLV_stop_music();
    MLV_free_music(menu_music);
    MLV_free_audio();
    MLV_free_image(background_image);
    MLV_free_image(zqsd);
    MLV_free_image(space);
    MLV_free_window();
    return 0;
}
