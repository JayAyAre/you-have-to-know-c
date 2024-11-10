/*
    Diseña un programa con las siguientes características:

    1. El programa pedirá al usuario un número entero positivo.

    2. Si el número es menor o igual a 0, mostrará el mensaje: "Número no válido".

    3. Si el número es positivo, calculará el factorial del número ingresado
    y mostrará el resultado con el mensaje: "El factorial de [número] es [resultado]".

*/

#include <stdio.h>

int main(void) {
    int numero;
    unsigned long long factorial = 1;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Número no válido\n");
    } else {
        for (int i = 1; i <= numero; i++) {
            factorial *= i;
        }
        printf("El factorial de %d es %llu\n", numero, factorial);
    }

    return 0;
}
