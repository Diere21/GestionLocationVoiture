// include/location.h
#ifndef LOCATION_H
#define LOCATION_H

typedef struct {
    int numeroClient;
    int codeVoiture;
    char dateDebut[11]; // Format "dd/mm/yyyy"
    int nombreJours;
    float tarifJournalier;
    float coutTotal;
    char etat[20]; // "réservée", "en cours", "terminée"
} Location;

int client_existe(int numeroClient);
int voiture_disponible(int codeVoiture, char dateDebut[11], int nombreJours);
void ajout_Location();
void list_all_Location();


#endif // LOCATION_H
