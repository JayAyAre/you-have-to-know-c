#include <stdio.h>

#define MAX 100

int main(){
    char frase[MAX];

    printf("Introduce una frase: ");
    fgets(frase, MAX, stdin);

    int i = 0;

    printf("Frase original: %s\n", frase);

    i = 0;

    while (frase[i] != '.' && frase[i] != '\0')
    {
        switch (frase[i])
        {
        case 'a':
            frase[i] = 'e';
            break;
        case 'e':
            frase[i] = 'i';
            break;
        case 'i':
            frase[i] = 'o';
            break;
        case 'o':
            frase[i] = 'u';
            break;
        default:
            break;
        }
        i++;
    }

    printf("Frase modificada: %s\n", frase);

    return 0;
}

