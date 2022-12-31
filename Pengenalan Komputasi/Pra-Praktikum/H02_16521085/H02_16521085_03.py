# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 27 Oktober 2021
# Deskripsi : Problem 3 - Menentukan X bilangan prima.

# Kamus
# X,  i : int
# Prima : bool


# Algoritma
X = int(input("Masukkan X: "))
Prima = True

for i in range(2, X):
    if X%i==0:
        Prima = False

if (Prima==True):
    print(X, "adalah bilangan prima.")
elif(Prima==False):
    print(X, "bukan bilangan prima.")