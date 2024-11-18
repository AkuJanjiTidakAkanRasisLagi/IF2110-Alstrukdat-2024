#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
    int i = 0;
    int num, cnt = 0;
    boolean yes = 1;
    boolean first;

    STARTWORD();
    while (!EndWord) {
        yes = 1, num = 0, cnt = 0, first = 1;

        for (i = 0; i <= currentWord.Length; i++) {
            if (i == currentWord.Length || currentWord.TabWord[i] == '@') {
                if (first) yes = 0;
                if (num >= 256) yes = 0;
                //printf("%d\n", num);

                first = 1;
                num = 0;
                cnt++;
                continue;
            }
            if (currentWord.TabWord[i] - '0' >= 0 && currentWord.TabWord[i] - '0' <= 9)  {
                if (first) first = 0;
                else if (num == 0) yes = 0;
                num *= 10;
                num += currentWord.TabWord[i] - '0';
            }
            else yes = 0;
        }
        if (cnt != 4) yes = 0;
        
        if (yes) {
            printf("4Lay");
        }
        else {
            printf("ewh");
        }
        ADVWORD();

        if (!EndWord) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
}