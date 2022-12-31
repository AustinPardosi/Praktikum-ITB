# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 6 Oktober 2021
# Deskripsi : Problem 2 - Program pembantu menampilkan Harga dan Kelas tiket
 
# Membuat program yang dapat menampilkan Harga dan Kelas tiket tuan Kil sebagai output 
# berdasarkan input nomor kursi dan posisi kursi

#Kamus
#a, harga = int
#b = str

#Algoritma
a = int(input("Tentukan Nomor Kursi: "))
b = input("Tentukan Posisi Kursi: ")

if (a<=20 and a>=1) or (a<=60 and a>=51):
    c = "Hot Seat"
    if b == "A" or b == "F":
        Harga = 1600000
    elif b == "B" or b == "E":
        Harga = 1550000
    elif b == "C" or b == "D":
        Harga = 1500000

elif (a<=50 and a>=21) or (a<=100 and a>=61):
    c = "Regular"
    if b == "A" or b == "F":
        Harga = 1000000
    elif b == "B" or b == "E":
        Harga = 950000
    elif b == "C" or b == "D":
        Harga = 900000

print("Tuan Kil memilih kursi", c, "dengan harga", Harga )
