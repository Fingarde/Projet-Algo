#include "enum.h"

#include <stdbool.h>

char civiliteValues[2][4] = {"Mr", "Mme"}; // Chaine de caractères correspondant aux valeurs de l'enum

/* 
   	Fonction: getCivilite
    Paramètre:
        - civilite          la civilite a afficher
   	Finalité: Retourne la chaine de caractère correspondant au paramètre
*/
char* getCivilite(Civilite civilite) {
    return civiliteValues[civilite];
}

char echelonValues[9][5] = {"0bis", "01", "02", "03", "04", "05", "06", "07", "Aucun"}; // Chaine de caractères correspondant aux valeurs de l'enum

/* 
   	Fonction: getEchelon
    Paramètre:
        - echelon          l'echelon a afficher
   	Finalité: Retourne la chaine de caractère correspondant au paramètre
*/
char* getEchelon(Echelon echelon) {
    return echelonValues[echelon];
}

char boolValues[2][4] = {"✘", "✔"}; // Chaine de caractères correspondant aux valeurs de l'enum

/* 
   	Fonction: getBoolean
    Paramètre:
        - boolean          le boolean a afficher
   	Finalité: Retourne la chaine de caractère correspondant au paramètre
*/
char* getBoolean(bool boolean) {
    return boolValues[boolean];
}

char typeLogementValues[4][8] = {"Chambre", "Studio", "T1", "T2"}; // Chaine de caractères correspondant aux valeurs de l'enum

/* 
   	Fonction: getTypeLogement
    Paramètre:
        - typeLogement         le type logement a afficher
   	Finalité: Retourne la chaine de caractère correspondant au paramètre
*/
char* getTypeLogement(TypeLogement typeLogement) {
    return typeLogementValues[typeLogement];
}
