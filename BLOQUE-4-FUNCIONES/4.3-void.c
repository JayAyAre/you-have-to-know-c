#include <stdio.h>

// ejemplos
void factorial(int a);

// las funciones de tipo void no devuelven valores

int main(){
    int numero_1 = 3;

    factorial(numero_1);

    return 0;
}

void factorial(int a){
    int resultado = 1;
    for (int i = 1; i <= a; i++)
        resultado *= i;
    printf("El factorial de %d es %d\n", a, resultado);
}

