#ifndef DEMANDES_H
#define DEMANDES_H

#include <stdio.h>
#include <stdbool.h>

#include "../etudiants/etudiants.h"
#include "../logements/logements.h"

/* Structure */

// Structure d'une demande
typedef struct {
	int idDemande;
	int idEtudiant;
	Echelon echelon;
	char* nomCite;
	TypeLogement typeLogement;
} Demande;

// Maillon d'une demande
typedef struct MailleDema {
    Demande demande;
    struct MailleDema* suivant;
} MaillonDemande;

// Liste de demandes
typedef MaillonDemande* ListeDemandes;

/* Prototypes */

Demande lireDemande (FILE* flot);
ListeDemandes ajouterDemandeListe(ListeDemandes listeDemandes, Demande demande);
ListeDemandes chargementDemandes(FILE* fe);
void afficherDemande(Demande dema);
void sauvegardeDemandes(ListeDemandes demandes, FILE* fe);
MaillonDemande* rechercheListe (ListeDemandes listeDemandes, int idDemande);
Demande ajouterDemande (ListeDemandes listeDemandes);
ListeDemandes insererEnTeteDemande(ListeDemandes liste, Demande dema);
ListeDemandes insererTrieDemandes(ListeDemandes liste, Demande dema);
ListeDemandes supprimerDemande(ListeDemandes listeDemandes, int idDemande);
ListeDemandes rechercheDemande(ListeDemandes listeDemandes, int idDemande);
int traiterDemande(Demande demande, ListeLogements listeLogements, Etudiant etudiants[], int nbEtudiants);

#endif