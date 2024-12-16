#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_WORDS 30
#define MAX_WORD_LEN 20

// Prototipos
void leerPalabras(const char *filename, char palabras[MAX_WORDS][MAX_WORD_LEN], int *numPalabras);
void generarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
int colocarPalabra(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas);
void rellenarEspacios(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void guardarSopa(const char *filename, char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void mostrarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);

int main() {
    char sopa[MAX_SIZE][MAX_SIZE];
    char palabras[MAX_WORDS][MAX_WORD_LEN];
    int numPalabras = 0, filas, columnas;
    const char *diccionario = "diccionari.txt";
    const char *archivoSalida = "sopa.txt";

    // Leer palabras del fichero
    leerPalabras(diccionario, palabras, &numPalabras);
    if (numPalabras == 0) {
        printf("No se encontraron palabras en el fichero.\n");
        return 1;
    }

    // Solicitar dimensiones al usuario
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

// Leer palabras del fichero
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