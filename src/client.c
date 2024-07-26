// src/client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"


Client client;

int recherche_Client(int alpha_rech)
{
    FILE *F;
    F = fopen("client.txt", "r"); // ouverture du fichier en mode lecture
    if (F == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return -1;
    }

    while (fscanf(F, "%d %s %s", &client.numero, client.nom, client.profession) != EOF)
    {
        if (client.numero == alpha_rech)
        {
            fclose(F);
            return 1;
        }
    }

    fclose(F);
    return -1;
}

/*-------------ajout------------- */
void ajout_Client()
{
    int num;
    FILE *F;
    F = fopen("client.txt", "a");

    if (F == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }

init:
    printf("Veuillez entrer le num�ro du nouveau client : \n");
    scanf("%d", &num);

    if (recherche_Client(num) == 1)
    {
        printf("Le num�ro saisi existe d�j� dans notre base de donn�es : \n");
        goto init;
    }
    else
    {
        printf("Le numero saisi n'est pas occupe, Veuillez continuer : \n");
        client.numero = num;
        printf("nom_client\n");
        scanf("%s", client.nom);
        printf("profession_client\n");
        scanf("%s", client.profession);
    }
    fprintf(F, "%d %s %s\n", client.numero, client.nom, client.profession);
    fclose(F);
    printf("L'ajout a �t� effectu� avec succ�s \n");
}
//------------------------affiche
void list_Client()
{
    int num;
    printf("Saisir le num�ro du client � rechercher: \n ");
    scanf("%d", &num);

    if (recherche_Client(num) == 1)
    {
        printf("Le num�ro saisi est bien enregistr� dans notre base de donn�es : \n");
        printf("Voulez-vous l'afficher O/N: \n");
        getchar();  // Pour consommer le '\n' restant
        if (getchar() == 'O' || getchar() == 'o')
        {
            FILE *F;
            F = fopen("client.txt", "r");
            if (F == NULL)
            {
                printf("Erreur d'ouverture du fichier\n");
                return;
            }

            while (fscanf(F, "%d %s %s", &client.numero, client.nom, client.profession) != EOF)
            {
                if (client.numero == num)
                {
                    printf("<<<<-------------------INFORMATIONS SUR Le client ------------------>>>>\n \n");
                    printf("Num�ro : %d\n", client.numero);
                    printf("Nom : %s\n", client.nom);
                    printf("Profession : %s\n", client.profession);
                }
            }
            fclose(F);
        }
    }
    else
    {
        printf("Le num�ro client saisi n'existe pas \n");
    }
}
//----------------------suppression
void suppression_Client()
{
    int num;
    printf("Veuillez entrer le num�ro du client � supprimer: \n");
    scanf("%d", &num);
    getchar(); // Pour consommer le '\n' restant

    if (recherche_Client(num) == 1)
    {
        printf("Voulez-vous le supprimer O/N: \n");
        if (getchar() == 'O' || getchar() == 'o')
        {
            FILE *F, *tmp;
            F = fopen("client.txt", "r");
            tmp = fopen("tempo_client.txt", "w");

            if (F == NULL || tmp == NULL)
            {
                printf("Erreur d'ouverture du fichier\n");
                return;
            }

            while (fscanf(F, "%d %s %s", &client.numero, client.nom, client.profession) != EOF)
            {
                if (client.numero != num)
                {
                    fprintf(tmp, "%d %s %s\n", client.numero, client.nom, client.profession);
                }
            }
            fclose(F);
            fclose(tmp);
            remove("client.txt");
            rename("tempo_client.txt", "client.txt");
            printf("Suppression avec succ�s \n");
        }
    }
    else
    {
        printf("Le num�ro client saisi n'existe pas: Suppression Annul�e \n");
    }
}
//---------------------modification
void modification_Client()
{
    int num;
    printf("Veuillez entrer le num�ro du client � modifier: \n");
    scanf("%d", &num);

    if (recherche_Client(num) == 1)
    {
        printf("Voulez-vous le modifier O/N: \n");
        getchar(); // Pour consommer le '\n' restant
        if (getchar() == 'O')
        {
            FILE *F, *tmp;
            F = fopen("client.txt", "r");
            tmp = fopen("tempo_client.txt", "w");

            if (F == NULL || tmp == NULL)
            {
                printf("Erreur d'ouverture du fichier\n");
                return;
            }

            while (fscanf(F, "%d %s %s", &client.numero, client.nom, client.profession) != EOF)
            {
                if (client.numero == num)
                {
                    printf("nom_client\n");
                    scanf("%s", client.nom);
                    printf("profession_client\n");
                    scanf("%s", client.profession);
                }
                fprintf(tmp, "%d %s %s\n", client.numero, client.nom, client.profession);
            }
            fclose(F);
            fclose(tmp);
            remove("client.txt");
            rename("tempo_client.txt", "client.txt");
            printf("La modification a r�ussi \n");
        }
        else
        {
            printf("Modification annul�e \n");
        }
    }
    else
    {
        printf("Le num�ro client saisi n'existe pas \n");
    }
}
//------------------------affichage
void list_all_Client()
{
    FILE *F;
    F = fopen("client.txt", "r");
    if (F == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    printf("La liste des clients est : \n");
    printf("Num�ro\t Nom\t Profession \n");
    while (fscanf(F, "%d\t   %s\t     %s", &client.numero, client.nom, client.profession) != EOF)
    {
        printf("%d\t%s\t%s\n", client.numero, client.nom, client.profession);
    }
    fclose(F);
}


