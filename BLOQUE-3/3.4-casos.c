#include <stdio.h>

int main(void)
{
    // Aqui reproduciremos varios casos cursiosos que se pueden presentar al programar
    // en C.

    // Que pasa si asignamos un valor entero a un float?
    int numero_entero = 10;
    float numero_float = numero_entero;     // El valor del entero 10, se transforma en un float
    printf("El valor de numero_float es: %f\n", numero_float);

    // Que pasa si asignamos un valor entero a un char?
    numero_entero = 65;
    char numero_char = numero_entero;       // El valor del entero 10, se transforma en un char
    // Esto es especial ya que considera el valor, y lo transforma segun el codigo ASCII
    printf("El valor de numero_char es: %c\n", numero_char);

    // viceversa

    numero_char = 'A';
    numero_entero = numero_char;            // El valor del char 'A', se transforma en un entero
    printf("El valor de numero_entero es: %d\n", numero_entero);

    // Que pasa si colocamos mas de una letra en un char?
    char letra = 'ABC';
    printf("El valor de letra es: %c\n", letra);

    // Que pasa si asignamos un valor negativo a un unsigned int?
    unsigned int numero_unsigned_int = -1; // Se asigna el valor maximo del int, menos el numero asignado
    printf("El valor de numero_unsigned_int es: %u\n", numero_unsigned_int);

    // Que pasa si asignamos un valor negativo a un unsigned char?
    unsigned char numero_unsigned_char = -100; // Se asigna el valor maximo del char, menos el numero asignado. y se representa el caracter ASCII

    printf("El valor de numero_unsigned_char es: %c\n", numero_unsigned_char);

    // Que pasa si el resultado de una operacion entre ints, da un float y lo asignamos a una variable
    int numero_int = 13;
    float numero_float_2 = numero_int/3;    // Devuelve un numero redondeado, al mas proximo en funcion del decimal
    int numero_int_2 = numero_float_2;

    printf("El valor de numero_int_2 es: %d\n", numero_int_2);

    printf("El valor de numero_float_2 es: %f\n", numero_float_2);
}