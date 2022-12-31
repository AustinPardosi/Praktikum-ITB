# NIM/Nama  : 16521085/Austin Gabriel Pardosi
# Tanggal   : 6 Oktober 2021
# Deskripsi : Membuat sebuah program kalkulator sederhana yang menerima input 2 buah angka dan 
#             sebuah karakter operasi,dan menuliskan hasil perhitungannya sebagai output. 

# Kamus
# a, b : int
# c : string

# Algoritma
a = int(input("Masukkan angka pertama: "))
b = int(input("Masukkan angka kedua: "))
c = input("Masukkan operator: ")

if c == "+": #tambah
    d = a + b
elif c == "-": #kurang
    d = a - b 
elif c == "*": #kali
    d = a * b
elif c == "/": #bagi = pembagian dibulatan kebawah
    d = a // b
else : #sisa bagi
    d = a % b 

print(a, c, b,"=", d)