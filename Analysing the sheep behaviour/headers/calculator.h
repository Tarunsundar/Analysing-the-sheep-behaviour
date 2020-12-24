//
// Created by Arsalan on 16/12/2020.
//

#ifndef MAIN_C_CALCULATOR_H
#define MAIN_C_CALCULATOR_H


#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)

#define M_PI 3.14159265358979323846

#include "coordinate.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


double distance(coordinate* first, coordinate* second);
int times(coordinate* first, coordinate* second);

#endif //MAIN_C_CALCULATOR_H
