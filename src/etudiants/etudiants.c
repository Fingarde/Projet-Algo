#include "etudiants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../enum/enum.h"
#include "../color/color.h"

#include "../logements/logements.h"

Etudiant lireEtudiant(FILE* flot) {
    Etudiant etud;

    char nom[65];
    int tailleNom;
    char prenom[65];
    int taillePrenom;

    etud.echelon = AUCUN;

    fscanf(flot, "%d%*c", &etud.idEtudiant); // ID Etudiant

    fscanf(flot, "%d%*c", &etud.civilite); // Civilite

    fgets(etud.nom, 65, flot); // Nom
    tailleNom = strlen(etud.nom);
    if(etud.nom[tailleNom - 1] == '\n') {
        etud.nom[tailleNom - 1] = '\0';
        tailleNom--;
    }

    fgets(etud.prenom, 65, flot); // Prenom
    taillePrenom = strlen(etud.prenom);
    if(etud.prenom[taillePrenom - 1] == '\n') {
        etud.prenom[taillePrenom - 1] = '\0';
        taillePrenom--;
    }

    fscanf(flot, "%d%*c", &etud.boursie); // Boursier
    if(etud.boursie) {
        fscanf(flot, "%d%*c", &etud.echelon); // Echelon
    }

    fscanf(flot, "%d%*c", &etud.handicape); // Handicape
    
    return etud;
}

void afficherEtudiant(Etudiant etud) {
    printf(UNDERLINE_YELLOW BOLD_YELLOW "Etudiant N°%d\n" RESET, etud.idEtudiant);

	printf(BOLD_BLUE "%s %s\n" RESET, etud.nom, etud.prenom);
	printf(BOLD_CYAN "Civilité: %s%s\n" RESET, etud.civilite == 0 ? BOLD_CYAN : BOLD_MAGENTA, getCivilite(etud.civilite));

	if(etud.handicape) printf(BOLD_RED "Est handicapé\n" RESET);
	else printf(BOLD_GREEN "N'est pas handicapé\n" RESET);
	
	if(etud.boursie) printf(BOLD_GREEN "Echelon de bourse: %s\n" RESET, getEchelon(etud.echelon));
	else printf(BOLD_RED "N'est pas boursier\n" RESET);
}

MaillonLogement* getLogement(ListeLogements logements, Etudiant etud) {
    if(logements == NULL) return NULL;

    if(logements->logement.idEtudiant == etud.idEtudiant) return logements;
    return getLogement(logements->suivant, etud);
}

int rechercheEtudiant(Etudiant etudiants[], int idEtudiant, int* position) {
    // recherche dichotomique
}

void insererEtudiant(Etudiant etudiants[], int* nbEtudiants) {
    Etudiant etudiant;
    int position;

    printf(BOLD_GREEN "ID de l'étudiant: " BOLD_CYAN);
    scanf("%d", &(etudiant.idEtudiant));
    if(rechercheEtudiant(etudiants, etudiant.idEtudiant, &position) != -1) {
        printf(BOLD_RED "L'etudiant existe déja");
        return;
    }


    // Faire tout les scanf


    printf("%d", etudiant.idEtudiant);
    //(*nbEtudiants)++;
}

void supprimerEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants, int positionEtudiant) {
    MaillonLogement* logement;
    int index;

    logement = getLogement(logements, etudiants[positionEtudiant]);
    if(logement != NULL) {
        logement->logement.disponible = 1;
    }

    for(index = positionEtudiant; index < (*nbEtudiants) - 1; index++) {
        etudiants[index] = etudiants[index + 1];
    }

    (*nbEtudiants)--;
}

