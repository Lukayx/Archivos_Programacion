#include "../../Include/directorioArbol.h"
// Ruta prueba: //ruta: Files/Directory Files/dirarbol.dit
// compilar: g++ -std=c++17 listar2.cpp -o listar2 -ljsoncpp
// Función para validar la extensión del archivo
bool verificaRuta(std::string path){
  if (path.find_last_of('/') != std::string::npos) {
    size_t last = path.find_last_of('/');
    std::string directoryPath = path.substr(0, last);
    std::string nameFile = path.substr(last+1, path.length() - (last+1));
    if (!(fs::exists(directoryPath) && fs::is_directory(directoryPath))) {
      std::cout << "La ruta entregada no es válida." << std::endl;
      std::cout << "Se cerrará el proceso externo." << std::endl;
      return false;
    } else {
      if (nameFile.length() < 4 || nameFile.substr(nameFile.length() - 4) != ".dit") {
        std::cout << "La extensión del archivo es invalida, por favor, use un archivo '.dit'" << std::endl;
        exit(1);
      }
      std::ifstream archivo(path);
      if(!archivo.is_open()){
        std::cout << "El archivo no fue encontrado en la ruta entregada." << std::endl;
        std::cout << "Se cerrará el proceso externo." << std::endl;
        return false;
      }
      archivo.close();
    }
  } else {
    return false;
  }
  return true;
}

size_t findMatchingClosingBrace(const std::string& str, size_t startPos) {
    size_t openBraces = 0;
    size_t pos = startPos;

    while (pos < str.length()) {
        if (str[pos] == '{') {
            openBraces++;
        } else if (str[pos] == '}') {
            openBraces--;
            if (openBraces == 0) {
                return pos;
            }
        }
        pos++;
    }

    return std::string::npos;
}


