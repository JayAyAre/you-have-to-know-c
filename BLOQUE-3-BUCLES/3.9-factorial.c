#include <stdio.h>

// Ejercicio: Calcular el factorial de un numero por teclado
int main(){
    int factorial = 1;
    int numero_entrada = 0;

    printf("Introduce un numero por teclado.\n");
    scanf("%d", &numero_entrada);

    for (int i = 1; i <= numero_entrada; i++)
    {
        factorial *= i;
    }

    printf("El factorial de %d es %d\n", numero_entrada, factorial);

    return 0;
}