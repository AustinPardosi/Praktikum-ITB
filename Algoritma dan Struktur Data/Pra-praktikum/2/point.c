/* NIM = 13521084*/
/* Nama = Austin Gabriel Pardosi*/
/* Tanggal = 7 September 2022*/
/* Topik praktikum = ADT Sederhana*/
/* Implementasi ABSTRACT DATA TYPE POINT */

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P){
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}


boolean EQ (POINT P1, POINT P2){
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat((P2))));
}

boolean NEQ (POINT P1, POINT P2){
    return (!EQ(P1, P2));
}


boolean IsOrigin (POINT P){
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P) {
    if (Absis(P) > 0) {
        if (Ordinat(P) > 0) return 1;
        else return 4;
    } else {
        if (Ordinat(P) > 0) return 2;
        else return 3;
    }
}

POINT NextX (POINT P){
    Absis(P) += 1;
    return P;
}

POINT NextY (POINT P){
    Ordinat(P) += 1;
    return P;
}


POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if (!(IsOnSbX(P) || IsOnSbY(P))){
        if(SbX){
            Ordinat(P) *= (-1);
        } else {
            Absis(P) *=  (-1);
        }
    }
    return P;
}

float Jarak0 (POINT P){
    return sqrt((pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}

float Panjang (POINT P1, POINT P2){
    return sqrt(pow(Absis(P2) - Absis(P1), 2) + pow(Ordinat(P2) - Ordinat(P1), 2));
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
    if (!(IsOnSbX(*P) || IsOnSbY(*P))){
        if(SbX) {
            Ordinat(*P) *= (-1);
        } else {
            Absis(*P) *= (-1);
        }
    }   
}

void Putar (POINT *P, float Sudut){
    float initialAbsis, initialOrdinat;
    initialAbsis = Absis(*P);
    initialOrdinat = Ordinat(*P);
    Sudut = (360-Sudut)*M_PI/180;
    Absis(*P) = Absis(*P)*cos(Sudut) - initialOrdinat*sin(Sudut);
    Ordinat(*P) = initialAbsis*sin(Sudut) + initialOrdinat*cos(Sudut);
}

