#include<stdio.h>
//#include<windows.h>
#include<stdlib.h>
#include "util.h"
int main(){
    char **matriz = malloc(2*sizeof(char*));
    matriz[0] = malloc(2*sizeof(char));
    matriz[1] = malloc(2*sizeof(char));
    matriz[0][0] = 1;
    matriz[0][1]=1;
    dibujar_grilla(matriz,2,2);
    free(matriz[0]);
    free(matriz[1]);
    free(matriz);

}
