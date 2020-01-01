#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "etudiants.h"

char civiliteValues[2][4] = {"Mr", "Mme"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getCivilite(Civilite civilite) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return civiliteValues[civilite];
}

char echelonValues[8][5] = {"0bis", "01", "02", "03", "04", "05", "06", "07"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getEchelon(Echelon echelon) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return echelonValues[echelon];
}

Etudiant lireEtudiant(FILE* flot) {
    Etudiant etud;
    Civilite civi;
    Echelon eche;

    char civilite[4];
    char nom[65];
    int tailleNom;
    char prenom[65];
    int taillePrenom;
    char echelon[5];

    fscanf(flot, "%d%*c", &etud.idEtudiant);

    civilite = getCivilite(civi);

    fscanf(flot, "%d%*c", &etud.civilite);

    fgets(nom, 65, flot);
    tailleNom = strlen(nom);
    if(nom[tailleNom - 2] == '\n') {
        nom[tailleNom - 2] = '\0';
        tailleNom--;
    }
    etud.nom = (char*)malloc(sizeof(char) * tailleNom + 1);
    if (etud.nom == NULL) {
        printf("Problème d'allocation de la mémoire\n");
        exit(1);
    }
    strcpy(etud.nom, nom);

    fgets(prenom, 65, flot);
    taillePrenom = strlen(prenom);
    if(prenom[taillePrenom - 2] == '\n') {
        prenom[taillePrenom - 2] = '\0';
        taillePrenom--;
    }
    etud.prenom = (char*)malloc(sizeof(char) * taillePrenom + 1);
    if (etud.prenom == NULL) {
        printf("Problème d'allocation de la mémoire\n");
        exit(1);
    }
    strcpy(etud.prenom, prenom);

    echelon = getEchelon[eche];

    // Booleen handicape

    return etud;
}

bool isBoursier(Etudiant etud) {
    if (etud.echelon) {
        return true;
    }
    return false;
}