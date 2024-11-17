#include <stdio.h>

int main(void)
{
    float temperatura[100];
    float fahrenheit;
    FILE *archivo;
    archivo = fopen("datos.txt", "r");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    printf("Archivo abierto correctamente\n");

    int i = 0;
    while (fscanf(archivo, "%f", &fahrenheit) == 1)
    {
        if (i >= 100)
        {
            break;
        }

        if (fahrenheit != -999.9)
        {
            temperatura[i] = (fahrenheit - 32) * 5 / 9;
            i++;
        }
    }

    int j = i;
    i = 0;
    float suma = 0;
    while (i < j)
    {
        printf("Temperatura: %.2f\n", temperatura[i]);
        suma += temperatura[i];
        i++;
    }
    printf("Media: %.2f\n", suma / j);
}
