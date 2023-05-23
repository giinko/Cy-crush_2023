#include <stdio.h>
#include <string.h>

#include "..\header\menu.h"

param_struct_game changement_caractere(param_struct_game all_param5) {

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin3 = 1;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");

        // Rappel du sens de la gravite
        printf("Actuellement, il y a %d de symboles differents \n", all_param5.symbole);

        // Indication des differents choix disponible
        printf("[4] - Jouer avec 4 symboles differents \n"
               "[5] - Jouer avec 5 symboles differents \n"
               "[6] - Jouer avec 6 symboles differents \n"
               "[0] - Retourner vers les parametres \n");

        // Enregistrement du choix dans une variable c3 en caractère.
        printf("---> ");
        int c4 = getchar();

        // suppression des caracteres dans stdin
        if (c4 != '\n' && c4 != EOF) {
            int j;
            while ((j = getchar()) != '\n' && j != EOF);
        }

        // Etude du choix de l'utilisateur
        switch (c4) {

                // Joue avec 4 symboles
            case '4':
                all_param5.symbole = 4;
                fin3 = 0; // puis retour vers les parametres
                break;

                // Joue avec 5 symboles
            case '5':
                all_param5.symbole = 5;
                fin3 = 0; // puis retour vers les parametres
                break;

                // Joue avec 6 symboles
            case '6':
                all_param5.symbole = 6;
                fin3 = 0; // puis retour vers les parametres
                break;

                // Retour vers les parametres
            case '0':
                fin3 = 0;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3,4)
            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    }
    ecrir_parametre(all_param5);
    return all_param5;
};

param_struct_game changement_gravite(param_struct_game all_param4)
{

    // Declaration d'un tableau de caractère qui va traduire la gravité.
    char sens_gravite[20] = "vers la droite." ;

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin3 = 1;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3) {

        // Traduction de la valeur de la gravite (si 1 : vers le bas, sinon si 2 : vers la droite)
        if (all_param4.gravite == 1) {
            strcpy(sens_gravite, "vers le bas.");
        } else if (all_param4.gravite == 2) {
            strcpy(sens_gravite, "vers la droite.");
        }

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");

        // Rappel du sens de la gravite
        printf("Actuellement, le sens de la gravite est %s \n", sens_gravite);

        // Indication des differents choix disponible
        printf("[1] - Diriger vers le bas \n"
               "[2] - Diriger vers la droite \n"
               "[3] - Retourner vers les parametres \n");

        // Enregistrement du choix dans une variable c3 en caractère.
        printf("---> ");
        int c3 = getchar();

        // suppression des caracteres dans stdin
        if (c3 != '\n' && c3 != EOF) {
            int j;
            while ((j = getchar()) != '\n' && j != EOF);
        }

        // Etude du choix de l'utilisateur
        switch (c3) {

            // Vers le bas
            case '1':
                all_param4.gravite = 1;
                fin3 = 0; // puis retour vers les parametres
                break;

                // Vers la droite
            case '2':
                all_param4.gravite = 2;
                fin3 = 0; // puis retour vers les parametres
                break;

            // Retour vers les parametres
            case '3':
                fin3 = 0;
                break;

            // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    }
    return all_param4;
}


param_struct_game changement_taillegrille(param_struct_game all_param3) {

    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n" //CY CRUSH
           "   ______         ______                __  \n"
           "  / ____/_  __   / ____/______  _______/ /_ \n"
           " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
           "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
           "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
           "     /____/                                 \n\n");

    // Rappel de la taille de la grille avant de la modifier
    printf("Taille actuelle de la grille : %d en longueur, et %d en largeur.\n", all_param3.longueur, all_param3.largeur);

// indication des limites de la grille
    printf("(Merci de saisir des nombres compris entre 5 et 25)\n\n");

// Enregistrer la nouvelle taille en longueur
    printf("Nouvelle taille en longueur : ");
    scanf("%d", &all_param3.longueur);

// Vérification de la validité des nouvelles valeurs
    while ((all_param3.longueur < 5 ) || (all_param3.longueur > 25)) {
        printf("Longueur invalide. Merci de choisir un nombre entre 5 et 25.\n");
        printf("Nouvelle taille en longueur : ");
        scanf("%d", &all_param3.longueur);
    }
// Enregistrer la nouvelle taille en largeur
    printf("Nouvelle taille en largeur : ");
    scanf("%d", &all_param3.largeur);

// Vérification de la validité des nouvelles valeurs
    while ((all_param3.largeur < 5 ) || (all_param3.largeur > 25)) {
        printf("Largeur invalide. Merci de choisir un nombre entre 5 et 25.\n");
        printf("Nouvelle taille en largeur : ");
        scanf("%d", &all_param3.largeur);
    }

    //récupère le dernier caractère pour éviter la regénération du menu.
    char stop = getchar();

    // sauvegarde les paramètres dans le dossier paramètre
    ecrir_parametre(all_param3);

    // retour des nouveaux parametres
    return all_param3 ;
}


