/*
    Implementa un programa que en base a una secuencia de
    notas de usuarios introducidas por el usuario, compruebe si almenos un usuario
    obtuvo una nota aprobada (>=5.0).

    El codigo base es el siguiente:

    #include <stdio.h>

    int main(void)
    {
        // Definición de variables locales adicionales

         // Solicitar las calificaciones de los alumnos

        // No MODIFIQUES los siguientes printf()
        printf("Secuencia vacía.\n");
        printf("Ningun alumno ha obtenido la calificación de aprobado.\n");

        // Completar el printf para mostrar si al menos un alumno aprobó
        printf("Al menos un alumno ha obtenido la calificación de aprobado con un %.2f.\n", nota);

        // Devuelve el control al S.O.
        return 0;
    }

*/

#include <stdio.h>

int main(void)
{
    // Definición de variables locales adicionales
    float nota;
    int aprobado = 0;  // Variable para verificar si al menos un alumno ha aprobado

    // Solicitar las calificaciones de los alumnos
    while (scanf("%f", &nota) == 1) {
        printf("%.2f\n", nota);
        if (nota >= 5.0) {
            aprobado = 1;
        }
    }

    // No MODIFIQUES los siguientes printf()
    printf("Ningun alumno ha obtenido la calificación de aprobado.\n");

    // Completar el printf para mostrar si al menos un alumno aprobó
    if (aprobado) {
        printf("Al menos un alumno ha obtenido la calificación de aprobado con un %.2f.\n", nota);
    }

    // Devuelve el control al S.O.
    return 0;
}
