#include <stdio.h>

// Ejercicio: Haz un programa que verifique si un numero esta entre 1 y 10. o si no lo esta.
int main(){
    int x = 0;

    printf("Introduce el primer valor numerico por teclado.");
    scanf("%d", &x);

    /*
        A veces vamos a querer utilizar condiciones multiples, por ejemplo,
        si un numero es mayor que 10 y menor que 20, o si es mayor que 20 y menor que 30.

        Para ello usamos los operadores lógicos, los cuales nos permiten comparar dos condiciones.
        ellos son:
            - AND que se representa como &&
            - OR que se representa como ||
            - NOT que se representa como !

        en este caso && nos permite ejecutar un codigo, solo cuando ambas son verdaderas.
    */

    if (x >= 1 && x <= 10){
        printf("El numero %d esta entre 1 y 10", x);
    }else{
        printf("El numero %d no esta entre 1 y 10", x);
    }

    return 0;
}