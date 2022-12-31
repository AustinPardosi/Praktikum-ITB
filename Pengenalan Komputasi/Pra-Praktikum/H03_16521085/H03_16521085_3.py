# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 3 November 2021
# Deskripsi : Problem 3 - Menentukan string palindrom.

# Kamus
# N : int

# Algoritma
N = int(input("Masukkan panjang string: "))
Kata = input("Masukkan string: ")
A = ["" for i in range (N)]

for i in range(N//2):
    for j in range (N-1, N//2, -1):
        if Kata[i] == Kata[j]:
            x = "adalah palindrom"
        else :
            x = "bukan palindrom"
print(Kata, x)