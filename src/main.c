#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <unistd.h>
#include "vida.h"

int filas;
int columnas;
int generaciones;
int tiempo;
int celulas;

juego_de_vida vida;

/**
 * Crea la unica instancia de la estructura principal 
 * de la aplicacion.
 */
void crear_estructura();

int main(int argc, char **argv)
{
    int c;

    while ((c = getopt(argc, argv, "f:c:g:s:i:")) != -1)
    {
        switch (c)
        {
        case 'f':
            filas = atoi(optarg);
            break;
        case 'c':
            columnas = atoi(optarg);
            break;
        case 'g':
            generaciones = atoi(optarg);
            break;
        case 's':
            tiempo = atoi(optarg);
            break;
        case 'i':
            celulas = atoi(optarg);
            break;
        default:
            abort();
        }
    }
    crear_estructura();
    printf("filas: %ld\n",vida.filas);
    dibujar_grilla(vida.tablero,vida.filas,vida.columnas);
    return 0;
}

char **crear_matriz(){
    char **tablero = calloc(vida.filas, sizeof(char *));
    for (int i = 0; i < filas; i++)
    {
        tablero[i] = calloc(vida.columnas, sizeof(char));
    }
    return tablero;
}

void crear_estructura()
{
    vida.filas = filas,
    vida.columnas = columnas,
    vida.tiempo_sleep = tiempo,
    vida.generaciones = generaciones;
    vida.tablero = crear_matriz(),
    llenar_matriz_azar(vida.tablero, filas, columnas, celulas);
}

void destruir_matriz(){
    for(int i=0; i<vida.filas;i++){
        free(vida.tablero[i]);
    }
    free(vida.tablero);
}