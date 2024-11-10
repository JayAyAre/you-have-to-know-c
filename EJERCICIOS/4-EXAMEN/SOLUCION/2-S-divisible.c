/*
Ejercicio 2. ¿Cuántas veces es divisible?

Diseña un procedimiento (prototipo, documentación e implementación)
que reciba dos números enteros y positivos: un número base y un factor.
Ambos números deben ser mayores que 0.

El procedimiento debe calcular y devolver cuántas veces se puede dividir
el número base por el factor de forma entera antes de que deje de ser divisible.

Por ejemplo, si base = 60 y factor = 2, el resultado debe ser 2, ya que 60 se
puede dividir por 2 dos veces antes de no ser divisible (60 ÷ 2 = 30, 30÷2= 15, y
15 ya no es divisible por 2).

base = 60

factor = 2

resultado = 2
 */

#include <stdio.h>

int divisible(int base, int factor);

/* Funcion que recibe dos números enteros y positivos: un número base y un factor.
    @param base Número base
    @param factor Factor
    @return Número de veces que se puede dividir el número base por el factor antes de que deje de ser divisible
*/

int divisible(int base, int factor){
    int resultado = 0;
    while (base % factor == 0)
    {
        resultado++;
        base = base / factor;
    }
    return resultado;
}