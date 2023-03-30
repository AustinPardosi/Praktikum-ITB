#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"
#include "boolean.h"

void findMedian(ListStatik l, ElType *med){
    int len_l = listLength(l);
    sortList(&l,true);
    if(len_l%2==1){
        *med = ELMT(l,((len_l/2)));
    } else{
        *med = ELMT(l,(len_l/2)-1);
    }
}

int main() {
    int x, idx, max, min, median;
    ListStatik L;
    
    readList(&L);
    printList(L);
    printf("\n");

    scanf("%d", &x);
    idx = indexOf(L, x);
    if (idx != IDX_UNDEF) {
        printf("%d\n", idx);
        extremeValues(L, &max, &min);
        findMedian(L, &median);
        if (x == max) {
            printf("maksimum\n");
        } 
        if (x == min) {
            printf("minimum\n");
        }
        if (x == median) {
            printf("median\n");
        }
    } else {
        printf("%d tidak ada\n", x);
    }

    return 0;
}