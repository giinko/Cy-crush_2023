#include <stdio.h>
#include <string.h>

#include "..\header\menu.h"

param_struct_game changement_caractere(param_struct_game all_param5) {

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin3 = 1;
    int d = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(d == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        d = 0;
        printf("\n"
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
               "[0] - Retourner vers les parametres \n\n");

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
                d = 1 ;
                break;
        }
    }
    ecrir_parametre(all_param5);
    return all_param5;
};

param_struct_game changement_gravite(param_struct_game all_param4)
{

    // Declaration d'un tableau de caractère qui va traduire la gravité.
    char sens_gravite[20];
    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin3 = 1;
    int c = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3) {

        // Traduction de la valeur de la gravite (si 1 : vers le bas, sinon si 2 : vers la droite)
        if (all_param4.gravite == 1) {
            strcpy(sens_gravite, "vers le bas.");
        } else if (all_param4.gravite == 2) {
            strcpy(sens_gravite, "vers la droite.");
        }

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(c == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        c = 0;
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");
        printf("Menu de changement de la gravite. \n");

        // Rappel du sens de la gravite
        printf("Actuellement, le sens de la gravite est %s \n\n", sens_gravite);
        // Indication des differents choix disponible
        printf("[1] - Diriger vers le bas \n"
               "[2] - Diriger vers la droite \n"
               "[3] - Retourner vers les parametres \n\n");

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
                return all_param4;

            // Vers la droite
            case '2':
                all_param4.gravite = 2;
                return all_param4;

            // Retour vers les parametres
            case '3':
                return all_param4;

            // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                c = 1 ;
                break;
        }
    }
}


