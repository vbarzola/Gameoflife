
#ifndef UTIL_H
#define UTIL_H


/*
Funcion que dibuja una grilla en la terminal.
Recibe un arreglo 2D de chars. Si el elemento es el 
numero 0, se muestra un espacio vacio, si es 1, se 
muestra una x.

Cada llamada de esta funcion borrara todo lo mostrado
en pantalla.

*/
void dibujar_grilla(char **matriz, int fil, int col);


/*
Llena matriz con cantidad de 1s en posiciones al azar,
el resto lo llena de 0s.
*/
void llenar_matriz_azar(char **grilla, int fil, int col, int cantidad);

char** crear_matriz();

void destruir_matriz();

int contar_alrededor(int i, int j);

void actualizar();

#endif 
