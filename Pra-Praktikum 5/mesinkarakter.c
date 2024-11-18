#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
FILE *pita;

void START() {
   EOP = false;
   pita = stdin;
   ADV();
}

void ADV() {
   fscanf(pita, "%c", &currentChar);
   if (currentChar == MARK) {
      EOP = true;
   }

   if (EOP) {
      fclose(pita);
   }
}