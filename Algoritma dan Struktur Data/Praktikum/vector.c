/* NIM = 13521084*/
/* Nama = Austin Gabriel Pardosi*/
/* Tanggal = 8 September 2022*/
/* Topik praktikum = ADT Sederhana*/
/* Implementasi ABSTRACT DATA TYPE VECTOR */

#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "vector.h"
#include <math.h>

void CreateVector(VECTOR *v, float x, float y){
    AbsisComponent(*v) = x;
    OrdinatComponent(*v) = y;
}

void TulisVector(VECTOR v){
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

float Magnitude(VECTOR v){
    return (sqrt(pow(AbsisComponent(v),2) + pow(OrdinatComponent(v),2)));
}

VECTOR Add(VECTOR a, VECTOR b){
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    return v;
}

VECTOR Substract(VECTOR a, VECTOR b){
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) - OrdinatComponent(b);
    return v;
}

float Dot(VECTOR a, VECTOR b){
    return ((AbsisComponent(a)*AbsisComponent(b)) + (OrdinatComponent(a)* OrdinatComponent(b)));
}

VECTOR Multiply(VECTOR v, float s){
    AbsisComponent(v) *= s;
    OrdinatComponent(v) *= s;
    return v;
}
