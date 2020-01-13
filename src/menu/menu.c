#include "menu.h"

#include <stdio.h>

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
	printf(BOLD_YELLOW "4» " BOLD_WHITE "Saisir une nouvelle demande de logements\n");
	printf(BOLD_YELLOW "5» " BOLD_WHITE "Annuler une demande de logements\n");
	printf(BOLD_YELLOW "6» " BOLD_WHITE "Libérer un logement\n");
	printf("\n");
	printf(BOLD_YELLOW "7» " BOLD_WHITE "Supprimer un étudiant\n");
	printf("\n");
	printf(BOLD_YELLOW "9» " BOLD_WHITE "Quitter le programme\n");
}

void choixMenuPrincipal(Etudiant etudiants[], int* nbEtudiants , ListeLogements listeLogements, ListeDemandes listeDemandes) {
	int valMenu;
	char choix;

	afficherMenuPrincipal();

	printf(BOLD_GREEN "Choix: " BOLD_CYAN);
	scanf("%d%*c", &valMenu);

	//while (valMenu != 9) {2
		switch (valMenu) {
			case 1:
				afficherListeLogementsDispo(listeLogements);
				break;
			case 2:
				afficherListeLogementsOccupe(listeLogements);
				break;
			case 3:
				afficherDemandesEnAttentes(listeDemandes); 
				break;
			case 4 :
				printf("Voulez vous entrez un nouvel étudiant (o/n) : ");
				scanf("%c%*c", choix);				
				while (choix != 'o' || choix != 'n') {
					printf("Voulez vous entrez un nouvel étudiant (o/n) : ");
					scanf("%c%*c", choix);	
				}

				if (choix == 'o') {
					insererEtudiant(etudiants, nbEtudiants);
				}

				break;
			// case 5 :

			// 	break;
			// case 6 : 

			// 	break;
			case 7:
				departEtudiant(listeLogements, etudiants,  nbEtudiants); 
				break;	
			default:
				choixMenuPrincipal(etudiants, nbEtudiants, listeLogements, listeDemandes);
				break;
		}

	// afficherMenuPrincipal();

	// printf(BOLD_GREEN "Choix: " BOLD_CYAN);
	// scanf("%d%*c", &valMenu);
	//}
}

void afficherListeLogementsDispo(ListeLogements listeLogements) {
	ListeLogements logeTmp = listeLogements;
	while(logeTmp != NULL) {
		if(logeTmp->logement.disponible) { // == 0
			afficherLogement(logeTmp->logement); // Libre
		}
		printf("\n");
		logeTmp = logeTmp->suivant;
	}
}

void afficherListeLogementsOccupe(ListeLogements listeLogements) {
	ListeLogements logeTmp = listeLogements;

	while(logeTmp != NULL) {
		if(!logeTmp->logement.disponible) { // == 1
			afficherLogement(logeTmp->logement); // Occupé
		}
		printf("\n");
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


	//supprimerEtudiant(logements, etudiants, *nbEtudiants, idEtudiant);
}