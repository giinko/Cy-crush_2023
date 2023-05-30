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
    int score ;
    int content ;
}struc_charge_grille;

void ecrir_parametre(param_struct all_param);
struc_charge_grille lire_parametre();
void save_grille(struc_charge_grille grille, int partie,int score);
struc_charge_grille charge_grille(int partie,struc_charge_grille total);
void supp_save(int partie);