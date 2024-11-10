/*
    Diseña un programa que reciba tres números enteros y determine cuál de ellos es el menor.

    1. El programa pedirá al usuario tres números enteros.

    2. El programa debe comparar los tres números y mostrar el número más pequeño.

    3. Si todos los números son iguales, el programa debe mostrar el mensaje: "Todos los números son iguales".

    4. Si alguno de los números es menor o igual a 0, el programa debe mostrar "Número no válido".

*/

#include <stdio.h>

int main(void) {
    int num1, num2, num3;

    printf("Ingrese tres números enteros: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 <= 0 || num2 <= 0 || num3 <= 0) {
        printf("Número no válido\n");
    } else if (num1 == num2 && num2 == num3) {
        printf("Todos los números son iguales\n");
    } else {
        int min = num1;
        if (num2 < min) min = num2;
        if (num3 < min) min = num3;
        printf("El número menor es: %d\n", min);
    }

    return 0;
}
