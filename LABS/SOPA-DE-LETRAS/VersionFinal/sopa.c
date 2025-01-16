#include "sopa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void leerPalabras(const char *filename, char palabras[MAX_WORDS][MAX_WORD_LEN], int *numPalabras) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("No se pudo abrir el fichero: %s\n", filename);
        *numPalabras = 0;
    } else {
        int i = 0;
        while (i < MAX_WORDS && fscanf(file, "%s", palabras[i]) == 1) {
            i++;
        }
        *numPalabras = i;
        fclose(file);
    }
}

void generarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            sopa[i][j] = ' ';
        }
    }
}

int generarDireccionAleatoria() {
    return rand() % 3;
}

int colocarPalabraAleatoria(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas) {
    int direccion = generarDireccionAleatoria();
    int len = strlen(palabra);

    if (direccion == 0) {
        return colocarPalabraHorizontal(sopa, palabra, filas, columnas, len);
    } else if (direccion == 1) {
        return colocarPalabraVertical(sopa, palabra, filas, columnas, len);
    } else {
        return colocarPalabraDiagonal(sopa, palabra, filas, columnas, len);
    }
}

int colocarPalabraHorizontal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j <= columnas - len; j++) {
            int puedeColocar = 1;
            for (int k = 0; k < len; k++) {
                if (sopa[i][j + k] != ' ' && sopa[i][j + k] != palabra[k]) {
                    puedeColocar = 0;
                    break;
                }
            }
            if (puedeColocar) {
                for (int k = 0; k < len; k++) {
                    sopa[i][j + k] = palabra[k];
                }
                return 1;
            }
        }
    }
    return 0;
}

int colocarPalabraVertical(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len) {
    for (int i = 0; i <= filas - len; i++) {
        for (int j = 0; j < columnas; j++) {
            int puedeColocar = 1;
            for (int k = 0; k < len; k++) {
                if (sopa[i + k][j] != ' ' && sopa[i + k][j] != palabra[k]) {
                    puedeColocar = 0;
                    break;
                }
            }
            if (puedeColocar) {
                for (int k = 0; k < len; k++) {
                    sopa[i + k][j] = palabra[k];
                }
                return 1;
            }
        }
    }
    return 0;
}

int colocarPalabraDiagonal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len) {
    for (int i = 0; i <= filas - len; i++) {
        for (int j = 0; j <= columnas - len; j++) {
            int puedeColocar = 1;
            for (int k = 0; k < len; k++) {
                if (sopa[i + k][j + k] != ' ' && sopa[i + k][j + k] != palabra[k]) {
                    puedeColocar = 0;
                    break;
                }
            }
            if (puedeColocar) {
                for (int k = 0; k < len; k++) {
                    sopa[i + k][j + k] = palabra[k];
                }
                return 1;
            }
        }
    }
    return 0;
}

void rellenarEspacios(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (sopa[i][j] == ' ') {
                sopa[i][j] = (char)('A' + (rand() % 26));
            }
        }
    }
}

void guardarSopa(const char *filename, char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                fprintf(file, "%c ", sopa[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    } else {
        printf("No se pudo guardar la sopa en el archivo: %s\n", filename);
    }
}

void mostrarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    printf("\nSopa de Letras:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            putchar(sopa[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}

double calcularLongitudMedia(char palabras[MAX_WORDS][MAX_WORD_LEN], int numPalabras) {
    int totalLongitud = 0;
    for (int i = 0; i < numPalabras; i++) {
        totalLongitud += strlen(palabras[i]);
    }
    return (double)totalLongitud / numPalabras;
}
