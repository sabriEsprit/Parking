#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parking.h"
#include "agent.h"
#include <gtk/gtk.h>
int VerifierIDUnique (char *filename, int id)
{
    FILE *f=NULL;
    f= fopen(filename, "r");
    Parking P;
    if (f == NULL) return 0;

    // Parcours du fichier pour vérifier si l'ID existe déjà
    else {
        while (fscanf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,&P.Id_agent,&P.id_parking,&P.c_postalp,P.villep,P.ruep,P.nature,&P.PaiementTPE,&P.PaiementCheques,&P.nb_places_std,&P.nb_places_std_dispo,&P.nb_places_elec,&P.nb_places_elec_dispo,\
                &P.lundi_o.heures, &P.lundi_o.minutes,&P.lundi_f.heures, &P.lundi_f.minutes,\
                &P.mardi_o.heures, &P.mardi_o.minutes,&P.mardi_f.heures,&P.mardi_f.minutes ,\
                &P.mercredi_o.heures,&P.mercredi_o.minutes, &P.mercredi_f.heures,&P.mercredi_f.minutes, \
                &P.jeudi_o.heures,&P.jeudi_o.minutes,&P.jeudi_f.heures,&P.jeudi_f.minutes, \
                 &P.vendredi_o.heures,&P.vendredi_o.minutes,&P.vendredi_f.heures,&P.vendredi_f.minutes, \
                 &P.samedi_o.heures,&P.samedi_o.minutes,&P.samedi_f.heures,&P.samedi_f.minutes, \
                 &P.dimanche_o.heures,&P.dimanche_o.minutes,&P.dimanche_f.heures,&P.dimanche_f.minutes,\
                  &P.o_dimanche, &P.f_dimanche,\
                 &P.abo_mensuel_std_dispo,&P.abo_mensuel_elec_dispo,&P.tarif_h_std,&P.tarif_j_std,&P.tarif_abo_std, \
                 &P.tarif_h_elec,&P.tarif_j_elec,&P.tarif_abo_elec)!=EOF) {


        if (P.id_parking == id) {
            fclose(f);
            return 0; // ID déjà existant
        }
    }
    fclose(f);
    return 1; // ID unique

    }


}


int AjouterParking(char *filename ,Parking P)
{
    int vID;
    FILE *f=NULL;
    f=fopen(filename, "a");
    vID=VerifierIDUnique(filename, P.id_parking);
    if(f==NULL)
    {
        return(0);
    }

    else{
         if(vID==1)
         {
        
                 // remplissage automatique des champs
                 P.nb_places_std_dispo=P.nb_places_std;
                 P.nb_places_elec_dispo=P.nb_places_elec;
                 if(P.nb_places_elec==0){ P.abo_mensuel_elec_dispo=0; P.tarif_abo_elec=0;P.tarif_j_elec=0; P.tarif_h_elec=0;}
                 

        fprintf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %.3f %.3f %.3f %.3f %.3f %.3f  \n" \
                ,-1,P.id_parking,P.c_postalp,P.villep,P.ruep,P.nature,P.PaiementTPE,P.PaiementCheques, \
                P.nb_places_std,P.nb_places_std_dispo,P.nb_places_elec,P.nb_places_elec_dispo,\
                P.lundi_o.heures, P.lundi_o.minutes,P.lundi_f.heures, P.lundi_f.minutes,\
                P.mardi_o.heures, P.mardi_o.minutes,P.mardi_f.heures,P.mardi_f.minutes, \
                P.mercredi_o.heures,P.mercredi_o.minutes, P.mercredi_f.heures,P.mercredi_f.minutes, \
                P.jeudi_o.heures,P.jeudi_o.minutes,P.jeudi_f.heures,P.jeudi_f.minutes, \
                 P.vendredi_o.heures,P.vendredi_o.minutes,P.vendredi_f.heures,P.vendredi_f.minutes, \
                 P.samedi_o.heures,P.samedi_o.minutes,P.samedi_f.heures,P.samedi_f.minutes, \
                 P.dimanche_o.heures,P.dimanche_o.minutes,P.dimanche_f.heures,P.dimanche_f.minutes,\
                  P.o_dimanche, P.f_dimanche,\
                  P.abo_mensuel_std_dispo,P.abo_mensuel_elec_dispo,P.tarif_h_std,P.tarif_j_std,P.tarif_abo_std, \
                 P.tarif_h_elec,P.tarif_j_elec,P.tarif_abo_elec);


        fclose(f);
        return(1);
         }
         else {
            
            fclose(f);
            return(0);
         }

    }


}





