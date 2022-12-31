# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 27 Oktober 2021
# Deskripsi : Problem 2 - Menentukan berapa ember x dan y yang diperlukan mengisi ember z.

# Kamus
# x : int
# y : int
# z : int
# sum_x : int
# sum_y : int
# hasil : str
# diasumsikan input berupa bilangan bulat positif selain 0

# Algoritma
# input
x = int(input("Masukkan Volume x= "))
y = int(input("Masukkan Volume y= "))
z = int(input("Masukkan Volume z= "))

sum_x = 0
sum_y = 0


for a in range(1, z+1):
    for b in range (1, z+1):
        if a*x+b*y==z:
            sum_x = a   #update jumlah ember x
            sum_y = b   #update jumlah ember y

if sum_x==0 and sum_y==0:   #tidak ada jumlah ember x dan y yang memenuhi
    hasil = "Tidak Mungkin"     
    print(hasil) 
else:
    # output
    print(sum_x, "kali ember x", sum_y, "kali ember y.") 
