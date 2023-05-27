#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "..\header\game.h"


// Fonction qui permet de changer la couleur des caractères de la consol

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

struct_grille_cc** creation_full_grille(param_struct all_param)
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


// Fonction qui reenvoie la grille avec les position supprimé

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


// Fonction esthétique qui remplace '.' par '*' pour l'animation

struct_grille_cc** supp_case1(position* all_position, struct_grille_cc** grille, int taille)
{

    for(int i=0;i<taille;i++){
        int pos_x = all_position[i].x;
        int pos_y = all_position[i].y;

        grille[pos_y][pos_x].car = '*';
        grille[pos_y][pos_x].num = 15;
    }

    return grille;
}


// Supprime tous les symboles aligné

score_grille glob_supp_score(struct_grille_cc** grille, int n, int m,int start)
{

    score_grille score;
    position all_pos[n*m];
    int count_pos=0;
    int count_score = 0;
    score.points = 0;


    // ================ Boucle qui check en ligne ! ================

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
                    count_score += 3+(count_x-3)*1.5;
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
            count_score += 3+(count_x-3)*1.5;
        }

        supp_x = 0;
        count_x = 1;
    }


    // ================ Boucle qui check en colonne ! ================

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
                    count_score += 3+(count_y-3)*1.5;
                }
                supp_y = 0;
                count_y = 1;
            }
            car_y_1 = car_y_2;
        }

        if (supp_y==1){

            // Permet d'ajouter les positions a supprimé dans le tableau
            for(int z=1;z<=count_y;z++){
                position pos;
                pos.x=i;
                pos.y=n-z;
                all_pos[count_pos] = pos;
                count_pos+=1;
            }
        }
        count_score += 3+(count_y-3)*1.5;
        supp_y = 0;
        count_y = 1;
    }


    // ================ Boucle qui supp en diagonale ================

    // Check chaque ligne
    for(int i=0;i<n;i++) {

        // ================ Pour la colonne 1 ================
        if (i == 0) {

            for (int j = 0; j < m; ++j) {

                // Variable de base nécessaire
                char car1 = grille[0][j].car;
                int k = 1;
                int count_car = 1;
                int bool_diag = False;
                position tab[n+m];
                int tab_count = 0;

                position pos;
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
                            count_score += 3+(count_car-3)*1.5;
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
                    count_score += 3+(count_car-3)*1.5;
                }
            }
        }


            // ================ Pour la dernière colonne ================

        else if(i==(n-1)){
            for (int j = 0; j < m; ++j) {

                //Variable de base
                char car1 = grille[n-1][j].car;
                int k = 1;
                int count_car = 1;
                int bool_diag = False;
                position tab[n+m];
                int tab_count = 0;

                position pos;
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
                                all_pos[count_pos] = pos1;
                                count_pos ++;
                            }
                            count_score += 3+(count_car-3)*1.5;
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
                    count_score += 3+(count_car-3)*1.5;
                }
            }
        }

            // Pour toute les autres colonnes

        else {

            // ================ Vers le bas ================

            //Variable de base
            char car1 = grille[i][0].car;
            int k = 1;
            int count_car = 1;
            int bool_diag = False;
            position tab[n + m];
            int tab_count = 0;

            position pos;
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
                        count_score += 3+(count_car-3)*1.5;
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
                count_score += 3+(count_car-3)*1.5;
            }


            // ================ Vers le haut ================

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
                        count_score += 3+(count_car-3)*1.5;
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
                count_score += 3+(count_car-3)*1.5;
            }
        }
    }

    if((start==0)&&(count_pos!=0)) {
        affichage(n, m, grille);
        sleep(1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    // Supprimer les case contenu dans all_pos
    struct_grille_cc **g_supp = supp_case(all_pos, grille, count_pos);

    // Permet de faire l'animation qui montre ce que l'utilisateur supp
    if((start==0)&&(count_pos!=0)) {
        // def affichage styler ici


        affichage(n, m, g_supp);
        sleep(1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        g_supp = supp_case1(all_pos, grille, count_pos);
        affichage(n, m, g_supp);
        sleep(1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        g_supp = supp_case(all_pos, grille, count_pos);
        affichage(n, m, g_supp);
        sleep(1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    score.grille = g_supp;
    score.points = count_score;

    return score;
}


// Fonction qui gère la gravité de la grille

struct_grille_cc** grille_gravite(struct_grille_cc** grille, int n, int m)
{

    // Vers la droite
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
    return grille;
}


// Fonction qui remplir une grille de facon optimiser

struct_grille_cc** remplir_grille(struct_grille_cc** grille, param_struct all_param)
{

    char tab[6] = {'X','O','@','+','Y','C'};
    int color[6] = {14,12,1,2,5,4};
    int count_remp1=0;
    int count_remp2=4;
    for(int i=0;i<all_param.largeur;i++){
        for(int j=0;j<all_param.longueur;j++){

            if(grille[i][j].car == '.'){

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


// Fonction qui reenvoie une grille prête a jouer

struct_grille_cc** start_grille(struct_grille_cc** grille, param_struct all_param)
{
    int score = 1;
    while (score>0){

        score_grille grille_score = glob_supp_score(grille, all_param.largeur, all_param.longueur,1);

        struct_grille_cc** grille1 = grille_gravite(grille_score.grille, all_param.largeur, all_param.longueur);

        struct_grille_cc** grille2 = remplir_grille(grille1, all_param);

        grille = grille2;
        score = grille_score.points;
        // affichage(all_param.largeur, all_param.longueur,grille);
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


// Libère les mallocs de notre grille

void liber_malloc(struct_grille_cc** grille,int n,int m)
{
    for (int i = 0; i < 10; i++) {
        free(grille[i]);
    }
    free(grille);
}


// Fonction qui gere la reaction en chaine du jeu

score_grille grille_reac_chaine(struct_grille_cc** grille,int n,int m)
{
    // Variable de base
    int score = 1;
    int all_score = 0;
    score_grille struct_grille_score;

    while (score>0){
        // supp les choses a supp
        score_grille grille1 = glob_supp_score(grille, n, m,0);

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


// Fonction qui verifie si les entre sont bonne

int check_entry_good(char car,int num,int n,int m){
    if (car == 'q'){
        return 2;
    }
    if ((car<65)||(car>=65+m)){ // largueur
        return 0;
    }
    else if((num>n)||(num<=0)){ // longueur
        return 0;
    }
    else{
        return 1;
    }

}


// Fonction qui fait tourner le jeu a partir d'une grille

score_grille game(struct_grille_cc** grille,int n,int m,int score)
{
    int finish = 1;
    while(finish!=0) {

        position pos1;
        position pos2;
        struct_grille_cc position1;
        struct_grille_cc position2;

        printf("\nScore actuel : %d \n", score);

        printf("\nIndiquez la position des symboles que vous voulez changer.\n");
        printf("Par exemple : 'A3' ou 'B4' (ou 'quitter' pour quitter)\n\n");

        int pos1_valide = 1;
        int trop = 0 ;

        while (pos1_valide) {
            printf("Position 1 : ");
            scanf("%1c%2d", &position1.car, &position1.num);
            while (getchar() != '\n');

            if (check_entry_good(position1.car, position1.num, n, m) == 2) {

                finish = 0;
                pos1_valide = 0;
            } else if (check_entry_good(position1.car, position1.num, n, m) == 1) {
                pos1_valide = 0;
                finish = 1;
            } else {
                if (trop > 2){
                    printf("Vous faites trop d'erreurs, merci de vous assurer des choses suivantes : \n\n");
                    printf("- Les lettres doivent etre en majuscule \n");
                    printf("- Entrez une seule position a la fois (Exemple : 'A3' ou 'B5') \n");
                    printf("- Verifier si la position est comprise dans la grille \n\n");
                    trop = 0 ;

                }else {
                    printf("Position inexistante, veuillez recommencer.\n");
                    trop += 1 ;
                }

            }

        }
        pos1.y = position1.num - 1;
        pos1.x = position1.car - 65;

        int pos2_valide = 1;

        while (pos2_valide && finish == 1) {
            printf("Position 2 : ");
            scanf("%1c%2d", &position2.car, &position2.num);
            while (getchar() != '\n');

            if (check_entry_good(position2.car, position2.num, n, m) == 2) {
                finish = 0;
                pos2_valide = 0;
            } else if (check_entry_good(position2.car, position2.num, n, m) == 1) {
                pos2_valide = 0;
                finish = 1;
            } else {
                if (trop > 2){
                    printf("Vous faites trop d'erreurs, merci de vous assurer des choses suivantes : \n\n");
                    printf("- Les lettres doivent etre en majuscule \n");
                    printf("- Entrez une seule position a la fois (Exemple : 'A3' ou 'B5')\n");
                    printf("- Verifier si la position est comprise dans la grille \n\n");
                    trop = 0 ;

                }else {
                    printf("Position inexistante, veuillez recommencer.\n");
                    trop += 1 ;
                }
            }

        }
        pos2.y = position2.num - 1;
        pos2.x = position2.car - 65;

        if (finish == 1) {

            // On déplace le coup.
            struct_grille_cc **grille2 = deplacement_grille(grille, pos1, pos2);
            affichage(n, m, grille2);
            printf("\n");

            // Reaction en chaine
            score_grille struct_grille_score;
            struct_grille_score = grille_reac_chaine(grille2, n, m);

            grille = struct_grille_score.grille;
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            affichage(n, m, grille);
            printf("\n");

            if (struct_grille_score.points == 0) {
                finish = 0;
            }
            else {
                score += struct_grille_score.points;
            }
        }
    }
    score_grille grille_fin_return;
    grille_fin_return.grille = grille;
    grille_fin_return.points = score;
    return grille_fin_return;
}