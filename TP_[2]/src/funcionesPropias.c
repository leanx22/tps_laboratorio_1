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

int failedMessage()
{
	printf("\n\x1b[35mFAILED: you run out of attempts or function returns NULL.");
	printf("\nNothing will be saved, you will return to the main menu.\x1b[0m");
	printf("\n");
	system("PAUSE");

	return 0;
}

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


