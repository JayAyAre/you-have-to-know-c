#include "sopa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char sopa[MAX_SIZE][MAX_SIZE];
    char palabras[MAX_WORDS][MAX_WORD_LEN];
    int numPalabras = 0, filas, columnas;
    char archivoEntrada[50];
    const char *archivoSalida = "sopa.txt";

    printf("Introduce el nombre del archivo de palabras (ej: palabras.txt): ");
    scanf("%s", archivoEntrada);

    leerPalabras(archivoEntrada, palabras, &numPalabras);
    if (numPalabras == 0) {
        printf("No se encontraron palabras o el archivo no existe.\n");
        return 1;
    }

    double longitudMedia = calcularLongitudMedia(palabras, numPalabras);

    int dimensionesValidas = 0;
    while (!dimensionesValidas) {
        printf("Introduce el numero de filas (entre %d y %d): ", MIN_SIZE, MAX_SIZE);
        scanf("%d", &filas);
        printf("Introduce el numero de columnas (entre %d y %d): ", MIN_SIZE, MAX_SIZE);
        scanf("%d", &columnas);
        if (filas >= MIN_SIZE && filas <= MAX_SIZE && columnas >= MIN_SIZE && columnas <= MAX_SIZE) {
            dimensionesValidas = 1;
        } else {
            printf("Dimensiones no validas. Intenta de nuevo.\n");
        }
    }

    int palabrasSugeridas = (int)(0.3 * (filas * columnas) / longitudMedia);
    printf("Numero maximo de palabras sugerido: %d\n", palabrasSugeridas);

    generarSopa(sopa, filas, columnas);

    int palabrasColocadas = 0;
    for (int i = 0; i < numPalabras && palabrasColocadas < palabrasSugeridas; i++) {
        if (colocarPalabraAleatoria(sopa, palabras[i], filas, columnas)) {
            palabrasColocadas++;
        }
    }

    rellenarEspacios(sopa, filas, columnas);
    mostrarSopa(sopa, filas, columnas);
    guardarSopa(archivoSalida, sopa, filas, columnas);

    printf("Sopa guardada en: %s\n", archivoSalida);
    return 0;
}
