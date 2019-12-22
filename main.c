#include <stdio.h>

#include "classes/color.h"
#include "classes/etudiants.h"
#include "classes/logements.h"

int main() {
    setColor(RED);
    printf("%s\n", getCivilite(0));
    setColor(RESET);
}