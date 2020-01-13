#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <stdio.h>
#include <stdbool.h>

#include "../enum/enum.h"

#include "../logements/logements.h"
/* Structure */

// Étudiant
typedef struct {
    int idEtudiant;
    Civilite civilite;
    char nom[65];
    char prenom[65];
    bool boursie;
    Echelon echelon;
    bool handicape;
} Etudiant;

/* Prototypes */
Etudiant lireEtudiant(FILE* flot);
void afficherEtudiant(Etudiant etud);
MaillonLogement* getLogement(ListeLogements logements, Etudiant etud);
void supprimerEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants, int idEtudiant);
void insererEtudiant(Etudiant etudiants[], int* nbEtudiants);
void supprimerEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants, int positionEtudiant);
int rechercheEtudiant(Etudiant etudiants[], int idEtudiant, int nbEtudiants);

#endif