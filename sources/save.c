#include <stdio.h>
#include "..\header\save.h"

void ecrir_parametre(param_struct all_param)
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
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }

}

param_struct lire_parametre()
{
    param_struct all_param;
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
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }
    return all_param;
}

void save_grille(param_struct all_param,struct_grille_cc **grille, int partie,int score)
{
    FILE *fichier;
    if (partie==1)
    {
        fichier = fopen("..\\save\\partie_1.txt", "w+");
    }
    else if (partie==2)
    {
        fichier = fopen("..\\save\\partie_2.txt", "w+");
    }
    else if(partie==3)
    {
        fichier = fopen("..\\save\\partie_3.txt", "w+");
    }
    else{
        printf("frro y'a que 3 parties c'est tt 1, 2 ou 3\n");
    }

    if (fichier != NULL) {

        fprintf(fichier, "game : 1\n");
        fprintf(fichier, "score : %d\n", score);
        fprintf(fichier, "longueur_grille : %d\n", all_param.longueur);
        fprintf(fichier, "largeur_grille : %d\n", all_param.largeur);
        fprintf(fichier, "symbole : %d\n", all_param.symbole);
        fprintf(fichier, "gravite : %d\n", all_param.gravite);
        printf("fichier choisis\n");
        for (int i = 0; i < all_param.largeur; ++i) {
            printf("fichier choisis\n");
            for (int j = 0; j < all_param.longueur; ++j) {
                fprintf(fichier, "%c:%d\n", grille[i][j].car, grille[i][j].num);
            }
        }
    }
    else
    {
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }
}

void save_grille(param_struct all_param,struct_grille_cc **grille, int partie,int score)
{
    FILE *fichier;
    if (partie==1)
    {
        fichier = fopen("..\\save\\partie_1.txt", "w+");
    }
    else if (partie==2)
    {
        fichier = fopen("..\\save\\partie_2.txt", "w+");
    }
    else if(partie==3)
    {
        fichier = fopen("..\\save\\partie_3.txt", "w+");
    }
    else{
        printf("frro y'a que 3 parties c'est tt 1, 2 ou 3\n");
    }

    if (fichier != NULL) {

        fprintf(fichier, "game : 1\n");
        fprintf(fichier, "score : %d\n", score);
        fprintf(fichier, "longueur_grille : %d\n", all_param.longueur);
        fprintf(fichier, "largeur_grille : %d\n", all_param.largeur);
        fprintf(fichier, "symbole : %d\n", all_param.symbole);
        fprintf(fichier, "gravite : %d\n", all_param.gravite);
        printf("fichier choisis\n");
        for (int i = 0; i < all_param.largeur; ++i) {
            printf("fichier choisis\n");
            for (int j = 0; j < all_param.longueur; ++j) {
                fprintf(fichier, "%c:%d\n", grille[i][j].car, grille[i][j].num);
            }
        }
    }
    else
    {
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }
}