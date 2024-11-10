/*
    Diseña un programa con las siguientes características:

    1. El programa pedirá al usuario que introduzca una secuencia de números enteros.

    2. La secuencia finalizará cuando el usuario introduzca el número 0.

    3. El programa contará cuántos números positivos y cuántos números negativos se han introducido,
    y mostrará el resultado al final.

*/

#include <stdio.h>

int main(void) {
    int numero;
    int positivos = 0, negativos = 0;

    printf("Ingrese una secuencia de números (0 para finalizar):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        } else if (numero > 0) {
            positivos++;
        } else {
            negativos++;
        }
    }

    printf("Números positivos: %d\n", positivos);
    printf("Números negativos: %d\n", negativos);

    return 0;
}
