//fichier pour gerer le menu dans le Projet
//Nathanael SIMON

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
		printf("[3] Afficher la liste des ouvrages actuellement en stock\n");//fait 
		printf("[4] Lister les ouvrages dont on a moins que X exemplaires\n");
		printf("[5] Chercher un livre dans les stocks\n"); 
		printf("[6] Modifier la frequence de vente d'un livre\n");
		printf("[7] Rajouter un livre de la liste des livres a commander\n");
		printf("[8] Supprimer un livre de la liste des livres a commander\n");
		printf("[0] Sortir du programme\n\n");
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		etat = 1;
	} while (choix != 0 && choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 
			&& choix != 6 && choix != 7 && choix != 8);
	
	return(choix);
}