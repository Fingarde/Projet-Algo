#ifndef LOGEMENTS_H
#define LOGEMENTS_H

#include <stdio.h>
#include <stdbool.h>

#include "../enum/enum.h"

// Logement
typedef struct {
    int idLogement;
    char* nomCite;
    TypeLogement typeLogement;
    bool disponible;
    bool adapteHandicap;
    int idEtudiant;
} Logement;

// Maillon d'un logement
typedef struct MailleLoge {
	Logement logement;
	struct MailleLoge* suivant;
} MaillonLogement;

// Liste logements
typedef MaillonLogement* ListeLogements;

/* Prototypes */

Logement lireLogement(FILE* flot);
ListeLogements ajouterLogementListe(ListeLogements listeLogements, Logement logement);
ListeLogements chargementLogements(FILE* fe);
void afficherLogement(Logement loge);
ListeLogements trierParNomCite(ListeLogements listeLogements);
void sauvegardeLogements(ListeLogements logements, FILE* fe);
ListeLogements inserTete (ListeLogements l, char *nomVille);
ListeLogements trierParNomCite(ListeLogements listeLogements, char *nomVille);
Logement triListe (Logement loge);

#endif