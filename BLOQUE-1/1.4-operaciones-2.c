#include <stdio.h>
#include <math.h>   // Libreria que permite usar funciones matematicas

int main(){
    int x, y;   // Declaracion de variables en una linea
    int resultado;
    float resultado_float;
    x = 10;
    y = 2;
    // Operaciones basicas

    // Suma
    resultado = x + y;
    printf("El resultado de la suma de %d y %d es %d\n",x ,y, resultado);

    // Resta
    resultado = x - y;
    printf("El resultado de la resta de %d y %d es %d\n",x ,y, resultado);

    // Multiplicación
    resultado = x * y;
    printf("El resultado de la multiplicacion de %d y %d es %d\n",x ,y, resultado);

    // División
    resultado = x / y;
    printf("El resultado de la división de %d y %d es %d\n",x ,y, resultado);

    // Modulo
    resultado = x % y;
    printf("El resultado del modulo de %d y %d es %d\n",x ,y, resultado);

    // Potencia
    resultado = pow(x, y);
    printf("El resultado de la potencia de %d y %d es %d\n",x ,y, resultado);

    // Raiz
    resultado_float = sqrt(x);
    printf("El resultado de la raiz cuadrada de %d es %f\n",x ,resultado_float);

    // incremento
    x++;
    printf("El valor de x es %d\n", x);

    // decremento
    x--;
    printf("El valor de x es %d\n", x);

    return 0;
}