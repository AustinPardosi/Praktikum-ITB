# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 27 Oktober 2021
# Deskripsi : Problem 3 - Menentukan X nilai maksimal dari perkalian.

# Kamus
# N : int
# x1 : int
# x2 : int
# root : int
# N : int

# Algoritma
# input 
N = int(input("Masukkan bilangan N : "))
x1 = 1
x2 = 1
root = int(N ** 0.5)

# Cari Nilai x1
for i in range(N % root):
    x1 *= N // root + 1
for i in range(root - N % root):
    x1 *= N // root

# Cari Nilai x2
root += 1
for i in range(N % root):
    x2 *= N // root + 1
for i in range(root - N % root):
    x2 *= N // root

# Menentukan nilai terbesar
if x1 < x2:
    x1 = x2
elif N == 2 or N == 3: #pada N==2 dan N==3 nilai terbesarnya N-1
    x1 = N-1

# output
print("Nilai maksimalnya adalah", x1)

