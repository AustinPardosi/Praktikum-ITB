#include "Rekening.h"
// Konstruktor untuk menginisialisasi saldo
// Set saldo 0.0 apabila saldo bernilai negatif
Rekening::Rekening(double saldo) {
    if (saldo < 0) {
        this->saldo = 0.0;
    } else {
        this->saldo = saldo;
    }
}
	
// Getter, Setter
void Rekening::setSaldo(double newSaldo) {
    this->saldo = newSaldo;
}

double Rekening::getSaldo() const {
    return this->saldo;
}

// Member Function
// Tambahkan sejumlah nominal uang ke saldo
void Rekening::simpanUang(double newSaldo) {
    this->saldo += newSaldo;
}

// Kurangkan sejumlah nominal uang dari saldo apabila saldo mencukupi (tidak negatif setelah dikurangkan)
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool Rekening::tarikUang(double minSaldo) {
    double x = this->saldo;
    if (this->saldo - minSaldo >= 0) {
        this->saldo -= minSaldo;
    }

    if (x == this->saldo + minSaldo) {
        return true;
    } else {
        return false;
    }
}