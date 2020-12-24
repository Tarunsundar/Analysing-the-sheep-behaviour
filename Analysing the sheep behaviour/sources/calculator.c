//
// Created by Tarunsundar on 16/12/2020.
//

#include "../headers/calculator.h"

/**
 * The great circle distance or the orthodromic distance is the shortest distance
 * between two points on a sphere
 * @param start coordinate
 * @param end coordinate
 * @return distance in m
 */
double distance(coordinate* first, coordinate* second){

    double lon1 = degToRad(first->lon);
    double lon2 = degToRad(second->lon);
    double lat1 = degToRad(first->lat);
    double lat2 = degToRad(second->lat);

    // Haversine formula (alt. vincenties formula)
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat / 2), 2)
               + cos(lat1) * cos(lat2)
                 * pow(sin(dlon / 2),2);

    double c = 2 * asin(sqrt(a));

    // Radius of earth in kilometers. Use 3956
    // for miles
    double r = 6371;

    // calculate the result (in m)
    return((c * r)*1000);
}

int times(coordinate* first, coordinate * second){
    int s1 = first->hours*60*60 + first->min*60 + first->sec;
    int s2 = second->hours*60*60 + second->min*60 + second->sec;

    // take a difference of the lesser number with the greater
    int diff = s1 > s2 ? s1 - s2 : s2 - s1;
    return diff;
}

