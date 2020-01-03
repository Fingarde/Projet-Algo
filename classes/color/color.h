#ifndef COLOR_H
#define COLOR_H

//Regular text
#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

//Regular bold text
#define BOLD_BLACK "\e[1;30m"
#define BOLD_RED "\e[1;31m"
#define BOLD_GREEN "\e[1;32m"
#define BOLD_YELLOW "\e[1;33m"
#define BOLD_BLUE "\e[1;34m"
#define BOLD_MAGENTA "\e[1;35m"
#define BOLD_CYAN "\e[1;36m"
#define BOLD_WHITE "\e[1;37m"

//Regular underline text
#define UNDERLINE_BLACK "\e[4;30m"
#define UNDERLINE_RED "\e[4;31m"
#define UNDERLINE_GREEN "\e[4;32m"
#define UNDERLINE_YELLOW "\e[4;33m"
#define UNDERLINE_BLUE "\e[4;34m"
#define UNDERLINE_MAGENTA "\e[4;35m"
#define UNDERLINE_CYAN "\e[4;36m"
#define UNDERLINE_WHITE "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background 
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define reset "\e[0m"

#endif