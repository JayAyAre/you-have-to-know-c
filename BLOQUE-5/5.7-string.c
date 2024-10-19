// Introducir una frase como cadena de caracteres

#include <stdio.h>
#include <string.h> // Funciones de string

int main(){
    char frase[13];

    printf("Introduzca una frase: ");
    //scanf("%s\n", frase);   // Con scanf, leera hasta el primer espacio

    fgets(frase, 13, stdin); // Con fgets, leera hasta que se introduzca un caracter '\n'
    printf("Frase introducida: %s\n", frase);

    // Para comparar frases hacemos esto

    char frase2[13] = "Hola mundo";
    char frase3[13] = "Hola mundo";

    // NO COMPARAMOS ASI frase2 == frase3, ya que compara las direcciones de memoria
    if (strcmp(frase, frase2) == 0){
        printf("Las frases son iguales\n");
    }
    else{
        printf("Las frases son distintas\n");
    }

    return 0;
}