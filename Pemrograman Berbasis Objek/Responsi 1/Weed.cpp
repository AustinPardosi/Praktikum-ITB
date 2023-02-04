#include "Weed.hpp"
#include <cstdio>

// Membuat Weed dengan jumlah kawanan 1
Weed::Weed() {
    this->many = 1;
}

// Membuat Weed dengan jumlah kawanan n
Weed::Weed(int n) {
    this->many = n;
}

Weed::Weed(const Weed &b) {
    this->many = b.many;
}

Weed::~Weed() {}

// Menghasilkan bunyi "kresek..." berulang sebanyak n kawanan
void Weed::step() {
    for(int i=0; i<this->many; i++) {
        printf("kresek...");
    }
    printf("\n");
}