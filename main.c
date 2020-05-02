// fichier main du projet Stock livre
// Nathanael SIMON

#include "stock_livre.h"

int main(void)
{
	int choix;
	int statut = 1;
	int nbr_livre = 0;
	int nbr_commande = 0;
	int exemplaires;
	int j;
	int* p = &j;
	int testsupp;
	int nbrExCommande;

	Livre livre[NBRMAX];
	Livre commande[NBRMAX];
	while (statut == 1){
		choix = menu_choix(); 
		switch(choix){
			case 0: 
				printf("=== AU REVOIR ===");
				return (0);
				break;
			case 1: 
				system("clear");
				printf("=== AJOUT D'UN NOUVEL OUVRAGE ===\n\n");
				if(ajout_livre(livre, nbr_livre, 0))
					nbr_livre++;
				break;
			case 2:
				system("clear");
				printf("=== SUPPRESSION D'UN OUVRAGE===\n\n");
				testsupp = suppLivre(livre, nbr_livre, p);
				if(testsupp == 1)
					nbr_livre--;
				else if(testsupp == 2)
				{
					printf("Le livre etant frequement vendu et en dessous de 10 exemplaires, il est automatiquement ajoute sur la liste des commandes.\n");
					printf("Combien d'exemplaires voulez vous ajouter a la liste d'une commande ? :");
					scanf("%d", &nbrExCommande);
					livre[j].exCommande = nbrExCommande;
					commande[nbr_commande]=livre[j];
					nbr_commande++;
				}
				break;
			case 3:
				system("clear");
				printf("=== LISTE DE TOUS LES OUVRAGES ===\n\n");
				if(nbr_livre != 0)
					listlivres(livre, nbr_livre, 200000000, 0);
				else
					printf("Il n'y actuellement pas de livres en stock\n");
				break;
			case 4:
				system("clear");
				printf("=== LISTE ===\n");
				printf("les ouvrages en dessous de combien d'exemplaires voulez vous lister ? : ");
				scanf("%d", &exemplaires);
				printf("\n");
				listlivres(livre, nbr_livre, exemplaires, 0);
				break;
			case 5:
				system("clear");
				printf("=== RECHERCHE ===\n\n");
				recherchelivre(livre, nbr_livre);
				break;
			case 6:
				system("clear");
				printf("=== Changer la frequence de vente ===\n\n");
				freqLivre(livre, nbr_livre);
				break;
			case 7:
				system("clear");
				printf("=== Ajout d'un livre a la liste de commandes ===\n\n");
				if(ajout_livre(commande, nbr_commande, 1))
					nbr_commande++;
				break;
			case 8:
				system("clear");
				printf("=== Suppression de la liste de commandes ===\n\n");
				if(suppLivreCommande(commande, nbr_commande))
					nbr_commande--;
				break;
			case 9:
				system("clear");
				printf("=== Affichage de la liste des commandes ===\n\n");
				listlivres(commande, nbr_commande, 200000000, 1);
				break;
		}
	}
	return (0);
}