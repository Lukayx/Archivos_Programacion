import random
victoria=0
derrota=0
num = []
for i in range(5):
    num.append(random.randint(1,10))

print("Pensare en un numero del 1 al 10. Si te acercas 2 posiciones, ganas tú, de lo contrario gano yo")
for i in range(5):
    x = int(input("ingresa tu numero:"))
    if(x>=num[i]-2 and x<=num[i]+2):
        print(f"el numero era {num[i]}, ganaste")
        victoria+=1
    else:
        print((f"el numero era {num[i]}, gane yo"))
        derrota+=1
if(victoria>derrota):
    print("tú ganaste la partida")
else:
    print("no vale la pena que sigamos jugando, yo gané la partida")