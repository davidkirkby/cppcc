#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "cppcc.h"

bool is_positive_integer(const char *str) {
   if (*str == '\0') {
      return FALSE;  // Empty string
   }

   while (*str != '\0') {
      if (!isdigit(*str)) {
         return FALSE;  // Contains non-digit characters
      }
      str++;
   }

   return TRUE;
}

int main(int argc, char **argv) {

   unsigned int length, width_and_height, r1, r2, t1, t2, x;
   float ***float_array3D;
   double ***double_array3D;
   double epsilon_r, maxram, ram;
   

   if (argc != 10) {
     usage_cppcc(argv[0]);
     exit(1);
   } 

   if (!is_positive_integer(argv[1])) {
      printf("Error: Invalid input. Please provide a positive integer for r1.\n");
      exit(1);
   }
   r1 = atoi(argv[1]);

   if (!is_positive_integer(argv[2])) {
      printf("Error: Invalid input. Please provide a positive integer for t1.\n");
      exit(1);
   }
   t1 = atoi(argv[2]);

   if (!is_positive_integer(argv[3])) {
      printf("Error: Invalid input. Please provide a positive integer for r2.\n");
      exit(1);
   }
   r2 = atoi(argv[3]);

   if (!is_positive_integer(argv[4])) {
      printf("Error: Invalid input. Please provide a positive integer for t2.\n");
      exit(1);
   }
   t2 = atoi(argv[4]);

   if (!is_positive_integer(argv[5])) {
      printf("Error: Invalid input. Please provide a positive integer for x.\n");
      exit(1);
   }
   x = atoi(argv[5]);

   if (!is_positive_integer(argv[6])) {
      printf("Error: Invalid input. Please provide a positive integer for the length L.\n");
      exit(1);
   }
   length = atoi(argv[6]);

   if (!is_positive_integer(argv[7])) {
      printf("Error: Invalid input. Please provide a positive integer for the height H.\n");
      exit(1);
   }
   width_and_height = atoi(argv[7]);  // Corrected variable name

   epsilon_r = atof(argv[8]);
   if (epsilon_r < 1.0) {
      printf("Error: Er must be greater than or equal to 1.\n");
      return 1;
   }

   maxram = atof(argv[9]);  

   /* 8 bytes for a double. The cuboid is L*H*H, so there needs to be at least 8*L*H*H bytes, or */
   /* Add on 0.02 GB for overhead */
   ram = sizeof(double) * (double) length * (double) width_and_height * (double) width_and_height / (1024 * 1024 * 1024) + 0.02;
   if (ram > maxram) {
      printf("The 3D array that holds the data in the cuboid takes up %.2lf GB\n", (double) 8*length*width_and_height*width_and_height/(1024*1024*1024));
      printf("Some more RAM will be needed too. You will need at least %.2lf GB\n", (double) ram);
      exit(1);
   }
   
   printf("r1=%d t1=%d r2=%d t2=%d x=%d L=%d H=%d Er=%lf MaxRAM=%lf ram=%lf\n",r1, t1, r2, t2, x, length, width_and_height, epsilon_r, maxram,ram);

   double_array3D = allocate_3d_double_array(length, width_and_height, width_and_height);
   float_array3D = allocate_3d_float_array(length, width_and_height, width_and_height);
   check_inputs_are_reasonable(r1, t1, r2, t2, x, length, width_and_height);
   //set_initial_voltages_on_3D_float_array(array3D, r1, t1, r2, t2, x, length, width_and_height);
}

