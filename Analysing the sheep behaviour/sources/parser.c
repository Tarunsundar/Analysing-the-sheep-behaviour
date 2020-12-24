//
// Created by Arsalan on 16/12/2020.
//

#include "../headers/parser.h"

/**
 * Open and read the collar file line by line, parsing the lines and storing data in linked lists
 * processing movements and coordinates
 * @param file file pointer to parse
 * @param head head of coordinate list
 * @param head_m head of movement list
 * @param total_lines
 * @param valid_lines
 * @param invalid_lines
 * @param same_coordinates
 */
void read_and_parse_movement_data(FILE *file, coordinate_node **head, movement_node **head_m, int *total_lines, int *valid_lines, int *invalid_lines,
                                  int *same_coordinates) {
    double previous_lat = 0;
    double previous_lon = 0;

    char buffer[LINE_LENGTH] = "";
    while (fgets(buffer, LINE_LENGTH, file)) {
        (*total_lines)++;

        if (buffer[0] == '\n' || buffer[0] == 'W' || buffer[0] == 'r' || buffer[0] == '\r' || buffer[0] == ' ') {
            (*invalid_lines)++;
        } else {
            double lat = 0;
            double lon = 0;
            int day = 0;
            int month = 0;
            int year = 0;
            int hours = 0;
            int min = 0;
            int secs = 0;
            char *token = strtok(buffer, ", ");
            parse_line(token, &lat, &lon, &day, &month, &year, &hours, &min, &secs);

            if ((previous_lat != lat) && (previous_lon != lon)) {
                previous_lat = lat;
                previous_lon = lon;

                coordinate *c = get_coordinate(lat, lon, day, month, year, hours,
                                               min, secs);

                // insert coordinate struct into linked list
                // all functions for linked list and the struct are already there in coordinates.c

                coordinate_node *n = get_coordinate_node(c);
                insert_coordinate(head, n);
                // this line was valid
                (*valid_lines)++;

            } else {
                (*same_coordinates)++;
            }
        }
    }
    fclose(file);
    compute_movements(*head, head_m);
}

/**
 * Parse tokenized string
 * @param token
 * @param lat
 * @param lon
 * @param day
 * @param month
 * @param year
 * @param hours
 * @param min
 * @param secs
 */
void parse_line(char *token, double *lat, double *lon, int *day, int *month, int *year, int *hours, int *mins,
                int *secs) {
    // read tokenized string part by part
    for (int i = 0; i < PARTS_OF_LINE; i++) {
        if (NULL != token) {
            if(i==0) sscanf(token, "%lf", lat);

            if(i==1) sscanf(token, "%lf", lon);

            if(i==2) sscanf(token, "%d/%d/%d", day, month, year);

            if(i==3) sscanf(token, "%d:%d:%d", hours, mins, secs);
        }
        token = strtok(NULL, ", ");
    }
}

/**
 * Create CSV file given the list head of movements (Snippet from StackOverflow)
 * @param filename
 * @param curr head of movement list
 */
void create_csv(char *filename, movement_node* curr){
    FILE *fp = fopen(filename,"w+");
    int count = 1;
    while (curr != NULL) {
        fprintf(fp, "Movement:%d, %02d/%02d/%04d, %02d:%02d:%02d, %lf, %lf, %lf, %lf, %lfm, %ds, %lfm/s, %s\n",
                count,
                curr->val->origin->date, curr->val->origin->month, curr->val->origin->year,
                curr->val->origin->hours, curr->val->origin->min, curr->val->origin->sec,
                curr->val->origin->lon, curr->val->origin->lat,
                curr->val->end->lon, curr->val->end->lat,
                curr->val->dist, curr->val->time, curr->val->speed,
                curr->val->category);
        curr = curr->next;
        count++;
    }
    fclose(fp);
    printf("--- data stored in %s",filename);
}