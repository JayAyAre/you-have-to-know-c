// Arrays en funciones

#include <stdio.h>

// introducir elementos a un vector
void fun(int a[]);
void imprimir_vector(int a[]);

int main(){

    // Para los vectores, no hace falta pasar por referencia.
    int v[5];

    fun(v);

    imprimir_vector(v);

    return 0;
}

void imprimir_vector(int a[]){
    for (int i = 0; i < 5; i++)
        printf("El valor de la posicion %d es %d\n", i, a[i]);
}

void fun(int a[]){
    for (int i = 0; i < 5; i++)
    {
        printf("Introduce el valor de la posicion %d.\n", i);
        scanf("%d", &a[i]);
    }
}