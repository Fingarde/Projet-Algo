#include "etudiants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char civiliteValues[2][4] = {"Mr", "Mme"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getCivilite(Civilite civilite) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return civiliteValues[civilite];
}


char echelonValues[8][5] = {"0bis", "01", "02", "03", "04", "05", "06", "07"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getEchelon(Echelon echelon) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return echelonValues[echelon];
}

Etudiant lireEtudiant(FILE* flot) {
    Etudiant etudiant;

    char nom[65];
    int tailleNom;

    char prenom[65];
    int taillePrenom;

    fscanf(flot, "%d%*c", &etudiant.idEtudiant);
    fscanf(flot, "%d%*c", &etudiant.civilite);

    fgets(nom, 65, flot);
    tailleNom = strlen(nom);
    if(nom[tailleNom - 2] == '\n') {
        nom[tailleNom - 2] = '\0';
        tailleNom--;
    }
    etudiant.nom = (char*) malloc(sizeof(char) * tailleNom + 1);
    strcpy(etudiant.nom, nom);

    fgets(prenom, 65, flot);
    taillePrenom = strlen(prenom);
    if(prenom[taillePrenom - 2] == '\n') {
        prenom[taillePrenom - 2] = '\0';
        taillePrenom--;
    }
    etudiant.prenom = (char*) malloc(sizeof(char) * taillePrenom + 1);
    strcpy(etudiant.prenom, prenom);

    fscanf(flot, "%d%*c", &etudiant.echelon);
    fscanf(flot, "%d%*c", &etudiant.handicape);

    return etudiant;
}

bool isBoursier(Etudiant etudiant) {
    if(etudiant.echelon) return true;
    return false;
}