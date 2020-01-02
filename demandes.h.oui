#ifndef DEMANDES_H
#define DEMANDES_H

#include <stdio.h>
#include <stdbool.h>

#include "etudiants.h"
#include "logements.h"

/* Structure */

typedef struct {
	int idDemande;
	int idEtudiant;
	Echelon echelon;
	char* nomCite;
	TypeLogement typeLogement;
} Demande;

/* Prototypes */

char* getEchelon(Echelon echelon);
char* getTypeLogement(TypeLogement typeLogement);
Demande lireDemande (FILE* flot);

#endif