// NIM              : 13521084
// Nama             : Austin Gabriel Pardosi
// Tanggal          : 3 November 2022
// Topik praktikum  : Latihan Praktikum ADT Linked List

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listlinier.h"

Address newNode(ElType val)
{
    Address p = (Address) malloc(sizeof(Node));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    int ctr;
    Address p;

    ctr = 0;
    p = FIRST(l);
    while(ctr < idx) {
        ctr += 1;
        p = NEXT(p);
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    int ctr;
    Address p;

    ctr = 0;
    p = FIRST(*l);
    while (ctr < idx) {
        ctr += 1;
        p = NEXT(p);
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    Address p;
    int idx;
    boolean found;

    p = FIRST(l);
    found = false;
    idx = 0;
    while (p!= NULL && !found) {
        if (INFO(p) == val) {
            found = true;
        } else {
            idx += 1;
            p = NEXT(p);
        }
    }
    if (found) {
        return idx;
    } else {
        return IDX_UNDEF;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p;

    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address p, last;

    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = FIRST(*l);
            while(NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    int ctr;
    Address p, loc;

    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = FIRST(*l);
            while (ctr < idx-1) {
                ctr += 1;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p;

    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address p, loc;

    p = FIRST(*l);
    loc = NULL;
    while(NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    int ctr;
    Address p, loc;

    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        ctr = 0;
        loc = FIRST(*l);
        while (ctr < idx-1) {
            ctr += 1;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address p;

    printf("[");
    p = FIRST(l);
    while (p != NULL) {
        if (NEXT(p) == NULL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int ctr;
    Address p;

    ctr = 0;
    p = FIRST(l);
    while (p != NULL) {
        ctr += 1;
        p = NEXT(p);
    }
    return ctr;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P){
    while (FIRST(L) != NULL && FIRST(L) != P) {
        FIRST(L) = NEXT(L);
    }
    return (FIRST(L) == P);
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

Address searchPrec(List L, ElType X){
    Address prev;
    prev = NULL;
    while (FIRST(L) != NULL && INFO(FIRST(L)) != X) {
        prev = FIRST(L);
        FIRST(L) = NEXT(L);
    }
    if (prev == NULL) {
        return NULL;
    } else {
        return prev;
    }
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/*** Prekondisi untuk Max/Min : List tidak kosong ***/

ElType max(List l){
    ElType maxElmt;
    maxElmt = INFO(FIRST(l));
    while(FIRST(l) != NULL) {
        if (maxElmt < INFO(FIRST(l))) {
            maxElmt = INFO(FIRST(l));
        }
        FIRST(l) = NEXT(l);
    }
    return maxElmt;
}
/* Mengirimkan nilai info(P) yang maksimum */

Address adrMax(List l){
    ElType maxElmt;
    Address adr;
    maxElmt = INFO(FIRST(l));
    adr = FIRST(l);
    while (FIRST(l) != NULL) {
        if (maxElmt < INFO(FIRST(l))) {
            maxElmt = INFO(FIRST(l));
            adr = FIRST(l);
        }
        FIRST(l) = NEXT(l);
    }
    return adr;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */

ElType min(List l){
    ElType minElmt;

    minElmt = INFO(FIRST(l));
    while (FIRST(l) != NULL) {
        if (minElmt > INFO(FIRST(l))) {
            minElmt = INFO(FIRST(l));
        }
        FIRST(l) = NEXT(l);
    }
    return minElmt;
}
/* Mengirimkan nilai info(P) yang minimum */

Address adrMin(List l){
  ElType minElmt;
  Address adr;

// ALGORITMA
    minElmt = INFO(FIRST(l));
    adr = FIRST(l);
    while (FIRST(l) != NULL) {
        if (INFO(FIRST(l)) < minElmt) {
            minElmt = INFO(FIRST(l));
            adr = FIRST(l);
        }
        FIRST(l) = NEXT(l);
    }
    return adr;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
    Address p;
    List l3;

    CreateList(&l3);
    p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l){
    Address walker, temp;

    walker = FIRST(*l);
    while (FIRST(walker) != NULL) {
        temp = FIRST(walker);
        FIRST(walker) = NEXT(walker);
        free(temp);
    }
    FIRST(*l) = NULL;
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyList(List *l1, List *l2){
    FIRST(*l2) = FIRST(*l1);
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

void inverseList(List *l){
    Address walker1, walker2, walker3;

    walker1 = FIRST(*l);
    walker2 = NULL;

    if (walker1 != NULL) {
        do {
            walker3 = walker2;
            walker2 = walker1;
            walker1 = NEXT(walker1);
            NEXT(walker2) = walker3;
        } while (walker1 != NULL);
        FIRST(*l) = walker2;
    }
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void splitList(List *l1, List *l2, List l){
    int l1len;
    CreateList(l1);
    CreateList(l1);
    l1len = length(l) / 2;

    for (int i=0; i<l1len; i++) {
        insertLast(l1, INFO(FIRST(l)));
        FIRST(l) = NEXT(l);
    }
    while (FIRST(l) != NULL) {
        insertLast(l2, INFO(FIRST(l)));
        FIRST(l) = NEXT(l);
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */