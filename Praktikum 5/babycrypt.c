#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
    int i = 0;
    int first = 1;
    int putar = 1;

    int shift;
    scanf("%d", &shift);
    shift %= 26;
    shift = 26 - shift;

    STARTWORD();
    while (!EndWord) {
        if (!first) printf(" ");
        else {
            first = 0;
        }

        for (int i = 0; i < currentWord.Length; i++) {
            char c = currentWord.TabWord[i];

            if (c - 'a' >= 0 && c - 'a' <= 25) {
                c = (c - 'a' + shift) % 26;
                c += 'a';
            }
            else if (c - 'A' >= 0 && c - 'A' <= 25){
                c = (c - 'A' + shift) % 26;
                c += 'A';
            }
            printf("%c", c);
        }

        ADVWORD();
    }
    printf("\n");
}