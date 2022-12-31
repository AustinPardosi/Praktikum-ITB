# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 17 November 2021
# Deskripsi : Problem 3 - Mencari keliling pulau.

# Kamus
# x : int
# y : int
# keliling : int
# i : int
# j : int
# Grid : array

# ALGORITMA
# Input
x = int(input('Masukkan nilai brs: '))
y = int(input('Masukkan nilai klm: '))

Grid = [[0 for j in range(y)] for i in range(x)]

# Perulangan
for i in range(x):
    for j in range(y):
        print('Masukkan nilai petak baris', int(i + 1), 'kolom', int(j + 1), end=': ')
        Grid[i][j] = int(input())

kelilng = 0

for i in range(x):
    for j in range(y):
        if Grid[i][j] == 1:

            # Bagian atas
            if (i == 0):
                kelilng += 1
            elif (Grid[i - 1][j] == 0):
                kelilng += 1

            # Bagian bawah
            if (i == (x - 1)):
                kelilng += 1
            elif (Grid[i + 1][j] == 0):
                kelilng += 1

            # Bagian kanan
            if (j == (y - 1)):
                kelilng += 1
            elif (Grid[i][j + 1] == 0):
                kelilng += 1

            # Bagian kiri
            if (j == 0):
                kelilng += 1
            elif (Grid[j - 1] == 0):
                kelilng += 1
            
# Output
print()
print(f"Keliling pulau tersebut adalah {kelilng}.")