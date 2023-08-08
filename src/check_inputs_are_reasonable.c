#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cppcc.h"

void check_inputs_are_reasonable(unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height) {

   /* Check that the radius of the plates is not too big to fit in the cuboid */
   if ( 2 * r1 >= width_and_height ) {
      fprintf(stderr,"The radius of the plate r1 (%ud) is too big to fit in the cubeoid which is %ud x %ud\n", r1, width_and_height,width_and_height);
      exit(1);
   }
   if ( 2 * r2 >= width_and_height ) {
      fprintf(stderr,"The radius of the plate r2 (%ud) is too big to fit in the cubeoid which is %ud x %ud\n", r2, width_and_height,width_and_height);
      exit(1);
   }
   if ( t1 + t2 + x <= length) {
      fprintf(stderr,"The sum of the thickness of the plates (%ud and %ud), plus the gap between them (%ud), is too big for the length (%ud)\n", t1, t2, x, length);
      exit(1);
   }

   /* Check that the plates will fit, but the walls seem too close */ 
   
   if ( r1 > 4* width_and_height ) {
      fprintf(stderr,"The radius of the plate 1 (%ud) is greater  than 4x the size of the cubeoid (%ud x %ud)\n", r1, width_and_height,width_and_height);
      fprintf(stderr,"The cubeoid's width and height (%ud x %ud) is probably too small for the radius of plate 1 (%ud)\n", width_and_height,width_and_height,r1);
   }
   if ( r2 > 4* width_and_height ) {
      fprintf(stderr,"The radius of the plate 2 (%ud) is greater than 4x the size of the cubeoid (%ud x %ud)\n", r2, width_and_height,width_and_height);
      fprintf(stderr,"The cubeoid's width and height (%ud x %ud) is probably too small for the radius of plate 2 (%ud)\n", width_and_height,width_and_height,r2);
   }
   if ( t1 + t2 + x >= 4* length) {
      fprintf(stderr,"The sum of the thickness of the plates, plus the gap between them\n");
      fprintf(stderr,"(%ud+%ud+%ud=%ud), is greater than 4x the length (4*%ud = %ud)\n", t1, t2, x, t1+t2+x, length, 4*length);
      fprintf(stderr,"The cubeoid's length is probably too small\n");
   }
} 


