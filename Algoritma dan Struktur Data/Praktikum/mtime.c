/* NIM = 13521084*/
/* Nama = Austin Gabriel Pardosi*/
/* Tanggal = 8 September 2022*/
/* Topik praktikum = ADT Sederhana*/
/* Membuatlah sebuah program yang digunakan untuk membaca beberapa pasangan TIME yang merepresentasikan waktu mulai dan waktu selesai pembicaraan telepon di suatu perusahaan penyedia layanan telepon, misalnya <T1, T2>.  */

#include <stdio.h>
#include "boolean.h"
#include "time.h"

int main() {
    int Record;
    TIME T1, T2, T;
    TIME TAwal, TAkhir;
    CreateTime(&TAwal, 23, 59, 59);
    CreateTime(&TAkhir, 0, 0, 0);
    scanf("%d", &Record);

    for (int i = 0; i < Record; i++) {
        printf("[%d]\n", i+1);
        BacaTIME (&T1);
        BacaTIME (&T2);

        if (TEQ (T1, T2)) {
            printf("0\n");
        } else {
            if (TLT (T1, T2)) {
                printf("%d\n", Durasi (T1, T2));
            }  else {
                printf("%d\n", Durasi (T2, T1));
            }
        }

        if (TLT (T1, T2)) {
            if (TLT (T1, TAwal)) {
                TAwal = T1;
            }
            if (TLT (TAkhir, T2)) {
                TAkhir = T2;
            }
        } else {
            if (TLT (T2, TAwal)) {
                TAwal = T2;
            }
            if (TLT (TAkhir, T1)) {
                TAkhir = T1;
            }
        }
    }

    TulisTIME (TAwal);
    printf("\n");
    TulisTIME (TAkhir);
    printf("\n");


    return 0;
}
