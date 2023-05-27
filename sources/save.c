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
        printf(" fichier 1\n");
        fichier = fopen("..\\save\\partie_1.txt", "w+");
    }
    else if (partie==2)
    {
        printf(" fichier 2\n");
        fichier = fopen("..\\save\\partie_2.txt", "w+");
    }
    else if(partie==3)
    {
        printf(" fichier 3\n");
        fichier = fopen("..\\save\\partie_3.txt", "w+");
    }
    else{
        printf("frro y'a que 3 parties c'est tt 1, 2 ou 3\n");
    }


    if (fichier != NULL) {
        printf("%d,%c,%d\n",((party.grille)[0][0]).num, ((party.grille)[0][0]).car, party.all_param.symbole);
        fprintf(fichier, "game : 1\n");
        fprintf(fichier, "score : %d\n", score);
        fprintf(fichier, "longueur_grille : %d\n", (party.all_param).longueur);
        fprintf(fichier, "largeur_grille : %d\n", (party.all_param).largeur);
        fprintf(fichier, "symbole : %d\n", (party.all_param).symbole);
        fprintf(fichier, "gravite : %d\n", (party.all_param).gravite);


        for (int i = 0; i < (party.all_param).largeur; i++) {
            for (int j = 0; j < (party.all_param).longueur; j++) {
                fprintf(fichier, "%c:%d\n", party.grille[i][j].car, party.grille[i][j].num);

            }
        }

        fclose(fichier);
    }
    else
    {
        printf("Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }
}

struc_charge_grille charge_grille(int partie, struc_charge_grille total)
{
    FILE *fichier;
    struc_charge_grille crg_grille;


    if (partie==1)
    {
        fichier = fopen("..\\save\\partie_1.txt", "r");
    }
    else if (partie==2)
    {
        fichier = fopen("..\\save\\partie_2.txt", "r");
    }
    else if(partie==3)
    {
        fichier = fopen("..\\save\\partie_3.txt", "r");
    }
    else{
        printf("frro y'a que 3 parties c'est tt 1, 2 ou 3\n");
    }

    if (fichier != NULL) {
        int game=1;
        fscanf(fichier, "game : %d\n",&game);

            if (game==1){

                fscanf(fichier, "score : %d\n", &total.score);
                fscanf(fichier, "longueur_grille : %d\n", &total.all_param.longueur);
                fscanf(fichier, "largeur_grille : %d\n", &total.all_param.largeur);
                fscanf(fichier, "symbole : %d\n", &total.all_param.symbole);
                fscanf(fichier, "gravite : %d\n", &total.all_param.gravite);
                int j = 0 ;

                for (int i = 0; i < total.all_param.largeur; ++i) {
                    while (j < total.all_param.longueur){
                        j += 1 ;
                        printf("\ni = %d ; j = %d \n", i, j);
                        fscanf(fichier, "%c:%d\n", &total.grille[i][j].car, &total.grille[i][j].num);
                        printf("RESULTAT : %c : %d \n", total.grille[i][j].car, j) ;
                    } /*
                    for (j = 0; j < total.all_param.longueur; ++j) {
                        fscanf(fichier, "%c:%d\n", &total.grille[i][j].car, &total.grille[i][j].num);
                        printf("%c : %d \n", total.grille[i][j].car, total.grille[i][j].num) ; */

                }

                printf("%c:%d | %c:%d \n",total.grille[0][0].car,total.grille[0][0].num,total.grille[0][1].car,total.grille[0][1].num);
                fclose(fichier);
                crg_grille.grille = total.grille;
                crg_grille.all_param = total.all_param;
                crg_grille.content = 1 ;
            }
            else{
                printf("ERREUR : La partie que vous essayez de charger est vide.\n");
                crg_grille.content = 0 ;
            }
        }
    else
    {
        printf("ERREUR : Une erreur s'est produite lors de l'ouverture d'un fichier. ");
    }

    return crg_grille;
}