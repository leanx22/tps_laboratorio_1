/*
 * funcionesPropias.c
 *
 *  Created on: 13 may. 2022
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesPropias.h"
#include "ArrayPassenger.h"
#include "utn.h"

int idGenerator(int * counter)//mover
{
	int ret = -1;

	if(counter !=NULL)
	{
		*counter+=1;
		ret = *counter;
	}

	return ret; //A la hora de dar de alta, se verificara si ret en -1, si ese es el caso isEmpty quedara en true y se cancelara la carga para reintentarla.
}

int newPassenger(ePassenger*list, int len, int*idCounter)
{
	int ret = -1;

	char name[20];
	char lastName[20];
	float price;
	int pType;
	char fCode[10];

	system("CLS");
	printf("ADD NEW PASSENGER DATA: ");

	//Validar si una funcion devuelve algo !=0 cancelar la operacion y que no siga pidiendo datos!
	utn_getStr(name, "\nName: ", "\nERROR!: NULL or no more tryes",20,3);
	utn_getStr(lastName, "\nLast name: ", "\nERROR!: NULL or no more tryes",20,3);
	utn_pedirFloat(&price, "\nEnter price: ", "ERROR!: try again!", 1, 9999999, 3);
	utn_pedirInt(&pType, "\nEnter passengerType: ", "ERROR!", 0,2, 3);
	utn_getStr(fCode, "\nEnter Fly code: ", "\nERROR!: NULL or no more tryes",20,3);

	if(addPassenger(list, len, idGenerator(idCounter), name, lastName,price,pType,fCode)==0)
	{
		printf("New passenger added OK!");
		printf("\n");
		system("PAUSE");
		ret=0;
	}else
	{
		printf("There was an error!, one function return -1 or maybe not enough space!");
		printf("n");
		system("PAUSE");
	}

return ret;
}
