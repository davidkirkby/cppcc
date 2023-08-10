#ifndef PPCCC_H
#define PPCCC_H
#include <stdbool.h>

/* Have double and float versions, which will allow one to choose memory or accuracy */

double ***allocate_3d_double_array(int dim1, int dim2, int dim3);
void free_3d_double_array(double ***array3D, int dim1, int dim2);

float  ***allocate_3d_float_array(int dim1, int dim2, int dim3);
void free_3d_float_array(float ***array3D, int dim1, int dim2);

void usage_cppcc(char *exefilename); 

void set_voltages_for_capacitor_plates_float(float *** voltage_array, unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height);

void set_voltages_for_capacitor_plates_double(double *** voltage_array, unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height);



void check_inputs_are_reasonable(unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height);


bool is_positive_integer(const char *str); 

#define USE_FLOATS 1000

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#endif // PPCCC_H

