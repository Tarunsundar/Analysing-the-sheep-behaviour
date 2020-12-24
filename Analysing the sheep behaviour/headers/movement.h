//
// Created by Arsalan on 16/12/2020.
//

#ifndef MAIN_C_MOVEMENT_H
#define MAIN_C_MOVEMENT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config.h"
#include "coordinate.h"

struct movement {
    coordinate* origin;
    coordinate* end;
    double dist;
    int time;
    double speed;
    char category[CATEGORY_LENGTH];
};
typedef struct movement movement;

struct movement_node {
    movement* val;
    struct movement_node* next;
};
typedef struct movement_node movement_node;

movement_node* insert_movement(movement_node** head, movement_node* to_insert);
movement* get_movement(coordinate* origin, coordinate* end, double dist, int time, double speed, char *category);
char* get_category(double speed);

void compute_movements(coordinate_node *curr, movement_node **head);

#endif //MAIN_C_MOVEMENT_H
