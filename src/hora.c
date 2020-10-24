#include<stdio.h>	//Libreria por default de C
#include<signal.h>	//Libreria para poder atrapar las señales de linux
#include<unistd.h>	//Libreria que sirve para el manejo de archivos y directorios
#include<time.h>	//Libreria para poder mostrar el tiempo
#include<stdlib.h>	//Libreria para poder incorporar exit();
#include<global.hh>

void funcion_tiempo(int signal)	//Funcion donde se muestra el tiempo si es que se atrapa la señal SIGUSR1
{
	time_t current_time;	//Se declara la variable
	time(&current_time);	//Se le asigna el tiempo actual
	printf("Señal SIGUSR1 recibida: %s\n",ctime(&current_time));	//Se muestra el tiempo actual
}

void finalizar(int signal2)	//Funcion para finalizar el programa con el segundo ctrl+c
{
	printf("\nAdios Mundo\n");	//Mensaje de despedida 
	exit(0);	//Salida del script
}


void trampa(int signal1)	//Funcion carnada para atrapar el primer ctrl+c
{
	printf("\n");
	signal(SIGINT, &finalizar);	//Se redirige a la funcion para matar el script
}

int main (void)
{
	printf("Programa hora ejecutandose. PID = %d \n",getpid()); //Salida en pantalla pedida
	printf("Listo para recibir la señal SIGUSR1 \n");
	signal(SIGUSR1, &funcion_tiempo);	//Si se atrapa la señal SIGUSR1 se redirige a la funcion para mostrar el tiempo
	signal(SIGINT, &trampa);	//Se atrapa al primer ctrl+c redirigiendolo a una funcion trampa
	while(1){	//Con este while se mantiene al programa en espera hasta que se ingresa una de las dos señales (SIGUSR1 o SIGINT)
		sleep(1);
	}
	return 0;
}
