print("<---- 0 = NO ; 1 = SI ---->")
print()

A = int(input("¿Tiene 3 o mas promedios rojos? "))
while(A>1 or A<0):
    A = int(input("¿Tiene 3 o mas promedios rojos? "))

B = int(input("¿Se porta bien? "))
while(B>1 or B<0):
    B = int(input("¿Se porta bien? "))

C= int(input("¿Se come la comida? "))
while(C>1 or C<0):
    C = int(input("¿Se come la comida? "))

if(A==0 and B==1 and C==1):
    print("TA BIEN")
else:
    print("Ta mal")












b=int(input("Numero 1: "))
n=int(input("Numero 2: "))
m=int(input("Numero 3: "))

if(abs(b-n)==1 and abs(n-m)==1):
    print("Los 3 numeros son CONSECUTIVOS")
else:
    if(abs(b-n)==1 and not(abs(n-m)==1) or abs(n-m)==1 and not(abs(b-n)==1)):
        print("AAA")
