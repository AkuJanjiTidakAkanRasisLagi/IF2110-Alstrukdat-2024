#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin li, pref, suff;
    int n, i;
    scanf("%d", &n);

    CreateListDin(&li, n);
    CreateListDin(&pref, n);
    CreateListDin(&suff, n);

    for (i = 0; i < n; i++) {
        scanf("%d", &ELMT(li, i));
    }

    ELMT(pref, 0) = ELMT(li, 0);
    ELMT(suff, n-1) = ELMT(li, n-1);
    NEFF(pref)++;
    NEFF(suff)++;
    
    for (i = 1; i < n; i++) {
        //ELMT(pref, i) = max(ELMT(li, i), ELMT(pref, i-1));
        if (ELMT(li, i) > ELMT(pref, i-1)) {
            ELMT(pref, i) = ELMT(li, i);
        }
        else {
            ELMT(pref, i) = ELMT(pref, i-1);
        }

        if (ELMT(li, n-i-1) < ELMT(suff, n-i)) {
            ELMT(suff, n-i-1) = ELMT(li, n-i-1);
        }
        else {
            ELMT(suff, n-i-1) = ELMT(suff, n-i);
        }
        
        NEFF(pref)++;
        NEFF(suff)++;

        //ELMT(suff, n-i-1) = max(ELMT(li, i), ELMT(suff, n-i));
    }
    
    int ans = 0;
    for (i = 0; i < n; i++) {
        int left = -1;
        if (i > 0) left = ELMT(pref, i-1);

        int right = 696969696;
        if (i < n-1) right = ELMT(suff, i+1);

        if (right > ELMT(li, i) && left < ELMT(li, i)) {
            ans++;
        }
    }

    printf("%d\n", ans);
}