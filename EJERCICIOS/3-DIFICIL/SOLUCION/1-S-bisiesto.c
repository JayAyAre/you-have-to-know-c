/*
    Diseña un programa que determine si un año es bisiesto o no. 

    1. El programa pedirá al usuario un número que representa el año.

    2. Si el año es divisible entre 4, pero no es divisible entre 100, o si es divisible entre 400, entonces el año es bisiesto.

    3. Si el año es bisiesto, el programa debe imprimir "El año [año] es bisiesto", y si no lo es, debe imprimir "El año [año] no es bisiesto".

    4. Si el número ingresado es menor o igual a 0, el programa debe mostrar el mensaje "Año no válido".

*/

#include <stdio.h>

int main(void) {
    int año;

    printf("Ingrese un año: ");
    scanf("%d", &año);

    if (año <= 0) {
        printf("Año no válido\n");
    } else {
        if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) {
            printf("El año %d es bisiesto\n", año);
        } else {
            printf("El año %d no es bisiesto\n", año);
        }
    }

    return 0;
}
