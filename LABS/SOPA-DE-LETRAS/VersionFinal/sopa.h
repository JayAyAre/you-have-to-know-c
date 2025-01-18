#ifndef SOPA_H
#define SOPA_H

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_WORDS 30
#define MAX_WORD_LEN 20

void leerPalabras(const char *filename, char palabras[MAX_WORDS][MAX_WORD_LEN], int *numPalabras); // Lee palabras de un archivo
void generarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas); // Genera una sopa de letras vacía
int colocarPalabraAleatoria(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas); // Coloca una palabra de manera aleatoria
int colocarPalabraHorizontal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len); // Coloca una palabra horizontalmente
int colocarPalabraVertical(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len); // Coloca una palabra verticalmente
int colocarPalabraDiagonal(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas, int len); // Coloca una palabra diagonalmente
void rellenarEspacios(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas); // Rellena los espacios vacíos con letras aleatorias
void guardarSopa(const char *filename, char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas); // Guarda la sopa en un archivo
void mostrarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas); // Muestra la sopa en pantalla
int generarDireccionAleatoria(); // Genera una dirección aleatoria para colocar palabras
double calcularLongitudMedia(char palabras[MAX_WORDS][MAX_WORD_LEN], int numPalabras); // Calcula la longitud media de las palabras

#endif
