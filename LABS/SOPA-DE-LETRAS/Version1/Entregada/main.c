#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcs.h"

int main() {
    char tauler[MIDA_MAX][MIDA_MAX];
    Paraula_t llista_paraules[MAX_PARAULES];
    int total_paraules, max_intents, paraules_colocades;
    int num_files, num_columnes;
    int index_paraula;

    total_paraules = 0;
    max_intents = MAX_PARAULES;
    paraules_colocades = 0;
    num_files = 0;
    num_columnes = 0;

    total_paraules = llegir_paraules("diccionari.txt", llista_paraules);
    if (total_paraules == 0) {
        printf("Error: No s'han trobat paraules al diccionari.\n");
    }

    num_files = demanar_files();
    num_columnes = demanar_columnes();

    inicialitzar_sopa(tauler, num_files, num_columnes);

    index_paraula = 0;
    while (index_paraula < total_paraules && paraules_colocades < max_intents) {
        if (inserir_paraula(tauler, num_files, num_columnes, llista_paraules[index_paraula].nom)) {
            llista_paraules[index_paraula].colocada = 1;
            paraules_colocades++;
        }
        index_paraula++;
    }

    printf("S'han col·locat %d paraules a la sopa.\n", paraules_colocades);

    completar_buides(tauler, num_files, num_columnes);

    printf("\nSopa de lletres generada:\n");
    mostrar_tauler(tauler, num_files, num_columnes);
    desar_tauler("sopa_resultat.txt", tauler, num_files, num_columnes);

    printf("La sopa de lletres s'ha guardat a 'sopa_resultat.txt'.\n");
    return 0;
}
