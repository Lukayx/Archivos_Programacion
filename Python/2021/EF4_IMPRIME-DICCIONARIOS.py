def asigna_conceptos(alumnos,conceptos):
    ''' retorna un diccionario con los estudiantes de un curso evaluados con un concepto de acuerdo a su nota'''
    D = {}
    for est in alumnos:
        for conc in conceptos:
            lista=conceptos[conc]
            if alumnos[est]>=lista[0] and alumnos[est]<=lista[1]:
                D[est]=conc
    return D

def imprime_diccionario(D):
    print("-"*30)
    for i in D:
        print(str(i).ljust(15) + str(D[i]).rjust(15))

def main():
    mapeo_conceptos = {'Muy bien' : [6.0, 7.0], 'Bien' : [5.0,5.9], 'Suficiente' : [4.0, 4.9], 'Insuficiente' : [3.0, 3.9], 'Deficiente' : [2.0,2.9], 'Muy deficiente' : [1.0,1.9]}
    
    curso1 = {'Roberto' : 1.3, 'Carla' : 4.2, 'Andrés' : 2.4, 'Josefina' : 6.1}
    curso2 = {'Matías' : 4.8, 'Susana': 5.3, 'Marcelo': 3.8}
    #imprime_diccionario(mapeo_conceptos)
    # datos de prueba
    imprime_diccionario(curso1)
    imprime_diccionario(asigna_conceptos(curso1,mapeo_conceptos))
    imprime_diccionario(curso2)
    imprime_diccionario(asigna_conceptos(curso2,mapeo_conceptos))


main()
