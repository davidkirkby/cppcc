#include "ppccc.h"


void free_3d_array(double ***array3D, int dim1, int dim2) {
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            free(array3D[i][j]);
        }
        free(array3D[i]);
    }
    free(array3D);
}

void free_3d_float_array(float ***array3D, int dim1, int dim2) {
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            free(array3D[i][j]);
        }
        free(array3D[i]);
    }
    free(array3D);
}

