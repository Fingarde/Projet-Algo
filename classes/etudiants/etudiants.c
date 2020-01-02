#include "etudiants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../enum/enum.h"

Etudiant lireEtudiant(FILE* flot) {
    Etudiant etud;

    char nom[65];
    int tailleNom;
    char prenom[65];
    int taillePrenom;

    etud.echelon = AUCUN;

    fscanf(flot, "%d%*c", &etud.idEtudiant); // ID Etudiant

    fscanf(flot, "%d%*c", &etud.civilite); // Civilite

    fgets(nom, 65, flot); // Nom
    tailleNom = strlen(nom);
    if(nom[tailleNom - 1] == '\n') {
        nom[tailleNom - 1] = '\0';
        tailleNom--;
    }

    etud.nom = (char*) malloc(sizeof(char) * tailleNom + 1);
    if (etud.nom == NULL) {
        printf("Problème d'allocation de la mémoire\n");
        exit(1);
    }

    strcpy(etud.nom, nom);


    fgets(prenom, 65, flot); // Prenom
    taillePrenom = strlen(prenom);

    if(prenom[taillePrenom - 1] == '\n') {
        prenom[taillePrenom - 1] = '\0';
        taillePrenom--;
    }

    etud.prenom = (char*) malloc(sizeof(char) * taillePrenom + 1);
    if (etud.prenom == NULL) {
        printf("Problème d'allocation de la mémoire\n");
        exit(1);
    }

    strcpy(etud.prenom, prenom);

    fscanf(flot, "%d%*c", &etud.boursie); // Boursier
    if(etud.boursie) {
        fscanf(flot, "%d%*c", &etud.echelon); // Echelon
    }

    fscanf(flot, "%d%*c", &etud.handicape);
    
    return etud;
}