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
#include "funcionesPropias.h"
#include "utn.h"

//De la consigna:
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
	int indexValue;

	if(list != NULL && len>0 && id>=100)
	{

		indexValue = findPassengerById(list,len,id);
		if(indexValue != -1)
		{
			list[indexValue].isEmpty = 1;
			printf("\nPassenger deleted!.\n");
			system("PAUSE");
			ret=0;
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

//No de consigna:
int modifyPassenger(ePassenger*list,int listLen)
{
	int ret = 0;
	int idToSearch;
	int indexValue;
	int selectedOption;
	int continueEdit = 1;

	printf("MODIFY PASSENGER");
	utn_pedirInt(&idToSearch,"\nEnter the passenger ID: ", "\nERROR! try again!: ",100,2100,3);

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
			printf("\n7) Exit.");

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
				case 3:

					break;

				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				}


			}

		}

	}else
	{
		printf("\nCANT FIND THE PASSENGER!.\n");
		system("PAUSE");
	}

	return ret;
}

int newPassenger(ePassenger*list, int len, int*idCounter)
{
	int ret = -1;

	char name[20];
	char lastName[20];
	float price;
	int pType;
	char fCode[10];
	int contiinue = 1;

	system("CLS");
	printf("ADD NEW PASSENGER DATA: ");

	//while(continuee == 1)
	//{
	while(contiinue != 0)
	{
		if(utn_getStr(name, "\nName: ", "\nERROR: Try again: ",20,3)==-1)
		{
			failedMessage();
			break;
		}

		if(utn_getStr(lastName, "\nLast name: ", "\nERROR!: NULL or no more tryes",20,3)==-1)
		{
			failedMessage();
			break;
		}

		if(utn_pedirFloat(&price, "\nEnter price: ", "ERROR!: try again!", 1, 9999999, 3)==-1)
		{
			failedMessage();
			break;
		}

		if(utn_pedirInt(&pType, "\nEnter passengerType: ", "ERROR!", 0,2, 3)==-1)
		{
			failedMessage();
			break;
		}

		if(utn_getStr(fCode, "\nEnter Fly code: ", "\nERROR!: NULL or no more tryes",20,3)==-1)
		{
			failedMessage();
			break;
		}


			if(addPassenger(list, len, idGenerator(idCounter), name, lastName,price,pType,fCode)==0)
			{
				printf("\x1b[32mNew passenger added OK! \x1b[33mID: %d \x1b[0m", *idCounter);
				printf("\n");
				system("PAUSE");
				ret=0;
			}else
			{
				printf("There was an error trying to save the data or maybe theres no more space!");
				printf("\n");
				system("PAUSE");
			}
		contiinue = 0;
	}
	//Validar si una funcion devuelve algo !=0 cancelar la operacion y que no siga pidiendo datos!
return ret;
}
