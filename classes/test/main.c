#include <stdio.h>

#include "etudiants.h"
#include "logements.h"

int main() {
	FILE* fe;
	Etudiant etud;
	Logement loge;

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
	
	printf("\n");

	loge = lireLogement(fe);
	printf("%s\n", loge.nomCite);
	
	fclose(fe);
}
