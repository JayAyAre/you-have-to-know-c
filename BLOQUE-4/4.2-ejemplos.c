#include <stdio.h>

// ejemplos

// Calcular el factorial de 2 numeros con una funcion
int factorial(int a);

// Calcular si dos numeros diferentes son primos con una funcion
int primos(int a);

// Calcular el numero maximo entre dos numeros con una funcion
int main(){
    int numero_1 = 3, numero_2 = 5;

    int fact1 = factorial(numero_1);
    int fact2 = factorial(numero_2);

    printf("El factorial de %d es %d\n", numero_1, fact1);
    printf("El factorial de %d es %d\n", numero_2, fact2);

    int primo1 = primos(numero_1);
    int primo2 = primos(numero_2);

    printf("El numero %d es primo: %d\n", numero_1, primo1);
    printf("El numero %d es primo: %d\n", numero_2, primo2);

    return 0;
}

// Devuelve el factorial de un numero
int factorial(int a){
    int resultado = 1;
    for (int i = 1; i <= a; i++)
        resultado *= i;
    return resultado;
}

// Devuelve 1 si los numeros son primos, 0 si no 
int primos(int a){
    int primo = 1;
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            primo = 0;
            break;
        }
    }
    return primo;
}