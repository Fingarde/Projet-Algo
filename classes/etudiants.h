#include <stdio.h>
#include <stdbool.h>

/* Structure et Énumérations */

// Civilité
typedef enum {
    MR,
    MME
} Civilite;

// Échelon
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

// Étudiant
typedef struct {
    int idEtudiant;
    Civilite civilite;
    char* nom;
    char* prenom;
    bool bourse;
    Echelon echelon;
    bool handicap;
} Etudiant;

/* Prototypes */

char* getCivilite(Civilite civilite);
char* getEchelon(Echelon echelon);
Etudiant lireEtudiant(FILE* flot);