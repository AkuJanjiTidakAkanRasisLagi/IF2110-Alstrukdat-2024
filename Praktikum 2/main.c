#include <stdio.h>
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
        if (ELMT(freq, ELMT(arr, i)) == MARK) {
            ELMT(freq, ELMT(arr, i)) = 1;
            insertLast(&uniq, ELMT(arr, i));
        }
        else {
            ELMT(freq, ELMT(arr, i)) += 1;
        }
    }

    int mx = 0;
    for (i = 1; i < listLength(uniq); i++) {
        if (ELMT(freq, ELMT(uniq, i)) > ELMT(freq, ELMT(uniq, mx))) {
            mx = i;
        }
    }

    int mxx = -1;
    for ( i = 0; i < listLength(uniq); i++) {
        if (ELMT(freq, ELMT(uniq, i)) == ELMT(freq, ELMT(uniq, mx))) continue;

        if (mxx == -1) {
            mxx = i;
            continue;
        }
        
        if (ELMT(freq, ELMT(uniq, i)) > ELMT(freq, ELMT(uniq, mxx))) {
            mxx = i;
        }
        else if (ELMT(freq, ELMT(uniq, i)) == ELMT(freq, ELMT(uniq, mxx))) {
            if (ELMT(uniq, i) < ELMT(uniq, mxx)) {
                mxx = i;
            }
        } 
    }

    if (mxx == -1) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    else {
        printf("%d\n", ELMT(uniq, mxx));
    }
}