#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "..\header\game.h"


/* Fonction qui permet de changer la couleur des caractères de la consol */

void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

// Fonction qui choisi un caractere aléatoire parmis la liste prédéfinis

struct_grille_cc random_char(int nbr_symbole)
{
    struct_grille_cc zz;
    int r = rand()%nbr_symbole;
    char tab[6] = {'X','O','@','+','Y','C'};
    int color[6] = {14,12,1,2,5,4};
    zz.car = tab[r];
    zz.num = color[r];
    return zz;
}


// fonction qui cree une grille a partir de 2 dimensions

struct_grille_cc** creation_full_grille(param_struct_game all_param)
{

    struct_grille_cc** tab = malloc(all_param.largeur * sizeof(struct_grille_cc*));
    for (int i = 0; i < all_param.largeur; i++) {
        tab[i] = malloc(all_param.longueur * sizeof(struct_grille_cc));
        for (int j = 0; j < all_param.longueur; j++) {
            tab[i][j] = random_char(all_param.symbole);
        }
    }
    return tab;
}


// fonction qui affiche la grille en parametre en fonction de la taille

void affichage(int n, int m, struct_grille_cc** grille)
{
    for(int p=0;p<2;p++){
        printf("    ");
        for(int k=0;k<m;k++){
            if(p==0){
                printf("%c ",'A'+k);
            }
            else{ printf("_ ");}
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){

        if(i<9){printf("%d  |",1+i);}
        else{printf("%d |",1+i);}

        for( int j=0;j<m;j++){
            color(grille[i][j].num,0);
            printf("%c ",grille[i][j].car);
        }
        printf("\n");
        color(15,0);
    }
}


// Fonction qui reenvoie la grille avec les position supp

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



// Renvoie uns structure avec la grille supprimer et le score

score_grille glob_supp_score(struct_grille_cc** grille, int n, int m)
{

    score_grille score;
    position all_pos[n*m];
    int count_pos=0;
    int count_score = 0;
    score.points = 0;


    // boucle qui check en ligne ! ===================
    int count_x = 1;
    int supp_x = 0;

    for(int i=0;i<n;i++){
        char car_x_1 = grille[i][0].car;
        for(int j=1;j<m;j++){
            char car_x_2 = grille[i][j].car;
            if((car_x_1==car_x_2)&&(car_x_1!='.')){
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
                count_score += count_x; // a modifier
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
        count_score += count_x;
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
            if((car_y_1==car_y_2)&&(car_y_1!='.')){
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
                count_score += supp_y;
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
        count_score += supp_y;
        supp_y = 0;
        count_y = 1;
    }


    // Boucle qui supp en diagonale =======================================


    // Pour chaque ligne :
    for(int i=0;i<n;i++) {

        // Colonne 1 ======================================================
        if (i == 0) {

            for (int j = 0; j < m; ++j) {

                //Variable de base
                char car1 = grille[0][j].car;
                int k = 1;
                int count_car = 1;
                int bool_diag = False;
                position tab[n+m];
                int tab_count = 0;

                position pos; // Attention X et Y inverser !
                pos.x=j;
                pos.y=0;

                tab[tab_count] = pos;
                while ((i+k<n)&&(j+k<m)){
                    char car2 = grille[k][j+k].car;
                    pos.x=j+k;
                    pos.y=k;
                    if((car1==car2)&&(car2!='.')){
                        count_car++;
                        if(count_car>=3){bool_diag = True;}
                        tab_count++;
                        tab[tab_count] = pos;
                    }

                    else{
                        if(bool_diag){
                            for (int z = 0; z < count_car; ++z) {
                                position pos1 = tab[z];
                                all_pos[count_pos] = pos1;
                                count_pos ++;
                            }
                        }
                        count_car=1;
                        tab_count=0;
                        tab[tab_count] = pos;
                        bool_diag = False;

                    }
                    car1=car2;
                    k++;
                }
                if(bool_diag){
                    for (int z = 0; z < count_car; ++z) {
                        position pos1 = tab[z];
                        all_pos[count_pos] = pos1;
                        count_pos ++;
                    }
                }
            }
        }



        // Colonne n-1 ========================================================

        else if(i==(n-1)){
            for (int j = 0; j < m; ++j) {

                //Variable de base
                char car1 = grille[n-1][j].car;
                int k = 1;
                int count_car = 1;
                int bool_diag = False;
                position tab[n+m];
                int tab_count = 0;

                position pos; // Attention X et Y inverser !
                pos.x=j;
                pos.y=n-1;

                tab[tab_count] = pos;
                while (((n-1)-k>0)&&(j+k<m)){
                    char car2 = grille[n-1-k][j+k].car;
                    pos.x=j+k;
                    pos.y=n-1-k;
                    if((car1==car2)&&(car2!='.')){
                        count_car++;
                        if(count_car>=3){bool_diag = True;}
                        tab_count++;
                        tab[tab_count] = pos;
                    }

                    else{
                        if(bool_diag){
                            for (int z = 0; z < count_car; ++z) {
                                position pos1 = tab[z];
                                //printf("X : %d, Y : %d\n",pos1.x,pos1.y);
                                all_pos[count_pos] = pos1;
                                count_pos ++;
                            }
                        }
                        count_car=1;
                        tab_count=0;
                        tab[tab_count] = pos;
                        bool_diag = False;

                    }
                    car1=car2;
                    k++;
                }
                if(bool_diag){
                    for (int z = 0; z < count_car; ++z) {
                        position pos1 = tab[z];
                        all_pos[count_pos] = pos1;
                        count_pos ++;
                    }
                }
            }
        }

        //Toute les autres colonnes
        else {

            // Vers le bas =========================================

            //Variable de base
            char car1 = grille[i][0].car;
            int k = 1;
            int count_car = 1;
            int bool_diag = False;
            position tab[n + m];
            int tab_count = 0;

            position pos; // Attention X et Y inverser !
            pos.x = 0;
            pos.y = i;
            tab[tab_count] = pos;

            while ((i + k < n) && (k < m)) {
                char car2 = grille[i + k][k].car;
                pos.x = k;
                pos.y = i + k;

                if ((car1 == car2) && (car2 != '.')) {
                    count_car++;
                    if (count_car >= 3) { bool_diag = True; }
                    tab_count++;
                    tab[tab_count] = pos;
                } else {
                    if (bool_diag) {
                        for (int z = 0; z < count_car; ++z) {
                            position pos1 = tab[z];
                            all_pos[count_pos] = pos1;
                            count_pos++;
                        }
                    }
                    bool_diag = False;
                    count_car = 1;
                    tab_count = 0;
                    tab[tab_count] = pos;

                }
                car1 = car2;
                k++;
            }
            if (bool_diag) {
                for (int z = 0; z < count_car; ++z) {
                    position pos1 = tab[z];
                    all_pos[count_pos] = pos1;
                    count_pos++;
                }
            }

            // Vers le haut ========================================
            car1 = grille[i][0].car;
            k = 1;
            count_car = 1;
            bool_diag = False;
            tab_count = 0;

            pos.x = 0;
            pos.y = i;
            tab[tab_count] = pos;

            while ((i - k >= 0) && (k < m)) {
                char car2 = grille[i - k][k].car;
                pos.x = k;
                pos.y = i - k;
                if ((car1 == car2) && (car2 != '.')) {
                    count_car++;
                    if (count_car >= 3) { bool_diag = True; }
                    tab_count++;
                    tab[tab_count] = pos;
                }
                else {
                    if (bool_diag) {
                        for (int z = 0; z < count_car; ++z) {
                            position pos1 = tab[z];
                            all_pos[count_pos] = pos1;
                            count_pos++;
                        }
                    }
                    bool_diag = False;
                    count_car = 1;
                    tab_count = 0;
                    tab[tab_count] = pos;

                }
                car1 = car2;
                k++;
            }
            if (bool_diag) {
                for (int z = 0; z < count_car; ++z) {
                    position pos1 = tab[z];
                    all_pos[count_pos] = pos1;
                    count_pos++;
                }


            }
        }
    }


    //le tableau est cree avec tt les pos a supp, mnt on les supp
    struct_grille_cc** g_supp = supp_case(all_pos, grille, count_pos);
    score.grille = g_supp;
    score.points = count_pos; // a modifier

    return score;
}


// Fonction qui gère la gravité de la grille

struct_grille_cc** grille_gravite(struct_grille_cc** grille, int n, int m)
{
    // pour pouvoir changé la direction ultérieurement
    char direction = 'R';

    //Gravité à droite
    if (direction == 'R'){

        for(int i=0;i<n;i++){
            struct_grille_cc grav_rest[m];
            int count_grav_tab = 0;
            for(int j=m;j>=0;j--){
                char car_dep_grav = grille[i][j].car;
                int col_dep_grav = grille[i][j].num;
                if (car_dep_grav != '.'){
                    grav_rest[count_grav_tab].car = car_dep_grav;
                    grav_rest[count_grav_tab].num = col_dep_grav;
                    count_grav_tab +=1;
                }
            }
            for (int w=0;w<count_grav_tab;w++){
                grille[i][m-w].car = grav_rest[w].car;
                grille[i][m-w].num = grav_rest[w].num;
            }

            for(int y=count_grav_tab;y<=m;y++){
                grille[i][m-y].car = '.';
                grille[i][m-y].num = 15;
            }
        }
    }
    return grille;
}


// Fonction qui remplit une grille aléatoirement

struct_grille_cc** remplir_grille(struct_grille_cc** grille, param_struct_game all_param)
{

    char tab[6] = {'X','O','@','+','Y','C'};
    int color[6] = {14,12,1,2,5,4};
    int count_remp1=0;
    int count_remp2=4;
    for(int i=0;i<all_param.largeur;i++){
        for(int j=0;j<all_param.longueur;j++){

            if(grille[i][j].car == '.'){ // pour 5 carac ca marche nicke

                    if((j>0)&&(j<all_param.longueur-1)&&(i>0)&&(i<all_param.largeur-1)){
                        struct_grille_cc rdm_car = random_char(all_param.symbole);
                        int fin = 1;
                        int stop = 0;
                        while ((fin==1) || (stop < all_param.symbole)){
                            rdm_car.car = tab[stop];
                            rdm_car.num = color[stop];
                            if ((rdm_car.car != grille[i][j-1].car)&&(rdm_car.car != grille[i][j+1].car)&&(rdm_car.car != grille[i-1][j].car)&&(rdm_car.car != grille[i+1][j].car)){
                                fin=0;
                            }
                            stop ++;
                        }
                        if (stop == all_param.symbole-1 ){
                            grille[i][j] = rdm_car;
                        }
                        else{
                            grille[i][j] = random_char(all_param.symbole);
                        }
                    }
                    else{
                        grille[i][j] = random_char(all_param.symbole);
                    }
            }
        }
    }
    return grille;
}


// Fonction qui prend une grille en paramètre et qui reenvoie une grille prête a jouer

struct_grille_cc** start_grille(struct_grille_cc** grille, param_struct_game all_param)
{
    int score = 1;
    while (score>0){

        score_grille grille_score = glob_supp_score(grille, all_param.largeur, all_param.longueur);

        struct_grille_cc** grille1 = grille_gravite(grille_score.grille, all_param.largeur, all_param.longueur);

        struct_grille_cc** grille2 = remplir_grille(grille1, all_param);

        grille = grille2;
        score = grille_score.points;
        affichage(all_param.largeur, all_param.longueur,grille);
    }
    return grille;
}

//Fonction qui permet de déplacer les pions dans la grille

struct_grille_cc** deplacement_grille(struct_grille_cc** grille,position pos1,position pos2)
{

    int pos1_x = pos1.x;
    int pos1_y = pos1.y;
    struct_grille_cc case1;
    case1.car = grille[pos1_y][pos1_x].car;
    case1.num = grille[pos1_y][pos1_x].num;

    int pos2_x = pos2.x;
    int pos2_y = pos2.y;
    struct_grille_cc case2;
    case2.car = grille[pos2_y][pos2_x].car;
    case2.num = grille[pos2_y][pos2_x].num;

    grille[pos1_y][pos1_x] = case2;
    grille[pos2_y][pos2_x] = case1;

    return grille;
}

// Fonction qui gere la reaction en chaine

score_grille grille_reac_chaine(struct_grille_cc** grille,int n,int m)
{

    // Modifier cette fonction pour améliorer l'esthétique.

    int score = 1;
    int all_score = 0;
    score_grille struct_grille_score;
    while (score>0){
        // supp les choses a supp
        score_grille grille1 = glob_supp_score(grille, n, m);

        // Gravité de la grille
        struct_grille_cc** grille2 = grille_gravite(grille1.grille, n, m);

        score = grille1.points;
        all_score += score;
        grille = grille2;
    }

    struct_grille_score.points = all_score;
    struct_grille_score.grille = grille;
    return struct_grille_score;
}

// Fonction qui fait tourner le jeu

int game(struct_grille_cc** grille,int n,int m,int score)
{
    int finish = 1;
    while(finish!=0){

        position pos1;
        position pos2;

        printf("Indiquez la position des symboles que vous voulez changer.\n");
        printf("Par exemple : A3 ou B4\n");

        char pos_car;
        int pos_num;
        printf("Position 1 : ");
        scanf("%1c%1d",&pos_car,&pos_num); // Check les erreur, si == 2 et tte les infos comme on veut on continue
        while(getchar()!='\n'); // reset le scanf viens de internet
        pos1.y = pos_num-1;
        pos1.x = pos_car-65;

        printf("Position 2 : ");
        scanf("%1c%1d",&pos_car,&pos_num);
        while(getchar()!='\n');
        pos2.y = pos_num-1;
        pos2.x = pos_car-65;

        // On déplace le coup.
        struct_grille_cc** grille2 = deplacement_grille(grille, pos1,pos2);
        affichage(n,m,grille2);
        printf("\n");

        score_grille struct_grille_score;
        struct_grille_score = grille_reac_chaine(grille2,n,m);

        grille = struct_grille_score.grille;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        affichage(n,m,grille);
        printf("\n");

        if(struct_grille_score.points == 0){
            finish = 0;
        }
        else{
            score+=struct_grille_score.points;
        }

    }
    return score;
}