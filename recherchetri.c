#include "stock_livre.h"


void triA(Livre* livre, int nbr_livre, int croissant)
{
    int i;
    int j;
    Livre tmp;
    int min_idx;
    for(i = 0; i<nbr_livre; i++)
    {
        min_idx = i;
        for(j = i+1; j < nbr_livre; j++)
        {
            if(croissant == 1)
            {
                if(strcmp(livre[min_idx].titre, livre[j].titre) < 0)
                    min_idx = j;
            }
            else if(croissant == 0)
            {
                if(strcmp(livre[min_idx].titre, livre[j].titre) > 0)
                    min_idx = j;
            }
        }
        tmp = livre[min_idx];
        livre[min_idx] = livre[i];
        livre[i] = tmp;
    }
    if(croissant == 0)
        printf("La liste a ete triee par ordre alphabetique\n\n");
    else 
        printf("La liste a ete triee par ordre alphabetique decroissant\n\n");
}

void tri(Livre* livre, int nbr_livre, int croissant)
{
    int i;
    int j;
    Livre tmp;
    int min_idx;
    for(i = 0; i<nbr_livre; i++)
    {
        min_idx = i;
        for(j = i+1; j < nbr_livre; j++)
        {
            if(croissant == 1)
            {
                if(livre[min_idx].exStock < livre[j].exStock)
                    min_idx = j;
            }
            else if(croissant == 0)
            {
                if(livre[min_idx].exStock > livre[j].exStock)
                    min_idx = j;
            }
        }
        tmp = livre[min_idx];
        livre[min_idx] = livre[i];
        livre[i] = tmp;
    }
    if(croissant == 0)
        printf("La liste a ete triee du plus petit nombre d'exemplaires au plus grand\n\n");
    else 
        printf("La liste a ete triee du plus grand nombre d'exemplaires au plus petit\n\n");
}

int triLivre(Livre* livre, int nbr_livre, Livre* commande, int nbr_commande)
{
    int choix;
    int liste;

    liste = selecListe();

    if(liste == 0)
        return(0);

    choix = selecTri();

    if(choix == 0)
        return(0);
    

    switch(choix)
    {
        case 0:
            printf("\n=== Retour au menu principal ===\n");
            return(0);
            break;
        case 1:
            if(liste == 1)
                tri(commande, nbr_commande, 0);
            if(liste == 2)
                tri(livre, nbr_livre, 0);
            break;
        case 2:
            if(liste == 1)
                tri(commande, nbr_commande, 1);
            if(liste == 2)
                tri(livre, nbr_livre, 1);
            break;
        case 3:
            if(liste == 1)
                triA(commande, nbr_commande, 0);
            if(liste == 2)
                triA(livre, nbr_livre, 0);
            break;
        case 4:
            if(liste == 1)
                triA(commande, nbr_commande, 1);
            if(liste == 2)
                triA(livre, nbr_livre, 1);
            break;
    }
    printf("Voici les liste triee :\n");
    if(liste == 1)
        listlivres(commande, nbr_commande, 2000000, 1);
    if(liste == 2)
        listlivres(livre, nbr_livre, 2000000, 0);
    
    return(0);
}

int rechercheNom(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int trouver = 0;
    int choix;
    printf("Quel titre voulez vous chercher ? : ");
    scanf("%s", tab);
    fflush(stdin);
    while(i < nbr_livre)
    {
        if(!strcmp(tab, livre[i].titre))
        {
            trouver = 1;
            printf("=== Livre trouve ===\n");
            aff_livre(livre[i], 0, 0);
            i++;
        }
        else
            i++;
    }
    if (trouver == 0)
    {
        printf("\nLe livre n'a pas ete trouve. Voulez vous le rajouter a la liste des livres a commander ? 1-oui 2-non: ");
        scanf("%d", &choix);
        fflush(stdin);
        if(choix == 1)
            return(1);
    }
    return(0);
}

int rechercheEditeur(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int trouver = 0;
    int choix;
    printf("Quel editeur voulez vous chercher ? : ");
    scanf("%s", tab);
    fflush(stdin);
    while(i < nbr_livre)
    {
        if(!strcmp(tab, livre[i].editeur))
        {
            trouver = 1;
            printf("=== Livre trouve ===\n");
            aff_livre(livre[i], 0, 0);
            i++;
        }
        else
            i++;
    }
    if (trouver == 0)
    {
        printf("\nLe livre n'a pas ete trouve. Voulez vous le rajouter a la liste des livres a commander ? 1-oui 2-non: ");
        scanf("%d", &choix);
        fflush(stdin);
        if(choix == 1)
            return(1);
    }
    return(0);
}

int rechercheISBN(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int trouver = 0;
    int choix;
    printf("Quel ISBN voulez vous chercher ? : ");
    scanf("%s", tab);
    fflush(stdin);
    while(i < nbr_livre)
    {
        if(!strcmp(tab, livre[i].ISBN))
        {
            trouver = 1;
            printf("=== Livre trouve ===\n");
            aff_livre(livre[i], 0, 0);
            i++;
        }
        else
            i++;
    }
    if (trouver == 0)
    {
        printf("\nLe livre n'a pas ete trouve. Voulez vous le rajouter a la liste des livres a commander ? 1-oui 2-non: ");
        scanf("%d", &choix);
        fflush(stdin);
        if(choix == 1)
            return(1);
    }
    return(0);
}

int rechercheAuteur(Livre* livre, int nbr_livre)
{
    char tab[200];
    int i = 0;
    int j = 0;
    int choix;
    int trouver = 0;
    printf("Quel est le nom de l'auteur que vous chercher ? : ");
    scanf("%s", tab);
    fflush(stdin);
    while(i < nbr_livre)
    {
        while(j < livre[i].nbrAuteurs)
        {
            if(!strcmp(tab, livre[i].auteurs[j].nom))
            {
                trouver = 1;
                printf("=== Livre trouve ===\n\n");
                aff_livre(livre[i],0, 0);
                j++;
            }
            else
                j++;
        }
        i++;
    }
    if (trouver == 0)
    {
        printf("\nLe livre n'a pas ete trouve. Voulez vous le rajouter a la liste des livres a commander ? 1-oui 2-non: ");
        scanf("%d", &choix);
        fflush(stdin);
        if(choix == 1)
            return(1);
    }
    return(0);
}

int recherchelivre(Livre* livre, int nbr_livre)
{
    int choix;

    choix = selecRecherche();

    switch(choix)
    {
        case 0:
            printf("\n=== Retour au menu principal ===\n");
            return(0);
        case 1:
            if(rechercheNom(livre, nbr_livre) == 1)
                return (1);
            break;
        case 2:
            if(rechercheISBN(livre, nbr_livre) == 1)
                return(1);
            break;
        case 3:
            if(rechercheAuteur(livre, nbr_livre) == 1)
                return(1);
            break;
        case 4:
            if(rechercheEditeur(livre, nbr_livre) == 1)
                return(1);
            break;
    }
    return(0);
    //return(1) si on a ajouter un livre sinon 0;
}