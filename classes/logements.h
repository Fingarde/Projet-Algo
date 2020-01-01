#include <stdio.h>
#include <stdbool.h>

/* Structure et Énumération */

// Type Logement
typedef enum {
    CHAMBRE, 
    STUDIO,
    T1,
    T2
} TypeLogement;

// Logement
typedef struct {
    int idLogement;
    char* nomCite;
    TypeLogement typeLogement;
    bool disponible;
    bool adapteHandicap;
    int idEtudiant;
} Logement;

/* Prototypes */

char* getTypeLogement(TypeLogement typeLogement);
Logement lireLogement(FILE* flot);