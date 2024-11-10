// Los arrays/vector nacen de donde guardar numerosas variables
#include <stdio.h>

int main(){

    // Si queremos tener varias variables diferentes, podemos hacer esto pero es
    // poco eficiente

    int numero_1, numero_2, numero_3, numero_4, numero_5;
    numero_1 = 1;
    numero_2 = 2;
    numero_3 = 3;
    numero_4 = 4;
    numero_5 = 5;

    // Por otro lado, metemos los arrays, lo cual seria hacer esto:
    // En este caso, permite tener un vector de 1000 posiciones con valores iniciales a 0.0

    float temperaturas[1000] = {0.0};
    printf("El valor en la posición 0 es: %f", temperaturas[0]);

    // Esto permite declarar un array de las posiciones que quieras
    // Sin embargo, se debe tener en cuenta que debe tener cuidado ya que asignar
    // x posiciones al inicio es peligroso, ya que puede ocupar mucho espacio en memoria
    // Pero ese problema lo resolveremos mas adelante

    // Para recorrer un array o vector, podemos hacer esto:

    for (int i = 0; i < 1000; i++)
    {
        printf("Temperatura de la posicion %d es %f \n", i, temperaturas[i]);
    }


    return 0;
}