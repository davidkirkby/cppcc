#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <unistd.h>
#include <time.h>
#include "cppcc.h"


int main(int argc, char **argv) {

   unsigned int length, width_and_height, r1, r2, t1, t2, x;
   float ***float_array3D;
   double ***double_array3D;
   double epsilon_r, maxram, ram, elapsed_time;
   struct timespec start_time, end_time;
   int num_threads=1; // Default to single-threaded code 
 

   int option;
   int floats = 0; // Flag to indicate the --floats option


    // Define the long options
    static struct option long_options[] = {
       {"help", no_argument, 0, 'h'},
       {"floats", no_argument, 0, 'f'},
       {"threads", required_argument, 0, 't'},
       {0, 0, 0, 0}
    };

    while ((option = getopt_long(argc, argv, "hf", long_options, NULL)) != -1) {
       switch (option) {
          case 'h':
             // Handle the --help option
             usage_cppcc(argv[0]); 
             exit(1); 
          case 't':
             // Parse the number of threads
             num_threads = atoi(optarg);
             if (num_threads <= 0) {
                 fprintf(stderr, "Invalid number of threads\n");
                 exit(1);
             }
             break;
 
          case 'f':
             floats = 1;
                break;
          case '?':
             // Handle unknown or missing options
             exit(1);
          default:
                break;
        }
    }

 

    // Check if there are too many non-option arguments
    if (argc - optind > 9 ) {
        fprintf(stderr, "Error: Too many parameters. Expected: r1 t1 r1 t2 d L WxH Er MaxRAM\n");
        fprintf(stderr, "Use the --help or -h option for help\n");
        exit(EXIT_FAILURE);
    }
    if (argc - optind < 9) {
        fprintf(stderr, "Error: Too few parameters. Expected: r1 t1 r1 t2 d L WxH Er MaxRAM\n");
        fprintf(stderr, "Use the --help or -h option for help\n");
        exit(EXIT_FAILURE);
    }


   if (!is_positive_integer(argv[optind])) {
      printf("Error: Invalid input. Please provide a positive integer for r1.\n");
      exit(1);
   }
   r1 = atoi(argv[optind]);

   if (!is_positive_integer(argv[optind+1])) {
      printf("Error: Invalid input. Please provide a positive integer for t1.\n");
      exit(1);
   }
   t1 = atoi(argv[optind+1]);

   if (!is_positive_integer(argv[optind+2])) {
      printf("Error: Invalid input. Please provide a positive integer for r2.\n");
      exit(1);
   }
   r2 = atoi(argv[optind+2]);

   if (!is_positive_integer(argv[optind+3])) {
      printf("Error: Invalid input. Please provide a positive integer for t2.\n");
      exit(1);
   }
   t2 = atoi(argv[optind+3]);

   if (!is_positive_integer(argv[optind+4])) {
      printf("Error: Invalid input. Please provide a positive integer for x.\n");
      exit(1);
   }
   x = atoi(argv[optind+4]);

   if (!is_positive_integer(argv[optind+5])) {
      printf("Error: Invalid input. Please provide a positive integer for the length L.\n");
      exit(1);
   }
   length = atoi(argv[optind+5]);

   if (!is_positive_integer(argv[optind+6])) {
      printf("Error: Invalid input. Please provide a positive integer for the height H.\n");
      exit(1);
   }
   width_and_height = atoi(argv[optind+6]);  // Corrected variable name

   epsilon_r = atof(argv[optind+7]);
   if (epsilon_r < 1.0) {
      printf("Error: Er must be greater than or equal to 1.\n");
      return 1;
   }

   maxram = atof(argv[optind+8]);  

   /* 8 bytes for a double. The cuboid is L*H*H, so there needs to be at least 8*L*H*H bytes, or */
   /* Add on 0.02 GB for overhead */
   if (floats==TRUE)
      ram = sizeof(float) * (double) length * (double) width_and_height * (double) width_and_height / (1024 * 1024 * 1024) + 0.02;
   else 
      ram = sizeof(double) * (double) length * (double) width_and_height * (double) width_and_height / (1024 * 1024 * 1024) + 0.02;
   if (ram > maxram) {
      printf("The 3D array that holds the data in the cuboid takes up %.2lf GB\n", (double) 8*length*width_and_height*width_and_height/(1024*1024*1024));
      printf("Some more RAM will be needed too. You will need at least %.2lf GB\n", (double) ram);
      exit(1);
   }
   
   printf("r1=%d t1=%d r2=%d t2=%d x=%d L=%d H=%d Er=%lf MaxRAM=%lf ram=%lf\n",r1, t1, r2, t2, x, length, width_and_height, epsilon_r, maxram,ram);

   check_inputs_are_reasonable(r1, t1, r2, t2, x, length, width_and_height);
    // Record the starting time of setting the voltages to a specific value. 
    // Memory allocation is only done once, so don't bother timing that. 
    if (floats == TRUE) {
       clock_gettime(CLOCK_MONOTONIC, &start_time);
       float_array3D = allocate_3d_float_array(length, width_and_height, width_and_height);
       clock_gettime(CLOCK_MONOTONIC, &end_time);
       // Calculate the elapsed time in seconds
       elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
       printf("Elapsed time allocating  %f GB RAM was %f seconds\n", ram, elapsed_time);

       clock_gettime(CLOCK_MONOTONIC, &start_time);
       set_initial_voltages_on_3D_float_array(float_array3D, r1, t1, r2, t2, x, length, width_and_height);
       clock_gettime(CLOCK_MONOTONIC, &end_time);
       elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
       printf("Elapsed time setting volages with  %f GB RAM  with %d threads was %f seconds\n", ram, num_threads, elapsed_time);

   } else {
      double_array3D = allocate_3d_double_array(length, width_and_height, width_and_height);

      set_initial_voltages_on_3D_double_array(double_array3D, r1, t1, r2, t2, x, length, width_and_height);
      set_voltages_for_capacitor_plates_double(double_array3D, r1, t1, r2, t2, x, length, width_and_height);
   }


}

