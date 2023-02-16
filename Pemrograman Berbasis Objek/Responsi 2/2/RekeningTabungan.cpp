#include "RekeningTabungan.h"

// Konstruktor menginisialisi saldo (parameter 1) dan biaya transaksi (parameter 2)
// Set biaya transaksi 0.0 apabila biaya transaksi bernilai negatif
RekeningTabungan::RekeningTabungan(double initSaldo, double initTransaksi) : Rekening(initSaldo) {
    if (initTransaksi < 0) {
        this->biayaTransaksi = 0.0;
    } else {
        this->biayaTransaksi = initTransaksi;
    }
}

// Getter, Setter
void RekeningTabungan::setBiayaTransaksi(double initTransaksi) {
    this->biayaTransaksi = initTransaksi;
}

double RekeningTabungan::getBiayaTransaksi() const {
    return this->biayaTransaksi;
}

// Member Function
// Panggil fungsi simpanUang dari parent class
// Kurangkan saldo dengan biaya transaksi
void RekeningTabungan::simpanUang(double initUang) {
    Rekening::simpanUang(initUang);
    setSaldo(getSaldo() - this->biayaTransaksi);
}

// Panggil fungsi tarikUang dari parent class
// Kurangkan saldo dengan biaya transaksi hanya jika penarikan uang berhasil
// Saldo mungkin saja menjadi negatif apabila setelah penarikan, saldo < biaya transaksi
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool RekeningTabungan::tarikUang(double money) {
    bool hasil = Rekening::tarikUang(money);
    if (hasil) {
        setSaldo(getSaldo() - getBiayaTransaksi());
    } 
    return hasil;
}