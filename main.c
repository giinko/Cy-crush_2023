#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
<<<<<<< HEAD

/*
0: noir
1: bleu foncé
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc
*/
=======



        // yayaya
>>>>>>> 9b05fdabc1a847e2bbef88093c37571d36e3fc97


/* Structure nécéssaire pour la suite */

typedef struct{
    int num;
    char car;
}struct_grille_cc;

typedef struct{
    int x;
    int y;
}position;

typedef struct{
    int points;
    char** grille;
}score_grille;


/* Fonction qui permet de changer la couleur des caractères de la consol */

void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}


// Fonction qui choisi un caractere aléatoire parmis la liste prédéfinis

struct_grille_cc random_char()
{
    struct_grille_cc zz;
    int r = rand()%4;
    char tab[4] = {'X','O','@','+'};
    int color[4] = {14,12,1,2};
    zz.car = tab[r];
    zz.num = color[r];
    return zz;
}


// fonction qui cree une grille a partir de 2 dimensions

char** creation_full_grille(int n,int m){

    struct_grille_cc** tab = malloc(n * sizeof(struct_grille_cc*));
    for (int i = 0; i < n; i++) {
        tab[i] = malloc(m * sizeof(struct_grille_cc));
        for (int j = 0; j < m; j++) {
            tab[i][j] = random_char();
        }
    }
    return tab;
}


// fonction qui affiche la grille en parametre avec la taille

