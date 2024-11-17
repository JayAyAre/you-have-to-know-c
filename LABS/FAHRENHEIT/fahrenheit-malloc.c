#include <stdio.h>
#include <stdlib.h>  // Para malloc, realloc, free

#define INITIAL_SIZE 1000  // Tamaño inicial del array

int main() {
    double *taula_temperatures;  // Puntero para el array dinámico
    double farenhite, celsius;
    int i = 0;  // índice para la tabla
    int capacity = INITIAL_SIZE;  // Capacidad inicial
    FILE *file;

    // Asignar memoria inicial para el array
    /*
        En esta linea, llamamos la función malloc, que asigna memoria dinámicamente
        y para su parametro, debemos indicar el tamaño de la memoria que queremos asignar
        en bytes. En este caso, estamos asignando memoria para un array de doubles
        (8 bytes por elemento)

        Para saber el tamaño de bytes de un tipo de dato, podemos usar la función sizeof
        que nos devuelve el tamaño de un tipo de dato en bytes

        y esto lo multiplicamos por el número de elementos que queremos asignar

        y finalmente, tenemos un puntero de tipo void, el cual casteamos a un puntero
        de tipo double, para que podamos acceder a los elementos del array
    */
    taula_temperatures = (double *)malloc(capacity * sizeof(double));

    // Verificar si la memoria fue asignada correctamente
    if (taula_temperatures == NULL) {
        printf("Error al asignar memoria\n");
        return 1;  // Terminar el programa si falla la asignación
    }

    file = fopen("fitxer_amb_temperatures.txt", "r");

    // Verificar si el archivo se pudo abrir
    /*
        La funcion free permite liberar la memoria asignada inicialmente
        Si no lo hacemos, se quedara asignada y probablemente nos quedemos sin memoria
    */
    if (file == NULL) {
        printf("No es troben dades al fitxer\n");
        free(taula_temperatures);  // Liberar la memoria antes de salir
        return 1;
    }

    while (fscanf(file, "%lf", &farenhite) != EOF) {

        if (farenhite == -999.9) {
            printf("%.1lf farenhite\n", farenhite);
        } else {

            celsius = (farenhite - 32) / 1.8;
            printf("%.2lf celsius\n", celsius);

            // Si el array está lleno, redimensionar
            if (i >= capacity) {

                /*
                    realloc nos permite reasignar memoria dinámicamente
                    en tal caso que si el array está lleno, se redimensiona.
                    Esto es necesario porque si el array está lleno, se necesita
                    más espacio para almacenar los datos.

                    El primer parámetro es el puntero que queremos reasignar
                    (en este caso, el puntero de la tabla)

                    El segundo parámetro es el nuevo tamaño de la memoria
                    que queremos asignar (en este caso, el nuevo tamaño de la tabla)
                */

                capacity *= 2;  // Duplicar el tamaño

                double *new_ptr = realloc(taula_temperatures, capacity * sizeof(double));

                // Verificar si realloc fue exitoso
                if (new_ptr == NULL) {
                    printf("Error al reasignar memoria\n");
                    free(taula_temperatures);  // Liberar la memoria antes de salir
                    fclose(file);
                    return 1;
                }

                taula_temperatures = new_ptr;  // Actualizar puntero si realloc fue exitoso
            }

            // Almacenar la temperatura en Celsius en la tabla
            taula_temperatures[i] = celsius;
            i++;
        }
    }

    // Cerrar el archivo
    fclose(file);

    // Liberar la memoria asignada dinámicamente
    free(taula_temperatures);
    return 0;
}
