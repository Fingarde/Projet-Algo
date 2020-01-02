#include <stdio.h>

#include "color.h"

void setColor(Color color) {
    switch(color) {
        case RED:
            printf("\033[0;31m");
            break;
        case BOLD_RED:
            printf("\033[1;31m");
            break;
        case GREEN:
            printf("\033[0;32m");
            break;
        case BOLD_GREEN:
            printf("\033[1;32m");
            break;
        case YELLOW:
            printf("\033[0;33m");
            break;
        case BOLD_YELLOW:
            printf("\033[1;33m");
            break;
        case BLUE:
            printf("\033[0;34m");
            break;
        case BOLD_BLUE:
            printf("\033[1;34m");
            break;
        case MAGENTA:
            printf("\033[0;35m");
            break;
        case BOLD_MAGENTA:
            printf("\033[1;35m");
            break;
        case CYAN:
            printf("\033[0;36m");
            break;
        case BOLD_CYAN:
            printf("\033[1;3m");
            break;
        default:
            printf("\033[0m");
            break;
    }
}