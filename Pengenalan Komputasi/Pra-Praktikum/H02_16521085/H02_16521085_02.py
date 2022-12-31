# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 27 Oktober 2021
# Deskripsi : Problem 2 - Menuliskan bilangan 10**x terkecil yang lebih dari N.

# Kamus
# N,  i : int
# Stop : bool


# Algoritma
N = int(input("Masukkan N : "))
Stop = False
i = 0
while (Stop==False):
    if 10**i>N:
        Stop = True
    else:
        i += 1
print(10**i)