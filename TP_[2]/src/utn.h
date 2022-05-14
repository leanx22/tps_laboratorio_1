#ifndef UTN_H_
#define UTN_H_
#endif /* UTN_H_ */
//HH

/// @param pResultado Variable donde se va a guardar el valor ingresado(si es correcto).
/// @param mensaje Lo que imprime al pedir el numero.
/// @param mensajeError
/// @param minimo El numero mas pequenio admitido
/// @param maximo El numero mas grande admitido
/// @param reintentos Cantidad de veces que se puede reintentar antes de dar error.
/// @return Retorna -1 si NULL, sin reintentos o caracter no numerico, 0 si OK.
int utn_pedirInt(int*pResultado,char*mensaje,char*mensajeError,int minimo,int maximo,int reintentos);

/// @brief Esta funcion pide una cadena al usuario y verifica que to.do sean letras, si esto es asi copiara lo ingresado al array indicado como parametro.
/// @param array Array de caracteres donde se almacenara lo ingresado SOLO SI SE VALIDA correctamente.
/// @param mensaje El mensaje con el que se le pedira los datos al usuario.
/// @param tamanio Tamanio maximo de la cadena. (no debe ser mayor a lo declarado).
/// @return retornara 0 si finalizo correctamente o -1 si hubo error.
int utn_getStr(char array[], char*mensaje,char*mensajeError,int tamanio,int reintentos);

/// @brief Guarda en un array de caracteres el numero, utilizo la funcion esNumerica para
/// verificar que todos los valores sean numericos y en caso de ser asi, lo convierto en int con ATOI().
/// @param resultado Punt a variable donde se va a guardar el numero como long int.
/// @param mensaje Lo que se le mostrara el usuario al llamar la funcion.
/// @param mensajeError En caso de que el usuario ingrese un valor NO numerico.
/// @param reintentos Cantidad de veces que la funcion tolera el ingreso de datos incorrectos antes de retornar error.
/// @return La funcion retornara 1 si fue exitoso o 0 si hubo error.
int utn_getTelefono(long*resultado, char*mensaje,char*mensajeError,int reintentos);

/// @brief Esta funcion pide un flotante, el ingreso lo guarda en un array y luego verifica si contiene algun caracter que no sea numerico o '.'
/// luego utiliza la funcion atof para convertir el array en flotante.
/// @param pResultado puntero variable donde se guardara el ingreso una vez validado.
/// @param mensaje Lo que se le mostrara al usuario
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return Retorna -1 si lo ingresado no es valido o si NULL, 0 si to.do sale bien.
int utn_pedirFloat(float* pResultado, char*mensaje,char*mensajeError, int minimo,int maximo, int reintentos);


