#include "logements.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../enum/enum.h"
#include "../color/color.h"

/*  Fonction : lireLogement
    Finalité : lire un logement sur un flot
    Paramètres : flot - flot d'entrée des données 
    Valeur retournée : loge - structure d'un logement
*/

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

/*  Fonction : initListeLogements
    Finalité : initialise la liste
    Valeur retournée : NULL - valeur du pointeur de liste
*/

ListeLogements initListeLogements() {
    return NULL;
}

/*  Fonction : ajouterLogementListe
    Finalité : ajouter un logement dans la liste
    Paramètres : listeLogements - liste contenant les logements
				 logement - structure de logement 
    Valeur retournée : tmp - adresse vers le maillon de la liste
*/

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

/*  Fonction : chargementLogements
    Finalité : charger les logements dans une liste 
    Paramètres : fe - flot d'entrée des données 
    Valeur retournée : loge - liste de demandes
*/

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

/*  Fonction : insererEnTeteLogements
    Finalité : inserer un logement en tete de liste
    Paramètres : liste - liste de logements
				 loge - structure de logement
    Valeur retournée : tmp - adresse vers le maillon de la liste
*/
ListeLogements insererEnTeteLogements(ListeLogements liste, Logement loge) {
    MaillonLogement* tmp;

    tmp = (MaillonLogement*) malloc(sizeof(MaillonLogement));
    if (tmp == NULL) {
        printf("Problème allocation\n");
        exit(1);
    }

    tmp->logement = loge;

    tmp->suivant = liste;
    liste = tmp;

    return liste;
}

/*  Fonction : insererTrieLogements
    Finalité : inserer un logement au bon endroit dans la liste
    Paramètres : liste - liste de logements
				 loge - structure de logement
    Valeur retournée : liste - liste de logements
*/

ListeLogements insererTrieLogements(ListeLogements liste, Logement loge) {
   if(liste == NULL) {
       liste = insererEnTeteLogements(liste, loge);
   }
   else if(strcmp(liste->logement.nomCite, loge.nomCite) > 0) {
       liste = insererEnTeteLogements(liste, loge);
   }
   else {
       liste->suivant = insererTrieLogements(liste->suivant, loge);
   }

   return liste;
}

/* 
   	Fonction: trierLogements
   	Finalité: Trier les logements par nom de cité et retourne la nouvelle liste de logements
    Variables : 
        - res 		        liste chainée des logements
		- tmp		        liste chainée des logements
	Paramètre entrant/sortant:
        - liste            liste chainée des logements
    Valeur retournée : 
        La nouvelle liste trié de logements
*/
ListeLogements trierLogements (ListeLogements liste) {
    ListeLogements res, tmp = liste;
    

    res = initListeLogements();

    while (tmp != NULL){
        res = insererTrieLogements(res, tmp->logement);
        tmp = tmp->suivant;
    }

    return res;
}

/* 
   	Fonction: afficherLogement
   	Finalité: Affiche un logement
	Paramètre:
        - logement            le logement a afficher
*/
void afficherLogement(Logement loge) {
    printf(UNDERLINE_YELLOW BOLD_YELLOW "Logement N°%d\n" RESET, loge.idLogement);
   
    printf(BOLD_WHITE "Cité: " BOLD_BLUE "%s\n" RESET, loge.nomCite);

    printf(BOLD_WHITE "Type: " BOLD_CYAN "%s\n" RESET, getTypeLogement(loge.typeLogement));

    printf(BOLD_WHITE "Disponible: %s%s\n", loge.disponible ? GREEN : RED, getBoolean(loge.disponible));

    printf(BOLD_WHITE "Adapté handicapé: %s%s\n", loge.adapteHandicap ? GREEN : RED, getBoolean(loge.adapteHandicap));

    if(!loge.disponible) printf(BOLD_WHITE  "Occupé par l'étudiant N°%d\n", loge.idEtudiant);
}

/* 
   	Fonction: sauvegardeLogements
   	Finalité: Sauvegarde la liste des logements dans le fichier
	Paramètre entant/sortant:
        - fe                    le flot de donnée de sortie
        - logements             liste chainée des logements
*/
void sauvegardeLogements(ListeLogements logements, FILE* fe) {
	if(logements == NULL) return;

    sauvegardeLogements(logements->suivant, fe);

    if(logements->suivant != NULL) fprintf(fe, "\n");

    fprintf(fe, "%d\n", logements->logement.idLogement);
    fprintf(fe, "%s\n", logements->logement.nomCite);
    fprintf(fe, "%d\n", logements->logement.typeLogement);
    fprintf(fe, "%d\n", logements->logement.disponible);
    fprintf(fe, "%d", logements->logement.adapteHandicap);

    if(!logements->logement.disponible)
        fprintf(fe, "\n%d", logements->logement.idEtudiant);
}