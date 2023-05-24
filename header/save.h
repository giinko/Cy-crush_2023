typedef struct{
    int longueur;
    int largeur;
    int gravite;
    int symbole;
}param_struct;

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
    param_struct all_param;
    struct_grille_cc** grille;
}charge_grille;

void ecrir_parametre(param_struct all_param);
param_struct lire_parametre();
void save_grille(param_struct all_param,struct_grille_cc **grille, int partie,int score);