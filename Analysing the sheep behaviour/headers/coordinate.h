//
// Created by Arsalan on 16/12/2020.
//

#ifndef MAIN_C_COORDINATE_H
#define MAIN_C_COORDINATE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct coordinate {
    double lat;
    double lon;
    int date;
    int month;
    int year;
    int hours;
    int min;
    int sec;
};
typedef struct coordinate coordinate;

struct coordinate_node {
    coordinate* val;
    struct coordinate_node* next;
};
typedef struct coordinate_node coordinate_node;

struct coordinate* get_coordinate(double lat, double lon, int date, int month, int year, int hours, int mins, int sec);

coordinate_node* get_coordinate_node(struct coordinate* b);

coordinate_node* insert_coordinate(coordinate_node** head, coordinate_node* to_insert);

#endif //MAIN_C_COORDINATE_H