param_struct_game parametres(param_struct_game all_param) {

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1;

    param_struct_game all_param2 = all_param;

    // tant que fin2 = 0 : (si fin2 = 1 alors c'est la fin de la boucle).
    while (fin2) {
        int c2;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
/*
        if(all_param != all_param2){
            printf("Changements correctements enresgitrés");
        } */

        printf("\n\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");

        // Menu des parametres
        printf("Parametres : \n");
        printf("[1] - Changer la taille de la grille\n"
               "[2] - Changer le sens de gravite\n"
               "[3] - Changer le nombre de symboles\n"
               "[4] - Quitter les parametres\n");

        // Enregistrement du choix (dans c2) en caractère.
        printf("---> ");
        c2 = getchar();

        /* suppression des caracteres dans stdin */
        if (c2 != '\n' && c2 != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }

        switch (c2) {

            // Entre dans le menu changement de la taille de la grille
            case '1':
                all_param2 = changement_taillegrille(all_param);
                break;

            // Entre dans le menu changement de sens de gravité.
            case '2':
                all_param2 = changement_gravite(all_param);
                break;

            // Entre dans le menu changement du nombre des caracteres (4 par defaut)
            case '3':
                all_param2 = changement_caractere(all_param);
                break;

            // Fais quitter l'utilisateur si il fait 4
            case '4':
                fin2 = 0;
                break;

            // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3,4)
            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
        all_param = all_param2;
    }
    return all_param;
}


int menu(param_struct_game all_param1) {

// Déclaration de la variable fin, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin = 1;

    param_struct_game all_param2;

// tant que fin = 1 : (si fin = 0 alors c'est la fin de la boucle).
    while (fin) {

        int c;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                  \n\n");

        // Menu principal
        printf("[1] - Lancer le jeu\n"
               "[2] - Parametres\n"
               "[3] - Charger une grille\n"
               "[4] - Quitter\n");

        // Enregistrement du choix (dans c2) en caractère.
        printf("---> ");
        c = getchar();

        /* suppression des caracteres dans stdin */
        if (c != '\n' && c != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }


        // Etude du choix de l'utilisateur
        switch (c) {
            // Lance le jeu à l'aide du return 1.
            case '1':
                return 1;

                //
            case '2':
                all_param2 = parametres(all_param1);
                all_param1 = all_param2;
                break;

                //
            case '3':
                printf(" == En cours de dev ... == \n");
                printf(" == En cours de dev ... == \n");
                printf(" == En cours de dev ... == \n");
                printf(" == En cours de dev ... == \n");
                printf(" == En cours de dev ... == \n");
                break;

                // Fais quitter l'utilisateur (fin de la boucle activé)
            case '4':
                fin = 0;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3,4)
            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    }
}