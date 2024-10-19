#include <stdio.h>

// Ejercicio: imprimir por pantalla si un numero es primo o no
int main(){
    int primo = 0;
    int es_primo = 0;

    printf("Introduce un numero por teclado.\n");
    scanf("%d", &primo);

    for (int i = 2; i <= primo; i++)
    {
        if (primo % i == 0)
        {
            es_primo = 0;
            break;  // Permite salir del bucle inmediatamente
        }
        else
        {
            es_primo = 1;
        }
    }

    if (es_primo == 1)
    {
        printf("%d es primo\n", primo);
    }
    else
    {
        printf("%d no es primo\n", primo);
    }
    return 0;
}