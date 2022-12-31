# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 17 November 2021
# Deskripsi : Problem 1 - Mencari volume rumah yang terbentuk.

# Kamus
# x : int
# t : int
# volume : int
# hasil : int
# asumsikan masukan pengguna bilangan bulat

# Algoritma
# Fungsi kubus
def kubus(x): 
    volume = x**3 # Volume kubus = s x s x s
    return volume # Mengembalikan nilai volume kubus

# Fungsi limas
def limas(x,t):
    volume = x**2*t/3  # Volume limas = s x s x t / 3
    return volume # Mengembalikan nilai volume imas

# Input
x = int(input("Masukkan panjang sisi kubus: "))
t = int(input("Masukkan tinggi limas: "))
hasil = kubus(x) + limas(x,t)

# Output
# Memanggil hasil dan dicetak
print("Volume rumah yang terbentuk adalah", '{:.1f}'.format(hasil), "meter kubik.")
