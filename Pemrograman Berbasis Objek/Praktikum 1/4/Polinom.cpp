#include "Polinom.hpp"
#include <cstdio>
#include <cmath>

Polinom::Polinom() {
    this->derajat = 0;
    this->koef = new int[this->derajat];
} 

Polinom::Polinom(int n) {
    this->derajat = n;
    this->koef = new int[this->derajat];
} 

Polinom::Polinom(const Polinom& t) {
    this->derajat = t.derajat;
    this->koef = new int[this->derajat];
    for(int i=0; i<=this->derajat; i++) {
        this->koef[i] = t.koef[i];
    }
}

Polinom::~Polinom() {
    delete [] this->koef;
}

Polinom& Polinom::operator=(const Polinom& t) {
    this->derajat = t.derajat;
    for(int i=0; i<=this->derajat; i++) {
        this->koef[i] = t.koef[i];
    }
    return *this;
}

int Polinom::getKoefAt(int idx) const {
    return this->koef[idx];
}

int Polinom::getDerajat() const {
    return this->derajat;
}

void Polinom::setKoefAt(int idx, int val) {
    this->koef[idx] = val;
}

void Polinom::setDerajat(int x) {
    this->derajat = x;
}

void Polinom::input() {
    for(int i=0; i<=this->derajat; i++) {
        scanf("%d", &this->koef[i]);
    }
}

void Polinom::printKoef() {
    for(int i=0; i<=this->derajat; i++) {
        printf("%d\n", this->koef[i]);
    }
}

int Polinom::substitute(int t) {
    int sum = 0;
    for(int i=0;i<=this->derajat;i++){
        sum += koef[i]*pow(t,i);
    }
    return sum;
}

void Polinom::print() {
    bool allZero = true;

    for(int i = 0;i<=this->derajat;i++){
        if(koef[i]!=0){
            allZero = false;
            break;
        }
    }

    if (allZero) {
        printf("0\n");
    } else {
        printf("%d", this->koef[0]);
        for(int i = 1;i<=this->derajat;i++){
            if(koef[i]>0){
                printf("+");
            }

            if(koef[i]!=0){
                printf("%d", koef[i]);
                printf("x^");
                printf("%d", i);
            }
        }
        printf("\n");
    }
}