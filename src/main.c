#include <stdio.h>
#include <stdlib.h>
#include "../include/util.h"

int filas;
int columnas;
int generaciones;
int tiempo;
int celulas;

int main(int argc, char **argv)
{
    int index;
    int c;

    opterr = 0;

    while ((c = getopt(argc, argv, "f:c:g:s:i:")) != -1)
        switch (c)
        {
        case 'f':
            filas = optarg;
            break;
        case 'c':
            columnas = optarg;
            break;
        case 'g':
            generaciones = optarg;
            break;
        case 's':
            tiempo = optarg;
            break;
        case 'i':
            celulas = optarg;
            break;
        case '?':
            if (optopt == 'c')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
            return 1;
        default:
            abort();
        }

    return 0;
}
