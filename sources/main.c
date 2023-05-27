#include <stdio.h>

#include "..\header\menu.h"


// lance les fonctions Pour lancer le jeu ( le menu )

int main()
{

    printf("Maxime, Fares and Sany present :");
    struc_charge_grille a = lire_parametre();

    int menu1 = menu(a);

    return 0;
}