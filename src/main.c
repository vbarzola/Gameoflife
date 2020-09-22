#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <unistd.h>

int filas;
int columnas;
int generaciones;
int tiempo;
int celulas;

int main(int argc, char **argv)
{
    int c;

    while ((c = getopt(argc, argv, "f:c:g:s:i:")) != -1){
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
    printf("Filas: %d, columnas: %d, generaciones: %d, tiempo: %d, celulas iniciales: %d\n",filas, columnas, generaciones, tiempo, celulas);
    
    
    return 0;
}
