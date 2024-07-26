#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "menu.h"
#include "manager.h"


void evop()
{
    int choice;
    printf("*******\t Bienvenue sur notre application DOX SA SOXLA SI DIAM \t ******* \n");
    
    printf("\n");
    printf(" ||     MENU PRINCIPAL        || \n \n");
    
    printf(" ******************************* \n");
    printf("\n");
    printf(" || (1) Gestion des clients     || \n");
    printf(" || (2) Gestion des voitures    || \n");
    printf(" || (3) Gestion des locations   || \n");
    printf(" || (0) QUITTER                 || \n");
    printf(" ******************************* \n");
    
    
    
    printf(" Veuillez renseigner  votre choix : \n");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 0 :
        printf("Au revoir , � bient�t !!!\n");
        break;
    case 1 :
        manager_Client();
        break;
    case 2 :
        manager_Voiture();
        break;
    case 3 : 
        manager_LOcation();
        break;
        
    default:
        printf("choix indisponible pour le moment \n");
        
    }
}