Trabajo 1 sistope
Al recibir el nombre y el vector este lo recibe con la funcion getotp y los almacena en las variables u y v respectivamente. Luego se envian a la funcion getout para verificar si se encuentran en la base de datos, a partir de aqui hay 2 caminos:

  Estas en la base de datos: Te desplegara todas las opciones que hay pero solo podras acceder a las que tengas permiso

  No estas en la base de datos: No podras acceder a las operaciones con vector pero te dara la opcion de Registrarte e ir elijiendo 
    los permisos que deseas tener.

Para compilar el codigo y generar el archivo .exe se debe escribir:
  g++ trabajo1.cpp -o trabajo1

Para ejecutar el .exe generado tras compilar se debe escribir: 
  trabajo1 -u "{username}" -v "{vector}" -f "{ruta}" -t "{texto}"
Donde username es Nombre y apellido con mayusculas al principio y sin caracteres especiales.
El vector se escribe de la forma 3;6;1;7;12 (Se transformara a <3,6,1,7,12>)

La base de datos (Archivo db.txt) se estructura de la forma {username};{permisos}
como por ejemplo: 
  Vicente Alves;1,3,4 