param_struct_game changement_taillegrille(param_struct_game all_param3) {
    int fin3 = 1;
    int b = 0 ;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3) {

        // Enregistrement du choix dans une variable c3 en caractère.

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(b == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        b = 0;
        printf("\n" //CY CRUSH
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n\n");

        // Rappel de la taille de la grille avant de la modifier
        printf("Menu de changement de la taille de la grille. \n");
        printf("Actuellement, la taille de la grille est : \n\n");
        printf("Longueur : %d\n", all_param3.longueur);
        printf("Largeur : %d\n\n", all_param3.largeur);
        printf("Voulez-vous toujours changer la taille ?\n\n");
        printf("[1] - Oui \n"
               "[2] - Non, quitter \n\n");
        printf("---> ");

        int c6 = getchar();

        // suppression des caracteres dans stdin
        if (c6 != '\n' && c6 != EOF) {
            int e;
            while ((e = getchar()) != '\n' && e != EOF);
        }

        // Etude du choix de l'utilisateur
        switch (c6) {

            // Vers le bas
            case '1':
                printf("\nTres bien, veuillez entrer la nouvelle taille souhaitee.");

// indication des limites de la grille
                printf("(Merci de saisir des nombres compris entre 5 et 25)\n\n");

// Enregistrer la nouvelle taille en longueur
                printf("Nouvelle taille en longueur : ");
                scanf("%d", &all_param3.longueur);

// Vérification de la validité des nouvelles valeurs
                while ((all_param3.longueur < 5) || (all_param3.longueur > 25)) {
                    printf("\nLongueur invalide. Merci de choisir un nombre entre 5 et 25.\n\n");
                    printf("Nouvelle taille en longueur : ");
                    scanf("%d", &all_param3.longueur);
                }
// Enregistrer la nouvelle taille en largeur
                printf("Nouvelle taille en largeur : ");
                scanf("%d", &all_param3.largeur);

// Vérification de la validité des nouvelles valeurs
                while ((all_param3.largeur < 5) || (all_param3.largeur > 25)) {
                    printf("\nLargeur invalide. Merci de choisir un nombre entre 5 et 25.\n\n");
                    printf("Nouvelle taille en largeur : ");
                    scanf("%d", &all_param3.largeur);
                }
                //récupère le dernier caractère pour éviter la regénération du menu.
                char stop = getchar();

                // sauvegarde les paramètres dans le dossier paramètre
                ecrir_parametre(all_param3);

                return all_param3;

                // Vers la droite
            case '2':
                return all_param3;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                b = 1 ;
                break;
        }
    }
}


param_struct_game parametres(param_struct_game all_param) {

    param_struct_game all_param2 = all_param;

    char sensgravite[20];

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1;
    int a = 0;

    // tant que fin2 = 0 : (si fin2 = 1 alors c'est la fin de la boucle).
    while (fin2) {

        int c2;

        if (all_param2.gravite == 1) {
            strcpy(sensgravite, "vers le bas");
        } else if (all_param2.gravite == 2) {
            strcpy(sensgravite, "vers la droite");
        }

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        if(all_param.longueur != all_param2.longueur){
            printf("Changements en longueur correctement enregistres.\n");
        }
        if(all_param.largeur != all_param2.largeur){
            printf("Changements en largeur correctement enresgitres.\n");
        }
        if(all_param.gravite != all_param2.gravite){
            printf("Changement de gravite correctement enresgitre.\n");
        }
        if(all_param.symbole != all_param2.symbole){
            printf("Changement du nombre de symbole correctement enresgitre.\n");
        }
        if(all_param.gravite == all_param2.gravite){
            if (all_param.largeur == all_param2.largeur){
                if (all_param.longueur == all_param2.longueur){
                    if (all_param.symbole == all_param2.symbole){
                        printf("Aucun changement enresgitre.\n");
                    }
                }
            }
        }
        if(a == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        a = 0;
        all_param = all_param2;

        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n\n");

        // Menu des parametres
        printf("Parametres :                               | Parametres actuels :\n");
        printf("                                           | \n");
        printf("[1] - Changer la taille de la grille       | taille de la grille : %d / %d\n", all_param2.longueur, all_param2.largeur);
        printf("[2] - Changer le sens de gravite           | sens de gravite : %s\n", sensgravite);
        printf("[3] - Changer le nombre de symboles        | nombre de symboles : %d\n", all_param2.symbole);
        printf("[4] - Quitter les parametres               |\n\n");

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
                a = 1 ;
                break;
        }
    }
    return all_param;
}
param_struct_game chargement_partie1(param_struct_game all_param0)
{

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin = 1;
    int c = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (c == 1) {
            printf("Choix invalide, veuillez recommencer.\n");
        }

        c = 0;
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");
        printf("Chargement de la partie 1 pret.\n\n");

        // Rappel du sens de la gravite

        printf("Etes-vous sur de vouloir charger cette partie ?\n\n");
        printf("[1] - Oui \n"
               "[2] - Non, quitter \n\n");
        printf("---> ");

        int c6 = getchar();

        // suppression des caracteres dans stdin
        if (c6 != '\n' && c6 != EOF) {
            int e;
            while ((e = getchar()) != '\n' && e != EOF);
        }

        // Etude du choix de l'utilisateur
        switch (c6) {

            // Charger la partie 1
            case '1':
                printf("=========DEV LE CHARGEMENT DE LA PARTIE=========");
                //Faire charger la partie 1

                return all_param0;

                // Faire quitter
            case '2':
                return all_param0;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                c = 1;
                break;
        }
    }
}
param_struct_game chargement_partie2(param_struct_game all_param0)
{

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin = 1;
    int c = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (c == 1) {
            printf("Choix invalide, veuillez recommencer.\n");
        }

        c = 0;
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");
        printf("Chargement de la partie 2 pret.\n\n");

        // Rappel du sens de la gravite

        printf("Etes-vous sur de vouloir charger cette partie ?\n\n");
        printf("[1] - Oui \n"
               "[2] - Non, quitter \n\n");
        printf("---> ");

        int c6 = getchar();

        // suppression des caracteres dans stdin
        if (c6 != '\n' && c6 != EOF) {
            int e;
            while ((e = getchar()) != '\n' && e != EOF);
        }

        // Etude du choix de l'utilisateur
        switch (c6) {

            // Charger la partie 2
            case '1':
                printf("=========DEV LE CHARGEMENT DE LA PARTIE=========");
                //Faire charger la partie 2

                return all_param0;

                // Faire quitter
            case '2':
                return all_param0;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                c = 1;
                break;
        }
    }
}
param_struct_game chargement_partie3(param_struct_game all_param0)
{

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin = 1;
    int c = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (c == 1) {
            printf("Choix invalide, veuillez recommencer.\n");
        }

        c = 0;
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");
        printf("Chargement de la partie 3 pret.\n\n");

        // Rappel du sens de la gravite

        printf("Etes-vous sur de vouloir charger cette partie ?\n\n");
        printf("[1] - Oui \n"
               "[2] - Non, quitter \n\n");
        printf("---> ");

        int c6 = getchar();

        // suppression des caracteres dans stdin
        if (c6 != '\n' && c6 != EOF) {
            int e;
            while ((e = getchar()) != '\n' && e != EOF);
        }

        // Etude du choix de l'utilisateur
        switch (c6) {

            // Charger la partie 3
            case '1':
                printf("=========DEV LE CHARGEMENT DE LA PARTIE=========");
                //Faire charger la partie 3

                return all_param0;

                // Faire quitter
            case '2':
                fin = 0;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                c = 1;
                break;
        }
    }
}
param_struct_game charger_grille(param_struct_game all_param6){

    param_struct_game all_param = all_param6 ;
// Déclaration de la variable fin, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin = 1;
    int i = 0 ;
    int changement = 0;

// tant que fin = 1 : (si fin = 0 alors c'est la fin de la boucle).
    while (fin) {

        int f;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        if (changement == 1) {
            if (all_param.gravite == all_param6.gravite) {
                if (all_param.largeur == all_param6.largeur) {
                    if (all_param.longueur == all_param6.longueur) {
                        if (all_param.symbole == all_param6.symbole) {
                            printf("Aucun changement enresgitre.\n");
                        }
                    }
                }
            }
        }
        if(i == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        i = 0;
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                  \n\n\n");

        // Menu chargement grille
        printf("Menu de chargement d'une grille\n\n");
        printf("[1] - Partie 1\n"
               "[2] - Partie 2\n"
               "[3] - Partie 3\n"
               "[4] - Quitter\n\n");

        // Enregistrement du choix (dans c2) en caractère.
        printf("---> ");
        f = getchar();

        /* suppression des caracteres dans stdin */
        if (f != '\n' && f != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }


        // Etude du choix de l'utilisateur
        switch (f) {

            // Charger la premiere partie
            case '1':
                changement = 0 ;
                all_param6 = chargement_partie1(all_param6);
                changement = 1 ;
                break;

                // Charger la deuxieme partie
            case '2':
                changement = 0 ;
                all_param6 = chargement_partie2(all_param6);
                changement = 1 ;
                break;

                // Charger la troisième partie
            case '3':
                changement = 0 ;
                all_param6 = chargement_partie3(all_param6);
                changement = 1 ;
                break;

                // Fais quitter l'utilisateur (fin de la boucle activé)
            case '4':
                fin = 0;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3,4)
            default:
                i = 1 ;
                break;
        }
    }
    return all_param6 ;
}


int menu(param_struct_game all_param1) {

// Déclaration de la variable fin, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin = 1;
    int i = 0 ;

    param_struct_game all_param2;

// tant que fin = 1 : (si fin = 0 alors c'est la fin de la boucle).
    while (fin) {

        int c;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(i == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        i = 0;
        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                  \n\n\n");

        // Menu principal
        printf("[1] - Lancer le jeu\n"
               "[2] - Parametres\n"
               "[3] - Charger une grille\n"
               "[4] - Quitter\n\n");

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
                printf("Chargement de votre grille... Veuillez patienter");
                return 1;

                //
            case '2':
                all_param2 = parametres(all_param1);
                all_param1 = all_param2;
                break;

                //
            case '3':
                all_param2 = charger_grille(all_param1);
                break;

                // Fais quitter l'utilisateur (fin de la boucle activé)
            case '4':
                fin = 0;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3,4)
            default:
                i = 1 ;
                break;
        }
    }
}