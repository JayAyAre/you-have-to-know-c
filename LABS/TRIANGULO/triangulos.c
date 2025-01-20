typedef struct{
    int a, b, c;
}triangulo;

void leer_triangulo(triangulo *t){
    printf("Introduce los valores de a, b y c de un triangulo: ");
    int valido = 0;
    while (!valido)
    {
        printf("Introduce a: ");
        scanf("%d", &t->a);
        printf("Introduce b: ");
        scanf("%d", &t->b);
        printf("Introduce c: ");
        scanf("%d", &t->c);
        if (t->a + t->b > t->c && t->a + t->c > t->b && t->b + t->c > t->a)
        {
            valido = 1;
        }
        else
        {
            printf("Los valores introducidos no son un triangulo valido.\n");
        }
    }
}

int calcular_perimetro(triangulo t){
    return t.a + t.b + t.c;
}

#include <stdio.h>

int main(void){
    triangulo t1, t2;
    leer_triangulo(&t1);
    leer_triangulo(&t2);

    int p1 = calcular_perimetro(t1);
    int p2 = calcular_perimetro(t2);

    if (p1 > p2)
    {
        printf("El primer triangulo es mayor que el segundo.\n");
    }
    else if (p1 < p2)
    {
        printf("El segundo triangulo es mayor que el primero.\n");
    }
    else
    {
        printf("Los dos triangulos son iguales.\n");
    }

    return 0;
}