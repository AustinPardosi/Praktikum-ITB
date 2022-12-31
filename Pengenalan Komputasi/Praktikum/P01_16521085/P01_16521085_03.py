# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 6 Oktober 2021
# Deskripsi : Problem 3 - Program pembantu menampilkan data mungkin benar atau tidak mungkin benar
 
# Membuat program yang dapat menentukan data mungkin benar atau tidak mungkin benar berdasarkan 
# input banyak kaki, orangtua dan anak

#Kamus
#a,b,c = int
#x = str

#Algoritma
a = int(input("Banyak kaki yang menginjak lantai: "))
b = int(input("Banyak orangtua: "))
c = int(input("Banyak anak: "))

if a%2==0:
    if a == 2*(b+c):
        x = "mungkin benar"
    elif a > 2*(b+c):
        x = "tidak mungkin benar"
    else :
        if a>=b*2 :
            if c<=b*2:
                x = "mungkin benar"
            else:
                x = "tidak mungkin benar"
        else :
            x = "tidak mungkin benar"
else :
    x = "tidak mungkin benar"

print("Data Tuan Dip", x)