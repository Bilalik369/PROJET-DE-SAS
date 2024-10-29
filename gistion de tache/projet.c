#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//determinr el maximo 
#define MXA_TACHE 100
#define TITRE_LONGUEUR 100
#define DESCRIPTION_LONGUEUR 500


typedef enum { LOW, HIGH} Priorite;

typedef struct {
	char titre[TITRE_LONGUEUR];
	char description[DESCRIPTION_LONGUEUR];
	char date [11];
	Priorite priorite;
} tache ;

 tache taches[MXA_TACHE];
int compteur_taches = 0	;


void ajouter_tache();
void afficher_taches();
void modifier_tache();
void supprimer_tache();
void filtrer_taches();
void afficher_Menu();

int main() {
    int choix;
    do {
        afficher_menu(); // Affiche le menu
        printf("Choisissez une option: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajouter_tache(); 
			break;
            case 2: afficher_taches(); 
			break;
            case 3: modifier_tache(); 
			break;
            case 4: supprimer_tache(); 
			break;
            case 5: filtrer_taches(); 
			break;
            case 6: printf("Au revoir!\n"); 
			break;
            default: printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);
    return 0;
    
    void afficher_Menu() { 
    printf("\n ============ Menu de Gestion des Tâches ============\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher les tâches \n");
    printf("3. Modifier une tâche \n");
    printf("4. Supprimer une tâche\n");
    printf("5. Filtrer les tâches\n");
    printf("6. Quitter\n");
}
