#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM_MAX 50

int random(int dim);
void crea_tauler(int tablero[DIM_MAX][DIM_MAX], int dim);
int escriu_matriu_f(char nombre[], int tablero[DIM_MAX][DIM_MAX],int fila, int col, int dim);

// Funcion para generar un numero aleatorio entre 0 y dim-1
int random(int dim) {
    return (rand() % dim);
}


void crea_tauler(int tablero[DIM_MAX][DIM_MAX], int dim) {

    // Crear el tablero
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            tablero[i][j] = (i + j) % dim + 1;
        }
    }

    // Bucle para desordenar el tablero, intercambiadndo filas y columnas
    for (int i = 0; i < dim; i++){
        int row1 = random(dim);
        int row2 = random(dim);

        // Intercambiar filas
        for (int j = 0; j < dim; j++) {
            int aux = tablero[row1][j];
            tablero[row1][j] = tablero[row2][j];
            tablero[row2][j] = aux;
        }

        int col1 = random(dim);
        int col2 = random(dim);

        // Intercambiar columnas
        for (int j = 0; j < dim; j++) {
            int aux = tablero[j][col1];
            tablero[j][col1] = tablero[j][col2];
            tablero[j][col2] = aux;
        }
    }
}


// Funcion para guardar el tablero en un archivo
int escriu_matriu_f(char nombre[], int tablero[DIM_MAX][DIM_MAX],int fila, int col, int dim) {
    FILE *fp;
    fp = fopen(nombre, "w");

    // Escribo filas y columnas
    fprintf(fp, "%d\n", fila);
    fprintf(fp, "%d\n", col);

    // Escribo el tablero
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            fprintf(fp, "%d ", tablero[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));  // Inicializa el generador de números aleatorios
    int tablero[DIM_MAX][DIM_MAX];
    int dim = 5;
    crea_tauler(tablero, dim);
    escriu_matriu_f("tablero.txt", tablero, dim, dim, dim);
    return 0;
}
