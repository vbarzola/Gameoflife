#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "vida.h"


char** crear_matriz();
void destruir_matriz();
juego_de_vida vida;
void dibujar_grilla(char **matriz, int fil, int col){
	printf("\e[1;1H\e[2J");
	char *linea = malloc(col + 1);	//Char nulo al final
	for(int i = 0; i < fil; i++){
		memset(linea, ' ', col+1);
		linea[col] = 0;
		for(int j = 0; j < col; j++){
			if(matriz[i][j] == 0){
				linea[j] = ' ';
			}
			else if(matriz[i][j] == 1){
				linea[j] = 'x';			
			}
		}
		printf("%s", linea);
		printf("\n");
		fflush(stdout);
	}

	free(linea);
}


void llenar_matriz_azar(char **grilla, int fil, int col, int cantidad){
	for(int i =0; i<fil; i++){
		memset(grilla[i], 0, col);	
	}
	srand(time(NULL));
	for(int i = 0; i < cantidad; i++){
		long rnd_fil = rand() % fil;	
		long rnd_col = rand() % col;
		
		//printf("%ld %ld\n", rnd_fil, rnd_col);
		if(grilla[rnd_fil][rnd_col] == 1){
			i--;
		}
		else{
			grilla[rnd_fil][rnd_col] = 1;
		}
		
	}
}




/**
 * Actualiza la matriz de vida.
 */
void actualizar(){
	char** nuevaMatriz = crear_matriz();
	for(int i=0;i<vida.filas;i++){
		for(int j=0;j<vida.columnas;j++){
			int c = contar_alrededor(i,j);
			if(vida.tablero[i][j]==1){
				if(c<=1||c>=4) nuevaMatriz[i][j]=0;
				else nuevaMatriz[i][j]=1;
			}else{
				if(c==3) nuevaMatriz[i][j]=1;
			}
			
		}
	
	}

	destruir_matriz();
	vida.tablero= nuevaMatriz;


}

int contar_alrededor(int i, int j){
	char ** tablero = vida.tablero;
	int cont=0;
	for(int x=i-1;x<i+2;x++){
		for(int y=j-1;y<j+2;y++){
			if((i!=x)&&(j!=y)&&(x>=0&&x<vida.filas)&&(y>=0&&y<vida.columnas)&&(tablero[x][y]==1)){
			       	cont++;
			}		
		}
	}
	return cont;
}
