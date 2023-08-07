#include <stdio.h>
#include <stdlib.h>
#include "cppcc.h"
      
void usage_cppcc(char *exename) {
   printf("Cylindrical Parallel Plate Capacitance Capacitance Calculator\n");
   printf("Usage: %s [options] r1 t1 r2 t2 x L H Er MaxRAM\n",exename);
   printf("where r1 is the radius of the capacitor plate 1\n");
   printf("      t1 is the thickness of capacitor plate 1\n");
   printf("      r2 is the radius of the capacitor plate 2\n");
   printf("      t2 is the thickness of capacitor plate 2\n");
   printf("      x  is the spacing between the capacitor plates\n");
   printf("      L is the length of the cuboid\n");
   printf("      H is the height and depth of the cuboid\n");
   printf("      Er is the relative permittivity of the medium.\n");
   printf("      MaxRAM is the maximum RAM (GB) you wish program to use\n");
   printf("Options:\n");
   printf("        --float Use 4-byte floats rather than 8-bytes doubles to save memory\n");
   printf("            /----------------------------------------------------------------------/\n");
   printf("           /                                                                      /|\n");
   printf("          /                                                                      / |\n");
   printf("         /                                                                      /  |\n");
   printf("        /                                                                      /   |\n");
   printf("       /                                                                      /    |\n");
   printf("      /                                                                      H     |\n");
   printf("     /                                                                      /      |\n");
   printf("    /                                                                      /       |\n");
   printf("   /                                                                      /        |\n");
   printf("  /                                                                      /         |\n");
   printf(" /                                                                      /          |\n");
   printf("/                                                                      /           |\n");
   printf("------------------------------ L --------------------------------------|           |\n");
   printf("|                                                                      |           |\n");            
   printf("|                                                                      |           |\n");            
   printf("|                                                                      |           |\n");            
   printf("|                                                                      |           |\n");            
   printf("|              <--t1-->                                                |           |\n");            
   printf("|                                                                      |           |\n");            
   printf("|        ^     ********                                                |           |\n");            
   printf("|        |     ********                                                |           H\n");            
   printf("|        |     ********                                                |           |\n");            
   printf("|        r1    ********                      <-----t2----->            |           |\n");            
   printf("|        |     ********                                                |           |\n");            
   printf("|        |     ********                      **************  ^         |           |\n");            
   printf("|        |     ********                      **************  |         |           |\n");            
   printf("|        |     ********                      **************  r2        |           |\n");            
   printf("|        |     ********                      **************  |         |           |\n");            
   printf("|              ******** <------- x --------> **************  |         H           |\n");            
   printf("|              ********                      **************            |           |\n");            
   printf("|              ********                      **************            |           |\n");            
   printf("|              ********                      **************            |           |\n");            
   printf("|              ********                      **************            |          /\n");            
   printf("|              ********                      **************            |         /\n");            
   printf("|              ********                                                |        /\n");            
   printf("|              ********                                                |       H\n");            
   printf("|              ********                                                |      /\n");            
   printf("|                                                                      |     /\n");            
   printf("|                                                                      |    /\n");            
   printf("|                                                                      |   /\n");            
   printf("|                                                                      |  /\n");            
   printf("|                                                                      | /\n");            
   printf("|                                                                      |/\n");            
   printf("-----------------------------------------------------------------------\n");
}
