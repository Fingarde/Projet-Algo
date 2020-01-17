# projet Algo - 1ère année

##### Timothé BERTRAND 
##### Maxime DESGRANGES
##### Yohann BREUIL

> Projet CROUS

> #### Pour lancer compiler le programme
 zsh -c 'gcc **/*.c -o projet'


> Fichiers

Le fichier texte logements est composé :
	> - ID logement (0, 1, 2, 3, etc)
    > - Nom de la cité 
    > -Type de logement (0 : Chambre – 1 : Studio – 2 : T1 – 3  : T2)
    > -Disponible (0 : Non – 1 : Oui)
    > -Adapté aux handicapés (0 : Non – 1 : Oui)
    > -Si non disponible : ID Etudiant (0, 1, 2, 3, etc)

Le fichier texte demandes est composé :
	ID Demande (0, 1, 2, 3, etc)
	ID Etudiant (0, 1, 2, 3, etc)
	Echelon de bourse de l'étudiant (0 : 0bis – 1 : 01 – 2 : 02 – 3 : 03 – 4 : 04 – 5 : 05 – 6 : 06 – 7 : 07 – 8 : AUCUN)
	Nom de la cité 
	Type de logement (0 : Chambre – 1 : Studio – 2 : T1 – 3  : T2)

Chargement en mémoire

Etudiant : tableaux

Logement : liste chainée de logement
typedef struct MailleLoge {
	Logement logement;
	struct MailleLoge* suivant;
} MaillonLogement;
typedef MaillonLogement* ListeLogements;

Demande : liste  chainée de demande

typedef struct MailleDema {
    Demande demande;
    struct MailleDema* suivant;
} MaillonDemande;
typedef MaillonDemande* ListeDemandes;





Structures

typedef struct {
    int idLogement; 	
    char* nomCite;	
    TypeLogement typeLogement;	 (0 : Chambre – 1 : Studio – 2 : T1 – 3  : T2)
    bool disponible;			 (0 : Non – 1 : Oui)
    bool adapteHandicap;		 (0 : Non – 1 : Oui)
    int idEtudiant;
} Logement;

typedef struct {
    int idEtudiant;
    Civilite civilite;
    char nom[65];
    char prenom[65];
    bool boursie;			(0 : Non – 1 : Oui)
    Echelon echelon;			(0 : 0bis – 1 : 01 – 2 : 02 – 3 : 03 – 4 : 04 – 5 : 05 – 6 : 06 – 7 : 07 – 8 : AUCUN)
    bool handicape;			(0 : Non – 1 : Oui)
} Etudiant;

typedef struct {
	int idDemande;
	int idEtudiant;
	Echelon echelon;		(0 : 0bis – 1 : 01 – 2 : 02 – 3 : 03 – 4 : 04 – 5 : 05 – 6 : 06 – 7 : 07 – 8 : AUCUN)
	char* nomCite;
	TypeLogement typeLogement;	(0 : Chambre – 1 : Studio – 2 : T1 – 3  : T2)
} Demande;






















Fonctionnalités

1 – Affichage des logements disponibles (triée par cité) :

	Affiche les logements disponibles (n'ayant pas d'étudiant habitant)

2 – Affichage des logements occupés (avec ID de l'étudiant occupant) : 

	Affiche les logements occupés (ayant un étudiant habitant)

3 – Affichage des demandes en attentes

	Affiche les demandes en attentes 

4 – Traitement des demandes en attentes (fonction non opérationnel)

	Traite les demandes en attentes si un étudiant demande un type de logement dans une cité souhaité et que ce logment est diponible alors la demande est validée
5 – Saisissement d'une nouvelle demande 

	Saisie d'un étudiant (si nouveau) et saisie d'une demande à ajouter

6 – Annulation d'une demande 

	Annule une demande et la retire

7 – Libération d'un logement 

	Changement de la disponibilité pour ce logement ce qui peut aboutir à une réponse positive d'une demande et supprime un étudiant




  