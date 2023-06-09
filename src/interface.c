#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "../include/interface.h"

ImageWithPosition * init_image_with_position(const char * image_file_name, int x, int y, int speed){
    MLV_Image * image = MLV_load_image(image_file_name);
    ImageWithPosition * res = malloc(sizeof(ImageWithPosition));
    res->image = image;
    res->x = x;
    res->y = y;
    res->speed = speed;
    return res;
}

void free_image_with_position(ImageWithPosition * iwp){
    MLV_free_image(iwp->image);
    free(iwp);
}

BulletWithImage * init_bullet_with_image(Bullet * bullet){
    BulletWithImage * bwi = malloc(sizeof(BulletWithImage));
    bwi->bullet = bullet;
    if(bullet->type == PLAYER_SHIP_TYPE){
        bwi->image = MLV_load_image("./data/images/bullet.png");
    }
    else if(bullet->type == NORMAL_ENEMY_SHIP_TYPE){
        bwi->image = MLV_load_image("./data/images/normal_enemy_bullet.png");
    }
    else{
        bwi->image = MLV_load_image("./data/images/flashing_enemy_bullet.png");
    }
    MLV_resize_image(bwi->image, 12, 12);
    return bwi;
}

void free_bullet_with_image(BulletWithImage * bwi){
    free_bullet(bwi->bullet);
    MLV_free_image(bwi->image);
    free(bwi);
    bwi = NULL;
}

void add_bullet(BulletWithImage ** bullets, Bullet * bullet){
    int i;
    for(i = 0; i < MAX_BULLETS; i++){
        if(bullets[i] == NULL){
            bullets[i] = init_bullet_with_image(bullet);
            break;
        }
    }
}

//fonction qui permet de supprimer les bullets qui sont hors de l'écran
void remove_out_screen_bullets(BulletWithImage ** bullets){
    int i;
    for(i = 0; i < MAX_BULLETS; i++){
        if(bullets[i] != NULL){
            if(bullets[i]->bullet->x < 0 || bullets[i]->bullet->x >= WIDTH || bullets[i]->bullet->y < 0 || bullets[i]->bullet->y > HEIGHT){
                free_bullet_with_image(bullets[i]);
                bullets[i] = NULL;
            }
        }
    }
}

//fonction qui permet de supprimer une bullet
void remove_bullet(BulletWithImage ** bullets, int index){
    free_bullet_with_image(bullets[index]);
    bullets[index] = NULL;
}

//fonction qui permet d'afficher les bullets
void display_bullets(BulletWithImage ** bullets){
    int i;
    for(i = 0; i < MAX_BULLETS; i++){
        if(bullets[i] != NULL){
            MLV_draw_image(bullets[i]->image, bullets[i]->bullet->x, bullets[i]->bullet->y);
        }
    }
}

//fonction qui permet d'afficher le vaisseau
void display_ship(Ship * ship, MLV_Image * image){
    MLV_draw_image(image, ship->x, ship->y);
}

//fonction qui permet d'afficher le score
void display_pv_ammo_score(Ship * ship, float score){
    MLV_draw_rectangle(2, 2, 100, 10, MLV_COLOR_RED);
    MLV_draw_filled_rectangle(2, 2, ship->pv, 10, MLV_COLOR_GREEN);
    MLV_draw_rectangle(2, 13, 15, 10, MLV_COLOR_RED);
    MLV_draw_filled_rectangle(2, 13, ship->ammo, 10, MLV_COLOR_BLUE);
    char str[32];
    sprintf(str, "score : %.2f", score);
    MLV_draw_text(110, 2, str, MLV_COLOR_WHITE);
}

//fonction qui permet d'afficher la map
void display_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition * moon){
    int i;
    for(i = 0; i < 6; i++){
        MLV_draw_image(small_stars[i]->image, small_stars[i]->x, small_stars[i]->y);
        small_stars[i]->y += small_stars[i]->speed;

        if(small_stars[i]->y >= HEIGHT){
            small_stars[i]->y =  (-STAR_IMAGE_HEIGHT);
        }
    }

    MLV_draw_image(moon->image, moon->x, moon->y);
    moon->y += moon->speed;
    
    if(moon->y >= HEIGHT){
        moon->y = (-MOON_IMAGE_HEIGHT);
    }
    
    for(i = 0; i < 6; i++){
        MLV_draw_image(big_stars[i]->image, big_stars[i]->x, big_stars[i]->y);
        big_stars[i]->y += big_stars[i]->speed;

        if(big_stars[i]->y >= HEIGHT){
            big_stars[i]->y = (-STAR_IMAGE_HEIGHT);
        }
    }
}

