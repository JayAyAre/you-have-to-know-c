// Calcula la probabilidad de que salgan cada uno de los numeros de un dado de 6 caras.
// Mediante un vector de punteros. tirando los dados 10000 veces.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sorteo(int *v);
void imprimir_vector(int *a);

int main(){
    int v[6] = {0, 0, 0, 0, 0, 0};

    sorteo(v);
    imprimir_vector(v);
    return 0;
}

// Función que imprime las probabilidades de cada número
void imprimir_vector(int *a) {
    float aux = 0;
    for (int i = 0; i < 6; i++) {
        // Acceso mediante puntero: *(a + i) es equivalente a a[i]
        aux = (*(a + i) * 100.0) / 10000.0; // Calcula la probabilidad en porcentaje
        printf("La probabilidad de que salga el número %d es %.2f%%\n", i + 1, aux);
    }
}


// Tira los dados 10000 veces y suma 1 a cada uno de los 6 numeros del vector.
void sorteo(int *v) {
    srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios

    int aux;
    for (int i = 0; i < 10000; i++) {
        aux = rand() % 6; // Genera un número aleatorio entre 0 y 5
        (*(v + aux))++; // Incrementa el contador correspondiente usando aritmética de punteros
    }
}