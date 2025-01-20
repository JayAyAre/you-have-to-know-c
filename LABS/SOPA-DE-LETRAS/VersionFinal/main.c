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
    const char *archivoSalida = "sopa.txt";

    printf("Introduce el nombre del archivo de palabras (ej: programacion.txt o animales.txt): ");
    scanf("%s", archivoEntrada);

    leerPalabras(archivoEntrada, palabras, &numPalabras);
    if (numPalabras == 0) {
        printf("No se encontraron palabras en el fichero o el archivo no existe.\n");
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
            printf("Dimensiones no validas. Por favor, intentalo de nuevo.\n");
        }
    }

    int palabrasSugeridas = (int)(0.3 * (filas * columnas) / longitudMedia);
    printf("Numero maximo de palabras sugerido para esta sopa: %d\n", palabrasSugeridas);

    generarSopa(sopa, filas, columnas);

    int palabrasColocadas = 0;
    int usadas[MAX_WORDS] = {0};

    while (palabrasColocadas < palabrasSugeridas && palabrasColocadas < numPalabras) {
        int indiceAleatorio = rand() % numPalabras;

        if (!usadas[indiceAleatorio]) {
            if (colocarPalabraAleatoria(sopa, palabras[indiceAleatorio], filas, columnas)) {
                usadas[indiceAleatorio] = 1;
                palabrasColocadas++;
            }
        }
    }

    rellenarEspacios(sopa, filas, columnas);

    mostrarSopa(sopa, filas, columnas);

    guardarSopa(archivoSalida, sopa, filas, columnas);

    printf("Sopa de letras guardada en el archivo: %s\n", archivoSalida);
    return 0;
}
