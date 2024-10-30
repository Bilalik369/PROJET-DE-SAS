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
int compteur_taches = 0;

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
	
	void ajouter_tache(){
		if(compteur_taches >= MAX_TACHE){
		printf("Le nombre maxumim des taches a ete attient .\n");
	    return ;
		}
		Tache nouvelle_tache;
		printf("Titre :");
		scanf(" %[^\n]" , nouvelle_tache.titre);
		printf("Descriprion :");
		scanf(" %[^\n]" , nouvelle_tache.description);
		printf("Date d'échance (YYYY-MM-DD)").
		scanf(" %[^\n]", nouvelle_tache.date);
		
		
		int input_periorite;
		printf("Periorite (1 pour HIGH , 0 pour LOW)").
		scanf("%d", &input_periorite);
		nouvelle_tache.periorite = (input_periorite == 1) ? HIGH : LOW;
		
		int input_statut;
		printf("Statut (1 pour COMPLIT, 0 pour INCOMPLIT)");
		scanf("%d", &input_statut);
		nouvelle_tache.statut = (input_statut == 1) ? COMPLIT : INCOMPLIT;
		taches[compteur_taches++] = nouvelle_tache
		printf("Tache ajouter avec succes .\n");
		
		
	}
	void afficher_taches(){
		if (compteur_taches == 0){
			printf("Accune tache a afficher");
			return;
		}
		printf("==========Liste des tâches==========");
		
		for(i = 0; i < compteur_taches;i++); {
		printf("Tache :\n", i + 1);
		printf("Titre :%s\n", taches[i].titre)
		printf("Description:%s\n", taches[i].description);
		printf("Date d'échance: %s\n", taches[i].date);
		printf("Periorite:%s\n", taches[i].periorite == HIGH ? "HIGH" : "LOW");
		printf("Statut:%s\n", taches[i].statut == COMPLIT ? "COMPLITE" : "INCOMPLET");
		}
	}
void modifier_tache(){
	int index;
	afficher_taches();
	printf("Entre le numero de tache a modifier .\n");
	scanf("%d", &index)
	
	if(index < 1 || index > compteur_taches){
		printf("le numero de tache invalide.\n");
		return;
	}
	index--;
	char nouveau_titre[TITRE_LENGUEUR]
	printf("Nouveau titre : ");
	scanf("%[^\n]", nouveau_titre);
	if(strlen(nouveau_titre) > 0) {
		strcpy(taches[index].titre, nouveau_titre);
	}
	printf("nouvelle description : ");
	char nouveau_description[MAX_DESCRIPTION];
	scanf("%[^\n]", nouveau_description);
	if(strlen(nouveau_description) > 0){
		strcpy(taches[index].description, nouveau_description);
	}
	printf("Nouvelle date d'écheance : ");
	char nouveau_date;
	scanf("%[^\n]", nouveau_date);
	if(strlen(nouveau_date) > 0){
	strcpy(taches[index].date, nouveau_date);
	}
	int input_periorite;
	printf("Nouvelle periorite (1 pour HIGH, 0 pour LOW )");
	scanf("%d",&input_periorite);
	if(input_periorite == 1){
		taches[index].periorite = HIGH; 
	}else if(input_periorite = 0){
		taches[index].description = LOW;
	}
	int input_statut;
	printf("Nouvelle statut(1 pour COMPLIT , 0 pour INCOMPLIT)");
	scanf("%d" ,&input_input_statut);
	if(input_statut = 1){
		taches[index].statut = COMPLIT;
	}else if(input_statut = 0){
		taches[index].statut = INCCOMPLIT;
	}
	printf("Tache modifie avec succes .\n");
}

