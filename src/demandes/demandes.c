#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "demandes.h"

#include "../etudiants/etudiants.h"
#include "../logements/logements.h"
#include "../color/color.h"

/*  Fonction : lireDemande
    Finalité : lire une demande sur un flot
    Paramètres : flot - flot d'entrée des données 
	Variables : dema - structure d'une demande
				nomCite - nom de la cite 
				tailleNomCite - taille du nom de la cite
    Valeur retournée : dema - structure d'une demande
*/

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
	

	fscanf(flot, "%d%*c", &dema.typeLogement);

	return dema;
}

/*  Fonction : ajouterDemandeListe
    Finalité : ajouter une demande dans la liste
    Paramètres : listeDemandes - liste contenant les demandes
				 demande - structure de demande 
	Variables : tmp - adresse vers le maillon de la liste
				tailleCite - taille du nom de la cite
    Valeur retournée : tmp - adresse vers le maillon de la liste
*/

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

/*  Fonction : initListeDemandes
    Finalité : initialise la liste
    Valeur retournée : NULL - valeur du pointeur de liste
*/

ListeDemandes initListeDemandes() {
    return NULL;
}

/*  Fonction : chargementDemandes
    Finalité : charger les demandes dans une liste 
    Paramètres : fe - flot d'entrée des données 
	Variables : demandes - liste de demandes
				dema - structure d'un étudiant 
    Valeur retournée : demandes - liste de demandes
*/

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

/*  Fonction : afficherDemande
    Finalité : afficher la liste de demandes
    Paramètres : dema - structure d'une demande
*/

void afficherDemande(Demande dema) {
	printf(UNDERLINE_YELLOW BOLD_YELLOW "Demande N°%d\n" RESET, dema.idDemande);

	printf(BOLD_GREEN "Etudiant N°%d\n" RESET, dema.idEtudiant);
	printf(BOLD_CYAN "Echelon %s\n" RESET, getEchelon(dema.echelon));
	
	printf(BOLD_BLUE "%s\n" RESET, dema.nomCite);

	printf(BOLD_MAGENTA "%s\n" RESET, getTypeLogement(dema.typeLogement));
}

/*  Fonction : sauvegardeDemandes
    Finalité : sauvegarder les demandes 
    Paramètres : demandes - liste de demandes
				 fe - flot d'entrée des données
*/

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

/*  Fonction : rechercheListe
    Finalité : rechercher une demande dans la liste
    Paramètres : listeDemandes - liste de demandes
				 idDemande - ID d'une demande
	Variables : tmp - adresse vers le maillon de la liste
    Valeur retournée : tmp - adresse vers le maillon de la liste
*/

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

/*  Fonction : ajouterDemande
    Finalité : ajouter une demande dans la liste
    Paramètres : listeDemandes - liste de demandes
	Variables : demande - structure d'une demande
				nomCite - nom de la cite 
				tailleCite - taille du nom de la cite
    Valeur retournée : demande - structure d'une demande
*/

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

/*  Fonction : insererEnTeteDemande
    Finalité : inserer une demande en tete de liste
    Paramètres : liste - liste de demandes
				 dema - structure de demande
	Variable : tmp - adresse vers le maillon de la liste
    Valeur retournée : tmp - adresse vers le maillon de la liste
*/

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

/*  Fonction : insererTrieDemandes
    Finalité : inserer une demande au bon endroit dans la liste
    Paramètres : liste - liste de demandes
				 dema - structure de demande
    Valeur retournée : liste - liste de demandes
*/

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

/*  Fonction : supprimerDemande
    Finalité : supprimer une demande de la liste
    Paramètres : listeDemandes - liste de demandes
				 idDemande - ID d'une demande
	Variables : tmp - adresse vers le maillon de la liste
				avant = liste de demandes 
    Valeur retournée : listeDemandes - liste de demandes
*/

ListeDemandes supprimerDemande(ListeDemandes listeDemandes, int idDemande) {
	MaillonDemande* tmp;
	ListeDemandes avant = listeDemandes;

	tmp = rechercheDemande(listeDemandes, idDemande);
	if(tmp == NULL)
	{
		printf(BOLD_RED "La demande spécifié n'existe pas");
		return listeDemandes;
	}

	if(avant != tmp) {
		while(avant->suivant != NULL && avant->suivant != tmp)
			avant = avant->suivant;

			avant->suivant = tmp->suivant;
	}
	else {
		listeDemandes = avant->suivant;
	}
}

/*  Fonction : rechercheDemande
    Finalité : recherche une demande dans la liste
    Paramètres : listeDemandes - liste de demandes
				 idDemande - ID d'une demande
    Valeur retournée : listeDemandes - liste de demandes
*/

ListeDemandes rechercheDemande(ListeDemandes listeDemandes, int idDemande) {
	if(listeDemandes == NULL) return NULL;
 
	if(listeDemandes->demande.idDemande == idDemande) return listeDemandes;

	return rechercheDemande(listeDemandes->suivant, idDemande);
}

/*  Fonction : traiterDemande
    Finalité : traiter les demandes en attentes
    Paramètres : demande - structure d'une demande
				 listeLogements - liste des logements 
				 etudiants[] - tableau d'étudiants
				 nbEtudiants - nombre d'étudiants
	Variables : tmp - adresse vers le maillon de la liste
    Valeur retournée : 0 ou 1 - demande traitée ou non
*/

int traiterDemande(Demande demande, ListeLogements listeLogements, Etudiant etudiants[], int nbEtudiants) {
	ListeLogements tmp;

	for(tmp = listeLogements; tmp != NULL; tmp = tmp->suivant) {
		int pos;
		if(!tmp->logement.disponible) continue;

		if(strcmp(tmp->logement.nomCite, demande.nomCite) != 0) continue;
		if(tmp->logement.typeLogement != demande.typeLogement) continue;
	
		pos = rechercheEtudiant(etudiants, demande.idEtudiant, nbEtudiants);
		if(etudiants[pos].handicape != tmp->logement.adapteHandicap) continue;

		tmp->logement.disponible = 0;
		tmp->logement.idEtudiant = demande.idDemande;

		return 1;
	}

	return 0;
}