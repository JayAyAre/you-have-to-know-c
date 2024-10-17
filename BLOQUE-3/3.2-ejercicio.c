#include <stdio.h>

// Ejercicio: Imprime la suma de los numeros pares entre dos y mil
int main(){
    float suma;

    for (int i = 0; i <= 1000; i++)
    {
        if (i % 2 == 0)
        {
            suma += i;
        }
    }

    printf("La suma de los numeros pares entre 0 y 1000 es %.2f", suma);
    return 0;
}