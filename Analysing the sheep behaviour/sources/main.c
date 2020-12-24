#include <stdio.h>
#include <string.h>
#include "../headers/parser.h"

int main() {

    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Cannot open file!\n");
        fclose(file);
    }

    int total_lines = 0;
    int valid_lines = 0;
    int ignored_lines = 0;
    int no_pos_change = 0;

    coordinate_node *head = NULL;
    movement_node *head_m = NULL;
    read_and_parse_movement_data(file, &head, &head_m, &total_lines, &valid_lines, &ignored_lines,
                                 &no_pos_change);

    printf("%s opened. Total lines read %d\n"
           "%d were valid and %d lines ignored/invalid lines\n"
           "%d lines stationary/no change in coordinate\n", FILENAME, total_lines, valid_lines, ignored_lines, no_pos_change);

    create_csv(CSV_FILENAME, head_m);
    return 0;
}