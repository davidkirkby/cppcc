#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cppcc.h"

void check_inputs_are_reasonable(unsigned int r1, unsigned int t1, unsigned int r2, unsigned int t2, unsigned int x, unsigned int length, unsigned int width_and_height) {

   /* Check that the radius of the plates is not too big to fit in the cuboid */
   if ( 2 * r1 >= width_and_height ) {
      fprintf(stderr,"ERROR: The radius of the plate r1 (%u) is too big to fit in the cubeoid which is %u x %u\n", r1, width_and_height,width_and_height);
      exit(1);
   }
   if ( 2 * r2 >= width_and_height ) {
      fprintf(stderr,"ERROR: The radius of the plate r2 (%u) is too big to fit in the cubeoid which is %u x %u\n", r2, width_and_height,width_and_height);
      exit(1);
   }
   if ( t1 + t2 + x >= length) {
      fprintf(stderr,"ERROR: The sum of the thickness of the plates, plus the gap between them (%u+%u+%u=%u), is too big for the length (%u)\n", t1, t2, x, t1+t2+x,length);
      exit(1);
   }

   /* Check that the plates will fit, but the walls seem too close */ 
   
   if ( width_and_height < 6 * r1) {
      fprintf(stderr,"WARNING: The radius of the plate 1 (%u) is greater than 6x the size of the cubeoid (%u x %u)\n", r1, width_and_height,width_and_height);
      fprintf(stderr,"The cubeoid's width and height (%u x %u) is probably too small for the radius of plate 1 (%u)\n\n", width_and_height,width_and_height,r1);
   }
   if ( width_and_height < 6*r2 ) {
      fprintf(stderr,"WARNING: The radius of the plate 2 (%u) is greater than 6x the size of the cubeoid (%u x %u)\n", r2, width_and_height,width_and_height);
      fprintf(stderr,"The cubeoid's width and height (%u x %u) is probably too small for the radius of plate 2 (%u)\n\n", width_and_height,width_and_height,r2);
   }
   if ( length < 4*(t1+t2+x) ) {
      fprintf(stderr,"WARNING: The length of the cuboid (%u) is less than 4x the\n",length);
      fprintf(stderr,"sum of the total thickness of plates and gap (%u+%u+%u = %u)\n", t1,t2,x,t1+t2+x);
      fprintf(stderr,"The cubeoid's length (%u) is probably too small. Consider increasing it to at least %u.\n\n",length, 4*(t1+t2+x));
   }
} 


