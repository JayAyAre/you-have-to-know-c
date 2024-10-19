#include <stdio.h>
#include <string.h>

void imprimir_string(char *str);

int main() {
    char str[] = "Hola, mundo!"; // Definimos un array de caracteres con un string
    char *ptr = str; // Declaramos un puntero que apunta al array de caracteres

    // Imprimir el string usando el puntero
    printf("El string es: %s\n", ptr);

    // Acceder a cada carácter usando el puntero
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c ", *(ptr + i));
    }

    printf("\nLos caracteres del string son:\n");
    while (*ptr != '\0') { // Recorre hasta el final del string
        printf("%c ", *ptr);
        ptr++; // Mueve el puntero al siguiente carácter
    }

    ptr = &str[0]; // Reiniciamos el puntero

    printf("\n");

    imprimir_string(ptr); // Imprimimos el string usando el puntero

    return 0;
}

void imprimir_string(char *str) {
    for (int i = 0; i < 13; i++) {
        printf("%c ", str[i]);

    }
    printf("\n");
}