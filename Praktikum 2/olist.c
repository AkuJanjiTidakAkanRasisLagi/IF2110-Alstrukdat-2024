#include <stdio.h>
//#include "liststatik.c"
#include "liststatik.h"


int main() {
    int i;
    ListStatik arr;
    readList(&arr);

    ListStatik freq;
    CreateListStatik(&freq);

    ListStatik uniq;
    CreateListStatik(&uniq);

    int n = listLength(arr);
    for (i = 0; i < n; i++) {
        if (indexOf(uniq, ELMT(arr, i)) == IDX_UNDEF) {
            insertLast(&uniq, ELMT(arr, i));
        }
    }

    for (i = 0; i < n; i++) {
        int id = indexOf(uniq, ELMT(arr, i));
        if (ELMT(freq, id) == MARK) {
            ELMT(freq, id) = 1;
        }
        else {
            ELMT(freq, id) += 1;
        }
    }

    printList(uniq);
    printf("\n");
    for (i = 0; i < listLength(uniq); i++) {
        printf("%d %d\n", ELMT(uniq, i), ELMT(freq, i));
    }
}