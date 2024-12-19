#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED
#include "agent.h"


typedef struct {
    char nom[20], prenom[20], login[20], mdp[20];
    int role;
}Utilisateur;


typedef struct {
    int heures;
    int minutes;
} Temps;
typedef struct
{
    int Id_agent;
    int id_parking;
    int c_postalp;
    char villep[20];
    char ruep[20];
    char nature[20];     // chaine de caractere
    int PaiementTPE;     // 1 oui 0 non
    int PaiementCheques; // 1 oui 0 non
    int nb_places_std;
    int nb_places_std_dispo;
    int nb_places_elec;
    int nb_places_elec_dispo;
    Temps lundi_o;
    Temps lundi_f;
    Temps mardi_o;
    Temps mardi_f;
    Temps mercredi_o;
    Temps mercredi_f;
    Temps jeudi_o;
    Temps jeudi_f;
    Temps vendredi_o;
    Temps vendredi_f;
    Temps samedi_o;
    Temps samedi_f;
    int o_dimanche;           // 1--> ouvert dimache
    int f_dimanche;           // 1--> ferme dimanche
    Temps dimanche_o;
    Temps dimanche_f;
    int abo_mensuel_std_dispo; // 1 oui 0 non
    int abo_mensuel_elec_dispo; // 1 oui 0 non
    float tarif_h_std;
    float tarif_j_std;
    float tarif_abo_std;
    float tarif_h_elec;
    float tarif_j_elec;
    float tarif_abo_elec;

}Parking;

int AjouterParking(char *filename ,Parking P);
int ModifierParking( char * filename, Parking NouveauP );
int AfficherParking(char *filename);
int verifierIDUnique(char *filename, int id);
int SupprimerParking(char * filename, int id);
Parking ChercherParking(char * filename, int id);
int AffecterAgentParking(char * filenamep,char * filenamea, int Id_parking, char ID_agent[60] );
Agent chercherAgent(char * filename, char ID_agent[60] );
int ModifierAgent( char * filename,  Agent NouveauA);
int AffecterAgentParking(char * filenamep,char * filenamea, int Id_parking, char ID_agent[60] );
int SupprimerAffectationAgentParking(char * filenamea,char * filenamep, int id_parking, char Id_agent[60]);
void afficher_agent_non_affecter(GtkWidget *liste, char *filename);
int verifier (char login[], char password[]);


#endif // PARKING_H_INCLUDED

