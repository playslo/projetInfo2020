//fichier de gestion des stocks
//Nathanael SIMON & Nassim SI MOHAMMED

#include "stock_livre.h"

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

int verif_livre(Livre* livre, char* ISBNtemp, int nbr_livre, int statut)
{
    int i = 0;
    int stock;
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
            printf("Nous possedons deja cet ouvrage. Combien d'exemplaires voulez vous ajouter ? :\n");
            scanf("%d", &stock);
            fflush(stdin);
            livre[i].exStock += stock;
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

int ajout_livre(Livre* livre, int nbr_livre, int commande)
{
    int i;
    char ISBNtmp[13];
    int valide = 0;
    printf("Entrez l'ISBN de l'ouvrage : ");
    scanf("%s", ISBNtmp);
    fflush(stdin);
    
    while(valide != 2 && !verif_ISBN(ISBNtmp))
    {
        printf("ISBN Invalide. Reesayer ? 1-oui. 2-non :");
        scanf("%d", &valide);
        fflush(stdin);
        if(valide == 1)
        {
            printf("Entrez l'ISBN : ");
            scanf("%s", ISBNtmp);
            fflush(stdin);
        }
    }
    if(verif_livre(livre, ISBNtmp, nbr_livre, 0) && (valide == 1 || valide == 0))
    {
        init_livre(livre[nbr_livre]);
        ft_strcpy(ISBNtmp, livre[nbr_livre].ISBN);
        printf("\nEntrez le titre de l'ouvrage : ");
        scanf("%s",livre[nbr_livre].titre);
        fflush(stdin);
        printf("\nEntrez le nombres d'auteurs :");
        scanf("%d", &livre[nbr_livre].nbrAuteurs);
        fflush(stdin);
        for(i = 0; i < livre[nbr_livre].nbrAuteurs; i++)
        {
            printf("\nEntrez le nom de l'auteur nO %d : ", i+1);
            scanf("%s", livre[nbr_livre].auteurs[i].nom);
            fflush(stdin);
            printf("\nEntrez le prenom de l'auteur nO %d : ", i+1);
            scanf("%s", livre[nbr_livre].auteurs[i].prenom); 
            fflush(stdin);
        }
        printf("\nEntrez l'editeur du livre :");
        scanf("%s", livre[nbr_livre].editeur);
        fflush(stdin);
        if(commande == 0)
        {
            printf("\nCombien d'exemplaires souhaitez vous ajouter ? : ");
            scanf("%d", &livre[nbr_livre].exStock);
            fflush(stdin);
        }
        else if(commande == 1)
        {
            printf("\nCombien d'exemplaires souhaitez vous ajouter a commander ? : ");
            scanf("%d", &livre[nbr_livre].exCommande);
            fflush(stdin);
        }
        livre[nbr_livre].freq = 0;
        printf("\n");
        if(commande == 0)
            aff_livre(livre[nbr_livre], 0, 0);
        else
            aff_livre(livre[nbr_livre], 1, 1);
        return(1);
    }
    return(0);
}

int suppLivre(Livre* livre, int nbr_livre, int* p)
{
    char ISBNtmp[13];
    int valide = 0;
    int i;
    int choix;
    int ex;

    printf("\nVoici la liste des livres actuellements en stock : \n");
    listlivres(livre, nbr_livre, 2000000, 0);
    printf("Entrez l'ISBN du livre que vous voulez supprimer :");
    scanf("%s", ISBNtmp);
    fflush(stdin);
    while(valide != 2 && !verif_ISBN(ISBNtmp))
    {
        printf("ISBN Invalide. Reesayer ? 1-oui. 2-non :");
        scanf("%d", &valide);
        fflush(stdin);
        if(valide == 1)
        {
            printf("Entrez l'ISBN : ");
            scanf("%s", ISBNtmp);
            fflush(stdin);
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
                aff_livre(livre[i], 0, 0);
                printf("Etes vous sur ? 1- oui, 2- non :");
                scanf("%d", &choix);
                fflush(stdin);
                    if(choix == 1)
                    {
                        printf("\nCombien d'exemplaires voulez vous supprimer ?");
                        scanf("%d",&ex);
                        fflush(stdin);
                        if(ex >= livre[i].exStock)
                        {
                            while(i < nbr_livre)
                            {
                                livre[i] = livre[i+1];
                                i++;
                            }
                            return(1);
                        }
                        else
                        {
                            livre[i].exStock-=ex;
                            printf("le livre a desormais %d exemplaire(s) en stock", livre[i].exStock);
                            if(livre[i].freq == 1)
                            {
                                if(livre[i].exStock <= 10)
                                {
                                    *p = i;
                                    return(2);
                                }
                            }
                            return(0);
                        }
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

int suppLivreCommande(Livre* livre, int nbr_livre)
{
    char ISBNtmp[13];
    int valide = 0;
    int i;
    int choix;
    int ex;

    printf("\nVoici la liste des livres actuellements en stock : \n");
    listlivres(livre, nbr_livre, 2000000, 1);
    printf("Entrez l'ISBN du livre que vous voulez supprimer :");
    scanf("%s", ISBNtmp);
    fflush(stdin);
    while(valide != 2 && !verif_ISBN(ISBNtmp))
    {
        printf("ISBN Invalide. Reesayer ? 1-oui. 2-non :");
        scanf("%d", &valide);
        fflush(stdin);
        if(valide == 1)
        {
            printf("Entrez l'ISBN : ");
            scanf("%s", ISBNtmp);
            fflush(stdin);
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
                printf("\nVoici le livre que vous voulez supprimer :\n\n");
                aff_livre(livre[i], 1, 1);
                printf("Etes vous sur ? 1- oui, 2- non :");
                scanf("%d", &choix);
                fflush(stdin);
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

int freqLivre(Livre* livre, int nbr_livre)
{
    int i = 0;
    int trouver = 0;
    int etat;
    int valide = 0;
    char ISBNtmp[13];
    printf("\nVoici la liste des livres actuellements en stock : \n");
    listlivres(livre, nbr_livre, 2000000, 0);
    printf("Entrez l'ISBN du livre dont vous voulez changer la frequence de vente :");
    scanf("%s", ISBNtmp);
    fflush(stdin);
    while(valide != 2 && !verif_ISBN(ISBNtmp))
    {
        printf("ISBN Invalide. Reesayer ? 1-oui. 2-non :");
        scanf("%d", &valide);
        fflush(stdin);
        if(valide == 1)
        {
            printf("Entrez l'ISBN : ");
            scanf("%s", ISBNtmp);
            fflush(stdin);
        }
        if(valide == 2)
            return(0);
    }
    if(verif_livre(livre, ISBNtmp, nbr_livre, 1) && (valide == 1 || valide == 0))
    {
        while (i < nbr_livre)
        {
            if(!strcmp(ISBNtmp, livre[i].ISBN))
            {
                if(livre[i].freq == 0)
                {
                    aff_livre(livre[i], 1, 0);
                    printf("\nCe livre est indiquer comme peu vendu, voulez vous changer cela ? \n1- oui. 2- non : ");
                    scanf("%d", &etat);
                    fflush(stdin);
                    if(etat == 1)
                    {
                        livre[i].freq = 1;
                        printf("\nLe livre est desormais marquer comme frequement vendu\n");
                    }
                    else
                        printf("\nRetour au menu principal\n\n");
                }
                else if(livre[i].freq == 1)
                {
                    aff_livre(livre[i], 1, 0);
                    printf("\nCe livre est indiquer comme frequement vendu, voulez vous changer cela ? \n1- oui. 2- non : ");
                    scanf("%d", &etat);
                    fflush(stdin);
                    if(etat == 1)
                    {
                        livre[i].freq = 0;
                        printf("\nLe livre est desormais marquer comme peu vendu\n");
                    }
                    else
                        printf("\nRetour au menu principal\n\n");
                    
                }
                trouver = 1;
                i++;
            }
            else
                i++;
        }
    }
    if(trouver == 0)
        printf("Livre non present, retour au menu principal\n");
}
