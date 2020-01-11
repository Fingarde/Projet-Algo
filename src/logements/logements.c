#include "logements.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../enum/enum.h"
#include "../color/color.h"

Logement lireLogement(FILE* flot) {
    Logement loge;
    char nomCite[65];
    int tailleNomCite;

    loge.idEtudiant = -1;

    // ID Logement
    fscanf(flot, "%d%*c", &loge.idLogement);

    // Nom cité
    fgets(nomCite, 65, flot);
    tailleNomCite = strlen(nomCite);
    if(nomCite[tailleNomCite - 1] == '\n') {
        nomCite[tailleNomCite - 1] = '\0';
        tailleNomCite--;
    }

    loge.nomCite = (char*) malloc(sizeof(char) * tailleNomCite + 1);
    if (loge.nomCite == NULL) {
        printf("Problème d'allocation mémoire\n");
        exit(1);
    }
    strcpy(loge.nomCite, nomCite);

    // Type logement
    fscanf(flot, "%d%*c", &loge.typeLogement);

    // Disponibilité logement
    fscanf(flot, "%d%*c", &loge.disponible);
 
    // Adapté pour les personnes handicapés
    fscanf(flot, "%d%*c", &loge.adapteHandicap);

    if (!loge.disponible) {
        // ID Étudiant
        fscanf(flot, "%d%*c", &loge.idEtudiant);
    }

    return loge;
}

ListeLogements ajouterLogementListe(ListeLogements listeLogements, Logement logement) {
	MaillonLogement* tmp;

    int tailleCite;

	tmp = (MaillonLogement*) malloc(sizeof(MaillonLogement));
    if(tmp == NULL) {
        printf("Problème mémoire");
        exit(1);
    }

    tmp->logement.idLogement = logement.idLogement;

    tailleCite = strlen(logement.nomCite);
    tmp->logement.nomCite = (char*) malloc(sizeof(char) * tailleCite + 1);
    strcpy(tmp->logement.nomCite, logement.nomCite);

    tmp->logement.typeLogement = logement.typeLogement;
    tmp->logement.disponible = logement.disponible;
    tmp->logement.adapteHandicap = logement.adapteHandicap;
    tmp->logement.idEtudiant = logement.idEtudiant;

    tmp->suivant = listeLogements;
	
	return tmp;
}

ListeLogements chargementLogements(FILE* fe) {
	ListeLogements logements = NULL;
	Logement loge;
	
	loge = lireLogement(fe);
	logements = ajouterLogementListe(logements, loge);

	while(feof(fe) == 0) {
		loge = lireLogement(fe);
		logements = ajouterLogementListe(logements, loge);
	}

	return logements;
}

void afficherLogement(Logement loge) {
    printf(UNDERLINE_YELLOW BOLD_YELLOW "Logement N°%d\n" RESET, loge.idLogement);
   
    printf(BOLD_WHITE "Ville: " BOLD_BLUE "%s\n" RESET, loge.nomCite);

    printf(BOLD_WHITE "Type: " BOLD_CYAN "%s\n" RESET, getTypeLogement(loge.typeLogement));

    printf(BOLD_WHITE "Disponible: %s%s\n", loge.disponible ? GREEN : RED, getBoolean(loge.disponible));

    printf(BOLD_WHITE "Adapté handicapé: %s%s\n", loge.adapteHandicap ? GREEN : RED, getBoolean(loge.adapteHandicap));

    if(!loge.disponible) printf(BOLD_WHITE  "Occupé par %d\n", loge.idEtudiant);
}

// Ajouter titer 
// Ajouter en tete

ListeLogements trierParNomCite(ListeLogements listeLogements) {
   // COMME EN ALGO
}