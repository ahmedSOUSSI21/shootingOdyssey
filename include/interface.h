#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <stdlib.h>
#include <math.h>
#include <MLV/MLV_all.h>
#include "../include/ship.h"
#include "../include/bullet.h"

#define MAX_BULLETS 2048
#define WIDTH 320
#define HEIGHT 640
#define STAR_IMAGE_WIDTH 160
#define STAR_IMAGE_HEIGHT 320
#define MOON_IMAGE_WIDTH 90
#define MOON_IMAGE_HEIGHT 66
#define HEALTH_BAR_X 10
#define HEALTH_BAR_Y (HEIGHT - 43)
#define IMAGE_DIR "data/images/"
#define SOUND_DIR "data/sounds/"

typedef struct _image_and_pos{
    MLV_Image * image;
    int x; 
    int y;
    int speed;
}ImageWithPosition;

typedef struct _bullet_with_image{
    Bullet * bullet;
    MLV_Image * image;
}BulletWithImage;

ImageWithPosition * init_image_with_position(const char * image_file_name, int x, int y, int speed);
void free_image_with_position(ImageWithPosition * iwp);
BulletWithImage * init_bullet_with_image(Bullet * bullet);
void free_bullet_with_image(BulletWithImage * bwi);
void add_bullet(BulletWithImage ** bullets, Bullet * bullet);
void display_bullets(BulletWithImage ** bullets);
void remove_out_screen_bullets(BulletWithImage ** bullets);
void remove_bullet(BulletWithImage ** bullets, int index);
void display_ship(Ship * ship, MLV_Image * image);
void display_pv_ammo(Ship * ship);
void display_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition * moon);
void init_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition ** moon);
void free_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition ** moon);

#endif