void crearDirectorios(const std::string& rutaBase, const Json::Value& objetos) {
    if (objetos.isArray() || objetos.isObject()) {
        if (objetos.isArray()) {
            for (const auto& objeto : objetos) {
                const std::string tipo = objeto["tipo"].asString();
                const std::string nombre = objeto["nombre"].asString();

                if (tipo == "directorio") {
                    // Crear directorio
                    std::string rutaDirectorio = rutaBase + "/" + nombre;
                    std::filesystem::create_directory(rutaDirectorio);

                    // Llamar recursivamente para los objetos dentro del directorio
                    const Json::Value subobjetos = objeto["objetos"];
                    crearDirectorios(rutaDirectorio, subobjetos);
                } else if (tipo == "archivo") {
                    // Crear archivo
                    std::string rutaArchivo = rutaBase + "/" + nombre;
                    std::ofstream archivo(rutaArchivo);
                    if (archivo.is_open()) {
                        archivo << objeto["contenido"].asString();
                        archivo.close();

                        // Obtener permisos desde el JSON si están presentes
                        if (objeto.isMember("permisos") && objeto["permisos"].isArray()) {
                            const Json::Value permisos = objeto["permisos"];
                            // Verificar si hay al menos un permiso
                            if (!permisos.empty()) {
                                // Convertir permisos de JSON a modo octal
                                std::string permisosStr = "";
                                for (const auto& permiso : permisos) {
                                    permisosStr += permiso.asString();
                                }

								std::cout<<"-----------------ACA PERMISOS: "<< permisosStr << std::endl;
								std::cout<<"Para: "<<rutaArchivo<<std::endl;
								
								mode_t permisos = 0;								

								if(permisosStr == "escrituralectura"){
									permisos |= S_IRUSR | S_IWUSR;
									// Permisos para el grupo
									permisos |= S_IRGRP | S_IWGRP;
									// Permisos para otros
									permisos |= S_IROTH | S_IWOTH;
									chmod(rutaArchivo.c_str(), permisos);

								}else if(permisosStr == "lectura"){
									permisos = S_IRUSR;
									permisos |= S_IRGRP;
									permisos |= S_IROTH;
									chmod(rutaArchivo.c_str(), permisos);
								}else if(permisosStr == "escritura"){
									std::filesystem::perms permisos = std::filesystem::status(rutaArchivo).permissions();

									permisos &= ~std::filesystem::perms::owner_all;    
									permisos &= ~std::filesystem::perms::group_all;   
									permisos &= ~std::filesystem::perms::others_all;

									permisos |= std::filesystem::perms::owner_write;

									std::filesystem::permissions(rutaArchivo, permisos);
	
								}
                            }
                        }
                    } else {
                        std::cerr << "Error al crear el archivo: " << rutaArchivo << std::endl;
                    }
                }
            }
        } else { // Es un objeto único
            const std::string tipo = objetos["tipo"].asString();
            const std::string nombre = objetos["nombre"].asString();

            if (tipo == "directorio") {
                // Crear directorio
                std::string rutaDirectorio = rutaBase + "/" + nombre;
                std::filesystem::create_directory(rutaDirectorio);

                // Llamar recursivamente para los objetos dentro del directorio
                const Json::Value subobjetos = objetos["objetos"];
                crearDirectorios(rutaDirectorio, subobjetos);
            } else if (tipo == "archivo") {
                std::string rutaArchivo = rutaBase + "/" + nombre; // aca se crea el archivo
                std::ofstream archivo(rutaArchivo);
                if (archivo.is_open()) {
                    archivo << objetos["contenido"].asString();
                    archivo.close();

                    // Obtener permisos desde el JSON 
                    if (objetos.isMember("permisos") && objetos["permisos"].isArray()) {
                        const Json::Value permisos = objetos["permisos"];
                        // Verificar si hay al menos un permiso
                        if (!permisos.empty()) {
                            std::string permisosStr = "";
                            for (const auto& permiso : permisos) {
                                permisosStr +=permiso.asString();
                            }

							std::cout<<"-----------------ACA PERMISOS: "<< permisosStr << std::endl;
							std::cout<<"Para: "<<rutaArchivo<<std::endl;
                            
							mode_t permisos = 0;								

							if(permisosStr == "escrituralectura"){
								permisos |= S_IRUSR | S_IWUSR;
								// Permisos para el grupo
								permisos |= S_IRGRP | S_IWGRP;
								// Permisos para otros
								permisos |= S_IROTH | S_IWOTH;
								chmod(rutaArchivo.c_str(), permisos);

							}else if(permisosStr == "lectura"){
								permisos = S_IRUSR;
								permisos |= S_IRGRP;
								permisos |= S_IROTH;
								chmod(rutaArchivo.c_str(), permisos);

							}else if(permisosStr == "escritura"){
								std::cout<<"Paso a solo escritura"<<std::endl;
								//permisos = S_IWUSR;
								//permisos |= S_IWGRP;
								//permisos |= S_IWOTH;
								//chmod(rutaArchivo.c_str(), permisos);

								std::string comando = "chmod a-r \"" + rutaArchivo + "\"";
								system(comando.c_str());
		
							}
                        }
                    }
                } else {
                    std::cerr << "Error al crear el archivo: " << rutaArchivo << std::endl;
                }
            }
        }
    } else {
        std::cerr << "Error: objetos no es un array o un objeto JSON válido." << std::endl;
        std::cerr << "Contenido de objetos:\n" << objetos.toStyledString() << std::endl;
    }
}


