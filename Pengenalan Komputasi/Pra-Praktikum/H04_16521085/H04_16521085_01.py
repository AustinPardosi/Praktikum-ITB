# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 17 November 2021
# Deskripsi : Problem 1 - Menuliskan semua nilai f(x).

# Algoritma
def fungsi(x): # Mendeklarasi fungsi f(x)
    hasil = x*x-2*x+5
    return hasil

# Input
a = int(input("Masukkan A: "))
b = int(input("Masukkan B: "))

for x in range(a, b+1):
    # Output
    print(f"f({x}) = {fungsi(x)}")