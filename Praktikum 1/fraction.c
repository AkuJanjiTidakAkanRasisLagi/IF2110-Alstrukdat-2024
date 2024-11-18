#include "fraction.h"
#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D) {
    return D != 0;
}

void CreateFRACTION(FRACTION *F, int N, int R) {
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F) {
    int a, b;
    scanf("%d %d", &a, &b);

    while (!IsFRACTIONValid(a, b)) {   
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &a, &b);
    } 
    Numerator(*F) = a;
    Denominator(*F) = b;
}

void WriteFRACTION(FRACTION F) {
    int a = Numerator(F);
    int b = Denominator(F);
    
    if (a == 0) {
        printf("0/1");
        return;
    }

    boolean neg = ((a < 0)^(b < 0));
    if (neg) printf("-");

    a = abs(a);
    b = abs(b);
    int div = gcd(a, b);

    printf("%d/%d", a/div, b/div);
}


FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    int a = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
    int b = Denominator(F1) * Denominator(F2);
    int div = gcd(a, b);

    FRACTION RES;
    CreateFRACTION(&RES, a/div, b/div);
    return RES;
}


FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    int a = Numerator(F1) * Denominator(F2) - Numerator(F2) * Denominator(F1);
    int b = Denominator(F1) * Denominator(F2);
    int div = gcd(a, b);

    FRACTION RES;
    CreateFRACTION(&RES, a/div, b/div);
    return RES;
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
    int a = Numerator(F1) * Numerator(F2);
    int b = Denominator(F1) * Denominator(F2);
    int div = gcd(a, b);

    FRACTION RES;
    CreateFRACTION(&RES, a/div, b/div);
    return RES;
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F3;
    CreateFRACTION(&F3, Denominator(F2), Numerator(F2));

    return MultiplyFRACTION(F1, F3);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
    int a = Numerator(F1)*n;
    int b = Denominator(F1);

    int div = gcd(a, b);

    FRACTION RES;
    CreateFRACTION(&RES, a/div, b/div);
    return RES;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F) {
    int a = Numerator(F);
    int b = Denominator(F);

    int div = gcd(a, b);

    FRACTION RES;
    CreateFRACTION(&RES, a/div, b/div);
    
    return RES;
}

float ToDecimal(FRACTION F) {
    return (float)Numerator(F) / (float)Denominator(F);
}