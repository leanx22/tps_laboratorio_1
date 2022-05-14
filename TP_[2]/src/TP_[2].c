/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Guia Leandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "utn.h"
#include "funcionesPropias.h"

#define TAM 2000 //cambiar a 2000! (+1?)

int main(void)
{
	int idCounter = 100; //Variable donde se establece el inicio de los Ids y se suma +1 al dar de alta.
	int selectedOption;



	ePassenger aPassengers[TAM];
	initPassengers(aPassengers, TAM); //Inicializo las flag isEmpty en true.


	//printPassengers(aPassengers,TAM);

	do{
		if(utn_pedirInt(&selectedOption, "MENU:\n1) AddPassenger."
										"\n2)Modify passenger."
										"\n3)Delete passenger."
										"\n4)Inform."
										"\n5)EXIT.", "---ERROR, TRY AGAIN---", 1, 5, 5)==-1)
		{
			printf("\nError in option select!");
			break;
		}
		else{
			switch(selectedOption)
			{
				case 1:
					newPassenger(aPassengers, TAM, &idCounter);
					break;

				case 2:
					modifyPassenger(aPassengers, TAM);

					break;


				case 3:
					break;

				case 4:
					break;
			}
		}

	}while(selectedOption != 5);

	system("PAUSE");


	return 0;
}
