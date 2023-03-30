/* NIM = 13521084*/
/* Nama = Austin Gabriel Pardosi*/
/* Tanggal = 14 September 2022*/
/* Topik praktikum = ADT List Statik dan Dinamik*/
/* Implementasi ABSTRACT DATA TYPE LIST STATIC */

#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"
#include "boolean.h"

void CreateListStatik(ListStatik *l) {
    int i;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;    
    }
}

int listLength(ListStatik l) {
    int length = IDX_MIN;
    boolean foundMark = false;

    while (length < CAPACITY && foundMark == false) {
        if (ELMT(l, length) == MARK) {
            foundMark = true;
        } else {
            length++;
        }
    } 
    return length;
}

IdxType getFirstIdx(ListStatik l) {
    if (listLength(l) == 0) {
        return IDX_UNDEF;
    } else {
        return IDX_MIN;
    }
}

IdxType getLastIdx(ListStatik l) {
    if (listLength(l) == 0) {
        return IDX_UNDEF;
    } else {
        return listLength(l)-1;
    }
}

boolean isIdxValid(ListStatik l, IdxType i) {
    return ((i >= 0) && (i <= CAPACITY-1));
}

boolean isIdxEff(ListStatik l, IdxType i) {
    return ((i >= 0) && (i <= getLastIdx(l)));
}

boolean isEmpty(ListStatik l) {
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l) {
    int n, i, j, elemen;
    scanf("%d", &n);

    while ((n < 0) || (n > CAPACITY)) {
        scanf("%d", &n);
    }

    if (n == 0) {
        CreateListStatik(l);
    } else {
        CreateListStatik(l);
        for (i = 0; i <= n-1; i++) {
            scanf("%d", &elemen);
            ELMT(*l, i) = elemen;
        }
    }
}

void printList(ListStatik l) {
    int i;
    if (listLength(l) == 0) {
        printf("[]");
    }
    else{
        printf("[");
        for (i = 0; i <= getLastIdx(l)-1; i++) {
            printf("%d,", ELMT(l, i));
        }
        printf("%d]", ELMT(l, getLastIdx(l)));
    }
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik lhasil;
    int i;

    CreateListStatik(&lhasil);

    if ((listLength(l1) == listLength(l2)) && (listLength(l1) != 0)) {
        if (plus ==  true) {
            for (i=0; i <= getLastIdx(l1); i++) {
                ELMT(lhasil, i) = ELMT(l1, i) + ELMT(l2, i);
            }
        }
        else {
            for (i=0; i <= getLastIdx(l1); i++) {
                ELMT(lhasil, i) = ELMT(l1, i) - ELMT(l2, i);
            }
        }
    }

    return lhasil;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
    int i = IDX_MIN;
    boolean equal = true;

    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    else if (listLength(l1) == 0) {
        return equal;
    }
    else {
        while ((i <= getLastIdx(l1)) && (equal == true)) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                equal = false;
            }else {
                i++;
            }
        }
        return equal;
    }
}

int indexOf(ListStatik l, ElType val) {
    int indexFound = IDX_UNDEF, i = IDX_MIN;
    boolean found = false;

    if (listLength(l) > 0) {
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

void extremeValues(ListStatik l, ElType *max, ElType *min) {
    int i = IDX_MIN + 1;

    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);

    for (i; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val){
    if (listLength(*l) == 0) {
        ELMT(*l, IDX_MIN) = val;
    } else {
        for (int i=listLength(*l); i>0; i--) {
            ELMT(*l,i) = ELMT(*l, i-1);
        }

        ELMT(*l, IDX_MIN) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    for(int i=listLength(*l); i>= idx+1; i--) {
        ELMT(*l,i) = ELMT(*l, i-1);
    }

    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val){
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
    *val = ELMT(*l, IDX_MIN);

    for (int i = IDX_MIN; i<=getLastIdx(*l)-1; i++) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }

    ELMT(*l, getLastIdx(*l)) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    *val = ELMT(*l, idx);

    for (int i=idx; i<=getLastIdx(*l)-1; i++) {
        ELMT(*l, i) = ELMT(*l, i+1);
    }

    ELMT(*l, getLastIdx(*l)) = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    *val  = ELMT(*l, getLastIdx(*l));

    ELMT(*l, getLastIdx(*l)) = MARK;
}

void sortList(ListStatik *l, boolean asc){
    int swap_idx,len;
    ElType temp;

    len = listLength(*l);
    if (asc) {
        for (int i =IDX_MIN;i<len;i++) {
            swap_idx = i;
            for (int j=i+1;j<len;j++) {
                if (ELMT(*l,j) < ELMT(*l,swap_idx))
                    swap_idx = j;
            }
            temp = ELMT(*l,swap_idx);
            ELMT(*l,swap_idx) = ELMT(*l,i);
            ELMT(*l,i) = temp;
        }
        return;
    }

    for (int i=IDX_MIN;i<len;i++) {
        swap_idx = i;
        for (int j=i+1;j<len;j++) {
            if (ELMT(*l,j) > ELMT(*l,swap_idx))
                swap_idx = j;
        }
        temp = ELMT(*l,swap_idx);
        ELMT(*l,swap_idx) = ELMT(*l,i);
        ELMT(*l,i) = temp;
    }
}