#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass arguments to the thread function
struct ThreadArgs_double {
    double ***array;
    int start_index;
    int end_index;
    int dim2;
    int dim3;
};


void *allocate_memory_thread_double(void *args) {
    struct ThreadArgs_double *thread_args = (struct ThreadArgs_double *)args;

    for (int i = thread_args->start_index; i < thread_args->end_index; ++i) {
        thread_args->array[i] = (double **)malloc(thread_args->dim2 * sizeof(double *));
        if (thread_args->array[i] == NULL) {
            // Handle memory allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            // Free previously allocated memory
            for (int j = thread_args->start_index; j < i; ++j) {
                for (int k = 0; k < thread_args->dim2; ++k) {
                    free(thread_args->array[j][k]);
                }
                free(thread_args->array[j]);
            }
            pthread_exit(NULL);
        }
        for (int j = 0; j < thread_args->dim2; ++j) {
            thread_args->array[i][j] = (double *)malloc(thread_args->dim3 * sizeof(double));
            if (thread_args->array[i][j] == NULL) {
                // Handle memory allocation failure
                fprintf(stderr, "Memory allocation failed\n");
                // Free previously allocated memory
                for (int k = thread_args->start_index; k < i; ++k) {
                    for (int l = 0; l < thread_args->dim2; ++l) {
                        free(thread_args->array[k][l]);
                    }
                    free(thread_args->array[k]);
                }
                pthread_exit(NULL);
            }
        }
    }

    pthread_exit(NULL);
}

// Function to allocate a 3D array using multiple threads
double ***multi_threaded_allocate_3d_double_array(int dim1, int dim2, int dim3, int num_threads) {
    double ***array = (double ***)malloc(dim1 * sizeof(double **));

    // Create an array of thread structures and thread IDs
    pthread_t threads[num_threads];
    struct ThreadArgs_double thread_args[num_threads];

    // Divide the work among threads
    int blocks_per_thread = dim1 / num_threads;
    int remainder = dim1 % num_threads;
    int start_index = 0;

    for (int t = 0; t < num_threads; ++t) {
        thread_args[t].array = array;
        thread_args[t].start_index = start_index;
        thread_args[t].end_index = start_index + blocks_per_thread + (t < remainder ? 1 : 0);
        thread_args[t].dim2 = dim2;
        thread_args[t].dim3 = dim3;

        pthread_create(&threads[t], NULL, allocate_memory_thread_double, &thread_args[t]);

        start_index = thread_args[t].end_index;
    }

    // Wait for all threads to finish
    for (int t = 0; t < num_threads; ++t) {
        pthread_join(threads[t], NULL);
    }

    return array;
}


