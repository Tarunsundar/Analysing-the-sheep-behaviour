//
// Created by Arsalan on 16/12/2020.
//

#ifndef MAIN_C_PARSER_H
#define MAIN_C_PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "movement.h"
#include "coordinate.h"

void parse_line(char *buffer, double *lat, double *lon, int *day, int *month, int *year, int *hours, int *mins,
                int *secs);

void read_and_parse_movement_data(FILE *file, coordinate_node **head, movement_node **head_m, int *total_lines, int *valid_lines, int *ignored_lines,
                                  int *no_pos_change);

void create_csv(char *filename, movement_node* head);

#endif //MAIN_C_PARSER_H
