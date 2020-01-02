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
    SEPT,
    AUCUN
} Echelon;

// Étudiant
typedef struct {
    int idEtudiant;
    Civilite civilite;
    char* nom;
    char* prenom;
    bool boursie;
    Echelon echelon;
    bool handicape;
} Etudiant;

/* Prototypes */

char* getCivilite(Civilite civilite);
char* getEchelon(Echelon echelon);
char* getBoolean(bool boolean);
Etudiant lireEtudiant(FILE* flot);