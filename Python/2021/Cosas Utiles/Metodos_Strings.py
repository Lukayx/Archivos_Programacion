text = "el@@@perrito@@@lindo@@@:) "
Text = "EL PERRITO LINDO"
myTuple = ("John", "Peter", "Vicky")

text.capitalize() # ? Transforma la cadena a mayusculas ? # 

Text.casefold() # ? Transforma la cadena a minusculas, es parecida a .lower pero esta es mucho mas agresiva en cuanto a encontrar caracteres ? #

text.center(50) # ? Centra el texto segun cuanto ingreces ? #

text.count("perrito") # ? devuelve el número de veces que aparece un valor especificado en la cadena ? #
# ! SINTAXIS: string.count(value, start, end) ! # 

text.encode() # ? Devuelve un texto extraño ? #

text.endswith("X") # ? Devuelve True o False si el la cadena termina en el caracter introducido ? #

text.find("lindo") # ? Devuelve el indice en el que encuentra lo que buscaba ? #
# ! La unica diferencia de este metodo con el .index es que esta devuelve -1 si no encuentra el valor ! #

text.index("lindo") # ? Devuelve el indice en el que encuentra lo que buscaba ? # 

text.isalnum() # ? devuelve True si todos los caracteres son alfanuméricos (alfabeto y números) ? #

text.isascii() # ? devuelve True si todos los caracteres son caracteres ascii (az) ? #

text.isdecimal() # ? devuelve True si todos los caracteres son decimales (0-9)(se utiliza en objetos Unicode) ? #

text.isdigit() # ? devuelve True si todos los caracteres son dígitos (En un string); de lo contrario, False ? #

text.isidentifier() # ? devuelve True si la cadena es un identificador válido; de lo contrario, False ? #
# ! Una cadena se considera un identificador válido si solo contiene letras alfanuméricas (az) y (0-9), o guiones bajos (_) ! #
# ! Un identificador válido no puede comenzar con un número ni contener espacios ! #

text.islower() # ? devuelve True si todos los caracteres están en minúsculas; de lo contrario, False ? #

text.isnumeric() # ? devuelve True si todos los caracteres son numéricos (0-9); de lo contrario, False ? #
# ! "-1"y "1.5"no se consideran valores numéricos, porque todos los caracteres de la cadena deben ser numéricos, y el - y el . no lo son ! # 

text.isspace() # ? devuelve True si todos los caracteres de una cadena son espacios en blanco; de lo contrario, False ? #

text.istitle() # ? devuelve Verdadero si todas las palabras de un texto comienzan con una letra mayúscula Y el resto de la palabra son letras minúsculas ? # 
# ? de lo contrario, Falso ? #

Text.isupper() # ? devuelve True si todos los caracteres están en mayúsculas; de lo contrario, False ? #

"#".join(myTuple) # ? El join() método toma todos los elementos en un iterable y los une en una cadena ? # 
# ! Se debe especificar una cadena como separador ! #

text.lower() # ? Transforma la cadena a minusculas ? #

text.strip() # ? Quita los espacios en blanco de la derecha y izquierda ? #
# * si colocas una 'l' (left) o 'r' (right) removera los espacios del lugar correspondiente * #

text.replace("texto a remplazar","texto que quieres") # ? reemplaza una frase especificada con otra frase especificada ? #

# text.rindex(# palabra a buscar entre comillas #) # ? encuentra la ÚLTIMA aparición del valor especificado ? #
# * genera una excepción si no se encuentra el valor * #

text.rsplit(",") # ? divide una cadena en una lista, comenzando por la derecha. ? #

x = text.split("@@@") # ? divide una cadena en una lista. ? #
# * Puede especificar el separador, el separador predeterminado es cualquier espacio en blanco. * #
print(x) # ! Ejecutar para ver ejemplo ! #

text.splitlines() # ? divide una cadena en una lista. La división se realiza en los saltos de línea ? # 
# ! colocando \n en el string ! #

text.startswith("perrito") # ? devuelve True si la cadena comienza con el valor especificado; de lo contrario, False ? #
# ! SINTAXIS: string.startswith(value, start, end) ! #

text.swapcase() # ? devuelve una cadena donde todas las letras mayúsculas son minúsculas y viceversa ? #

text.title() # ? devuelve una cadena donde el primer carácter de cada palabra está en mayúsculas. Como un encabezado o un título ? #
# * Si la palabra contiene un número o un símbolo, la primera letra posterior se convertirá a mayúsculas. * #

text.upper() # ? devuelve una cadena donde todos los caracteres están en mayúsculas. ? #
# * Los símbolos y números se ignoran * #

#text.zfill() # ? agrega ceros (0) al comienzo de la cadena, hasta que alcanza la longitud especificada ? #
# ! Si el valor del parámetro len es menor que la longitud de la cadena, no se realiza ningún llenado. ! #
# ! SINTAXIS: string.zfill(len) ! #