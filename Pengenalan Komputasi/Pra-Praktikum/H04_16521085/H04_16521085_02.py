# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 17 November 2021
# Deskripsi : Problem 2 - Mencetak matriks.

# Algoritma
n = int(input("Masukkan N: "))
m = int(input("Masukkan M: "))
X = [[0 for i in range(m)] for i in range(n)] # deklarasi array untuk matriks
positif = 0  

for i in range (n):
    for j in range(m):  # mengisi matriks 
        X[i][j] = int(input("Masukkan Nilai A[{}][{}]: " .format(i+1, j+1)))
        if X[i][j] > 0: # menentukan jumlah bil. positif
            positif += 1      

print(f"Ada {positif}, bilangan positif di matriks.")

for i in range(n):
    for j in range(m):  # mencetak matriks 
        print(X[i][j], end=" ")
    print()