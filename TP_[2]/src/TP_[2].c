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
#include "ArrayPassenger.h"

#define TAM 2000 //cambiar a 2000! (+1?)

int main(void)
{
	int idCounter = 100; //Variable donde se establece el inicio de los Ids y se suma +1 al dar de alta.

	ePassenger aPassengers[TAM];
	initPassengers(aPassengers, TAM); //Inicializo las flag isEmpty en true.

	addPassenger(aPassengers, TAM, idGenerator(&idCounter), "Leandro", "Guia", 1200, 2, "23");
	addPassenger(aPassengers, TAM, idGenerator(&idCounter), "Leandro2", "Guia2", 1300, 3, "24");
	addPassenger(aPassengers, TAM, idGenerator(&idCounter), "Leandro3", "Guia3", 1400, 4, "25");
	addPassenger(aPassengers, TAM, idGenerator(&idCounter), "Leandro4", "Guia4", 1500, 5, "26");

	removePassenger(aPassengers, TAM, 102);
	printPassengers(aPassengers,TAM);
	system("PAUSE");


	return 0;
}
