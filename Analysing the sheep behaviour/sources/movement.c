//
// Created by Arsalan on 16/12/2020.
//

#include "../headers/movement.h"
#include "../headers/calculator.h"

/**
 * Insert movement struct inside the linked list with given head
 * @param head of movement list
 * @param to_insert node to insert
 * @return head
 */
movement_node* insert_movement(movement_node** head, movement_node* to_insert) {
    to_insert->next = *head;
    *head = to_insert;
    return *head;
}

/**
 * Create a movement struct
 * @param origin
 * @param end
 * @param distance
 * @param time_taken
 * @param speed
 * @param category
 * @return created movement struct
 */
movement* get_movement(coordinate* origin, coordinate* end, double dist, int time, double speed, char *category) {
    movement* ret = malloc(sizeof(movement));
    ret->origin = origin;
    ret->end = end;
    ret->dist = dist;
    ret->time = time;
    ret->speed = speed;
    strcpy(ret->category, category);

    return ret;
}

/**
 * Get movement category based on speed, could be changed in the future if required
 * @param speed
 * @param move category string
 */
char* get_category(double speed) {
    if (0 <= speed < 0.02) {
        return "Stationary";
    }
    else if(0.02 <= speed < 0.33) {
        return "Foraging";
    }
    else if(0.33 <= speed < 12.00) {
        return "Moving";
    }
    else {
        return "Implausible";
    }
}

/**
 * Read the coordinate list and compute movement data from the list
 * @param curr coordinate list head
 * @param movement_list movement list head
 */
void compute_movements(coordinate_node *curr, movement_node **head) {
    while (curr->next!=NULL) {
        double position_difference = distance(curr->val, curr->next->val);
        int time_difference = times(curr->val, curr->next->val);
        double speed = time_difference == 0 ? 0 : position_difference / (double) time_difference;

        char category[CATEGORY_LENGTH] = "";
        strcpy(category, get_category(speed));


        movement_node *to_insert = malloc(sizeof(movement_node));
        to_insert->val = get_movement(curr->val, curr->next->val, position_difference, time_difference, speed, category);;
        to_insert->next = NULL;

        insert_movement(head, to_insert);
        curr = curr->next;
    }
}