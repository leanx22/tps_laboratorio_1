/*
 * utilidades.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Leandro
 */
#include <stdlib.h>
#include <stdio.h>


#ifndef UTILIDADES_H_
#define UTILIDADES_H_
#endif /* UTILIDADES_H_ */

/// @param debito variable en donde se guardo guardado el resultado del precio al pagar con debito.
/// @param credito variable en donde se guardo el resultado del precio al pagar con credito.
/// @param bitcoin variable en donde se guardo el resultado del precio al pagar con bitcoins.
/// @param unitario variable en donde se guardo el precio unitario del vuelo.
/// Se le pasa a la funcion aquellas variables en donde previamente se guardaron esos datos para mostrarlos.
void mostrarResultados(float* debito, float* credito, float* bitcoin, float* unitario);
