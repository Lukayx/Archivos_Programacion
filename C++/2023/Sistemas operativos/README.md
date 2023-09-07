Trabajo 1 sistope

-----------------------------------------Archivo Main-----------------------------------------
Importa los archivos dataBaseManagement y menuOptions al principio del archivo, así no tiene que importar las librerias directamente ya que estan  
Al recibir el nombre, el vector, la ruta y el texto con la funcion getotp son verificados que sean correctos. Luego se envian a la funcion getout, donde se almacenan en el struct Usuario y se verifica si se encuentran en la base de datos. al mismo tiempo que se cargan las opciones del menu con un map que tiene un identificador (numero de la opcion) y un pair de un label y la funcion que va de acuerdo a la opcion elejida(con parametro del struct Usuario), a partir de aqui hay 2 caminos: 

  Estas en la base de datos: Te desplegara todas las opciones que hay pero solo podras acceder a las que tengas permiso

  No estas en la base de datos: No podras acceder a las operaciones con vector pero te dara la opcion de Registrarte e ir elijiendo los permisos que deseas tener.

---------------------------------Archivo dataBaseManagement-----------------------------------
Tiene las funciones que recolectan la informacion de la base de datos y hace un #import al archivo menuOptions

Las funciones son:

  Validation: Resibe un struct Usuario del cual usando el nombre que tiene verifica su existencia en la base de datos.

  signIn: Resibe un struct Usuario y el map con las opciones del menu. En caso de que no exista en la base de datos se le pregunta si quiere registrarse, si lo quiere hacerlo entonces tendra una serie de preguntas que le irán dando los permisos que usted quiera tener (cada pregunta tiene el label sacado del map para saber la opcion a la que tendra permiso), si no quiere entonces termina.

  userProfileAssignment: Funcion que retorna un vector con los permisos correspondientes y recibe 2 strings, el perfil de usuario y el string de la base de datos (Sacada el .env). busca en la base de datos de los perfiles de usuario el que se pasó por los parametros de la funcion y luego le asigna los permisos de ese perfil al vector que será retornado.

  confirmPermiss: recibe un struct Usuario y un entero opcion. El struct usuario tiene sus permisos sacados de la base de datos por lo que recorre estos permisos y busca si se encuentra la opcion elejida, si la encuentra entonces tiene permiso para usar esa opcion, en caso contrario no lo tiene.

  crearMapa: recibe un struct usuario. Se crea un map con una key de primera y un pair de segunda con un string y una funcion de parametros Usuario. Luego lee la base de datos del menu y separa cada linea con las ',' y agrega el numero de opcion en la key del map. luego agrega el label en el string del pair y con el identificador del ultimo getline se le agrega la funcion correspondiente (usando funciones lambda)

  leerEnv: No recibe parametros, el lee el .env e identifica cuales son las bases de datos. Despues, ocupando un unordered_map de <string,string> con el primero el nombre de la base de datos correspondiente y de segunda la ruta en la que se encuentra

-----------------------------------Archivo menuOptions---------------------------------------

Tiene todas las opciones del menu (salir, sumatoria, promedio, moda, contar, crearArchivo, agregarTexto y opcionIndefinida). La mayoria recibe el parametro Usuario a excepcion de las funciones salir y opcionIndefinida.

También, aqui está definido el struct Usuario con los atributos u,path y text de tipo string, v y options siendo vectores de tipo int.

  u: nombre de usuario
  v: vector dado por linea de comando
  options: permisos a los que tiene acceso el usuario
  path: ruta dada por linea de comando
  text: texto dado por linea de comando
  input: ruta de archivo con al menos 1 MB de peso
  output: ruta de donde se creara el archivo con las frecuencias del conteo de palabras

Para compilar el codigo y generar el archivo .exe se debe escribir:
  g++ main.cpp -o main

Para ejecutar el .exe generado tras compilar se debe escribir: 
  main -u "{username}" -v "{vector}" -f "{ruta}" -t "{texto}" -i "{input}" -o "{output}"
Ejemplo:
  main -u "Fernando Inzulza" -v "13;7;-4;7;25" -f "perro.txt" -t "soy un perrito" -i "large_file.txt" -o "perrito/resultado.txt"
Donde username es Nombre y apellido con mayusculas al principio y sin caracteres especiales.
El vector se escribe de la forma 3;6;1;7;12 (Se transformara a <3,6,1,7,12>)
La ruta puede ser escrita como solo el nombre del archivo y su extension para crearlo en la misma carpeta o una mas especifica para crearla en otro lugar.
El texto será lo que quieres escribir dentro del archivo. 
El input será una ruta donde leerá un archivo que debe ser de al menos 1 MB
El output es la ruta en donde se generara un archivo de frecuencia de palabras en el que se usó el input

La base de datos (db.txt) se estructura de la forma {username};{userProfile}
como por ejemplo: 
  Vicente Alves;admin

Las opciones del menú (menu.txt) se estructura de la forma {numeroOpcion},{Label},{identificador}
como por ejemplo: 
  5,Crear archivo de texto,crearArchivo

Los perfiles de usuario (userProfile.txt) se estructura de la forma {userProfile};{permisos} como por ejemplo:
  admin;1,2,3,4,5,6,7


AÑADIR .ENV 