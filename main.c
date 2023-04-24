#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
// testtettete fares tu pu t trop moche nn je rigole je taime
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


/* Structure nécéssaire pour la suite */

typedef struct{
    int num;
    char car;
}random_char_color;

typedef struct{
    int x;
    int y;
}position;

typedef struct{
    int points;
    char** grille;
}score_set;


/* Fonction qui permet de changer la couleur des caractères de la consol */

void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}


// Fonction qui choisi un caractere aléatoire parmis la liste prédéfinis

random_char_color random_char()
{
    random_char_color zz;
    int r = rand()%4;
    char tab[4] = {'X','O','@','+'};
    int color[4] = {14,12,1,2};
    zz.car = tab[r];
    zz.num = color[r];
    return zz;
}


// fonction qui cree une grille a partir de 2 dimensions

char** creation_full_grille(int n,int m){

    random_char_color** tab = malloc(n * sizeof(random_char_color*));
    for (int i = 0; i < n; i++) {
        tab[i] = malloc(m * sizeof(random_char_color));
        for (int j = 0; j < m; j++) {
            tab[i][j] = random_char();
        }
    }
    return tab;
}


// fonction qui affiche la grille en parametre avec la taille

void affichage(int n, int m,random_char_color** grille)
{
    for(int p=0;p<2;p++){
        printf("   ");
        for(int k=0;k<m;k++){
            if(p==0){
                printf("%d ",k+1);
            }
            else{ printf("_ ");}
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){
        printf("%c |",'A'+i);
        for( int j=0;j<m;j++){
            color(grille[i][j].num,0);
            printf("%c ",grille[i][j].car);
        }
        printf("\n");
        color(15,0);
    }
}

// fonction qui permet de modifier la grille et la reenvoie

char** moov_grille(random_char_color** grille, position pos, char dep){

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

}
/*
// Fonction qui calcule les points et qui supp les lignes =================== en dev ==========================


score_set score(char** grille,int n,int m){
    score_set score;
    char car_x_1 = grille[0][0];
    int count_x;
    char car_y_1 = grille[0][0];
    int count_y;
    // Bien regarder n et m, inverser i et j dans le code !
    // parcourir les x, y par y
    for(int i;i<n;i++){
        for(int j;j<m;j++){
            char car_x_2 = grille[i][j];
            if(car_x_1==car_x_2){count_x+=1;}
            if(count_x>=3){ printf("");} // supp les cases si c'est finis. check si encore + ou si fin du tableau.
            // cree d'autre variable pour check si

            // cree une fonction qui supp les case comme ca plus facile de check si la grille a ete modifier suffit
            // d'ajouter un compteur dans la fonction qui supp les cases si elle ne bouge pas on modifie

        }
    }
    // parcourir les y, x par x
    for(int i;i<m;i++){
        for(int j;j<n;j++){

        }
    }


    return score;
}*/
            /*
             * ont cree une fonction qui supp, des qu'il y a des case je lui enoie un tab avec les case a supp,
             * elle supp et elle ajoute 1 a un compteur personnel a la fin de la fonction on vérifie si ce compteur
             * a été modifier pour savoir si la fonction a été utiliser, si la grille n'a pas été modifier elle peut
             * etre afficher car on a finis de la "traiter"
             * cree aussi une fonction qui a chaque tour fait déscendre les cases quand on a finis de tt tt check
             * on check tte la grille une fois on fait tt déscendre, si y'a eu des modife on refait sinon
             * on refait pareil on check tte la grile et on fait déscendre ainsie de suite jusqua plus de modif.
             * on reenvoie le score a chaque fois mais on commence a le compter a partir du premier coup.
             * on a du taff lol c pas des hehe
             *
             */
//======================================================================================================================


int main()
{
    //variable de base pour le code, initalisation
    srand(time( NULL ));
    color(15,0);
    int n=5;
    int m=5;

    //reste du code
    random_char_color** grille = creation_full_grille(n,m);
    affichage(n,m,grille);

    int stop = 1;
    while (stop == 1){
        position position;
        char dep;
        printf("Merci de donner la position et le déplacer de votre pion (X/Y/DEP):\n");
        scanf("%d/%d/%c",&position.x,&position.y,&dep); // pouvoir choisir A1 ou B5 de cette facon la.

        random_char_color** grille_temp = moov_grille(grille,position,dep);

        if(dep == 'S'){stop=0;}
        else{
            affichage(n,m,grille_temp);
            grille = grille_temp;
        }
    }

    return 0;
}

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
 */


/* libérer la mémoire allouée dynamiquement
for (int i = 0; i < 10; i++) {
free(g[i]);
}
free(g); /!\ A AJOUTER QUAND ON REVIENT AU MENU POUR LIBERER LA MEMOIR? APRES LA SAUVEGARDE ATTENTION !!!! */