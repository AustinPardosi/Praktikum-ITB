# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 6 Oktober 2021
# Deskripsi : Membuat program yang dapat memberikan output apakah sebuah bilangan adalah 
#             bilangan positif (ganjil atau genap), negatif, atau nol berdasarkan input yang diberikan.

#Kamus
#a = float

#Algoritma
a = int(input("Masukkan X: "))

if a > 0:
    if a % 2 == 0:
        b = "bilangan positif genap"
    else :
        b = "bilangan positif ganjil"
elif a == 0:
    b = "bilangan nol"
else :
    b = "bilangan negatif"

print("X adalah", b)
