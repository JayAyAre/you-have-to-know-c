#include <stdio.h>

// Bucle do-while
int main(){
    int contador = 0;

    // Si probamos con un while:
    while (contador > 10)
    {
        printf("El valor de contador (while) es: %d\n", contador);
        contador++;
    }

    do
    {
        printf("El valor de contador (do-while) es: %d\n", contador);
        contador++;
    } while (contador > 10);

    // Se utiliza sobre todo para casos asi:
    // Realiza un bucle mientras no se introduzca el caracter 's' o 'S'

    char caracter;
    do
    {
        printf("Introduce un caracter por teclado.\n");
        // fflush(stdin);  // Otro metodo para hacerlo, limpia el buffer.
        scanf(" %c", &caracter);    // Aparecera dos veces el printf superior, ya que al introducir una letra, se suma el \n
        // Para eliminarlo, pondremos un espacio antes del %c
        // Si introducimos s mayuscula, seguira en el bucle.
    } while (caracter != 's' && caracter != 'S');

    return 0;
}