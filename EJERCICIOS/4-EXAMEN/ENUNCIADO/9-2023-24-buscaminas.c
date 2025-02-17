/*
    A tiempo (1 punto)

        Diseña un nuevo tipo de datos para almacenar una hora, que incluya: hora, minutos y segundos.

        Diseña un procedimiento que calcule el intervalo de tiempo, en segundos, 
        entre dos horas utilizando el nuevo tipo de datos definido anteriormente. El procedimiento recibirá como parámetros dos horas y deberá calcular la diferencia, en segundos, entre ambas.

        Por ejemplo, si las horas dadas son 13:53:50 y 12:31:23, la diferencia es de 4947 segundos. El cálculo sería:

            13h * 60m * 60s + 53m * 60s + 50s = 50030s
            12h * 60m * 60s + 31m * 60s + 23s = 45083s
            50030s - 45083s = 4947s

        Si el resultado es negativo, asumimos que ha transcurrido un día y sumamos 86400 segundos (correspondiente al número de segundos de un día).
*/


/*
    Leer un entero acotado (1 punto)

        Diseña un procedimiento que proporcione el valor entero
        leído por el teclado. Este valor estará acotado entre un valor mínimo y un valor máximo, ambos inclusive [min, máx). 
        El procedimiento solicitará al usuario un valor y comprobará que se encuentra entre el valor mínimo y el máximo.
        Si no es así, volverá a solicitar el valor e informará al usuario del error hasta que sea correcto.
*/

/*

    Inicializar matriz (1 punto)

        Diseñad el procedimiento para inicializar un tablero (matriz de caracteres) con un carácter que se
        pasa como parámetro. Tenéis libertad para decidir la cabecera del procedimiento.
*/


/*
    Ejercicio 1

        Diseña el procedimiento que comprueba si las casillas ocultas del tablero de juego corresponden
        a las minas del tablero de minas. En este caso devolverá verdadero, en caso contrario falso. Las casillas ocultas en el tablero
        de juego son las que contienen un ESPACIO. A continuación, indicamos la cabecera del procedimiento.

        ** Comprueba si las casillas ocultas en el tablero de juego corresponden a minas. *

        @param tauler_minas (Ref (E): taula [] [MAX_COL] de caràcter) Tablero de minas.

        @param tauler_joc (Ref (E): taula [] [MAX_COL] de caràcter) Tablero de juego.

        * * @param maxfil (Valor (E): enter) Número de filas del tablero.

        * @param maxcol (Valor (E): enter) Número de columnas del tablero.

        * @return (booleà) Devuelve cierto si corresponden y falso en caso contrario.

        función comprovar_fi_joc (tauler_mines: taula [][MAX_COL] de caracteres, tauler_joc: taula [] [MAX_COL] de caracteres, maxfil: enter, maxcol: enter) retorna booleà

*/

/*
    Ejercicio 2

    Diseña el procedimiento que actualiza el tablero de juego después de una tirada del jugador a una
    casilla vacía. Además de la celda correspondiente, colocará los valores adecuados a las celdas de
    alrededor (3, 5 u 8 celdas, dependiendo de si la celda está en una esquina o no).
    La cabecera del procedimiento es:

        /** Destapa una casilla vacía y las de alrededor.

        * @param tauler_minas (Ref (E): taula [] [MAX_COL] de caràcter) Tablero de minas.

        * @param tauler_joc (Ref (S): taula [] [MAX_COL] de caràcter) Tablero de juego.

        * @param fila (Valor (E): enter) Fila del tablero que queremos destapar.

        * @param columna (Valor (E): enter) Columna del tablero que queremos destapar.

        * @param maxfil (Valor (E): enter) Número de filas del tablero.

        * @param maxcol (Valor (E): enter) Número de columnas del tablero.

        /*

        acción destapar_caselles (tauler_mines: taula [] [MAX_COL] de caracteres, var tauler_joc: taula [] [MAX_COL] de caracteres, fila: enter, columna: enter, maxfil: enter, maxcol: enter)

        Siendo el tercer y cuarto parámetro respectivamente la fila y la columna del tablero que queremos destapar.
*/

/*
    Buscaminas

        Ejercicio 3

            Diseña el programa principal del juego, utilizando todos los procedimientos que has diseñado
            anteriormente, incluido el procedimiento para inicializar la matriz. Si lo deseas,
             puedes añadir más procedimientos.

            Es importante tener en cuenta que el jugador puede cometer el error de disparar a coordenadas
            incorrectas (disparo inválido), en este caso el programa debe informar del error cometido y
            volver a pedir las coordenadas. No trataremos el caso de que el jugador
            quiera disparar a una casilla en la que ya ha disparado.

            El tamaño de los tableros es fijo, así como el número de minas (no se tienen que pedir al usuario).

            Recuerda que al final del juego es necesario mostrar la puntuación obtenida.
*/