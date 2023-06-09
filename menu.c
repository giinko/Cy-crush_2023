#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "menu.h"


// Renvoie 1 si les paramètre son identique pour : struc charge grille
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

// Renvoie 2 si les paramètres sont identique pour : struc param_struct
int meme_param(param_struct all_param1, param_struct all_param2)
{
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

// Vérifie si un fichier est vide ou non
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

// Fonction qui vide le fichier de la partie selectionnée
void vider_partie(){

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1 ;
    int a = 0 ;
    int fichier1_plein = 0 ;
    int fichier2_plein = 0 ;
    int fichier3_plein = 0 ;
    const char *chemin_fichier1 = "partie_1.txt" ;
    const char *chemin_fichier2 = "partie_2.txt" ;
    const char *chemin_fichier3 = "partie_3.txt" ;

    // tant que fin2 = 1 : (si fin2 = 0 alors c'est la fin de la boucle).
    while (fin2) {

        int c2;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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
        printf("Quelle sauvegarde voulez-vous supprimer ? \n\n");

        if (verifier_fichier_vide(chemin_fichier1) == 1){
            printf("[1] - Supprimer la partie 1 \n");
            fichier1_plein = 1 ;
        }
        if (verifier_fichier_vide(chemin_fichier2) == 1){
            printf("[2] - Supprimer la partie 2 \n");
            fichier2_plein = 1 ;
        }
        if (verifier_fichier_vide(chemin_fichier3) == 1){
            printf("[3] - Supprimer la partie 3 \n");
            fichier3_plein = 1 ;
        }
        if (fichier1_plein == 0 && fichier2_plein == 0 && fichier3_plein == 0){
            printf("Toutes les sauvegardes sont vides.\n");
        }
        printf("[0] - Quitter\n\n");

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
                if (fichier1_plein == 1){

                    supp_save(1); // supp les valeurs
                    printf ("\n\nFichier de la partie 1 supprime avec succes.");
                    sleep(2);
                    fin2 = 0;
                    break;
                }else if (fichier1_plein == 0){
                    a = 1 ;
                    break ;
                }

            case '2':
                if (fichier2_plein == 1){
                    supp_save(2); //supp les valeurs
                    printf ("\n\nFichier de la partie 2 supprime avec succes.");
                    sleep(2);
                    fin2 = 0;
                    break;
                }else if (fichier2_plein == 0){
                    a = 1 ;
                    break ;
                }

            case '3':
                if (fichier3_plein == 1){
                    supp_save(3); // supp les valeurs
                    printf ("\n\nFichier de la partie 3 supprime avec succes.");
                    sleep(2);
                    fin2 = 0;
                    break;
                }else if (fichier3_plein == 0){
                    a = 1 ;
                    break ;
                }

                // Fais quitter l'utilisateur si il fait 4
            case '0':
                fin2 = 0;
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3,4)
            default:
                a = 1 ;
                break;
        }
    }

}

// Menu de sauvgarde d'une grille
struc_charge_grille sauvegarder(struc_charge_grille partie) {

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1 ;
    int a = 0 ;
    const char *chemin_fichier1 = "partie_1.txt" ;
    const char *chemin_fichier2 = "partie_2.txt" ;
    const char *chemin_fichier3 = "partie_3.txt" ;

    // tant que fin2 = 1 : (si fin2 = 0 alors c'est la fin de la boucle).
    while (fin2) {

        int c2;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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

        // Menu de sauvegarde
        printf("Dans quelle partie voulez-vous sauvegarder ? \n\n");
        printf("[1] - Partie 1 ");
        // affiche vide ou non-vide
        if (verifier_fichier_vide(chemin_fichier1) == 0){
            printf("(vide)\n");
        }else if (verifier_fichier_vide(chemin_fichier1) == 1){
            printf("(non-vide)\n");
        }

        // affiche vide ou non-vide
        printf("[2] - Partie 2 ");
        if (verifier_fichier_vide(chemin_fichier2) == 0){
            printf("(vide)\n");
        }else if (verifier_fichier_vide(chemin_fichier2) == 1){
            printf("(non-vide)\n");
        }

        // affiche vide ou non-vide
        printf("[3] - Partie 3 ");
        if (verifier_fichier_vide(chemin_fichier3) == 0){
            printf("(vide)\n");
        }else if (verifier_fichier_vide(chemin_fichier3) == 1){
            printf("(non-vide)\n");
        }
        printf("[4] - Quitter sans sauvegarder  \n\n");

        // Enregistrement du choix (dans c2) en caractère.
        printf("---> ");
        c2 = getchar();

        // suppression des caracteres dans stdin
        if (c2 != '\n' && c2 != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }

        switch (c2) {

            case '1': //sauvegarde dans la partie 1
                save_grille(partie, 1, partie.score);
                liber_malloc(partie.grille, partie.all_param.largeur,partie.all_param.longueur);
                printf("\nSauvegarde en cours, veuillez patienter...");
                sleep(2); // simulation de sauvegarde
                fin2 = 0;
                break;

            case '2': //sauvegarde dans la partie 2
                save_grille(partie, 2, partie.score);
                liber_malloc(partie.grille, partie.all_param.largeur,partie.all_param.longueur);
                printf("\nSauvegarde en cours, veuillez patienter...");
                sleep(2); // simulation de sauvegarde
                fin2 = 0;
                break;

            case '3': //sauvegarde dans la partie 3
                save_grille(partie, 3, partie.score);
                liber_malloc(partie.grille, partie.all_param.largeur,partie.all_param.longueur);
                printf("\nSauvegarde en cours, veuillez patienter...");
                sleep(2); // simulation de sauvegarde
                fin2 = 0;
                break;

            // Fais quitter l'utilisateur si il fait 4
            case '4':
                fin2 = 0;
                //liberation de malloc
                liber_malloc(partie.grille, partie.all_param.largeur,partie.all_param.longueur);
                break;

            // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2,3,4)
            default:
                // regénère le menu avec 'choix invalide'
                a = 1 ;
                break;
        }
    }
    // Met la variable content à 0 pour retirer le menu de charger une partie (au cas ou)
    partie.content = 0 ;
    return partie;
}

