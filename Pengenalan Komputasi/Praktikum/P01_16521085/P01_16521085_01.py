# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 6 Oktober 2021
# Deskripsi : Problem 1 - Program pembantu menampilkan Harga dan Kelas tiket
 
# Membuat program yang dapat menampilkan Pajak yang harus dibayar Tuan Ric sebagai output 
# berdasarkan input penghasilan Tuan Ric

#Kamus
#a, pajak = int

#Algoritma
a = int(input("Masukkan penghasilan Tuan Ric: "))

if a<50000000:
    Pajak = 5/100*a
elif a>=50000000 and a<250000000:
    Pajak = 15/100*a
elif a>=250000000 and a<500000000:
    Pajak = 25/100*a
else :
    Pajak = 30/100*a

print("Pajak yang harus dibayar Tuan Ric sebesar", Pajak, "rupiah.")

