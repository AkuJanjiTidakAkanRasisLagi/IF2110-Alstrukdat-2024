#include <stdio.h>
#include "listdin.h"
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    ListDin li;
    CreateListDin(&li, n);

    ListDin final;
    CreateListDin(&final, n+69);

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(li, i));
        NEFF(li)++;
    }

    int le, ri;
    scanf("%d", &le);
    scanf("%d", &ri);

    boolean inserted = 0;
    for (i = 0; i < listLength(li); i+=2) {
        int nextstart = ELMT(li, i);
        int nextstop = ELMT(li, i+1);

        //printf("nextstart: %d, nextstop: %d\n", nextstart, nextstop);
        if (nextstart > ri && !inserted) {
            insertLast(&final, le);
            insertLast(&final, ri);
            inserted = 1;
        }

        if (listLength(final) > 0 && ELMT(final, getLastIdx(final)) >= nextstart) {
            if (ELMT(final, getLastIdx(final)) < nextstop) {
                ELMT(final, getLastIdx(final)) = nextstop;
            }
            continue;
        }

        if (!inserted && nextstop >= le && ri >= nextstart) {
            inserted = 1;
            if (nextstart > le) {
                nextstart = le;
            }

            if (nextstop < ri) {
                nextstop = ri;
            }
        }

        insertLast(&final, nextstart);
        insertLast(&final, nextstop);
    }

    if (!inserted) {
        insertLast(&final, le);
        insertLast(&final, ri);
    }

    for (int i = 0; i < listLength(final); i++) {
        if (i != listLength(final) - 1) printf("%d ", ELMT(final, i));
        else printf("%d\n", ELMT(final, i));
    }
}