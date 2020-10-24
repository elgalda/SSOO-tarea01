# SSOO-tarea01
Para solucionar este problema se utilizaron las siguientes librerias:

stdlib.h -> Es la libreria para poder implementar la funcion exit(), la cual se usa para la condicion de salida propuesta en el problema.
time.h -> Es la libreria para poder implementar la funcion que muestra el tiempo como se solicita en el problema.
unistd.h -> Libreria para poder manejar los directorios y archivos
signal.h -> Libreria para poder atrapar y leer las señales enviadas por consola hacie el script
stdio.h -> Libreria por default de C

Este script cuenta con 4 funciones para la resolucion de este problema, al momento de entrar a la funcion main() se muestra en pantalla lo que se pide, desde ahi hay 2 posibles caminos.
Si es que se capta la señal SIGUSR1 se cumple la funcion principal del codigo, la cual es mostrar la hora y fecha en la cual se ingreso esta señal.
Esto se logra a traves de funcion_tiempo, la cual almacena esta innformacion en la variable tipo time_t llama current time. Posteriormente esto muestra por pantalla.
Si es que se capta la señal SIGNINT, la cual es la que se capta al capturar el ctrl+c se va a la funcion trampa, la cual logra ignorar la primera señal, si es que se vuelve a ingresar la señal SIGNINT con ctrl+c se redirige a la funcion finalizar, la cual es la que pone fin al script.
