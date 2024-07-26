// src/voiture.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voiture.h"

Voiture voiture;

int recherche_Voiture(int alpha_rech)
{
    FILE *F = fopen("voiure.txt", "r");
    if (F == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    while (fscanf(F, "%d %s %s %d %d %f", &voiture.code, voiture.marque, voiture.modele,
                  &voiture.nombreExemplairesTotal, &voiture.nombreExemplairesDisponibles, &voiture.tarifJournalier) != EOF) {
        if (voiture.code == alpha_rech) {
            fclose(F);
            return 1;
        }
    }

    fclose(F);
    return -1;
}

/*-------------------------Ajout-------------------------*/
void ajout_Voiture()
{
    int num;
    FILE *F = fopen("voiure.txt", "a");
    if (F == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

init:
    printf("Veuillez entrer le numero de la nouvelle voiture : \n");
    scanf("%d", &num);
    fflush(stdin);

    if (recherche_Voiture(num) == 1) {
        printf("Le num?ro saisi existe d?j? dans notre base de donnees : \n");
        goto init;
    } else {
        voiture.code = num;
        printf("Marque : ");
        scanf("%s", voiture.marque);
        printf("Mod�le : ");
        scanf("%s", voiture.modele);
        printf("Nombre d'exemplaires total : ");
        scanf("%d", &voiture.nombreExemplairesTotal);
        printf("Nombre d'exemplaires disponibles : ");
        scanf("%d", &voiture.nombreExemplairesDisponibles);
        printf("Tarif journalier : ");
        scanf("%f", &voiture.tarifJournalier);
		fflush(stdin);
        fprintf(F, "%d %s %s %d %d %.2f\n", voiture.code, voiture.marque, voiture.modele,
                voiture.nombreExemplairesTotal, voiture.nombreExemplairesDisponibles, voiture.tarifJournalier);
        fclose(F);
        printf("L'ajout a ete effectue avec succ?s \n");
    }
}

 /*----------------------affichage d'une voiture-------------------------*/
void list_Voiture()
{
    int num;
    printf("Saisir le num�ro de la voiture � rechercher : \n");
    scanf("%d", &num);
    fflush(stdin);

    if (recherche_Voiture(num) == 1) {
        printf("Le numero saisi est bien enregistre dans notre base de donnees.\n");
        printf("Voulez-vous l'afficher (O/N) : ");
        getchar();  // clear newline left by scanf
        if (getchar() == 'O' || getchar() == 'o') {
            FILE *F = fopen("voiure.txt", "r");
            if (F == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            }

            while (fscanf(F, "%d %s %s %d %d %f", &voiture.code, voiture.marque, voiture.modele,
                          &voiture.nombreExemplairesTotal, &voiture.nombreExemplairesDisponibles, &voiture.tarifJournalier) != EOF) {
                if (voiture.code == num) {
                    printf("Code : %d\n", voiture.code);
                    printf("Marque : %s\n", voiture.marque);
                    printf("Mod�le : %s\n", voiture.modele);
                    printf("Nombre d'exemplaires total : %d\n", voiture.nombreExemplairesTotal);
                    printf("Nombre d'exemplaires disponibles : %d\n", voiture.nombreExemplairesDisponibles);
                    printf("Tarif journalier : %.2f\n", voiture.tarifJournalier);
                    fflush(stdin);
                }
            }
            fclose(F);
        }
    } else {
        printf("Le code de la voiture saisi n'existe pas.\n");
    }
}

/*-------------------------Suppression------------------------*/
void suppression_Voiture()
{
    int num;
    printf("Veuillez entrer le code de la voiture a supprimer : \n");
    scanf("%d", &num);
    fflush(stdin);

    if (recherche_Voiture(num) == 1) {
        printf("Voulez-vous la supprimer (O/N) : ");
        getchar();  // clear newline left by scanf
        if (getchar() == 'O' || getchar() == 'o' ) {
            FILE *F = fopen("voiure.txt", "r");
            FILE *tmp = fopen("tempo_voiture.txt", "w");

            if (F == NULL || tmp == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            }

            while (fscanf(F, "%d %s %s %d %d %f", &voiture.code, voiture.marque, voiture.modele,
                          &voiture.nombreExemplairesTotal, &voiture.nombreExemplairesDisponibles, &voiture.tarifJournalier) != EOF) {
                if (voiture.code != num) {
                    fprintf(tmp, "%d %s %s %d %d %.2f\n", voiture.code, voiture.marque, voiture.modele,
                            voiture.nombreExemplairesTotal, voiture.nombreExemplairesDisponibles, voiture.tarifJournalier);
                }
            }

            fclose(F);
            fclose(tmp);
            remove("voiture.txt");
            rename("tempo_voiture.txt", "./Données/voiture.txt");
            printf("Suppression avec succes.\n");
        }
    } else {
        printf("Le code de la voiture saisi n'existe pas : Suppression annulee.\n");
    }
}

/*-------------------------Modification-------------------------*/
void modification_Voiture()
{
    int num;
    printf("Veuillez entrer le code de la voiture a modifier : \n");
    scanf("%d", &num);
    fflush(stdin);

    if (recherche_Voiture(num) == 1) {
        printf("Voulez-vous la modifier (O/N) : ");
        getchar();  // clear newline left by scanf
        if (getchar() == 'O' || getchar() == 'o') {
            FILE *F = fopen("voiure.txt", "r");
            FILE *tmp = fopen("tempo_voiture.txt", "w");

            if (F == NULL || tmp == NULL) {
                perror("Erreur lors de l'ouverture du fichier");
                return;
            }

            while (fscanf(F, "%d %s %s %d %d %f", &voiture.code, voiture.marque, voiture.modele,
                          &voiture.nombreExemplairesTotal, &voiture.nombreExemplairesDisponibles, &voiture.tarifJournalier) != EOF) {
                if (voiture.code == num) {
                    printf("Marque : ");
                    scanf("%s", voiture.marque);
                    printf("Mod�le : ");
                    scanf("%s", voiture.modele);
                    printf("Nombre d'exemplaires total : ");
                    scanf("%d", &voiture.nombreExemplairesTotal);
                    printf("Nombre d'exemplaires disponibles : ");
                    scanf("%d", &voiture.nombreExemplairesDisponibles);
                    printf("Tarif journalier : ");
                    scanf("%f", &voiture.tarifJournalier);
                    fflush(stdin);
                }
                fprintf(tmp, "%d %s %s %d %d %.2f\n", voiture.code, voiture.marque, voiture.modele,
                        voiture.nombreExemplairesTotal, voiture.nombreExemplairesDisponibles, voiture.tarifJournalier);
            }

            fclose(F);
            fclose(tmp);
            remove("voiure.txt");
            rename("tempo_voiture.txt", "voiure.txt");
            printf("Modification avec succ?s.\n");
        } else {
            printf("Modification annulee.\n");
        }
    } else {
        printf("Le code de la voiture saisi n'existe pas.\n");
    }
}

/*-------------------------affichage-------------------------*/
void list_all_Voiture()
{
    FILE *F = fopen("voiure.txt", "r");
    if (F == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    printf("La liste des voitures est : \n");
    printf("CODE\tMARQUE\tMODELE\t NBRTT\tNBRDISPO\t TARIF\n");

    while (fscanf(F, "%d %s %s %d %d %f", &voiture.code, voiture.marque, voiture.modele,
                  &voiture.nombreExemplairesTotal, &voiture.nombreExemplairesDisponibles, &voiture.tarifJournalier) != EOF) {
        printf("%d\t %s\t %s\t %d\t %d\t %.2f\n", voiture.code, voiture.marque, voiture.modele,
               voiture.nombreExemplairesTotal, voiture.nombreExemplairesDisponibles, voiture.tarifJournalier);
    }

    fclose(F);
}


