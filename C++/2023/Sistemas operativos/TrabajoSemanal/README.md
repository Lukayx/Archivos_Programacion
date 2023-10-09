|===========================|
|TRABAJO SISTEMAS OPERATIVOS|
|===========================|

---------------------------------------------------------------------------------------------------------------------------------------------
DESCRIPCION GENERAL:

Esta aplicación cuenta con un menú en el cual podrá seleccionar varias opciones, el acceso a estas opciones dependerá de los permisos que posea el usuario, estos permisos serán dados por el perfil de usuario que elijío al registarse. Las unicas opciones que no requieren permisos son la 0, 8 y 9. 

Para compilar el programa debe situarse en la carpeta principal del proyecto, abrir el bash ahí y luego escribir:
      make -f MAKEFILE
      cd Src (AQUI PODRÁ EJECUTAR EL SIGUIENTE PASO)

Para ejecutar el archivo "main" generado tras compilar se debe escribir siguiendo la siguinte estructura: 
      ./main -u "{username}" -v "{vector}" -f "{ruta}" -t "{texto}" -i "{input}" -o "{output}"

  u: nombre de usuario
  v: vector dado por linea de comando (Se escribe de la forma: 3;6;1;7;12)
  options: permisos a los que tiene acceso el usuario
  path: ruta dada por linea de comando
  text: texto dado por linea de comando
  input: ruta de archivo con al menos 1 MB de peso
  output: ruta de donde se creara el archivo con las frecuencias del conteo de palabras

EJEMPLO:
      ./main -u "Fernando Inzulza" -v "13;7;-4;7;25" -f "perro.txt" -t "soy un perrito" -i "../Files/IN/largeFile/large_file.txt" -o "../Files/outCuentaPalabras/large_file.txt"
---------------------------------------------------------------------------------------------------------------------------------------------


=============================================================================================================================================
Los ~Base de datos de Perfiles de Usuarios~ disponibles se encuentran en la carpeta "Database", el nombre del archivo es "userProfiles.txt"
-Su estructura es la siguiente:
      {NOMBREDE_DEL_PERFIL_DE_USUARIO};{NUMERO_DE_LAS_OPCIONES_A_LAS_QUE_TIENE_PERMISO}
      (EJEMPLO: userRookie:1,3,5,7,9)
=============================================================================================================================================


=============================================================================================================================================
La ~Base de datos de Usuarios~ se encuentra en la carpeta "Database", el nombre del archivo es "db.txt"
-Su estructura es la Siguiente:
      {NOMBRE_DEL_USUARIO};{NOMBRE_DEL_PERFIL_DE_USUARIO}
      (EJEMPLO: Erin Solstice;userRookie)
=============================================================================================================================================


=============================================================================================================================================
La ~Base de datos del Menu~ se encuentra en la carpeta "Database", el nombre del archivo es "menu.txt"
-Su estructura es la Siguiente:
      {NUMERO_OPCION};{FUNCION_DE_LA_OPCION};{PALABRA_CLAVE}
      (EJEMPLO: 8,Preparar datos para indice invertido,prepararIndiceInvertido)
=============================================================================================================================================


=============================================================================================================================================
Las ~Variables de Entorno~ (.env) del proyecto se encuentran en la carpeta principal llamada "TrabajoSemanal"
Su estrucura es la Siguiente:
      Las bases de datos comienzan con "DB_" y luego le sigue el nombre a la que correponde. (EJ: DB_MENU)
      EXTENTION = {extension del archivo que se busca los archivos de entrada}
      PATH_FILES_(IN/OUT) = {ruta correspondiente a las carpetas con archivos de entrada y salida}
      AMOUNT_THREADS = {Cantidad de hilos que se ocuparan para ciertas opciones}
      INVERTED_INDEX_FILE = {Ruta en la que se creara el archivo de Indice Invertido}
=============================================================================================================================================