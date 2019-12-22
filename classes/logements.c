#include "logements.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char typeLogementValues[4][8] = {"Chambre", "Studio", "T1", "T2"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getTypeLogement(TypeLogement typeLogement) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return typeLogementValues[typeLogement];
}

Logement lireLogement(FILE* flot) {
    Logement logement;

    char nomCite[65];
    int tailleNomCite;

    logement.idEtudiant = -1;

    fscanf(flot, "%d%*c", &logement.idLogement);

    fgets(nomCite, 65, flot);
    tailleNomCite = strlen(nomCite);
    if(nomCite[tailleNomCite - 2] == '\n') {
        nomCite[tailleNomCite - 2] = '\0';
        tailleNomCite--;
    }
    logement.nomCite = (char*) malloc(sizeof(char) * tailleNomCite + 1);
    strcpy(logement.nomCite, nomCite);

    fscanf(flot, "%d%*c", &logement.typeLogement);
    fscanf(flot, "%d%*c", &logement.disponible);
    fscanf(flot, "%d%*c", &logement.adapteHandicap);

    if(logement.disponible == 0) fscanf(flot, "%d%*c", &logement.idEtudiant);

    return logement;
}

