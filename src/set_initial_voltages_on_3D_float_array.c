#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cppcc.h"

/* Array is width_and_height by width_and_height by length. */


void set_initial_voltages_on_3D_float_array(float *** voltage_array, unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height) {

    unsigned int w=0, h=0, l=0;
    for (l = 0; l < length; l++) {
        for (w = 0; w < width_and_height; w++) {
            for (h = 0; h < width_and_height; h++) {
                    voltage_array[l][w][h] = 0.5;
            }
        }
    }
}

