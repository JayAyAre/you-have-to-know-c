/*
    Diseña un programa con las siguientes características:

    1. El programa pedirá al usuario un número entero positivo.

    2. Si el número es menor o igual a 1, mostrará el mensaje: "Número no válido".

    3. Si el número es mayor a 1, el programa verificará si es un número primo.

    4. Si el número es primo, mostrará el mensaje: "El número es primo".
    De lo contrario, mostrará "El número no es primo".

*/

#include <stdio.h>

int main(void) {
    int numero, esPrimo = 1;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    if (numero <= 1) {
        printf("Número no válido\n");
    } else {
        for (int i = 2; i <= numero / 2; i++) {
            if (numero % i == 0) {
                esPrimo = 0;
                break;
            }
        }

        if (esPrimo) {
            printf("El número es primo\n");
        } else {
            printf("El número no es primo\n");
        }
    }

    return 0;
}
