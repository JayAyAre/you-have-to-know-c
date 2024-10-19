#include <stdio.h>

// Ejercicio: indicar cual es el numero maximo de 3 valores.
int main(){
    int x, y, z;

    printf("Introduce el primer valor numerico por teclado.");
    scanf("%d", &x);

    printf("Introduce el segundo valor numerico por teclado.");
    scanf("%d", &y);

    printf("Introduce el tercer valor numerico por teclado.");
    scanf("%d", &z);

    if(x > y){
        if(x > z){
            printf("El numero %d es el mayor", x);
        }else{
            printf("El numero %d es el mayor", z);
        }
    }else{
        if(y > z){
            printf("El numero %d es el mayor", y);
        }else{
            printf("El numero %d es el mayor", z);
        }
    }
    return 0;
}