#include <stdio.h>

// Ejercicio: Haz un programa que lea un valor numerico entre 1 y 4, y devuelva el dia de la semana correspondiente.
int main(){
    int x;

    printf("Introduce el valor numerico por teclado.");
    scanf("%d", &x);

    // Primera forma

    if (x == 1)
    {
        printf("El dia es lunes");
    }
    if (x == 2)
    {
        printf("El dia es martes");
    }
    if (x == 3)
    {
        printf("El dia es miercoles");
    }
    if (x == 4)
    {
        printf("El dia es jueves");
    }

    // Segunda forma

    // Usamos la forma else if o elif, la cual nos permite ejecutar un bloque de codigo si el if anterior no se cumple
    if(x == 1){
        printf("El dia es lunes");
    }else if(x == 2){
        printf("El dia es martes");
    }else if(x == 3){
        printf("El dia es miercoles");
    }else if(x == 4){
        printf("El dia es jueves");
    }else{
        printf("El dia no existe");
    }

    // Tercera forma

    // Las formas anteriores son muy poco intuitivas, por ello, podemos usar un switch
    switch (x)
    {
    case 1:
        printf("El dia es lunes");
        break;
    case 2:
        printf("El dia es martes");
        break;
    case 3:
        printf("El dia es miercoles");
        break;
    case 4:
        printf("El dia es jueves");
        break;
    default:
        break;
    }

    // Version comprimida

    switch (x)
    {
        case 1: printf("El dia es lunes"); break;
        case 2: printf("El dia es martes"); break;
        case 3: printf("El dia es miercoles"); break;
        case 4: printf("El dia es jueves"); break;
        default: break;
    }
    // Cuando solo hay una linea dentro del caso, podemos comprimir el switch asi

    // La instruccion break, permite que solo se ejecute hasta ese punto, despues, se ejecuta break
    // y saldra del switch
    // Y la instruccion default permite controlar cuando no se cumple ninguno de los casos
    return 0;
}