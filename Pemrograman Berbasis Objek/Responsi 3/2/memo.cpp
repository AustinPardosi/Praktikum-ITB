#include "memo.h"

/* 	Membuat objek Memo dengan 'pesan' dan 'untuk' kosong */
Memo::Memo() {
    this->pesan = "";
    this->untuk = "";
}

/* 	Membuat objek Memo dengan isi sesuai yang diberikan.	
	Jika panjang pesan melebihi panjang maksimum, maka	metode ini melemparkan PesanKepanjanganException.*/
Memo::Memo(string pesan, string untuk) {
    this->untuk = untuk;
    if(pesan.length() > this->PESAN_MAX) {
        PesanKepanjanganException e;
        throw e;
    } else {
        this->pesan = pesan;
    }
}

/* 	Menyalin nilai pesan dan untuk ke objek lain */
Memo& Memo::operator=(Memo& obj) {
    this->pesan = obj.pesan;
    this->untuk = obj.untuk;
    return *this;
}

/*	Mendapatkan nilai pesan */
string Memo::getPesan() {
    return this->pesan;
}
/*	Mendapatkan nilai untuk */
string Memo::getUntuk() {
    return this->untuk;
}