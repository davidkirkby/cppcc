#include <stdio.h>
#include <stdlib.h>
#include "cppcc.h"


float ***allocate_3d_float_array(int dim1, int dim2, int dim3) {
    float ***array3D = (float ***)malloc(dim1 * sizeof(float **));
    if (array3D == NULL) {
        perror("Memory allocation for array3D failed");
        return NULL;
    }

    for (int i = 0; i < dim1; ++i) {
        array3D[i] = (float **)malloc(dim2 * sizeof(float *));
        if (array3D[i] == NULL) {
            perror("Memory allocation for array3D[i] failed");
            // Free previously allocated memory before returning
            for (int j = 0; j < i; ++j) {
                free(array3D[j]);
            }
            free(array3D);
            return NULL;
        }

        for (int j = 0; j < dim2; ++j) {
            array3D[i][j] = (float *)malloc(dim3 * sizeof(float));
            if (array3D[i][j] == NULL) {
                perror("Memory allocation for array3D[i][j] failed");
                // Free previously allocated memory before returning
                for (int k = 0; k < j; ++k) {
                    free(array3D[i][k]);
                }
                for (int k = 0; k < i; ++k) {
                    for (int l = 0; l < dim2; ++l) {
                        free(array3D[k][l]);
                    }
                    free(array3D[k]);
                }
                free(array3D);
                return NULL;
            }
        }
    }

    return array3D;
}


