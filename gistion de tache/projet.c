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
            default: printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choix != 6);
    return 0;
    
    void afficher_Menu() { 
    printf("\n ============ Menu de Gestion des T�ches ============\n");
    printf("1. Ajouter une t�che\n");
    printf("2. Afficher les t�ches \n");
    printf("3. Modifier une t�che \n");
    printf("4. Supprimer une t�che\n");
    printf("5. Filtrer les t�ches\n");
    printf("6. Quitter\n");
}

void ajouter_tache() {
    if (compteur_taches >= MXA_TACHE) { 
        printf("Le nombre maximum de t�ches a �t� atteint.\n");
        return; 
    }

    tache nouvelle_tache;
    printf("Titre : ");
    scanf(" %[^\n]", nouvelle_tache.titre); 
    printf("Description : ");
    scanf(" %[^\n]", nouvelle_tache.description); 
    printf("Date d'�ch�ance (YYYY-MM-DD) : ");
    scanf(" %[^\n]", nouvelle_tache.date); 
    
    int input_priorite;
    printf("Priorit� (1 pour HIGH, 0 pour LOW) : ");
    scanf("%d", &input_priorite);
    nouvelle_tache.priorite = (input_priorite == 1) ? HIGH : LOW; 
    
    taches[compteur_taches++] = nouvelle_tache; 
    printf("T�che ajout�e avec succ�s \n");
}


    }

    tache nouvelle_tache;
    printf("Titre : ");
    scanf(" %[^\n]", nouvelle_tache.titre); // Correction ici: ajout d'un espace avant % pour ignorer les espaces
    printf("Description : ");
    scanf(" %[^\n]", nouvelle_tache.description); // Correction ici: ajout d'un espace avant % 
    printf("Date d'�ch�ance (YYYY-MM-DD) : ");
    scanf(" %[^\n]", nouvelle_tache.date); // Correction ici: usage de "date" au lieu de "date_echance"
    
    int input_priorite;
    printf("Priorit� (1 pour HIGH, 0 pour LOW) : ");
    scanf("%d", &input_priorite);
    nouvelle_tache.priorite = (input_priorite == 1) ? HIGH : LOW; 
    
    taches[compteur_taches++] = nouvelle_tache; 
    printf("T�che ajout�e avec succ�s \n");
}

void afficher_taches() {
    if (compteur_taches == 0) {
        printf("Aucune t�che � afficher.\n");
        return;
    }

    printf("\n========= Liste des t�ches =========\n");
    for (int i = 0; i < compteur_taches; i++) {
        printf("T�che %d :\n", i + 1);
        printf("Titre : %s\n", taches[i].titre); 
        printf("Description : %s\n", taches[i].description);
        printf("Date d'�ch�ance : %s\n", taches[i].date);
        printf("Priorit� : %s\n", taches[i].priorite == HIGH ? "HIGH" : "LOW"); 
    }
}

