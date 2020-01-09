#ifndef ENUM_H
#define ENUM_H

#include <stdbool.h>

// Civilité
typedef enum {
    MR,
    MME
} Civilite;

// Échelon
typedef enum {
    ZERO_BIS,
    UN,
    DEUX,
    TROIS,
    QUATRE,
    CINQ,
    SIX,
    SEPT,
    AUCUN
} Echelon;

// Type logement
typedef enum {
    CHAMBRE, 
    STUDIO,
    T1,
    T2
} TypeLogement;

/* Prototypes */

char* getCivilite(Civilite civilite);
char* getEchelon(Echelon echelon);
char* getBoolean(bool boolean);
char* getTypeLogement(TypeLogement typeLogement);

#endif