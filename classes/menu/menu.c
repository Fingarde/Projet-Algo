#include "menu.h"

#include <stdio.h>

void afficherMenuPrincipal() {
	printf("-- Bienvenue sur le programme de demandes de logement du CROUS --\n");
	printf("1 - Afficher la liste des logements disponibles\n");
	printf("2 - Afficher la liste des logements occupés\n");
	printf("3 - Afficher la liste des demandes de logements en attente\n");
	printf("4 - Saisir une nouvelle demande de logements\n");
	printf("5 - Annuler une demande de logements\n");
	printf("6 - Libérer un logement\n");
	printf("7 - Quitter le programme\n");
}