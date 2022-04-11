#include <stdio.h>
#include <stdlib.h>





void calculoDePrecios(long int pAerolineas, long int pLatam, int km);

int main(void)
{
	setbuf(stdout, NULL);

	int kilometros = 0;
	long int precioAerolineas = 0;
	long int precioLatam = 0;

	int continuar = 1;
	int opcionElegida;

	//Imprimo el menu mientras que continuar sea = 1
	do{
		//Cada vez que se imprima el menu se va a limpiar lo anterior con el CLS.
		system("CLS");
		printf("\n1) Ingresar kilometros: (%d)", kilometros);
		printf("\n2) Ingresar precio de vuelos: (Aerolineas: %ld, Latam: %ld)", precioAerolineas, precioLatam);
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
			break;

		case 2:
			//Tengo que validar si se cumplio el paso anterior!
			//Pido los precios y los guardo en sus respectivas variables.
			printf("\nIngrese el precio de Aerolineas: ");
			scanf("%ld", &precioAerolineas);

			printf("\nIngrese el precio de Latam: ");
			scanf("%ld", &precioLatam);
			break;

		case 3:
			//Llamo a mi funcion y le paso como parametros los precios y kilometros ingresados por el user.
			calculoDePrecios(precioAerolineas, precioLatam, kilometros);
			//Al salir de la funcion se volvera a ejecutar el bucle ya que esta no toca la VAR continuar (es decir, se vuelve a imprimir el menu).
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			//Al cambiar continuar a 0 sale del bucle.
			continuar =  0;
			break;

		default:
			printf("\nERROR!: tal vez ingresaste mal la opcion?\n");
			system("PAUSE");
			break;

		}
	}while(continuar == 1);

	//Esto se ejecuta solo cuando el usuario presiona 6, es decir la var continuar seria 0 y saldria del bucle.
	system("PAUSE");
	return 0;
}

void calculoDePrecios(long int pAerolineas, long int pLatam, int km)
{
	int aerolineasDebito;
	int aerolineasCredito;
	float aerolineasBitCoin;
	int aerolineasUnitario;

	int latamDebito;
	int latamCredito;
	float latamBitCoin;
	int latamUnitario;

	int diferenciaPrecio;

	//Igualo la variable al precio que pase en los parametros para luego restarle el porcentaje.
	aerolineasDebito = pAerolineas;
	aerolineasDebito -= pAerolineas*10/100;

	//Igualo la variable al precio que pase en los parametros para luego sumarle el porcentaje.
	aerolineasCredito = pAerolineas;
	aerolineasCredito += pAerolineas*25/100;

	//Calculo cuanto saldria en BC.
	aerolineasBitCoin = pAerolineas/4836581.70;

	//Calculo cuanto sale cada km.
	aerolineasUnitario = pAerolineas/km;

	///////////////////////////////////////////////

	latamDebito = pLatam;
	latamDebito -= pLatam*10/100;

	latamCredito = pLatam;
	latamCredito += pLatam*25/100;

	latamBitCoin = pLatam/4836581.70;

	latamUnitario = pLatam/km;

	//Imprimo por pantalla todos los resultados.
	printf("\nPrecio Aerolineas: %ld", pAerolineas);
	printf("\nPrecio Aerolineas con tarjeta de debito: %d", aerolineasDebito);
	printf("\nPrecio Aerolineas con tarjeta de credito: %d", aerolineasCredito);
	printf("\nPrecio Aerolineas pagando con bitcoin: %.4f", aerolineasBitCoin);
	printf("\nMostrar Aerolineas precio unitario: %d \n", aerolineasUnitario);

	printf("\nPrecio Latam: %ld", pLatam);
	printf("\nPrecio Latam con tarjeta de debito: %d", latamDebito);
	printf("\nPrecio Latam con tarjeta de credito: %d", latamCredito);
	printf("\nPrecio Latam pagando con bitcoin: %.4f", latamBitCoin);
	printf("\nMostrar Latam precio unitario: %d \n", latamUnitario);

	//Para sacar la dif de precio: averiguo cual es el precio mayo y le resto el menor.
	if(pLatam>pAerolineas)
	{
		diferenciaPrecio = pLatam-pAerolineas;
	}
	else
	{
		diferenciaPrecio = pAerolineas-pLatam;
	}

	//Muestro el resultado.
	printf("\nLa diferencia de precio es de: %d \n", diferenciaPrecio);

	//PAUSE para que de tiempo a leer al usuario la salida de datos.
	system("PAUSE");

	//FIN DE LA FUNCION.
}
