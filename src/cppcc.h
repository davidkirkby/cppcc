#ifndef PPCCC_H
#define PPCCC_H

/* Have double and float versions, which will allow one to choose memory or accuracy */

double ***allocate_3d_double_array(int dim1, int dim2, int dim3);
void free_3d_double_array(double ***array3D, int dim1, int dim2);

float  ***allocate_3d_float_array(int dim1, int dim2, int dim3);
void free_3d_float_array(float ***array3D, int dim1, int dim2);

void usage_cppcc(char *exefilename); 
void set_initial_double_voltages(double ***voltage_array_3D, unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height);


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#endif // PPCCC_H
