/* NIM = 13521084*/
/* Nama = Austin Gabriel Pardosi*/
/* Tanggal = 7 September 2022*/
/* Topik praktikum = ADT Sederhana*/
/* Implementasi ABSTRACT DATA TYPE TIME */

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "time.h"

boolean IsTIMEValid (int H, int M, int S){
    return ((H>=0 && H<=23) && (M>=0 && M<=59) && (S>=0 && S<=59));
}

void CreateTime (TIME * T, int HH, int MM, int SS){
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME (TIME * T){
    int inputHH, inputMM, inputSS;
    while(true){
        scanf("%d %d %d", &inputHH, &inputMM, &inputSS);
        if (IsTIMEValid(inputHH, inputMM, inputSS)) {
            break;
        } else {
            printf("Jam tidak valid\n");
        }
    }
    CreateTime(T, inputHH, inputMM, inputSS);
}

void TulisTIME (TIME T){
    if (Hour(T) <= 9) {         //biasakan presisi cth <= 9 lebih pas drpd <10.
        printf("0");
    } printf("%d:", Hour(T));

    if (Minute(T) <= 9) {
        printf("0");
    } printf("%d:", Minute(T));

    if (Second(T) <= 9) {
        printf("0");
    } printf("%d", Second(T));
}

long TIMEToDetik (TIME T){
    return (3600*(Hour(T)) + 60*(Minute(T)) + Second(T));
}

TIME DetikToTIME (long N){
    long N1;
    int NewH, NewM, NewS;
    TIME T;
    N1 = N % 86400;

    NewH = N1 / 3600;
    NewM = (N1 % 3600) / 60;
    NewS = (N1 % 3600) % 60;
    CreateTime(&T, NewH, NewM, NewS);
    return T;
}

boolean TEQ (TIME T1, TIME T2){
    return ((Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2)));
}

boolean TNEQ (TIME T1, TIME T2){
    return (!TEQ(T1, T2));
}

boolean TLT (TIME T1, TIME T2){
    return (TIMEToDetik(T2) > TIMEToDetik(T1));
}

boolean TGT (TIME T1, TIME T2){
    return (!TLT(T1, T2));
}

TIME NextDetik (TIME T){
    long TotalSecond;
    TotalSecond = TIMEToDetik(T) + 1;
    return DetikToTIME(TotalSecond);
}

TIME NextNDetik (TIME T, int N){
    long TotalSecond;
    TotalSecond = TIMEToDetik(T) + N;
    return DetikToTIME(TotalSecond);
}

TIME PrevDetik (TIME T){
    long TotalSecond;
    TotalSecond = TIMEToDetik(T) - 1;
    return DetikToTIME(TotalSecond);
}

TIME PrevNDetik (TIME T, int N){
    long TotalSecond;
    TotalSecond = TIMEToDetik(T) - N;
    return DetikToTIME(TotalSecond);
}

long Durasi (TIME TAw, TIME TAkh){
    if (TGT(TAw, TAkh)){
        return (TIMEToDetik(TAkh) - TIMEToDetik(TAw) + 86400);
    } else {
        return (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
    }
}
