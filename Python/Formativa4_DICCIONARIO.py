def generaDiccionario(Nombre,Fechas):
    D = {}
    c=0
    for i in Nombre:
        D[i]=Fechas[c]
        c+=1
    return D

def chequeaFecha(D,fecha):
    cumpleañeros = 0
    for i in D:
        if(D[i]==fecha):
            if(cumpleañeros==0):
                print(f"Feliz cumpleaños a {i}",end="")
                cumpleañeros += 1
            else:   
                print(", "+i,end="")
    if(cumpleañeros == 0):
        print("No hay nadie de cumpleaños esa fecha :[")      

def main(): 
    #los nombres y las fechas están en relación 1:1, 
    # #por lo que el cumpleaños de listaNombres[3] es listaFechas[3] y así sucesivamente. 
    listaNombres = ["Juan Lopez", "Juanito Carretera", "Carlitos Lechuga", "Pablo Jimenez", "Felipe Maldonado", "Matilda Bruja", "Mario Mario", "Luigi Mario", "Papara para", "Jorge Cohetes"]
    listaFechas = ["06/02","03/10","06/11","03/10", "22/08", "21/05","21/05","21/05","04/01","06/02"]
    d = generaDiccionario(listaNombres, listaFechas) 
    fecha = input("Ingrese fecha a revisar (dd/mm): ") 
    chequeaFecha(d,fecha) #chequea la fecha e imprime el resultado

main()