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

struc_charge_grille lire_parametre()
{
    struc_charge_grille all_param;
    FILE *fichier = fopen("..\\save\\parametre.txt", "r");

    if (fichier != NULL)
    {
        fscanf(fichier,"longueur_grille : %d\n",&all_param.all_param.longueur);
        fscanf(fichier,"largeur_grille : %d\n",&all_param.all_param.largeur);
        fscanf(fichier,"nbr_symbole : %d\n",&all_param.all_param.symbole);
        fscanf(fichier,"Direction_gravite : %d\n",&all_param.all_param.gravite);

        fclose(fichier);
    }
    else
    {
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }
    return all_param;
}

void save_grille(struc_charge_grille party, int partie,int score)
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
        fprintf(fichier, "longueur_grille : %d\n", party.all_param.longueur);
        fprintf(fichier, "largeur_grille : %d\n", party.all_param.largeur);
        fprintf(fichier, "symbole : %d\n", party.all_param.symbole);
        fprintf(fichier, "gravite : %d\n", party.all_param.gravite);

        for (int i = 0; i < party.all_param.largeur; ++i) {
            for (int j = 0; j < party.all_param.longueur; ++j) {
                fprintf(fichier, "%c:%d\n", party.grille[i][j].car, party.grille[i][j].num);
            }
        }
    }
    else
    {
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }
}

struc_charge_grille charge_grille(int partie,struct_grille_cc **grille)
{
    FILE *fichier;
    param_struct all_param;
    struc_charge_grille crg_grille;
    int score;

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
        int game=1;
        fscanf(fichier, "game : %d\n",&game);

            if (game==1){

                fscanf(fichier, "score : %d\n", &score);
                fscanf(fichier, "longueur_grille : %d\n", &all_param.longueur);
                fscanf(fichier, "largeur_grille : %d\n", &all_param.largeur);
                fscanf(fichier, "symbole : %d\n", &all_param.symbole);
                fscanf(fichier, "gravite : %d\n", &all_param.gravite);

                for (int i = 0; i < all_param.largeur; ++i) {
                    for (int j = 0; j < all_param.longueur; ++j) {
                        fscanf(fichier, "%c:%d\n", &grille[i][j].car, &grille[i][j].num);
                    }
                }

                crg_grille.grille = grille;
                crg_grille.all_param = all_param;
                crg_grille.content = 1 ;
            }
            else{
                printf("La partie que vous essayez de charger est vide.\n");
                crg_grille.content = 0 ;
            }
        }
    else
    {
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }

    return crg_grille;
}