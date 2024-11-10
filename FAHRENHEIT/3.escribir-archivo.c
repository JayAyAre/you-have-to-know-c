#include <stdio.h>

int main() {
    FILE *archivo;
    char nombre[50];

    // Abrir el archivo en modo escritura (crea si no existe, sobreescribe si existe)
    archivo = fopen("escribir.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    printf("Ingrese un nombre: ");
    scanf("%s", nombre);

    // Escribir el nombre en el archivo
    fprintf(archivo, "Hola, %s!\n", nombre);
    fprintf(archivo, "Hola, %s!\n", nombre);

    // Cerrar el archivo
    fclose(archivo);

    printf("Datos escritos en el archivo.\n");

    return 0;
}