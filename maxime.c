#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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

score_set score(random_char_color** grille,int n,int m){
    score_set score;
    int count_x = 1;
    int supp_x = 0;

    // boucle qui check en ligne !
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
                    printf(" i : %d, count_x : %d, char : %c\n",i,count_x,car_x_1);
                }
                supp_x = 0;
                count_x = 1;
            }
            car_x_1 = car_x_2;
        }
        if (supp_x==1){
            printf(" i : %d, count_x : %d, char : %c\n",i,count_x,car_x_1);
        }
        supp_x = 0;
        count_x = 1;
    }


    char car_y_1 = grille[0][0].car;
    int count_y = 0;
    // parcourir les y, x par x
    for(int i;i<m;i++){
        for(int j;j<n;j++){
        }
    }
    return score;
}

char** supp_case(position* all_position, random_char_color** grille,int taille)
{

    for(int i=0;i<taille;i++){
        int pos_x = all_position[i].x;
        int pos_y = all_position[i].y;

        grille[pos_y][pos_x].car = ' ';
        grille[pos_y][pos_x].num = 15;
    }

    return grille;
}

int main()
{
    srand(8);
    color(15,0);
    int n=10;
    int m=10;

    random_char_color** grille = creation_full_grille(n,m);
    affichage(n,m,grille);

    score_set s = score(grille,n,m);

    return 0;
}

// pour ligne : seed 4

/*
 *
 *
 * position pos1;
    position pos2;
    position pos3;
    pos1.x = 2;
    pos1.y = 2;
    pos2.x = 3;
    pos2.y = 3;
    pos3.x = 1;
    pos3.y = 1;

    int taille = 3;
    position* tab_pos = malloc(sizeof(position)*taille);
    tab_pos[0] = pos1;
    tab_pos[1] = pos2;
    tab_pos[2] = pos3;
    random_char_color** g = supp_case(tab_pos, grille, taille);

    free(tab_pos);
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
*/