// Menu de fin de partie
struc_charge_grille fin_de_partie(struc_charge_grille partie)
{

    // Déclaration de la variable fin2, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin2 = 1;
    int a = 0;

    // tant que fin2 = 0 : (si fin2 = 1 alors c'est la fin de la boucle).
    while (fin2) {

        int c2;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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

        // Menu de fin de partie
        printf("Fin de partie. \n");
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
                // Liberation de malloc
                liber_malloc(partie.grille, partie.all_param.largeur,partie.all_param.longueur);
                break;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2)
            default:
                a = 1 ;
                break;
        }
    }
    // content à 0 au cas ou si il y a le menu de charger une partie dans le menu principal
    partie.content = 0 ;
    return partie;
}

// Menu de changement de la taille de la grille
param_struct changement_taillegrille(param_struct all_param11) {

    int fin3 = 1;
    int b = 0 ;
    param_struct init = all_param11 ; // parametres initiaux enregistrés dans init.
    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3) {

        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
          // si symbole sup à 5 alors max 25 et minimum 5
if (all_param11.symbole >= 5){
    while ((all_param11.longueur < 5) || (all_param11.longueur > 25)) {
        printf("\nLongueur invalide. Merci de saisir un nombre entre 5 et 25.\n\n");
        printf("Nouvelle taille en longueur : ");
        scanf("%d", &all_param11.longueur);
    }
}else { //sinon si symbole = 4 alors max 14 (compris)
    while ((all_param11.longueur < 5) || (all_param11.longueur > 14)) {
        printf("\nLongueur invalide. Votre nombre de symbole est trop faible (4). (Maximum autorise : 14/14) \n\n");
        printf("Nouvelle taille en longueur : ");
        scanf("%d", &all_param11.longueur);
    }

    }
// Enregistrer la nouvelle taille en largeur
        printf("Nouvelle taille en largeur : ");
        scanf("%d", &all_param11.largeur);

// Vérification de la validité des nouvelles valeurs
// symboles sup ou egal a 5 alors maximum de la grille 25
        if (all_param11.symbole >= 5){

            while ((all_param11.largeur < 5) || (all_param11.largeur > 25)) {
                printf("\nLargeur invalide. Merci de choisir un nombre entre 5 et 25.\n\n");
                printf("Nouvelle taille en largeur : ");
                scanf("%d", &all_param11.largeur);
            }
        }else { //symboles = 4 alors maximum 14 (compris)
            while ((all_param11.largeur < 5) || (all_param11.largeur > 14)) {
                printf("\nLongueur invalide. Votre nombre de symbole est trop faible (4). (Maximum autorise : 14/14) \n\n");
                printf("Nouvelle taille en largeur : ");
                scanf("%d", &all_param11.largeur);
            }

        }
        //récupère le dernier caractère pour éviter la regénération du menu.
         char stop = getchar();

        // sauvegarde les paramètres dans le dossier paramètres
        ecrir_parametre(all_param11);

        // Derniere confirmation
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

            case '1':
                // C'est ok et fin de fonction
                return all_param11;
            case '2':
                // Return les parametres initiaux (enregistrée au debut)
                return init;

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 1,2)
            default:
                b = 1 ; //message d'invalidité
                break;
        }
    }
    return all_param11 ;
}

// Menu de changement du nombre de caracteres
param_struct changement_caractere(param_struct all_param13) {

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin3 = 1;
    int d = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin3) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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

        // Rappel du sens du nombre de symboles
        printf("Actuellement, vous jouez avec %d symboles differents. \n\n", all_param13.symbole);

        // Indication des differents choix disponibles
        if (all_param13.symbole != 4){
            printf("[4] - Jouer avec 4 symboles differents \n");
        }
        if (all_param13.symbole != 5){
            printf("[5] - Jouer avec 5 symboles differents \n");
        }
        if (all_param13.symbole != 6){
            printf("[6] - Jouer avec 6 symboles differents \n");
        }

        printf("[0] - Retourner vers les parametres \n\n");

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

                // Si l'utilisateur entre un autre caractère que ceux proposés (autre que : 4,5,6,0)
            default:
                d = 1 ;
                break;
        }
    }
    ecrir_parametre(all_param13); // ecriture des parametres dans parametres.txt
    // return les nouveaux parametres (changés ou inchangés)
    return all_param13;
}

