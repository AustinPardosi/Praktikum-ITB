# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 3 November 2021
# Deskripsi : Problem 2 - Mengetahui keadaan akhir rangkaian lampu.

# Kamus
# N : int 
# x : int
# i : int
# j : int
# Tombool : array

# Algoritma
# input
N = int(input("Masukkan banyak lampu: "))
x = int(input("Masukkan berapa kali Tuan Kil menekan tombol: "))

# inisiasi array untuk inputan
# inisiasi array Tombol yang nilainya 0
Tombol = [0 for i in range(N)]

# isi array inputan
for i in range(x):
    j = int(input(f"Tombol yang ditekan ke {i+1}: ")) - 1
    if Tombol[j] == 0:
        Tombol[j] = 1
    else:
        Tombol[j] = 0

    if j+1 != N:
        if Tombol[j+1] == 0:
            Tombol[j+1] = 1
        else:
            Tombol[j+1] = 0

    if j != 0:
        if Tombol[j-1] == 0:
            Tombol[j-1] = 1
        else:
            Tombol[j-1] = 0

# output
print(f"Keadaan akhir rangkaian lampu adalah {Tombol}.")