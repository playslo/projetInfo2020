// Ficher header projet Stock livre
// Nathanael SIMON & 
#include <stdlib.h>
#include <stdio.h>

int nbr_livre = 0;
typedef struct Livre Livre;
typedef struct Auteur Auteur;


int verif_ISBN(char*);
int ajout_livre(Livre*);
int menu_choix(void);
int checkseg3N2(char*, int*);
int checkseg3N10(char*, int*);
char* ISBN(char*);
void init_livre(Livre*);


#include "affichage.c"
#include "gestion_stock.c"
#include "isbn.c"
#define NBRMAX 200

struct Auteur
{
	char nom[50];
	char prenom[30];
};

struct Livre 
{
	char titre[200];
	char editeur[50];
	int exStock;
	int nbrAuteurs;
	Auteur auteurs[10];
	int freq;
	char ISBN[13];
};

//Questions: Verification ISBN (fr et 3eme SEG) lutilisateur peut il rentrer un ISBN invalide apres 978 2 et peut il mettre 97810 ou 9792 ?
//Cas pour le 35000 inexistant mais present sur le sujet
//cas 978 2 354000 pas de 5eme membre ?
//cas 979 10 976000 pas de 5eme membre ?