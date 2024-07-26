#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Manager.h"
#include "client.h"
#include "voiture.h"
#include "location.h"



void manager_Client()
{
    int choice;

    do {
        printf(" ||   Bienvenue au    MENU CLIENT           || \n \n");
        printf(" ***********************************\n");
        printf(" || (1) Ajout                     || \n");
        printf(" || (2) Modification              || \n");
        printf(" || (3) Recherche                 || \n");
        printf(" || (4) Suppression               || \n");
        printf(" || (5) Afficher les Clients      || \n");
        printf(" || (0) PR�C�DENT                 || \n");
        printf(" *********************************** \n");
        printf("Veuillez entrer votre choix : \n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                break;
            case 1:
                ajout_Client();
                break;
            case 2:
                modification_Client();
                break;
            case 3:
                list_Client();
                break;
            case 4:
                suppression_Client();
                break;
            case 5:
                list_all_Client();
                break;
            default:
                printf("Choix indisponible pour le moment\n");
        }

        if (choice != 0) {
            printf("Voulez-vous continuer (O/N) : \n");
            getchar();  // clear newline left by scanf
        }
    } while (choice != 0 && getchar() == 'O' );
}
void manager_LOcation() {
    int choice;

    do {
        printf("\n ||       MENU LOCATION         || \n\n");
        printf(" ***********************************\n");
        printf(" || (1) Ajout                     || \n");
        printf(" || (2) Afficher les Locations    || \n");
        printf(" || (0) PR�C�DENT                 || \n");
        printf(" ***********************************\n");

        printf("Veuillez entrer votre choix : \n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                break;
            case 1:
                ajout_Location();
                break;
            case 2:
                list_all_Location();
                break;
            default:
                printf("Choix indisponible pour le moment\n");
        }

        if (choice != 0) {
            printf("Voulez-vous continuer (O/N) : \n");
            getchar();  // clear newline left by scanf
        }
    } while (choice != 0 && getchar() == 'O');
}
void manager_Voiture()
{
    int choice;

    do {
        printf(" ||       MENU VOITURE           || \n\n");
        printf(" ***********************************\n");
        printf(" || (1) Ajout                     || \n");
        printf(" || (2) Modification              || \n");
        printf(" || (3) Recherche                 || \n");
        printf(" || (4) Suppression               || \n");
        printf(" || (5) Afficher les Voitures     || \n");
        printf(" || (0) PR�C�DENT                 || \n");
        printf(" ***********************************\n");
        printf("Veuillez entrer votre choix : \n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                break;
            case 1:
                ajout_Voiture();
                break;
            case 2:
                modification_Voiture();
                break;
            case 3:
                list_Voiture();
                break;
            case 4:
                suppression_Voiture();
                break;
            case 5:
                list_all_Voiture();
                break;
            default:
                printf("Choix indisponible pour le moment\n");
        }

        if (choice != 0) {
            printf("Voulez-vous continuer (O/N) : \n");
            getchar();  // clear newline left by scanf
        }
    } while (choice != 0 && getchar() == 'O' );
}
