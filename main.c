// fichier main du projet Stock livre
// Nathanael SIMON
// Sous linux il faut activer la ligne 88 du fichier gestion_stock.c pour un bon fonctionnement

#include "stock_livre.h"

int main(void)
{
	int choix;
	int statut = 1;
	int nbr_livre = 0;
	int nbr_commande = 0;
	int j;
	int* p = &j;
	int testsupp;
	int nbrExCommande;

	Livre livre[NBRMAX];
	Livre commande[NBRMAX];
	clrscreen(); //fonction qui remplace systeme("clear");
	while (statut == 1){
		choix = menu_choix();
		switch(choix){
			case 0:
				clrscreen(); 
				printf("\n\n=== AU REVOIR ===\n");
				return (0);
				break;
			case 1:
				clrscreen();
				printf("=== AJOUT D'UN NOUVEL OUVRAGE ===\n\n");
				if(nbr_livre == NBRMAX -1)
					printf("Le nombre d'ouvrage maximal a ete atteint. Veuillez supprimer un ouvrage avant d'en rajouter un autre.\n\n");
				else if(ajout_livre(livre, nbr_livre, 0))
					nbr_livre++;
				break;
			case 2:
				clrscreen();
				printf("=== SUPPRESSION D'UN OUVRAGE===\n\n");
				testsupp = suppLivre(livre, nbr_livre, p);
				if(testsupp == 1)
					nbr_livre--;
				else if(testsupp == 2)
				{
					printf("Le livre etant frequement vendu et en dessous de 10 exemplaires, il est automatiquement ajoute sur la liste des commandes.\n");
					printf("Combien d'exemplaires voulez vous ajouter a la liste d'une commande ? :");
					scanf("%d", &nbrExCommande);
					fflush(stdin);
					livre[j].exCommande = nbrExCommande;
					commande[nbr_commande]=livre[j];
					nbr_commande++;
				}
				break;
			case 3:
				clrscreen();
				printf("=== LISTE DES OUVRAGES ===\n");
				afflivres(livre, nbr_livre);
				break;
			case 4:
				clrscreen();
				triLivre(livre, nbr_livre, commande, nbr_commande);
				break;
			case 5:
				clrscreen();
				printf("=== RECHERCHE ===\n\n");
				if(recherchelivre(livre, nbr_livre) == 1)
				{
					if(nbr_commande == NBRMAX -1)
						printf("Le nombre maximal de livres sur la liste de commande a ete atteint. Veuillez en supprimer avant d'en rajouter");
					else if(ajout_livre(commande, nbr_commande, 1))
						nbr_commande++;
				}
				break;
			case 6:
				clrscreen();
				printf("=== Changer la frequence de vente ===\n\n");
				freqLivre(livre, nbr_livre);
				break;
			case 7:
				clrscreen();
				printf("=== Ajout d'un livre a la liste de commandes ===\n\n");
				if(nbr_commande == NBRMAX -1)
					printf("Le nombre maximal de livres sur la liste de commande a ete atteint. Veuillez en supprimer avant d'en rajouter");
				else if(ajout_livre(commande, nbr_commande, 1))
					nbr_commande++;
				break;
			case 8:
				clrscreen();
				printf("=== Suppression de la liste de commandes ===\n\n");
				if(suppLivreCommande(commande, nbr_commande))
					nbr_commande--;
				break;
			case 9:
				clrscreen();
				printf("=== Affichage de la liste des commandes ===\n\n");
				listlivres(commande, nbr_commande, 200000000, 1);
				break;
		}
	}
	return (0);
}