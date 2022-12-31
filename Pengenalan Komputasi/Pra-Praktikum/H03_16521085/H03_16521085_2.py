NA = int(input("Masukkan banyaknya elemen A: "))
A = [0 for i in range(NA)]
F = [0 for k in range(10)]
G = [0 for k in range(10)]

for i in range(NA):     # membuat array A
    A[i] = int(input("Masukkan elemen A ke-{}: " .format(i+1)))
for i in range(NA):
    for k in range(10):
        if int(A[i]) == k: # membuat array frekuensi A (F)
            F[k] += 1

NB = int(input("Masukkan banyaknya elemen B: "))
B = [0 for i in range(NB)]

if NB != NA:    # jika panjang A != B otomatis A bukan anagram B
    print("A bukan anagram dari B")
else:
    for j in range(NB): # membuat array B
        B[j] = int(input("Masukkan elemen B ke-{}: " .format(j+1)))
    for j in range(NB):
        for k in range(10):
            if int(B[j]) == k: # membuat array frekuensi B (G)
                G[k] += 1
                
    if F == G: # membandingkan komposisi array frekuensi dari A dan B
        print("A adalah anagram dari B")
    else:
        print("A bukan anagram dari B")