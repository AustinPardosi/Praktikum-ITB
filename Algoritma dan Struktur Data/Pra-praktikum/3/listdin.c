/* NIM = 13521084*/
/* Nama = Austin Gabriel Pardosi*/
/* Tanggal = 14 September 2022*/
/* Topik praktikum = ADT List Statik dan Dinamik*/
/* Implementasi ABSTRACT DATA TYPE LIST DINAMIK */

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "boolean.h"

void CreateListDin(ListDin *l, int capacity) {
    BUFFER(*l) = (int*) malloc(capacity * sizeof(int));
    NEFF(*l) = 0 ;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l) {
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

int listLength(ListDin l) {
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    if (listLength(l) == 0) {
        return IDX_UNDEF;
    }
    else  {
        return IDX_MIN;
    }
}

IdxType getLastIdx(ListDin l) {
    if (NEFF(l) == 0) {
        return IDX_UNDEF;
    }
    else {
        return NEFF(l)-1;
    }
}

boolean isIdxValid(ListDin l, IdxType i) {
    return ((i >= 0) && (i < CAPACITY(l)));
}

boolean isIdxEff(ListDin l, IdxType i) {
    return ((i >= 0) && (i < NEFF(l)));
}

boolean isEmpty(ListDin l) {
    return (NEFF(l) == 0);
}

boolean isFull(ListDin l) {
    return (NEFF(l) == CAPACITY(l));
}

void readList(ListDin *l) {
    int N, j, elemen;

    scanf("%d", &N);

    while ((N < 0) || (N > CAPACITY(*l))) {
        scanf("%d", &N);
    }

    if (N == 0) {
        CreateListDin(l, CAPACITY(*l));
    }
    else {
        CreateListDin(l, CAPACITY(*l));
        for (int i = 0; i <= N-1; i++) {
            scanf("%d", &elemen);
            ELMT(*l, i) = elemen;
        }
        NEFF(*l) = N;
    }
}

void printList(ListDin l) {
    if (listLength(l) == 0) {
        printf("[]");
    }
    else {
        printf("[");

        for (int i = 0; i <= getLastIdx(l)-1; i++) {
            printf("%d,", ELMT(l, i));
        }

        printf("%d]", ELMT(l, getLastIdx(l)));
    }
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin l3;
    CreateListDin(&l3, CAPACITY(l1));

    if ((NEFF(l1) == NEFF(l2)) && (NEFF(l1) != 0)) {
        if (plus ==  true) {
            for (int i=0; i <= getLastIdx(l1); i++) {
                ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
            }
        }
        else {
            for (int i=0; i <= getLastIdx(l1); i++) {
                ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
            }
        }
    }

    NEFF(l3) = NEFF(l1);
    return l3;
}

boolean isListEqual(ListDin l1, ListDin l2) {
    boolean equal = true;

    if (NEFF(l1) != NEFF(l2)) {
        return false;
    }
    else if (NEFF(l1) == 0) {
        return equal;
    }
    else {
        int i = IDX_MIN;
        while ((i <= getLastIdx(l1)) && (equal == true)) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                equal = false;
            }
            else{
                i++;
            }
        }
        return equal;
    }
}

IdxType indexOf(ListDin l, ElType val) {
    int indexFound = IDX_UNDEF;
    boolean found = false;

    if (listLength(l) > 0) {
        int i = IDX_MIN;
        while ((i <= getLastIdx(l)) && found == false) {
            if (ELMT(l,i) == val) {
                found = true;
                indexFound = i;
            }
            else {
                i++;
            }
        }
    }
    return indexFound;
}

void extremeValues(ListDin l, ElType *max, ElType *min) {
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    for (int i = IDX_MIN + 1; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, CAPACITY(lIn));
    
    for (int i = IDX_MIN; i <= getLastIdx(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }

    NEFF(*lOut) = NEFF(lIn);
}

ElType sumList(ListDin l) {
    int jumlah = 0;
    if (NEFF(l) != 0) {
        for (int i = IDX_MIN; i <= getLastIdx(l); i++) {
            jumlah += ELMT(l, i);
        }
    }
    return jumlah;
}

int countVal(ListDin l, ElType val) {
    int count = 0;
    if (NEFF(l) != 0) {
        for (int i = IDX_MIN; i <= getLastIdx(l); i++) {
            if (ELMT(l, i) == val) {
                count += 1;
            }
        }
    }

    return count;
}

void sort(ListDin *l, boolean asc) {
    if (NEFF(*l) > 1) {
        int min = 9999, max=-9999, idxMin, idxMax, temp;
        if (asc == true) {
            for (int i = IDX_MIN; i<=getLastIdx(*l)-1; i++) {
                for (int j=i; j<=getLastIdx(*l); j++) {
                    if (ELMT(*l, j) < min) {
                        min = ELMT(*l, j);
                        idxMin = j;
                    }
                }

                temp = ELMT(*l, i);
                ELMT(*l, i) = min;
                ELMT(*l, idxMin) = temp;

                min = 9999;
            }
        }
        else {
            for (int i = IDX_MIN; i<=getLastIdx(*l)-1; i++) {
                for (int j=i; j<=getLastIdx(*l); j++) {
                    if (ELMT(*l, j) > max) {
                        max = ELMT(*l, j);
                        idxMax = j;
                    }
                }

                temp = ELMT(*l, i);
                ELMT(*l, i) = max;
                ELMT(*l, idxMax) = temp;

                max = -9999;
            }
        }
    }
}

void insertLast(ListDin *l, ElType val) {
    ELMT(*l, getLastIdx(*l)+1) = val;
    NEFF(*l) += 1;
}

void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) -= 1;
}

void expandList(ListDin *l, int num) {
    int capacityAwal;
    ListDin tempList;
    
    capacityAwal = CAPACITY(*l);
    copyList(*l, &tempList);
    CreateListDin(l, capacityAwal + num);

    for (int i = IDX_MIN; i <= getLastIdx(tempList); i++) {
        ELMT(*l, i) = ELMT(tempList, i);
    }

    NEFF(*l) = NEFF(tempList);
    dealocateList(&tempList);
}

void shrinkList(ListDin *l, int num) {
    int capacityAwal;
    ListDin tempList;
    
    capacityAwal = CAPACITY(*l);
    copyList(*l, &tempList);
    CreateListDin(l, capacityAwal - num);

    for (int i = IDX_MIN; i <= getLastIdx(tempList); i++) {
        ELMT(*l, i) = ELMT(tempList, i);
    }

    NEFF(*l) = NEFF(tempList);
    dealocateList(&tempList);
}

void compressList(ListDin *l) {
    int capacityAwal;
    ListDin tempList;
    
    copyList(*l, &tempList);
    CreateListDin(l, NEFF(*l));

    for (int i = IDX_MIN; i <= getLastIdx(tempList); i++) {
        ELMT(*l, i) = ELMT(tempList, i);
    }

    NEFF(*l) = NEFF(tempList);
    dealocateList(&tempList);
}
