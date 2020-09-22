#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>



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
		
		printf("%ld %ld\n", rnd_fil, rnd_col);
		if(grilla[rnd_fil][rnd_col] == 1){
			i--;
		}
		else{
			grilla[rnd_fil][rnd_col] = 1;
		}
		
	}
}

