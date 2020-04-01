//fichier de gestion des stocks
//Nathanael SIMON

 void init_livre(Livre livre)
{
     livre.exStock = 1;
     livre.freq = 0;
     livre.nbrAuteurs = 0;
}

int ft_strcmp(char* str1, char* str2)
{
    int i = 0;
    while(i < 13)
    {
        if(str1[i] == str2[i])
            i++;
        else
            return(0);
    }
    return(1);
}

void aff_livre(Livre livre)
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
    printf("\nQUANTITE : %d\n\n", livre.exStock);
}

int verif_livre(Livre* livre, char* ISBNtemp, int nbr_livre, int statut)
{
    int i = 0;
    while(i <= nbr_livre)
    {
        if(!ft_strcmp(ISBNtemp, livre[i].ISBN))
        {
            i++;
        }
        else
        {
            if(statut == 1)
                return(1);
            printf("Nous possedons deja cet ouvrage. Nous rajoutons 1 exemplaire a ceux que nous avons deja\n"); //demander le nombre dex voulu
            livre[i].exStock++;
            printf("Cet exemplaire est desormais disponnible en %d exemplaires\n", livre[i].exStock);
            return(0);
        }        
    }
    return (1);
}

void ft_strcpy(char* src, char* dest)
{
    int i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
}

void ajout_livre(Livre* livre, int nbr_livre)
{
    int i;
    char ISBNtmp[13];
    int valide = 0;
    printf("Entrez l'ISBN de l'ouvrage : ");
    scanf("%s", ISBNtmp);
    while(valide != 2 && !verif_ISBN(ISBNtmp))
    {
        printf("ISBN Invalide. Reesayer ? 1-oui. 2-non :");
        scanf("%d", &valide);
        if(valide == 1)
        {
            printf("Entrez l'ISBN : ");
            scanf("%s", ISBNtmp);
        }
    }
    if(verif_livre(livre, ISBNtmp, nbr_livre, 0) && (valide == 1 || valide == 0))
    {
        init_livre(livre[nbr_livre]);
        ft_strcpy(ISBNtmp, livre[nbr_livre].ISBN);
        printf("\nEntrez le titre de l'ouvrage : ");
        scanf("%s", livre[nbr_livre].titre);
        printf("\nEntrez le nombres d'auteurs :");
        scanf("%d", &livre[nbr_livre].nbrAuteurs);
        for(i = 0; i < livre[nbr_livre].nbrAuteurs; i++)
        {
            printf("\nEntrez le nom de l'auteur nO %d : ", i+1);
            scanf("%s", livre[nbr_livre].auteurs[i].nom);
            printf("\nEntrez le prenom de l'auteur nO %d : ", i+1);
            scanf("%s", livre[nbr_livre].auteurs[i].prenom); 
        }
        printf("\nEntrez l'editeur du livre :");
        scanf("%s", livre[nbr_livre].editeur);
        printf("\nCombien d'exemplaires souhaitez vous ajouter ? : ");
        scanf("%d", &livre[nbr_livre].exStock);
        printf("\n");
        aff_livre(livre[nbr_livre]);
    }
}

int suppLivre(Livre* livre, int nbr_livre)
{
    char ISBNtmp[13];
    int valide = 0;
    int i;
    int choix;
    printf("\nVoici la liste des livres actuellements en stock : \n");
    listlivres(livre, nbr_livre, 2000000);
    printf("Entrez l'ISBN du livre que vous voulez supprimer :");
    scanf("%s", ISBNtmp);
    while(valide != 2 && !verif_ISBN(ISBNtmp))
    {
        printf("ISBN Invalide. Reesayer ? 1-oui. 2-non :");
        scanf("%d", &valide);
        if(valide == 1)
        {
            printf("Entrez l'ISBN : ");
            scanf("%s", ISBNtmp);
        }
        if(valide == 2)
            return(0);
    }
    if(verif_livre(livre, ISBNtmp, nbr_livre, 1) && (valide == 1 || valide == 0))
    {
        while(i < nbr_livre)
        {
            if(ft_strcmp(ISBNtmp, livre[i].ISBN))
            {
                printf("Voici le livre que vous voulez supprimer :\n");
                aff_livre(livre[i]);
                printf("Etes vous sur ? 1- oui, 2- non :");
                scanf("%d", &choix);
                    if(choix == 1)
                    {
                        while(i < nbr_livre)
                        {
                            livre[i] = livre[i+1];
                            i++;
                        }
                        return(1);
                    }
                    else
                        return(0);
            }
            else
            i++;
        }
        printf("ISBN non trouver dans la liste. Retour au menu principal.\n");
        return(0);
    }
}

