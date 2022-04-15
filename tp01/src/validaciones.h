/*
 * validaciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>

/// @param minimo Pide el minimo numero que el usuario podra ingresar.
/// @param maximo Pide el maximo numero que el usuario podra ingresar.
/// @return la funcion retorna el flotante ingresado validando que no sea ni mayor ni menor a lo que se quiere.
float pedirValidarFloat(float minimo, float maximo);

/// @param precioAero Puntero
/// @param precioLtm Puntero
/// La funcion pide dos direcciones de memoria en la cual se guardaran los precios de dos vuelos (en este caso Aerolineas y LATAM)
/// validando que no sean menores a 1.
void pedirValidarPrecio(float* precioAero, float* precioLtm);






#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#endif /* VALIDACIONES_H_ */
