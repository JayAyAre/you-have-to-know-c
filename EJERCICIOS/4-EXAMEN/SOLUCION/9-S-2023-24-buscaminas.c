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

typedef struct {
    int horas;
    int minutos;
    int segundos;
} Hora;

// Función para calcular la diferencia entre dos horas en segundos
int calcularDiferencia(Hora h1, Hora h2) {
    int segundos1 = h1.horas * 3600 + h1.minutos * 60 + h1.segundos;
    int segundos2 = h2.horas * 3600 + h2.minutos * 60 + h2.segundos;
    int diferencia = segundos1 - segundos2;

    // Si la diferencia es negativa, sumamos un día completo (86400 segundos)
    if (diferencia < 0) {
        diferencia += 86400;
    }

    return diferencia;
}



/*
    Leer un entero acotado (1 punto)

        Diseña un procedimiento que proporcione el valor entero
        leído por el teclado. Este valor estará acotado entre un valor mínimo y un valor máximo, ambos inclusive [min, máx). 
        El procedimiento solicitará al usuario un valor y comprobará que se encuentra entre el valor mínimo y el máximo.
        Si no es así, volverá a solicitar el valor e informará al usuario del error hasta que sea correcto.
*/

int leerEnteroAcotado(int min, int max) {
    int valor;
    do {
        printf("Introduzca un valor entre %d y %d: ", min, max);
        scanf("%d", &valor);
    } while (valor < min || valor > max);
    return valor;
}

/*

    Inicializar matriz (1 punto)

        Diseñad el procedimiento para inicializar un tablero (matriz de caracteres) con un carácter que se
        pasa como parámetro. Tenéis libertad para decidir la cabecera del procedimiento.
*/

int inicializarMatriz(char[][] matriz, char caracter, int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            matriz[i][j] = caracter;
        }
    }
    return 0;
}

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

bool comprovar_fi_joc(char tauler_mines[MAX_FIL][MAX_COL], char tauler_joc[MAX_FIL][MAX_COL], int maxfil, int maxcol) {
    for (int i = 0; i < maxfil; i++) {
        for (int j = 0; j < maxcol; j++) {
            // Verificamos las casillas ocultas (que contienen un espacio ' ')
            if (tauler_joc[i][j] == ' ') {
                // Si hay una casilla oculta que no corresponde a una mina, devolvemos falso
                if (tauler_mines[i][j] != 'M') {
                    return false;
                }
            }
        }
    }
    // Si todas las casillas ocultas corresponden a minas, devolvemos verdadero
    return true;
}

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


/**
 * Destapa una casilla vacía y las de alrededor.
 * @param tauler_mines (E): Tablero de minas.
 * @param tauler_joc (S): Tablero de juego.
 * @param fila (E): Fila del tablero que queremos destapar.
 * @param columna (E): Columna del tablero que queremos destapar.
 * @param maxfil (E): Número de filas del tablero.
 * @param maxcol (E): Número de columnas del tablero.
 */
void destapar_caselles(char tauler_minas[MAX_FIL][MAX_COL], char tauler_joc[MAX_FIL][MAX_COL], int fila, int columna, int maxfil, int maxcol) {
    // Verificar que la casilla está dentro del tablero
    if (fila < 0 || fila >= maxfil || columna < 0 || columna >= maxcol) {
        return; // Fuera de límites
    }

    // Verificar que la casilla no está ya destapada
    if (tauler_joc[fila][columna] != ' ' || tauler_minas[fila][columna] == 'M') {
        return;
    }

    // Destapamos la casilla actual
    tauler_joc[fila][columna] = tauler_minas[fila][columna];

    // Si la casilla no contiene '0', no hace falta destapar las vecinas
    if (tauler_minas[fila][columna] != '0') {
        return;
    }

    // Recorrer todas las casillas vecinas
    for (int i = fila - 1; i <= fila + 1; i++) {
        for (int j = columna - 1; j <= columna + 1; j++) {
            // Saltar si está fuera de límites o es la casilla actual
            if (i >= 0 && i < maxfil && j >= 0 && j < maxcol && tauler_joc[i][j] == ' ') {
                tauler_joc[i][j] = tauler_minas[i][j]; // Destapar vecina
            }
        }
    }
}


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

void destapar_caselles(char tauler_mines[MAX_FIL][MAX_COL], char tauler_joc[MAX_FIL][MAX_COL], int fila, int columna, int maxfil, int maxcol);
bool comprovar_fi_joc(char tauler_mines[MAX_FIL][MAX_COL], char tauler_joc[MAX_FIL][MAX_COL], int maxfil, int maxcol);
void inicializar_tableros(char tauler_mines[MAX_FIL][MAX_COL], char tauler_joc[MAX_FIL][MAX_COL], int maxfil, int maxcol);
void mostrar_tablero(char tauler[MAX_FIL][MAX_COL], int maxfil, int maxcol);

int main() {
    // Declaración de los tableros
    char tauler_mines[MAX_FIL][MAX_COL];
    char tauler_joc[MAX_FIL][MAX_COL];
    int maxfil = 10, maxcol = 10; // Tamaño fijo del tablero
    int puntuacion = 0;          // Contador de puntuación

    // Inicialización de los tableros
    inicializar_tableros(tauler_mines, tauler_joc, maxfil, maxcol);

    printf("¡Bienvenido al Buscaminas!\n");
    mostrar_tablero(tauler_joc, maxfil, maxcol);

    // Bucle principal del juego
    while (true) {
        int fila, columna;

        // Pedir coordenadas al usuario
        printf("\nIntroduce las coordenadas (fila y columna, separadas por un espacio): ");
        scanf("%d %d", &fila, &columna);

        // Validar coordenadas
        if (fila < 0 || fila >= maxfil || columna < 0 || columna >= maxcol) {
            printf("Coordenadas inválidas. Intenta de nuevo.\n");
            continue;
        }

        // Verificar si el jugador disparó a una mina
        if (tauler_mines[fila][columna] == 'M') {
            printf("\n¡Has perdido! Disparaste a una mina.\n");
            mostrar_tablero(tauler_mines, maxfil, maxcol);
            break;
        }

        // Destapar casillas
        destapar_caselles(tauler_mines, tauler_joc, fila, columna, maxfil, maxcol);

        // Actualizar puntuación
        puntuacion++;

        // Mostrar el tablero actualizado
        mostrar_tablero(tauler_joc, maxfil, maxcol);

        // Comprobar si el juego ha terminado
        if (comprovar_fi_joc(tauler_mines, tauler_joc, maxfil, maxcol)) {
            printf("\n¡Felicidades! Has ganado.\n");
            printf("Tu puntuación final es: %d\n", puntuacion);
            mostrar_tablero(tauler_mines, maxfil, maxcol);
            break;
        }
    }

    return 0;
}