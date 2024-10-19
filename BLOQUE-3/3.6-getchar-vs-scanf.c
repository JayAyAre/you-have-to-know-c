#include <stdio.h>

// getchat y scanf
int main(){

    // getchar
    // Si queremos leer un caracter, podemos usar getchar
    printf("Introduce caracteres (presiona 'q' para salir):\n");
    char caracter;

    while (1) {
        caracter = getchar();

        // Ignorar el carácter de nueva línea (\n)
        if (caracter == '\n') {
            continue;  // Salta esta iteración del bucle y lee el siguiente carácter
        }

        // Si se introduce 'q', termina el bucle
        if (caracter == 'q') {
            break;
        }

        // Muestra el carácter que fue leído (que no es un \n)
        printf("Caracter introducido: %c\n", caracter);
    }

    // Con scanf, podemos especificar el tipo de dato ademas de evitar leer \n
    printf("\nIntroduce caracteres (presiona 'q' para salir):\n");
    caracter = ' ';
    while (1) {
        scanf(" %c", &caracter);  // El espacio antes de %c ignora los espacios y \n

        // Si se introduce 'q', termina el bucle
        if (caracter == 'q') {
            break;
        }

        // Muestra el carácter que fue leído
        printf("Caracter introducido: %c\n", caracter);
    }

    return 0;
}