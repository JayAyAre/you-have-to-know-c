#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEA 100
#define MAX_TEMPERATURAS_POR_LINEA 10 // Ajusta según tus necesidades
#define MAX_TEMPERATURES 1000

int main() {
    FILE *archivo;
    char linea[MAX_LINEA];
    double temperatura;
    int i = 0, j, k = 0;
    float taula_temperatures_celsius[MAX_TEMPERATURES] = {0.0};
    float celsius, farenhite;

    // Abrir el archivo en modo lectura
    archivo = fopen("temperaturas.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Leer cada línea del archivo
    while (fgets(linea, MAX_LINEA, archivo) != NULL && i < MAX_TEMPERATURAS_POR_LINEA) {
        char *token;
        j = 0; // Reiniciar el contador de temperaturas por línea

        // Tokenizar la línea por comas
        token = strtok(linea, ",");
        while (token != NULL && j < MAX_TEMPERATURAS_POR_LINEA) {
            // Convertir la cadena a un número real
            if (sscanf(token, "%lf", &temperatura) == 1) {
                if (farenhite == (float)-999.9) {
                    printf("%.1f farenhite\n", farenhite);
                } else {
                    // Convertir a Celsius
                    celsius = (farenhite - 32) / 1.8;
                    printf("%.2f celsius\n", celsius);

                    // Almacenar la temperatura en Celsius en la tabla
                    if (k < MAX_TEMPERATURES) {
                        taula_temperatures_celsius[k] = celsius;
                        k++;
                    } else {
                        printf("Taula de temperatures plena!\n");
                        break;
                    }
                }
                j++;
            } else {
                printf("Error al leer una temperatura en la línea %d\n", i+1);
            }
            token = strtok(NULL, ",");
        }
        i++;


    fclose(archivo);

    return 0;
}