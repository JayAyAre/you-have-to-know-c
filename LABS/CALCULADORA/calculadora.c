#include <stdio.h>

int factorial(int n);
int variacions_sense_repeticio(int m, int n);

int main() {
    int opcion = 0;

    printf("Bienvenido a la calculadora\n");
    do{
        printf("\nOpciones disponibles:\n");
        printf("1. Calcular el factorial de un numero\n");
        printf("2. Calcular variaciones sin repeticion\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ingrese un numero: ");
                int numero;
                scanf("%d", &numero);
                printf("El factorial de %d es %d\n", numero, factorial(numero));
                break;
            case 2:
                printf("Ingrese dos numeros (El primero es mayor): ");
                int m, n;
                scanf("%d %d", &n, &m);
                printf("El numero de variaciones sin repeticion es %d\n", variacions_sense_repeticio(n, m));
                break;
            case 3:
                printf("Adios!\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while(opcion != 3);
    return 0;
}

int factorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int variacions_sense_repeticio(int n, int m) {
    if (m < n) {
        return 0; // Caso en que m < n
    }

    return factorial(m) / factorial(m - n);
}
