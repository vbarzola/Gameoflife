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
    int cont_generaciones=0;
    if(generaciones<0){
    	while(1){
		    print("generacion: %d",cont_generaciones);
		    dibujar_grilla(vida.tablero,vida.filas,vida.columnas);
		    actualizar();
		    usleep(tiempo);
		    cont_generaciones++;		
	    }
    }
    for(int i=0; i<generaciones;i++){
        print("generación: %d",i);
        dibujar_grilla(vida.tablero,vida.filas,vida.columnas);
        actualizar();
        usleep(tiempo);	
    }
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
    vida.stats.celulas_muertas = filas*columnas - celulas;
    vida.stats.celulas_vivas = celulas;
    vida.stats.n_generacion = 0;
    vida.stats.promedio_celulas_muertas = vida.stats.celulas_muertas;
    vida.stats.promedio_celulas_vivas = vida.stats.celulas_vivas;
    vida.stats.celulas_nacidas = 0;
    vida.stats.celulas_muertas_gen = 0;
    llenar_matriz_azar(vida.tablero, filas, columnas, celulas);
}

void destruir_matriz(){
    for(int i=0; i<vida.filas;i++){
        free(vida.tablero[i]);
    }
    free(vida.tablero);
}
