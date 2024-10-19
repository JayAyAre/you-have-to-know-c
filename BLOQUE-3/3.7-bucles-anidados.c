#include <stdio.h>

// bucles anidados
// Tabla de multiplicar del numero 1 a 9
int main(){
    int contador = 0;

    // Suelen ser usados cuando queremos que los numeros funcionen de manera independiente
    int numero_1 = 0, numero_2 = 0;
    int pausa = 0;

    for (int numero_1 = 1; numero_1 < 10; numero_1++)
    {
        for (int numero_2 = 1; numero_2 < 10; numero_2++)
        {
            printf("Tabla del %d = %d * %d\n", numero_1, numero_2, numero_1 * numero_2);
        }
        printf("\n");
        scanf(" %d", &pausa);
    }
    return 0;
}