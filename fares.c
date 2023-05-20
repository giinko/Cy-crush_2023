#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



#define True 1
#define False 0


/* Structure nécéssaire pour la suite ================ */

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
    struct_grille_cc** grille;
}score_grille;


// ==========================================================

typedef struct score score;

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

struct_grille_cc** creation_full_grille(int n,int m){

    struct_grille_cc** tab = malloc(n * sizeof(struct_grille_cc*));
    for (int i = 0; i < n; i++) {
        tab[i] = malloc(m * sizeof(struct_grille_cc));
        for (int j = 0; j < m; j++) {
            tab[i][j] = random_char();
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
score_grille glob_supp_score(struct_grille_cc** grille, int n, int m){

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


    // Boucle qui supp en diagonale ====================
    // ===============================================================================

   // affichage(n,m,grille);

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
                    //printf("X : %d, Y : %d, count : %d, char : %c | %c\n",pos.x,pos.y,count_car,car1,car2);
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
                        //printf("X : %d, Y : %d\n",pos1.x,pos1.y);
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
struct_grille_cc** grille_gravite(struct_grille_cc** grille, int n, int m){
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
struct_grille_cc** remplir_grille(struct_grille_cc** grille, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grille[i][j].car == '.'){
                grille[i][j] = random_char();
            }
        }
    }
    return grille;
}


// Fonction qui prend une grille en paramètre et qui reenvoie une grille prête a jouer
struct_grille_cc** start_grille(struct_grille_cc** grille, int n, int m){
    int score = 1;
    while (score>0){

        score_grille grille_score = glob_supp_score(grille, n, m);

        struct_grille_cc** grille1 = grille_gravite(grille_score.grille, n, m);

        struct_grille_cc** grille2 = remplir_grille(grille1, n, m);

        grille = grille2;
        score = grille_score.points;
    }
    return grille;
}

//Fonction qui permet de déplacer les pions dans la grille
struct_grille_cc** deplacement_grille(struct_grille_cc** grille,position pos1,position pos2){

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
score_grille grille_reac_chaine(struct_grille_cc** grille,int n,int m){

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

int verif_position(char pos_car, int pos_num, int na, int ma){

    if ((pos_car - 'A' < na) && (pos_num < ma)) {
        return = 1;
    } else {
        printf("Coordonnées invalides. Veuillez entrer des coordonnées valides.\n");
    }

}

// Fonction qui fait tourner le jeu
int game(struct_grille_cc** grille,int n,int m,int score){
    int finish = 1;
    while(finish!=0){

        //Déplacement sur la grille ======== voir si possiblité de créé une fonction !!
        // Cree une struc avec 2 pos, puis une focntion qui reenvoie 2 pos !!
        position pos1;
        position pos2;

        printf("Indiquez moi la position des points que vous voulez changer.\n");
        printf("Par exemple : A:3, B:4, j'echange a3 et b4\n");

        char pos1_car;
        int pos1_num;
        char pos2_car;
        int pos2_num;

        int valid_input = 0;

        while (!valid_input) {

            printf("Position 1 : ");
            scanf("%1c%1d",&pos1_car,&pos1_num); // Check les erreur, si == 2 et tte les infos comme on veut on continue
            while(getchar() != '\n'); // reset le scanf viens de internet
            pos1.y = pos1_num-1;
            pos1.x = pos1_car-65;

            // Vérification des coordonnées 1
            valid_input = verif_position(pos1_car, pos1_num, n, m);

            printf("Position 2 : ");
            scanf("%1c%1d",&pos2_car,&pos2_num);
            while(getchar()!='\n');
            pos2.y = pos2_num-1;
            pos2.x = pos2_car-65;

            // Vérification des coordonnées 2
            valid_input = verif_position(pos2_car, pos2_num, n, m);
        }

        // On déplace le coup.
        struct_grille_cc** grille2 = deplacement_grille(grille, pos1,pos2);
        affichage(n,m,grille2);
        printf("\n");

        score_grille struct_grille_score;
        struct_grille_score = grille_reac_chaine(grille2,n,m);

        grille = struct_grille_score.grille;
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
void changement_taillegrille(int* pnc, int* pmc) {

    printf("\n\n\n"
           "   ______         ______                __  \n"
           "  / ____/_  __   / ____/______  _______/ /_ \n"
           " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
           "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
           "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
           "     /____/                                 \n\n");

    printf("Taille actuelle de la grille : %d en longueur, et %d en largeur.\n", *pnc, *pmc);
    printf("Merci de saisir des nombres inferieur a 20.\n");
    printf("Vous serez ensuite dirige au menu principal.\n\n");
    printf("Nouvelle la taille en longueur : ");
    scanf("%d", pmc);
    while (*pmc > 20) {
        printf("Votre grille sera trop longue ! Choisissez un nombre plus petit.\n");
        printf("Nouvelle la taille en largeur : ");
        scanf("%d", pmc);
    }

    printf("Changez la taille en largeur : ");
    scanf("%d", pnc);
    while (*pnc > 20) {
        printf("Votre grille sera trop large ! Choisissez un nombre plus petit.\n");
        printf("Changez la taille en largeur : ");
        scanf("%d", pnc);
    }
}

void parametres(int* pnb, int* pmb) {
    int fin2 = 0;
    int choix;

    while (!fin2) {
        int c2;

        /* affichage menu-paramètres */

        printf("\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                 \n\n");
        printf("Parametres : \n");
        printf("[1] - Changer la taille de la grille\n"
               "[2] - Changer le sens de gravite\n"
               "[3] - Activer/desactiver les jokers :\n"
               "[4] - Revenir au menu principal\n");

        printf("Je fais le choix numero : ");
        c2 = getchar();

        /* suppression des caracteres dans stdin */
        if (c2 != '\n' && c2 != EOF) {
            int d;
            while ((d = getchar()) != '\n' && d != EOF);
        }

        switch (c2) {
            // changer la taille de la grille
            case '1':
                changement_taillegrille(pnb, pmb);
                fin2 = 1;
                break;
                // changer le sens de la gravité
            case '2':
                fin2 = 1;
                break;
                // Activer/désactiver Joker
            case '3':
                printf("Choix 3\n");
                fin2 = 1;
                break;
                // quitter
            case '4':
                fin2 = 1;
                break;
            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    }
}

int menu(int * pna, int * pma){
    int fin;

    fin = 0;
    while(!fin)
    {
        int c;

        /* affichage menu */

        printf("Maxime, Fares and Sany present :\n"
               "   ______         ______                __  \n"
               "  / ____/_  __   / ____/______  _______/ /_ \n"
               " / /   / / / /  / /   / ___/ / / / ___/ __ \\\n"
               "/ /___/ /_/ /  / /___/ /  / /_/ (__  ) / / /\n"
               "\\____/\\__, /   \\____/_/   \\__,_/____/_/ /_/ \n"
               "     /____/                                  \n\n");
        printf("[1] - Lancer le jeu\n"
               "[2] - Parametres\n"
               "[3] - Charger une grille\n"
               "[4] - Quitter\n");

        printf("Je fais le choix numero : "); c = getchar();

        /* suppression des caracteres dans stdin */
        if(c != '\n' && c != EOF)
        {
            int d;
            while((d = getchar()) != '\n' && d != EOF);
        }

        switch(c)
        {
            case '1':
                return 1 ;
                fin = 1;
                break;

            case '2':
                parametres(pna, pma);
                break;

            case '3':
                printf("Choix 3\n");
                return 3 ;
                fin = 1;
                break;

            case '4':
                fin = 1;
                break;

            default:
                printf("Choix invalide, veuillez recommencer.\n");
        }
    }
}
// Focntion main
int main()
{
    int n = 8 ;
    int m = 8 ;
    int* pn = &n;
    int* pm = &m;

   int menuu = menu(pn, pm) ;

if(menuu == 1) {
    srand(8);
    color(15, 0);

    // creation grille
    struct_grille_cc **grille = creation_full_grille(n, m);

    // Initialisation de la grille
    struct_grille_cc **grille3 = start_grille(grille, n, m);
    affichage(n, m, grille3);

    // Jeu
    int final_score;
    final_score = game(grille3, n, m, 0);

    printf("Le score final est de : %d", final_score);
    return 0;
}
}

// Fonction qui check si il y a toujours au moins 2 symbols sinon game finis !
// réflechir pas suffisent !!

// permet de bien comprendre l'enchainement !! voir fonction start aussi !
/*
    // supp les choses a supp
    score_grille s = glob_supp_score(grille,n,m);
    affichage(n,m,s.grille);
    printf("\n %d \n",s.points);

    // Gravité de la grille
    struct_grille_cc** grille1 = grille_gravite(s.grille, n, m);
    affichage(n,m,grille1);

    // Ajout des nouveaux symbols qui tombent.
    struct_grille_cc** grille2 = remplir_grille(grille1, n, m);
    affichage(n,m,grille2);
 */






// n ord et m abs, on va modif ca apres trop relou !!


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
    struct_grille_cc** g = supp_case(tab_pos, grille, taille);

    free(tab_pos);
int main()
{
    //variable de base pour le code, initalisation
    srand(time( NULL ));
    color(15,0);
    int n=5;
    int m=5;

    //reste du code
    struct_grille_cc** grille = creation_full_grille(n,m);
    affichage(n,m,grille);

    int stop = 1;
    while (stop == 1){
        position position;
        char dep;
        printf("Merci de donner la position et le déplacer de votre pion (X/Y/DEP):\n");
        scanf("%d/%d/%c",&position.x,&position.y,&dep); // pouvoir choisir A1 ou B5 de cette facon la.

        struct_grille_cc** grille_temp = moov_grille(grille,position,dep);

        if(dep == 'S'){stop=0;}
        else{
            affichage(n,m,grille_temp);
            grille = grille_temp;
        }
    }

    return 0;
}
*/