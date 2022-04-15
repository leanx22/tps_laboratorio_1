/*
 * utilidades.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Leandro
 */

#include <stdlib.h>
#include <stdio.h>
#include "utilidades.h"

void mostrarResultados(float* debito, float* credito, float* bitcoin, float* unitario)
{
	printf("\nPagando con DEBITO: %.2f", *debito);
	printf("\nPagando con CREDITO: %.2f", *credito);
	printf("\nPagando en BITCOIN: %.3f", *bitcoin);
	printf("\nPrecio por KM: %.2f", *unitario);
}
