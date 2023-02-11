#include "BunchOfKeys.hpp"
#include <cstdio>

BunchOfKeys::BunchOfKeys() {
	this->n_keys = 0;
}

void BunchOfKeys::add() {
	this->n_keys++;
}

void BunchOfKeys::shake() {
	if (n_keys > 1) {
		for(int i=0; i<this->n_keys; i++) {
			printf("krincing\n");
		}
	} else {
		printf("Tidak terjadi apa-apa\n");
	}
}
