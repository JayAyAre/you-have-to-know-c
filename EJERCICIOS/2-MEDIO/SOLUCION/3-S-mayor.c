/*
    Diseña un programa con las siguientes características:

    1. El programa pedirá al usuario una secuencia de números enteros.

    2. La secuencia finalizará cuando el usuario introduzca el número 0.

    3. El programa identificará y mostrará el número mayor de la secuencia ingresada.

    4. Si el usuario solo ingresa 0, el programa mostrará el mensaje "Secuencia vacía".

*/

#include <stdio.h>

int main(void) {
    int numero, mayor = -1;
    int hayNumero = 0;

    printf("Ingrese una secuencia de números (0 para finalizar):\n");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        hayNumero = 1;  // Se ha ingresado al menos un número
        if (numero > mayor) {
            mayor = numero;
        }
    }

    if (hayNumero) {
        printf("El número mayor es: %d\n", mayor);
    } else {
        printf("Secuencia vacía\n");
    }

    return 0;
}