// Menu de parametres generaux
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
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

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

// Menu de confirmation du chargement de la partie 1
struc_charge_grille chargement_partie1(struc_charge_grille total01)
{

    // Déclaration de la variable fin, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    struc_charge_grille o_k_ou_il_quitte = total01 ;
    int fin = 1;
    int c = 0;

    // tant que fin = 0 : (si fin = 1 alors c'est la fin de la boucle).
    while (fin) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
                total01.grille = grille;
                struc_charge_grille total001 = charge_grille(1,total01);
                printf("\n\nChargement de votre grille en cours");
                total001.content = 1 ;
                sleep(2) ;
                return total001;

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
    return o_k_ou_il_quitte ;
}

// Menu de confirmation du chargement de la partie 2
struc_charge_grille chargement_partie2(struc_charge_grille total02)
{

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin = 1;
    int c = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
                total02.grille = grille;
                struc_charge_grille total002 = charge_grille(2,total02);
                printf("\n\nChargement de votre grille en cours");
                total002.content = 1 ;
                sleep(2) ;
                return total002;

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
    return total02 ;
}

// Menu de confirmation du chargement de la partie 3
struc_charge_grille chargement_partie3(struc_charge_grille total03)
{

    // Déclaration de la variable fin3, pour mettre fin à la boucle : 0 = ça tourne, 1 = stop.
    int fin = 1;
    int c = 0;

    // tant que fin3 = 0 : (si fin3 = 1 alors c'est la fin de la boucle).
    while (fin) {

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
                total03.grille = grille;
                struc_charge_grille total003 = charge_grille(3,total03);
                printf("\n\nChargement de votre grille en cours");
                total003.content = 1 ;
                sleep(2) ;
                return total003;

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
    return total03;
}

// Menu de chargement d'une partie (ou de suppression d'un fichier)
struc_charge_grille charger_grille(struc_charge_grille total0){


// Déclaration de la variable fin, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin = 1;
    total0.content = 0 ;
    int i = 0 ;
    int fichier_vide ;
    const char *chemin_fichier1 = "partie_1.txt";
    const char *chemin_fichier2 = "partie_2.txt";
    const char *chemin_fichier3 = "partie_3.txt";

// tant que fin = 1 : (si fin = 0 alors c'est la fin de la boucle).
    while (fin) {

        int f;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
        printf("[4] - Vider une partie\n");
        printf("[5] - Quitter\n\n");

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

            case '4':
                vider_partie();
                fin = 0;
                break;

                // Fais quitter l'utilisateur (fin de la boucle activé)

            case '5':
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

// Menu principal qui lie toutes les fonctions
int menu(struc_charge_grille total) {

// Déclaration de la variable fin, pour mettre fin à la boucle : 1 = ça tourne, 0 = stop.
    int fin = 1;
    int i = 0 ;
    struc_charge_grille a = lire_parametre() ;
    total.content = 0 ;
    int deja_charge = 0 ;
    int j =0 ;

// tant que fin = 1 : (si fin = 0 alors c'est la fin de la boucle).
    while (fin) {

        int c;

        // CY CRUSH
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        if (i ==1){
            printf("Choix invalide, veuillez recommencer.\n");
        }
        if (total.content == 1){
            if (deja_charge == 0){
                printf("Une partie a ete chargee.");
            }else{
                printf("Impossible, vous avez deja charge une partie. (Vous ne pouvez que jouer)");
            }
            deja_charge = 0 ;
        } i = 0;
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
            printf("[2] - Parametres ");
            if((total.all_param.longueur == 8 && total.all_param.largeur == 8) && total.all_param.symbole == 5){
                printf("(parametres par defaut)\n");
            }else {
                printf("\n");
            }
        }
        if (total.content == 1){
            printf("[3] - X Voir les sauvegardes X\n");
        }else {
            printf("[3] - Voir les sauvegardes\n");
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
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    affichage(a.all_param.largeur, a.all_param.longueur, grille3);
                    printf("\n");

                    // Jeu
                    score_grille final_score_grille;
                    final_score_grille = game(grille3, a.all_param.largeur, a.all_param.longueur, 0);

                    a.grille = final_score_grille.grille;
                    a.score = final_score_grille.points;

                    total = fin_de_partie(a);
                }else if (total.content == 1){

                    if (total.all_param.symbole == 4){
                        printf("Chargement de votre grille... Veuillez patienter\n\n");
                        sleep(2); // chutt c'est un secret, on fais genre il reflechis
                    }
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    affichage(total.all_param.largeur, total.all_param.longueur, total.grille);
                    printf("\n");
                    score_grille final_score_grille;
                    final_score_grille = game(total.grille, total.all_param.largeur, total.all_param.longueur, total.score);

                    a.grille = final_score_grille.grille;
                    a.score = final_score_grille.points;
                    total = fin_de_partie(a);
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
    return 0 ;
}