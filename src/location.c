// src/location.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "location.h"

Location loc;
int client_existe(int numeroClient) {
    // Logique pour v�rifier si le client existe dans votre syst�me
    // Par exemple, v�rifier dans un fichier clients.txt ou une base de donn�es
    // Retourne 1 si le client existe, 0 sinon
    return 1; // Exemple : supposons que tous les clients existent pour l'instant
}

int voiture_disponible(int codeVoiture, char dateDebut[11], int nombreJours) {
    // Logique pour v�rifier la disponibilit� du v�hicule
    // Par exemple, v�rifier dans un fichier de locations ou une base de donn�es
    // Retourne 1 si la voiture est disponible, 0 sinon
    return 1; // Exemple : supposons que la voiture est toujours disponible pour l'instant
}

void ajout_Location() {
    FILE *F = fopen("./Données/location.txt", "a");
    if (F == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    
    printf("Num�ro client : ");
    scanf("%d", &loc.numeroClient);

    if (!client_existe(loc.numeroClient)) {
        printf("Client inexistant. Veuillez d'abord ajouter le client.\n");
        fclose(F);
        return;
    }

    printf("Code voiture : ");
    scanf("%d", &loc.codeVoiture);

    if (!voiture_disponible(loc.codeVoiture, loc.dateDebut, loc.nombreJours)) {
        printf("La voiture n'est pas disponible pour ces dates.\n");
        fclose(F);
        return;
    }

    printf("Date de d�but (jj/mm/aaaa) : ");
    scanf("%s", loc.dateDebut);
    printf("Nombre de jours : ");
    scanf("%d", &loc.nombreJours);
    printf("tarifJournalier journalier : ");
    scanf("%lf", &loc.tarifJournalier);
    loc.coutTotal = loc.nombreJours * loc.tarifJournalier;
    strcpy(loc.etat, "En cours");

    fprintf(F, "%d %d %s %d %.2lf %.2lf %s\n", loc.numeroClient, loc.codeVoiture,
            loc.dateDebut, loc.nombreJours, loc.tarifJournalier, loc.coutTotal, loc.etat);
    fclose(F);

    printf("Location ajout�e avec succ�s.\n");
}

   
void list_all_Location() {
    FILE *F = fopen("./Données/location.txt", "r");
    if (F == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    
    printf("Liste des locations :\n");
    printf("Client\tVoiture\tDate d�but\tJours\ttarifJournalier\tCo�t total\t�tat\n");

    while (fscanf(F, "%d %d %s %d %lf %lf %s", &loc.numeroClient, &loc.codeVoiture,
                  loc.dateDebut, &loc.nombreJours, &loc.tarifJournalier, &loc.coutTotal, loc.etat) != EOF) {
        printf("%d\t%d\t%s\t%d\t%.2lf\t%.2lf\t%s\n", loc.numeroClient, loc.codeVoiture,
               loc.dateDebut, loc.nombreJours, loc.tarifJournalier, loc.coutTotal, loc.etat);
    }

    fclose(F);
}
