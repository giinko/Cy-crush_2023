typedef struct{
    int longueur;
    int largeur;
    int gravite;
    int symbole;
}param_struct_game;

void ecrir_parametre(param_struct_game all_param);
param_struct_game lire_parametre();