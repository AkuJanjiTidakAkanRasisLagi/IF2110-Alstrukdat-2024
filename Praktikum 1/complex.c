#include <stdio.h>
#include "complex.h"

boolean IsCOMPLEXValid(float Re, float Im) {
  return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
  Real(*C) = Re;
  Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C) {
  scanf("%f %f", &Real(*C), &Imag(*C));
}

void TulisCOMPLEX(COMPLEX C) {
  if (Imag(C) >= 0)
    printf("%.2f+%.2fi\n", Real(C), Imag(C));
  else{
    printf("%.2f-%.2fi\n", Real(C), -1*Imag(C));
  }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
  COMPLEX Res;
  Real(Res) = Real(C1) + Real(C2);
  Imag(Res) = Imag(C1) + Imag(C2);
  return Res;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
  COMPLEX Res;
  Real(Res) = Real(C1) - Real(C2);
  Imag(Res) = Imag(C1) - Imag(C2);
  return Res;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
  /* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
  COMPLEX Res;
  Real(Res) = Real(C1) * Real(C2) - Imag(C1) * Imag(C2);
  Imag(Res) = Real(C1) * Imag(C2) + Imag(C1) * Real(C2);
  return Res;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
  /* Mengirim hasil pembagian C1 / C2 */
  /* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
  /* Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i*/

  float Denom = Real(C2) * Real(C2) + Imag(C2) * Imag(C2);
  if (Denom == 0) {
    COMPLEX Res;
    Real(Res) = 0;
    Imag(Res) = 0;
    return Res;
  }
  else {
    COMPLEX Res = MultiplyCOMPLEX(C1, ConjugateCOMPLEX(C2));
    Real(Res) /= Denom;
    Imag(Res) /= Denom;

    return Res;
  }
}

float AbsCOMPLEX(COMPLEX C) {
  return sqrt(Real(C) * Real(C) + Imag(C) * Imag(C));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
  COMPLEX Res;
  Real(Res) = Real(C);
  Imag(Res) = -Imag(C);
  return Res;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
  return Real(C1) == Real(C2) && Imag(C1) == Imag(C2);
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
  return !CEQ(C1, C2);
}