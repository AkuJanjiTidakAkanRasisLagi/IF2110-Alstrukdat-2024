#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
    int i = 0;
    int first = 1;
    int putar = 1;

    STARTWORD();
    while (!EndWord) {
        if (!first) printf(" ");
        else {
            first = 0;
        }

        if (putar) {
            for (i = currentWord.Length - 1; i >= 0; i--) {
                printf("%c", currentWord.TabWord[i]);
            }
        }

        else {
            for (i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
        }
        

        putar = !putar;
        ADVWORD();
    }
    printf("\n");
}