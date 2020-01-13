#include <stdio.h>

#include "src/etudiants/etudiants.h"
#include "src/logements/logements.h"
#include "src/demandes/demandes.h"

#include "src/enum/enum.h"
#include "src/menu/menu.h"

int main() {
	FILE* etudiantsDon;
	FILE* logementsDon;
	FILE* demandesDon;

	Etudiant etudiants[300];
	int nbEtudiants;

	ListeLogements logements;
	ListeDemandes demandes;

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

	insererEtudiant(etudiants, &nbEtudiants);

	//choixMenuPrincipal(etudiants, &nbEtudiants, logements, demandes);




	//					SAUVEGARDE			
	etudiantsDon = fopen("fichiers/etudiants.don", "wb");
	logementsDon = fopen("fichiers/logements.don", "w");
	demandesDon = fopen("fichiers/demandes.don", "w");
	if(etudiantsDon == NULL || logementsDon == NULL || demandesDon == NULL) {
		printf("Impossible d'ouvrir les fichiers");
		return 0;
	}

	sauvegardeDemandes(demandes, demandesDon);

	fclose(etudiantsDon);
	fclose(logementsDon);
	fclose(demandesDon);
}