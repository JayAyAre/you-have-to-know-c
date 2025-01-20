#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sopa.h"

void leerPalabras(const char *filename, char palabras[MAX_WORDS][MAX_WORD_LEN], int *numPalabras) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        *numPalabras = 0;
        return;
    }

    int i = 0, j = 0;
    char c;

    while (i < MAX_WORDS && (c = fgetc(file)) != EOF) {
        if (c == '\n' || c == ' ') {
            if (j > 0) {
                palabras[i][j] = '\0';
                i++;
                j = 0;
            }
        } else if (j < MAX_WORD_LEN - 1) {
            palabras[i][j++] = c;
        }
    }

    if (j > 0) {
        palabras[i][j] = '\0';
        i++;
    }

    *numPalabras = i;
    fclose(file);
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

    int resultado = 0;
    if (direccion == 0) {
        resultado =  colocarPalabraHorizontal(sopa, palabra, filas, columnas, len);
    } else if (direccion == 1) {
        resultado =  colocarPalabraVertical(sopa, palabra, filas, columnas, len);
    } else {
        resultado = colocarPalabraDiagonal(sopa, palabra, filas, columnas, len);
    }

    return resultado;
}

int colocarPalabraHorizontal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len) {
    int colocada = 0;
    for (int i = 0; i < filas && !colocada; i++) {
        for (int j = 0; j <= columnas - len && !colocada; j++) {
            int puedeColocar = 1;
            for (int k = 0; k < len; k++) {
                if (sopa[i][j + k] != ' ' && sopa[i][j + k] != palabra[k]) {
                    puedeColocar = 0;
                }
            }
            if (puedeColocar) {
                for (int k = 0; k < len; k++) {
                    sopa[i][j + k] = palabra[k];
                }
                colocada = 1;
            }
        }
    }
    return colocada;
}

int colocarPalabraVertical(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len) {
    int colocada = 0;
    for (int i = 0; i <= filas - len && !colocada; i++) {
        for (int j = 0; j < columnas && !colocada; j++) {
            int puedeColocar = 1;
            for (int k = 0; k < len; k++) {
                if (sopa[i + k][j] != ' ' && sopa[i + k][j] != palabra[k]) {
                    puedeColocar = 0;
                }
            }
            if (puedeColocar) {
                for (int k = 0; k < len; k++) {
                    sopa[i + k][j] = palabra[k];
                }
                colocada = 1;
            }
        }
    }
    return colocada;
}

int colocarPalabraDiagonal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len) {
    int colocada = 0;
    for (int i = 0; i <= filas - len && !colocada; i++) {
        for (int j = 0; j <= columnas - len && !colocada; j++) {
            int puedeColocar = 1;
            for (int k = 0; k < len; k++) {
                if (sopa[i + k][j + k] != ' ' && sopa[i + k][j + k] != palabra[k]) {
                    puedeColocar = 0;
                }
            }
            if (puedeColocar) {
                for (int k = 0; k < len; k++) {
                    sopa[i + k][j + k] = palabra[k];
                }
                colocada = 1;
            }
        }
    }
    return colocada;
}

void rellenarEspacios(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
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
                fprintf(file, "%c", sopa[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
}

void mostrarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%c ", sopa[i][j]);
        }
        printf("\n");
    }
}

double calcularLongitudMedia(char palabras[MAX_WORDS][MAX_WORD_LEN], int numPalabras) {
    int totalLongitud = 0;
    for (int i = 0; i < numPalabras; i++) {
        totalLongitud += strlen(palabras[i]);
    }
    return (double)totalLongitud / numPalabras;
}