void listlivres(Livre* livre, int nbr_livre, int stock)
{
    int i;
    for(i = 0; i< nbr_livre; i++)
    {
        if(livre[i].exStock <= stock)
            aff_livre(livre[i]);
    }
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

int ft_strcmp2(char* str1, char* str2)
{
    int i = 0;
    while(str1[i] || str2[2])
    {
        if(str1[i] == str2[i])
            i++;
        else
            return(0);
    }
    return(1);
}



int rechercheNom(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int trouver = 0;
    printf("Quel titre voulez vous chercher ? : ");
    scanf("%s", tab);
    while(i < nbr_livre)
    {
        if(!strcmp(tab, livre[i].titre))
        {
            trouver = 1;
            printf("=== Livre trouve ===\n");
            aff_livre(livre[i]);
            i++;
        }
        else
            i++;
    }
    if (trouver == 0)
        printf("Le livre n'a pas ete trouve. Il est ajoute a la liste a commander (pas encore programmer)");
    return(0);
}

int rechercheEditeur(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int trouver = 0;
    printf("Quel editeur voulez vous chercher ? : ");
    scanf("%s", tab);
    while(i < nbr_livre)
    {
        if(!strcmp(tab, livre[i].editeur))
        {
            trouver = 1;
            printf("=== Livre trouve ===\n");
            aff_livre(livre[i]);
            i++;
        }
        else
            i++;
    }
    if (trouver == 0)
        printf("Le livre n'a pas ete trouve. Il est ajoute a la liste a commander (pas encore programmer)");
    return(0);
}

int rechercheISBN(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int trouver = 0;
    printf("Quel ISBN voulez vous chercher ? : ");
    scanf("%s", tab);
    while(i < nbr_livre)
    {
        if(!strcmp(tab, livre[i].ISBN))
        {
            trouver = 1;
            printf("=== Livre trouve ===\n");
            aff_livre(livre[i]);
            i++;
        }
        else
            i++;
    }
    if (trouver == 0)
        printf("Le livre n'a pas ete trouve. Il est ajoute a la liste a commander (pas encore programmer)");
    return(0);
}

int rechercheAuteur(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int j = 0;
    int trouver = 0;
    printf("Quel est le nom de l'auteur que vous chercher ? : ");
    scanf("%s", tab);
    while(i < nbr_livre)
    {
        while(j < livre[i].nbrAuteurs)
        {
            if(!strcmp(tab, livre[i].auteurs[j].nom))
            {
                trouver = 1;
                printf("=== Livre trouve ===\n\n");
                aff_livre(livre[i]);
                j++;
            }
            else
                j++;
        }
        i++;
    }
    if (trouver == 0)
        printf("Le livre n'a pas ete trouve. Il est ajoute a la liste a commander (pas encore programmer)");
    return(0);
}

int recherchelivre(Livre* livre, int nbr_livre)
{
    int choix;

    choix = selecRecherche();

    switch(choix)
    {
        case 0:
            printf("=== Retour au menu principal ===");
            return(0);
        case 1:
            rechercheNom(livre, nbr_livre);
            break;
        case 2:
            rechercheISBN(livre, nbr_livre);
            break;
        case 3:
            rechercheAuteur(livre, nbr_livre);
            break;
        case 4:
            rechercheEditeur(livre, nbr_livre);
            break;

    }
    return(1);
    //return(1) si on a ajouter un livre sinon 0;
}