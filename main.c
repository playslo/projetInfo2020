// fichier main du projet Stock livre
// Nathanael SIMON

#include "stock_livre.h"
#include "isbn.c"
#include "affichage.c"
#include "gestion_stock.c"



int main(void)
{
	int choix;
	int statut = 1;
	int nbr_livre = 0;
	int exemplaires;

	Livre livre[NBRMAX];
	while (statut == 1){
		choix = menu_choix(); 
		printf("\nNBR LIVRE : %d\n", nbr_livre); 
		switch(choix){
			case 0: 
				printf("=== AU REVOIR ===");
				return (0);
				break;
			case 1: 
				printf("=== AJOUT D'UN NOUVEL OUVRAGE ===\n\n");
				ajout_livre(livre, nbr_livre);
				nbr_livre++;
				break;
			case 2:
				printf("=== SUPPRESSION D'UN OUVRAGE===\n");
				if(suppLivre(livre, nbr_livre))
					nbr_livre--;
				break;
			case 3:
				printf("=== LISTE DE TOUS LES OUVRAGES ===\n\n");
				listlivres(livre, nbr_livre, 200000000);
				break;
			case 4:
				printf("=== LISTE ===\n");
				printf("les ouvrages en dessous de combien d'exemplaires voulez vous lister ? : ");
				scanf("%d", &exemplaires);
				printf("\n");
				listlivres(livre, nbr_livre, exemplaires);
				break;
			case 5:
				printf("=== RECHERCHE ===\n");
				recherchelivre(livre, nbr_livre);
				break;
			default: 
				printf("pas encore programme tu connais");
				break;
		}
	}
	return (0);
}