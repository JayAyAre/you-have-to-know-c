/*
    El parametro de direccion

        El parametro de direccion es el &. con este simbolo indicamos la DIRECCION de una variable
        donde queremos guardar un valor.

        por ejemplo, al usar scanf, le pasamos el valor de la direccion de la variable a la que queremos
        guardar el valor leido por teclado.
        de tal manera que podemos sobreescribir el contenido de esa direccion perteneciente a la variable.

        scanf("%d", &numero_1); asi por ejemplo.

    El puntero o parametro de indireccion

        El puntero o parametro de indireccion es el *. con este simbolo
        SEÑALAMOS el valor de la direccion dada. se usa para el paso de parametros por referencia.

        indicamos el valor del contenido de una direccion dada, por ejemplo:
        int *numero_1;
        numero_1 = &numero_2;

        Aqui numero_1 es un puntero o parametro de indireccion, y numero_2 es una variable.
        En este caso, numero_1 contiene el valor de numero 2, y &numero_2 es la direccion de la variable numero_2.
*/

// https://www.youtube.com/watch?v=LtRtU3auCVo

#include <stdio.h>

void cambio(int *a, int *b, int c);

int main(){
    int valor, *puntero, z, w = 0;

    valor = 4;
    puntero = &valor;

    printf("x: %d\n", valor);
    printf("y: %d\n", *puntero);
    printf("&x: %x\n", puntero);

    *puntero = 300;
    printf("x: %d\n", valor);
    printf("y: %d\n", *puntero);

    // Direcciones
    valor = 4;
    z = 10;

    printf("\nx: %d\n", valor);
    printf("z: %d\n", z);
    printf("w: %x\n", w);

    cambio(&valor, &z, w);

    printf("\nx: %d\n", valor);
    printf("z: %d\n", z);
    printf("w: %x\n", w);
    return 0;
}

// Con la referencia, podemos devolver la cantidad de variables que queramos en una funcion

void cambio(int *a, int *b, int c){ // x = &x y por tanto, x* sera lo mismo que x
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    c = 100;
}