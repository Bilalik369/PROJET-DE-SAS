#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// D�terminer le maximum 
#define MAX_TACHE 100
#define TITRE_LONGUEUR 100
#define DESCRIPTION_LONGUEUR 500

typedef enum { LOW, HIGH } Priorite;
typedef enum { INCOMPLETE, COMPLETE } Statut; // Ajout du statut

typedef struct {
    char titre[TITRE_LONGUEUR];
    char description[DESCRIPTION_LONGUEUR];
    char date[11]; // Format: YYYY-MM-DD
    Priorite priorite;
    Statut statut; // Ajout du statut
} Tache;

Tache taches[MAX_TACHE];
int compteur_taches = 0;

void ajouter_tache();
void afficher_taches();
void modifier_tache();
void supprimer_tache();
void filtrer_taches();
void trier_taches(); // D�claration de la fonction pour trier les t�ches
void afficher_menu();
void sauvegarder_donnees(); // D�claration de la fonction pour sauvegarder les donn�es

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
            case 6: trier_taches(); break; // Option pour trier les t�ches
            case 7: sauvegarder_donnees(); break; // Option pour sauvegarder les donn�es
            case 8: printf("Au revoir :\n"); break;
            default: printf("Choix invalide ;\n");
        }
    } while (choix != 8);
    return 0;
}

void afficher_menu() { 
    printf("\n=========== Menu de Gestion des T�ches ============\n");
    printf("1. Ajouter une t�che\n");
    printf("2. Afficher les t�ches\n");
    printf("3. Modifier une t�che\n");
    printf("4. Supprimer une t�che\n");
    printf("5. Filtrer les t�ches\n");
    printf("6. Ordonner les t�ches par date\n");
    printf("7. Sauvegarder les donn�es\n");
    printf("8. Quitter\n");
}

void ajouter_tache() {
    if (compteur_taches >= MAX_TACHE) {
        printf("Le nombre maximum de t�ches a �t� atteint.\n");
        return; 
    }

    Tache nouvelle_tache;
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

    int input_statut;
    printf("Statut (1 pour COMPLET, 0 pour INCOMPLET) : ");
    scanf("%d", &input_statut);
    nouvelle_tache.statut = (input_statut == 1) ? COMPLETE : INCOMPLETE;

    taches[compteur_taches++] = nouvelle_tache;
    printf("T�che ajout�e avec succ�s.\n");
}

void afficher_taches() {
    if (compteur_taches == 0) {
        printf("Aucune t�che � afficher.\n");
        return;
    }

    printf("\n========= Liste des t�ches =========\n");
    
    for (int i = 0; i < compteur_taches; i++) {
        printf("T�che %d :\n", i + 1);
        printf("  Titre : %s\n", taches[i].titre);
        printf("  Description : %s\n", taches[i].description);
        printf("  Date d'�ch�ance : %s\n", taches[i].date);
        printf("  Priorit� : %s\n", taches[i].priorite == HIGH ? "HIGH" : "LOW");
        printf("  Statut : %s\n", taches[i].statut == COMPLETE ? "COMPLET" : "INCOMPLET");
    }
}

void modifier_tache() {
    int index;
    afficher_taches();
    printf("Entrez le num�ro de la t�che � modifier : ");
    scanf("%d", &index);

    if (index < 1 || index > compteur_taches) {
        printf("Num�ro de t�che invalide.\n");
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
    
    printf("Nouvelle date d'�ch�ance : ");
    char nouveau_date[11];
    scanf(" %[^\n]", nouveau_date);
    if (strlen(nouveau_date) > 0) {
        strcpy(taches[index].date, nouveau_date);
    }
    
    int input_priorite;
    printf("Nouvelle priorit� (1 pour HIGH, 0 pour LOW, -1 pour conserver) : ");
    scanf("%d", &input_priorite);
    if (input_priorite == 1) {
        taches[index].priorite = HIGH;
    } else if (input_priorite == 0) {
        taches[index].priorite = LOW;
    }

    int input_statut;
    printf("Nouveau statut (1 pour COMPLET, 0 pour INCOMPLET, -1 pour conserver) : ");
    scanf("%d", &input_statut);
    if (input_statut == 1) {
        taches[index].statut = COMPLETE;
    } else if (input_statut == 0) {
        taches[index].statut = INCOMPLETE;
    }
    
    printf("T�che modifi�e avec succ�s.\n");
}

void supprimer_tache() {
    int index;
    afficher_taches();
    printf("Entrez le num�ro de la t�che � supprimer : ");
    scanf("%d", &index);
    
    if (index < 1 || index > compteur_taches) {
        printf("Num�ro de t�che invalide.\n");
        return;
    }

    index--;
    for (int i = index; i < compteur_taches - 1; i++) {
        taches[i] = taches[i + 1];
    }
    compteur_taches--;
    printf("T�che supprim�e avec succ�s!\n");
}

void filtrer_taches() {
    int input_priorite;
    printf("Filtrer par priorit� (1 pour HIGH, 0 pour LOW) : ");
    scanf("%d", &input_priorite);
    Priorite priorite_filtre = (input_priorite == 1) ? HIGH : LOW;

    printf("\n=== T�ches Filtr�es ===\n");
    for (int i = 0; i < compteur_taches; i++) {
        if (taches[i].priorite == priorite_filtre) {
            printf("T�che %d :\n", i + 1);
            printf("  Titre : %s\n", taches[i].titre);
            printf("  Description : %s\n", taches[i].description);
            printf("  Date d'�ch�ance : %s\n", taches[i].date);
            printf("  Priorit� : %s\n", taches[i].priorite == HIGH ? "HIGH" : "LOW");
            printf("  Statut : %s\n", taches[i].statut == COMPLETE ? "COMPLET" : "INCOMPLET");
        }
    }
}

void trier_taches() {
    // Impl�mentation simple du tri � bulles
    for (int i = 0; i < compteur_taches - 1; i++) {
        for (int j = 0; j < compteur_taches - i - 1; j++) {
            if (strcmp(taches[j].date, taches[j + 1].date) > 0) {
                Tache temp = taches[j];
                taches[j] = taches[j + 1];
                taches[j + 1] = temp;
            }
        }
    }
    printf("T�ches tri�es par date avec succ�s.\n");
}

void sauvegarder_donnees() {
    FILE *f = fopen("taches.txt", "w");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < compteur_taches; i++) {
        fprintf(f, "%s\n%s\n%s\n%d\n%d\n", 
                taches[i].titre,
                taches[i].description,
                taches[i].date,
                taches[i].priorite,
                taches[i].statut);
    }
    
    fclose(f);
    printf("Donn�es sauvegard�es avec succ�s dans taches.txt.\n");
}

