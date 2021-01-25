#include "token.h"
#include <stdio.h>
#include <stdlib.h>



void reorganise_couleur(Liste lst, int nbrclou){
    Tokens *premcoul = lst, *suivcoul, *reticoul;
    int i;
    for(i = 0; i<nbrclou; i++){
        /*recherche du premier de la couleur*/
        do{
            if(premcoul->couleur == i){
                break;
            }
            premcoul = premcoul->suivant;
        }while(premcoul != lst);
        /*mets corectement le chainage double en partant de du premier trouver*/
        reticoul = premcoul;
        suivcoul = premcoul;
        do{
            suivcoul = suivcoul->suivant;
            if(suivcoul->couleur == i){
                reticoul->suivantC = suivcoul;
                suivcoul->precedantC = reticoul;
                reticoul = suivcoul;
            }
        }while(premcoul->suivant != suivcoul);
    }
}



void reorganise_forme(Liste lst, int nbforme){
    Tokens *premcoul = lst, *suivcoul, *reticoul;
    int i;
    for(i = 0; i<nbforme; i++){
        do{
            if(premcoul->forme == i){
                break;
            }
            premcoul = premcoul->suivant;
        }while(premcoul != lst);
        reticoul = premcoul;
        suivcoul = premcoul;
        do{
            suivcoul = suivcoul->suivant;
            if(suivcoul->forme == i){
                reticoul->suivantF = suivcoul;
                suivcoul->precedantF = reticoul;
                reticoul = suivcoul;
            }
        }while(premcoul != suivcoul);
    }
}



void deux_rota_f(Liste *lst, Tokens *elem, Tokens *suiv){
    /*echange deux token*/
    Tokens *prececoul = elem->suivantF;
    do{
        prececoul = prececoul->suivant;
    }while(prececoul->suivant != elem->suivantF);
    elem->suivantF->suivant = suiv;
    elem->suivant = elem->suivantF;
    prececoul->suivant = elem;
    if(elem == (*lst)){
        (*lst) = elem->suivantF;
    }else if(elem->suivantF == (*lst)){
        (*lst) = elem;
    }
}



int rotation_circulaire_forme(Liste *lst, Tokens *premelme, Tokens *elem, Tokens *elem_prece, Tokens *retour){
    Tokens *preced, *suiv;
    int rot;
    /*si il n'y as qu'un element*/
    if(premelme->suivantF == premelme){
        return 1;
    }

    preced = elem;

    /*recherche elemnt avant elem*/
    do{
        preced = preced->suivant;
    }while(preced->suivant != elem);

    suiv = elem->suivant;

    if(suiv == preced){
        (*lst) = suiv;
        return 1;
    }

    /*si il n'y a que 2 element a echanger*/
    if(preced == elem->suivantF){
        deux_rota_f(lst, elem, suiv);
        return 1;
    }
    /*fait l'appel recursif*/
    if(retour != premelme){
        rot = rotation_circulaire_forme(lst, premelme, elem->precedantF, elem, elem->precedantF);
    }else{
        rot = 1;
    }

    /*si nous ne somme pas dans le premier appel*/
    if(retour != NULL){
        /*si les token sont cote a cote*/
        if(suiv == elem_prece){
            /*element qui preced n'est pas coller au token*/
            if(elem->precedantF != preced){
                elem_prece->suivant = elem_prece->suivantF;
                preced->suivant = elem_prece;
            }
        }else{
            if((*lst) == elem && rot != 2){
                /*element qui preced est coller au token*/
                if(elem->precedantF == preced){
                    elem_prece->suivant = suiv;
                    elem->suivant = elem_prece;
                }else{
                    preced->suivant = elem_prece;
                    elem_prece->suivant = suiv;
                }
            }else{
                /*element qui preced n'est pas coller au token*/
                if(elem->precedantF != preced){
                    elem_prece->suivant = suiv;
                    preced->suivant = elem_prece;
                }else{
                    if(elem_prece->suivant == (*lst)){
                        elem->suivant = elem_prece;
                        elem_prece->suivant = suiv;
                    }else{
                        elem -> suivant = elem_prece;
                        elem_prece->suivant = suiv;
                    }
                }
            }
        }
        if(elem == (*lst) && rot != 2){
            (*lst) = elem_prece;
            return 2;
        }
    }
    return 1;
}