// Función para crear la carpeta según la información en el archivo .dit
void carpetaObjetos(const std::string& rutaArchivo) {
    std::ifstream archivoDIT(rutaArchivo);
    if (!archivoDIT.is_open()) {
        std::cerr << "Error al abrir el archivo. Verifica que el archivo exista y tenga los permisos necesarios." << std::endl;
        return; 
    }

    // Leer el contenido del archivo y almacenarlo en una cadena
    std::string contenido((std::istreambuf_iterator<char>(archivoDIT)), std::istreambuf_iterator<char>());

    // Cerrar el archivo
    archivoDIT.close();

    std::cout << "Contenido del archivo:\n" << contenido << std::endl;

    // Buscar la posición de "dirBase" en la cadena
    size_t posDirBase = contenido.find("\"dirBase\":");
    if (posDirBase != std::string::npos) {
        // Encontrar la posición del primer '"' después de "dirBase"
        size_t posComillaInicio = contenido.find("\"", posDirBase + 10);
        if (posComillaInicio != std::string::npos) {
            // Encontrar la posición del segundo '"' después de "dirBase"
            size_t posComillaFin = contenido.find("\"", posComillaInicio + 1);
            if (posComillaFin != std::string::npos) {
                // Extraer la ruta base entre las comillas
                std::string rutaBase = contenido.substr(posComillaInicio + 1, posComillaFin - posComillaInicio - 1);

                // Verificar y corregir la rutaBase si termina con '/'
                if (!rutaBase.empty() && rutaBase.back() == '/') {
                    rutaBase.pop_back();
                }

                // Crear la carpeta en la rutaBase
                if (std::filesystem::exists(rutaBase)) {
                    std::cout << "La carpeta ya existe. Saliendo." << std::endl;
                } else {
                    // Intentar crear la carpeta
                    if (std::filesystem::create_directory(rutaBase)) {
                        std::cout << "La carpeta ha sido creada con éxito." << std::endl;

                        // Buscar la posición de "objetos" en la cadena
                        size_t posObjetos = contenido.find("\"objetos\":");
                        if (posObjetos != std::string::npos) {
                            // Encontrar la posición del primer '[' después de "objetos"
                            size_t posInicio = contenido.find("[", posObjetos);
                            // Encontrar la posición del último ']' antes del final de la cadena
                            size_t posFin = contenido.find_last_of("]");
                            if (posInicio != std::string::npos && posFin != std::string::npos && posInicio < posFin) {
                                // Extraer la cadena de objetos
                                std::string objetosStr = contenido.substr(posInicio + 1, posFin - posInicio - 1);

                                // Imprimir el contenido de objetos para depurar
                                std::cout << "Contenido de objetos:\n" << objetosStr << std::endl;

                                
								Json::Reader reader;
								Json::Value root;

								size_t pos = 0;
								size_t endPos = objetosStr.length();

								while (pos < endPos) {
									// Encontramos el próximo objeto JSON
									size_t openBrace = objetosStr.find('{', pos);
									size_t closeBrace = findMatchingClosingBrace(objetosStr, openBrace);

									if (openBrace != std::string::npos && closeBrace != std::string::npos) {
										// Extraemos el objeto JSON
										std::string jsonSnippet = objetosStr.substr(openBrace, closeBrace - openBrace + 1);
										if (reader.parse(jsonSnippet, root, false)) {
											// Imprimimos cada objeto JSON
											std::cout <<"Contenido del root:\n" << root << std::endl;
											crearDirectorios(rutaBase, root);
										} else {
											std::cerr << "Error al parsear un objeto JSON." << std::endl;
										}

										// Avanzamos a la siguiente posición después del cierre del objeto
										pos = closeBrace + 1;
									} else {
										// Si no encontramos más objetos, salimos del bucle
										break;
									}
								}
                            }
                        }
                    } else {
                        std::cerr << "Error al intentar crear la carpeta." << std::endl;
                    }
                }
            } else {
                std::cerr << "Error en el formato del archivo JSON: no se encontró la segunda comilla después de 'dirBase'." << std::endl;
            }
        } else {
            std::cerr << "Error en el formato del archivo JSON: no se encontró la primera comilla después de 'dirBase'." << std::endl;
        }
    } else {
        std::cerr << "Error en el formato del archivo JSON: no se encontró 'dirBase'." << std::endl;
    }
}

int main(int argc, char **argv){
    if (argc < 2) {
    std::cout << "Por favor, proporcione la ruta del archivo como argumento." << std::endl;
    return 0;
    }
    std::string path = argv[1];
    // Validar la extensión del archivo utilizando la función
    if(!verificaRuta(path)) return 0;

    // Llamar a la función carpetaObjetos
    carpetaObjetos(path);

    return 0;
}
