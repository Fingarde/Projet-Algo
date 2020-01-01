#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "logements.h"

char typeLogementValues[4][8] = {"Chambre", "Studio", "T1", "T2"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getTypeLogement(TypeLogement typeLogement) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return typeLogementValues[typeLogement];
}

Logement lireLogement(FILE* flot) {
    Logement loge;
    TypeLogement type;

    char nomCite[65];
    int tailleNomCite;
    char typeLoge[8];

    loge.idEtudiant = -1;

    fscanf(flot, "%d%*c", &loge.idLogement);

    fgets(nomCite, 65, flot);
    tailleNomCite = strlen(nomCite);
    if(nomCite[tailleNomCite - 2] == '\n') {
        nomCite[tailleNomCite - 2] = '\0';
        tailleNomCite--;
    }
    loge.nomCite = (char*) malloc(sizeof(char) * tailleNomCite + 1);
    if (loge.nomCite == NULL) {
        printf("Problème d'allocation mémoire\n");
        exit(1);
    }
    strcpy(loge.nomCite, nomCite);

    typeLoge = getTypeLogement(type);

    fscanf(flot, "%d%*c", &loge.typeLogement);
    
    // Booléen disponible

    // Booléen adapté handicapé

    if (loge.disponible == 0) {
        fscanf(flot, "%d%*c", &loge.idEtudiant);
    }

    return loge;
}