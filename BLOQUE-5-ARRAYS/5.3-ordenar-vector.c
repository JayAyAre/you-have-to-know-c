// Arrays en funciones
// Ordenar el vector de menor a mayor

#include <stdio.h>

void imprimir_vector(int a[]);
void ordenar_vector(int a[]);

int main(){

    // Para los vectores, no hace falta pasar por referencia.
    int v[5] = {5, 3, 2, 6, 1};

    imprimir_vector(v);
    ordenar_vector(v);
    imprimir_vector(v);


    return 0;
}

void imprimir_vector(int a[]){
    for (int i = 0; i < 5; i++)
        printf("El valor de la posicion %d es %d\n", i, a[i]);
    printf("\n");
}

void ordenar_vector(int a[]){
    int aux;
    for (int i = 0; i < 5; i++){
        for (int j = i; j < 5; j++){
            if (a[i] > a[j])
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}