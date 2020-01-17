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
	if (tmp->demande.nomCite == NULL) {
		printf("Problème d'allocation mèmoire\n");
		exit(1);
	}
	strcpy(tmp->demande.nomCite, demande.nomCite);

	tmp->demande.typeLogement = demande.typeLogement;
	tmp->demande.idEtudiant = demande.idEtudiant;
	tmp->demande.echelon = demande.echelon;

	tmp->suivant = listeDemandes;

	return tmp;
}

ListeDemandes initListeDemandes() {
    return NULL;
}

ListeDemandes chargementDemandes(FILE* fe) {
	ListeDemandes demandes = initListeDemandes();
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

MaillonDemande* rechercheListe (ListeDemandes listeDemandes, int idDemande) {
	MaillonDemande* tmp = listeDemandes;

	if (listeDemandes == NULL) { 
		return NULL; 
	}          

	if (tmp->demande.idDemande == idDemande) {
		return listeDemandes;
	}

	tmp = rechercheListe(listeDemandes->suivant, idDemande);

	return tmp;
}

Demande ajouterDemande (ListeDemandes listeDemandes) {
	Demande demande;
	char nomCite[65];
	int tailleCite;

	printf(BOLD_GREEN "ID Demande : " RESET);
	scanf("%d%*c", &demande.idDemande);

	if (rechercheListe(listeDemandes, demande.idDemande) != NULL) {
		printf(BOLD_RED "La demande existe déja\n");
		demande.idDemande = -1;
        return demande;
	}

	printf(BOLD_GREEN "ID Étudiant : " RESET);
	scanf("%d%*c", &demande.idEtudiant);

	printf(BOLD_GREEN "Échelon de bourse : " RESET);
	scanf("%d%*c", &demande.echelon);

	printf(BOLD_GREEN "Nom de la cité : " RESET);
	fgets(nomCite, 65, stdin);

	tailleCite = strlen(nomCite);
	if (nomCite[tailleCite - 1] == '\n') {
		nomCite[tailleCite - 1] = '\0';
	}

	demande.nomCite = (char*) malloc(sizeof(char) * tailleCite + 1);
	if (demande.nomCite == NULL) {
		printf("Problème d'allocation mémoire\n");
		exit(1);
	}
	strcpy(demande.nomCite, nomCite);

	printf(BOLD_GREEN "Type de logement : "RESET);
	scanf("%d%*c", &demande.typeLogement);

	return demande;
}


ListeDemandes insererEnTeteDemande(ListeDemandes liste, Demande dema) {
    MaillonDemande* tmp;

    tmp = (MaillonDemande*) malloc(sizeof(MaillonDemande));
    if (tmp == NULL) {
        printf("Problème allocation\n");
        exit(1);
    }

    tmp->demande = dema;

    tmp->suivant = liste;
    liste = tmp;

    return liste;
}

ListeDemandes insererTrieDemandes(ListeDemandes liste, Demande dema) {
   if(liste == NULL) {
       liste = insererEnTeteDemande(liste, dema);
   }
   else if(liste->demande.echelon > dema.echelon) {
       liste = insererEnTeteDemande(liste, dema);
   }
   else {
       liste->suivant = insererTrieDemandes(liste->suivant, dema);
   }

   return liste;
}
