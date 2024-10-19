#include <stdio.h>
#include <windows.h>

int main(){
    int h, min, seg, x; // tenemos 3 numeros que queremos que se incrementen independientemente


    for (int h = 0; h < 24; h++)
    {
        for (int min = 0; min < 60; min++)
        {
            for (int seg = 0; seg < 60; seg++)
            {
                printf("%02d:%02d:%02d\n", h, min, seg);
                // Si queremos indicar la cantidad de numeros que se enseñen, colocamos 02. indica 2 numeros a enseñar
                // y usando \r en vez de \n, se reemplaza la linea actual
                Sleep(1000);    // Pausa 1 segundo, se coloca en milisegundos
            }
            printf("\n");
        }
    }

    return 0;
}