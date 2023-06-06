#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <math.h>
#include <time.h>

#include "../include/ship.h"
#include "../include/bullet.h"
#include "../include/interface.h"
#include "../include/game.h"
#include "../include/animations.h"
#include "../include/in_out.h"

#define MAX_ANIMATIONS 2048
#define MAX_ENEMY_SHIPS 100

void move_bullets(BulletWithImage ** bullets){
    int i;
    for(i = 0; i < MAX_BULLETS; i++){
        if(bullets[i] != NULL) move_bullet(bullets[i]->bullet);
    }
}

void free_bullets(BulletWithImage ** bullets){
    int i;
    for(i = 0; i < MAX_BULLETS; i++){
        if(bullets[i] != NULL) free_bullet_with_image(bullets[i]);
    }
}

void display_animations(Animation ** animations, float timeDelta){
    int i;
    for(i = 0; i < MAX_ANIMATIONS; i++){
        if(animations[i] != NULL){
            if(animations[i]->wait > animations[i]->last_time){
                MLV_draw_image(animations[i]->images[animations[i]->image_index], animations[i]->x, animations[i]->y);
                animations[i]->last_time += timeDelta;
                continue;
            }
            else{
                display_current_frame(animations[i]);
                animations[i]->last_time = 0.0;
            }
        }
    }
    for(i = 0; i < MAX_ANIMATIONS; i++){
        if(animations[i] != NULL){
            if(animations[i]->image_index == 0){
                free_animation(animations[i]);
                animations[i] = NULL;
            }
        }
    }
}

void free_all_animations(Animation ** animations){
    int i;
    for(i = 0; i < MAX_ANIMATIONS; i++){
        if(animations[i] != NULL){
            free_animation(animations[i]);
            animations[i] = NULL;
        }
    }
}

void add_animation(Animation ** animations, Animation * animation){
    int i;
    for(i = 0; i < MAX_ANIMATIONS; i++){
        if(animations[i] == NULL){
            animations[i] = animation;
            return ;
        }
    }
}

void enemy_collision(BulletWithImage ** bullets, Ship ** enemy_ships, Animation ** animations, int * enemy_killed, float * player_score, MLV_Sound * explosion_sound){
    int i, j;
    for(i = 0; i < MAX_BULLETS; i++){
        if(bullets[i]!= NULL){
            if(bullets[i]->bullet->type == PLAYER_BULLET_TYPE){
                for(j = 0; j < MAX_ENEMY_SHIPS; j++){
                    if(enemy_ships[j] != NULL && bullets[i] != NULL){
                        if(bullets[i]->bullet->x >= enemy_ships[j]->x && bullets[i]->bullet->x < (enemy_ships[j]->x + SHIP_WIDTH) 
                        && bullets[i]->bullet->y >= enemy_ships[j]->y && bullets[i]->bullet->y < (enemy_ships[j]->y + SHIP_HEIGHT)){
                            add_animation(animations, init_explosion_animation(bullets[i]->bullet->x, bullets[i]->bullet->y));
                            take_damage_from_bullet(enemy_ships[j], bullets[i]->bullet);
                            MLV_play_sound(explosion_sound, 1.0);
                            if(enemy_ships[j]->pv <= 0){
                                if(enemy_ships[j]->type == NORMAL_ENEMY_SHIP_TYPE){
                                    *player_score += 100;
                                }
                                if(enemy_ships[j]->type == FLASHING_ENEMY_SHIP_TYPE){
                                    *player_score += 150;
                                }
                                free_ship(enemy_ships[j]);
                                enemy_ships[j] = NULL;
                                *enemy_killed += 1;
                            }
                            remove_bullet(bullets, i);
                        }
                    }
                }
            }
        }
    }
}

int distance(Ship * ship, Ship * ship2){
    return sqrt(pow(ship->x - ship2->x, 2) + pow(ship->y - ship2->y, 2));
}