void affichage(int n, int m, struct_grille_cc** grille)
{
    for(int p=0;p<2;p++){
        printf("   ");
        for(int k=0;k<m;k++){
            if(p==0){
                printf("%c ",'A'+k);
            }
            else{ printf("_ ");}
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){
        printf("%d |",1+i);
        for( int j=0;j<m;j++){
            color(grille[i][j].num,0);
            printf("%c ",grille[i][j].car);
        }
        printf("\n");
        color(15,0);
    }
}


// fonction qui permet de modifier la grille et la reenvoie ============= a modifier plus valable pour notre projet !===


char** moov_grille(struct_grille_cc** grille, position pos, char dep){

    position pos1 = pos;
    position pos2 = pos;
    char char_temp1 = grille[pos1.y][pos1.x].car;
    int color_temp1 = grille[pos1.y][pos1.x].num;

    // check si le dep est possible !!! pas encore fait car dep des versions !!
    if (dep == 'U'){
        pos2.y -=1;
    }
    else if(dep == 'D'){
        pos2.y += 1;
    }
    else if(dep == 'L'){
        pos2.x -=1;
    }
    else if(dep == 'R'){
        pos2.x +=1;
    }
    else{printf("tg t con\n");}

    char char_temp2 = grille[pos2.y][pos2.x].car;
    int color_temp2 = grille[pos2.y][pos2.x].num;

    grille[pos1.y][pos1.x].car = char_temp2;
    grille[pos1.y][pos1.x].num = color_temp2;
    grille[pos2.y][pos2.x].car = char_temp1;
    grille[pos2.y][pos2.x].num = color_temp1;

    return grille;
}//==================================================================================================================


//Fonction qui supp les positions placer en parametre

struct_grille_cc** supp_case(position* all_position, struct_grille_cc** grille, int taille)
{

    for(int i=0;i<taille;i++){
        int pos_x = all_position[i].x;
        int pos_y = all_position[i].y;

        grille[pos_y][pos_x].car = '.';
        grille[pos_y][pos_x].num = 15;
    }

    return grille;
}


// Fonction qui calcule les points et qui supp les lignes
//Ne calcule pas encore les points a définir !
//Il faut faire la diagonale aussi !


score_grille supp_score(struct_grille_cc** grille, int n, int m){
    score_grille score;
    position all_pos[n*m];
    int count_pos=0;

    // boucle qui check en ligne ! ===================
    int count_x = 1;
    int supp_x = 0;

    for(int i=0;i<n;i++){
        char car_x_1 = grille[i][0].car;
        for(int j=1;j<m;j++){
            char car_x_2 = grille[i][j].car;
            if(car_x_1==car_x_2){
                count_x+=1;
                if(count_x>=3){
                    supp_x = 1;
                }
            }
            else{
                if (supp_x==1){

                    // permet d'ajouter les positions a supp dans le tableau
                    for(int z=1;z<=count_x;z++){
                        position pos;
                        pos.x=j-z;
                        pos.y=i;
                        all_pos[count_pos] = pos;
                        count_pos+=1;
                    }
                }
                supp_x = 0;
                count_x = 1;
            }
            car_x_1 = car_x_2;
        }
        if (supp_x==1){

            // permet d'ajouter les positions a supp dans le tableau
            for(int z=1;z<=count_x;z++){
                position pos;
                pos.x=m-z;
                pos.y=i;
                all_pos[count_pos] = pos;
                count_pos+=1;
            }
        }
        supp_x = 0;
        count_x = 1;
    }

    // boucle qui check en colonne ! ===================
    int count_y = 1;
    int supp_y = 0;

    for(int i=0;i<m;i++){
        char car_y_1 = grille[0][i].car;
        for(int j=1;j<n;j++){
            char car_y_2 = grille[j][i].car;
            if(car_y_1==car_y_2){
                count_y+=1;
                if(count_y>=3){
                    supp_y = 1;
                }
            }
            else{
                if (supp_y==1){
                    // permet d'ajouter les positions a supp dans le tableau
                    for(int z=1;z<=count_y;z++){
                        position pos;
                        pos.x=i;
                        pos.y=j-z;
                        all_pos[count_pos] = pos;
                        count_pos+=1;
                    }
                }
                supp_y = 0;
                count_y = 1;
            }
            car_y_1 = car_y_2;
        }
        if (supp_y==1){
            for(int z=1;z<=count_y;z++){
                position pos;
                pos.x=i;
                pos.y=n-z;
                all_pos[count_pos] = pos;
                count_pos+=1;
            }
        }
        supp_y = 0;
        count_y = 1;
    }

    //le tableau est cree avec tt les pos a supp, mnt on les supp
    struct_grille_cc** g_supp = supp_case(all_pos, grille, count_pos);
    score.grille = g_supp;
    score.points = 10;

    return score;
}


// Main a revoir, car .h apres je test sur maxime.c
int main()
{
    //variable de base pour le code, initalisation
    srand(time( NULL ));
    color(15,0);
    int n=5;
    int m=5;

    //reste du code
    struct_grille_cc** grille = creation_full_grille(n, m);
    affichage(n,m,grille);

    int stop = 1;
    while (stop == 1){
        position position;
        char dep;
        printf("Merci de donner la position et le déplacer de votre pion (X/Y/DEP):\n");
        scanf("%d/%d/%c",&position.x,&position.y,&dep); // pouvoir choisir A1 ou B5 de cette facon la.

        struct_grille_cc** grille_temp = moov_grille(grille, position, dep);

        if(dep == 'S'){stop=0;}
        else{
            affichage(n,m,grille_temp);
            grille = grille_temp;
        }
    }



    return 0;
}

// ca avance tres bien

/*
 * Cree une fonction qui check si aucune case ne se touchent 3 ou plus
 * Cree un systeme de score
 * Cree la possibilité de sauvgarder ( A CHAQUE TOUR CA SE SAUVGARDE AUTO )
 * Menu pour lancer le jeu et voir son meilleur score
 * Afficher chaque progression avec le score en cour
 * Cree un systeme de bonus ???
 * Dans le menu possibilité de choisir son mode !!
 *
 * Faire 1 mode facile, une mode moyen, un mode difficile un mode personnalisé
 * dasn chaque mode donner le meilleur score et le nbr de coup qu'il reste.
 *
 * faire un dossier réglage avec tous les paramètre modifiable via le dossier que le jeu va prendre en compte
 *
 */


/* libérer la mémoire allouée dynamiquement
for (int i = 0; i < 10; i++) {
free(g[i]);
}
free(g); /!\ A AJOUTER QUAND ON REVIENT AU MENU POUR LIBERER LA MEMOIR? APRES LA SAUVEGARDE ATTENTION !!!! */