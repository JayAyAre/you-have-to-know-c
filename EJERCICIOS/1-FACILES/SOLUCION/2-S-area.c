/*
    Diseña un programa con las siguientes características:

    1. La funcion recibira la base y la altura de un triángulo como valores decimales (float).

    2. Si la base o la altura son menores o iguales a 0, mostrará el mensaje: "Valores no válidos".

    3. Si los valores son correctos, calculará el área del triángulo con la fórmula:

        área = (base * altura) / 2

    4. El programa mostrará el resultado en pantalla con el mensaje: "El área del triángulo es: [resultado]"

    Nota: Implementa la documentación, prototipo e implementación del programa.
*/

void area(float base, float altura);

/* Funcion que recibe los valores de la base y la altura de un triángulo y calcula su área
    @param base Valor de la base del triángulo
    @param altura Valor de la altura del triángulo
*/
void area(float base, float altura){
    if (base <= 0 || altura <= 0) {
        printf("Valores no válidos\n");
    } else {
        printf("El área del triángulo es: %.2f\n", (base * altura) / 2);
    }
}