#include "ascii.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int detecte_triplet_coul(Liste *liste){
    Tokens *lsttricoul[3] = {NULL, NULL, NULL}, *prem = (*liste);
    int nbrcoul = 0, tst_couleur, i;
    if((*liste) != NULL){
        tst_couleur = ((*liste)->couleur);
        do{
            if((prem->couleur) != tst_couleur){/*la verification du token si il a une couleur differente de la suite actuelle*/
                tst_couleur = prem->couleur;/*si c'est different on reinitialise la suite*/
                lsttricoul[0] = prem;
                nbrcoul = 1;
            }else{
                lsttricoul[nbrcoul] = prem;/*sinon on ajoute le pointeur dans le tableau*/
                nbrcoul++;
            }
            if(nbrcoul == 3){/*ont regarde si la liste de couleur vaut 3*/
                for(i = 0; i<3; i++){
                    liberer_un_Token_mem(liste, lsttricoul[i]);
                }
                return 1;
            }
            prem = prem -> suivant;
        }while(prem != (*liste));
    }
    return 0;
}


int detecte_triplet_form(Liste *liste){
    Tokens *lsttrifrom[3] = {NULL, NULL, NULL}, *prem = (*liste);
    int nbrform = 0, tst_forme, i;
    if((*liste) != NULL){
        tst_forme = ((*liste)->forme);
        do{
            if((prem->forme) != tst_forme){
                tst_forme = prem->forme;
                lsttrifrom[0] = prem;
                nbrform = 1;
            }else{
                lsttrifrom[nbrform] = prem;
                nbrform++;
            }
            if(nbrform == 3){
                for(i = 0; i<3; i++){
                    liberer_un_Token_mem(liste, lsttrifrom[i]);
                }
                nbrform = 0;
                return 1;
            }
            prem = prem -> suivant;
        }while(prem != (*liste));
    }
    return 0;
}


int joue_ascii(Liste *lst){
    int lstcoulatt[4], lstfromatt[4], i, coter;
    srand(time(NULL));
    initialise_to_att(lstcoulatt, lstfromatt, 4, 4);
    i=0;
    while(i < 20){
        printf("====================\n");
        affiche_tok_attend(lstcoulatt, lstfromatt);
        affiche_list((*lst));
        if(demande_cote(&coter) == 0){
            return 1;
        }else{
            i++;
            if(coter == 1){
                if(ajt_elem_en_dernier(lst, lstcoulatt[3], lstfromatt[3]) == 0){
                    return 0;
                }
            }else{
                if(ajt_elem_en_premier(lst, lstcoulatt[3], lstfromatt[3]) == 0){
                    return 0;
                }
            }
        }
        affiche_list((*lst));
        while((detecte_triplet_coul(lst) != 1) && (detecte_triplet_form(lst) == 1)){
            printf("verification...\n");
        }
        ajoute_tk_attente(lstcoulatt, lstfromatt, 4, 4);
    }
    return 1;
}


void initialise_to_att(int lstcoulatt[], int lstfromatt[], int nbrcoul, int nbfrom){
    int couleur_t, forme_t, i;
    for(i = 0; i < 4; i++){
        aleatoire_un_elemt(&couleur_t, &forme_t, nbrcoul, nbfrom);
        lstcoulatt[i] = couleur_t;
        lstfromatt[i] = forme_t;
    }
}


void affiche_tok_attend(int lstcoula[], int lstforma[]){
    int i;
    char listefrom[4] = {'O', 'C', 'T', 'D'}, listecoul[4] = {'r', 'v', 'b', 'j'};
    for(i = 0; i < 4; i++){
        if(i != 3){
            printf(" %c %c ->", listefrom[lstforma[i]], listecoul[lstcoula[i]]);
        }else{
            printf(" %c %c\n", listefrom[lstforma[i]], listecoul[lstcoula[i]]);
        }
    }
}


int demande_cote(int *coter){
    printf("Veuillez choisir  1 pour rajouter le token a droite ou 2 pour la gauche\n");
    scanf("%d", coter);
    if((*coter) == 1 || (*coter) == 2){
        return 1;
    }else{
        return 0;
    }
}


void ajoute_tk_attente(int lstcoula[], int lstforma[], int nombre, int nbform){
    int i, couleurt, formet;
    for(i = 2; i >= 0; i--){
        lstcoula[i+1] = lstcoula[i];
        lstforma[i+1] = lstforma[i];
    }
    aleatoire_un_elemt(&couleurt, &formet, nombre, nbform);
    lstcoula[0] = couleurt;
    lstforma[0] = formet;
}


void aleatoire_un_elemt(int *couleurtok, int *formetok, int nombre, int nbforme){
    (*couleurtok) = rand()%nombre;
    (*formetok) = rand()%nbforme;
}


void transforme_time_char(int  nbr, char nombre[5]){
    int minute = (nbr/60);
    nombre[0] = '0' + minute;
    nombre[1] = ':';
    nombre[2] = '0' + (nbr - (60*minute))/10;
    nombre[3] = '0' + (nbr - (60*minute))%10;
    nombre[4] = '\0';
}


int puissance(int x, int n){
    int i, att = x;
    if(n == 0){
        return 1;
    }
    for(i = 1; i < n; i++){
        x = x * att;
    }
    return x;
}


void transforme_int_char(int  nbr, char nombre[], int taillenbr){
    int i;
    for(i = 0; i <( taillenbr - 1); i++){
        nombre[taillenbr - 2 - i] = '0' + ((nbr/puissance(10 , i))%10);
    }
    nombre[taillenbr - 1] = '\0';
}


void insertabint(int nombre, int tab[], int position, int taille, int taillemax){
    int i;
    if(position == taillemax){
        tab[position - 1] = nombre;
    }else if((position - 1) == taille){
        tab[taille] = nombre;
    }else{
        for(i = (taille - 1); i != (position - 2) ; i--){
            if(i == (position - 1)){
                if(i == (taille - 1) && taille!= taillemax){
                    tab[i + 1] = tab[i];
                }
                tab[i] = nombre;
            }else{
                if(i == (taille - 1) && taille!= taillemax){
                    tab[i + 1] = tab[i];
                }
                tab[i] = tab[i - 1];
            }
        }
    }
}


void ins(char mo[], char remp[]){
    int i = -1;
    do{
        i+=1;
        remp[i] = mo[i];
    }while(mo[i] != '\0');
}


void insertabs(char nom[], char tab[][25], int position, int taille, int taillemax){
    int i;
    if(position == taillemax){
        ins(nom, tab[position - 1]);
    }else if((position - 1) == taille){
        ins(nom, tab[taille]);
    }else{
        for(i = (taille - 1); i != (position - 2) ; i--){
            if(i == (position-1)){
                if(i == (taille - 1) && taille!= taillemax){
                    ins(tab[i], tab[i + 1]);
                }
                ins(nom, tab[i]);
            }else{
                if(i == (taille - 1) && taille!= taillemax){
                    ins(tab[i], tab[i + 1]);
                }
                ins(tab[i - 1], tab[i]);
            }
        }
    }
}
