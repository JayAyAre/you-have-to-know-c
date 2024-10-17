#include <stdio.h>
#define PI 3.1416   // Constante que guarda en PI, el valor de 3.1416.
// Es una constante ya que su valor dentro del codigo, no se puede modificar.

int main(){
    float x;
    int y = 0;

    x = PI; // x tendra el valor que tiene la constante PI

    printf("Introduce el valor para y: ");
    scanf("%d", &y);    // Escanea el valor introducido por el usuario en el teclado
    printf("El valor de y es: %d", y);

    x = x + y;

    printf("El valor de x es: %f", x);
    return 0;
}