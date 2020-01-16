#include "etudiants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../enum/enum.h"
#include "../color/color.h"

#include "../logements/logements.h"

Etudiant lireEtudiant(FILE* flot) {
    Etudiant etud;

    char nom[65];
    int tailleNom;
    char prenom[65];
    int taillePrenom;

    etud.echelon = AUCUN;

    fscanf(flot, "%d%*c", &etud.idEtudiant); // ID Etudiant

    fscanf(flot, "%d%*c", &etud.civilite); // Civilite

    fgets(etud.nom, 65, flot); // Nom
    tailleNom = strlen(etud.nom);
    if(etud.nom[tailleNom - 1] == '\n') {
        etud.nom[tailleNom - 1] = '\0';
        tailleNom--;
    }

    fgets(etud.prenom, 65, flot); // Prenom
    taillePrenom = strlen(etud.prenom);
    if(etud.prenom[taillePrenom - 1] == '\n') {
        etud.prenom[taillePrenom - 1] = '\0';
        taillePrenom--;
    }

    fscanf(flot, "%d%*c", &etud.boursie); // Boursier
    if(etud.boursie) {
        fscanf(flot, "%d%*c", &etud.echelon); // Echelon
    }

    fscanf(flot, "%d%*c", &etud.handicape); // Handicape
    
    return etud;
}

void afficherEtudiant(Etudiant etud) {
    printf(UNDERLINE_YELLOW BOLD_YELLOW "Etudiant N°%d\n" RESET, etud.idEtudiant);

	printf(BOLD_BLUE "%s %s\n" RESET, etud.nom, etud.prenom);
	printf(BOLD_WHITE "Civilité: %s%s\n" RESET, etud.civilite == 0 ? BOLD_CYAN : BOLD_MAGENTA, getCivilite(etud.civilite));

    printf(BOLD_WHITE "Handicapé: %s%s\n", etud.handicape ? GREEN : RED, getBoolean(etud.handicape));
 
    printf(BOLD_WHITE "Boursié: %s%s\n", etud.boursie ? GREEN : RED, getBoolean(etud.boursie));
	if(etud.boursie) printf(BOLD_WHITE "Echelon de bourse: " BOLD_YELLOW "%s\n" RESET, getEchelon(etud.echelon));
}

MaillonLogement* getLogement(ListeLogements logements, Etudiant etud) {
    if(logements == NULL) return NULL;

    if(logements->logement.idEtudiant == etud.idEtudiant) return logements;
    return getLogement(logements->suivant, etud);
}

int rechercheEtudiant (Etudiant etudiants[], int idEtudiant, int nbEtudiants) { // TODO TOUJOURS BOUCLE INFINIE WTF
    int deb = 0, m, fin = nbEtudiants - 1;

    while (deb <= fin) {
        m = (fin - deb) / 2;

        if (idEtudiant == etudiants[m].idEtudiant) {
            return 0;
        }
        else if (idEtudiant < etudiants[m].idEtudiant) {
            fin = m - 1;
        }
        else if (idEtudiant > etudiants[m].idEtudiant) {
            deb = m + 1;
        }
    }

    return -1;
}

void insererEtudiant(Etudiant etudiants[], int* nbEtudiants) {
    Etudiant etudiant;
    int position, tailleNom, taillePrenom;

    printf(BOLD_GREEN "ID de l'étudiant: " BOLD_CYAN);
    scanf("%d", &(etudiant.idEtudiant)); 
    if (rechercheEtudiant(etudiants, etudiant.idEtudiant, *nbEtudiants) == 0) {
        printf(BOLD_RED "L'etudiant existe déja\n");
        return;
    }

    printf(BOLD_GREEN "Civilite: " BOLD_CYAN);
    scanf("%d", &(etudiant.civilite));

    printf(BOLD_GREEN "Nom de l'etudiant: " BOLD_CYAN);
    scanf("%s", etudiant.nom);
    tailleNom = strlen(etudiant.nom);
    if(etudiant.nom[tailleNom - 1] == '\n') {
        etudiant.nom[tailleNom - 1] = '\0';
        tailleNom--;
    }

    printf(BOLD_GREEN "Prenom de l'etudiant: " BOLD_CYAN);
    scanf("%s", etudiant.prenom);
    taillePrenom = strlen(etudiant.prenom);
    if(etudiant.prenom[taillePrenom - 1] == '\n') {
        etudiant.prenom[taillePrenom - 1] = '\0';
        taillePrenom--;
    }

    printf(BOLD_GREEN "Boursier: " BOLD_CYAN);
    scanf("%d", &(etudiant.boursie));

    if(etudiant.boursie) {
        printf(BOLD_GREEN "Echelon: " BOLD_CYAN);
        scanf("%d", &(etudiant.echelon));
    }

    printf(BOLD_GREEN "Handicape: " BOLD_CYAN);
    scanf("%d", &(etudiant.handicape));
    
    
    etudiants[*nbEtudiants] = etudiant;
    (*nbEtudiants)++;
}

void supprimerEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants, int positionEtudiant) {
    MaillonLogement* logement;
    int index;

    logement = getLogement(logements, etudiants[positionEtudiant]);
    if(logement != NULL) {
        logement->logement.disponible = 1;
    }

    for(index = positionEtudiant; index < (*nbEtudiants) - 1; index++) {
        etudiants[index] = etudiants[index + 1];
    }

    (*nbEtudiants)--;
}

