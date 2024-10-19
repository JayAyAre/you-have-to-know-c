#include <stdio.h>

// Funciones
int maxima(int a, int b); // Declaramos la funcion

// Si la funcion esta por encima del main, no hace falta declararla

// Calcular el numero maximo entre dos numeros con una funcion
int main(){
    int numero_1, numero_2, max;
    printf("Introduce dos numeros por teclado.\n");
    scanf("%d %d", &numero_1, &numero_2);   // Leemos dos numeros por teclado ej: 23 55 <CR>

    max = maxima(numero_1, numero_2);       // Llamamos la funcion y le pasamos los valores
    printf("El numero maximo (maxima) es %d\n", maxima(numero_1, numero_2)); // Llamamos la funcion y le pasamos los valores
    printf("El numero maximo (max) es %d\n", max);
    return 0;
}

int maxima(int a, int b){
    // La palabra sirve para devolver un valor al llamar una funcion
    if (a > b)
        return a;
    else
        return b;
}