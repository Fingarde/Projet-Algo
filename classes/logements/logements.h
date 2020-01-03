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
typedef struct maillon {
	Logement logement;
	struct maillon* suiv;
} MaillonLoge;

// Liste logements
typedef MaillonLoge* ListeLogement;

/* Prototypes */

char* getTypeLogement(TypeLogement typeLogement);
Logement lireLogement(FILE* flot);

#endif