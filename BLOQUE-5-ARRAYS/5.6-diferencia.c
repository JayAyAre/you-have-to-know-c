#include <stdio.h>

void imprimir_array_puntero(int *array);
void imprimir_array_corchetes(int array[]);

// Usando punteros
void imprimir_array_puntero(int *array) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

// Usando corchetes
void imprimir_array_corchetes(int array[]) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};

    // Llamadas a funciones
    imprimir_array_puntero(numeros); // Pasando como puntero
    imprimir_array_corchetes(numeros); // Pasando con corchetes

    return 0;
}
