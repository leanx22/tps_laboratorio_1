#include <stdio.h>
#include <stdlib.h>

#include "calculosPrecio.h"
#include "validaciones.h"
#include "utilidades.h"


int main(void)
{
	setbuf(stdout, NULL);

	//Los precios los declare como flotantes ya que podrian contener "centavos".
	float precioAerolineas = 0;
	float precioLatam = 0;
	int kilometros = 0;

	int opcionElegida;
	int continuar = 1;

	int flagOpcion1 = 0;
	int flagOpcion2 = 0;
	int flagOpcion3 = 0;

	float aerolineasDebito;
	float aerolineasCredito;
	float aerolineasBitCoin;
	float aerolineasUnitario;

	float latamDebito;
	float latamCredito;
	float latamBitCoin;
	float latamUnitario;

	float diferenciaPrecio;

	//Imprimo el menu mientras que continuar sea = 1
	do{
		fflush(stdin);
		fflush(stdout);
		//Cada vez que se imprima el menu se va a limpiar lo anterior con el CLS.
		system("CLS");
		printf("\n1) Ingresar kilometros: (%d)", kilometros);
		printf("\n2) Ingresar precio de vuelos: (Aerolineas: %.2f, Latam: %.2f)", precioAerolineas, precioLatam);
		printf("\n3) Calcular todos los costos.");
		printf("\n4) Informar resultados.");
		printf("\n5) Carga forzada de datos.");
		printf("\n6) Salir.\n");

		scanf("%d", &opcionElegida);

		switch(opcionElegida)
		{
		case 1:
			printf("\nIngrese los kilometros (maximo 35000[Argentina a china 18000km]): ");
			//Uso mi funcion para pedir datos flotantes, le pongo maximo de 35000 ya que la distancia de viaje mas larga es de Arg a china (18000km)
			kilometros = pedirValidarFloat(1, 35000);
			//cambio el flag para saber que el usuario completo esta opcion.
			flagOpcion1 = 1;
		break;

		case 2:
			//Por medio de la funcion pido y valido dos precios que seran guardados en las variables de los parametros.
			pedirValidarPrecio(&precioAerolineas, &precioLatam);
			//Cambio el flag para saber que el usuario completo la opcion 2.
			flagOpcion2 = 1;
		break;

		case 3:
			//Verifico si el usuario completo los pasos anteriores.
			if (flagOpcion1 == 1 && flagOpcion2 == 1)
			{
				//Llamo mis funciones que van a calcular los precios, les paso el valor de precio y kilometros y las direcciones donde debera guardar todos los resultados.
				calculoPrecios(precioAerolineas, kilometros, &aerolineasDebito, &aerolineasCredito, &aerolineasBitCoin, &aerolineasUnitario);
				calculoPrecios(precioLatam, kilometros, &latamDebito, &latamCredito, &latamBitCoin, &latamUnitario);
				//Guardo la diferencia de precio que me va a retornar la funcion.
				diferenciaPrecio = calculoDiferencia(precioAerolineas, precioLatam);
				//Cambio el valor del flag para que se le habilite la opcion 4 al usuario.
				flagOpcion3 = 1;
				printf("\n\x1b[32mPRECIOS OK\x1b[0m\n");
				system("PAUSE");
			}
			else
			{
				//Si no se realizo la carga de datos anteriores no deja seleccionar la opcion.
				printf("\n\x1b[31mSE DEBEN COMPLETAR LOS 2 PASOS PREVIOS!\x1b[0m\n");
				system("PAUSE");
			}
		break;

		case 4:
			//Imprimo todos los resultados que fueron guardados en las variables previamente (en la opcion 3).
			if(flagOpcion3 == 1)
			{
				system("CLS");
				printf("Resultados Aerolineas: (ingresado: %.2f)", precioAerolineas);
				mostrarResultados(&aerolineasDebito, &aerolineasCredito, &aerolineasBitCoin, &aerolineasUnitario);

				printf("\n\nResultados LATAM: (ingresado: %.2f)", precioLatam);
				mostrarResultados(&latamDebito, &latamCredito, &latamBitCoin, &latamUnitario);

				printf("\nLa diferencia de precio entre ambos es de: %.2f\n", diferenciaPrecio);
				system("PAUSE");
			}
			else
			{
				printf("\n\x1b[31mSE NECESITA EL OK DE LA OPCION 3!\x1b[0m\n");
				system("PAUSE");
			}
			break;

		case 5:
			cargaForzada(); //La funcion Realiza la carga forzada e imprime los resultados.
			break;

		case 6:
			continuar =  0; //Al cambiar continuar a 0 sale del bucle.
			break;

		default: //Utilizo el default para validar la opcion elegida en el menu, es decir que si no es una opcion valida (entre 1 y 6) va a dar error y pedira que se reingrese.
			printf("\nERROR!: Tal vez ingresaste mal la opcion?\n");
			system("PAUSE");
			break;

		}
	}while(continuar == 1);
	//Cuando el usuario seleccione la opcion 6 se saldra del bucle y el programa finalizara retornando 0.
	return 0;
}
