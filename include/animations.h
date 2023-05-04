#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <math.h>

#include "bullet.h"
#include "ship.h"
#include "interface.h"

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

Animation * init_explosion_animation(int x, int y);
Animation * init_reloading_animation(int x, int y);
void free_animation(Animation * animation);
void display_current_frame(Animation * animation);