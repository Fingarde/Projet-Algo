#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "demandes.h"

#include "etudiants.h"
#include "logements.h"

Demande lireDemande (FILE* flot) {
	Demande dema;
  Echelon eche;
  TypeLogement type;

	char nomCite[65];
  int tailleNomCite;


	fscanf(flot, "%d%*c", &dema.idDemande);
	fscanf(flot, "%d%*c", &dema.idEtudiant);

  fscanf(flot, "%d%*c", &dema.echelon);

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
  
  fscanf(flot, "%d%*c", &dema.typeLogement);

  return dema;
}