void player_collision(BulletWithImage ** bullets, Ship * player_ship, Ship** enemy_ships, Animation ** animations, int * enemy_killed, float * player_score, MLV_Sound * explosion_sound){
    int i;
    for(i = 0; i < MAX_BULLETS; i++){
        if(bullets[i]!= NULL){
            if(bullets[i]->bullet->type != PLAYER_BULLET_TYPE){
                if(bullets[i]->bullet->x >= player_ship->x && bullets[i]->bullet->x < (player_ship->x + SHIP_WIDTH) 
                && bullets[i]->bullet->y >= player_ship->y && bullets[i]->bullet->y < (player_ship->y + SHIP_HEIGHT)){
                    add_animation(animations, init_explosion_animation(bullets[i]->bullet->x, bullets[i]->bullet->y));
                    take_damage_from_bullet(player_ship, bullets[i]->bullet);
                    remove_bullet(bullets, i);
                    MLV_play_sound(explosion_sound, 1.0);
                }
            }
        }
    }

    for(i = 0; i < MAX_ENEMY_SHIPS; i++){
        if(enemy_ships[i] != NULL){
            if(distance(player_ship, enemy_ships[i]) <= 10) {
                damage_between_ships(player_ship, enemy_ships[i]);
                MLV_play_sound(explosion_sound, 1.0);
                if(enemy_ships[i]->pv <= 0){
                    free_ship(enemy_ships[i]);
                    enemy_ships[i] = NULL;
                    *enemy_killed += 1;
                    *player_score += 50;
                }
            }
        }
    }
}

void add_all_deltaTime(Ship ** enemy_ships, float deltaTime){
    int j;
    for(j = 0; j < MAX_ENEMY_SHIPS; j++){
        if(enemy_ships[j] != NULL){
            enemy_ships[j]->last_fire += deltaTime;
        }
    }
}

void add_enemy(Ship ** enemy_ships, Ship * new_enemy){
    int j;
    for(j = 0; j < MAX_ENEMY_SHIPS; j++){
        if(enemy_ships[j] == NULL){
            enemy_ships[j] = new_enemy;
            return ;
        }
    }
}

void move_enemies(Ship ** enemy_ships, Ship * player_ship){
    int i;
    for(i = 0; i < MAX_ENEMY_SHIPS; i++){
        if(enemy_ships[i] != NULL){
            if(enemy_ships[i]->type == NORMAL_ENEMY_SHIP_TYPE){
                move_ship(enemy_ships[i], DOWN, WIDTH, HEIGHT);
            }
            else{
                int destX = player_ship->x - enemy_ships[i]->x; 
                int destY = player_ship->y - enemy_ships[i]->y;
                if(destX < 0){
                    move_ship(enemy_ships[i], LEFT, WIDTH, HEIGHT);
                }
                else{
                    move_ship(enemy_ships[i], RIGHT, WIDTH, HEIGHT);
                }
                if(destY < 0){
                    move_ship(enemy_ships[i], UP, WIDTH, HEIGHT);
                }
                else{
                    move_ship(enemy_ships[i], DOWN, WIDTH, HEIGHT);
                }
            }
        }
    }
}

void enemies_fire(Ship ** enemy_ships, Ship * player_ship, BulletWithImage ** bullets){
    int i;
    for(i = 0; i < MAX_ENEMY_SHIPS; i++){
        if(enemy_ships[i] != NULL){
            Bullet * tmp;
            if(enemy_ships[i]->type == NORMAL_ENEMY_SHIP_TYPE){
                tmp = enemy_fire_normal(enemy_ships[i]);
            }
            else{
                tmp = enemy_fire(enemy_ships[i], player_ship);
            }
            if(tmp != NULL){
                add_bullet(bullets, tmp);
            }
        }
    }
}

