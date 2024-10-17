#include <stdio.h>

int main() {
    int numero_entero;  // 1, 2, -1, -19. 16 bits
    float numero_real;  // 1.0, 2.0, -1.0, -19.16. 32 bits
    double numero_real_largo;   //  64 bits, funciona igual que float, pero es mas grande.
    char caracter;  // A, a, 2, c. 8 bits

    numero_entero = 5;
    numero_real = 3.3;
    numero_real_largo = 3.33333;
    caracter = 'A';

    printf("Numero entero: %d\n", numero_entero);   // %d o %i es un formato para enteros
    printf("Numero real: %f\n", numero_real);   // %f es un formato para float
    printf("Numero real largo: %lf\n", numero_real_largo);   // %f es un formato para double
    printf("Caracter: %c\n", caracter); // %c es un formato para char.

    return 0;
}