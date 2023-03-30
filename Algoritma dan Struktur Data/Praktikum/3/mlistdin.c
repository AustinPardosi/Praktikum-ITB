#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

int main() {
    int Q, capacity, op, num;
    ListDin L;

    scanf("%d", &capacity);
    CreateListDin(&L, capacity);
    readList(&L);

    scanf("%d", &Q);
    for (int i=0; i<Q; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &num);
            if (isFull(L)) {
                printf("list sudah penuh\n");
            } else {
                insertLast(&L, num);
                printf("%d ", CAPACITY(L));
                printList(L);
                printf("\n");
            }
        } else if (op == 2) {
            scanf("%d", &num);
            expandList(&L, num);
            printf("%d ", CAPACITY(L));
            printList(L);
            printf("\n");
        } else if (op == 3) {
            scanf("%d", &num);
            if (listLength(L) < num) {
                printf("list terlalu kecil\n");
            } else {
                shrinkList(&L, num);
                printf("%d ", CAPACITY(L));
                printList(L);
                printf("\n");
            }
        } else if (op == 4) {
            compressList(&L);
            printf("%d ", CAPACITY(L));
            printList(L);
            printf("\n");
        }
    }

    return 0;
}