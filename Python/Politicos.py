def main():
    while True:
        try:
            nombre_archivo = input("Ingrese el nombre del archivo con las firmas: ")
            firmas = open(nombre_archivo, 'r')
            datos_archivo = firmas.readlines()
            firmas.close()
            break
        except FileNotFoundError:
            print(f"El Archivo {nombre_archivo} no existe.")
    firmas_partido={}

    for i in range(len(datos_archivo)):
        data_candidato = datos_archivo[i].split(",")
        firmas = int(data_candidato[2])
        if firmas >= 20000:
            if data_candidato[1] in firmas_partido:
                firmas_partido[data_candidato[1]] += firmas
            else:
                firmas_partido[data_candidato[1]] = firmas
    print(firmas_partido)
    for partido in firmas_partido:
        outfile = open(partido+".csv","w")
        for i in range(len(datos_archivo)):
            data_candidato = datos_archivo[i].split(",")        
            firmas = int(data_candidato[2])
            if firmas >= 20000 and data_candidato[1] in partido:
                outfile.write(data_candidato[0]+","+data_candidato[2])
        outfile.write(str(firmas_partido[partido]))
        outfile.close()

main()