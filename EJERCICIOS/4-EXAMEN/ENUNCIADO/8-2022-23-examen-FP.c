/*
    Ejercicio 1: El juego de la vida (3 puntos / 35 minutos)

        Os presentamos el Juego de la Vida. Este juego manipula una matriz en la que sus celdas tienen sólo dos estados, celda
        viva o celda muerta. Para guardar el estado del juego definiremos una matriz de enteros y representaremos las celdas
        muertas con el valor 0 y las celdas vivas con el valor 1.
        En el juego, la matriz evoluciona sola en cada instante de tiempo según las siguientes reglas:
        • Una celda muerta que tiene exactamente 3 celdas vecinas vivas nace, es decir, en el siguiente turno estará viva.
        • Una celda viva que tiene 2 o 3 celdas vecinas vivas, sigue viva.
        • Una celda viva que tiene menos de 2 celdas vecinas vivas muere por soledad.
        • Una celda viva que tiene más de 3 celdas vecinas vivas se muere por sobrepoblación.
        La matriz sigue evolucionando sola hasta el infinito o hasta que llegue a un estado que ya no se modifica (no se produce
        ningún cambio entre un estado y el siguiente). Observa que todas las celdas cambian su valor a la vez y que en el cálculo
        del número de vecinas vivas no se cuenta la propia celda.
        Cada celda debe contar cuántas de sus vecinas están vivas (tienen el valor 1). Observa que las celdas interiores de la
        matriz siempre tienen 8 celdas vecinas, en cambio, las de los bordes, pueden tener menos.
        Por ejemplo: (las celdas muertas las indicamos con un 0 y las vivas con un 1)

        Se pide:

            Se deben implementar el siguiente procedimiento.

            Ejercicio 1.1 Evoluciona la matriz juego (2 puntos / 20 minutos) Define e implementa (cabecera, documentación e
            implementación) un procedimiento para evolucionar una matriz de juego. Este procedimiento recibe como
            parámetros una matriz de juego y la matriz vecinas correspondiente (y toda la información adicional que se necesite)
            y calcula la nueva matriz de juego.

            Ejercicio 1.2 Programa principal (1 puntos / 15 minutos) Completa el código. Define todas las variables que necesites
            y completa el programa principal para que, inicialice la matriz definida en la variable juego, muestre por pantalla la
            matriz juego, calcule la matriz auxiliar vecinas y calcule la evolución de la matriz juego (llamando al procedimiento
            anterior).

            El programa acabará cuando la matriz juego y la matriz juego evolucionada son iguales.
            Puedes definir (cabecera y documentación) todos los procedimientos adicionales que consideres necesarios, pero NO
            debes implementarlos.

            Procedimientos disponibles

                 Crea matriz de juego.
                *
                * @param m (Ref (E/S): taula[][] de enter) Matriz que guarda el juego.
                * @param nfilas (Valor (E): enter) Número de filas de la matriz.
                * @param mcols (Valor (E): enter) Número de columnas de la matriz.

                acció crea_matriz_juego (var m: taula[][] de enter, nfilas: enter, mcols: enter) és;
                 Compara dos matrices.
                *
                * @param m1 (Ref (E): taula[][] de enter) Primera matriz.
                * @param m2 (Ref (E): taula[][] de enter) Segunda matriz.
                * @param nfilas (Valor (E): enter) Número de filas de la matriz.
                * @param mcols (Valor (E): enter) Número de columnas de la matriz.
                * @return (booleano) Devuelve cierto si son iguales y falso en caso contrario.

                funció compara_matrices (m1: taula[][] de enter, m1: taula [][] d

            Ejercicio 2: Tabla de números primos (3 puntos / 40 minutos)

                Ejercicio 2.1 ¿Es primo? (1 punto) Diseña un procedimiento para determinar si un número es primo o no.
                Un número primo es aquel que no puede dividirse entre ningún otro (excepto entre el mismo y entre uno). Recuerda
                que el primer número primo es el número 2.

                Ejercicio 2.2 Tabla de números primos(2 puntos) Diseña un procedimiento (cabecera, documentación e implementación)
                que reciba dos números enteros positivos como parámetros y guarde, en una tabla de enteros, los números primos que
                hay entre ellos (ambos incluidos). El procedimiento debe informar de:
                • Los números primos.
                • El número de números primos guardados en la tabla.
                • Si los números primos no caben en la tabla, debe indicarlo.
                Explica de forma detallada los parámetros (información intercambia el procedimiento con el programa que le llama).
                El procedimiento NO DEBE ESCRIBIR nada por pantalla.


            Ejercicio 3: Radicales (4 puntos / 40 minutos)


            En las ecuaciones matemáticas es frecuente encontrar radicales:
             Ecuación 2.1. n es el índice, a es el radicando y k es el coeficiente.
            Desde un instituto cercano nos han pedido un programa para trabajar con radicales, concretamente nos piden un
            programa para multiplicar dos radicales. A continuación, se muestra un ejemplo:
            √6 " ∗ √2! #
            = √6" $ ∗ √2#$ $ = √6" ∗ 2#$ $ = √3" ∗ 2#" $ Ecuación 2.2. Producto de dos radicales.
            Se pide:
            Utilizaremos diseño descendente para resolver el problema y diseñaremos, como mínimo, los siguientes procedimientos
            y tipos de datos (puedes añadir más procedimientos si lo consideras oportuno):


            Ejercicio 3.1 Estructuras de datos (0,5 con registros) Define un nuevo tipo de dato para guardar la información de un
            radical. Suponemos que el radical y el índice son siempre naturales (a > 0 y n > 0) y que el coeficiente es un valor entero
            distinto de cero. (Ver Ecuación 2.1).


            Ejercicio 3.2 Leer un radical de teclado (1 punto + 0,5 con registros) Define un procedimiento (documentación, cabecera
            e implementación) para leer la información de un radical de teclado. Se debe comprobar que el radical sea correcto, si el
            usuario comete algún error al introducir los datos, se debe volver a pedir hasta que sean correctos.
            • el índice (n) debe ser mayor que cero.
            • el coeficiente (k) puede ser positivo o negativo, pero nunca cero.
            • el radicando (a) debe ser mayor que cero.
            El radical que nos proporciona el procedimiento SIEMPRE será correcto.


            Ejercicio 3.3 Multiplica dos radicales. (0,25 puntos + 0,25 con registros) Define un procedimiento: documentación y
            cabecera (NO es necesario implementarlo) para realizar la operación de multiplicación de dos radicales. El procedimiento
            recibirá la información de dos radicales (el índice (n), el radicando (a) y el coeficiente (k)) y nos calculará el producto de
            ambos. Por ejemplo:
            2√9 # ∗ 5√9 # = 10√81 # = 30√3 # Ecuación 2.3. Producto de dos radicales.


            Ejercicio 3.4 Programa principal (1 punto + 0,5 con registros) Completa el programa principal para multiplicar un conjunto
            de radicales. La secuencia de radicales se leerá de teclado y se almacenará en una tabla. El número de radicales se
            preguntará por teclado y debe ser correcto mayor que cero y menor que la dimensión máxima de la tabla. Posteriormente
            se multiplicarán todos los radicales de la tabla. El resultado de la multiplicación se mostrará por pantalla usando la
            notación latex, por ejemplo, para el resultado de la Ecuación 2.3 se mostraría:
            Notas:
            • Se debe evitar utilizar literales o variables globales dentro del código. El número máximo de elementos de la
            tabla es constante. Puedes decidir tú el valor.
            • Se debe aplicar el diseño descendente y utilizar los procedimientos diseñados anteriormente.
            • Se pueden diseñar (documentación, cabecera e implementación) tantos procedimientos adicionales como se
            necesite.
            • La secuencia puedes estar vacía, pero si hay información, puedes considerar que siempre será correcta.
            • Cuidado con los límites de las tablas
*/