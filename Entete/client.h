// include/client.h
#ifndef CLIENT_H
#define CLIENT_H

typedef struct {
    int numero;
    char nom[50];
    char profession[50];
} Client;

int recherche_Client(int alpha_rech);
void ajout_Client();
void list_Client();
void suppression_Client();
void modification_Client();
void list_all_Client();


#endif // CLIENT_H
