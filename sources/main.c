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
    dans le menu tu prends en parametre, all_param ( la struct)
    tu fais en sorte que tt marche avec la struc, 
    dc prempalce les pointeur par .long, .larg et tt
    merci !
    */
    int menuu = menu(pn, pm, pgravite) ;

    if(menuu == 1) {
        srand(8);
        color(15, 0);

        // creation grille
        struct_grille_cc **grille = creation_full_grille(n, m);

        // Initialisation de la grille
        struct_grille_cc **grille3 = start_grille(grille, n, m);
        affichage(n, m, grille3);

        // Jeu
        int final_score;
        final_score = game(grille3, n, m, 0);

        printf("Le score final est de : %d", final_score);
        return 0;
    }
}