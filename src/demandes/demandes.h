#ifndef DEMANDES_H
#define DEMANDES_H

#include <stdio.h>
#include <stdbool.h>

#include "../etudiants/etudiants.h"
#include "../logements/logements.h"

/* Structure */

// Demande
typedef struct {
	int idDemande;
	int idEtudiant;
	Echelon echelon;
	char* nomCite; // char 30 utiliser le tableau pour le fichier bibn
	TypeLogement typeLogement;
} Demande;

typedef struct MailleDema {
    Demande demande;
    struct MailleDema* suivant;
} MaillonDemande;

typedef MaillonDemande* ListeDemandes;

/* Prototypes */

Demande lireDemande (FILE* flot);
ListeDemandes ajouterDemandeListe(ListeDemandes listeDemandes, Demande demande);
ListeDemandes chargementDemandes(FILE* fe);
void afficherDemande(Demande dema);

#endif