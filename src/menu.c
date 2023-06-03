#include "../include/menu.h"
#include "../include/interface.h"
#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <stdio.h>

void display_credits(MLV_Image * background){
    MLV_resize_image(background, WIDTH, HEIGHT);
    MLV_draw_image(background, 0, 0);
    MLV_Font * font = MLV_load_font("./data/fonts/main-font.ttf", 20);
    MLV_draw_text_with_font(WIDTH/3 + 2, HEIGHT/4 + 50, "Developpeurs: ",font, MLV_COLOR_GREEN1);
    MLV_draw_text_with_font(WIDTH/3 + 2, HEIGHT/4 + 70, "Ahmed SOUSSI", font, MLV_COLOR_WHITE);
    MLV_draw_text_with_font(WIDTH/3 + 2, HEIGHT/4 + 90, "Enzo Greneche", font, MLV_COLOR_WHITE);
    MLV_draw_text_with_font(WIDTH/3 + 2, HEIGHT/4 + 120, "Remerciments: ", font, MLV_COLOR_GREEN1);
    MLV_draw_text_with_font(WIDTH/3 + 2, HEIGHT/4 + 140, "M. Nicolas BORIE", font, MLV_COLOR_WHITE);
    MLV_free_font(font);
}

void display_play_box(int mouseX, int mouseY){
    MLV_Font * font = MLV_load_font("./data/fonts/main-font.ttf", 20);
    MLV_Font * font2 = MLV_load_font("./data/fonts/main-font.ttf", 25);
    if(mouseX >= (WIDTH/3) && mouseX < (WIDTH/3 + 20*6) && mouseY >= (HEIGHT/4 + 60) && mouseY < (HEIGHT/4 + 60 + 20*2)){
        MLV_draw_filled_rectangle(WIDTH/3, HEIGHT/4 + 60, 20*6, 20*2, MLV_COLOR_GREEN1);
        MLV_draw_rectangle(WIDTH/3, HEIGHT/4 + 60, 20*6, 20*2, MLV_COLOR_PURPLE);
        MLV_draw_text_with_font(WIDTH/3 + 25, HEIGHT/4 + 60 + 7, "Play",font2, MLV_COLOR_WHITE);
    }
    else{
        MLV_draw_filled_rectangle(WIDTH/3, HEIGHT/4 + 60, 20*6, 20*2, MLV_COLOR_PURPLE);
        MLV_draw_rectangle(WIDTH/3, HEIGHT/4 + 60, 20*6, 20*2, MLV_COLOR_GREEN);
        MLV_draw_text_with_font(WIDTH/3 + 25, HEIGHT/4 + 60 + 7, "Play",font, MLV_COLOR_WHITE);
    }
    MLV_free_font(font);
    MLV_free_font(font2);
}

void display_credits_box(int mouseX, int mouseY){
    MLV_Font * font = MLV_load_font("./data/fonts/main-font.ttf", 20);
    MLV_Font * font2 = MLV_load_font("./data/fonts/main-font.ttf", 25);
    if(mouseX >= WIDTH/3 && mouseX < (WIDTH/3 + 20*6) && mouseY >= (HEIGHT/4 + 120) && mouseY < HEIGHT/4 + 120 + 20*2){
        MLV_draw_filled_rectangle(WIDTH/3, HEIGHT/4 + 120, 20*6, 20*2, MLV_COLOR_GREEN1);
        MLV_draw_rectangle(WIDTH/3, HEIGHT/4 + 120, 20*6, 20*2, MLV_COLOR_PURPLE);
        MLV_draw_text_with_font(WIDTH/3 + 25, HEIGHT/4 + 120 + 7, "Credits",font2, MLV_COLOR_WHITE);
    }
    else{
        MLV_draw_filled_rectangle(WIDTH/3, HEIGHT/4 + 120, 20*6, 20*2, MLV_COLOR_PURPLE);
        MLV_draw_rectangle(WIDTH/3, HEIGHT/4 + 120, 20*6, 20*2, MLV_COLOR_GREEN1);
        MLV_draw_text_with_font(WIDTH/3 + 25, HEIGHT/4 + 120 + 7, "Credits",font, MLV_COLOR_WHITE);
    }
    MLV_free_font(font);
    MLV_free_font(font2);
}

void display_quit_box(int mouseX, int mouseY){
    MLV_Font * font = MLV_load_font("./data/fonts/main-font.ttf", 20);
    MLV_Font * font2 = MLV_load_font("./data/fonts/main-font.ttf", 25);
    if(mouseX >= WIDTH/3 && mouseX < (WIDTH/3 + 20*6) && mouseY >= (HEIGHT/4 + 180) && mouseY < HEIGHT/4 + 180 + 20*2){
        MLV_draw_filled_rectangle(WIDTH/3, HEIGHT/4 + 180, 20*6, 20*2, MLV_COLOR_GREEN1);
        MLV_draw_rectangle(WIDTH/3, HEIGHT/4 + 180, 20*6, 20*2, MLV_COLOR_PURPLE);
        MLV_draw_text_with_font(WIDTH/3 + 25, HEIGHT/4 + 180 + 7, "Quit",font2, MLV_COLOR_WHITE);
    }
    else{
        MLV_draw_filled_rectangle(WIDTH/3, HEIGHT/4 + 180, 20*6, 20*2, MLV_COLOR_PURPLE);
        MLV_draw_rectangle(WIDTH/3, HEIGHT/4 + 180, 20*6, 20*2, MLV_COLOR_GREEN1);
        MLV_draw_text_with_font(WIDTH/3 + 25, HEIGHT/4 + 180 + 7, "Quit",font, MLV_COLOR_WHITE);
    }
    MLV_free_font(font);
    MLV_free_font(font2);
}

int display_menu(MLV_Image * background){
    int x, y;
    MLV_Button_state state;
    MLV_Font * font = MLV_load_font("./data/fonts/main-font.ttf", 35);
    MLV_resize_image(background, WIDTH, HEIGHT);
    while(1){
        MLV_draw_image(background, 0, 0);
        MLV_draw_text_with_font(60, HEIGHT/5, "Shooting Odyssey",font, MLV_COLOR_ANTIQUEWHITE);
        MLV_get_mouse_position(&x, &y);
        display_play_box(x, y);
        display_credits_box(x, y);
        display_quit_box(x, y);
        MLV_actualise_window();
        
        MLV_Event event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &state);
        if(event == MLV_MOUSE_BUTTON){
            if(state == MLV_PRESSED){
                MLV_get_mouse_position(&x, &y);
                if(x >= (WIDTH/3) && x < (WIDTH/3 + 20*60) && y >= (HEIGHT/4 + 60) && y < (HEIGHT/4 + 60 + 20*2)){
                    MLV_free_font(font);
                    return PLAY;
                }
                if(x >= (WIDTH/3) && x < (WIDTH/3 + 20*60) && y >= (HEIGHT/4 + 120) && y < (HEIGHT/4 + 120 + 20*2)){
                    MLV_free_font(font);
                    return CREDITS;
                }
                if(x >= (WIDTH/3) && x < (WIDTH/3 + 20*60) && y >= (HEIGHT/4 + 180) && y < (HEIGHT/4 + 180 + 20*2)){
                    MLV_free_font(font);
                    return QUIT;
                }
            }
        }
    }
}