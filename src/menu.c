#include "../include/menu.h"
#include "../include/interface.h"
#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <stdio.h>

void display_credits(MLV_Image * background){
    MLV_resize_image(background, WIDTH, HEIGHT);
    MLV_draw_image(background, 0, 0);
    MLV_Font * font = MLV_load_font("./data/fonts/main-font.ttf", 20);
    MLV_draw_text_with_font(WIDTH/3, HEIGHT/4 + 50, "Developpeurs: ",font, MLV_COLOR_GREEN1);
    MLV_draw_text_with_font(WIDTH/3, HEIGHT/4 + 70, "Ahmed SOUSSI", font, MLV_COLOR_WHITE);
    MLV_draw_text_with_font(WIDTH/3, HEIGHT/4 + 90, "Enzo Greneche", font, MLV_COLOR_WHITE);
    MLV_draw_text_with_font(WIDTH/3, HEIGHT/4 + 120, "Remerciments: ", font, MLV_COLOR_GREEN1);
    MLV_draw_text_with_font(WIDTH/3, HEIGHT/4 + 140, "M. Nicolas BORIE", font, MLV_COLOR_WHITE);
    MLV_free_font(font);
}

int display_menu(){
    return 0;
}