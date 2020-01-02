#include <stdio.h>

#include "etudiants.h"
#include "logements.h"

int main() {
	FILE* fe;
	Etudiant etud;
	Logement loge;
	//Demande dema;

	fe = fopen("etudiants.don", "r");
	if(fe == NULL) {
		printf("Impossible d'ouvrir le fichier");
		return 1;
  	}

	etud = lireEtudiant(fe);

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

	loge = lireLogement(fe);

	printf("Logement N°%d\n", loge.idLogement);
	printf("\n");
	printf("%s\n", loge.nomCite);
	printf("\n");
	printf("Type: %s\n", getTypeLogement(loge.typeLogement));

	if(loge.disponible) printf("Est disponible\n");
	else printf("Est loué par l'étudiant N°%d\n", loge.idEtudiant);

	if(loge.adapteHandicap) printf("Est adapté pour les handicapés\n");
	else printf("N'est pas adapté pour les handicapés\n");

	/*dema = lireDemande(fe);

	printf("Demande N°%d\n", dema.idDemande);
	printf("Etudiant N°%d\n", dema.idEtudiant);

	printf("Echelon de bourse: %s\n", getEchelon(dema.echelon));
	printf("Nom cité: %s\n", dema.nomCite);
*/

	fclose(fe);
}
