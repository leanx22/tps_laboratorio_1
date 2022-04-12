#include <stdio.h>
#include <stdlib.h>

#include "calculosPrecio.h"


int main(void)
{
	setbuf(stdout, NULL);

	//Los precios los declare como flotantes ya que podrian contener "centavos".
	float precioAerolineas = 0;
	float precioLatam = 0;
	int kilometros = 1;

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
			printf("\nIngrese los kilometros: ");
			scanf("%d", &kilometros);
			while(kilometros < 1 || kilometros > 36000) //La distancia de Argentina a china (practicamente el destino mas lejano posible) es de 18.887km.
			{
				printf("\nERROR, REINGRESE: ");
				scanf("%d", &kilometros);
			}
		flagOpcion1 = 1;
		break;

		case 2:

			printf("\nIngrese el precio de Aerolineas: ");
			scanf("%f", &precioAerolineas);

			printf("\nIngrese el precio de Latam: ");
			scanf("%f", &precioLatam);

			while(precioAerolineas < 1 || precioLatam  < 0)
			{
				system("CLS");
				printf("\nLos precios no pueden ser menor a 1, reingreselos correctamente.");

				printf("\nIngrese el precio de Aerolineas: ");
				scanf("%f", &precioAerolineas);

				printf("\nIngrese el precio de Latam: ");
				scanf("%f", &precioLatam);
			}
		flagOpcion2 = 1;
		break;

		case 3:
			//Verifico si el usuario completo los pasos anteriores.
			if (flagOpcion1 == 1 && flagOpcion2 == 1)
			{
				//guardo en las variables todos los resultados de los calculos (que me lo da el return de las funciones).
				aerolineasDebito = calculoDebito(precioAerolineas);
				aerolineasCredito = calculoCredito(precioAerolineas);
				aerolineasBitCoin = pasajeBitcoin(precioAerolineas);
				aerolineasUnitario = calculoPrecioUnitario(precioAerolineas, kilometros);

				latamDebito = calculoDebito(precioLatam);
				latamCredito = calculoCredito(precioLatam);
				latamBitCoin = pasajeBitcoin(precioLatam);
				latamUnitario = calculoPrecioUnitario(precioLatam, kilometros);

				diferenciaPrecio = calculoDiferencia(precioAerolineas, precioLatam);
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
				printf("\nPagando con DEBITO: %.2f", aerolineasDebito);
				printf("\nPagando con CREDITO: %.2f", aerolineasCredito);
				printf("\nPagando en BITCOIN: %.3f", aerolineasBitCoin);
				printf("\nPrecio por KM: %.2f", aerolineasUnitario);

				printf("\n\nResultados LATAM: (ingresado: %.2f)", precioLatam);
				printf("\nPagando con DEBITO: %.2f", latamDebito);
				printf("\nPagando con CREDITO: %.2f", latamCredito);
				printf("\nPagando en BITCOIN: %.3f", latamBitCoin);
				printf("\nPrecio por KM: %.2f", latamUnitario);

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
			cargaForzada();
			break;

		case 6:
			//Al cambiar continuar a 0 sale del bucle.
			continuar =  0;
			break;

		default:
			printf("\nERROR!: Tal vez ingresaste mal la opcion?\n");
			system("PAUSE");
			break;

		}
	}while(continuar == 1);

	//Esto se ejecuta solo cuando el usuario presiona 6, es decir la var continuar seria 0 y saldria del bucle.
	return 0;
}
