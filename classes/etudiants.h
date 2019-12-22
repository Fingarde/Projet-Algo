#include <stdio.h>
#include <stdbool.h>

typedef enum {
    MR,
    MME
} Civilite;

typedef enum {
    ZERO_BIS,
    UN,
    DEUX,
    TROIS,
    QUATRE,
    CINQ,
    SIX,
    SEPT
} Echelon;

typedef struct {
    int idEtudiant;
    Civilite civilite;
    char* nom;
    char* prenom;
    Echelon echelon;
    bool handicape;
} Etudiant;

char* getCivilite(Civilite civilite);
char* getEchelon(Echelon echelon);
Etudiant lireEtudiant(FILE* flot);