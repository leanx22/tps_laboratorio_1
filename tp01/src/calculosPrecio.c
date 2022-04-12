/*
 * calculosPrecio.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculosPrecio.h"

float calculoDebito(float precio)
{

	float resultado;

	resultado = precio;
	resultado -= precio*10/100;

	return resultado;
}


float calculoCredito(float precio)
{
	float resultado;

	resultado = precio;
	resultado += precio*25/100;

	return resultado;
}


float pasajeBitcoin(float precio)
{
	float resultado;

	resultado = precio/4836581.70;

	return resultado;
}


float calculoPrecioUnitario(float precio, int kilometros)
{
	float resultado;

	resultado = precio/kilometros;

	return resultado;
}


float calculoDiferencia(float precioAero, float precioLatam)
{
	float resultado;

	if(precioLatam>precioAero)
		{
			resultado = precioLatam-precioAero;
		}
		else
		{
			resultado = precioAero-precioLatam;
		}

	return resultado;
}


void cargaForzada()
{

	float precioAerolineas = 162965;
	float precioLatam = 159339;
	int kilometros = 7090;

	float aeroDebito;
	float aeroCredito;
	float aeroBitCoin;
	float aeroUnitario;

	float latamDebito;
	float latamCredito;
	float latamBitCoin;
	float latamUnitario;

	long diferenciaPrecio;

	//inicializo las variables debito y credito con el precio original, para luego restarles el porcentaje del mismo.
	aeroDebito = precioAerolineas;
	aeroDebito -= precioAerolineas*10/100;

	aeroCredito = precioAerolineas;
	aeroCredito += precioAerolineas*25/100;

	aeroBitCoin = precioAerolineas/4836581.70;
	aeroUnitario = precioAerolineas/kilometros;

	latamDebito = precioLatam;
	latamDebito -= precioLatam*10/100;

	latamCredito = precioLatam;
	latamCredito += precioLatam*25/100;

	latamBitCoin = precioLatam/4836581.70;
	latamUnitario = precioLatam/kilometros;

	//Averiguo cual es el precio mayor y le resto el menor para calcular la diff.
	if(precioLatam>precioAerolineas)
	{
		diferenciaPrecio = precioLatam - precioAerolineas;
	}
	else
	{
		diferenciaPrecio = precioAerolineas - precioLatam;
	}

	system("CLS");
	printf("KM ingresados: %d", kilometros);

	printf("\nResultados forzados Aerolineas: ");
	printf("\nPrecio: %.2f", precioAerolineas);
	printf("\nPagando con DEBITO: %.2f", aeroDebito);
	printf("\nPagando con CREDITO: %.2f", aeroCredito);
	printf("\nPagando en BITCOIN: %.3f", aeroBitCoin);
	printf("\nPrecio por KM: %.2f", aeroUnitario);

	printf("\n\nResultados forzados LATAM: ");
	printf("\nPrecio: %.2f", precioLatam);
	printf("\nPagando con DEBITO: %.2f", latamDebito);
	printf("\nPagando con CREDITO: %.2f", latamCredito);
	printf("\nPagando en BITCOIN: %.3f", latamBitCoin);
	printf("\nPrecio por KM: %.2f", latamUnitario);

	printf("\nLa diferencia de precio entre ambos es de: %ld\n", diferenciaPrecio);
	system("PAUSE");
}
