# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 17 November 2021
# Deskripsi : Problem 2 - Mencari banyak permutasi string.

# Kamus
# N : int
# hasil : int
# kata : str
# huruf : array
# jlh : array
# asumsikan masukan pengguna bilangan bulat

# Algoritma
# Fungsi Permutasi
def permutasi(x):
    hasil = 1
    for i in range (1, x + 1):
        hasil *= i
    return hasil # Mengembalikan nilai permutasi

# Input
N = int(input('Masukkan panjang string: '))
kata = input('Masukkan string: ')

huruf = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
jlh = [0 for i in range(26)] # Jumlah huruf yang ada 

# Perulangan
for i in range(N):
    for j in range(26):
        if kata[i] == huruf[j]:
            jlh[j] += 1

hasil = permutasi(N)

# Perulangan
for i in range(26):
    if jlh[i] > 1:
        hasil /= permutasi(jlh[i])

# Output
# Memanggil hasil dan dicetak
print(f"String tersebut dapat membentuk {str(hasil)} kata berbeda.")