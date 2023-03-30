/*Untuk File .pl*/

/* Bagian I */
/* Deklarasi Fakta */
pria(gede).
pria(gojo).
pria(vonNeumann).
pria(vanRossum).
pria(bambang).
pria(vito).
pria(ave).
pria(wesly).
pria(elonMusk).
pria(patrick).

wanita(indah).
wanita(lovelace).
wanita(khelli).
wanita(power).
wanita(aqua).
wanita(wulandari).
wanita(anya).

usia(gede,96).
usia(indah,92).
usia(gojo,90).
usia(lovelace,79).
usia(khelli,89).
usia(vonNeumann,92).
usia(vanRossum,65).
usia(bambang,60).
usia(vito,56).
usia(power,50).
usia(ave,54).
usia(aqua,50).
usia(wulandari,24).
usia(wesly,26).
usia(elonMusk,28).
usia(patrick,24).
usia(anya,4).

menikah(gede,indah).
menikah(indah,gede).
menikah(gojo,lovelace).
menikah(lovelace,gojo).
menikah(khelli,vonNeumann).
menikah(vonNeumann,khelli).
menikah(vito,power).
menikah(power,vito).
menikah(ave,aqua).
menikah(aqua,ave).
menikah(wulandari,wesly).
menikah(wesly,wulandari).

anak(vanRossum,gede).
anak(vanRossum,indah).
anak(bambang,gede).
anak(bambang,indah).
anak(vito,gede).
anak(vito,indah).
anak(power,gojo).
anak(power,lovelace).
anak(ave,gojo).
anak(ave,lovelace).
anak(aqua,khelli).
anak(aqua,vonNeumann).
anak(wesly,vito).
anak(wesly,power).
anak(elonMusk,ave).
anak(elonMusk,aqua).
anak(patrick,ave).
anak(patrick,aqua).
anak(anya,wulandari).
anak(anya,wesly).

saudara(vanRossum,bambang).
saudara(vanRossum,vito).
saudara(bambang,vanRossum).
saudara(bambang,vito).
saudara(vito,bambang).
saudara(vito,vanRossum).
saudara(power,ave).
saudara(ave,power).
saudara(elonMusk,patrick).
saudara(patrick,elonMusk).

/* Deklarasi Rules */
kakak(X,Y) :- saudara(X,Y), usia(X,UmurX), usia(Y,UmurY), UmurX > UmurY.
keponakan(X,Y) :- saudara(SaudaraKandungY,Y), anak(X,SaudaraKandungY).
suami(X,Y) :- menikah(X,Y), pria(X).
sepupu(X,Y) :- bibi(BibiY,Y), anak(X,BibiY).
menantu(X,Y) :- anak(AnakY,Y), menikah(X,AnakY).
orangtua(X,Y) :- anak(Y,X).
bibi(X,Y) :- saudara(SaudaraKandungX,X), anak(Y,SaudaraKandungX), wanita(X).
cucu(X,Y) :- anak(AnakY,Y), anak(X,AnakY).
keturunan(X,Y):- anak(X,Y); anak(X,AnakX), keturunan(AnakX,Y).
anaksulung(X) :- anak(X,OrangtuaX), pria(OrangtuaX), \+kakak(Z,X).
anakbungsu(X) :- anak(X,OrangtuaX), pria(OrangtuaX), \+kakak(X,Z).

/* Bagian II */
/* Deklarasi Rules */
combination(N,N,1).
combination(N,0,1).
combination(N,C,X) :- N >= 0, C >= 0, N1 is N-1, C1 is C-1, combination(N1,C1,X1), combination(N1,C,X2), X is X1 + X2, !.

change(0,0).
change(X,Y) :- Y >= 5, X1 is X-1, Y1 is Y-5, change(X1,Y1).
change(X,Y) :- Y >= 2, Y < 5, X1 is X-1, Y1 is Y-2, change(X1,Y1).
change(X,Y) :- Y >=1, Y < 2, X1 is X-1, Y1 is Y-1, change(X1,Y1).

fpb(A,0,A).
fpb(A,B,X)  :- B > 0, A1 is B, B1 is A mod B, fpb(A1, B1, X), !.

mod(N,N,0).
mod(A,B,X) :- A < B, X is A.
mod(A,B,X)  :- A > 0, B > 0, A1 is A-B, mod(A1,B,Y), X is Y ,!.

deret(X,Y).
deret(X,Y) :- B > 0, A1 is B, B1 is A mod B, fpb(A1, B1, X), !.

/* Bagian III */
/* Deklarasi Rules */
min([X],X).
min([Head|Xs],Min) :- min(Xs,PrevMin), PrevMin =< Head, Min is PrevMin.
min([Head|Xs],Min) :- min(Xs,PrevMin), PrevMin > Head, Min is Head.

max([X],X).
max([Head|Xs],Max) :- max(Xs,PrevMax), PrevMax >= Head, Max is PrevMax.
max([Head|Xs],Max) :- max(Xs,PrevMax), PrevMax < Head, Max is Head.

range(List,Range) :- min(List,Min), max(List,Max), Range is Max-Min.

count([],0).
count([Head|Xs],Count) :- count(Xs,PrevCount), Count is PrevCount+1.

sum([X],X).
sum([Head|Xs],Sum) :- sum(Xs,PrevSum), Sum is PrevSum+Head.

getIndex([Element|_], Element, 1).
getIndex([_|Xs],SearchedElement,Result) :- getIndex(Xs,SearchedElement,PrevResult), Result is PrevResult+1, !.

getElmt([X | _], 1, X).
getElmt([_ | T], Index, Elmt) :- Index > 1, U is Index - 1, getElmt(T, U, Elmt).
setElmt([X | T], 1, Y, [Y | T]).
setElmt([H | T], Index, Elmt, [H | W]) :- Index > 1, U is Index - 1, setElmt(T, U, Elmt, W).
swap(List, Index1, Index2, Result) :- getElmt(List, Index1, Elmt1), getElmt(List, Index2, Elmt2), setElmt(List, Index1, Elmt2, Temp), setElmt(Temp, Index2, Elmt1, Result).

splitList([List],Ganjil,Genap) :- List mod 2 =:= 1,Ganjil = [List],Genap = [].
splitList([List],Ganjil,Genap) :- List mod 2 =:= 0,Ganjil = [],Genap = [List].
splitList([List|B],Ganjil,Genap) :- List mod 2 =:= 0,splitList(B,O,E),Ganjil = O,Genap = [List|E].
splitList([List|B],Ganjil,Genap) :- List mod 2 =:= 1,splitList(B,O,E),Ganjil = [List|O],Genap = E.