void display_all_enemies(Ship ** enemy_ships, MLV_Image * normal_image, MLV_Image * flashing_image){
    int i;
    for(i = 0; i < MAX_ENEMY_SHIPS; i++){
        if(enemy_ships[i] != NULL){
            if(enemy_ships[i]->type == FLASHING_ENEMY_SHIP_TYPE){
                display_ship(enemy_ships[i], flashing_image);
            }
            else{
                display_ship(enemy_ships[i], normal_image);
            }
        }
    }
}

void free_all_enemies(Ship ** enemy_ships){
    int j;
    for(j = 0; j < MAX_ENEMY_SHIPS; j++){
        if(enemy_ships[j] != NULL){
            free_ship(enemy_ships[j]);
            enemy_ships[j] = NULL;
        }
    }
}

void remove_outscreen_normal(Ship ** enemy_ships){
    int i;
    for(i = 0; i < MAX_ENEMY_SHIPS; i++){
        if(enemy_ships[i] != NULL){
            if(enemy_ships[i]->y >= (HEIGHT - SHIP_HEIGHT)){
                free_ship(enemy_ships[i]);
                enemy_ships[i] = NULL;
            }
        }
    }
}

void treat_event(Ship * player_ship, BulletWithImage ** bullets, int * quit, int * move_left, int * move_right, int * move_up, int * move_down, int * fire_clicked){
    MLV_Keyboard_button key_sym;
    MLV_Button_state state;
    MLV_Event event = MLV_get_event(&key_sym, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &state);
    if(event == MLV_KEY){
        if(state == MLV_PRESSED){
            if (key_sym == MLV_KEYBOARD_q) *move_left = 1;
            if (key_sym == MLV_KEYBOARD_d) *move_right = 1;
            if (key_sym == MLV_KEYBOARD_z) *move_up = 1;
            if (key_sym == MLV_KEYBOARD_s) *move_down = 1;
            if (key_sym == MLV_KEYBOARD_SPACE) *fire_clicked = 1;
            if (key_sym == MLV_KEYBOARD_ESCAPE) *quit = 1;
        }
        else{
            if (key_sym == MLV_KEYBOARD_q) *move_left = 0;
            if (key_sym == MLV_KEYBOARD_d) *move_right = 0;
            if (key_sym == MLV_KEYBOARD_z) *move_up = 0;
            if (key_sym == MLV_KEYBOARD_s) *move_down = 0;
            if (key_sym == MLV_KEYBOARD_SPACE) *fire_clicked = 0;
            if (key_sym == MLV_KEYBOARD_ESCAPE) *quit = 0;
        }
    }

    if(*move_up) move_ship(player_ship, UP, WIDTH, HEIGHT);
    if(*move_down) move_ship(player_ship, DOWN, WIDTH, HEIGHT);
    if(*move_left) move_ship(player_ship, LEFT, WIDTH, HEIGHT);
    if(*move_right) move_ship(player_ship, RIGHT, WIDTH, HEIGHT);

    if(*fire_clicked && (player_ship->last_fire >= LAST_FIRE_PLAYER)){
        Bullet * tmp = player_fire(player_ship);
        if(tmp != NULL) add_bullet(bullets, tmp);
    }
}

