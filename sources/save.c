#include <stdio.h>
#include "..\header\save.h"

void ecrir_parametre(param_struct_game all_param)
{

    FILE *fichier = fopen("..\\save\\parametre.txt", "w+");
    if (fichier != NULL)
    {

        fprintf(fichier,"longueur_grille : %d\n",all_param.longueur);
        fprintf(fichier,"largeur_grille : %d\n",all_param.largeur);
        fprintf(fichier,"nbr_symbole : %d\n",all_param.symbole);
        fprintf(fichier,"Direction_gravite : %d\n",all_param.gravite);

        fclose(fichier);
    }
    else
    {
        printf("Une erreur c'est produite lors de l'ouverture d'un fichier. ");
    }

}

param_struct_game lire_parametre()
{
    param_struct_game all_param;
    FILE *fichier = fopen("..\\save\\parametre.txt", "r");

    if (fichier != NULL)
    {
        fscanf(fichier,"longueur_grille : %d\n",&all_param.longueur);
        fscanf(fichier,"largeur_grille : %d\n",&all_param.largeur);
        fscanf(fichier,"nbr_symbole : %d\n",&all_param.symbole);
        fscanf(fichier,"Direction_gravite : %d\n",&all_param.gravite);

        fclose(fichier);
    }
    else
    {
        printf("Une erreur c'est produite lors de l'ouverture d'un fichier. ");
    }
    return all_param;
}

void save_grille(param_struct_game all_param,struct_grille_cc **grille)
{
    printf("yaya");
}