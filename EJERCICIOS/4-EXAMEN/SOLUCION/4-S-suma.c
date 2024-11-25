/*
    Implementa la funcion suma_multiplos

    Esta funcion recibe dos parametros:
        num1 (el número más bajo del intervalo, menor o igual a num2).
        num2 (el número más alto del intervalo).

    La funcion, debera calcular La suma de todos los múltiplos de 3 en un intervalo definido por los parámetros
    num1 (valor más bajo) y num2 (valor más alto), incluyendo ambos extremos si son múltiplos de 3.

    Ademas, por otro lado, debera calcular el producto tambien de todos los multiplos de 3 en el mismo intervalo.

    Se pasaran un 3r y un 4r parametros llamados suma y prod. por los cuales se debe devolver el resultado de la funcion.

    Ejemplo:

        num1 = 1
        num2 = 10

        suma = 3 + 6 + 9
        prod = 3 * 6 * 9
*/

#include <stdio.h>

void suma_multiplos(int num1, int num2, int* suma, int* prod);

int main() {
    int num1, num2;
    int suma, prod;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    suma_multiplos(num1, num2, &suma, &prod);

    printf("La suma es %d\n", suma);
    printf("El producto es %d\n", prod);

    return 0;
}

void suma_multiplos(int num1, int num2, int* suma, int* prod) {
    if (num1 >= num2){
        int suma_multiplos = 0;  // Inicializar la suma en 0
        int prod_multiplos = 1;  // Inicializar el producto en 1 (neutro del producto)
        int hay_multiplos = 0;   // booleano para manejar casos donde no haya múltiplos

        // Recorrer el rango [num1, num2]
        for (int i = num1; i <= num2; i++) {
            if (i % 3 == 0) {  // Verificar si es múltiplo de 3
                suma_multiplos += i;  // Sumar el múltiplo
                prod_multiplos *= i;  // Multiplicar el múltiplo
                hay_multiplos = 1;    // Marcar que hay al menos un múltiplo
            }
        }

        // Manejo del caso en que no hay múltiplos de 3 en el rango
        if (!hay_multiplos) {
            prod_multiplos = 0;  // Producto indefinido si no hay múltiplos
        }

        *suma = suma_multiplos;
        *prod = prod_multiplos;
    }else{
        *suma = -1;
        *prod = -1;
    }
}