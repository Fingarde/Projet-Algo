#include <stdio.h>

#include "classes/etudiants/etudiants.h"
#include "classes/logements/logements.h"
#include "classes/demandes/demandes.h"

#include "classes/enum/enum.h"
#include "classes/menu/menu.h"

int main() {
	//choixMenuPrincipal();

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








/*
	etud = lireEtudiant(etudiantsDon);

	printf("Etudiant N°%d\n", etud.idEtudiant);
	printf("\n");
	printf("%s %s\n", etud.nom, etud.prenom);
	printf("\n");
	printf("Civilité: %s\n", getCivilite(etud.civilite));

	if(etud.handicape) printf("Est handicapé\n");
	else printf("N'est pas handicapé\n");
	
	if(etud.boursie) printf("Echelon de bourse: %s\n", getEchelon(etud.echelon));
	else printf("N'est pas boursier\n");
	
	printf("\n-------\n\n");

	loge = lireLogement(logementsDon);

	printf("Logement N°%d\n", loge.idLogement);
	printf("\n");
	printf("%s\n", loge.nomCite);
	printf("\n");
	printf("Type: %s\n", getTypeLogement(loge.typeLogement));

	if(loge.disponible) printf("Est disponible\n");
	else printf("Est loué par l'étudiant N°%d\n", loge.idEtudiant);

	if(loge.adapteHandicap) printf("Est adapté pour les handicapés\n");
	else printf("N'est pas adapté pour les handicapés\n");

	printf("\n-------\n\n");

	dema = lireDemande(demandesDon);

	printf("Demande N°%d\n", dema.idDemande);
	printf("Etudiant N°%d\n", dema.idEtudiant);

	printf("Echelon de bourse: %s\n", getEchelon(dema.echelon));
	printf("Nom cité: %s\n", dema.nomCite);
*/
	fclose(etudiantsDon);
	fclose(logementsDon);
	fclose(demandesDon);
}