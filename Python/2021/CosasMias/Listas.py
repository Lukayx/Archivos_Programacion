array = ['perro', 7, True, 7.77,[1,2,3]]
colores = ['white', 'red', 'cian']
lista_de_numeros = list((1,2,3,4))
r = list(range(1,11))

#----------------------TE DICE EL TIPO DE ELEMENTO-------------------#

##print(type(lista_de_numeros))

#------------------TE DICE LA LONGITUD DE LA LISTA-------------------#

##print(len(colores))

#---BUSCA UN ELEMENTO SEGUN EL INDICE (AL SER NEGATIVO VA DE DERECHA A IZQUIERDA)---#

##print(colores[-1])

#-------------BUSCA UN EL ELEMNTO MENCIONADO EN LA LISTA-------------#

##print('red' in colores)

#----------REEMPLAZA UN ELEMENTO EN SEGUN EL INDICE ESCRITO----------#

##colores[1] = 'yellow'

#---------------------AGREGA UN ELEMENTO AL ARRAY--------------------#
#-----------si tratas de agregar mas se crea una sub_lista-----------#

##colores.append('violet')

#------------AGREGA VARIOS ELEMENTOS AL ARRAY-------------#

##colores.extend(['violet', 'black'])

#-----------INSERTA UN ELEMENTO SEGUN EL INDICE ESCRITO-----------#

##colores.insert(1, 'perro')

#---LEN PREGUNTA LA LONGITUD DE LA LISTA Y EL .INSERT COLOCA EL ELEMENTO AHÍ---"

##colores.insert(len(colores), 'perro')

#----------------QUITA EL ULTIMO ELEMENTO(si es que no señalas el indice)-----------------#

##colores.pop()

#---------------QUITA EL ELEMENTO ESPECIFICADO---------------#

##colores.remove('red')

#----------------------LIMPIA LA LISTA-----------------------#

##colores.clear()

#------------ORDENA LA LISTA EN ORDEN ALFABETICO-------------#

#reverse=True para ordenarlo a la inversa
##colores.sort()

#----------BUSCA EL INDICE DEL ELEMENTO MENCIONADO-----------#

##print(colores.index('red'))

#---BUSCA UN ELEMENTO CUANTAS VECES SE REPITE EN CASO DE QUE HAYA MAS QUE 2---#

##print(colores.count('red'))

for i in range (0,5):
    print(colores[i])

print(colores)