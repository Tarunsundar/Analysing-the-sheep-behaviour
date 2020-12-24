//
// Created by Arsalan on 16/12/2020.
//

#include "../headers/coordinate.h"

/**
 * Create coordinate struct
 * @param lat
 * @param lon
 * @param date
 * @param month
 * @param year
 * @param hours
 * @param min
 * @param sec
 * @return created coordinate struct
 */
coordinate * get_coordinate(double lat, double lon, int date, int month, int year, int hours, int min, int sec) {
    coordinate* b = malloc(sizeof(coordinate));
    b->date = date;
    b->month = month;
    b->year = year;
    b->hours = hours;
    b->min = min;
    b->sec = sec;
    b->lat = lat;
    b->lon = lon;

    return b;
}

/**
 * Create list node for coordinate struct
 * @param b
 * @return created list node
 */
coordinate_node* get_coordinate_node(coordinate* b) {
    coordinate_node* n = malloc(sizeof(coordinate_node));
    n->val = b;
    n->next = NULL;
    return n;
}

/**
 * Insert coordinate struct inside the linked list with given head
 * @param head of coordinate list
 * @param to_insert coordinate node to insert
 * @return head
 */
coordinate_node* insert_coordinate(coordinate_node** head, coordinate_node* to_insert) {
    to_insert->next = *head;
    *head = to_insert;
    return *head;
}
