//Fichier des fonctions sur l'ISBN
#include "stock_livre.h"

void affISBN(char *ISBN)
{
	int i;
	int *p = &i;
	int a;
	int long4emeSeg;
	for (i = 0; i<3; i++)
		printf("%c", ISBN[i]);
	printf("-");
	if(ISBN[3] == '2')
	{
		printf("2-");
		long4emeSeg = checkseg3N2(ISBN, p);
		printf("-");
		a = i;
		for(; i< a+long4emeSeg; i++)
			printf("%c", ISBN[i]);
		printf("-");
		for(; i < 13; i++)
		{
			printf("%c", ISBN[i]);
		}
		printf("\n");	
	}
	else
	{
		printf("10-");
		long4emeSeg = checkseg3N10(ISBN, p);
		printf("-");
		a = i;
		for(; i< a+long4emeSeg; i++)
			printf("%c", ISBN[i]);
		printf("-");
		for(; i < 13; i++)
		{
			printf("%c", ISBN[i]);
		}
		printf("\n");
	}
}

int verif_ISBN(char* ISBN) //verifie la validite de ISBN
{
    int i = 0;
    if(ISBN[0] == '9' && ISBN[1] == '7')
    {
        if(ISBN[2] == '8')
		{
            if(ISBN[3] != '2')
                return(0);
		}
		else if(ISBN[2] == '9')
		{
		    if(ISBN[3] != '1' || ISBN[4] != '0')
                return(0);
		}
		else
            return(0);
    }
    else 
        return (0);

    while(ISBN[i] != '\0')
    {
        i++;
    }
	if(i == 13)
    	return(1);
	else
		return(0);
}    

char* ISBN(char *ISBN) //Prends et affiche l'ISBN
{
    int valide = 0;
    while(valide != 1)
    {
        if(verif_ISBN(ISBN))
        {
            printf("L'ISBN est valide. ISBN = : ");
            affISBN(ISBN);
            valide = 1;
            return(ISBN);
        }
        
        else
        { 
            printf("ISBN PAS VALIDE - RETENTEZ :");
            scanf("%s", ISBN);
            fflush(stdin);
        }
    }
	return(ISBN);
}


int checkseg3N2(char* ISBN, int* p) //affiche le 3eme membre et retourne
{							//le nombre de caractere du 4eme segment
	int i;
	if(ISBN[4] < '2')
	{
		for(i = 4; i < 6; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(6);
	}
	if(ISBN[4] == '3' && ISBN[5] >= '5')
	{
		for(i = 4; i< 9; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(3);
	}
	if(ISBN[4] >= '2' && ISBN[4] <= '3')
	{
		for(i = 4; i < 7; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(5);
	}
	if(ISBN[4] == '4' && ISBN[5] <= '8')
	{
		for(i = 4; i < 7; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(5);
	}
	if(ISBN[4] == '4' && ISBN[5] == '9' && ISBN[6] < '5')
	{
		for(i = 4; i < 10; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(2);
	}
	if(ISBN[4] >= '4' && ISBN[4] <= '6')
	{
		for(i = 4; i < 7; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(5);
	}
	if(ISBN[4] == '7' || (ISBN[4] == '8' && ISBN[5] < '4'))
	{
		for(i = 4; i < 8; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(4);
	}
	if(ISBN[4] == '8')
	{
		for(i = 4; i < 9; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(3);
	}
	if(ISBN[4] == '9')
	{
		if(ISBN[5] >= '5')
		{
			for(i = 4; i < 11; i++)
				printf("%c", ISBN[i]);
			*p = i;
			return(1);
		}
		if(ISBN[5] >= '0' && ISBN[5] <= '1' && ISBN[6] <= '9' && ISBN[7] <= '7')
		{
			for(i = 4; i < 10; i++)
				printf("%c", ISBN[i]);
			*p = i;
			return(2);
		}
		if(ISBN[5] == '1' && ISBN[6] == '9' && ISBN[7] == '8' && ISBN[8] == '0')
		{
			for(i = 4; i< 9; i++)
				printf("%c", ISBN[i]);
			*p = i;
			return(3);
		}
		if(ISBN[5] == '1' && ISBN[6] == '9' && ISBN[7] == '9' && ISBN[8] >= '4' && 
		ISBN[8] <= '6' && ISBN[9] >= '3' && ISBN[9] <= '8' && ISBN[10] >= '0' && ISBN[10] <= '9')
		{
			for(i = 4; i < 11; i++)
				printf("%c", ISBN[i]);
			*p = i;
			return(1);
		}
		if(ISBN[5] == '1' && ISBN[6] == '9' && ISBN[7] >= '8' && ISBN[7] <= '9' && ISBN[8] >= '1'
		&& ISBN[8] <= '4' && ISBN[9] >= '0' && ISBN[9] <= '2')
		{
			for(i = 4; i < 10; i++)
				printf("%c", ISBN[i]);
			*p = i;
			return(2);
		}
		else
		{
			for(i = 4; i < 10; i++)
				printf("%c", ISBN[i]);
			*p = i;
			return(2);
		}
	}
	return(0);
}

int checkseg3N10(char *ISBN, int* p)
{
	int i;
	if(ISBN[5] < '2')
	{
		for(i = 5; i < 7; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(5);
	}
	if(ISBN[5] <= '6')
	{
		for(i = 5; i < 8; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(4);	
	}
	if(ISBN[5] <= '8')
	{
		for(i = 5; i < 9; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(3);
	}
	if(ISBN[6] < '7')
	{
		for(i = 5; i < 10; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(2);
	}
	if(ISBN[6] == '7' && ISBN[7] < '6')
	{
		for(i = 5; i < 10; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(2);
	}
	else
	{
		for(i = 5; i < 11; i++)
			printf("%c", ISBN[i]);
		*p = i;
		return(1); 
	}
}