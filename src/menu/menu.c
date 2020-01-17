#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

#include "../color/color.h"

#include "../etudiants/etudiants.h"
#include "../logements/logements.h"
#include "../demandes/demandes.h"


/* 
   	Fonction: afficherMenuPrincipal
   	Finalité: Affiche le menu principale
*/
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

/* 
   	Fonction: afficherListeLogementsDispo
	Paramètre entrant/sortant
		- listeLogements		liste chainée des logements
   	Finalité: Affiche les logements disponibles triés par nom de cité
*/
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

/* 
   	Fonction: afficherListeLogementsOccupe
	Paramètre entrant/sortant
		- listeLogements		liste chainée des logements
   	Finalité: Affiche les logements disponibles triés par nom de cité
*/
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

/* 
   	Fonction: afficherDemandesEnAttentes
	Paramètre entrant/sortant
		- listeDemandes		liste chainée des demandes
   	Finalité: Affiche les demandes en attentes
*/
void afficherDemandesEnAttentes(ListeDemandes listeDemandes) {
	if(listeDemandes == NULL) return;

  	afficherDemande(listeDemandes->demande);
  	afficherDemandesEnAttentes (listeDemandes->suivant);
}

/* 
   	Fonction: departEtudiant
   	Finalité: Supprime un etudiant, libère son logement si il en avait un et traite les demandes
	Paramètre entrant/sortant
		- logements			liste chainée des logements
		- etudiants			tableau d'étudiants
		- nbEtudiant		pointeur sur le nombre d'étudiant du tableau
		- listeDemandes		liste chainée des demandes
    Variables : 
        - idEtudiant 		id de l'étudiant a supprimer
    Valeur retournée : 
        La nouvelle liste de demandes
*/
ListeDemandes departEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants, ListeDemandes listeDemandes) {
	int idEtudiant;
	
	printf(BOLD_GREEN "ID de l'étudiant a supprimer: " BOLD_CYAN);
	scanf("%d", &idEtudiant);


	supprimerEtudiant(logements, etudiants, nbEtudiants, idEtudiant);
	return traitementDemandesEnAttentes(listeDemandes, logements, etudiants, *nbEtudiants); 
}

/* 
   	Fonction: ajouterDemandeEnAttentes
   	Finalité: Saisi puis ajoute une nouvelle demande
	Paramètre entrant/sortant
		- listeDemandes		liste chainée des demandes
    Variables : 
        - demande 			la demande a ajouter
    Valeur retournée : 
        La nouvelle liste de demandes
*/
ListeDemandes ajouterDemandeEnAttentes(ListeDemandes listeDemandes) {
	Demande demande;

	demande = ajouterDemande(listeDemandes);
	if(demande.idDemande == -1) {
		return listeDemandes;
	}


	return insererTrieDemandes(listeDemandes, demande);
}



/* 
   	Fonction: supprimerDemandeEnAttentes
   	Finalité: Saisi puis supprime une demande
	Paramètre entrant/sortant
		- listeDemandes		liste chainée des demandes
    Variables: 
        - idDemande 		l'id de la demande a supprimer
    Valeur retournée : 
        La nouvelle liste de demandes
*/
ListeDemandes supprimerDemandeEnAttentes(ListeDemandes listeDemandes) {
	int idDemande;


	printf(BOLD_GREEN "ID Demande : " RESET);
	scanf("%d%*c", &idDemande);

	return supprimerDemande(listeDemandes, idDemande);
}

/* 
   	Fonction: traitementDemandesEnAttentes
   	Finalité: Traite toutes les demande de la liste et retourne la liste des demandes qui n'ont pas pu être traitées
    Paramètre entrant/sortant : 
		- etudiants			tableau d'étudiants
		

		- listeLogements		liste chainée des logements
		- listeDemandes			liste chainée des demandes
	Paramètre:
		- nbEtudiants			nombre d'étudiants dans le tableau
	Variables: 
		- tmp					copie de la liste des demandes	
		- traite				si la demande a été traité passe a 1 et permet donc de supprimer cette demande
    Valeur retournée : 
        La nouvelle liste de demandes
*/
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