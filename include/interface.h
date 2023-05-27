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

/**
 * @struct _image_and_pos
 * @brief Structure contenant une image et sa position
    *
    * @param image L'image
    * @param x La position en x
    * @param y La position en y
    * @param speed La vitesse de déplacement
 */
typedef struct _image_and_pos{
    MLV_Image * image;
    int x; 
    int y;
    int speed;
}ImageWithPosition;

/**
 * @struct _bullet_with_image
 * @brief Structure contenant un bullet et son image
    *
    * @param bullet Le bullet
    * @param image L'image
 */
typedef struct _bullet_with_image{
    Bullet * bullet;
    MLV_Image * image;
}BulletWithImage;

/**
 * @brief Initialise une image avec sa position
    *
    * @param image_file_name Le nom du fichier image
    * @param x La position en x
    * @param y La position en y
    * @param speed La vitesse de déplacement
    * @return ImageWithPosition* L'image avec sa position
 */
ImageWithPosition * init_image_with_position(const char * image_file_name, int x, int y, int speed);

/**
 * @brief Libère une image avec sa position
    *
    * @param iwp L'image avec sa position
 */
void free_image_with_position(ImageWithPosition * iwp);

/**
 * @brief Initialise un bullet avec son image
    *
    * @param bullet Le bullet
    * @return BulletWithImage* Le bullet avec son image
 */
BulletWithImage * init_bullet_with_image(Bullet * bullet);

/**
 * @brief Libère un bullet avec son image
    *
    * @param bwi Le bullet avec son image
 */
void free_bullet_with_image(BulletWithImage * bwi);

/**
 * @brief Ajoute un bullet avec son image dans un tableau de bullet avec image
    *
    * @param bullets Le tableau de bullet avec image
    * @param bullet Le bullet avec son image
 */
void add_bullet(BulletWithImage ** bullets, Bullet * bullet);

/**
 * @brief Affiche les bullets
    *
    * @param bullets Le tableau de bullet avec image
 */
void display_bullets(BulletWithImage ** bullets);

/**
 * @brief Efface les bullets qui sont sortis de l'écran
    *
    * @param bullets Le tableau de bullet avec image
 */
void remove_out_screen_bullets(BulletWithImage ** bullets);

/**
 * @brief Efface un bullet
    *
    * @param bullets Le tableau de bullet avec image
    * @param index L'index du bullet avec son image à effacer
 */
void remove_bullet(BulletWithImage ** bullets, int index);

/**
 * @brief Affiche le vaisseau
    *
    * @param ship Le vaisseau
    * @param image L'image du vaisseau
 */
void display_ship(Ship * ship, MLV_Image * image);

/**
 * @brief Affiche les points de vie du vaisseau et les munitions
    *
    * @param ship Le vaisseau
 */
void display_pv_ammo(Ship * ship);

/**
 * @brief Affiche la map
    *
    * @param small_stars Les petites étoiles
    * @param big_stars Les grosses étoiles
    * @param moon La lune
 */
void display_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition * moon);

/**
 * @brief Initialise la map
    *
    * @param small_stars Les petites étoiles
    * @param big_stars Les grosses étoiles
    * @param moon La lune
 */
void init_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition ** moon);

/**
 * @brief Libère la map
    *
    * @param small_stars Les petites étoiles
    * @param big_stars Les grosses étoiles
    * @param moon La lune
 */
void free_map(ImageWithPosition ** small_stars, ImageWithPosition ** big_stars, ImageWithPosition ** moon);

#endif