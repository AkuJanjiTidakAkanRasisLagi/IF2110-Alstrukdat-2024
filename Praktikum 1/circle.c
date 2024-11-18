/* File: circle.h */
/* Tanggal: 21 September 2024 */
/* *** Definisi ADT CIRCLE *** */

#include <stdio.h>
#include "point.h"
#include "boolean.h"
#include "circle.h"
#include <math.h>
#include <stdlib.h>
#define pi 3.14
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCIRCLEValid(float X, float Y, float R) {
    return (R > 0);
}
/* Mengirim TRUE jika X, Y, R dapat membentuk Lingkaran C yang valid */

/* *** Konstruktor: Membentuk Lingkaran C dari titik pusat dan radius *** */
void CreateCIRCLE(CIRCLE *C, float X, float Y, float R) {
    /* Membentuk sebuah POINT dari komponen-komponennya */
    CreatePoint(&Center(*C), X, Y);
    Radius(*C)=R;
}
/* Membentuk sebuah CIRCLE dari komponen-komponen yang valid */
/* Prekondisi : X, Y, R, valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadCIRCLE(CIRCLE *C) {
    float x, y, r;
    scanf("%f %f %f", &x, &y, &r);
    while (!IsCIRCLEValid(x, y, r)) {
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f", &x, &y, &r);
    }
    CreateCIRCLE(C, x, y, r);
} 
/**
 * I.S. : C tidak terdefinisi
 * F.S. : C terdefinisi dan merupakan CIRCLE yang valid
 * Proses : Mengulangi membaca komponen X, Y, R sehingga membentuk C
 *  - Pembacaan dilakukan dengan mengetikkan komponen X, Y, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika CIRCLE tidak valid, maka berikan pesan: "CIRCLE tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat CIRCLE yang valid.
 */

void WriteCIRCLE(CIRCLE C) {
    POINT P = Center(C);
    float x = Absis(P);
    float y = Ordinat(P);
    float r = Radius(C);
    printf("P(%.2f,%.2f) r=%.2f", x, y, r);
}
/**
 * I.S. : C sembarang
 * F.S. : Nilai C ditulis dengan format "P(X,Y) r=R", ex: P(1,1) r=5
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI GEOMETRI TERHADAP TYPE                           */
/* ***************************************************************** */
float Circumference(CIRCLE C) {
    float r = Radius(C);
    return 2 * pi * r;
}
/* Menghitung keliling lingkaran: K = 2 * π * r, π = 3.14 */

float Area(CIRCLE C) {
    float r = Radius(C);
    return  pi * r * r;
}
/* Menghitung luas lingkaran: A = π * r^2, π = 3.14 */

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
    float r = Radius(C);
    POINT c = Center(C);
    return Panjang (c, P) < r;
}
/* Mengirim true jika titik P berada di dalam lingkaran C */

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
    float r = Radius(C);
    POINT c = Center(C);
    return (Panjang (c, P) - r) <= 1e-6;
}
/* Mengirim true jika titik P berada di tepi lingkaran C */
/* HINT: Gunakan toleransi kecil untuk komparasi float */

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
    float jarak = abs(Panjang(Center(C1), Center(C2)));
    float jari1 = Radius(C1);
    float jari2 = Radius(C2);
    float diff_rad = fabs(jari1 - jari2);
    return jarak < diff_rad;
}


// /* Mengirim true jika C1 di dalam C2 atau C2 di dalam C1 */
// /* NOTE: Tidak berpotongan/ bersinggungan */

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
    float jarak = abs(Panjang(Center(C1), Center(C2)));
    float jari1 = Radius(C1);
    float jari2 = Radius(C2);
    float sum_rad = fabs(jari1 + jari2);
    float diff_rad = fabs(jari1 - jari2);
    return (fabs(jarak - (sum_rad)) <= 1e-6) || (fabs(jarak - (diff_rad)) <= 1e-6);
}
/* Mengirim true jika C1 bersinggungan di 1 titik dengan C2 */
/**
 * HINT: Terdapat 2 Kemungkinan:
 *  1. Bersinggungan dalam
 *  2. Bersinggungan luar
 */

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
    float jarak = abs(Panjang(Center(C1), Center(C2)));
    float jari1 = Radius(C1);
    float jari2 = Radius(C2);
    float sum_rad = fabs(jari1 + jari2);
    float diff_rad = fabs(jari1 - jari2);
    return (jarak > diff_rad) && (jarak < sum_rad);
}
/* Mengirim true jika C1 berpotongan di 2 titik dengan C2 */

