/*
 * ArrayPassenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"

int idGenerator(int * counter)
{
	int ret = -1;

	if(counter !=NULL)
	{
		*counter+=1;
		ret = *counter;
	}

	return ret; //A la hora de dar de alta, se verificara si ret en -1, si ese es el caso isEmpty quedara en true y se cancelara la carga para reintentarla.
}

int initPassengers(ePassenger* list, int len)
{
	int ret = -1;

	if(list != NULL && len>0)
	{
		for(int i=0;i<len;i++){
			list[i].isEmpty = 1;
		}
		ret = 0;
	}
	return ret;
}

int addPassenger(ePassenger* list,int len,int id,char name[],char lastName[],float price,int passengerType,char flycode[])
{
	int ret =-1;
	int freeSpace;
	int disponible;

	if(list !=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				freeSpace = i;
				disponible = 1;
				break;
			}
			else if(i==len) //Si termina de recorrer y no hay mas espacios no se permite carga.
			{
				disponible = -1;
				break;
			}
		}

		if(disponible == 1)
		{
			list[freeSpace].id = id;
			strcpy(list[freeSpace].name, name);
			strcpy(list[freeSpace].lastName, lastName);
			list[freeSpace].price = price;
			list[freeSpace].passengerType = passengerType;
			strcpy(list[freeSpace].flyCode, flycode);

			/*Solo si se genero correctamente el id [es decir, si no retorno -1] se actualizara la flag isEmpty,
			 * en caso contrario queda igual...
			 *(lo cual permite que el slot pueda ser usado, y addPassenger retorna error[-1]).
			 */
			if(id != -1)
			{
				list[freeSpace].isEmpty = 0;
				ret = 0;
			}
		}
	}
	return ret;
}

int findPassengerById(ePassenger*list,int len,int id)
{
	int ret=-1;

	if(list != NULL && len>0 && id>=100)
		for(int i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				ret = i;
			}
		}
	return ret;
}

int removePassenger(ePassenger*list,int len, int id)
{
	int ret = -1;

	if(list != NULL && len>0 && id>=100)
		for(int i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				list[i].isEmpty = 1;
				ret = 0;
			}
		}

	return ret;
}

int printPassengers(ePassenger*list, int len)
{

	if(list != NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("\n");
				printf("\nNombre: %s", list[i].name);
				printf("\nApellido: %s", list[i].lastName);
				printf("\nID: %d", list[i].id);
				printf("\nPrecio: %.2f", list[i].price);
				printf("\nEstado del vuelo: %d", list[i].statusFlight);
				printf("\nCodigo del vuelo: %s", list[i].flyCode);
				printf("\nTipo de pasajero: %d", list[i].passengerType);
			}
		}
	}

	return 0;
}
