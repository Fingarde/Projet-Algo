#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

#include "../color/color.h"

#include "../etudiants/etudiants.h"
#include "../logements/logements.h"
#include "../demandes/demandes.h"

void afficherMenuPrincipal() {
	printf(BOLD_RED "▬▬  " BOLD_YELLOW "Bienvenue sur le programme de demandes de logement du CROUS" BOLD_RED "  ▬▬\n");
	printf("\n");
	printf(BOLD_YELLOW "1» " BOLD_WHITE "Afficher la liste des logements disponibles\n");
	printf(BOLD_YELLOW "2» " BOLD_WHITE "Afficher la liste des logements occupés\n");
	printf(BOLD_YELLOW "3» " BOLD_WHITE "Afficher la liste des demandes de logements en attente\n");
	printf("\n");
	printf(BOLD_YELLOW "4» " BOLD_WHITE "Traiter les demandes en attentes\n");
	printf("\n");
	printf(BOLD_YELLOW "5 " BOLD_WHITE "Saisir une nouvelle demande de logements\n");
	printf(BOLD_YELLOW "6» " BOLD_WHITE "Annuler une demande de logements\n");
	printf(BOLD_YELLOW "7» " BOLD_WHITE "Libérer un logement\n");
	printf("\n");
	printf(BOLD_YELLOW "9» " BOLD_WHITE "Quitter le programme\n");
}

void afficherListeLogementsDispo(ListeLogements listeLogements) {
	ListeLogements logeTmp = listeLogements;

	logeTmp = trierLogements(logeTmp);
	while(logeTmp != NULL) {
		if(logeTmp->logement.disponible) { // == 0
			afficherLogement(logeTmp->logement); // Libre
			printf("\n");
		}
	
		logeTmp = logeTmp->suivant;
	}
}

void afficherListeLogementsOccupe(ListeLogements listeLogements) {
	ListeLogements logeTmp = listeLogements;

	logeTmp = trierLogements(logeTmp);
	while(logeTmp != NULL) {
		if(!logeTmp->logement.disponible) { // == 1
			afficherLogement(logeTmp->logement); // Occupé
			printf("\n");
		}
		
		logeTmp = logeTmp->suivant;
	}
}

void afficherDemandesEnAttentes(ListeDemandes listeDemandes) {
	if(listeDemandes == NULL) return;

  	afficherDemande(listeDemandes->demande);
  	afficherDemandesEnAttentes (listeDemandes->suivant);
}

void departEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants) {
	int idEtudiant;
	
	printf(BOLD_GREEN "ID de l'étudiant a supprimer: " BOLD_CYAN);
	scanf("%d", &idEtudiant);


	supprimerEtudiant(logements, etudiants, nbEtudiants, idEtudiant);
}

ListeDemandes ajouterDemandeEnAttentes(ListeDemandes listeDemandes) {
	Demande demande;

	demande = ajouterDemande(listeDemandes);
	if(demande.idDemande == -1) {
		return listeDemandes;
	}


	return insererTrieDemandes(listeDemandes, demande);
}

ListeDemandes rechercheDemande(ListeDemandes listeDemandes, int idDemande) {
	if(listeDemandes == NULL) return NULL;
 
	if(listeDemandes->demande.idDemande == idDemande) return listeDemandes;

	return rechercheDemande(listeDemandes->suivant, idDemande);
}

ListeDemandes supprimerDemandeEnAttentes(ListeDemandes listeDemandes) {
	int idDemande;
	MaillonDemande* tmp;
	ListeDemandes avant = listeDemandes;

	printf(BOLD_GREEN "ID Demande : " RESET);
	scanf("%d%*c", &idDemande);

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

	

	return listeDemandes;
}


/*void traitementDemandesEnAttentes (ListeDemandes listeDemandes, ListeLogements listeLogements) {
	if (listeDemandes[i]->disponible == 1) {
		if (listeDemandes[i]->)
		{
		}
	}
}*/