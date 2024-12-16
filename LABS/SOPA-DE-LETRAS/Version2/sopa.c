#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sopa.h"

// Generar la sopa vacía
void generarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            sopa[i][j] = ' ';
        }
    }
}

// Colocar una palabra de forma horizontal
int colocarPalabra(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas) {
    int len = 0;
    while (palabra[len] != '\0') len++; // Longitud de la palabra

    if (len > columnas) return 0; // La palabra es demasiado larga

    int colocada = 0;
    for (int i = 0; i < filas && !colocada; i++) {
        for (int j = 0; j <= columnas - len && !colocada; j++) {
            // Comprobar si cabe la palabra
            int puedeColocar = 1;
            for (int k = 0; k < len && puedeColocar; k++) {
                if (sopa[i][j + k] != ' ') {
                    puedeColocar = 0;
                }
            }

            // Colocar la palabra si es posible
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

// Rellenar espacios vacíos con letras aleatorias
void rellenarEspacios(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    // Inicializar semilla para generar números aleatorios
    srand((unsigned int)time(NULL));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (sopa[i][j] == ' ') {
                // Rellenar con una letra aleatoria de 'A' a 'Z'
                sopa[i][j] = (char)('A' + (rand() % 26));
            }
        }
    }
}

// Guardar la sopa en un fichero
void guardarSopa(const char *filename, char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                fputc(sopa[i][j], file);
            }
            fputc('\n', file);
        }
        fclose(file);
    } else {
        printf("No se pudo guardar la sopa en el archivo: %s\n", filename);
    }
}

// Mostrar la sopa en pantalla
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