int ModifierParking( char * filename,  Parking NouveauP)
{
    int tr=0;
    Parking P, Pch;
    FILE *f =NULL;
    FILE *f2=NULL;

    f=fopen(filename, "r");
    f2=fopen("nouv.txt", "w");
    Pch=ChercherParking(filename,NouveauP.id_parking);
    if(Pch.id_parking==0)
    {  
      return tr;}

   else if(f!=NULL && f2!=NULL)
    {
       

        

        while (fscanf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,&P.Id_agent,&P.id_parking,&P.c_postalp,P.villep,P.ruep,P.nature,&P.PaiementTPE,&P.PaiementCheques,&P.nb_places_std,&P.nb_places_std_dispo,&P.nb_places_elec,&P.nb_places_elec_dispo,\
                &P.lundi_o.heures, &P.lundi_o.minutes,&P.lundi_f.heures, &P.lundi_f.minutes,\
                &P.mardi_o.heures, &P.mardi_o.minutes,&P.mardi_f.heures,&P.mardi_f.minutes ,\
                &P.mercredi_o.heures,&P.mercredi_o.minutes, &P.mercredi_f.heures,&P.mercredi_f.minutes, \
                &P.jeudi_o.heures,&P.jeudi_o.minutes,&P.jeudi_f.heures,&P.jeudi_f.minutes, \
                 &P.vendredi_o.heures,&P.vendredi_o.minutes,&P.vendredi_f.heures,&P.vendredi_f.minutes, \
                 &P.samedi_o.heures,&P.samedi_o.minutes,&P.samedi_f.heures,&P.samedi_f.minutes, \
                 &P.dimanche_o.heures,&P.dimanche_o.minutes,&P.dimanche_f.heures,&P.dimanche_f.minutes,\
                  &P.o_dimanche, &P.f_dimanche,\
                 &P.abo_mensuel_std_dispo,&P.abo_mensuel_elec_dispo,&P.tarif_h_std,&P.tarif_j_std,&P.tarif_abo_std, \
                 &P.tarif_h_elec,&P.tarif_j_elec,&P.tarif_abo_elec)!=EOF)
        {
            if(P.id_parking==NouveauP.id_parking)
            {    NouveauP.nb_places_std_dispo=NouveauP.nb_places_std;
                 NouveauP.nb_places_elec_dispo=NouveauP.nb_places_elec;
                 if(NouveauP.nb_places_elec==0){ NouveauP.abo_mensuel_elec_dispo=0; NouveauP.tarif_abo_elec=0;NouveauP.tarif_j_elec=0; NouveauP.tarif_h_elec=0;}

fprintf(f2,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %.3f %.3f %.3f %.3f %.3f %.3f  \n" \
                ,NouveauP.Id_agent,NouveauP.id_parking,NouveauP.c_postalp,NouveauP.villep,NouveauP.ruep,NouveauP.nature,NouveauP.PaiementTPE,NouveauP.PaiementCheques, \
                NouveauP.nb_places_std,NouveauP.nb_places_std_dispo,NouveauP.nb_places_elec,NouveauP.nb_places_elec_dispo,\
                NouveauP.lundi_o.heures, NouveauP.lundi_o.minutes,NouveauP.lundi_f.heures, NouveauP.lundi_f.minutes,\
                NouveauP.mardi_o.heures, NouveauP.mardi_o.minutes,NouveauP.mardi_f.heures,NouveauP.mardi_f.minutes, \
                NouveauP.mercredi_o.heures,NouveauP.mercredi_o.minutes, NouveauP.mercredi_f.heures,NouveauP.mercredi_f.minutes, \
                NouveauP.jeudi_o.heures,NouveauP.jeudi_o.minutes,NouveauP.jeudi_f.heures,NouveauP.jeudi_f.minutes, \
                 NouveauP.vendredi_o.heures,NouveauP.vendredi_o.minutes,NouveauP.vendredi_f.heures,NouveauP.vendredi_f.minutes, \
                 NouveauP.samedi_o.heures,NouveauP.samedi_o.minutes,NouveauP.samedi_f.heures,NouveauP.samedi_f.minutes, \
                 NouveauP.dimanche_o.heures,NouveauP.dimanche_o.minutes,NouveauP.dimanche_f.heures,NouveauP.dimanche_f.minutes,\
                  NouveauP.o_dimanche, NouveauP.f_dimanche,\
                  NouveauP.abo_mensuel_std_dispo,NouveauP.abo_mensuel_elec_dispo,NouveauP.tarif_h_std,NouveauP.tarif_j_std,NouveauP.tarif_abo_std, \
                 NouveauP.tarif_h_elec,NouveauP.tarif_j_elec,NouveauP.tarif_abo_elec);





                tr=1;
            }
            else
   fprintf(f2,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %.3f %.3f %.3f %.3f %.3f %.3f  \n" \
                ,P.Id_agent,P.id_parking,P.c_postalp,P.villep,P.ruep,P.nature,P.PaiementTPE,P.PaiementCheques, \
                P.nb_places_std,P.nb_places_std_dispo,P.nb_places_elec,P.nb_places_elec_dispo,\
                P.lundi_o.heures, P.lundi_o.minutes,P.lundi_f.heures, P.lundi_f.minutes,\
                P.mardi_o.heures, P.mardi_o.minutes,P.mardi_f.heures,P.mardi_f.minutes, \
                P.mercredi_o.heures,P.mercredi_o.minutes, P.mercredi_f.heures,P.mercredi_f.minutes, \
                P.jeudi_o.heures,P.jeudi_o.minutes,P.jeudi_f.heures,P.jeudi_f.minutes, \
                 P.vendredi_o.heures,P.vendredi_o.minutes,P.vendredi_f.heures,P.vendredi_f.minutes, \
                 P.samedi_o.heures,P.samedi_o.minutes,P.samedi_f.heures,P.samedi_f.minutes, \
                 P.dimanche_o.heures,P.dimanche_o.minutes,P.dimanche_f.heures,P.dimanche_f.minutes,\
                  P.o_dimanche, P.f_dimanche,\
                  P.abo_mensuel_std_dispo,P.abo_mensuel_elec_dispo,P.tarif_h_std,P.tarif_j_std,P.tarif_abo_std, \
                 P.tarif_h_elec,P.tarif_j_elec,P.tarif_abo_elec);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int AfficherParking(char *filename)
{
    FILE *f=NULL;
    Parking P;
    f= fopen(filename, "r");
    if (f == NULL) return 0;
    else
    { while (fscanf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,&P.Id_agent,&P.id_parking,&P.c_postalp,P.villep,P.ruep,P.nature,&P.PaiementTPE,&P.PaiementCheques,&P.nb_places_std,&P.nb_places_std_dispo,&P.nb_places_elec,&P.nb_places_elec_dispo,\
                &P.lundi_o.heures, &P.lundi_o.minutes,&P.lundi_f.heures, &P.lundi_f.minutes,\
                &P.mardi_o.heures, &P.mardi_o.minutes,&P.mardi_f.heures,&P.mardi_f.minutes ,\
                &P.mercredi_o.heures,&P.mercredi_o.minutes, &P.mercredi_f.heures,&P.mercredi_f.minutes, \
                &P.jeudi_o.heures,&P.jeudi_o.minutes,&P.jeudi_f.heures,&P.jeudi_f.minutes, \
                 &P.vendredi_o.heures,&P.vendredi_o.minutes,&P.vendredi_f.heures,&P.vendredi_f.minutes, \
                 &P.samedi_o.heures,&P.samedi_o.minutes,&P.samedi_f.heures,&P.samedi_f.minutes, \
                 &P.dimanche_o.heures,&P.dimanche_o.minutes,&P.dimanche_f.heures,&P.dimanche_f.minutes\
                 , &P.abo_mensuel_std_dispo,&P.abo_mensuel_elec_dispo,&P.tarif_h_std,&P.tarif_j_std,&P.tarif_abo_std, \
                 &P.tarif_h_elec,&P.tarif_j_elec,&P.tarif_abo_elec)!=EOF)

                 {
                printf("*********************\n");

                printf("Id agent :%d\t Id_parking:%d \t code postal:%d \t ville:%s \t rue: %s\t nature: %s\t \
                       Paiement TPE:%d \tPaiement cache %d\t nbre plces std: %d\t nbre plces std dispo %d\t nbre plces elec: %d \tnbre plces elec dipso %d\t \
                       ho lundi: %d:%d\t hf lundi: %d:%d \t ho mardi: %d:%d\t hf mardi: %d:%d\t ho mercredi:%d:%d\t hf mercredi %d:%d\t ho jeudi: %d:%d\t hf jeudi %d:%d\t ho vendredi: %d:%d \t \
                       hf vendredi: %d:%d \t ho samedi: %d:%d\t hf samedi: %d:%d\t ho dimanche: %d:%d\t hf dimanche: %d:%d\t abonement mensu std %d\t abonement mensu elec %d\t tarif h std: %.3f\t tarif j std %.3f \t tarif ab std %.3f\t tarif h elec %.3f \t tarif j elec %.3f\t tarif ab mens elec :%.3f\t  \n" \
                ,P.Id_agent,P.id_parking,P.c_postalp,P.villep,P.ruep,P.nature,P.PaiementTPE,P.PaiementCheques,P.nb_places_std,P.nb_places_std_dispo,P.nb_places_elec,P.nb_places_elec_dispo,\
                P.lundi_o.heures, P.lundi_o.minutes,P.lundi_f.heures, P.lundi_f.minutes,\
                P.mardi_o.heures, P.mardi_o.minutes,P.mardi_f.heures,P.mardi_f.minutes, \
                P.mercredi_o.heures,P.mercredi_o.minutes, P.mercredi_f.heures,P.mercredi_f.minutes, \
                P.jeudi_o.heures,P.jeudi_o.minutes,P.jeudi_f.heures,P.jeudi_f.minutes, \
                 P.vendredi_o.heures,P.vendredi_o.minutes,P.vendredi_f.heures,P.vendredi_f.minutes, \
                 P.samedi_o.heures,P.samedi_o.minutes,P.samedi_f.heures,P.samedi_f.minutes, \
                 P.dimanche_o.heures,P.dimanche_o.minutes,P.dimanche_f.heures,P.dimanche_f.minutes\
                 , P.abo_mensuel_std_dispo,P.abo_mensuel_elec_dispo,P.tarif_h_std,P.tarif_j_std,P.tarif_abo_std, \
                 P.tarif_h_elec,P.tarif_j_elec,P.tarif_abo_elec);
                 printf("*********************\n");


                 }




    } return 1;

}

int SupprimerParking(char * filename, int id)
{
    int tr=0;
    Parking P;
    FILE * f=NULL;
    FILE * f2=NULL;
    f= fopen(filename, "r");
    f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        // while(fscanf(f,"%d %d %s %s %s\n",&P.sb_id_parking,&P.sb_c_postalp,P.sb_villep,P.sb_ruep,P.nature)!=EOF)
       while (fscanf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,&P.Id_agent,&P.id_parking,&P.c_postalp,P.villep,P.ruep,P.nature,&P.PaiementTPE,&P.PaiementCheques,&P.nb_places_std,&P.nb_places_std_dispo,&P.nb_places_elec,&P.nb_places_elec_dispo,\
                &P.lundi_o.heures, &P.lundi_o.minutes,&P.lundi_f.heures, &P.lundi_f.minutes,\
                &P.mardi_o.heures, &P.mardi_o.minutes,&P.mardi_f.heures,&P.mardi_f.minutes ,\
                &P.mercredi_o.heures,&P.mercredi_o.minutes, &P.mercredi_f.heures,&P.mercredi_f.minutes, \
                &P.jeudi_o.heures,&P.jeudi_o.minutes,&P.jeudi_f.heures,&P.jeudi_f.minutes, \
                 &P.vendredi_o.heures,&P.vendredi_o.minutes,&P.vendredi_f.heures,&P.vendredi_f.minutes, \
                 &P.samedi_o.heures,&P.samedi_o.minutes,&P.samedi_f.heures,&P.samedi_f.minutes, \
                 &P.dimanche_o.heures,&P.dimanche_o.minutes,&P.dimanche_f.heures,&P.dimanche_f.minutes,\
                  &P.o_dimanche, &P.f_dimanche,\
                 &P.abo_mensuel_std_dispo,&P.abo_mensuel_elec_dispo,&P.tarif_h_std,&P.tarif_j_std,&P.tarif_abo_std, \
                 &P.tarif_h_elec,&P.tarif_j_elec,&P.tarif_abo_elec)!=EOF)
        {
            if(P.id_parking== id)
                tr=1;
            else
                // fprintf(f2,"%d %d %s %s %s\n",P.sb_id_parking,P.sb_c_postalp,P.sb_villep,P.sb_ruep,P.nature);
                fprintf(f2,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %.3f %.3f %.3f %.3f %.3f %.3f  \n" \
                ,P.Id_agent,P.id_parking,P.c_postalp,P.villep,P.ruep,P.nature,P.PaiementTPE,P.PaiementCheques, \
                P.nb_places_std,P.nb_places_std_dispo,P.nb_places_elec,P.nb_places_elec_dispo,\
                P.lundi_o.heures, P.lundi_o.minutes,P.lundi_f.heures, P.lundi_f.minutes,\
                P.mardi_o.heures, P.mardi_o.minutes,P.mardi_f.heures,P.mardi_f.minutes, \
                P.mercredi_o.heures,P.mercredi_o.minutes, P.mercredi_f.heures,P.mercredi_f.minutes, \
                P.jeudi_o.heures,P.jeudi_o.minutes,P.jeudi_f.heures,P.jeudi_f.minutes, \
                 P.vendredi_o.heures,P.vendredi_o.minutes,P.vendredi_f.heures,P.vendredi_f.minutes, \
                 P.samedi_o.heures,P.samedi_o.minutes,P.samedi_f.heures,P.samedi_f.minutes, \
                 P.dimanche_o.heures,P.dimanche_o.minutes,P.dimanche_f.heures,P.dimanche_f.minutes,\
                  P.o_dimanche, P.f_dimanche,\
                  P.abo_mensuel_std_dispo,P.abo_mensuel_elec_dispo,P.tarif_h_std,P.tarif_j_std,P.tarif_abo_std, \
                 P.tarif_h_elec,P.tarif_j_elec,P.tarif_abo_elec);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

Parking ChercherParking(char * filename, int id)
{
    Parking P ;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && (fscanf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,&P.Id_agent,&P.id_parking,&P.c_postalp,P.villep,P.ruep,P.nature,&P.PaiementTPE,&P.PaiementCheques,&P.nb_places_std,&P.nb_places_std_dispo,&P.nb_places_elec,&P.nb_places_elec_dispo,\
                &P.lundi_o.heures, &P.lundi_o.minutes,&P.lundi_f.heures, &P.lundi_f.minutes,\
                &P.mardi_o.heures, &P.mardi_o.minutes,&P.mardi_f.heures,&P.mardi_f.minutes ,\
                &P.mercredi_o.heures,&P.mercredi_o.minutes, &P.mercredi_f.heures,&P.mercredi_f.minutes, \
                &P.jeudi_o.heures,&P.jeudi_o.minutes,&P.jeudi_f.heures,&P.jeudi_f.minutes, \
                 &P.vendredi_o.heures,&P.vendredi_o.minutes,&P.vendredi_f.heures,&P.vendredi_f.minutes, \
                 &P.samedi_o.heures,&P.samedi_o.minutes,&P.samedi_f.heures,&P.samedi_f.minutes, \
                 &P.dimanche_o.heures,&P.dimanche_o.minutes,&P.dimanche_f.heures,&P.dimanche_f.minutes,\
                 &P.o_dimanche, &P.f_dimanche,\
                 &P.abo_mensuel_std_dispo,&P.abo_mensuel_elec_dispo,&P.tarif_h_std,&P.tarif_j_std,&P.tarif_abo_std, \
                 &P.tarif_h_elec,&P.tarif_j_elec,&P.tarif_abo_elec)!=EOF))
        {
            if(P.id_parking== id)
                tr=1;

        }
    }
    fclose(f);

    if(tr==0)

{
    Parking P0={0};
    return P0;
}

    return P;

}
// Fonction pour affecter un agent à un parking
/*int AffecterAgentParking(char * filename, int Id_parking, int ID_agent) {
    FILE *f=fopen(filename, "r");
    FILE *f2=fopen("nouv.txt", "w");
    int aff=0;
    Parking P;
    Parking Pr=ChercherParking(filename, Id_parking);

    if ( (Id_parking==Pr.id_parking) && Pr.Id_agent==-1) {
        Pr.Id_agent = ID_agent;
        if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,&P.Id_agent,&P.id_parking,&P.c_postalp,P.villep,P.ruep,P.nature,&P.PaiementTPE,&P.PaiementCheques,&P.nb_places_std,&P.nb_places_std_dispo,&P.nb_places_elec,&P.nb_places_elec_dispo,\
                &P.lundi_o.heures, &P.lundi_o.minutes,&P.lundi_f.heures, &P.lundi_f.minutes,\
                &P.mardi_o.heures, &P.mardi_o.minutes,&P.mardi_f.heures,&P.mardi_f.minutes ,\
                &P.mercredi_o.heures,&P.mercredi_o.minutes, &P.mercredi_f.heures,&P.mercredi_f.minutes, \
                &P.jeudi_o.heures,&P.jeudi_o.minutes,&P.jeudi_f.heures,&P.jeudi_f.minutes, \
                 &P.vendredi_o.heures,&P.vendredi_o.minutes,&P.vendredi_f.heures,&P.vendredi_f.minutes, \
                 &P.samedi_o.heures,&P.samedi_o.minutes,&P.samedi_f.heures,&P.samedi_f.minutes, \
                 &P.dimanche_o.heures,&P.dimanche_o.minutes,&P.dimanche_f.heures,&P.dimanche_f.minutes\
                 , &P.abo_mensuel_std_dispo,&P.abo_mensuel_elec_dispo,&P.tarif_h_std,&P.tarif_j_std,&P.tarif_abo_std, \
                 &P.tarif_h_elec,&P.tarif_j_elec,&P.tarif_abo_elec)!=EOF);
        {
            if(P.id_parking==Id_parking)
            {


            fprintf(f2,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,Pr.Id_agent,Pr.id_parking,Pr.c_postalp,P.villep,P.ruep,P.nature,Pr.PaiementTPE,Pr.PaiementCheques,Pr.nb_places_std,Pr.nb_places_std_dispo,Pr.nb_places_elec,Pr.nb_places_elec_dispo,\
                Pr.lundi_o.heures, Pr.lundi_o.minutes,Pr.lundi_f.heures, Pr.lundi_f.minutes,\
                Pr.mardi_o.heures, Pr.mardi_o.minutes,Pr.mardi_f.heures,Pr.mardi_f.minutes ,\
                Pr.mercredi_o.heures,Pr.mercredi_o.minutes, Pr.mercredi_f.heures,Pr.mercredi_f.minutes, \
                Pr.jeudi_o.heures,Pr.jeudi_o.minutes,Pr.jeudi_f.heures,Pr.jeudi_f.minutes, \
                 Pr.vendredi_o.heures,Pr.vendredi_o.minutes,Pr.vendredi_f.heures,Pr.vendredi_f.minutes, \
                 Pr.samedi_o.heures,Pr.samedi_o.minutes,Pr.samedi_f.heures,Pr.samedi_f.minutes, \
                 Pr.dimanche_o.heures,Pr.dimanche_o.minutes,Pr.dimanche_f.heures,Pr.dimanche_f.minutes\
                 , Pr.abo_mensuel_std_dispo,Pr.abo_mensuel_elec_dispo,Pr.tarif_h_std,Pr.tarif_j_std,Pr.tarif_abo_std, \
                 Pr.tarif_h_elec,Pr.tarif_j_elec,Pr.tarif_abo_elec);
                 aff=1;
                 }
            else
                fprintf(f2,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,P.Id_agent,P.id_parking,P.c_postalp,P.villep,P.ruep,P.nature,P.PaiementTPE,P.PaiementCheques,P.nb_places_std,P.nb_places_std_dispo,P.nb_places_elec,P.nb_places_elec_dispo,\
                P.lundi_o.heures, P.lundi_o.minutes,P.lundi_f.heures, P.lundi_f.minutes,\
                P.mardi_o.heures, P.mardi_o.minutes,P.mardi_f.heures,P.mardi_f.minutes ,\
                P.mercredi_o.heures,P.mercredi_o.minutes, P.mercredi_f.heures,P.mercredi_f.minutes, \
                P.jeudi_o.heures,P.jeudi_o.minutes,P.jeudi_f.heures,P.jeudi_f.minutes, \
                P.vendredi_o.heures,P.vendredi_o.minutes,P.vendredi_f.heures,P.vendredi_f.minutes, \
                P.samedi_o.heures,P.samedi_o.minutes,P.samedi_f.heures,P.samedi_f.minutes, \
                P.dimanche_o.heures,P.dimanche_o.minutes,P.dimanche_f.heures,P.dimanche_f.minutes\
                , P.abo_mensuel_std_dispo,P.abo_mensuel_elec_dispo,P.tarif_h_std,P.tarif_j_std,P.tarif_abo_std, \
                P.tarif_h_elec,P.tarif_j_elec,P.tarif_abo_elec);


        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
    }


    }
    else aff=0;

    return aff;
}*/
///////////
// chercher Agent
Agent chercherAgent(char * filename, char cin[60] )
{
    FILE *f=fopen(filename, "r");
    Agent agent ;
    int tr=0;
    
    if (f!=NULL)
    

    {
       


	
        while ((tr==0)&& (fscanf(f,"%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",
                  agent.id_parking,agent.first_name, agent.last_name, agent.birth_date.day, agent.birth_date.month, agent.birth_date.year,
                agent.civil_status, agent.cin, agent.phone_number, agent.email, agent.address, agent.job_title, agent.contract_duration) != EOF))
                {
                    if(strcmp(agent.cin, cin )==0)
                    {
                         tr=1;

                    }

                }


    }
    fclose(f);
    if(tr==1)
    {
        return agent;
    }
    else {

    Agent a0={0};

        return a0;
    }

}
//************************
int ModifierAgent( char * filename,  Agent NouveauA)
{
    int tr=0;
    Agent agent;
    FILE *f =NULL;
    FILE *f2=NULL;

    f=fopen(filename, "r");
    f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {




        while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",
                  agent.id_parking,agent.first_name, agent.last_name, agent.birth_date.day, agent.birth_date.month, agent.birth_date.year,
                agent.civil_status, agent.cin, agent.phone_number, agent.email, agent.address, agent.job_title, agent.contract_duration) != EOF)
        {
            if(strcmp(NouveauA.cin,agent.cin)==0)
            {

            fprintf(f2, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                  NouveauA.id_parking,NouveauA.first_name, NouveauA.last_name, NouveauA.birth_date.day, NouveauA.birth_date.month, NouveauA.birth_date.year,
                NouveauA.civil_status, NouveauA.cin, NouveauA.phone_number, NouveauA.email, NouveauA.address, NouveauA.job_title, NouveauA.contract_duration);

                tr=1;
            }
            else

             fprintf(f2, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
                  agent.id_parking,agent.first_name, agent.last_name, agent.birth_date.day, agent.birth_date.month, agent.birth_date.year,
                agent.civil_status, agent.cin, agent.phone_number, agent.email, agent.address, agent.job_title, agent.contract_duration);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
//***********************

// affecter agent aux parking
int AffecterAgentParking(char * filenamep,char * filenamea, int Id_parking, char ID_agent[60] ) {
    FILE *fp=fopen(filenamep, "r");
    //FILE *fp2=fopen("nouvp.txt", "w");
    FILE *fa=fopen(filenamea, "r");
    //FILE *fa2=fopen("nouva.txt", "w");
    int aff=0;
    int mp=0, ma=0;
    char txt[60]; // convertir entier en str

    Parking Pr=ChercherParking(filenamep, Id_parking); // chercher parking
    Agent Ar=chercherAgent(filenamea, ID_agent);
    
    
    if(fp!=NULL && fa!=NULL){
    //aff=atoi(Ar.cin);
  
    if((Pr.id_parking==Id_parking) && (strcmp(Ar.cin, ID_agent)==0))
    {
       
        Pr.Id_agent=atoi(ID_agent);
        sprintf(txt,"%d",Id_parking);
        strcpy(Ar.id_parking,txt);
        mp=ModifierParking(filenamep, Pr);
        ma=ModifierAgent(filenamea, Ar);
	aff=1;
        

    }
    }

        fclose(fp);
        fclose(fa);

    return aff;
}


//////////


int SupprimerAffectationAgentParking(char * filenamea,char * filenamep, int id_parking, char Id_agent[60]) {
    FILE *fa=fopen(filenamea, "r");
    FILE *fp=fopen(filenamep, "r");
    int sup;
    int supp, supa;
    Parking Pr=ChercherParking(filenamep, id_parking);
    Agent Ar=chercherAgent(filenamea,Id_agent  );
        if(fa!=NULL && fp!=NULL)
        {
            if((Pr.id_parking==id_parking)&& (strcmp(Ar.cin, Id_agent)==0)) // trouve
            {
                Pr.Id_agent=-1;
                strcpy(Ar.id_parking, "-1");
                supp=ModifierParking(filenamep,Pr );
                supa=ModifierAgent(filenamea, Ar);
                sup=1;
            }
            else
            {
                sup=0;


            }
        }
        fclose(fa);
        fclose(fp);
        return sup;

    }
                 enum
{
    IDPARKING,
    IDAGENT,
    VILLE,
    RUE,
    CODEP,
    LUNDI,
    MARDI,
    MERCREDI,
    JEUDI,
    VENDREDI,
    SAMEDI,
    DIMANCHE,
    NATURE,
    PAIEMENTTPE,
    PAIEMENTCHEQ,
    NBPST, //nb plce std
    NBPSTD,  // nb plce std dispo
    NBPE, //nb place elec
    NBPED,  //nb place elec dispo
    ABOSD,  //abo std dispo
    ABOED,  // abo elec dispo
    TABOS,  // TARIF abo std
    TARBOE,  // Tarif abo elec 
    THSTD,   // tarif horaire std
    TJSTD,  // tarif j std
    THELEC,  // tarif h elec
    TJELEC,  // Tarif j elec
    COLUMNS  
};
enum
{
    IDPARKINGA,
    FIRSTNAME,
    LASTNAME,
    BIRTHDATEY,
    BIRTHDATEM,
    BIRTHDATED,
    CIVILSTATUS,
    CIN,
    PONENUMBER,
    EMAIL,
    ADRESSE,
    JOBTITLE,
    CONTRACTDURATION,   
    COLUMNSA
};




void afficher_parking(GtkWidget *liste)
{
    // La fonction d'affichage de la liste$

GtkCellRenderer *renderer;
GtkTreeViewColumn *colummn;
GtkTreeIter iter;
GtkListStore *store;
char Lundi[20];
char Mardi[20];
char Mercredi[20];
char Jeudi[20];
char Vendredi[20];
char Samedi[20];
char Dimanche[20];
char PaiementTPEdisp[20];
char Paiementchequdisp[20];
char Abostddisp[20];
char Aboelecdisp[20];

Parking P;
store=NULL;

FILE *f;



    store = gtk_tree_view_get_model(liste);

    
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Id_parking", renderer, "text", IDPARKING, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Id_agent", renderer, "text", IDAGENT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Ville", renderer, "text", VILLE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Rue", renderer, "text", RUE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Code postal", renderer, "text", CODEP, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);
       
       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Lundi(GMT+1)", renderer, "text", LUNDI, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Mardi(GMT+1)", renderer, "text", MARDI, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Mercredi(GMT+1)", renderer, "text", MERCREDI, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);


       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Jeudi(GMT+1)", renderer, "text", JEUDI, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Vendredi(GMT+1)", renderer, "text", VENDREDI, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Sammedi(GMT+1)", renderer, "text", SAMEDI, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);


       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Dimanche(GMT+1)", renderer, "text", DIMANCHE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nature", renderer, "text", NATURE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Paiement TPE", renderer, "text", PAIEMENTTPE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Paiement cheque", renderer, "text", PAIEMENTCHEQ, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place std", renderer, "text", NBPST, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place std dispo", renderer, "text", NBPSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place elec", renderer, "text", NBPE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place elec disp", renderer, "text", NBPED, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Abo std dispo", renderer, "text", ABOSD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Abo elec dispo", renderer, "text", ABOED, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif abo std ", renderer, "text", TABOS, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif abo elec ", renderer, "text", TARBOE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif horaire std ", renderer, "text", THSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif jour std ", renderer, "text", TJSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif horaire elec", renderer, "text", THELEC, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);


       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif jour elec", renderer, "text", TJELEC, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);
    }


    store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_STRING, G_TYPE_STRING,
                                G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT );
    f = fopen("parking.txt", "r");
    if (f == NULL)
    {
        return;
    }
    else
    {f = fopen("parking.txt", "a+");
    while (fscanf(f,"%d %d %d %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %f %f %f %f %f %f  \n" \
                ,&P.Id_agent,&P.id_parking,&P.c_postalp,P.villep,P.ruep,P.nature,&P.PaiementTPE,&P.PaiementCheques,&P.nb_places_std,&P.nb_places_std_dispo,&P.nb_places_elec,&P.nb_places_elec_dispo,\
                &P.lundi_o.heures, &P.lundi_o.minutes,&P.lundi_f.heures, &P.lundi_f.minutes,\
                &P.mardi_o.heures, &P.mardi_o.minutes,&P.mardi_f.heures,&P.mardi_f.minutes ,\
                &P.mercredi_o.heures,&P.mercredi_o.minutes, &P.mercredi_f.heures,&P.mercredi_f.minutes, \
                &P.jeudi_o.heures,&P.jeudi_o.minutes,&P.jeudi_f.heures,&P.jeudi_f.minutes, \
                 &P.vendredi_o.heures,&P.vendredi_o.minutes,&P.vendredi_f.heures,&P.vendredi_f.minutes, \
                 &P.samedi_o.heures,&P.samedi_o.minutes,&P.samedi_f.heures,&P.samedi_f.minutes, \
                 &P.dimanche_o.heures,&P.dimanche_o.minutes,&P.dimanche_f.heures,&P.dimanche_f.minutes,\
                  &P.o_dimanche, &P.f_dimanche,\
                 &P.abo_mensuel_std_dispo,&P.abo_mensuel_elec_dispo,&P.tarif_h_std,&P.tarif_j_std,&P.tarif_abo_std, \
                 &P.tarif_h_elec,&P.tarif_j_elec,&P.tarif_abo_elec)!=EOF)
    {
        
char PaiementTPEdisp[20];
char Paiementchequdisp[20];
char Abostddisp[20];
char Aboelecdisp[20];
        sprintf(Lundi, "%02d:%02d --> %02d:%02d", P.lundi_o.heures, P.lundi_o.minutes,P.lundi_f.heures,P.lundi_f.minutes);
        sprintf(Mardi, "%02d:%02d --> %02d:%02d", P.mardi_o.heures, P.mardi_o.minutes,P.mardi_f.heures,P.mardi_f.minutes);
        sprintf(Mercredi, "%02d:%02d --> %02d:%02d", P.mercredi_o.heures, P.mercredi_o.minutes,P.mercredi_f.heures,P.mercredi_f.minutes);
        sprintf(Jeudi, "%02d:%02d --> %02d:%02d", P.jeudi_o.heures, P.jeudi_o.minutes,P.jeudi_f.heures,P.jeudi_f.minutes);
        sprintf(Vendredi, "%02d:%02d --> %02d:%02d", P.vendredi_o.heures, P.vendredi_o.minutes,P.vendredi_f.heures,P.vendredi_f.minutes);
        sprintf(Samedi, "%02d:%02d --> %02d:%02d", P.samedi_o.heures, P.samedi_o.minutes,P.samedi_f.heures,P.samedi_f.minutes);
        sprintf(Dimanche, "%02d:%02d --> %02d:%02d", P.dimanche_o.heures, P.dimanche_o.minutes,P.dimanche_f.heures,P.dimanche_f.minutes);
          if(P.PaiementTPE==1) {strcpy(PaiementTPEdisp, "OUI");} else {strcpy(PaiementTPEdisp, "NON");}  
          if(P.PaiementCheques==1) {strcpy(Paiementchequdisp, "OUI");} else {strcpy(Paiementchequdisp, "NON");}
          if(P.abo_mensuel_std_dispo==1) {strcpy(Abostddisp, "OUI");} else {strcpy(Abostddisp, "NON");}
          if(P.abo_mensuel_elec_dispo==1) {strcpy(Aboelecdisp, "OUI");} else {strcpy(Aboelecdisp, "NON");}
          
    







        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, IDPARKING, P.id_parking, IDAGENT, P.Id_agent, VILLE, P.villep, RUE, P.ruep, CODEP, P.c_postalp,LUNDI,Lundi,
                           MARDI,Mardi, MERCREDI,Mercredi, JEUDI, Jeudi, VENDREDI, Vendredi, SAMEDI, Samedi, DIMANCHE, Dimanche, NATURE, P.nature
                           , PAIEMENTTPE,PaiementTPEdisp, PAIEMENTCHEQ, Paiementchequdisp,NBPST,P.nb_places_std, NBPSTD,P.nb_places_std_dispo,NBPE,P.nb_places_elec,
                            NBPED, P.nb_places_elec_dispo,ABOSD,Abostddisp,ABOED,Aboelecdisp,TABOS,P.tarif_abo_std,TARBOE,P.tarif_abo_elec,THSTD,P.tarif_h_std,
                    TJSTD,P.tarif_j_std,THELEC,P.tarif_h_elec,TJELEC,P.tarif_j_elec,      -1);
    }
    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    }
    
}



