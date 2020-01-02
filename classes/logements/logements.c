#include "logements.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../enum/enum.h"

Logement lireLogement(FILE* flot) {
    Logement loge;
    TypeLogement type;

    char nomCite[65];
    int tailleNomCite;

    fscanf(flot, "%d%*c", &loge.idLogement);

    fgets(nomCite, 65, flot);
    tailleNomCite = strlen(nomCite);

    if(nomCite[tailleNomCite - 1] == '\n') {
        nomCite[tailleNomCite - 1] = '\0';
        tailleNomCite--;
    }

    loge.nomCite = (char*) malloc(sizeof(char) * tailleNomCite + 1);
    if (loge.nomCite == NULL) {
        printf("Problème d'allocation mémoire\n");
        exit(1);
    }
    
    strcpy(loge.nomCite, nomCite);

    fscanf(flot, "%d%*c", &loge.typeLogement);
    
    fscanf(flot, "%d%*c", &loge.disponible);

    fscanf(flot, "%d%*c", &loge.adapteHandicap);

    if (!loge.disponible) {
        fscanf(flot, "%d%*c", &loge.idEtudiant);
    }

    return loge;
}