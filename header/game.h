#define True 1
#define False 0

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

typedef struct{
    int longueur;
    int largeur;
    int gravite;

}param_struct;

int game(struct_grille_cc** grille,int n,int m,int score);
struct_grille_cc** creation_full_grille(param_struct all_param);
struct_grille_cc** start_grille(struct_grille_cc** grille, param_struct all_param);
void affichage(int n, int m, struct_grille_cc** grille);
void color(int t,int f);
struct_grille_cc random_char();
struct_grille_cc** supp_case(position* all_position, struct_grille_cc** grille, int taille);
score_grille glob_supp_score(struct_grille_cc** grille, int n, int m);
struct_grille_cc** grille_gravite(struct_grille_cc** grille, int n, int m);
struct_grille_cc** remplir_grille(struct_grille_cc** grille, int n, int m);
struct_grille_cc** deplacement_grille(struct_grille_cc** grille,position pos1,position pos2);
score_grille grille_reac_chaine(struct_grille_cc** grille,int n,int m);