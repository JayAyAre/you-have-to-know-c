#include <stdio.h>

// Ejercicio: realiza un programa que calcule la media de x numeros introducidos por teclado.
int main(){
    float suma = 0, media = 0, contador = 0;
    int numero = 0;

    printf("Introduce x numeros por teclado.\n");
    scanf("%f", &contador);

    for (int i = 0; i < contador; i++)
    {
        printf("Introduce el numero correspondiente a la posicion %d.\n", i);
        scanf("%d", &numero);
        suma += numero;
    }

    media = suma / contador;
    printf("La media es %.2f", media);
    return 0;
}