void deux_rota_c(Liste *lst, Tokens *elem, Tokens *suiv){
    Tokens *prececoul = elem->suivantC;
    do{
        prececoul = prececoul->suivant;
    }while(prececoul->suivant != elem->suivantC);
    elem->suivantC->suivant = suiv;
    elem->suivant = elem->suivantC;
    prececoul->suivant = elem;
    if(elem == (*lst)){
        (*lst) = elem->suivantC;
    }else if(elem->suivantC == (*lst)){
        (*lst) = elem;
    }
}



int rotation_circulaire_couleur(Liste *lst, Tokens *premelme, Tokens *elem, Tokens *elem_prece, Tokens *retour, int compte){
    Tokens *preced, *suiv;
    int rot;

    if(premelme->suivantC == premelme){
        return 1;
    }

    preced = elem;

    do{
        preced = preced->suivant;
    }while(preced->suivant != elem);

    suiv = elem->suivant;

    if(suiv == preced){
        (*lst) = suiv;
        return 1;
    }

    if(preced == elem->suivantC){
        deux_rota_c(lst, elem, suiv);
        return 1;
    }
    if(retour != premelme ){
        rot = rotation_circulaire_couleur(lst, premelme, elem->precedantC, elem, elem->precedantC, compte + 1);
    }else{
        rot = 1;
    }
    if(retour != NULL){
        if(suiv == elem_prece){
            if(elem->precedantC != preced){
                fprintf(stderr, "-ok0");
                elem_prece->suivant = elem_prece->suivantC;
                preced->suivant = elem_prece;
            }else{
                fprintf(stderr, "-ok1");
                
            }
        }else{
            if((*lst) == elem && rot != 2){
        
                if(elem->precedantC == preced){
                    fprintf(stderr, "-ok2.1");
                    elem_prece->suivant = suiv;
                    elem->suivant = elem_prece;
                }else{
                    fprintf(stderr, "-ok2.2");
                    preced->suivant = elem_prece;
                    elem_prece->suivant = suiv;
                }
            }else{
                if(elem->precedantC != preced){
                    fprintf(stderr, "-ok3");
                    elem_prece->suivant = suiv;
                    preced->suivant = elem_prece;
                }else{
                    if(elem_prece->suivant == (*lst)){
                        fprintf(stderr, "-ok4");
                        elem->suivant = elem_prece;
                        elem_prece->suivant = suiv;
                    }else{
                        fprintf(stderr, "-ok5");
                        elem -> suivant = elem_prece;
                        elem_prece->suivant = suiv;
                    }
                }
            }
        }
        if(elem == (*lst) && rot != 2){
            fprintf(stderr, "/ok4");
            (*lst) = elem_prece;
            return 2;
        }
    }
    return 1;
}



Liste premier_choix(Liste lst, int coul_form, int choix){
    Tokens *parcour;
    if(lst != NULL){
        parcour = lst;
        do{
            if(parcour == parcour->suivant){
                return parcour;
            }
            parcour = parcour->suivant;
            if(choix == 1){
                if(parcour->couleur == coul_form){
                    return parcour;
                }
            }else if(choix == 0){
                if(parcour->forme == coul_form){
                    return parcour;
                }
            }
        }while(parcour->suivant != lst);
        return (parcour->suivant);
    }
    return NULL;
}



Liste dernier_choix(Liste lst, int coul_form, int choix){
    Tokens *parcour, *dernier = NULL;
    if(lst != NULL){
        parcour = lst;
        do{
            parcour = parcour->suivant;
            if(choix == 1){
                if(parcour->couleur == coul_form){
                    dernier = parcour;
                }
            }else if(choix == 0){
                if(parcour->forme == coul_form){
                    dernier = parcour;
                }
            }
        }while(parcour->suivant != lst);
        if(dernier == NULL){
            return lst;
        }else{
            return dernier;
        }
    }
    return NULL;
}



