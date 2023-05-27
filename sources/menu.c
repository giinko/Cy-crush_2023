#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "..\header\menu.h"

int meme_total(struc_charge_grille total1, struc_charge_grille total2){
    if (total1.all_param.largeur == total2.all_param.largeur){
        if (total1.all_param.longueur == total2.all_param.longueur){
            if (total1.all_param.symbole == total2.all_param.symbole){
                if (total1.score == total2.score){
                    return 1 ;
                }else{
                    return 0 ;
                }
            }else{
                return 0 ;
            }
        }else{
            return 0 ;
        }
    }else{
        return 0 ;
    }
}
int meme_param(param_struct all_param1, param_struct all_param2){
    if (all_param1.largeur == all_param2.largeur){
        if (all_param1.longueur == all_param2.longueur){
            if (all_param1.symbole == all_param2.symbole){
                    return 1 ;
            }else{
                return 0 ;
            }
        }else{
            return 0 ;
        }
    }else{
        return 0 ;
    }
}
int verifier_fichier_vide(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Le fichier %s n'a pas été trouvé.\n", nom_fichier);
        return -1;
    }

    // Se déplace à la fin du fichier
    fseek(fichier, 0, SEEK_END);

    // Récupère la position actuelle dans le fichier
    long taille = ftell(fichier);

    if (taille == 0) {
        return 0 ; // fichier vide
    } else {
        return 1 ; // n'est pas vide
    }
}
struc_charge_grille sauvegarder(struc_charge_grille partie) {

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1;
    int a = 0;

    // tant que fin2 = 1 : (si fin2 = 0 alors c'est la fin de la boucle).
    while (fin2) {

        int c2;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        if(a == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        a = 0;

        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n\n");

        // Menu des parametres
        printf("Dans quelle partie voulez-vous sauvegarder ? \n\n");
        printf("[1] - Partie 1 \n");
        printf("[2] - Partie 2 \n");
        printf("[3] - Partie 3 \n");
        printf("[4] - Quitter sans sauvegarder  \n\n");

        // Enregistrement du choix (dans c2) en caractère.
        printf("---> ");
        c2 = getchar();

        /* suppression des caracteres dans stdin */
        if (c2 != '\n' && c2 != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }

        switch (c2) {

            case '1':
                save_grille(partie, 1, partie.score);
                printf("\nSauvegarde en cours, veuillez patienter...");
                sleep(2);
                fin2 = 0;
                break;

            case '2':
                save_grille(partie, 2, partie.score);
                printf("\nSauvegarde en cours, veuillez patienter...");
                sleep(2);
                fin2 = 0;
                break;

            case '3':
                save_grille(partie, 3, partie.score);
                printf("\nSauvegarde en cours, veuillez patienter...");
                sleep(2);
                fin2 = 0;
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
    return partie;
}
struc_charge_grille menu_pause(struc_charge_grille partie) {

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1;
    int a = 0;

    // tant que fin2 = 0 : (si fin2 = 1 alors c'est la fin de la boucle).
    while (fin2) {

        int c2;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        if(a == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        a = 0;

        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n\n");

        // Menu des parametres
        printf("Souhaitez-vous sauvegarder votre partie ? \n");
        printf("Score : %d\n\n", partie.score);
        printf("[1] - Oui, je veux sauvegarder ma partie \n");
        printf("[2] - Non, retourner vers le menu principal \n\n");

        // Enregistrement du choix (dans c2) en caractère.
        printf("---> ");
        c2 = getchar();

        /* suppression des caracteres dans stdin */
        if (c2 != '\n' && c2 != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }

        switch (c2) {

                // Entre dans le menu de sauvegarde
            case '1':
                partie = sauvegarder(partie);
                fin2 = 0 ;
                break;

                // Retour vers le menu principal
            case '2':
                fin2 = 0 ;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2)
            default:
                a = 1 ;
                break;
        }
    }
    return partie;
}
param_struct changement_taillegrille(param_struct all_param11) {
    int fin3 = 1;
    int b = 0 ;
    param_struct init = all_param11 ;
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
        printf("Longueur : %d\n", all_param11.longueur);
        printf("Largeur : %d\n\n", all_param11.largeur);
        printf("\nVeuillez entrer la nouvelle taille souhaitee.");
        printf("(Merci de saisir des nombres compris entre 5 et 25)\n\n");

// Enregistrer la nouvelle taille en longueur
        printf("Nouvelle taille en longueur : ");
        scanf("%d", &all_param11.longueur);

// Vérification de la validité des nouvelles valeurs
        while ((all_param11.longueur < 5) || (all_param11.longueur > 25)) {
            printf("\nLongueur invalide. Merci de choisir un nombre entre 5 et 25.\n\n");
            printf("Nouvelle taille en longueur : ");
            scanf("%d", &all_param11.longueur);
        }
// Enregistrer la nouvelle taille en largeur
        printf("Nouvelle taille en largeur : ");
        scanf("%d", &all_param11.largeur);

// Vérification de la validité des nouvelles valeurs
        while ((all_param11.largeur < 5) || (all_param11.largeur > 25)) {
            printf("\nLargeur invalide. Merci de choisir un nombre entre 5 et 25.\n\n");
            printf("Nouvelle taille en largeur : ");
            scanf("%d", &all_param11.largeur);
        }
        //récupère le dernier caractère pour éviter la regénération du menu.
        char stop = getchar();

        // sauvegarde les paramètres dans le dossier paramètre
        ecrir_parametre(all_param11);
        printf("\n\nSouhaitez-vous enregistrer vos modifications ?\n\n");
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
// indication des limites de la grille
                return all_param11;
                // Vers la droite
            case '2':
                return init;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                b = 1 ;
                break;
        }
    }
}/*
param_struct changement_gravite(param_struct all_param12)
{

    // Declaration d'un tableau de caractère qui va traduire la gravité.
    char sens_gravite[20];
    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin3 = 0;
    int c = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3 == 0) {

        // Traduction de la valeur de la gravite (si 1 : vers le bas, sinon si 2 : vers la droite)
        if (all_param12.gravite == 1) {
            strcpy(sens_gravite, "vers le bas.");
        } else if (all_param12.gravite == 2) {
            strcpy(sens_gravite, "vers la droite.");
        }

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(c == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

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
                all_param12.gravite = 1;
                fin3 = 1;
                break;

                // Vers la droite
            case '2':
                all_param12.gravite = 2;
                fin3 = 1;
                break;

                // Retour vers les parametres
            case '3':
                fin3 = 1;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3)
            default:
                c = 1 ;
                break;
        }
        return all_param12;
    }*/
param_struct changement_caractere(param_struct all_param13) {

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
        printf("Actuellement, il y a %d de symboles differents \n", all_param13.symbole);

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
                all_param13.symbole = 4;
                fin3 = 0; // puis retour vers les parametres
                break;

                // Joue avec 5 symboles
            case '5':
                all_param13.symbole = 5;
                fin3 = 0; // puis retour vers les parametres
                break;

                // Joue avec 6 symboles
            case '6':
                all_param13.symbole = 6;
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
    ecrir_parametre(all_param13);
    return all_param13;
}
param_struct parametres(param_struct all_param1) {

    param_struct all_param10 = all_param1;

    char sensgravite[20];

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1;
    int a = 0;
    int changement = 0 ;
    int reinit = 0 ;

    // tant que fin2 = 0 : (si fin2 = 1 alors c'est la fin de la boucle).
    while (fin2) {

        int c2;

        if (all_param10.gravite == 1) {
            strcpy(sensgravite, "vers le bas");
        } else if (all_param10.gravite == 2) {
            strcpy(sensgravite, "vers la droite");
        }

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        if(all_param1.longueur != all_param10.longueur){
            printf("Changements en longueur correctement enregistres.\n");
        }
        if(all_param1.largeur != all_param10.largeur){
            printf("Changements en largeur correctement enresgitres.\n");
        }
        if(all_param1.gravite != all_param10.gravite){
            printf("Changement de gravite correctement enresgitre.\n");
        }
        if(all_param1.symbole != all_param10.symbole){
            printf("Changement du nombre de symbole correctement enresgitre.\n");
        }
        if (changement == 1){
            if(all_param1.gravite == all_param10.gravite){
                if (all_param1.largeur == all_param10.largeur){
                    if (all_param1.longueur == all_param10.longueur){
                        if (all_param1.symbole == all_param10.symbole){
                            printf("Aucun changement enresgitre.\n");
                        }
                    }
                }
            }
        }
        if (reinit == 1){
            printf("Vos parametres ont ete reinitialises.");
        }
        reinit = 0 ;
        changement = 0 ;
        if(a == 1){
            printf("Choix invalide, veuillez recommencer.\n");
        }

        a = 0;
        all_param1 = all_param10;

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
        printf("[1] - Changer la taille de la grille       | taille de la grille : %d / %d\n", all_param10.longueur, all_param10.largeur);
        printf("[2] - Changer le nombre de symboles        | \n");
        printf("[3] - Reinitialiser les parametres         | nombre de symboles : %d\n", all_param10.symbole);
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
                all_param10 = changement_taillegrille(all_param1);
                changement = 1 ;
                break;

            // Reinitialisation des parametres.
            case '2':
                all_param10 = changement_caractere(all_param1);
                changement = 1 ;
                break;

            // Entre dans le menu changement du nombre des caracteres (4 par defaut)
            case '3':
                all_param10.longueur = 8 ;
                all_param10.largeur = 8 ;
                all_param10.symbole = 5 ;
                reinit = 1 ;
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
    return all_param1;
}
struc_charge_grille chargement_partie1(struc_charge_grille total01)
{

    // Déclaration de la variable fin, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    struc_charge_grille o_k_ou_il_quitte = total01 ;
    int fin = 1;
    int c = 0;

    // tant que fin = 0 : (si fin = 1 alors c'est la fin de la boucle).
    while (fin) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (c == 1) {
            printf("Choix invalide, veuillez recommencer.\n\n");
        }
        c = 0;

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

                total01 = lire_parametre();
                struct_grille_cc** grille = creation_full_grille(total01.all_param);
                struc_charge_grille crg_gr = charge_grille(1,grille);

                printf("\n\nChargement de votre grille en cours");
                crg_gr.content = 1 ;
                sleep(2) ;
                /*
                // On va return crg_gr !!!!!!!!!!!!! je vais dodo on verra demain pour p2 et p3 suffit de modifier le 1 au dessus.
                score_grille ss;
                ss = game(crg_gr.grille,crg_gr.all_param.largeur,crg_gr.all_param.longueur,crg_gr.score);
                struc_charge_grille bb = lire_parametre();
                bb.grille = ss.grille;
                bb.score = ss.points;
                menu_pause(bb); */
                return crg_gr;

                // Faire quitter
            case '2':
                o_k_ou_il_quitte.content = 0 ;
                return o_k_ou_il_quitte ;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2)
            default:
                c = 1;
                break;
        }
    }
}
struc_charge_grille chargement_partie2(struc_charge_grille total02)
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

                total02 = lire_parametre();
                struct_grille_cc** grille = creation_full_grille(total02.all_param);
                struc_charge_grille crg_gr = charge_grille(2,grille);
                crg_gr.content = 1 ;
                return crg_gr;

                // Faire quitter
            case '2':
                total02.content = 0 ;
                return total02 ;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2)
            default:
                c = 1;
                break;
        }
    }
}
struc_charge_grille chargement_partie3(struc_charge_grille total03)
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

                total03 = lire_parametre();
                struct_grille_cc** grille = creation_full_grille(total03.all_param);
                struc_charge_grille crg_gr = charge_grille(3,grille);
                //Faire charger la partie 3
                crg_gr.content = 1 ;
                return crg_gr;

                // Faire quitter
            case '2':
                total03.content = 0 ;
                return total03 ;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2)
            default:
                c = 1;
                break;
        }
    }
}
struc_charge_grille charger_grille(struc_charge_grille total0){


// Déclaration de la variable fin, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin = 1;
    total0.content = 0 ;
    struc_charge_grille verif = total0 ;
    int i = 0 ;
    int fichier_vide ;
    const char *chemin_fichier1 = "../save/partie_1.txt";
    const char *chemin_fichier2 = "../save/partie_2.txt";
    const char *chemin_fichier3 = "../save/partie_3.txt";

// tant que fin = 1 : (si fin = 0 alors c'est la fin de la boucle).
    while (fin) {

        int f;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if(fichier_vide == 1){
            printf("\n\nImpossible, le fichier est vide.");
        }
        fichier_vide = 0;
        if(i == 1){
            printf("\n\nChoix invalide, veuillez recommencer.");
        }
        i = 0;
        printf("\n\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                  \n\n\n");

        // Menu chargement grille
        printf("Menu de chargement d'une grille\n\n");
        printf("Quelle partie souhaitez-vous charger ?\n\n");
        printf("[1] - Partie 1 ");
        if (verifier_fichier_vide(chemin_fichier1) == 0){
            printf("(vide)\n");
        }else if (verifier_fichier_vide(chemin_fichier1) == 1){
            printf("(non-vide)\n");
        }
        printf("[2] - Partie 2 ");
        if (verifier_fichier_vide(chemin_fichier2) == 0){
            printf("(vide)\n");
        }else if (verifier_fichier_vide(chemin_fichier2) == 1){
            printf("(non-vide)\n");
        }
        printf("[3] - Partie 3 ");
        if (verifier_fichier_vide(chemin_fichier3) == 0){
            printf("(vide)\n");
        }else if (verifier_fichier_vide(chemin_fichier3) == 1){
            printf("(non-vide)\n");
        }
        printf("[4] - Quitter\n\n");

        // Enregistrement du choix (dans c2) en caractère.
        printf("---> ");
        f = getchar();

        // suppression des caracteres dans stdin
        if (f != '\n' && f != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }


        // Etude du choix de l'utilisateur
        switch (f) {

            // Charger la premiere partie
            case '1':
                if (verifier_fichier_vide(chemin_fichier1) == 0){
                    fichier_vide = 1 ;
                    break ;
                }else if (verifier_fichier_vide(chemin_fichier1) == 1) {
                    total0 = chargement_partie1(total0);
                    return total0 ;
                }

                // Charger la deuxieme partie
            case '2':
                if (verifier_fichier_vide(chemin_fichier2) == 0){
                    fichier_vide = 1 ;
                }else if (verifier_fichier_vide(chemin_fichier2) == 1){
                    total0 = chargement_partie2(total0);
                    return total0 ;
                }
                break;

                // Charger la troisième partie
            case '3':
                if (verifier_fichier_vide(chemin_fichier3) == 0){
                    fichier_vide = 1 ;
                }else if (verifier_fichier_vide(chemin_fichier3) == 1){
                    total0 = chargement_partie3(total0);
                    return total0 ;
                }
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
    return total0 ;
}
int menu(struc_charge_grille total) {

// Déclaration de la variable fin, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin = 1;
    int i = 0 ;
    struc_charge_grille a = lire_parametre() ;
    struc_charge_grille tootal = total ;
    total.content = 0 ;
    int deja_charge = 0 ;

// tant que fin = 1 : (si fin = 0 alors c'est la fin de la boucle).
    while (fin) {

        int c;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if((total.all_param.longueur == 8 && total.all_param.largeur == 8) && total.all_param.symbole == 5){
            printf("Parametres par defaut.");
        }
        if (i ==1){
            printf("Choix invalide, veuillez recommencer.");
        }
        if (total.content == 1){
            if (deja_charge == 0){
                printf("Une partie a ete chargee.");
            }else{
                printf("Impossible, vous avez deja charge une partie. ");
            }
        }
        i = 0;
        printf("\n\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                  \n\n\n");

        // Menu principal
        printf("[1] - Lancer le jeu\n");
        if (total.content == 1){
            printf("[2] - X Parametres X\n");
        }else {
            printf("[2] - Parametres\n");
        }
        if (total.content == 1){
            printf("[3] - X Charger une grille X\n");
        }else {
            printf("[3] - Charger une grille\n");
        }
        printf("[4] - Quitter\n\n");

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

            // Lance le jeu à l'aide.
            case '1':
                if (total.content == 0){

                    if (total.all_param.symbole == 4){
                        printf("Chargement de votre grille... Veuillez patienter\n\n");
                        sleep(2); // chutt c'est un secret, on fais genre il reflechis
                    }
                    srand(time( NULL ));
                    color(15, 0);

                    //re check les param
                    a = lire_parametre();

                    // creation grille
                    struct_grille_cc **grille = creation_full_grille(a.all_param);

                    // Initialisation de la grille
                    struct_grille_cc **grille3 = start_grille(grille, a.all_param);
                    printf("\n\n\n");
                    affichage(a.all_param.largeur, a.all_param.longueur, grille3);
                    printf("\n");

                    // Jeu
                    score_grille final_score_grille;
                    final_score_grille = game(grille3, a.all_param.largeur, a.all_param.longueur, 0);

                    a.grille = final_score_grille.grille;
                    a.score = final_score_grille.points;

                    menu_pause(a);
                }else if (total.content == 1){


                    if (total.all_param.symbole == 4){
                        printf("Chargement de votre grille... Veuillez patienter\n\n");
                        sleep(2); // chutt c'est un secret, on fais genre il reflechis
                    }
                    score_grille final_score_grille;
                    final_score_grille = game(total.grille, total.all_param.largeur, total.all_param.longueur, total.score);

                    a.grille = final_score_grille.grille;
                    a.score = final_score_grille.points;

                    menu_pause(a);
                }
                break ;

                //
            case '2':
                if (total.content == 0){
                    total.all_param = parametres(total.all_param);
                } else if (total.content == 1){
                    deja_charge = 1 ;
                }
                break;

                //
            case '3':
                if (total.content == 0){
                    total = charger_grille(total);
                } else if (total.content == 1){
                    deja_charge = 1 ;
                }
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