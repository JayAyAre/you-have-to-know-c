#include <stdio.h>

int factorial(int n);
int variacions_sense_repeticio(int m, int n);
int cossin(float x, float* cos, float* sin, int n);
float elevat(float a, float b);

int main() {
    int opcion = 0;

    printf("Bienvenido a la calculadora\n");
    do{
        printf("\nOpciones disponibles:\n");
        printf("1. Calcular el factorial de un numero\n");
        printf("2. Calcular variaciones sin repeticion\n");
        printf("3. Calcular el coseno y el seno de un numero\n");
        printf("4. Salir\n");
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
                printf("Ingrese dos numeros: ");
                int m, y;
                scanf("%d %d", &y, &m);
                printf("El numero de variaciones sin repeticion es %d\n", variacions_sense_repeticio(y, m));
                break;
            case 3:
                printf("Ingrese el numero x: ");
                float x;
                scanf("%f", &x);
                printf("Ingrese el grado n: ");
                int n;
                scanf("%d", &n);
                float cos, sin;
                cossin(x, &cos, &sin, n);
                printf("\nEl coseno de %.1f es %.5f\n", x, cos);
                printf("El seno de %.1f es %.5f\n", x, sin);
                break;
            case 4:
                printf("Adios!\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while(opcion != 4);
    return 0;
}

int cossin(float x, float* cos, float* sin, int n) {
    if (n > 0) {
        // Calcular cos
        float sin_result = 0;
        for (int i = 0; i <= n; i++) {
            sin_result += ((elevat(-1, i))/(factorial((2 * i) + 1))) * elevat(x, (2 * i + 1));
        }
        *sin = sin_result;

        float cos_result = 0;
        for (int i = 0; i <= n; i++) {
            cos_result += ((elevat(-1, i))/(factorial(2 * i))) * elevat(x, (2 * i));
        }
        *cos = cos_result;
        return 0;
    }else{
        return -1;
    }
}

float elevat(float a, float b) {
    if (b == 0) {
        return 1; // a^0 = 1
    }

    float resultado = 1;
    for (int i = 0; i < b; i++) {
        resultado *= a;
    }

    if (b < 0) {
        return 1 / resultado; // Si b es negativo, devolver 1/a^|b|
    }

    return resultado;
}


int factorial(int n) {
    int resultado = 1;
    if (n < 0) {
        return -1; // Error: factorial de número negativo
    }
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
