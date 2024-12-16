// palabras.c
#include "palabras.h"
#include <stdio.h>

void leerPalabras(const char *filename, char palabras[MAX_WORDS][MAX_WORD_LEN], int *numPalabras) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el fichero: %s\n", filename);
        *numPalabras = 0;
    } else {
        int i = 0;
        while (i < MAX_WORDS && fscanf(file, "%s", palabras[i]) == 1) {
            i++;
        }
        *numPalabras = i;
        fclose(file);
    }
}
