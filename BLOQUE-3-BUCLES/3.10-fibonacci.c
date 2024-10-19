#include <stdio.h>

// Ejercicio: Calcular el numero de Fibonacci por teclado
int main(){
    int numero_entrada = 0;
    int resultado = 0, fibonacci1 = 0, fibonacci2 = 1;

    printf("Introduce un numero por teclado.\n");
    scanf("%d", &numero_entrada);

    for (int i = 1; i <= numero_entrada; i++)
    {
        printf("%d\n", fibonacci1);
        resultado = fibonacci1 + fibonacci2;
        fibonacci1 = fibonacci2;
        fibonacci2 = resultado;
    }

    return 0;
}