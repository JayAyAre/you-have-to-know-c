/*
    Diseña un programa que reciba un número entero y cuente cuántos dígitos tiene.

    1. El programa pedirá un número entero positivo.

    2. El programa debe contar cuántos dígitos tiene el número ingresado.

    3. Si el número es menor o igual a 0, el programa debe mostrar el mensaje "Número no válido".
*/

#include <stdio.h>

int main(void) {
    int numero, contador = 0;

    printf("Ingrese un número entero positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Número no válido\n");
    } else {
        while (numero > 0) {
            numero = numero / 10;
            contador++;
        }
        printf("El número tiene %d dígitos\n", contador);
    }

    return 0;
}
