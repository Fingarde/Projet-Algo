#include <stdio.h>
#include <stdbool.h>

typedef enum {
    CHAMBRE, 
    STUDIO,
    T1,
    T2
} TypeLogement;

typedef struct {
    int idLogement;
    char* nomCite;
    TypeLogement typeLogement;
    bool disponible;
    bool adapteHandicap;
    int idEtudiant;
} Logement;

char* getTypeLogement(TypeLogement typeLogement);
Logement lireLogement(FILE* flot);