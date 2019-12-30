#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "demandes.h"

char echelonValues[8][5] = {"0bis", "01", "02", "03", "04", "05", "06", "07"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getEchelon(Echelon echelon) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return echelonValues[echelon];
}

char typeLogementValues[4][8] = {"Chambre", "Studio", "T1", "T2"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getTypeLogement(TypeLogement typeLogement) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return typeLogementValues[typeLogement];
}

Demande lireDemande (FILE* flot) {
	Demande dema;

	char nomCite[65];
    int tailleNomCite;

	fscanf(flot, "%d%*c", &dema.idDemande);
	fscanf(flot, "%d%*c", &dema.idEtudiant);

	fgets(nomCite, 65, flot);
    tailleNomCite = strlen(nomCite);
    if(nomCite[tailleNomCite - 2] == '\n') {
        nomCite[tailleNomCite - 2] = '\0';
        tailleNomCite--;
    }
    dema.nomCite = (char*) malloc(sizeof(char) * tailleNomCite + 1);
    if (dema.nomCite == NULL) {
        printf("Problème d'allocation mémoire\n");
        exit(1);
    }
    strcpy(dema.nomCite, nomCite);
}