/*

Ejercicio 1. Mensajes de error

En los programas es común mostrar varios mensajes de error, según la condición que se produzca.
Diseña un procedimiento que muestre un mensaje de error por pantalla dependiendo
del código de error recibido. El procedimiento recibe un código de error como parámetro
y muestra el mensaje de error correspondiente.

Define las siguientes constantes con los códigos de error:

    ERROR1 con el valor -1

    ERROR2 con el valor -2

    ERROR3 con el valor -3

Los mensajes de error correspondientes a cada código son los siguientes:

    ERROR1 → "Error -1: fichero vacio"

    ERROR2 → "Error -2: no existe fichero"

    ERROR3 → "Error -3: datos insuficientes"

En caso de no poder identificar el error se mostraría el mensaje: "Error desconocido"

Nota: Se debe diseñar la documentación, prototipo e implementación.

*/

void error(int error);

/* Funcion que recibe un código de error y muestra el mensaje de error correspondiente
    @param error Código de error
*/

void error(int error){
    switch(error){
        case ERROR1:
            printf("Error -1: fichero vacio\n");
            break;
        case ERROR2:
            printf("Error -2: no existe fichero\n");
            break;
        case ERROR3:
            printf("Error -3: datos insuficientes\n");
            break;
        default:
            printf("Error desconocido\n");
            break;
    }
}