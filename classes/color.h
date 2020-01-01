/* Structure */

/*
    Color Codes

    \033[0;31m  Red
    \033[1;31m  Bold Red
    \033[0;32m  Green
    \033[1;32m  Bold Green
    \033[0;33m  Yellow
    \033[01;33m Bold Yellow
    \033[0;34m  Blue
    \033[1;34m  Bold Blue
    \033[0;35m  Magenta
    \033[1;35m  Bold Magenta
    \033[0;36m  Cyan
    \033[1;36m  Bold Cyan
    \033[0m     Reset
*/

// Couleur
typedef enum {
    RED, 
    BOLD_RED,
    GREEN,
    BOLD_GREEN,
    YELLOW,
    BOLD_YELLOW,
    BLUE,
    BOLD_BLUE,
    MAGENTA,
    BOLD_MAGENTA,
    CYAN,
    BOLD_CYAN,
    RESET
} Color;

/* Fonction */

void setColor(Color color);