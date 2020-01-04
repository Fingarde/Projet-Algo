#include <stdio.h>

#include "classes/etudiants/etudiants.h"
#include "classes/logements/logements.h"
#include "classes/demandes/demandes.h"

#include "classes/enum/enum.h"
#include "classes/menu/menu.h"

int main() {
	FILE* etudiantsDon;
	FILE* logementsDon;
	FILE* demandesDon;

	ListeEtudiants etudiants;
	ListeLogements logements;
	ListeDemandes demandes;

	etudiantsDon = fopen("fichiers/etudiants.don", "r");
	logementsDon = fopen("fichiers/logements.don", "r");
	demandesDon = fopen("fichiers/demandes.don", "r");
	if(etudiantsDon == NULL || logementsDon == NULL || demandesDon == NULL) {
		printf("Impossible d'ouvrir les fichiers");
		return 0;
  	}

	etudiants = chargementEtudiants(etudiantsDon);
	logements = chargementLogements(logementsDon);
	demandes = chargementDemandes(demandesDon);
	
	choixMenuPrincipal(etudiants, logements, demandes);



/*

	etudiants = chargementEtudiants(etudiantsDon);

	ListeEtudiants etudTmp = etudiants;
	while(etudTmp != NULL) {
		afficherEtudiant(etudTmp->etudiant);
		printf("\n");
		etudTmp = etudTmp->suivant;
	}

	printf("\n\n");


	logements = chargementLogements(logementsDon);

	ListeLogements logeTmp = logements;
	while(logeTmp != NULL) {
		afficherLogement(logeTmp->logement);

		printf("\n");
		logeTmp = logeTmp->suivant;
	}

	printf("\n\n");


	demandes = chargementDemandes(demandesDon);

	ListeDemandes demaTmp = demandes;
	while(demaTmp != NULL) {
		afficherDemande(demaTmp->demande);

		printf("\n");
		demaTmp = demaTmp->suivant;
	}
*/
	fclose(etudiantsDon);
	fclose(logementsDon);
	fclose(demandesDon);
}