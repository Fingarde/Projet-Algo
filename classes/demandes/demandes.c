#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "demandes.h"

#include "../etudiants/etudiants.h"
#include "../logements/logements.h"

Demande lireDemande (FILE* flot) {
	Demande dema;

	char nomCite[65];
  int tailleNomCite;

  // ID Demande
	fscanf(flot, "%d%*c", &dema.idDemande); 
  // ID Étudiant
	fscanf(flot, "%d%*c", &dema.idEtudiant);
  // Échelon bourse
  fscanf(flot, "%d%*c", &dema.echelon);

  // Nom cité
	fgets(nomCite, 65, flot);
  tailleNomCite = strlen(nomCite);
  if(nomCite[tailleNomCite - 1] == '\n') {
    nomCite[tailleNomCite - 1] = '\0';
    tailleNomCite--;
	}

	dema.nomCite = (char*) malloc(sizeof(char) * tailleNomCite + 1);
  if (dema.nomCite == NULL) {
    printf("Problème d'allocation mémoire\n");
    exit(1);
  }
  strcpy(dema.nomCite, nomCite);
  
  // Type logement
  fscanf(flot, "%d%*c", &dema.typeLogement);

  return dema;
}
