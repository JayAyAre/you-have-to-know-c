#include <stdio.h>

// Función 1: Comprobar que un texto contiene solo letras
int esNomValid(const char *text, int *numLletres) {
    int i = 0;
    *numLletres = 0;
    while (text[i] != '\0') {
        if ((text[i] < 'A' || text[i] > 'Z') && (text[i] < 'a' || text[i] > 'z') && text[i] != ' ') {
            return 0; // No es válido
        }
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            (*numLletres)++;
        }
        i++;
    }
    return 1; // Es válido
}

// Función 2: Capitalizar el texto
int capitalitzarText(char *text, int *lletresConvertides) {
    int i = 0, convertir = 0;
    int capitalitzar = 1; // Indicador para capitalizar la siguiente letra
    *lletresConvertides = 0;

    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z' && capitalitzar) {
            text[i] -= 32; // Convertir a mayúscula
            (*lletresConvertides)++;
            convertir = 1;
        } else if (text[i] >= 'A' && text[i] <= 'Z' && !capitalitzar) {
            text[i] += 32; // Convertir a minúscula
            (*lletresConvertides)++;
            convertir = 1;
        }
        capitalitzar = (text[i] == ' ') ? 1 : 0;
        i++;
    }
    return convertir;
}

// Función 3: Comprobar que el teléfono tiene 9 dígitos
int esTelefonValid(const char *telefon) {
    int i = 0;
    while (telefon[i] != '\0') {
        if (telefon[i] < '0' || telefon[i] > '9') {
            return 0; // No es válido
        }
        i++;
    }
    return i == 9; // Es válido si tiene exactamente 9 dígitos
}

// Procedimiento 4: Interacción con el usuario
void llegirDades() {
    char nom[100];
    char telefon[20];
    int valid, lletres, conversions;

    // Pedir y validar el nombre
    do {
        printf("Introdueix el teu nom complet: ");
        fgets(nom, 100, stdin);

        // Eliminar el salto de línea
        int len = 0;
        while (nom[len] != '\0') len++;
        if (len > 0 && nom[len - 1] == '\n') nom[len - 1] = '\0';

        valid = esNomValid(nom, &lletres);
        if (!valid) {
            printf("El nom només pot contenir lletres. Torna-ho a intentar.\n");
        }
    } while (!valid);

    // Capitalizar el nombre
    capitalitzarText(nom, &conversions);
    printf("Nom processat: %s\n", nom);

    // Pedir y validar el teléfono
    do {
        printf("Introdueix el teu número de telèfon (9 dígits): ");
        fgets(telefon, 20, stdin);

        // Eliminar el salto de línea
        int len = 0;
        while (telefon[len] != '\0') len++;
        if (len > 0 && telefon[len - 1] == '\n') telefon[len - 1] = '\0';

        valid = esTelefonValid(telefon);
        if (!valid) {
            printf("El telèfon ha de tenir exactament 9 dígits. Torna-ho a intentar.\n");
        }
    } while (!valid);

    printf("Telèfon processat: %s\n", telefon);
}

// Función principal
int main() {
    llegirDades();
    return 0;
}
