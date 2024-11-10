/*
    Diseña un programa con las siguientes características:

    1. La funcio recibira un numero entero como parámetro.

    2. Si el número es par, mostrará el mensaje: "El número es par".
    Si el número es impar, mostrará el mensaje: "El número es impar".

    3. Si el número es menor o igual a 0, mostrará el mensaje: "Número no válido".

    Nota: Implementa la documentación, prototipo e implementación del programa.
*/

void es_par(int numero);

/* Funcion que recibe un número entero y verifica si es par o impar
    @param numero Número entero
*/
void es_par(int numero){

    if (numero <= 0) {
        printf("Número no válido\n");
    } else if (numero % 2 == 0) {
        printf("El número es par\n");
    } else {
        printf("El número es impar\n");
    }
}
