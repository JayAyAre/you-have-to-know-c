#include <stdio.h>

// Ejercicio: Intercambiar los valores de dos numeros enteros introducidos por teclado
int main(){

    int x, y, aux;

    printf("Introduce el valor de x:\n");
    scanf("%i", &x);

    printf("Introduce el valor de y:\n");
    scanf("%i", &y);

    aux = y;
    y = x;
    x = aux;

    printf("El valor de x es:\t%d\n", x);
    printf("El valor de y es:\t%d\n", y);

    return 0;
}