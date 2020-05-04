//fichier pour gerer le menu dans le Projet
//Nathanael SIMON

#include "stock_livre.h"

int menu_choix(void)
{
	int choix;
	int etat = 0;
	printf("==== Menu principal ====");
	do {
		if (etat == 1)
			printf("\n\nVotre choix ne correspond pas. Veuillez reessayer :\n");
		printf("\n[1] Ajouter un ouvrage a la liste des stocks\n");//fait
		printf("[2] Supprimer un ouvrage de la liste des stocks\n");
		printf("[3] Lister des ouvrages\n");//fait 
		printf("[4] Trier des ouvrages\n");
		printf("[5] Chercher un livre dans les stocks\n"); 
		printf("[6] Modifier la frequence de vente d'un livre\n");
		printf("[7] Rajouter un livre de la liste des livres a commander\n");
		printf("[8] Supprimer un livre de la liste des livres a commander\n");
		printf("[9] Afficher la liste des livres en commande\n");
		printf("[0] Sortir du programme\n\n");
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		etat = 1;
	} while (choix != 0 && choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 
			&& choix != 6 && choix != 7 && choix != 8 && choix != 9);
	
	return(choix);
}

int selecTri(void)
{
	int choix;
	int etat = 0;
	
	do {
		if (etat == 1)
			printf("\n\nVotre choix ne correspond pas. Veuillez reessayer :\n");
		printf("\n[1] Tri par exemplaires croissants\n");
		printf("[2] Tri par exemplaires decroissants\n");
		printf("[3] Tri par ordre alphabetique\n");
        printf("[4] Tri par ordre alphabetique decroissant\n");
		printf("[0] revenir au menu principal\n\n");
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		etat = 1;
	} while (choix != 0 && choix != 1 && choix != 2 && choix != 3 && choix != 4);
	
	return(choix);
}

int selecListe(void)
{
	int choix;
	int etat = 0;
	
	do {
		if (etat == 1)
			printf("\n\nVotre choix ne correspond pas. Veuillez reessayer :\n");
		printf("[1] Liste de commande\n");
		printf("[2] Liste des stocks\n");
        printf("[0] Retour au menu principal\n");
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		etat = 1;
	} while (choix != 1 && choix != 2 && choix != 0);
	
	return(choix);
}

int selecRecherche(void)
{
	int choix;
	int etat = 0;
	
	do {
		if (etat == 1)
			printf("\n\nVotre choix ne correspond pas. Veuillez reessayer :\n");
		printf("\n[1] Recherche par nom\n");
		printf("[2] Recherche par ISBN\n");
		printf("[3] Recheche par auteur\n"); 
		printf("[4] Recherche par editeur\n");
		printf("[0] revenir au menu principal\n\n");
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		etat = 1;
	} while (choix != 0 && choix != 1 && choix != 2 && choix != 3 && choix != 4);
	
	return(choix);
}

int selecaff(void)
{
	int choix;
	int etat = 0;
	do {
		if (etat == 1)
			printf("\n\nVotre choix ne correspond pas. Veuillez reessayer :\n");
		printf("\n[1] Afficher tous les livres\n");
		printf("[2] Afficher les livres en dessous de X exemplaires\n");;
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		etat = 1;
	} while (choix != 1 && choix != 2);
	
	return(choix);
}

void aff_livre(Livre livre, int option, int commande)
{
    int i;
    printf("TITRE :");
    printf("%s", livre.titre);
    printf("\nAUTEUR(S) :");
    for(i = 0; i < livre.nbrAuteurs; i++)
    {
        printf("  %s", livre.auteurs[i].nom);
        printf("  %s", livre.auteurs[i].prenom);
        if(i < livre.nbrAuteurs -1)
            printf(", ");
    }
    printf("\nEDITEUR : %s\n", livre.editeur);
    printf("ISBN : ");
    affISBN(livre.ISBN);
    if(commande == 0)
        printf("\nQUANTITE : %d\n", livre.exStock);
    else if(commande == 1)
        printf("EXEMPLAIRES A COMMANDER : %d\n\n", livre.exCommande);
    if (option == 0)
    {
        if(livre.freq == 1)
            printf("Livre frequement vendu (option [6] pour changer)\n\n");
        else
            printf("Livre peu vendu (option [6] pour changer)\n\n");
    }
}

void listlivres(Livre* livre, int nbr_livre, int stock, int commande)
{
    int i;
    for(i = 0; i< nbr_livre; i++)
    {
        if(livre[i].exStock <= stock)
        {
            if(commande == 0)
                aff_livre(livre[i], 0, 0);
            else
                aff_livre(livre[i], 1, 1);
        }
    }
}

int afflivres(Livre* livre, int nbr_livre)
{
    int choix;
    int exemplaires;
    choix = selecaff();

    switch(choix)
    {
        case 0:
            printf("\n=== Retour au menu principal ===\n");
            return(0);
            break;
        case 1:
            if(nbr_livre != 0)
            {
                printf("\nListe de tous les ouvrages :\n\n");
			    listlivres(livre, nbr_livre, 200000000, 0);
            }
            else
				printf("Il n'y actuellement pas de livres en stock\n");
            break;
        case 2:
            printf("\nLes ouvrages en dessous de combien d'exemplaires voulez vous lister ? : ");
			scanf("%d", &exemplaires);
			printf("\nListe des ouvrages en dessous de %d exemplaires :\n\n", exemplaires);
			listlivres(livre, nbr_livre, exemplaires, 0);
            break;
        case 3:
            break;
    }
}
