/*
 * utn.c
 *
 *  Created on: 29 abr. 2022
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

static int myGets(char* cadena, int longitud);
static int getInt(int* pResultado);
static int esNumerica(char* cadena);

static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1]== '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno=0;
	}

	return retorno;
}

static int esFlotante(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		while(cadena[i] != '\0')
		{
			if (cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] != '.')
				{
					printf("Caracter invalido en la posicion %d !", i+1);
					retorno = 0;
					break;
				}
			}
			i++;
		}

	}

	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];
	//fflush(stdin);

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int esNumerica(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena)>0)
	{
		while(cadena[i] != '\0')
		{
			if (cadena[i] < '0' || cadena[i] > '9'){
				retorno = 0;
				break;
			}
			i++;
		}

	}

	return retorno;
}

int utn_pedirInt(int*pResultado,char*mensaje,char*mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno =-1;
	int bufferInt;

	while (reintentos>0)
	{
		reintentos--;
		printf("\n");
		printf("%s", mensaje);
		if(getInt(&bufferInt)==0){
			if(bufferInt>=minimo && bufferInt<=maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int utn_getStr(char array[], char*mensaje,char*mensajeError,int tamanio,int reintentos)
{
	int retorno=-1;
	char buffer[tamanio];
	int i=0;

	if(array != NULL && mensaje != NULL)
	{
		while(reintentos>0)
		{
			printf(mensaje);
			fflush(stdin);
			myGets(buffer, tamanio);
			while(buffer[i]!='\0')
			{
				//printf("\n iteracion %d", i); //DEBUG
				if(isalpha(buffer[i])==0)
				{
					reintentos--;
					printf(mensajeError);
					printf("\n");
					system("PAUSE");
					break;
				}else if(buffer[i+1]=='\0')
				{
					//printf("\nen la pos %d termine y entre al else", i); //DEBUG
					strcpy(array, buffer);
					retorno = 0;
					reintentos = 0;
					break;
				}
				i++;
			}
		}
	}

	return retorno;
}

int utn_getTelefono(long*resultado, char*mensaje,char*mensajeError,int reintentos)
{
	int retorno = 0;
	char numeroTelefono[11];
	system("CLS");

	//if(*resultado != NULL && *mensaje != NULL && *mensajeError != NULL && reintentos > 0)
	//{
		while(reintentos != 0)
		{
			printf(mensaje);
			fflush(stdin);
			fgets(numeroTelefono, 11, stdin);

			if(esNumerica(numeroTelefono)!=0)
			{
				*resultado = atoi(numeroTelefono);
				retorno = 1;
				break;
			}else
			{
				printf(mensajeError);
				printf("\n");
			}
			reintentos--;
		}
	//}else{printf("\nNULL o intentos = 0!");}
	return retorno;
}

int utn_pedirFloat(float* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno =-1;
	float bufferResultado;
	char bufferFloat[32];

		while (reintentos>0)
		{
			printf("\n");
			printf("%s", mensaje);

			fflush(stdin);
			myGets(bufferFloat, 32);
			reintentos--;

			if(esFlotante(bufferFloat)==1)
			{
				bufferResultado = atof(bufferFloat);
				if(bufferResultado>minimo && bufferResultado<maximo)
				{
					*pResultado = bufferResultado;
					retorno = 0;
					break;
				}else{printf("\nEl numero debe ser minimo %d, y maximo: %d",minimo,maximo);}
			}else
			{
				printf("\n");
				printf(mensajeError);
				printf("\n");
				system("PAUSE");
			}
		}

		return retorno;
}

/*TODO
 *-funcion para pedir/validar un float.
 *-funcion para pedir un mail (verificando que tenga arroba).
 *-funcion para inicializar arrays!.
 *-funcion para buscar Ids y pasar indice.(esta en estructuras9)
 *-funciones restantes que estan en el pdf y que crea que son necesarias.
 */
