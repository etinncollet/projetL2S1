#include "graphique.h"


void initia();

/*
 *permet de remplir un fichier avec la liste des score et des nom
*/
void remplie(int score[], char lstj[10][25], int nombre, int niv);


/*
 *transforme un char et un int
*/
int transforme_char_int(int tail, char chiffre[]);


/*
 *permet de lire un fichier et renvoie en parametre la liste des scores et des noms
*/
void lit_sauv(int score[10], char lstj[][25], int *nombre, int niv);