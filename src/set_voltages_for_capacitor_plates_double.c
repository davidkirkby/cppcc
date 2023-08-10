#include <math.h>
#include <stdio.h>
void set_voltages_for_capacitor_plates_double(double ***double_array3D, unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height)
{
    unsigned int i, j, k;
    unsigned int overall_length = t1 + t2 + x;
    unsigned int space_each_end = length - overall_length / 2;
    unsigned int centre_width_and_height = width_and_height / 2;
    unsigned int counter_one = 0, counter_zero = 0, counter_half = 0;

    for (i = 0; i < length; i++) {
        for (j = 0; j < width_and_height; j++) {
            for (k = 0; k < width_and_height; k++) {
                // Check for capacitor plate 1, which is centered at centre_width_and_height
                if ((i > space_each_end) && (i <= space_each_end + t1) && (pow(j - centre_width_and_height, 2) + pow(k - centre_width_and_height, 2) < t1 * t1)) {
                    double_array3D[i][j][k] = 1;
                    counter_one++;
                } else if ((i > space_each_end + t1 + x) && (i <= space_each_end + t1 + x + t2) && (pow(j - centre_width_and_height, 2) + pow(j - centre_width_and_height, 2) < t2 * t2)) {
                    double_array3D[i][j][k] = 0;
                    counter_zero++;
                } else {
                    double_array3D[i][j][k] = 0.5;
                    counter_half++;
                }
            }
        }
    }
}
