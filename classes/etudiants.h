#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <stdio.h>
#include <stdbool.h>

#include "enum.h"

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
Etudiant lireEtudiant(FILE* flot);

#endif