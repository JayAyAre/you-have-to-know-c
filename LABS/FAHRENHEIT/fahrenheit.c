#include <stdio.h>
#define MAX_TEMPERATURES 1000

int main(){
    float taula_temperatures_celsius[MAX_TEMPERATURES] = {0.0};
    float celsius, farenhite;
    // recordemos, los fahrenheit son de van a partir de -459.67
    // y los celsius van a partir de -273.15
    int i = 0;
    FILE *file;

    file = fopen("fitxer_amb_temperatures.txt", "r");

    if (file == NULL)
    {
        printf("Error al abrir el archivo");
    }else{
        while (fscanf(file, "%f", &farenhite) != EOF) {
        // Si la temperatura es -999.9, simplemente se imprime
            if (farenhite == (float)-999.9) {
                printf("%.1f farenhite\n", farenhite);
            } else {
                // Convertir a Celsius
                celsius = (farenhite - 32) / 1.8;
                printf("%.2f celsius\n", celsius);

                // Almacenar la temperatura en Celsius en la tabla
                if (i < MAX_TEMPERATURES) {
                    taula_temperatures_celsius[i] = celsius;
                    i++;
                } else {
                    printf("Taula de temperatures plena!\n");
                    break;
                }
            }
        }
    }


    return 0;
}