#include <stdio.h>

// Ejercicio: segun un valor numerico introducido por teclado, indicar si es par o impar.
int main(){
    int x;

    printf("Introduce el valor numerico por teclado.");
    scanf("%d", &x);

    if (x % 2 == 0)
    {
        printf("El numero es par");
    }else{
        printf("El numero es impar");
    }

    return 0;
}