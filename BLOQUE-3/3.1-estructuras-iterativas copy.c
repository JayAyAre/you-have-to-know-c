#include <stdio.h>

// Escribe un programa que lea dos numeros, y que muestro todos los numeros comprendidos entre ellos dos
// Ejemplo, si se introducen 1, 10, el programa debe mostrar los numeros comprendidos entre 1 y 10.
// es decir: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
int main(){
    int x, y, i;

    // i sera nuestro contador. normalmente se suele usar i, j, k, etc

    printf("Introduce el primer numero por teclado.\n");
    scanf("%d", &x);

    printf("Introduce el segundo numero por teclado.\n");
    scanf("%d", &y);

    // La estructura for, nos permite iterar sobre un rango de numeros
    // y ejecutar un bloque de codigo para cada numero
    // la estructura for tiene 3 partes:
    // 1. la parte inicial, es la definicion del contador/iterador
    // 2. la parte la condicion, es la que verificaremos para mantener que el for se ejecute
    // 3. la parte del incremento, es como manejaremos el contador despues de cada iteracion
    for (i = x; i <= y; i++){
        printf("%d\n", i);
    }

    // La estructura while, a diferencia del for, normalmente se usa para hacer un bucle
    // el cual no sabemos cuantas iteraciones se van a ejecutar, sino que se va a ejecutar hasta que
    // se cumpla una condicion. en este caso, la condicion es que el contador sea menor o igual que
    // el numero que le damos al programa.
    i = x;
    while (i <= y)
    {
        printf("%d\n", i);
        i++;
    }

    printf("\n");
    return 0;
}