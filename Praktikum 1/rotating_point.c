#include "point.h"
#include "complex.h"


COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX temp = C;
    p--;
    while (p--) {
        C = MultiplyCOMPLEX(C, temp);
    }
    return C;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    int i;
    COMPLEX temp = C;   

    if (n == 0) {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
        return;
    }

    for (i = 1; i <= n; i++) {
        float x = Absis(*P);
        float y = Ordinat(*P);

        Absis(*P) = x*Real(C) - y*Imag(C);
        Ordinat(*P) = x*Imag(C) + y*Real(C);

        C = MultiplyCOMPLEX(C, temp);

        if (Jarak0(*P) < 1) continue;
        else {
            printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
            return;
        }
    }
    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
}

