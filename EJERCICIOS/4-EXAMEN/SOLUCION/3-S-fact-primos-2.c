/*
    Diseña un programa con las siguientes características:

1. El programa pedirá dos números enteros al usuario:

    el primer número es el factor

    el segundo número representa cuántas veces un número debe ser divisible por dicho factor.

Si alguno de los dos números (factor o veces) es menor o igual a 0,
el programa acaba mostrando un mensaje de error: "Error en la entrada de datos"

2. Después, el usuario introducirá una secuencia de números enteros, uno por uno.

    La secuencia finaliza con el valor -1.

    La secuencia siempre será correcta, nunca estará vacía y todos los números serán positivos excepto el -1.

3. Elige una de las dos opciones:

    Versión 1. (3 puntos)

        El programa verificará si algún número de la secuencia es divisible por el factor. Muestra el resultado por pantalla.

    -> Versión 2. (5 puntos)

        El programa verificará si algún número de la secuencia se puede dividir por el factor el número de veces indicado o más. Muestra el resultado por pantalla.

    Ejemplo 1:

        factor = 3

        veces = 2

        secuencia: 15 45 51 47 21 94 -1 -> "El 45 divisible por 3 2 veces o más"

    Ejemplo 2:

        factor = 5

        veces = 1

        secuencia: 93 31 76 -1 "Ninguno puede dividirse por 5 1 veces o más"
 */

// En este implementaremos la version 2
// Es un recorrido

#include <stdio.h>

int main(void) {
    int factor, veces, vecesActual, numeroDividido, numero;
    int encontrado = 0;  // Indicador para saber si al menos un número cumple la condición

    printf("Factor: ");
    scanf("%d", &factor);

    printf("Veces: ");
    scanf("%d", &veces);

    if (factor <= 0 || veces <= 0) {
        printf("Error en la entrada de datos\n");
        return 1;
    }

    printf("Secuencia: ");
    while (1) {
        scanf("%d", &numero);

        if (numero == -1) {
            break;  // Termina cuando el número es -1
        }

        vecesActual = 0;
        numeroDividido = numero;

        // Contamos cuántas veces se puede dividir el número entre el factor
        while (numeroDividido % factor == 0) {
            vecesActual++;
            numeroDividido /= factor;
        }

        // Verificamos si cumple con el número mínimo de divisiones
        if (vecesActual >= veces) {
            printf("El %d es divisible por %d %d veces o más\n", numero, factor, veces);
            encontrado = 1;  // Marcamos que al menos un número cumple la condición
        }
    }

    // Si ningún número cumple la condición, mostramos el mensaje correspondiente
    if (!encontrado) {
        printf("Ninguno puede dividirse por %d %d veces o más\n", factor, veces);
    }

    return 0;
}