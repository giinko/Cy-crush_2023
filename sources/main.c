#include <stdio.h>
#include <stdlib.h>


#include "..\header\game.h"


int main()
{
	
	srand(8);
    color(15,0);
    int n=8;
    int m=8;

    // creation grille
    struct_grille_cc** grille = creation_full_grille(n, m);

    // Initialisatino de la grille
    struct_grille_cc** grille3 = start_grille(grille, n, m);
    affichage(n,m,grille3);

    // Jeu
    int final_score;
    final_score = game(grille3,n,m,0);

    printf("Le score final est de : %d",final_score);
    return 0;


	return 0;
}