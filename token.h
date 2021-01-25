typedef struct token{
    int couleur ;
    int forme;
    struct token * suivant ;
    struct token * suivantC ;
    struct token * precedantC ;
    struct token * suivantF ;
    struct token * precedantF ;
}Tokens, *Liste;

/*
 *permet d'ajouter un elem en debut de liste 
 * @param la liste elle meme, la couleur et la forme a rajouter 
 * @return 0 en cas d'erreur, 1 sinon
*/
int ajt_elem_en_premier(Liste *liste, int couleurT, int formeT);


/*
 *permet d'ajouter un elem en fin de liste 
 * @param la liste elle meme, la couleur et la forme a rajouter 
 * @return 0 en cas d'erreur, 1 sinon
*/
int ajt_elem_en_dernier(Liste *liste, int couleurT, int formeT);


/*
 *Permet d'afficher la liste en parametre
 * @param lst la liste a afficher
 * @return rien
*/
void affiche_list(Liste liste);


/*
 *Permet de libere un token passé en param
 * @param le token a supprimer et la liste ou il se trouve 
 * @return 1 si il a été supprimer 0 si il n'existe pas 0 aussi si la liste est vide
*/
int liberer_un_Token_mem(Liste *liste, Tokens *elem);


/*
 *libere toute la liste rentrer par adresse
 * @param lst
 * @return rien
*/
void libere_toute_liste(Liste *liste);


/*
 *donne le nombre de token que contient la liste
 * @param la liste a parcourir 
 * @return un int le nombre de token
*/
int nombre_token(Liste liste);


/*renvoie la forme et la couleur du n eme token de la liste*/
int forme_coul_n_token(Liste liste, int n, int *coul, int *form, Tokens **tst);


/*
fait la rotation circulaire des couleur*/
int rotation_circulaire_couleur(Liste *lst, Tokens *premelme, Tokens *elme, Tokens *elem_prece, Tokens *retour, int compte);


/*
 *Permet de faire les rotations circulaire des formes de maniere recurcive
 * @param une liste de tokens, le premier elem, l'elem, et l'elem prec , et le retour 
 * @return un int soit 1 / 2 
*/
int rotation_circulaire_forme(Liste *lst, Tokens *premelme, Tokens *elem, Tokens *elem_prece, Tokens *retour);


/*
 *reorganise la liste des couleurs pour une liste donnée
 * @param liste et la couleur qu'on va associé a un elem de la liste
 * @return rien
*/
void reorganise_couleur(Liste lst, int nbrclou);

/*
 *reorganise la liste des couleurs pour une liste donnée
 * @param liste et la forme qu'on va  associé a un elem de la liste
 * @return rien
*/
void reorganise_forme(Liste lst, int nbforme);
