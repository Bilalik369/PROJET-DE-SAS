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
		}
			
		}while (choix != 8);
		return 0;
		
	}
	
	void afficher_menu(){
		printf("\n===========MENU DE GISTION DES TACHES==========\n");
		printf("1 . Ajouter une tache \n");
		printf("2 . Afficher les taches \n");
		printf("3 . Modifier une tache \n");
		printf("4 . Supprimer une tache \n");
		printf("5 . Filtrer les taches \n ");
		printf("6 . Ordoner les taches par date \n");
		printf("7 . Sauvgarder les donnees\n");
		printf("8 . Quitter \n");
		
	}
	


