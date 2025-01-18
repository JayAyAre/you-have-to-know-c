#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sopa.h"
#include <time.h>

int main() {
    srand(time(NULL));
    char sopa[MAX_SIZE][MAX_SIZE];
    char palabras[MAX_WORDS][MAX_WORD_LEN];
    int numPalabras = 0, filas, columnas;

    char archivoEntrada[50];
    printf("Introduce el nombre del archivo de palabras: ");
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && i < 49) archivoEntrada[i++] = c;
    archivoEntrada[i] = '\0';

    leerPalabras(archivoEntrada, palabras, &numPalabras);
    if (numPalabras == 0) {
        printf("No se encontraron palabras o archivo no existe.\n");
        return 1;
    }

    printf("Introduce las dimensiones (filas y columnas): ");
    scanf("%d %d", &filas, &columnas);

    generarSopa(sopa, filas, columnas);

    int palabrasColocadas = 0;
    for (int i = 0; i < numPalabras; i++) {
        if (colocarPalabraAleatoria(sopa, palabras[i], filas, columnas)) palabrasColocadas++;
    }

    rellenarEspacios(sopa, filas, columnas);

    printf("\nSopa generada:\n");
    mostrarSopa(sopa, filas, columnas);

    guardarSopa("sopa.txt", sopa, filas, columnas);

    printf("Sopa guardada en sopa.txt\n");
    return 0;
}
