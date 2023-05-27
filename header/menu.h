#include "game.h"

int meme_total(struc_charge_grille total1, struc_charge_grille total2);
int meme_param(param_struct all_param1, param_struct all_param2);
int verifier_fichier_vide(const char *nom_fichier);
void vider_partie();
struc_charge_grille sauvegarder(struc_charge_grille partie);
struc_charge_grille fin_de_partie(struc_charge_grille partie);
param_struct changement_taillegrille(param_struct all_param11) ;
param_struct changement_gravite(param_struct all_param12);
param_struct changement_caractere(param_struct all_param13);
param_struct parametres(param_struct all_param1);
struc_charge_grille chargement_partie1(struc_charge_grille total01);
struc_charge_grille chargement_partie2(struc_charge_grille total02);
struc_charge_grille chargement_partie3(struc_charge_grille total03);
struc_charge_grille charger_grille(struc_charge_grille total0);
int menu(struc_charge_grille total);