# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 27 Oktober 2021
# Deskripsi : Problem 1 - Menentukan banyak langkah diperlukan mengubah N jadi 1

# Kamus
# N : int
# Cara : int
# diasumsikan input berupa bilangan bulat positif 

# Algoritma
# input
N = int(input("Masukkan bilangan N = "))
Cara = 0
while N>1:
    if N%2==0:
        N/= 2
        Cara += 1
    else :
        N-= 1
        Cara += 1

# output
print("Banyak langkah yang diperlukan adalah", Cara)