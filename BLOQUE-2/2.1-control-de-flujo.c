#include <stdio.h>

int main(){

    int x = 5;

    // La palabra if nos permite decidir si ejecutar un bloque de codigo o no
    /*
        Los operadores de comparación son:
        == igual
        != no igual
        < menor que
        <= menor o igual que
        > mayor que
        >= mayor o igual que
    */
    if (x == 5)
    {
        printf("x es igual a 5\n");
    } // La palabra else nos permite ejecutar un bloque de codigo si el if no se cumple
    else{
        printf("x no es igual a 5\n");
    }

    // Declaramos una variable entre 1 y 10, y por teclado solicitamos un numero, y verificamos si acertamos

    int y = 9, respuesta = 0;
    printf("Introduce el numero que crees que es:\n");

    if (scanf("%d", &respuesta) == y)
    {
        printf("El numero introducido es correcto\n");
    }else{
        printf("El numero introducido es incorrecto\n");
    }

    return 0;
}