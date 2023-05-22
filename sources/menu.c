#include <stdio.h>
#include <string.h>

#include "..\header\menu.h"

int changement_gravite(int* sgravite){

    char sens_gravite[20];
    int fin3 = 1;

    while (fin3) {

        if (*sgravite == 1) {
            strcpy(sens_gravite, "vers le bas");
        } else if (*sgravite == 2) {
            strcpy(sens_gravite, "vers la droite");
        } else if (*sgravite == 3) {
            strcpy(sens_gravite, "vers la gauche");
        } else if (*sgravite == 4) {
            strcpy(sens_gravite, "vers le haut");
        }

        printf("\n\n\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");

        printf("Sens actuel de la gravite : %s \n", sens_gravite);
        printf("[1] - Diriger vers le bas \n"
               "[2] - Diriger vers la droite \n"
               "[3] - Diriger vers la gauche \n"
               "[4] - Diriger vers le haut \n"
               "[5] - Retourner vers les parametres \n"
               "[6] - Retourner vers le menu principal \n");
        printf("Choix : ");

        int c3 = getchar();

        // suppression des caracteres dans stdin 
        if (c3 != '\n' && c3 != EOF) {
            int j;
            while ((j = getchar()) != '\n' && j != EOF);
        }

        switch (c3) {

            // Vers le bas
            case '1':
                *sgravite = 1;
                fin3 = 0;
                break;
            
            // Vers la droite
            case '2':
                *sgravite = 2;
                fin3 = 0;
                break;

            // Vers la gauche
            case '3':
                *sgravite = 3;
                fin3 = 0;
                break;

            // Vers le haut
            case '4':
                *sgravite = 4;
                fin3 = 0;
                break;

            // Retour vers les parametres
            case '5':
                fin3 = 0;
                break;

            // Retour vers le menu principal
            case '6':
                fin3 = 0;
                break;

            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    }
    return 1;
}


void changement_taillegrille(int longueur, int largeur) {

    printf("\n\n\n"
           "   ______         ______                __  \n"
           "  / ____/_  __   / ____/______  _______/ /_ \n"
           " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
           "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
           "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
           "     /____/                                 \n\n");

    printf("Taille actuelle de la grille : %d en longueur, et %d en largeur.\n", longueur, largeur);


    printf("(Merci de saisir des nombres compris entre 5 et 25)\n\n");

    printf("Nouvelle la taille en longueur : ");
    scanf("%d", longueur);

    while ((longueur < 5 ) || (longueur > 25)) {
        printf("Longueur invalide. Merci de choisir un nombre entre 5 et 25.\n");
        printf("Nouvelle taille en longueur : ");
        scanf("%d", pmc);
    }

    printf("Nouvelle taille en largeur : ");
    scanf("%d", largeur);

    while ((largeur < 5 ) || (largeur > 25)) {
        printf("Largeur invalide. Merci de choisir un nombre entre 5 et 25.\n");
        printf("Nouvelle taille en largeur : ");
        scanf("%d", largeur);
    }
}




void parametres(int* pnb, int* pmb, int * pgravite_b) {
    int fin2 = 0;

    while (!fin2) {
        int c2;

        /* affichage menu-paramètres */

        printf("\n\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");
        printf("Parametres : \n");
        printf("[1] - Changer la taille de la grille\n"
               "[2] - Changer le sens de gravite\n"
               "[3] - Activer/desactiver les jokers :\n"
               "[4] - Revenir au menu principal\n");

        printf("Choix : ");
        c2 = getchar();

        /* suppression des caracteres dans stdin */
        if (c2 != '\n' && c2 != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }

        switch (c2) {
            // changer la taille de la grille
            case '1':
                changement_taillegrille(pnb, pmb);
                break;
                // changer le sens de la gravité
            case '2':
                if(changement_gravite(pgravite_b) == 1){
                    fin2 = 1;
                }
                // Activer/désactiver Joker
            case '3':
                printf("Choix 3\n");
                fin2 = 1;
                break;
                // quitter
                break;
            case '4':
                fin2 = 1;
                break;
            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    }
}


int menu(int * pna, int * pma, int * pgravite_a){
    
    int fin = 1;
    while(fin)
    {
        int c;

        /* affichage menu */
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                  \n\n");
        printf("[1] - Lancer le jeu\n"
               "[2] - Parametres\n"
               "[3] - Charger une grille\n"
               "[4] - Quitter\n");

        printf("Choix : ");


        c = getchar();

        /* suppression des caracteres dans stdin */
        if(c != '\n' && c != EOF)
        {
            int d;
            while((d = getchar()) != '\n' && d != EOF);
        }

        switch(c)
        {
            case '1':
                return 1 ;

            case '2':
                parametres(pna, pma, pgravite_a);
                fin = 0;
                break;

            case '3':
                printf("Choix 3 en cours de dev\n");
                return 3;

            case '4':
                fin = 1;
                break;

            default:
                printf("Choix invalide, veuillez saisir un choix valide pour continuer.\n");
        }
    }
}