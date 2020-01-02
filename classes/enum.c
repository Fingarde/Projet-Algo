#include "enum.h"

#include <stdbool.h>

char civiliteValues[2][4] = {"Mr", "Mme"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getCivilite(Civilite civilite) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return civiliteValues[civilite];
}

char echelonValues[9][5] = {"0bis", "01", "02", "03", "04", "05", "06", "07", "Aucun"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getEchelon(Echelon echelon) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return echelonValues[echelon];
}

char boolValues[2][4] = {"Non", "Oui"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getBoolean(bool boolean) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return boolValues[boolean];
}

char typeLogementValues[4][8] = {"Chambre", "Studio", "T1", "T2"}; // Chaine de caractères correspondant aux valeurs de l'enum
char* getTypeLogement(TypeLogement typeLogement) { // Retourne la chaine de caractères correspondant a la valeur de l'enum
    return typeLogementValues[typeLogement];
}