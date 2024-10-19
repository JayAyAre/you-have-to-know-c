#include <stdio.h>

// Ejercicio: Haz un programa que verifique y acepte 3 numeros. horas, minutos y segundos.
// yque devuelva la hora que sera dentro de un segundo, controlando que sea una hora correcta
int main(){
    int hora = 0, min = 0, seg = 0;

    printf("Introduce las horas por teclado.\n");
    scanf("%d", &hora);
    printf("Introduce los minutos por teclado.\n");
    scanf("%d", &min);
    printf("Introduce los segundos por teclado.\n");
    scanf("%d", &seg);

    if (hora >= 0 && hora <= 23 && min >= 0 && min <= 59 && seg >= 0 && seg <= 59){
        seg++;

        if(seg == 60){
            min++;
            if (min == 60)
            {
                hora++;
                if (hora == 24)
                {
                    hora = 0;
                }
            }
        }

        printf("La hora es %d:%d:%d\n", hora, min, seg);
    }else{
        printf("Algun valor introducido esta incorrecto\n");
    }
    return 0;
}