int ajt_elem_en_premier(Liste *liste, int couleurT, int formeT){
	Tokens *element, *tmp = (*liste), *premier = (*liste);/*initialise les variable necessaire*/
	element = (Tokens*)malloc(sizeof(Tokens));/*alou la place pour un Token*/

	if(element != NULL){
        element->couleur = couleurT;/*donne a la structure les valeur entrées*/
        element->forme = formeT;

        if (tmp == NULL){ /*si la liste est vide ont vient boucler le premier element avec lui meme*/
            element->suivant = element;
            (*liste) = element;
            element->suivantC = element;
            element->suivantF = element;
            element->precedantC = element;
            element->precedantF = element;
            return 1;
        }
        /*sinon ont vas a la fin de la liste et ont l'insert en bouclant avec le premier element*/
        do{
            tmp = tmp->suivant;
        }while(tmp->suivant != premier);

        element->suivant = premier;
        tmp->suivant = element ;
        (*liste) = element;

        element->suivantC = premier_choix((*liste), couleurT, 1);
        element->suivantC->precedantC = element;

        element->suivantF = premier_choix((*liste), formeT, 0);
        element->suivantF->precedantF = element;

        element->precedantC = dernier_choix((*liste), couleurT, 1);
        element->precedantC->suivantC = element;

        element->precedantF = dernier_choix((*liste), formeT, 0);
        element->precedantF->suivantF = element;
        return 1;
	}else{
		fprintf(stderr, "erreur ajout en dernier");
		return 0;
	}
}


int ajt_elem_en_dernier(Liste *liste, int couleurT, int formeT){
    if(ajt_elem_en_premier(liste, couleurT, formeT) == 0){
        fprintf(stderr, "erreur ajout en premier");
        return 0;
    }
    (*liste) = (*liste)->suivant;/*comme la liste est circulaire je fait passer l'element ajouter a la fin en changeant le debut de la liste*/
    return 1;
}



void affiche_list(Liste liste){
    Tokens *premier = liste, *parcour = liste;
    int i=0;
    char listefrom[4] = {'O', 'C', 'T', 'D'}, listecoul[4] = {'r', 'v', 'b', 'j'};
	if(liste == NULL){
		printf("la liste est vide\n");
		return;
	}
	do{
	    i++;
		fprintf(stderr, " %c %c -->", listefrom[parcour->forme], listecoul[parcour->couleur]);
	 	parcour = parcour->suivant;
	}while(premier != parcour && i<18);
	printf(">\n");
}


int liberer_un_Token_mem(Liste *liste, Tokens *elem){
    Tokens *temp = ((*liste)->suivant), *before, *premier = (*liste);
    /*ont commence par le deuxieme element et ont fini par le premier pour simplifier*/
	if((*liste) != NULL){
	    if((*liste) == temp){
	        free(elem);
	        (*liste) = NULL;
	        return 1;
	    }
	    do{
	        before = temp;
	        temp = temp->suivant;
	        if(temp == elem){
	            if(temp == premier){/*si l'ont doit supprimer la premiere valeur ont decale la liste a la deuxieme valeur*/
	                (*liste) = temp->suivant;
	            }
	            before->suivant = temp->suivant;/*ont relie la valeur precedente et la suivante*/
	            /*ont relie les double bloucle circulaire des couleur et des forme*/
	            if(temp != temp->suivantC){
	                temp->precedantC->suivantC = temp->suivantC;
	                temp->suivantC->precedantC = temp->precedantC;
	            }
	            if(temp != temp->suivantF){
	                temp->precedantF->suivantF = temp->suivantF;
	                temp->suivantF->precedantF = temp->precedantF;
	            }
	            free(elem);
	            return 1;
	        }
	    }while((premier->suivant) != temp);
	}
	return 0;
}



void libere_toute_liste(Liste *liste){
    Tokens *temp, *supre;
    if((*liste) != NULL){
        printf("ok");
        temp = (*liste);
        do{
            supre = temp;
            temp = temp->suivant;
            free(supre);
        }while(temp != (*liste));

        (*liste) = NULL;
    }


}



int nombre_token(Liste liste){
    Tokens *parcour = liste;
    int comte = 0;
    if(liste == NULL){
        return 0;
    }
	do{
		comte += 1;
	 	parcour = parcour->suivant;
	}while(liste != parcour);
    return comte;
}


/*renvoie la forme et la couleur du n eme token de la liste*/
int forme_coul_n_token(Liste liste, int n, int *coul, int *form, Tokens **tst){
    Tokens *parcour = liste;
    int comte = 0;
    if(liste != NULL){
        do{
            if(comte == n){
                (*coul) = parcour->couleur;
                (*form) = parcour->forme;
                (*tst) = parcour;
                return 1;
            }
            parcour = parcour->suivant;
		    comte += 1;
	    }while(liste != parcour);
    }
    return 0;
}
