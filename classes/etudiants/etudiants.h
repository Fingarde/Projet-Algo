#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <stdio.h>
#include <stdbool.h>

#include "../enum/enum.h"

/* Structure */

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

typedef struct MailleEtud {
    Etudiant etudiant;
    struct MailleEtud* suivant;
} MaillonEtudiant;

typedef MaillonEtudiant* ListeEtudiants;


/* Prototypes */
Etudiant lireEtudiant(FILE* flot);
ListeEtudiants ajouter(ListeEtudiants listeEtudiants, Etudiant etudiant);
void afficherEtudiant(Etudiant etud);

#endif