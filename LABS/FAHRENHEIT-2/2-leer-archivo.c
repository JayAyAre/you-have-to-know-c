#include <stdio.h>

int main(void)
{
    FILE *archivo;
    float temperatura;
    archivo = fopen("datos.txt", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    printf("Archivo abierto correctamente\n");

    while (fscanf(archivo, "%f", &temperatura) == 1)
    {
        printf("Temperatura: %.2f\n", temperatura);
    }
}