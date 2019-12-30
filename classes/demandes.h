#include <stdio.h>
#include <stdbool.h>

#include "etudiants.h"
#include "logements.h"

/* Structures */

typedef struct {
	int idDemande;
	int idEtudiant;
	Echelon echelon;
	char* nomCite;
	TypeLogement typeLogement;
} Demande;

/* Fonctions */

char* getEchelon(Echelon echelon)
char* getTypeLogement(TypeLogement typeLogement);
Demande lireDemande (FILE* flot)