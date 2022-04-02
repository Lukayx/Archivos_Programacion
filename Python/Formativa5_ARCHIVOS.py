def escribe_en_archivo(lnombres,lnotas,nombre_archivo):
    '''escribe en archivo nombre_archivo los nombres y notas de los estudiantes en formato CSV'''
    try:
        archivo_salida = open(nombre_archivo, 'x')
        for i in range(len(lnombres)):
            archivo_salida.write(f"{lnombres[i]},{lnotas[i]}\n")
        archivo_salida.close()
    except FileExistsError:
        print(f"El Archivo {nombre_archivo} ya existe.")

def main():
    estudiantes = ['Carla', 'Marcelo', 'Andrea']
    notas = [5.4,4.8,2.3]
    escribe_en_archivo(estudiantes,notas,'notas_curso.csv')
    print(str(len(estudiantes))+' registros procesados')

main()

