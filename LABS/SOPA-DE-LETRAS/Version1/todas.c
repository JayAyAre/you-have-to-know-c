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
int colocarPalabraAleatoria(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas);
int colocarPalabraHorizontal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len);
int colocarPalabraVertical(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len);
int colocarPalabraDiagonal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len);
void rellenarEspacios(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void guardarSopa(const char *filename, char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void mostrarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
int generarDireccionAleatoria(); // Para elegir la dirección

int main() {
    srand(time(NULL));
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

    // Asegurarse de colocar al menos 5 palabras
    int palabrasColocadas = 0;
    for (int i = 0; i < numPalabras && palabrasColocadas < 5; i++) {
        if (colocarPalabraAleatoria(sopa, palabras[i], filas, columnas)) {
            palabrasColocadas++;
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

// Función que genera una dirección aleatoria: 0 = horizontal, 1 = vertical, 2 = diagonal
int generarDireccionAleatoria() {
    return rand() % 3;
}

// Colocar una palabra de forma aleatoria
int colocarPalabraAleatoria(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas) {
    int direccion = generarDireccionAleatoria();
    int len = 0;

    // Longitud de la palabra
    while (palabra[len] != '\0') len++;

    if (direccion == 0) { // Horizontal
        return colocarPalabraHorizontal(sopa, palabra, filas, columnas, len);
    } else if (direccion == 1) { // Vertical
        return colocarPalabraVertical(sopa, palabra, filas, columnas, len);
    } else { // Diagonal
        return colocarPalabraDiagonal(sopa, palabra, filas, columnas, len);
    }
}

// Colocar la palabra horizontalmente
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

// Colocar la palabra verticalmente
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

// Colocar la palabra diagonalmente
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

// Rellenar espacios vacíos con letras aleatorias
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
