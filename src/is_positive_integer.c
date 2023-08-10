#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
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

