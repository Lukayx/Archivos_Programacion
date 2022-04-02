#cambia el nombre de este archivo poniendo tu nombre y apellidos

def main():
    while True:
        try:
            nombre_archivo = input("Ingrese el nombre del archivo a procesar: ")
            archivo = open(nombre_archivo, 'r')
            datos_archivo = archivo.readlines() # N°Boleta - Monto total venta - Rut Cliente
            archivo.close()
            break
        except FileNotFoundError:
            print("ERROR: el archivo no existe, intente nuevamente")
    datos_compra = {}
    for compras in datos_archivo:
        compras = compras.strip("\n")
        compras = compras.split(",")
        if compras[2]!="":
            datos_compra[compras[0]]=compras[2]
            
    print(datos_compra)
    lista={}
    while True:
        try:
            nombre_archivo = input("Ingrese el nombre del archivo de resultados: ")
            archivo = open(nombre_archivo+".csv", 'x')
            break
        except FileExistsError:
            print("ERROR: existe un archivo con ese nombre actualmente, intente nuevamente")
    for compras in datos_archivo:
        compras = compras.strip("\n")
        compras = compras.split(",")
        if compras[2]==datos_compra[compras[0]]:
            lista[compras[2]]=[

        print(compras)
    


main()