void gameloop(){
    Ship * player_ship;
    Ship * enemy_ships[MAX_ENEMY_SHIPS] = {NULL};
    BulletWithImage * bullets[MAX_BULLETS] = {NULL};
    MLV_Music* music;
    float player_score = 0.0;
    int enemy_killed = 0;
    float time_played = 0.0;
    int quit = 0, move_left = 0, move_right = 0, move_up = 0, move_down = 0, fire_clicked = 0;
    MLV_Image * player_image;
    MLV_Image * enemy_image;
    MLV_Image * enemy_image2;
    Animation * animations[MAX_ANIMATIONS] = {NULL};
    ImageWithPosition * small_stars[6];
    ImageWithPosition * big_stars[6];
    ImageWithPosition * moon = NULL;
    float deltaTime = 0.0;
    int current_time = 0, previous_time = 0;
    float reload = 0.0;
    struct timespec new, last;
    init_map(small_stars, big_stars, &moon);
    music = MLV_load_music("./data/sounds/menu-sound.ogg");
    MLV_Sound * explosion_sound = MLV_load_sound("./data/sounds/explosion.wav");
    MLV_play_music(music,1.0, -1);
    player_image = MLV_load_image("./data/images/ship.png");
    player_ship = init_player_ship(150, 600, 5);
    read_enemies("./data/files/enemies.txt", enemy_ships, MAX_ENEMY_SHIPS);
    enemy_image = MLV_load_image("./data/images/enemy_normal.png");
    enemy_image2 = MLV_load_image("./data/images/enemy_flashing.png");
    while(!quit){
        if(player_ship->pv <= 0) break;
        previous_time = current_time;
        current_time = MLV_get_time();
        deltaTime = (float)(current_time - previous_time);
        player_score += deltaTime/100;
        time_played += deltaTime/1000;
        player_ship->last_fire += deltaTime;
        if(player_ship->ammo <= 0){
            if(reload == 0.0)   add_animation(animations, init_reloading_animation(WIDTH/2, HEIGHT/2));
            reload += deltaTime;
            if(reload >= PLAYER_MINIMUM_RELOAD_TIME){
                player_reload(player_ship);
                reload = 0.0;
            }
        }
        
        add_all_deltaTime(enemy_ships, deltaTime);
        enemy_collision(bullets, enemy_ships, animations, &enemy_killed, &player_score, explosion_sound);
        player_collision(bullets, player_ship, enemy_ships, animations, &enemy_killed, &player_score, explosion_sound);
        MLV_clear_window(MLV_COLOR_BLACK);
        clock_gettime(0, &last);
        display_map(small_stars, big_stars, moon);
        display_ship(player_ship, player_image);
        display_pv_ammo_score(player_ship, player_score);
        display_all_enemies(enemy_ships, enemy_image, enemy_image2);
        display_bullets(bullets);
        display_animations(animations, deltaTime);
        MLV_actualise_window();
        treat_event(player_ship, bullets, &quit, &move_left, &move_right, &move_up, &move_down, &fire_clicked);
        move_enemies(enemy_ships, player_ship);
        enemies_fire(enemy_ships, player_ship, bullets);
        move_bullets(bullets);
        remove_out_screen_bullets(bullets);
        remove_outscreen_normal(enemy_ships);
        clock_gettime(0, &new);
        int accum = (new.tv_sec - last.tv_sec )+((new.tv_nsec - last.tv_nsec)/1000000000) ;
        if(accum < (1.0/60.0)){
            MLV_wait_milliseconds((int)(((1.0/60.0)-accum) * 1000));
        }
    }

    char * name = get_player_name();
    write_score("./data/output/scores.txt", name, player_score);
    free(name);
    
    MLV_Image * background_image = MLV_load_image("./data/images/credits.png");
    MLV_resize_image(background_image, WIDTH, HEIGHT);

    int size;
    Score * scores = fread_score("./data/output/scores.txt", &size);
    if(size > 10){
        size = 10;
    }

    int back_to_menu = 0;
    while(!back_to_menu){
        int mouse_x, mouse_y;
        MLV_get_mouse_position(&mouse_x, &mouse_y);
        back_to_menu = display_game_over(player_score, enemy_killed, time_played, mouse_x, mouse_y, scores, size, background_image);
        MLV_actualise_window();
    }
    
    MLV_free_image(background_image);
    free(scores);
    MLV_stop_music();
    MLV_free_music(music);
    MLV_free_sound(explosion_sound);
    free_all_animations(animations);
    free_map(small_stars, big_stars, &moon);
    free_bullets(bullets);
    free_all_enemies(enemy_ships);
    free_ship(player_ship);
    MLV_free_image(player_image);
    MLV_free_image(enemy_image);
    MLV_free_image(enemy_image2);
}