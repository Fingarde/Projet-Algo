#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "demandes.h"

#include "../etudiants/etudiants.h"
#include "../logements/logements.h"
#include "../color/color.h"


Demande lireDemande (FILE* flot) {
	Demande dema;

	char nomCite[65];
	int tailleNomCite;

	// ID Demande
	fscanf(flot, "%d%*c", &dema.idDemande); 
	// ID Étudiant
	fscanf(flot, "%d%*c", &dema.idEtudiant);
	// Échelon bourse
	fscanf(flot, "%d%*c", &dema.echelon);

	// Nom cité
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
	
	// Type logement
	fscanf(flot, "%d%*c", &dema.typeLogement);

	return dema;
}

ListeDemandes ajouterDemandeListe(ListeDemandes listeDemandes, Demande demande) {
	MaillonDemande* tmp;

	int tailleCite;

	tmp = (MaillonDemande*) malloc(sizeof(MaillonDemande));
	if(tmp == NULL) {
			printf("Problème mémoire");
			exit(1);
	}

	tmp->demande.idDemande = demande.idDemande;

	tailleCite = strlen(demande.nomCite);
	tmp->demande.nomCite = (char*) malloc(sizeof(char) * tailleCite + 1);
	strcpy(tmp->demande.nomCite, demande.nomCite);

	tmp->demande.typeLogement = demande.typeLogement;
	tmp->demande.idEtudiant = demande.idEtudiant;
	tmp->demande.echelon = demande.echelon;

	tmp->suivant = listeDemandes;

	return tmp;
}

ListeDemandes chargementDemandes(FILE* fe) {
	ListeDemandes demandes = NULL;
	Demande dema;
	
	dema = lireDemande(fe);
	demandes = ajouterDemandeListe(demandes, dema);

	while(feof(fe) == 0) {
		dema = lireDemande(fe);
		demandes = ajouterDemandeListe(demandes, dema);
	}

	return demandes;
}

void afficherDemande(Demande dema) {
	printf(UNDERLINE_YELLOW BOLD_YELLOW "Demande N°%d\n" RESET, dema.idDemande);

	printf(BOLD_GREEN "Etudiant N°%d\n" RESET, dema.idEtudiant);
	printf(BOLD_CYAN "Echelon %s\n" RESET, getEchelon(dema.echelon));
	
	printf(BOLD_BLUE "%s\n" RESET, dema.nomCite);

	printf(BOLD_MAGENTA "%s\n" RESET, getTypeLogement(dema.typeLogement));
}

void sauvegardeDemandes(ListeDemandes demandes, FILE* fe) {
	if(demandes == NULL) return;

  	sauvegardeDemandes(demandes->suivant, fe);

  	if(demandes->suivant != NULL) fprintf(fe, "\n");

    fprintf(fe, "%d\n", demandes->demande.idDemande);
    fprintf(fe, "%d\n", demandes->demande.idEtudiant);
    fprintf(fe, "%d\n", demandes->demande.echelon);
    fprintf(fe, "%s\n", demandes->demande.nomCite);
    fprintf(fe, "%d", demandes->demande.typeLogement);
}

void insererDemande (ListeDemandes ListeDemandes) {
	MaillonDemande* tmp;

	int tailleCite;

	tmp = (MaillonDemande*) malloc(sizeof(MaillonDemande));
	if (tmp == NULL) {
			printf("Problème mémoire");
			exit(1);
	}

	printf(BOLD_GREEN "ID Demande : " RESET);
	scanf("%d", tmp->demande.idDemande);

	printf(BOLD_GREEN "ID Étudiant : " RESET);
	scanf("%d", tmp->demande.idEtudiant);

	printf(BOLD_GREEN "Échelon de bourse : " RESET);
	scanf("%d", tmp->demande.echelon);

	printf(BOLD_GREEN "Nom de la cité : " RESET);
}