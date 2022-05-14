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
#include "utn.h"

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
	{
		printf("\nSEARCHING...");
		for(int i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				ret = i;
			}
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

//No de array passenger.

int modifyPassenger(ePassenger*list,int listLen)
{
	int ret = 0;
	int idToSearch;
	int indexValue;
	int selectedOption;
	int continueEdit = 1;

	printf("MODIFY PASSENGER");
	utn_pedirInt(&idToSearch,"\nEnter the passenger ID: ", "\nERROR!",100,2100,3);

	indexValue = findPassengerById(list,listLen,idToSearch);
	if(indexValue != -1)
	{
		while(continueEdit == 1)
		{
			printf("\n");
			printf("\nWHAT DO YOU WANT TO MODIFY?: ");
			printf("\n(Can not be edited)-->ID: %d", list[indexValue].id);
			printf("\n1) Name: %s", list[indexValue].name);
			printf("\n2) Last Name: %s", list[indexValue].lastName);
			printf("\n3) Price: %.2f", list[indexValue].price);
			printf("\n4) Flight status: %d", list[indexValue].statusFlight);
			printf("\n5) Flight Code: %s", list[indexValue].flyCode);
			printf("\n6) Passenger Type: %d", list[indexValue].passengerType);

			if(utn_pedirInt(&selectedOption,"", "\nERROR!",1,6,3)==0)
			{
				switch(selectedOption)
				{
				case 1:
					system("CLS");
					if(utn_getStr(list[indexValue].name,"\nNew name: ","ERROR!", 51, 5)==0)
					{
						printf("\n\x1b[32mCHANGE OK AND SAVED!\x1b[0m");
						utn_pedirInt(&continueEdit,"\nContinue editing?\n0-NO.\n1-YES.", "\nERROR!",0,1,3);
					}else
					{
						printf("\n\x1b[31mthere was an error!, changes are NOT going to be saved!\x1b[0m");
						system("PAUSE");
					}
					break;
				case 2:
					system("CLS");
					if(utn_getStr(list[indexValue].lastName,"\nNew Last Name: ","ERROR!", 51, 5)==0)
					{
						printf("\n\x1b[32mCHANGE OK AND SAVED!\x1b[0m");
						utn_pedirInt(&continueEdit,"\nContinue editing?\n0-NO.\n1-YES.", "\nERROR!",0,1,3);
					}else
					{
						printf("\n\x1b[31mthere was an error!, changes are NOT going to be saved!\x1b[0m");
						system("PAUSE");
					}
					break;

				}


			}

		}

	}

	return ret;
}
