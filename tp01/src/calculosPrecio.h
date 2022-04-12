/*
 * calculosPrecio.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef CALCULOSPRECIO_H_
#define CALCULOSPRECIO_H_
#endif /* CALCULOSPRECIO_H_ */

/// @param Pide un precio para hacer un descuento del 10%.
/// @return La funcion retornara el resultado de la operacion.
float calculoDebito(float precio);

/// @param Pide un precio para aplicar 25% de interes.
/// @return La funcion retornara el resultado de la operacion.
float calculoCredito(float precio);

/// @param Pide un precio.
/// @param kilometros: pide la distancia a recorrer para dividirla por el precio.
/// @return La funcion retornara el resultado de la operacion, la cual es el precio unitario precioxkilometro.
float calculoPrecioUnitario(float precio, int kilometros);

/// @param pide un precio.
/// @param pide un segundo precio.
/// @return la funcion retornara la diferencia entre ambos precios ingresados.
float calculoDiferencia(float precioAero, float precioLatam);

/// @param precio: se pide un valor monetario.
/// @return La funcion retornara el valor del parametro convertido a bitCoin.
float pasajeBitcoin(float precio);

///
/// Funcion que realiza los calculos y muestra los resultados de la carga forzada.
void cargaForzada();
