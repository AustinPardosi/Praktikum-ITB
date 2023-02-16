#include "RekeningGiro.h"

// Konstruktor menginisialisi saldo (parameter 1) dan suku bunga (parameter 2)
// Set suku bunga 0.0 apabila suku bunga bernilai negatif
RekeningGiro::RekeningGiro(double initSaldo, double initSukBung) : Rekening(initSaldo) {
    if (initSukBung < 0) {
        this->sukuBunga = 0.0;
    } else {
        this->sukuBunga = initSukBung;
    }
}

// Getter, Setter
void RekeningGiro::setSukuBunga(double newSukBung) {
    this->sukuBunga = newSukBung;
}

double RekeningGiro::getSukuBunga() const {
    return this->sukuBunga;
}

// Member Function
// Bunga dihitung dari saldo dikali suku bunga
double RekeningGiro::hitungBunga() {
    double x = getSaldo();
    return x * this->sukuBunga;
}