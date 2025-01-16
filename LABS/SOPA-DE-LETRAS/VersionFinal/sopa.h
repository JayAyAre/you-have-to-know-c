#ifndef SOPA_H
#define SOPA_H

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
int generarDireccionAleatoria();
double calcularLongitudMedia(char palabras[MAX_WORDS][MAX_WORD_LEN], int numPalabras);

#endif // SOPA_H
