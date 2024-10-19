#include <stdio.h>

//Ejercicio: imprimir por pantalla los numeros primos entre 2 y 2000
int main(){

    int primo = 1;

    for (int i = 2; i <= 2000; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                primo = 0;
                break;
            }
        }
        if (primo == 1)
            printf("%d\n", i);
        primo = 1;
    }
    return 0;
}