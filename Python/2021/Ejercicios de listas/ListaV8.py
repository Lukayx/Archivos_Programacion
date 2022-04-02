x = 160
y=90
tablero = []

for i in range(10):
    tablero.append([])
    for j in range(10):
        x = 160 + (50*i)
        y = 90 + (50*j)
        tablero[i].append([x,y,0])

print(tablero)