# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 3 November 2021
# Deskripsi : Problem 3 - Menghitung banyak string 1 muncul.

# Kamus
# N1 : int
# N2 : int
# muncul : int
# Kata1 = str
# Kata2 = array

# Algoritma
# input
N1 = int(input("Masukkan panjang string 1: "))
Kata1 = input("Masukkan string 1: ")
N2 = int(input("Masukkan panjang string 2: "))
Kata2 = input("Masukkan string 2: ")

# inisiasi awal muncul = 0
muncul = 0

for i in range(N2-N1+1):
    # mengecheck string
    if Kata2[i:i+N1] == Kata1:
        muncul += 1

# output
print(f"String 1 muncul sebanyak {muncul} kali.")
