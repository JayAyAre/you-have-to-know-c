#include <stdio.h>

int main(void)
{
    FILE *archivo;

    archivo = fopen("datos.txt", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    printf("Archivo abierto correctamente\n");
    fclose(archivo);
    return 0;
}