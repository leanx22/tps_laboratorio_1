/*
 * validaciones.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"



float pedirValidarFloat(float minimo, float maximo)
{
	float retorno;

	scanf("%f", &retorno);
	while(retorno < minimo || retorno > maximo)
	{
		printf("\nFuera de limites, reingrese: ");
		scanf("%f", &retorno);
	}

	return retorno;
}


void pedirValidarPrecio(float* precioAero, float* precioLtm)
{
	float ingresoAero;
	float ingresoLtm;

	printf("\nIngrese el precio de Aerolineas: ");
	scanf("%f", &ingresoAero);

	printf("\nIngrese el precio de LATAM: ");
	scanf("%f", &ingresoLtm);

	while(ingresoAero < 1 || ingresoLtm < 1)
	{
		printf("\nLOS PRECIOS NO PUEDEN SER GRATIS O NEGATIVOS! ");
		printf("\nReingrese el precio de Aerolineas: ");
		scanf("%f", &ingresoAero);

		printf("  \nReingrese el precio de LATAM: ");
		scanf("%f", &ingresoLtm);
	}

	*precioAero = ingresoAero;
	*precioLtm = ingresoLtm;
}
