typedef struct{
    int longueur;
    int largeur;
    int gravite;

}param_struct;

int menu(param_struct all_param);
param_struct parametres(param_struct all_param);
param_struct changement_taillegrille(param_struct all_param);
param_struct changement_gravite(param_struct all_param);