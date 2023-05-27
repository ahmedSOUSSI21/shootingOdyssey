#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <math.h>

#include "bullet.h"
#include "ship.h"
#include "interface.h"

/**
 * @struct Animation
 * @brief Structure représentant une animation
 *
    * @param source_image Image source de l'animation
    * @param images Tableau d'images de l'animation
    * @param nb_images Nombre d'images de l'animation
    * @param image_index Index de l'image courante
    * @param x Position x de l'animation
    * @param y Position y de l'animation
    * @param wait Temps d'attente entre chaque image
    * @param last_time Temps de la dernière image
 */
typedef struct _animation{
    MLV_Image * source_image;
    MLV_Image ** images;
    int nb_images;
    int image_index;
    int x; 
    int y;
    float wait;
    float last_time;
}Animation;

/**
 * @brief Initialise une animation d'explosion
    *
    * @param x Position x de l'animation
    * @param y Position y de l'animation

    * @return Animation * Pointeur sur l'animation initialisée
 */
Animation * init_explosion_animation(int x, int y);

/**
 * @brief Initialise une animation de rechargement
    *
    * @param x Position x de l'animation
    * @param y Position y de l'animation

    * @return Animation * Pointeur sur l'animation initialisée
 */
Animation * init_reloading_animation(int x, int y);

/**
 * @brief libération de la mémoire allouée pour une animation
    *
    * @param animation Animation à libérer
 */
void free_animation(Animation * animation);

/**
 * @brief Affiche l'animation courante
    *
    * @param animation Animation à afficher
 */
void display_current_frame(Animation * animation);