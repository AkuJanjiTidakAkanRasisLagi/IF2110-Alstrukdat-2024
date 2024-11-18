#include <stdio.h>
#include "listdin.h"

int main() {
    int n;
    scanf("%d", &n);

    ListDin li;
    CreateListDin(&li, n);

    int i, j;
    int ans = 0;
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        int pos = listLength(li);
        for (j = 0; j < listLength(li); j++) {
            if (ELMT(li, j) > x) {
                ans++;
                if (pos == listLength(li)) {
                    pos = j;
                }
            }
        }

        for (j = listLength(li) - 1; j >= pos; j--) {
            ELMT(li, j+1) = ELMT(li, j);
        }
        ELMT(li, pos) = x;
        NEFF(li)++;
    }

    printf("%d\n", ans);
}