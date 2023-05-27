#include <stdio.h>

#include "..\header\menu.h"


// lance les fonctions Pour lancer le jeu ( le menu )

int main()
{

    printf("Maxime, Fares and Sany present :\n");

    struc_charge_grille a = lire_parametre();

    int menu1 = menu(a);
    printf("Le score final est de :");

    return 0;
}