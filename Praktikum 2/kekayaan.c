#include <stdio.h>
//#include "liststatik.c"
#include "liststatik.h"


int main() {
    int i;
    ListStatik arr;
    readList(&arr);

    int n = listLength(arr);
    boolean tambah = true;

    i = n-1;
    while (tambah) {
        if (i == -1) {
            insertFirst(&arr, 1);
            tambah = false;
        }
        else {
            ELMT(arr, i) += 1;

            if (ELMT(arr, i) == 10) {
                ELMT(arr, i) = 0;
            }
            else {
                tambah = false;
            }
        }
        i--;
    }

    for (i = 0; i < listLength(arr); i++) {
        printf("%d", ELMT(arr, i));
        if (i != listLength(arr)-1) {
            printf(" ");
        }
    }
    printf("\n");
}