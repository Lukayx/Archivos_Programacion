lista1=[]
for i in range(10):
    lista1.append([])   
    for j in range(10):
        x = 135 + (70*i)
        y = 120 + (60*j)
        lista1[i].append([x,y,0])
print(lista1)