//fonction qui permet d'initialiser la map
void init_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition ** moon){
    int count = 0;
    small_stars[count] = init_image_with_position("./data/images/small_stars.png",0 ,-STAR_IMAGE_HEIGHT, 1);
    big_stars[count] = init_image_with_position("./data/images/big_stars.png",0 ,-STAR_IMAGE_HEIGHT, 2);
    count++;
    small_stars[count] = init_image_with_position("./data/images/small_stars.png",STAR_IMAGE_WIDTH ,-STAR_IMAGE_HEIGHT, 1);
    big_stars[count] = init_image_with_position("./data/images/big_stars.png",STAR_IMAGE_WIDTH ,-STAR_IMAGE_HEIGHT, 2);
    count++;
    for(int i = 0; i < WIDTH - 1; i += STAR_IMAGE_WIDTH){
        for(int j = 0; j < HEIGHT - 1; j+= STAR_IMAGE_HEIGHT){
            small_stars[count] = init_image_with_position("./data/images/small_stars.png",i ,j, 1);
            big_stars[count] = init_image_with_position("./data/images/big_stars.png",i ,j, 2);
            count++;
        }
    }
    *moon = init_image_with_position("./data/images/moon.png", 200, 10, 3);
}

//fonction qui permet de liberer la memoire allouer pour la map
void free_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition ** moon){
    for(int i = 0; i < 6; i++){
        free_image_with_position(small_stars[i]);
        free_image_with_position(big_stars[i]);
    }
    free_image_with_position(*moon);
}

char * get_player_name(){
    char * str;
    MLV_wait_input_box(WIDTH/4, HEIGHT/4, 200 , 30, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_BEIGE, "Your name:", &str);
    return str;
}

int display_game_over(float score, int enemy_killed, float time_played, int mouseX, int mouseY, Score * scores, int size, MLV_Image * background){
    char str[32];
    MLV_Font * font = MLV_load_font("./data/fonts/main-font.ttf", 20);
    MLV_draw_image(background, 0, 0);
    MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4 - 100, "GAME OVER", font, MLV_COLOR_GREEN);
    MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4, "Score : ", font, MLV_COLOR_GREEN);
    sprintf(str, "%.2f", score);
    MLV_draw_text_with_font(WIDTH/2 + 80, HEIGHT/4,str, font, MLV_COLOR_WHITE);
    MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4 + 30, "Enemy killed : ", font, MLV_COLOR_GREEN);
    sprintf(str, "%d", enemy_killed);
    MLV_draw_text_with_font(WIDTH/2 + 80, HEIGHT/4 + 60, str, font, MLV_COLOR_WHITE);
    sprintf(str, "%.2f", time_played);
    MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4 + 90, "Time played : ", font, MLV_COLOR_GREEN);
    MLV_draw_text_with_font(WIDTH/2 + 80, HEIGHT/4 + 120, str, font, MLV_COLOR_WHITE);
    MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4 + 150, "Top 10 : ", font, MLV_COLOR_GREEN);
    
    for(int i = 0; i < size; i++){
        MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4 + 180 + i * 20, scores[i].player_name, font, MLV_COLOR_RED);
        sprintf(str, "%.2f", scores[i].score);
        MLV_draw_text_with_font(WIDTH/2 + 80, HEIGHT/4 + 180 + i * 20, str, font, MLV_COLOR_WHITE);
    }
    int result = 0;
    if(mouseX >= WIDTH/2 - 100 && mouseX <= WIDTH/2 + 100 && mouseY >= HEIGHT/4 + 210 + size * 20 && mouseY <= HEIGHT/4 + 230 + size * 20){
        MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4 + 210 + size * 20, "BACK TO MENU", font, MLV_COLOR_GREEN);
    }else{
        MLV_draw_text_with_font(WIDTH/2 - 100, HEIGHT/4 + 210 + size * 20, "BACK TO MENU", font, MLV_COLOR_WHITE);
    }
    MLV_free_font(font);
    MLV_Button_state state;
    MLV_Event event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &state);
    if(event == MLV_MOUSE_BUTTON && state == MLV_PRESSED && mouseX >= WIDTH/2 - 100 && mouseX <= WIDTH/2 + 100 && mouseY >= HEIGHT/4 + 210 + size * 20 && mouseY <= HEIGHT/4 + 230 + size * 20){
        result = 1;
    }
    return result;
}