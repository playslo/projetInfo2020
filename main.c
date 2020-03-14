// fichier main du projet Stock livre
// Nathanael SIMON

#include "stock_livre.h"

int main(void)
{
	int choix;

	choix = menu_choix();
	Livre livre[NBRMAX];
	while (1){   //condition a modfier plus tard
		switch(choix){
			case 0: 
				return (0);
				break;
			case 1: 
				("Vous avez selectionner [1] :/n");
				ajout_livre(&livre[nbr_livre]);
				break;
			default: 
				printf("pas encore programme tu connais");
				choix = menu_choix(); 
				break;
		}
	}
	return (0);
}