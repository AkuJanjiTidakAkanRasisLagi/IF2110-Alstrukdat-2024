#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix M, piring;
    int n, i, j, ans = 0;
    scanf("%d", &n);

    createMatrix(n, n, &M);
    readMatrix(&M, n, n);

    createMatrix(2, 2, &piring);
    readMatrix(&piring, 2, 2);

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            int bef = ans;
            if (ELMT(M, i, j) > ELMT(piring, 0, 0) && ELMT(M, i, j+1) > ELMT(piring, 0, 1) && ELMT(M, i+1, j+1) > ELMT(piring, 1, 1) && ELMT(M, i+1, j) > ELMT(piring, 1, 0)) ans++;
            else if (ELMT(M, i, j) > ELMT(piring, 0, 01) && ELMT(M, i, j+1) > ELMT(piring, 1, 1) && ELMT(M, i+1, j+1) > ELMT(piring, 1, 0) && ELMT(M, i+1, j) > ELMT(piring, 0, 0)) ans++;
            else if (ELMT(M, i, j) > ELMT(piring, 1, 1) && ELMT(M, i, j+1) > ELMT(piring, 1, 0) && ELMT(M, i+1, j+1) > ELMT(piring, 0, 0) && ELMT(M, i+1, j) > ELMT(piring, 0, 1)) ans++;
            else if (ELMT(M, i, j) > ELMT(piring, 1, 0) && ELMT(M, i, j+1) > ELMT(piring, 0, 0) && ELMT(M, i+1, j+1) > ELMT(piring, 0, 1) && ELMT(M, i+1, j) > ELMT(piring, 1, 1)) ans++;
        }
    }

    printf("%d\n", ans);
}