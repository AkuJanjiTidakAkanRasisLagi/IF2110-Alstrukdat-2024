#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix M, dp;
    int n, i, j;
    scanf("%d", &n);

    createMatrix(n, n, &M);
    readMatrix(&M, n, n);

    createMatrix(n, n, &dp);
    int mod = 1000000000+7;

    ELMT(dp, 0, 0) = !(ELMT(M, 0, 0));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ELMT(M, i, j)) continue;
            else {
                if (i-1 >= 0) ELMT(dp, i, j) += ELMT(dp, i-1, j);
                if (j-1 >= 0) ELMT(dp, i, j) += ELMT(dp, i, j-1);
                ELMT(dp, i, j) %= mod; 
            }
        }
    }

    printf("%d\n", ELMT(dp, n-1, n-1));
}