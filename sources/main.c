#include <stdio.h>
#include <stdlib.h>


#include "..\header\game.h"
#include "..\header\menu.h"
#include "..\header\save.h"

int main()
{
    printf("Maxime, Fares and Sany present :\n");

    param_struct all_param = lire_parametre();
    /*
    dans le menu tu prends en parametres, all_param ( la struct)
    tu fais en sorte que tt marche avec la struc,
    dc prempalce les pointeur par .long, .larg et tt
    merci !
    */
    int menuu = menu(all_param) ;

    if(menuu == 1) {
        srand(8);
        color(15, 0);

        // creation grille
        struct_grille_cc **grille = creation_full_grille(all_param);

        // Initialisation de la grille
        struct_grille_cc **grille3 = start_grille(grille, all_param);
        affichage(all_param.largeur, all_param.longueur, grille3);

        // Jeu
        int final_score;
        final_score = game(grille3, all_param.largeur, all_param.longueur, 0);

        printf("Le score final est de : %d", final_score);
        return 0;
    }
}