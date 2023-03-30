/* NIM = 13521084*/
/* Nama = Austin Gabriel Pardosi*/
/* Tanggal = 8 September 2022*/
/* Topik praktikum = ADT Sederhana*/
/* Implementasi ABSTRACT DATA TYPE GARIS */

#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "garis.h"
#include <math.h>

void CreateGaris (GARIS * L, POINT P1, POINT P2){
    PAwal (*L) = P1;
    PAkhir (*L) = P2;
}

void BacaGARIS (GARIS * L){
    POINT P1, P2;
    while (true) {
        BacaPOINT (&P1);
        BacaPOINT (&P2);
        if (NEQ (P1, P2)) {
            break;
        } else {
            printf("Garis tidak valid\n");
        }
    }
    CreateGaris(L, P1, P2);
}

void TulisGARIS (GARIS L){
    printf("(");
    TulisPOINT (PAwal(L));
    printf(",");
    TulisPOINT (PAkhir(L));
    printf(")");
}


float PanjangGARIS (GARIS L){
    return sqrt(pow(Absis(PAkhir(L))-Absis(PAwal(L)),2) + pow(Ordinat(PAkhir(L))-Ordinat(PAwal(L)),2));
}

float Gradien (GARIS L){
    return ((Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L))));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY){
    Absis(PAwal(*L)) += deltaX;
    Absis(PAkhir(*L)) += deltaX;
    Ordinat(PAwal(*L)) += deltaY;
    Ordinat(PAkhir(*L)) += deltaY;
}


boolean IsTegakLurus (GARIS L1, GARIS L2){
    return (Gradien(L1)*Gradien(L2) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2){
    return (Gradien(L1) == Gradien(L2));
}