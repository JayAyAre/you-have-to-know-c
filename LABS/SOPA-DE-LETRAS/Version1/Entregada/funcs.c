#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcs.h"

int demanar_files() {
    int nombre_files = 0;

    while (nombre_files < MIDA_MIN || nombre_files > MIDA_MAX) {
        printf("Introdueix el nombre de files (%d-%d): ", MIDA_MIN, MIDA_MAX);
        if (scanf("%d", &nombre_files) != 1) {
            while (getchar() != '\n'); 
            nombre_files = 0;
        }
    }
    return nombre_files; 
}

int demanar_columnes() {
    int nombre_columnes = 0;

    while (nombre_columnes < MIDA_MIN || nombre_columnes > MIDA_MAX) {
        printf("Introdueix el nombre de columnes (%d-%d): ", MIDA_MIN, MIDA_MAX);
        if (scanf("%d", &nombre_columnes) != 1) {
            while (getchar() != '\n'); 
            nombre_columnes = 0;
        }
    }
    return nombre_columnes; 
}

int llegir_paraules(const char *nom_fitxer, Paraula_t llista[]) {
    FILE *fitxer = fopen(nom_fitxer, "r");
    int contador = 0;

    if (fitxer != NULL) {
        while (fscanf(fitxer, "%s", llista[contador].nom) == 1 && contador < MAX_PARAULES) {
            llista[contador].colocada = 0; 
            contador++;
        }
        fclose(fitxer);
    } else {
        printf("Error: No s'ha pogut obrir el fitxer %s.\n", nom_fitxer);
    }

    return contador; 
}

void inicialitzar_sopa(char tauler[][MIDA_MAX], int files, int columnes) {
    int fila, columna;
    for (fila = 0; fila < files; fila++) {
        for (columna = 0; columna < columnes; columna++) {
            tauler[fila][columna] = ' ';
        }
    }
}

int inserir_paraula(char tauler[][MIDA_MAX], int files, int columnes, const char *paraula) {
    int longitud = strlen(paraula);
    int intents_restants = 100;
    int fila, columna, encaixa, col_locada = 0;
    int i;

    while (intents_restants > 0 && col_locada == 0) {
        fila = rand() % files;
        columna = rand() % (columnes - longitud + 1);
        encaixa = 1;

        for (i = 0; i < longitud; i++) {
            if (tauler[fila][columna + i] != ' ' && tauler[fila][columna + i] != paraula[i]) {
                encaixa = 0;
            }
        }

        if (encaixa) {
            for (i = 0; i < longitud; i++) {
                tauler[fila][columna + i] = paraula[i];
            }
            col_locada = 1;
        }
        intents_restants--;
    }
    return col_locada;
}

void completar_buides(char tauler[][MIDA_MAX], int files, int columnes) {
    int fila, columna;
    for (fila = 0; fila < files; fila++) {
        for (columna = 0; columna < columnes; columna++) {
            if (tauler[fila][columna] == ' ') {
                tauler[fila][columna] = 'A' + (rand() % 26);
            }
        }
    }
}

void mostrar_tauler(char tauler[][MIDA_MAX], int files, int columnes) {
    int fila, columna;
    for (fila = 0; fila < files; fila++) {
        for (columna = 0; columna < columnes; columna++) {
            printf("%c ", tauler[fila][columna]);
        }
        printf("\n");
    }
}

void desar_tauler(const char *nom_fitxer, char tauler[][MIDA_MAX], int files, int columnes) {
    FILE *fitxer = fopen(nom_fitxer, "w");
    int fila, columna;

    if (fitxer != NULL) {
        for (fila = 0; fila < files; fila++) {
            for (columna = 0; columna < columnes; columna++) {
                fprintf(fitxer, "%c ", tauler[fila][columna]);
            }
            fprintf(fitxer, "\n");
        }
        fclose(fitxer);
        printf("Sopa de lletres guardada a %s\n", nom_fitxer);
    } else {
        printf("Error: No s'ha pogut guardar el fitxer %s.\n", nom_fitxer);
    }
}
