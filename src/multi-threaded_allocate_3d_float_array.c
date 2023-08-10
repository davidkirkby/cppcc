#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass arguments to the thread function
struct ThreadArgs_float {
    float ***array;
    int start_index;
    int end_index;
    int dim2;
    int dim3;
};

// Thread function to allocate memory for a range of array elements
void *allocate_memory_thread_float(void *args) {
    struct ThreadArgs_float *thread_args = (struct ThreadArgs_float *)args;

    for (int i = thread_args->start_index; i < thread_args->end_index; ++i) {
        thread_args->array[i] = (float **)malloc(thread_args->dim2 * sizeof(float *));
        for (int j = 0; j < thread_args->dim2; ++j) {
            thread_args->array[i][j] = (float *)malloc(thread_args->dim3 * sizeof(float));
        }
    }

    pthread_exit(NULL);
}

// Function to allocate a 3D array using multiple threads
float ***multi_threaded_allocate_3d_float_array(int dim1, int dim2, int dim3, int num_threads) {
    float ***array = (float ***)malloc(dim1 * sizeof(float **));

    // Create an array of thread structures and thread IDs
    pthread_t threads[num_threads];
    struct ThreadArgs_float thread_args[num_threads];

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

        pthread_create(&threads[t], NULL, allocate_memory_thread_float, &thread_args[t]);

        start_index = thread_args[t].end_index;
    }

    // Wait for all threads to finish
    for (int t = 0; t < num_threads; ++t) {
        pthread_join(threads[t], NULL);
    }

    return array;
}


