
#ifndef VIDA_H
#define VIDA_H

typedef struct stats{
	int n_generacion;
	int celulas_vivas;
	int celulas_muertas;
	int celulas_nacidas;
	int celulas_fallecidas;
	int promedio_celulas_vivas;
	int promedio_celulas_muertas;
} stats;

typedef struct vida{
	char **tablero;
	long filas;
	long columnas;
	long tiempo_sleep;
	long generaciones;
	stats stats;
} juego_de_vida;

#endif
