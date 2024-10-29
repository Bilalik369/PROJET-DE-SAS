#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déterminer le maximum 
#define MAX_TACHE 100
#define TITRE_LONGUEUR 100
#define DESCRIPTION_LONGUEUR 500

typedef enum { LOW, HIGH } Priorite;

typedef struct {
    char titre[TITRE_LONGUEUR];
    char description[DESCRIPTION_LONGUEUR];
    char date[11]; // Format: YYYY-MM-DD
    Priorite priorite;
} Tache;

Tache taches[MAX_TACHE];
int compteur_taches = 0;

void ajouter_tache();
void afficher_taches();
void modifier_tache();
void supprimer_tache();
void filtrer_taches();
void afficher_menu();

int main() {
    int choix;

    do {
        afficher_menu();
        printf("Choisissez une option:\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouter_tache(); break;
            case 2: afficher_taches(); break;
            case 3: modifier_tache(); break;
            case 4: supprimer_tache(); break;
            case 5: filtrer_taches(); break;
            case 6: printf("Au revoir :\n"); break;
            default: printf("Choix invalide ;\n");
        }
    } while (choix != 6);
    return 0;
}

void afficher_menu() { 
    printf("\n=========== Menu de Gestion des Tâches ============\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher les tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Filtrer les tâches\n");
    printf("6. Quitter\n");
}

void ajouter_tache() {
    if (compteur_taches >= MAX_TACHE) {
        printf("Le nombre maximum de tâches a été atteint.\n");
        return; 
    }

    Tache nouvelle_tache;
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
    printf("Tâche ajoutée avec succès.\n");
}

void afficher_taches() {
    if (compteur_taches == 0) {
        printf("Aucune tâche à afficher.\n");
        return;
    }

    printf("\n========= Liste des tâches =========\n");
    
    for (int i = 0; i < compteur_taches; i++) {
        printf("Tâche %d :\n", i + 1);
        printf("  Titre : %s\n", taches[i].titre);
        printf("  Description : %s\n", taches[i].description);
        printf("  Date d'échéance : %s\n", taches[i].date);
        printf("  Priorité : %s\n", taches[i].priorite == HIGH ? "HIGH" : "LOW");
    }
}

void modifier_tache() {
    int index;
    afficher_taches();
    printf("Entrez le numéro de la tâche à modifier : ");
    scanf("%d", &index);

    if (index < 1 || index > compteur_taches) {
        printf("Numéro de tâche invalide.\n");
        return;
    }
    
    index--;
    printf("Nouveau titre : ");
    char nouveau_titre[TITRE_LONGUEUR];
    scanf(" %[^\n]", nouveau_titre);
    if (strlen(nouveau_titre) > 0) {
        strcpy(taches[index].titre, nouveau_titre);
    }
    
    printf("Nouvelle description : ");
    char nouveau_description[DESCRIPTION_LONGUEUR];
    scanf(" %[^\n]", nouveau_description);
    if (strlen(nouveau_description) > 0) {
        strcpy(taches[index].description, nouveau_description);
    }
    
    printf("Nouvelle date d'échéance : ");
    char nouveau_date[11];
    scanf(" %[^\n]", nouveau_date);
    if (strlen(nouveau_date) > 0) {
        strcpy(taches[index].date, nouveau_date);
    }
    
    int input_priorite;
    printf("Nouvelle priorité (1 pour HIGH, 0 pour LOW, -1 pour conserver) : ");
    scanf("%d", &input_priorite);
    if (input_priorite == 1) {
        taches[index].priorite = HIGH;
    } else if (input_priorite == 0) {
        taches[index].priorite = LOW;
    }
    
    printf("Tâche modifiée avec succès.\n");
}

void supprimer_tache() {
    int index;
    afficher_taches();
    printf("Entrez le numéro de la tâche à supprimer : ");
    scanf("%d", &index);
    
    if (index < 1 || index > compteur_taches) {
        printf("Numéro de tâche invalide.\n");
        return;
    }

    index--;
    for (int i = index; i < compteur_taches - 1; i++) {
        taches[i] = taches[i + 1];
    }
    compteur_taches--;
    printf("Tâche supprimée avec succès!\n");
}

void filtrer_taches() {
    int input_priorite;
    printf("Filtrer par priorité (1 pour HIGH, 0 pour LOW) : ");
    scanf("%d", &input_priorite);
    Priorite priorite_filtre = (input_priorite == 1) ? HIGH : LOW;

    printf("\n=== Tâches Filtrées ===\n");
    for (int i = 0; i < compteur_taches; i++) {
        if (taches[i].priorite == priorite_filtre) {
            printf("Tâche %d :\n", i + 1);
            printf("  Titre : %s\n", taches[i].titre);
            printf("  Description : %s\n", taches[i].description);
            printf("  Date d'échéance : %s\n", taches[i].date);
            printf("  Priorité : %s\n", taches[i].priorite == HIGH ? "HIGH" : "LOW");
        }
    }
}

