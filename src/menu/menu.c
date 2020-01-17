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
	printf(BOLD_YELLOW "5» " BOLD_WHITE "Saisir une nouvelle demande de logements\n");
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

ListeDemandes departEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants, ListeDemandes listeDemandes) {
	int idEtudiant;
	
	printf(BOLD_GREEN "ID de l'étudiant a supprimer: " BOLD_CYAN);
	scanf("%d", &idEtudiant);


	supprimerEtudiant(logements, etudiants, nbEtudiants, idEtudiant);
	return traitementDemandesEnAttentes(listeDemandes, logements, etudiants, *nbEtudiants); 
}

ListeDemandes ajouterDemandeEnAttentes(ListeDemandes listeDemandes) {
	Demande demande;

	demande = ajouterDemande(listeDemandes);
	if(demande.idDemande == -1) {
		return listeDemandes;
	}


	return insererTrieDemandes(listeDemandes, demande);
}


ListeDemandes supprimerDemandeEnAttentes(ListeDemandes listeDemandes) {
	int idDemande;


	printf(BOLD_GREEN "ID Demande : " RESET);
	scanf("%d%*c", &idDemande);

	return supprimerDemande(listeDemandes, idDemande);
}

ListeDemandes traitementDemandesEnAttentes (ListeDemandes listeDemandes, ListeLogements listeLogements, Etudiant etudiants[], int nbEtudiants) {
	ListeDemandes tmp;
	int traite;

	for(tmp = listeDemandes; tmp != NULL; tmp = tmp->suivant) {
		traite = traiterDemande(tmp->demande, listeLogements, etudiants, nbEtudiants);
		if(traite) {
			listeDemandes = supprimerDemande(listeDemandes, tmp->demande.idDemande);
			return listeDemandes;
			
			break;
		}
	}

	return listeDemandes;
}