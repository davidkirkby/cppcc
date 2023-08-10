#include <math.h>
#include <stdio.h>
void set_voltages_for_capacitor_plates_float(float ***float_array3D, unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height)
{
    int i, j, k;
    int overall_length = t1 + t2 + x;  // Of the strucure being simulated 
    int space_each_end = (length - overall_length)/2;
    int centre_width_and_height = width_and_height / 2;
    int counter_one = 0, counter_zero = 0, counter_half = 0;
    printf("space_each_end=%u centre_width_and_height=%u \n", space_each_end,centre_width_and_height);

   for (i = 0; i < length; i++) {
      for (j = 0; j < width_and_height; j++) {
         for (k = 0; k < width_and_height; k++) {
            if  (i > space_each_end  && i <= space_each_end+t1 && pow(j - centre_width_and_height, 2) + pow(k - centre_width_and_height, 2) < r1 * r1) {
               float_array3D[i][j][k] = 1;
               counter_one++;
                  //printf("r1=%d r1^2=%d 1 at %d %d %d j - centre_width_and_height=%d k-centre_width_and_height=%d\n",r1,r1*r1,i, j, k,j - centre_width_and_height, k - centre_width_and_height);
            } // end of if
            else if  (i > space_each_end + t1 + x  && i <= space_each_end+t1+x+t2 && pow(j - centre_width_and_height, 2) + pow(k - centre_width_and_height, 2) < r2 * r2) {
               float_array3D[i][j][k] = 0;
               counter_zero++;
                  //printf("r1=%d r1^2=%d 1 at %d %d %d j - centre_width_and_height=%d k-centre_width_and_height=%d\n",r1,r1*r1,i, j, k,j - centre_width_and_height, k - centre_width_and_height);
            } else {
               float_array3D[i][j][k] = 0.5;
               counter_half++;
                  //printf("r1=%d r1^2=%d 1 at %d %d %d j - centre_width_and_height=%d k-centre_width_and_height=%d\n",r1,r1*r1,i, j, k,j - centre_width_and_height, k - centre_width_and_height);
            }
         }  //end of k
      } // end of k
   } // end of i
   printf("1's = %d 0.5's = %d 0's=%d sum=%d\n",counter_one, counter_half,counter_zero,counter_one+counter_half+counter_zero); 
} // end of function 
