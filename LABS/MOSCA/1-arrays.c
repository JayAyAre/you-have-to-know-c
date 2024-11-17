// Los arrays/vector nacen de donde guardar numerosas variables
#include <stdio.h>

int main(){
    int numero_1, numero_2, numero_3, numero_4, numero_5;
    numero_1 = 1;
    numero_2 = 2;
    numero_3 = 3;
    numero_4 = 4;
    numero_5 = 5;

    // En vez de tener 5 variables diferentes o mas, las podemos guardar en un array/vector

    int vector[] = {1, 2, 3, 4, 5};

    // Si tenemos 5 elementos, sus posiciones son 0, 1, 2, 3, 4
    // Siempre desde 0 hasta el numero de elementos - 1

    printf("El valor de la posicion 0 es %d\n", vector[0]);
    printf("El valor de la posicion 1 es %d\n", vector[1]);
    printf("El valor de la posicion 2 es %d\n", vector[2]);
    printf("El valor de la posicion 3 es %d\n", vector[3]);
    printf("El valor de la posicion 4 es %d\n\n", vector[4]);

    for (int i = 0; i < 5; i++){
        printf("El valor de la posicion %d es %d\n", i, vector[i]);
    }

    // Darle valor a un vector de 10 posiciones, y imprimirlo
    int vector_2[10];
    for (int i = 0; i < 10; i++){
        printf("Introduce el valor de la posicion %d.\n", i);
        scanf("%d", &vector_2[i]);
    }

    for (int i = 0; i < 10; i++){
        printf("El valor de la posicion %d es %d\n", i, vector_2[i]);
    }



    return 0;
}