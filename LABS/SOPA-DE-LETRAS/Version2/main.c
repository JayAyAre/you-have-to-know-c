// main.c
#include "config.h"  // Incluir el archivo de configuración
#include "sopa.h"
#include "palabras.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char sopa[MAX_SIZE][MAX_SIZE];
    char palabras[MAX_WORDS][MAX_WORD_LEN];
    int numPalabras = 0, filas, columnas;
    const char *diccionario = "diccionari.txt";
    const char *archivoSalida = "sopa.txt";

    // Leer palabras del ficheros
    leerPalabras(diccionario, palabras, &numPalabras);
    if (numPalabras == 0) {
        printf("No se encontraron palabras en el fichero.\n");
        return 1;
    }

    // Solicitar dimensiones al usuarios
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

    // Generar la sopa de letras vacía
    generarSopa(sopa, filas, columnas);

    // Colocar las palabras
    for (int i = 0; i < numPalabras; i++) {
        if (!colocarPalabra(sopa, palabras[i], filas, columnas)) {
            printf("No se pudo colocar la palabra: %s\n", palabras[i]);
        }
    }

    // Rellenar espacios vacíos
    rellenarEspacios(sopa, filas, columnas);

    // Mostrar la sopa en pantalla
    mostrarSopa(sopa, filas, columnas);

    // Guardar la sopa en un fichero
    guardarSopa(archivoSalida, sopa, filas, columnas);

    printf("Sopa de letras guardada en el archivo: %s\n", archivoSalida);
    return 0;
}
