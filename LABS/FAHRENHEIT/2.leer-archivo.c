#include <stdio.h>

int main(){
    // Algunas veces, queremos leer un archivo de texto
    // Para ello, podemos hacer esto:

    // Declaramos el archivo como variable
    FILE *archivo;

    // Abrimos el archivo con fopen
    archivo = fopen("archivo.txt", "r");
    // El segundo parametro varia en funcion de nuestro objetivo
    // Existen estos tipos de archivos:
    // - r: Abre un archivo existente para lectura
    // - w: Crea un archivo nuevo para escritura, o sobreescribe un archivo existente
    // - a: Abre un archivo y agrega datos al final
    // - r+: Abre un archivo existente para lectura y permite que se escriba en él
    // - w+: Crea un archivo nuevo para escritura, o sobreescribe un archivo existente

    // Si el archivo no existe, se imprime un mensaje
    if (archivo == NULL)
    {
        printf("El archivo no existe");
        return 0;
    }

    // Para leer su contenido, podemos hacer esto:
    // - fgetc: Lee un caracter
    // - fgets: Lee una linea
    // - fscanf: Lee datos formateados del archivo, similar a scanf().

    char c;
    // Leemos caracter por caracter
    while (( c = fgetc(archivo)) != EOF)
    {
        printf("%c", c);
    }

    printf("\n");

    // Leemos linea por linea
    char linea[100];
    while (fgets(linea, 100, archivo) != NULL)
    {
        printf("%s", linea);
    }

    fclose(archivo);
    return 0;
}