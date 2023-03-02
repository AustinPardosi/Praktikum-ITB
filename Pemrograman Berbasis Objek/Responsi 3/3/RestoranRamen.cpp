#include "RestoranRamen.hpp"

// map<int,int> daftarMeja;
// meja, harga

// Menambah jumlah order yang dipesan oleh meja n, dengan harga p
// Jika meja sudah diisi maka akan menambah total yang telah dipesan
void RestoranRamen::tambahOrder(int n, int p) {
    map<int,int>::iterator itr = this->daftarMeja.find(n);
    if (itr != daftarMeja.end()) {
        itr->second += p;
    } else {
        this->daftarMeja.insert(pair<int,int>(n,p));
    }
}

// Mengembalikan total harga pesanan pada meja n, menghapus entri untuk meja tersebut
int RestoranRamen::tutupOrder(int n) {
    map<int,int>::iterator itr = daftarMeja.find(n);
    int value = itr->second;
    daftarMeja.erase(n);
    return value;
}

// Mengembalikan total harga pesanan pada meja n
int RestoranRamen::cekTotal(int n) {
    map<int,int>::iterator itr = daftarMeja.find(n);
    return itr->second;
}

// Mengembalikan jumlah meja yang terisi saat itu
// Restoran mungkin kosong
int RestoranRamen::totalMeja() {
    return daftarMeja.size();
}

// Mencetak semua meja yang terisi pada restoran diakhiri dengan new line
// Contoh : 
/*
    Meja 1 = 5000
    Meja 2 = 3000
    Meja 4 = 10000
*/
// Jika restoran kosong akan mencetak "Restoran kosong" diakhiri new line
void RestoranRamen::cetakMeja() {
    int totalMeja = RestoranRamen::totalMeja();
    if (totalMeja == 0) {
        cout << "Restoran kosong" << endl;
    } else {
        int idx=0;
        for(map<int,int>::iterator i = daftarMeja.begin(); i!=daftarMeja.end(); i++) {
            cout << "Meja " << i->first << " = " << i->second << endl;
            idx++;
        }
    }
}