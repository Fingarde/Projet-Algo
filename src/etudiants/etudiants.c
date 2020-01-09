#include "etudiants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../enum/enum.h"
#include "../color/color.h"


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

ListeEtudiants creerListeVide() {
    return NULL;
}

ListeEtudiants ajouterEtudiantListe(ListeEtudiants listeEtudiants, Etudiant etudiant) {
	MaillonEtudiant* tmp;

    int taillePrenom, tailleNom;

	tmp = (MaillonEtudiant*) malloc(sizeof(MaillonEtudiant));
    if(tmp == NULL) {
        printf("Problème mémoire");
        exit(1);
    }

    tmp->etudiant.idEtudiant = etudiant.idEtudiant;
    tmp->etudiant.civilite = etudiant.civilite;

    tailleNom = strlen(etudiant.nom);
    tmp->etudiant.nom = (char*) malloc(sizeof(char) * tailleNom + 1);
    strcpy(tmp->etudiant.nom, etudiant.nom);

    taillePrenom = strlen(etudiant.prenom);
    tmp->etudiant.prenom = (char*) malloc(sizeof(char) * taillePrenom + 1);
    strcpy(tmp->etudiant.prenom, etudiant.prenom);

    tmp->etudiant.boursie = etudiant.boursie;
    tmp->etudiant.echelon = etudiant.echelon;
    tmp->etudiant.handicape = etudiant.handicape;
    
    tmp->suivant = listeEtudiants;
	
	return tmp;
}

ListeEtudiants chargementEtudiants(FILE* fe) {
	ListeEtudiants etudiants = creerListeVide();
	Etudiant etud;
	
	etud = lireEtudiant(fe);
	etudiants = ajouterEtudiantListe(etudiants, etud);

	while(feof(fe) == 0) {
		etud = lireEtudiant(fe);
		etudiants = ajouterEtudiantListe(etudiants, etud);
	}

	return etudiants;
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