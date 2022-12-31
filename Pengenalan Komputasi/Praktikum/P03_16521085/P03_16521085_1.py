# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 3 November 2021
# Deskripsi : Problem 1 - Mencari banyak huruf vokal dan konsonan dalam sebuah kata.

# Kamus
# Nilai_N : int
# spasi : int
# vokal : int
# konsonan : int
# i : int
# kata : array


# Algoritma
spasi = 0
vokal = 0
konsonan = 0

# input
Nilai_N = int(input("Masukkan N: "))
kata = input("Masukkan string: ")

for i in range (Nilai_N) :
    # Mengecheck huruf vokal
    if kata[i] == "a" or kata[i] == "e" or kata[i] == "i" or kata[i] == "o" or kata[i] == "u" :
        vokal = vokal + 1
    # Mengecheck spasi
    elif kata[i] == " " :
        spasi = spasi + 1
    # Mengecheck huruf konsonan
    else : 
        konsonan = konsonan + 1

# output
print(f"Terdapat {vokal} huruf vokal dan {konsonan} huruf konsonan")