// include/voiture.h
#ifndef VOITURE_H
#define VOITURE_H

typedef struct {
    int code;
    char marque[50];
    char modele[50];
    int nombreExemplairesTotal;
    int nombreExemplairesDisponibles;
    float tarifJournalier;
} Voiture;

int recherche_Voiture(int alpha_rech);
void ajout_Voiture();
void list_Voiture();
void suppression_Voiture();
void modification_Voiture();
void list_all_Voiture();
void print_Menu_Voiture();
void manager_Voiture();

#endif // VOITURE_H
