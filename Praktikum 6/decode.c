#include <stdio.h>
#include "boolean.h"
#include "stack.h"

char ans[1000069];
char temp[1000069];
int szans;
int sztemp;

int main()
{
    int N, i, j, k;
    char ch;
    Stack st;
    CreateEmpty(&st);

    scanf("%d\n", &N);

    // Start code here

    int cnt = 0;
    int now = 0;
    for (i = 0; i < N; i++) {
        scanf(" %c", &ch);
        
        ans[szans++] = ch;
    }
    
    //printf("test");

    while (true) {
        for (i = 0; i < szans; i++) {
            temp[i] = ans[i];
        }
        sztemp = szans;

        boolean done = false;

        int bef = -1;
        for (i = 0; i < sztemp; i++) {
            if (temp[i] == ']' && !done) {
                int rep = 0;
                rep += temp[bef-1] - '0';
                int l = bef-1;
                if (bef >= 2 && temp[bef-2] - '0' >= 0 && temp[bef-2] - '0' <= 9) {
                    rep += (temp[bef-2] - '0') * 10;
                    l--;
                }
                if (bef >= 3 && temp[bef-3] - '0' >= 0 && temp[bef-3] - '0' <= 9 && rep + (temp[bef-3] - '0') * 100 <= 150) {
                    rep += (temp[bef-3] - '0') * 100;
                    l--;
                }
                
                szans = 0;
                for (j = 0; j < l; j++) {
                    ans[szans++] = temp[j];
                }
                for (j = 0; j < rep; j++) {
                    for (k = bef + 1; k <= i-1; k++) {
                        ans[szans++] = temp[k];
                    }
                }   
                for (j = i+1; j < sztemp; j++) {
                    ans[szans++] = temp[j];
                }

                done = true;
            }
            else if (temp[i] == '[') bef = i;
        }

        if (!done) break;
    }

    for (int i = 0; i < szans; i++) {
        printf("%c", ans[i]);
    }
    printf("\n");

    return 0;
}