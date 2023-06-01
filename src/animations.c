#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <math.h>

#include "../include/animations.h"

Animation * init_explosion_animation(int x, int y){
    Animation * res = malloc(sizeof(Animation));
    MLV_Image * source = MLV_load_image("./data/images/explosion-Sheet.png");

    res->source_image = source;
    res->nb_images = 5;
    res->x = x;
    res->y = y;
    res->wait = 100;
    res->last_time = 100;

    MLV_Image ** images = malloc(sizeof(MLV_Image *) * res->nb_images);
    images[0] = MLV_copy_partial_image(source, 0, 0, 16, 16);
    images[1] = MLV_copy_partial_image(source, 16, 0, 16, 16);
    images[2] = MLV_copy_partial_image(source, 32, 0, 16, 16);
    images[3] = MLV_copy_partial_image(source, 48, 0, 16, 16);
    images[4] = MLV_copy_partial_image(source, 64, 0, 16, 16);

    res->images = images;
    res->image_index = 0;
    return res;
}

Animation * init_reloading_animation(int x, int y){
    Animation * res = malloc(sizeof(Animation));
    MLV_Image * source = MLV_load_image("./data/images/reload.png");

    res->source_image = source;
    res->nb_images = 8;
    res->x = x;
    res->y = y;

    res->wait = 200;
    res->last_time = 200;

    MLV_Image ** images = malloc(sizeof(MLV_Image * ) * res->nb_images);
    images[0] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[0], 45.00);
    images[1] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[1], 90.00);
    images[2] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[2], 135.00);
    images[3] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[3], 180.00);
    images[4] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[4], 225.00);
    images[5] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[5], 270.00);
    images[6] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[6], 315.00);
    images[7] = MLV_load_image("./data/images/reload.png");
    MLV_rotate_image(images[7], 360.00);

    for(int i = 0; i < 8; i++){
        MLV_resize_image(images[i], 33, 33);
    }
    
    res->images = images;
    res->image_index = 0;
    return res;
}

void free_animation(Animation * animation){
    int i;
    for(i = 0; i < animation->nb_images; i++){
        MLV_free_image(animation->images[i]);
    }
    free(animation->images);

    MLV_free_image(animation->source_image);
    free(animation);
    animation = NULL;
}

void display_current_frame(Animation * animation){
    MLV_draw_image(animation->images[animation->image_index], animation->x, animation->y);
    if(animation->image_index == (animation->nb_images - 1)){
        animation->image_index = 0;
    }
    else{
        animation->image_index+=1;
    }
}
