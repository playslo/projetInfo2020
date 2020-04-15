// Ficher header projet Stock livre
// Nathanael SIMON &

#ifndef DEF_stock_livre
#define DEF_stockl_livre
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Livre Livre;
typedef struct Auteur Auteur;


int verif_ISBN(char*);
int ajout_livre(Livre*, int);
int menu_choix(void);
int checkseg3N2(char*, int*);
int checkseg3N10(char*, int*);
char* ISBN(char*);
void init_livre(Livre);
int ft_strcmp(char*, char*);
int verif_livre(Livre*, char*, int ,int);
void ft_strcpy(char* src, char* dest);
void aff_livre(Livre, int);
void listlivres(Livre*, int, int);
int recherchelivre(Livre*, int);
int rechercheNom(Livre*, int);
int ft_strcmp2(char*, char*);
int suppLivre(Livre*, int, int*);
int suppLivreCommande(Livre*, int);
void affISBN(char*);
int freqLivre(Livre*, int);


#define NBRMAX 200
#define exemplaireMin 5

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

#endif
//Cas pour le 35000 inexistant mais present sur le sujet
//cas 978 2 354000 pas de 5eme membre ?
//cas 979 10 976000 pas de 5eme membre ?
//rajouter un fonction de tri des livres?
//rajouter dans les recherche de livres la non differenciation entre majuscule et minuscules pour la comparaison
//probleme avec option 3 et 4?
//Liste bugee affiche 1 en trop au debut de la liste. Testee avec 3 livres.