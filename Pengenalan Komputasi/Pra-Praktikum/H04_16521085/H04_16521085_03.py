# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 17 November 2021
# Deskripsi : Problem 3 - Menuliskan matriks segitiga pascal.

# Algoritma
# Input
n = int(input("Masukkan N: "))
X = [[1 for i in range(n)] for j in range(n)] # Deklaasi matriks 

for i in range(n) :
    for j in range(n) :
        if (i!= 0 and j!= 0): #!= yang artinya bilangan tidak boleh sama dengan 0
             X[i][j] = X[i-1][j] + X[i][j-1]

# Output     
        print(X[i][j], end = " ") 
    print()
