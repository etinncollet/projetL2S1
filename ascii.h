#include "token.h"

/**
 * Permet la detection et la suppression du triplet de couleurs
 * @param la liste des tokens a parcourir
 * @return 1 si ya eu 3 tokens successifs de la meme couleur, 0 sinon
**/
int detecte_triplet_coul(Liste *liste);

/**
 * Permet la detection et la suppression du triplet de formes
 * @param la liste des tokens a parcourir
 * @return 1 si ya eu 3 tokens successifs de la meme formes, 0 sinon
**/
int detecte_triplet_form(Liste *liste);


/**
 * Permet de jouer sur console
 * @param la liste actuelle du jeu
 * @return 0 pour l'ajout d'un token soit a gauche, ou a droite , et 1 si 3 couleur / formes successif identique
**/
int joue_ascii(Liste *lst);


/**
 * Affiche sur la console les tokens qui attendent
 * @param liste couleurs tq rouge = 0, vert = 1, bleu = 2, jaune = 3, liste formes tq cercle = 0, carre = 1, triangle = 2, diamant = 3
 * @return rien 
*/

void affiche_tok_attend(int lstcoula[], int lstforma[]);

/**
 * Permet a l'utilisateur de choisir de quel coté rajouter un token 
 * @param le coté choisis 
 * @return 1 a droite, 2 a gauche ,0 sinon
**/
int demande_cote(int *coter);


/*
 * Ajoute element au debut  
 * @param la liste des couleurs, des formes, nombre entre 0 et 3, forme entre 0 et 3
 * @return rien
*/

void ajoute_tk_attente(int lstcoula[], int lstforma[], int nombre, int nbform);


/* 
 * permet l'affichage aleatoire 
 * @param la couleur du token et la forme du token le max pour le random 
 * @return rien 
*/
void aleatoire_un_elemt(int *couleurtok, int *formetok, int nombre, int nbforme);


/*
 * L'initialisation des 4 premiers tokens a placer 
 * @param 
 * @return rien 
*/
void initialise_to_att(int lstcoulatt[], int lstfromatt[], int nbrcoul, int nbfrom);


/* 
 * Transforme le time en char 
 * @param nbr, et nombre[]
 * @return rien 
*/
void transforme_time_char(int  nbr, char nombre[]);


/*
 *transforme un int en chaine de caractere
*/
void transforme_int_char(int  nbr, char nombre[], int taillenbr);


/*calcule x puissance n*/
int puissance(int x, int n);


/*insert un int dans un tableau a une position donnée*/
void insertabint(int nombre, int tab[], int position, int taille, int taillemax);


/*insert une chaine de caractere dans un tableau de chaine de caractere a une position precise*/
void insertabs(char nom[], char tab[][25], int position, int taille, int taillemax);
