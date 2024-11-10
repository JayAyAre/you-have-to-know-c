// Punteros en vectores
#include <stdio.h>

void imprimir_array_puntero(int *array);

void imprimir_array_puntero(int *array) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};

    // Llamadas a funciones
    imprimir_array_puntero(numeros); // Pasando como puntero
    printf("%x", 16); // Imprimir en hexadecimal
    return 0;
}