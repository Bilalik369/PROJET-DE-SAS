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

void ajouter_tache() {
    if (compteur_taches >= MXA_TACHE) { 
        printf("Le nombre maximum de tâches a été atteint.\n");
        return; 
    }

    tache nouvelle_tache;
    printf("Titre : ");
    scanf(" %[^\n]", nouvelle_tache.titre); 
    printf("Description : ");
    scanf(" %[^\n]", nouvelle_tache.description); 
    printf("Date d'échéance (YYYY-MM-DD) : ");
    scanf(" %[^\n]", nouvelle_tache.date); 
    
    int input_priorite;
    printf("Priorité (1 pour HIGH, 0 pour LOW) : ");
    scanf("%d", &input_priorite);
    nouvelle_tache.priorite = (input_priorite == 1) ? HIGH : LOW; 
    
    taches[compteur_taches++] = nouvelle_tache; 
    printf("Tâche ajoutée avec succès \n");
}


    }

    tache nouvelle_tache;
    printf("Titre : ");
    scanf(" %[^\n]", nouvelle_tache.titre); // Correction ici: ajout d'un espace avant % pour ignorer les espaces
    printf("Description : ");
    scanf(" %[^\n]", nouvelle_tache.description); // Correction ici: ajout d'un espace avant % 
    printf("Date d'échéance (YYYY-MM-DD) : ");
    scanf(" %[^\n]", nouvelle_tache.date); // Correction ici: usage de "date" au lieu de "date_echance"
    
    int input_priorite;
    printf("Priorité (1 pour HIGH, 0 pour LOW) : ");
    scanf("%d", &input_priorite);
    nouvelle_tache.priorite = (input_priorite == 1) ? HIGH : LOW; 
    
    taches[compteur_taches++] = nouvelle_tache; 
    printf("Tâche ajoutée avec succès \n");
}

void afficher_taches() {
    if (compteur_taches == 0) {
        printf("Aucune tâche à afficher.\n");
        return;
    }

    printf("\n========= Liste des tâches =========\n");
    for (int i = 0; i < compteur_taches; i++) {
        printf("Tâche %d :\n", i + 1);
        printf("Titre : %s\n", taches[i].titre); 
        printf("Description : %s\n", taches[i].description);
        printf("Date d'échéance : %s\n", taches[i].date);
        printf("Priorité : %s\n", taches[i].priorite == HIGH ? "HIGH" : "LOW"); 
    }
}

