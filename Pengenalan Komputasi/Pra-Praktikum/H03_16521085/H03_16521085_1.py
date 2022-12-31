# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 3 November 2021
# Deskripsi : Problem 1 - Menuliskan kembali bilangan terbalik.

# Kamus
# N : int

# Algoritma
N = int(input("Masukkan N : "))
angka = [0 for i in range (N)]
for i in range (N):
    angka[i] = int(input())
for i in range (N-1, -1, -1):
    print(angka[i])