void afficher_parking_a_supprimer(GtkWidget *liste, Parking Ps)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *colummn;
    GtkTreeIter iter;
    GtkListStore *store;
char Lundi[20];
char Mardi[20];
char Mercredi[20];
char Jeudi[20];
char Vendredi[20];
char Samedi[20];
char Dimanche[20];
char PaiementTPEdisp[20];
char Paiementchequdisp[20];
char Abostddisp[20];
char Aboelecdisp[20];
    
    store = gtk_tree_view_get_model(liste);

    // Si le modèle n'est pas défini, on le crée
    if (store == NULL)
    {
        store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_STRING, G_TYPE_STRING,
                                G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT );
        
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

        // Ajouter les colonnes à la vue
        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Id_parking", renderer, "text", IDPARKING, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Id_agent", renderer, "text", IDAGENT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Ville", renderer, "text", VILLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Rue", renderer, "text", RUE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Code postal", renderer, "text", CODEP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Lundi(GMT+1)", renderer, "text", LUNDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Mardi(GMT+1)", renderer, "text", MARDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Mercredi(GMT+1)", renderer, "text", MERCREDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Jeudi(GMT+1)", renderer, "text", JEUDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Vendredi(GMT+1)", renderer, "text", VENDREDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Samedi(GMT+1)", renderer, "text", SAMEDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Dimanche(GMT+1)", renderer, "text", DIMANCHE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);


       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nature", renderer, "text", NATURE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Paiement TPE", renderer, "text", PAIEMENTTPE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Paiement cheque", renderer, "text", PAIEMENTCHEQ, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place std", renderer, "text", NBPST, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place std dispo", renderer, "text", NBPSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place elec", renderer, "text", NBPE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place elec disp", renderer, "text", NBPED, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Abo std dispo", renderer, "text", ABOSD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Abo elec dispo", renderer, "text", ABOED, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif abo std ", renderer, "text", TABOS, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif abo elec ", renderer, "text", TARBOE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif horaire std ", renderer, "text", THSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif jour std ", renderer, "text", TJSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif horaire elec", renderer, "text", THELEC, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);


       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif jour elec", renderer, "text", TJELEC, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);



    }

    // Vider le contenu actuel du GtkListStore (si nécessaire)
    // gtk_list_store_clear(store);

    // Si l'ID du parking est valide (non nul), on ajoute les informations de ce parking
    
        // Formater les horaires de chaque jour de la semaine
 
        sprintf(Lundi, "%02d:%02d --> %02d:%02d", Ps.lundi_o.heures, Ps.lundi_o.minutes, Ps.lundi_f.heures, Ps.lundi_f.minutes);
        sprintf(Mardi, "%02d:%02d --> %02d:%02d", Ps.mardi_o.heures, Ps.mardi_o.minutes, Ps.mardi_f.heures, Ps.mardi_f.minutes);
        sprintf(Mercredi, "%02d:%02d --> %02d:%02d", Ps.mercredi_o.heures, Ps.mercredi_o.minutes, Ps.mercredi_f.heures, Ps.mercredi_f.minutes);
        sprintf(Jeudi, "%02d:%02d --> %02d:%02d", Ps.jeudi_o.heures, Ps.jeudi_o.minutes, Ps.jeudi_f.heures, Ps.jeudi_f.minutes);
        sprintf(Vendredi, "%02d:%02d --> %02d:%02d", Ps.vendredi_o.heures, Ps.vendredi_o.minutes, Ps.vendredi_f.heures, Ps.vendredi_f.minutes);
        sprintf(Samedi, "%02d:%02d --> %02d:%02d", Ps.samedi_o.heures, Ps.samedi_o.minutes, Ps.samedi_f.heures, Ps.samedi_f.minutes);
        sprintf(Dimanche, "%02d:%02d --> %02d:%02d", Ps.dimanche_o.heures, Ps.dimanche_o.minutes, Ps.dimanche_f.heures, Ps.dimanche_f.minutes);
          if(Ps.PaiementTPE==1) {strcpy(PaiementTPEdisp, "OUI");} else {strcpy(PaiementTPEdisp, "NON");}  
          if(Ps.PaiementCheques==1) {strcpy(Paiementchequdisp, "OUI");} else {strcpy(Paiementchequdisp, "NON");}
          if(Ps.abo_mensuel_std_dispo==1) {strcpy(Abostddisp, "OUI");} else {strcpy(Abostddisp, "NON");}
          if(Ps.abo_mensuel_elec_dispo==1) {strcpy(Aboelecdisp, "OUI");} else {strcpy(Aboelecdisp, "NON");}

        // Ajouter les données du parking dans le store
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 
                           IDPARKING, Ps.id_parking, 
                           IDAGENT, Ps.Id_agent, 
                           VILLE, Ps.villep, 
                           RUE, Ps.ruep, 
                           CODEP, Ps.c_postalp,
                           LUNDI, Lundi,
                           MARDI, Mardi,
                           MERCREDI, Mercredi,
                           JEUDI, Jeudi,
                           VENDREDI, Vendredi,
                           SAMEDI, Samedi,
                           DIMANCHE, Dimanche,NATURE, Ps.nature
                           , PAIEMENTTPE,PaiementTPEdisp, PAIEMENTCHEQ, Paiementchequdisp,NBPST,Ps.nb_places_std, NBPSTD,Ps.nb_places_std_dispo,NBPE,Ps.nb_places_elec,
                            NBPED, Ps.nb_places_elec_dispo,ABOSD,Abostddisp,ABOED,Aboelecdisp,TABOS,Ps.tarif_abo_std,TARBOE,Ps.tarif_abo_elec,THSTD,Ps.tarif_h_std,
                    TJSTD,Ps.tarif_j_std,THELEC,Ps.tarif_h_elec,TJELEC,Ps.tarif_j_elec,
 
                           -1);
    
    // Libérer la référence du store
    
    g_object_unref(store);
}




