#include <stdio.h>

#include "src/etudiants/etudiants.h"
#include "src/logements/logements.h"
#include "src/demandes/demandes.h"

#include "src/enum/enum.h"
#include "src/menu/menu.h"
#include "src/color/color.h"

int main() {
	FILE* etudiantsDon;
	FILE* logementsDon;
	FILE* demandesDon;

	Etudiant etudiants[300];
	int nbEtudiants;

	ListeLogements logements;
	ListeDemandes demandes;

	Demande demande;
	int valMenu;
	char choix;

	//					CHARGEMENT
	etudiantsDon = fopen("fichiers/etudiants.don", "rb");
	logementsDon = fopen("fichiers/logements.don", "r");
	demandesDon = fopen("fichiers/demandes.don", "r");
	if(etudiantsDon == NULL || logementsDon == NULL || demandesDon == NULL) {
		printf("Impossible d'ouvrir les fichiers");
		return 0;
	}
	
	logements = chargementLogements(logementsDon);
	demandes = chargementDemandes(demandesDon);

	fread(&nbEtudiants, sizeof(int), 1, etudiantsDon);
	fread(etudiants, sizeof(Etudiant), nbEtudiants, etudiantsDon); 

	fclose(etudiantsDon);
	fclose(logementsDon);
	fclose(demandesDon);


	

	afficherMenuPrincipal();

	printf(BOLD_GREEN "Choix: " BOLD_CYAN);
	scanf("%d%*c", &valMenu);

	//while (valMenu != 9) {2
		switch (valMenu) {
			case 1:
				afficherListeLogementsDispo(logements);
				break;
			case 2:
				afficherListeLogementsOccupe(logements);
				break;
			case 3:
				afficherDemandesEnAttentes(demandes); 
				break;
			case 5 :
				choix = 'o';
				while (choix == 'o') {
					insererEtudiant(etudiants, &nbEtudiants);
					demandes = ajouterDemandeEnAttentes(demandes);

					printf(BOLD_YELLOW "Voulez vous entrez une nouvelle demande (o/n) : ");
					scanf("%c%*c", &choix);	
				}
				break;
			case 6:
					demandes = supprimerDemandeEnAttentes(demandes); 
					break;
			case 7:
					departEtudiant(logements, etudiants,  &nbEtudiants); 
				break;	
			default:
				break;
		}

	//					SAUVEGARDE			
	etudiantsDon = fopen("fichiers/etudiants.don", "wb");
	logementsDon = fopen("fichiers/logements.don", "w");
	demandesDon = fopen("fichiers/demandes.don", "w");
	if(etudiantsDon == NULL || logementsDon == NULL || demandesDon == NULL) {
		printf("Impossible d'ouvrir les fichiers");
		return 0;
	}

	sauvegardeDemandes(demandes, demandesDon);
	sauvegardeLogements(logements, logementsDon);

	fwrite(&nbEtudiants, sizeof(int), 1, etudiantsDon);
	fwrite(etudiants, sizeof(Etudiant), nbEtudiants, etudiantsDon);

	fclose(etudiantsDon);
	fclose(logementsDon);
	fclose(demandesDon);
}