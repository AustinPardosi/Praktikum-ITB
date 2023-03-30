// NIM              : 13521084
// Nama             : Austin Gabriel Pardosi
// Tanggal          : 3 November 2022
// Topik praktikum  : Latihan Praktikum ADT Linked List

#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

int main() {
	List l;
	int max, val, deletedVal; 
	float n, H, ratio; 

	CreateList(&l);

	scanf("%d", &max);
	scanf("%f", &n);
	
	H = 0;
	Address p = l;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		if (indexOf(l, val) == IDX_UNDEF) {
			insertFirst(&l, val);
			printf("miss ");
		} else {
			H += 1;
			if (indexOf(l, val) != 0) {
				deleteAt(&l, indexOf(l, val), &deletedVal);
				insertFirst(&l, val);
			}
			printf("hit ");
		}
		if (length(l) > max) {
			deleteLast(&l, &deletedVal);
		}
		displayList(l);
		printf("\n");
	}
	printf("hit ratio: ");
	if (n == 0) {
		printf("0.00\n");
	} else {
		ratio = H / n;
		printf("%.2f\n", ratio);
	}

	return 0;
}
