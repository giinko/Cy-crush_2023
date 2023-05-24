typedef struct{
    int longueur;
    int largeur;
    int gravite;
    int symbole;
}param_struct_game;

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

void ecrir_parametre(param_struct_game all_param);
param_struct_game lire_parametre();