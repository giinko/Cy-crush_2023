#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "..\header\menu.h"


int main()
{
    printf("Maxime, Fares and Sany present :\n");

    struc_charge_grille a = lire_parametre();

    int menu1 = menu(a);

    if(menu1 == 1) {
        srand(time( NULL ));
        color(15, 0);

        //re check les param
        a = lire_parametre();
        // creation grille
        struct_grille_cc **grille = creation_full_grille(a.all_param);

        // Initialisation de la grille
        struct_grille_cc **grille3 = start_grille(grille, a.all_param);
        affichage(a.all_param.largeur, a.all_param.longueur, grille3);

        // Jeu
        int final_score;
        final_score = game(grille3, a.all_param.largeur, a.all_param.longueur, 0);

        printf("Le score final est de : %d", final_score);
        return 0;
    }

    return 0;
}