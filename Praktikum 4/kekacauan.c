#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix M;
    int n, i, j;
    scanf("%d", &n);

    createMatrix(n, n, &M);
    readMatrix(&M, n, n);

    int ans = 0;
    int mod = 1000000000+7;
    for (i = 0; i < n; i++) {
        int cnt = 0;
        for (j = 0; j < n; j++) {
            if (ELMT(M, i, j)) cnt++;
        }

        for (j = 0; j < n; j++) {
            if (ELMT(M, i, j)) ans += (cnt-1)*ELMT(M,i,j);
            ans %= mod;
        }
    }

    for (j = 0; j < n; j++) {
        int cnt = 0;
        for (i = 0; i < n; i++) {
            if (ELMT(M, i, j)) cnt++;
        }

        for (i = 0; i < n; i++) {
            if (ELMT(M, i, j)) ans += (cnt-1)*ELMT(M,i,j);\
            ans %= mod;
        }
    }

    printf("%d\n", ans);
}