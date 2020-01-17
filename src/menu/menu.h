#ifndef MENU_H
#define MENU_H

#include "../logements/logements.h"
#include "../demandes/demandes.h"

/* Prototypes */
void afficherMenuPrincipal();
void afficherListeLogementsDispo(ListeLogements listeLogements);
void afficherListeLogementsOccupe(ListeLogements listeLogements);
void afficherDemandesEnAttentes (ListeDemandes listeDemandes);
void departEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants);
ListeDemandes ajouterDemandeEnAttentes(ListeDemandes listeDemandes);
ListeDemandes supprimerDemandeEnAttentes(ListeDemandes listeDemandes);
#endif