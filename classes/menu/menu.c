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
	printf(BOLD_YELLOW "9» " BOLD_WHITE "Quitter le programme\n");
}

void choixMenuPrincipal(ListeEtudiants listeEtudiants, ListeLogements listeLogements, ListeDemandes listeDemandes) {
	int valMenu;

	afficherMenuPrincipal();

	printf(BOLD_GREEN "Choix: " BOLD_CYAN);
	scanf("%d%*c", &valMenu);

	switch (valMenu) {
		case 1:
			afficherListeLogementsDispo(listeLogements);
			break;
		default:
			choixMenuPrincipal(listeEtudiants, listeLogements, listeDemandes);
			break;
	}
}

void afficherListeLogementsDispo(ListeLogements listeLogements) {
	ListeLogements logeTmp = listeLogements;

	while(logeTmp != NULL) {
		if(logeTmp->logement.disponible) {
			afficherLogement(logeTmp->logement);
		}
		printf("\n");
		logeTmp = logeTmp->suivant;
	}
}