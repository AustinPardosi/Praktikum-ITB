// NIM              : 13521084
// Nama             : Austin Gabriel Pardosi
// Tanggal          : 7 November 2022
// Topik praktikum  : Queue dan Stack dengan struktur berkait

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "queuelinked.h"

/* Prototype manajemen memori */
Address newNode(ElType x){
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
    Address p = (Address) malloc (sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return (ADDR_HEAD(q) == NULL) && (ADDR_TAIL(q) == NULL);
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    int len;
    Address walker;

    len = 0;
    walker = ADDR_HEAD(q);
    if (isEmpty(q)) {
        return 0;
    } else {
        while (walker != NULL) {
            len += 1;
            walker = NEXT(walker);
        }
        return len;
    }
}

/*** Kreator ***/
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q){
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    Address walker;
    walker = ADDR_HEAD(q);

    printf("[");
    if (!isEmpty(q)) {
        printf("%d", INFO(walker));
        walker = NEXT(walker);

        while (walker != NULL) {
            printf(",%d", INFO(walker));
            walker = NEXT(walker);
        }
    }
    printf("]");
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
    Address p;

    p = newNode(x);
    if (p != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void dequeue(Queue *q, ElType *x){
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    Address p;

    p = ADDR_HEAD(*q);
    *x = INFO(p);
    if (ADDR_HEAD(*q) == ADDR_TAIL(*q)) {
        ADDR_TAIL(*q) = NULL;
    }
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    free(p);
}