void afficher_agent_non_affecter(GtkWidget *liste, char *filename)
{
    // La fonction d'affichage de la liste$

GtkCellRenderer *renderer;
GtkTreeViewColumn *colummn;
GtkTreeIter iter;
GtkListStore *store;
FILE *f =NULL;
f=fopen(filename, "r");
int k=0;
Agent agent;

//Parking P;
store=NULL;

    store = gtk_tree_view_get_model(liste);


    if (store == NULL)
    {


        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Id_parking", renderer, "text", IDPARKINGA, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);
        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", FIRSTNAME, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", LASTNAME, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Anne naissance", renderer, "text", BIRTHDATEY, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Mois naissance", renderer, "text", BIRTHDATEM, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Jour naissance", renderer, "text", BIRTHDATED , NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Etat civil", renderer, "text", CIVILSTATUS, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", CIN, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("num telephone", renderer, "text", PONENUMBER, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("mail", renderer, "text", EMAIL, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text", ADRESSE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("poste", renderer, "text", JOBTITLE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("duree contrat", renderer, "text", CONTRACTDURATION, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);






    }
   
        store = gtk_list_store_new(COLUMNSA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        while (fscanf(f, "%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^;];%59[^\n]\n",
                  agent.id_parking,agent.first_name, agent.last_name, agent.birth_date.day, agent.birth_date.month, agent.birth_date.year,
                agent.civil_status, agent.cin, agent.phone_number, agent.email, agent.address, agent.job_title, agent.contract_duration) != EOF)
        {
           
            if (strcmp(agent.id_parking, "-1")==0)
            {
                
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, IDPARKINGA, agent.id_parking,FIRSTNAME,agent.first_name,LASTNAME, agent.last_name,BIRTHDATEY,agent.birth_date.year,
                BIRTHDATEM,agent.birth_date.month,BIRTHDATED,agent.birth_date.day,CIVILSTATUS,agent.civil_status,CIN , agent.cin, PONENUMBER, agent.phone_number,
                EMAIL,agent.email, ADRESSE, agent.address,JOBTITLE,  agent.job_title, CONTRACTDURATION, agent.contract_duration,-1);
                k++;
            }

        }
     
     gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
     g_object_unref(store);
    


    if(k==0)
    {
    store = gtk_list_store_new(COLUMNSA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
    G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    }
 fclose(f);


}



void vider(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *colummn;
    GtkTreeIter iter;
    GtkListStore *store;

    store = NULL;

    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Id_parking", renderer, "text", IDPARKING, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Id_agent", renderer, "text", IDAGENT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Ville", renderer, "text", VILLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Rue", renderer, "text", RUE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Code postal", renderer, "text", CODEP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Lundi(GMT+1)", renderer, "text", LUNDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Mardi(GMT+1)", renderer, "text", MARDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Mercredi(GMT+1)", renderer, "text", MERCREDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Jeudi(GMT+1)", renderer, "text", JEUDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Vendredi(GMT+1)", renderer, "text", VENDREDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Samedi(GMT+1)", renderer, "text", SAMEDI, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
        colummn = gtk_tree_view_column_new_with_attributes("Dimanche(GMT+1)", renderer, "text", DIMANCHE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

         
        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nature", renderer, "text", NATURE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Paiement TPE", renderer, "text", PAIEMENTTPE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Paiement cheque", renderer, "text", PAIEMENTCHEQ, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place std", renderer, "text", NBPST, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

        renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place std dispo", renderer, "text", NBPSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place elec", renderer, "text", NBPE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Nbre place elec disp", renderer, "text", NBPED, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Abo std dispo", renderer, "text", ABOSD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Abo elec dispo", renderer, "text", ABOED, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif abo std ", renderer, "text", TABOS, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif abo elec ", renderer, "text", TARBOE, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif horaire std ", renderer, "text", THSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif jour std ", renderer, "text", TJSTD, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);

       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif horaire elec", renderer, "text", THELEC, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);


       renderer = gtk_cell_renderer_text_new();
       colummn = gtk_tree_view_column_new_with_attributes("Tarif jour elec", renderer, "text", TJELEC, NULL);
       gtk_tree_view_append_column(GTK_TREE_VIEW(liste), colummn);







    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,
                               G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_STRING, G_TYPE_STRING,
                                G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_FLOAT );
    //gtk_list_store_append(store,&iter);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    //g_object_unref(store);

}


int verifier (char login[], char password[])
{
    int verif=0;
    FILE *f=NULL;
    f= fopen("Utilisateur.txt", "r");
    Utilisateur u;
    while(fscanf(f, "%s %s %s %s %d",u.nom, u.prenom, u.login ,u.mdp, &u.role )!=EOF)
    {
        if(!strcmp(login,u.login)&&(!strcmp(password, u.mdp)))
            {
              if(u.role==1)
              {verif=1;}
              else {verif=2;}
            }
    }
    return (verif);

}




