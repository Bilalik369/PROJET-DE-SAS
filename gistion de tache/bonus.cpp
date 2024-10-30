#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#difine MAX_TACHE 100
#difine TITRE_LENGUEUR 100
#define MAX_DESCRIPTION 500


typedef enum {COMPLIT , INCOMPLIT}Statut;
typedef enum {HIGH , LOW}Periorite;

typedef struct {
	char titre[TITRE_LENGUEUR];
	char description[MAX_DESCRIPTION];
	char date[11];  //format de (YYYY-MM-DD)
	Periorite periorite;
	Statut statut;
}Tache;

Tache taches[MAX_TACHE];
int compteur_tachesc = 0;

void ajouter_tache(); 
void afficher_taches();
void modifier_tache();
void supprimer_tache();
void filtrer_taches();
void trier_taches();   // declaration de la nouvelle fonction pour traie les taches 
void afficher_menu();
void sauvegarder_donnees(); // declaration de la nouvelle fonction sauvegarde des  donnes 


int main(){
	
	
	
	int choix;
	
	do{
		afficher_menu;
		printf("Choisier une option");
		scanf("%d", &chiox);
		
		switch(choix) {
			case 1: ajouter_tache;
			break;
			case 2: afficher_taches;
			break;
			case 3: modifier_tache;
			break;
			case 4: supprimer_tache;
			break;
			case 5: filtrer_taches;
			break;
			case 6: trier_taches; // option paur trier les taches
			break;
			case 7: sauvegarder_donnees; // option paur sauvgarde les donnes 
			break;
			case 8: printf("Au revoir :\n");
			default: printf("Choix invalide !\n");
			
			
		}while (choix != 8);
		return 0;
		
	}
}

