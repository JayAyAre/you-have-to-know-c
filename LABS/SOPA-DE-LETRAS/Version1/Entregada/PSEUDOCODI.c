INICIO

    // Declaración de variables
    DEFINIR tauler COMO MATRIZ[MIDA_MAX][MIDA_MAX]
    DEFINIR llista_paraules COMO LISTA[MAX_PARAULES]
    DEFINIR total_paraules, max_intents, paraules_colocades COMO ENTEROS
    DEFINIR num_files, num_columnes, index_paraula COMO ENTEROS

    // Inicialización de variables
    total_paraules ← 0
    max_intents ← MAX_PARAULES
    paraules_colocades ← 0
    num_files ← 0
    num_columnes ← 0

    // Leer palabras desde el diccionario
    total_paraules ← llegir_paraules("diccionari.txt", llista_paraules)
    SI total_paraules = 0 ENTONCES
        IMPRIMIR "Error: No s'han trobat paraules al diccionari."
        TERMINAR

    // Solicitar tamaño del tablero
    num_files ← demanar_files()
    num_columnes ← demanar_columnes()

    // Inicializar el tablero vacío
    inicialitzar_sopa(tauler, num_files, num_columnes)

    // Colocar palabras en el tablero
    index_paraula ← 0
    MIENTRAS index_paraula < total_paraules Y paraules_colocades < max_intents HACER
        SI inserir_paraula(tauler, num_files, num_columnes, llista_paraules[index_paraula].nom) ENTONCES
            llista_paraules[index_paraula].colocada ← 1
            paraules_colocades ← paraules_colocades + 1
        FIN_SI
        index_paraula ← index_paraula + 1
    FIN_MIENTRAS

    // Mostrar cantidad de palabras colocadas
    IMPRIMIR "S'han col·locat " + paraules_colocades + " paraules a la sopa."

    // Completar espacios vacíos del tablero
    completar_buides(tauler, num_files, num_columnes)

    // Mostrar y guardar el tablero generado
    IMPRIMIR "Sopa de lletres generada:"
    mostrar_tauler(tauler, num_files, num_columnes)
    desar_tauler("sopa_resultat.txt", tauler, num_files, num_columnes)

    IMPRIMIR "La sopa de lletres s'ha guardat a 'sopa_resultat.txt'."

FIN
