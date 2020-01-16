#ifndef MENU_H
#define MENU_H

#include "../logements/logements.h"
#include "../demandes/demandes.h"

/* Prototypes */
void afficherMenuPrincipal();
void choixMenuPrincipal(Etudiant etudiants[], int* nbEtudiants , ListeLogements listeLogements, ListeDemandes listeDemandes);
void afficherListeLogementsDispo(ListeLogements listeLogements);
void afficherListeLogementsOccupe(ListeLogements listeLogements);
void afficherDemandesEnAttentes (ListeDemandes listeDemandes);
void departEtudiant(ListeLogements logements, Etudiant etudiants[], int* nbEtudiants);
void ajouterDemandeEnAttentes(ListeDemandes listeDemandes);

#endif