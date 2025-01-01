#ifndef FUNCS_H
#define FUNCS_H

#define MIDA_MAX 20
#define MIDA_MIN 5
#define MAX_PARAULES 50

typedef struct {
    char nom[MIDA_MAX];
    int colocada;
} Paraula_t;

int demanar_files();
int demanar_columnes();
int llegir_paraules(const char *nom_fitxer, Paraula_t llista[]);
void inicialitzar_sopa(char tauler[][MIDA_MAX], int files, int columnes);
int inserir_paraula(char tauler[][MIDA_MAX], int files, int columnes, const char *paraula);
void completar_buides(char tauler[][MIDA_MAX], int files, int columnes);
void mostrar_tauler(char tauler[][MIDA_MAX], int files, int columnes);
void desar_tauler(const char *nom_fitxer, char tauler[][MIDA_MAX], int files, int columnes);

#endif
