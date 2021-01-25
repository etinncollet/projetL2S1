#include "ascii.h"
#include <MLV/MLV_all.h>


/* 
 *ouvre une fenetre MLV
*/
void ouvre_fenetre();


/*
 *Affiche le menu avec les deux choix possible(jouer et liste du top 10
*/
void affiche_menu(char titre[13], char prempano[13], char deuxpano[13], int fon);


/*
 *Affiche le monte charge et si monte vaux 1 alors ont anime le monte charge
 * @param l'animation
 * @return si le monte charge vaut 1 alors on le monte avec l'animation
*/
void monte_charge(int anime);


/*
 *affiche le decors du jeu
*/
void affiche_fond_jeux();


/*
 *affiche la fenetre de depart et le titre du jeu(la fennetre prend le plus de place possible
*/
void affiche_fenetre_depart();


/*
 *Affiche un token carre
 * @param x,y coordonnées, taille du token, la couleur
*/
void token_rectangle(int x, int y, int taille, MLV_Color couleur);


/*
 *Affiche un token cercle
 * @param x,y coordonnées, taille du token, la couleur
*/
void token_cercle(int x, int y, int taille, MLV_Color couleur);


/*
 *Affiche un token triangle 
 * @param x,y coordonnées, taille du token, la couleur
*/
void token_triangle(int x, int y, int taille, MLV_Color couleur);


/*
 *Affiche un token diamant
 * @param x,y coordonnées, taille du token, la couleur
*/
void token_diam(int x, int y, int taille, MLV_Color couleur);


/*
 * affichage des tokens suivis du token a choisir 
*/
void affiche_token_attente_graphique(int lstcoula[], int lstforma[]);


/*affiche graphiquement la liste*/
void affiche_liste_graphique(Liste lst, int taille);


/*
 *affiche la baree des infos
 * @param le temps, le score 
*/
void jeu_barre_info(int temps, int score, int plus, int tps);


/*
 *affiche les deux choix autour du token choisie soit par couleur soit par forme
 * @param les coordonnées x,y la couleur du token la forme et la taille
*/
void affiche_choix_sur_token(int x, int y, int couleur, int forme, int taille);


/*
 *permet d'afficher graphiquement la fin de la partie et le score
*/
int affiche_fin_partie(int score, int top[], int nombre);


/*
 *affiche un panneau de niveau au coordonnée indiquer
 * @param coordonnées x y num choix, top
*/
void affiche_niveau(int x, int y, int num, int choix, int top);


/*fait tomber un fond en pierre sur l'ecran*/
void chute_pierre(int fin, int anim);


/*affiche les regles avant de jouer*/
void affiche_avant_jeu();


/*premiere etape du tutoriel*/
void tuto_un();


/*deuxieme etape du tutoriel*/
void tuto_deux();


/*troisieme etape du tutoriel*/
void tuto_trois();


/*quatrieme etape du tutoriel*/
void tuto_quatre();


/*cinquieme etape du tutoriel*/
void tuto_cinq();


/*sixieme etape du tutoriel*/
void tuto_six();


/*derniere etape du tutoriel*/
void tuto_fin();


/*
 *affiche quand il est impossible d'ajouter un token au bout de 32 tokens
*/
void affiche_impossible();