/*
    Diseña una funcion con las siguientes características:

    1. La funcion recibira tres números enteros como parámetros.

    2. Si alguno de los números es menor o igual a 0, mostrará el mensaje: "Número no válido".

    3. Si los tres números son válidos, calculará el promedio de los tres y mostrará el resultado en pantalla.

    Nota: Implementa la documentación, prototipo e implementación del programa.

*/

void promedio(int numero1, int numero2, int numero3);

/* Funcion que recibe tres números enteros y calcula el promedio
    @param numero1 Primer número
    @param numero2 Segundo número
    @param numero3 Tercer número
*/
void promedio(int numero1, int numero2, int numero3){
    int promedio;

    if (numero1 <= 0 || numero2 <= 0 || numero3 <= 0) {
        printf("Número no válido\n");
    } else {
        promedio = (numero1 + numero2 + numero3) / 3;
        printf("El promedio es: %d\n", promedio);
    }