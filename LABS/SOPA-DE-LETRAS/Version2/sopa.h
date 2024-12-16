#ifndef SOPA_H
#define SOPA_H

#define MAX_SIZE 20
#define MIN_SIZE 10
#define MAX_WORDS 30
#define MAX_WORD_LEN 20

void generarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
int colocarPalabra(char sopa[MAX_SIZE][MAX_SIZE], const char *palabra, int filas, int columnas);
void rellenarEspacios(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void guardarSopa(const char *filename, char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void mostrarSopa(char sopa[MAX_SIZE][MAX_SIZE], int filas, int columnas);

#endif
