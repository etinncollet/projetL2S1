#include "joue_graph.h"
#include <time.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

/*definie le temps de demande d'un clik*/
#define ATTC 1
/*defini le temps de la partie*/
#define PARTIE 120

/*permet prendre en compte les clics sur les boutons du menu et renvoie un entier selon le bouton*/
int click_menu(char titre[13], char prempano[13], char deuxpano[13], int fond){
    int x, y;
    affiche_menu(titre, prempano, deuxpano, fond);
    MLV_update_window();
    do{
        MLV_wait_mouse(&x, &y);
        if ((500 < x) && (x < 800) && (400 < y) && (480 > y)){
            return 1;
        }else if((630 < x) && (x < 830) && (300 < y) && (375 > y)){
            return 0;
        }else if((500 < x) && (x < 800) && (500 < y) && (580 > y)){
            return 2;
        }
    }while(1);
}


/*permet de prendre en compte les clics lors d'une partie renvoie un entier selon le clique*/
int click_jeu(int nombre, int debut, int taille, int rota, int place_rota, int *temps, int score, int *crono, int *plus, int *reste){
    int x, y, i, deb_time, fin_time;
    deb_time = time(NULL);

    MLV_update_window();
    do{
        x = 0;
        y = 0;
        MLV_wait_mouse_or_seconds(&x, &y, ATTC);
        if(x == 0 && y == 0){
            (*crono) -= ATTC;
            jeu_barre_info((*crono), score, *plus, *reste);
            if((*crono) < 1){ return -6;}
            if(*reste > 0){*reste -= 1;}
            continue;
        }
        if ((470 < x) && (x < 520) && (270 < y) && (330 > y)){
            fin_time = time(NULL);
            (*temps) = fin_time - deb_time;
            return -1;
        }else if((790 < x) && (x < 850) && (270 < y) && (330 > y)){
            fin_time = time(NULL);
            (*temps) = fin_time - deb_time;
            return -2;
        }else if((910 < x) && (x < 950) && (5 < y) && (45 > y)){
            fin_time = time(NULL);
            (*temps) = fin_time - deb_time;
            return -3;
        }
        if(rota == 1){
            if((debut + (place_rota*4*(taille+5)) < x) && (x < debut + (place_rota*4*(taille+5))+(4*(taille))) &&
                    (675+(4*(taille))+4 < y) && (675+(4*(taille))+4+(4*(taille)) > y)){
                fin_time = time(NULL);
                (*temps) = fin_time - deb_time;
                return -4;
            }else if((debut + (place_rota*4*(taille+5)) < x) && (x < debut + (place_rota*4*(taille+5))+(4*(taille))) &&
                    (675 > y) && (675-(4*(taille)) < y)){
                fin_time = time(NULL);
                (*temps) = fin_time - deb_time;
                return -5;
            }
        }
        if(nombre != 0){
            for(i = 0; i<nombre; i++){
                if((debut+(i*4*(taille+5)) < x) && (x < debut+((i+1)*4*(taille+5))) && (675 < y) && ((675+(4*taille)) > y)){
                    fin_time = time(NULL);
                    (*temps) = fin_time - deb_time;
                    return i;
                }
            }
        }
    }while(1);
}


/*permet d'afficher la fin de la partie et de la gérée*/
int fin_partie(int score, int niv){
    int top[10], nbr;
    int topten, x = 0, y = 0;
    char *nom_joueur, nom[10][25];
    MLV_Font *font = MLV_load_font("font_titre.ttf", 35), *fontitre = MLV_load_font("font_titre.ttf", 75);
    lit_sauv(top, nom, &nbr, niv);
    topten = affiche_fin_partie(score, top, nbr);
    MLV_wait_mouse_or_seconds(&x, &y, 3);
    if(x == 0 && y == 0){
        MLV_draw_text_with_font(500, 175, "Cliquez pour continuer", font, MLV_COLOR_BLACK);
        MLV_update_window();
    }
    if(topten != -1){
        if(x == 0 && y == 0){
            MLV_wait_mouse(&x, &y);
        }
        chute_pierre(-400, 0);
        MLV_draw_text_with_font(400, 25, "Vous etes dans le TOP 10", fontitre, MLV_COLOR_BLACK);
        MLV_draw_text_with_font(300, 125, "Votre score sera enregistrer dans la liste des dix meilleurs", font, MLV_COLOR_BLACK);
        MLV_draw_text_with_font(400, 200, "Entrez votre pseudo puis appuyer sur entrer", font, MLV_COLOR_BLACK);
        MLV_update_window();
        MLV_wait_input_box_with_font(400, 300, 500, 100, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_COLOR_GREY,
        "   Entrez votre nom : ", &nom_joueur, font);
        chute_pierre(-400, 0);
        insertabint(score, top, topten, nbr, 10);
        insertabs(nom_joueur, nom, topten, nbr, 10);
        if(nbr < 10){nbr += 1;}
        remplie(top, nom, nbr, niv);

        /*enregistrement du score*/
        MLV_draw_text_with_font(300, 25, "Votre score a bien ete enregistrer", fontitre, MLV_COLOR_BLACK);
        MLV_draw_text_with_font(400, 125, "Vous allez etre amené au menu", font, MLV_COLOR_BLACK);
        MLV_update_window();
        MLV_wait_seconds(2);
        free( nom_joueur );
    }else{
        MLV_free_font(font);
        MLV_free_font(fontitre);
        if(x == 0 && y == 0){
            MLV_wait_mouse(&x, &y);
        }
        if(700<x && x<950 && 475<y && y<575){
            return 0;
        }else{
            return 1;
        }
    }
    MLV_free_font(font);
    MLV_free_font(fontitre);
    return 1;
}


/*affiche les quatres niveau */
void lst_niveau(int choix, int x, int y, int top){
    int i;
    for(i=0; i<4; i++){
        if(i + 1 == choix){
            affiche_niveau(x, y + (100 * i), i, 1, top);
        }else{
            affiche_niveau(x, y + (100 * i), i, 0, top);
        }
    }
    MLV_update_window();
}


/*prend en compte les clics de souris pour la partie juste avant le jeu*/
int debut_partie(int *nbr_c){
    int x, y, i;
    affiche_avant_jeu();
    while(1){
        lst_niveau((*nbr_c) - 2, 350, 150, 0);
        MLV_wait_mouse(&x, &y);
        if( 250 < x && x < 500 && 550 < y && y < 650){
            return 1;
        }else if( 550 < x && x < 800 && 550 < y && y < 650){
            return 0;
        }else if( 850 < x && x < 1050 && 550 < y && y < 650){
            return 2;
        }else{
            for(i = 0; i < 4; i++){
                if( 350 < x && x < 850 && 150 + (100 * i) < y && y < 240 + (100 * i)){
                    (*nbr_c) = i + 3;
                    break;
                }
            }
        }
    }
}


/*gere la mise en pause lors d'une partie*/
int pause_jeu(int temps_rest, int *debut){
    int menu, tm;
    menu = click_menu("PAUSE", "RECOMMENCER", "CONTINUER", 0);
    affiche_fond_jeux();
    tm = time(NULL);
    (*debut) = tm - temps_rest;
    return menu;
}


/*fait le fond du tuto*/
void fond_tuto(int lstcoulatt[], int lstfromatt[]){
    affiche_fond_jeux();
    affiche_token_attente_graphique(lstcoulatt, lstfromatt);
    jeu_barre_info(120, 0, 0, 0);
    affiche_liste_graphique(NULL, 8);
}


int tutoriel(int partie){
    int lstcoulatt[4], lstfromatt[4], x, y, i;
    Liste tst;
    tst = NULL;
    srand(partie);
    initialise_to_att(lstcoulatt, lstfromatt, 4, 4);
    fond_tuto(lstcoulatt, lstfromatt);
    MLV_update_window();
    tuto_un();
    MLV_wait_mouse(&x, &y);
    affiche_liste_graphique(tst, 8);
    tuto_deux();
    MLV_wait_mouse(&x, &y);
    fond_tuto(lstcoulatt, lstfromatt);
    tuto_cinq();
    MLV_wait_mouse(&x, &y);
    fond_tuto(lstcoulatt, lstfromatt);
    tuto_quatre();
    MLV_wait_mouse(&x, &y);
    fond_tuto(lstcoulatt, lstfromatt);
    tuto_trois();
    MLV_wait_mouse(&x, &y);
    for(i = 0; i < 6; i++){
        ajt_elem_en_premier( &tst, lstcoulatt[3], lstfromatt[3]);
        ajoute_tk_attente(lstcoulatt, lstfromatt, 4, 4);
        affiche_token_attente_graphique(lstcoulatt, lstfromatt);
    }
    fond_tuto(lstcoulatt, lstfromatt);
    affiche_liste_graphique(tst, 8);
    affiche_choix_sur_token(564, 673, 1, 1, 9);
    tuto_six();
    MLV_wait_mouse(&x, &y);
    tuto_fin();
    while(1){
        MLV_wait_mouse(&x, &y);
        if( 300 < x && x < 550 && 550 < y && y < 650){
            return 1;
        }else if( 700 < x && x < 950 && 550 < y && y < 650){
            return 0;
        }
    }

}


/*permet de jouer au jeu*/
int jeu_graphique(int partie, int recommence, int nbr_coul){
    int couleur_t, forme_t, lstcoulatt[4], lstfromatt[4];
    int coter, debut, taille = 8, nbr, exec, debut_time, fin_time;
    int rotacir = 0, nbr_rota = 0, temps = PARTIE, score = 0, tailmax = 32;
    int detecte, fin, pose, plus = 0, reste = 0, i, nbrf = 4, commence;
    float boost = 1;
    Tokens *att;
    Liste tst;
    tst = NULL;
    srand(partie);
    if(recommence == 0){
        while(1){
            commence = debut_partie(&nbr_coul);
            if(commence == 1){
                if(tutoriel(0)){
                    return 1;
                }
            }else{
                if(commence == 2){
                    return 1;
                }
                break;
            }
        }
    }
    if(nbr_coul == 6){
        nbrf = 5;
    }
    initialise_to_att(lstcoulatt, lstfromatt, nbr_coul, nbrf);
    affiche_fond_jeux();
    affiche_token_attente_graphique(lstcoulatt, lstfromatt);
    affiche_liste_graphique(tst, taille);
    MLV_update_window();
    debut_time = time(NULL);
    while(temps > 0){
        taille = 8;
        nbr = nombre_token(tst);
        for(i = 7; i < nbr; i += 9 ){
            taille -= 1;
        }
        debut = 670-(nbr*2*(taille+5));

        exec = 0;
        boost = 0;
        fin_time = time(NULL);
        temps = PARTIE - (fin_time - debut_time);
        jeu_barre_info(temps, score, plus, reste);
        if(rotacir != 1){
            affiche_liste_graphique(tst, taille);
        }
        coter = click_jeu(nbr, debut, taille, rotacir, nbr_rota, &exec, score, &temps, &plus, &reste);
        if(reste > 0){reste -= 1;}
        jeu_barre_info(temps, score, plus, reste);
        if(coter == -6){
            fin_time = time(NULL);
            temps = PARTIE - (fin_time - debut_time);
            continue;
        }
        fin_time = time(NULL);
        temps = PARTIE - (fin_time - debut_time);
        if(nbr < tailmax){
            if(coter == -1){
                ajt_elem_en_premier( &tst, lstcoulatt[3], lstfromatt[3]);
                ajoute_tk_attente(lstcoulatt, lstfromatt, nbr_coul, nbrf);
                affiche_token_attente_graphique(lstcoulatt, lstfromatt);
            }else if(coter == -2){
                ajt_elem_en_dernier( &tst, lstcoulatt[3], lstfromatt[3]);
                ajoute_tk_attente(lstcoulatt, lstfromatt, nbr_coul, nbrf);
                affiche_token_attente_graphique(lstcoulatt, lstfromatt);
            }
        }else{
            if(coter == -1 || coter == -2){
                affiche_impossible();
                MLV_wait_seconds(1);
            }
        }
        if(coter == -3){
            pose = pause_jeu(PARTIE - temps, &debut_time);
            if(pose == 0){
                libere_toute_liste(&tst);
                return 1;
            }else if(pose == 1){
                libere_toute_liste(&tst);
                return jeu_graphique(partie, 1, nbr_coul);
            }else{
                affiche_token_attente_graphique(lstcoulatt, lstfromatt);
            }
        }else if(coter == -4){
            rotation_circulaire_forme(&tst, att, att, NULL, NULL);
            affiche_liste_graphique(tst, taille);
            MLV_update_window();
            MLV_wait_seconds(1);
            reorganise_couleur(tst, nbr_coul);
        }else if(coter == -5){
            rotation_circulaire_couleur(&tst, att, att, NULL, NULL, 0);
            affiche_liste_graphique(tst, taille);
            MLV_update_window();
            MLV_wait_seconds(1);
            reorganise_forme(tst, nbrf);
        }else if(coter+1 > 0){
            if(forme_coul_n_token(tst, coter, &couleur_t, &forme_t, &att)){
                affiche_liste_graphique(tst, taille);
                affiche_choix_sur_token(debut-2 + (coter*4*(taille+5)), 675-2, couleur_t, forme_t, taille+1);
                rotacir = 1;
                nbr_rota = coter;
            }
            continue;
        }
        rotacir = 0;
        detecte = 1;
        plus = 0;
        while(detecte){
            if(detecte_triplet_coul(&tst) == 1){
                reste = 1;
                if(tst == NULL){
                    boost += 1.5;
                }
                boost += 1;
                score += (100 * boost);
                plus += (100 * boost);
            }else if (detecte_triplet_form(&tst) == 1){
                reste = 1;
                if(tst == NULL){
                    boost += 1.5;
                }
                boost += 1;
                score += (100 * boost);
                plus += (100 * boost);
            }else{
                detecte = 0;
            }
        }
        jeu_barre_info(temps, score, plus, reste);
        affiche_liste_graphique(tst, taille);
        MLV_update_window();
    }
    fin = fin_partie(score, nbr_coul - 2);
    if(fin == 0){
        libere_toute_liste(&tst);
        return 0;
    }
    libere_toute_liste(&tst);
    return 1;
}


/*permet de gerer le clic lors de l'affichage du top 10*/
int top_dix_score(){
    int top[10], nbr, i, x, y, niveau = 2, anim = 1;
    char nom[10][25], num[3] = {'0', '\0'}, preced[6];
    MLV_Font *font = MLV_load_font("font_titre.ttf", 50);
    MLV_Image *planche = MLV_load_image( "plache_v.png" );
    while(1){
        lit_sauv(top, nom, &nbr, niveau);
        chute_pierre(-50, anim);
        anim = 0;
        MLV_resize_image(planche, 500, 75);
        lst_niveau(niveau, 780, 350, 1);
        MLV_update_window();
        for(i = 0; i < nbr; i++){
            MLV_draw_image(planche, 250, 25+(i*72));
            transforme_int_char(top[i], preced, 6);
            if(i < 9){
                num[0] = '0' + i + 1 ;
                num[1] = '\0' ;
            }else{
                num[0] = '1' ;
                num[1] = '0' ;
                num[2] = '\0' ;
            }
            MLV_draw_text_with_font(325, 25+(i*72), num, font, MLV_COLOR_BLACK);
            MLV_draw_text_with_font(350, 25+(i*72), nom[i], font, MLV_COLOR_BLACK);
            MLV_draw_text_with_font(600, 25+(i*72), preced, font, MLV_COLOR_BLACK);
            MLV_update_window();
        }
        MLV_resize_image(planche, 200, 75);
        MLV_draw_image(planche, 850, 25);
        MLV_draw_text_with_font(925, 25, "MENU", font, MLV_COLOR_BLACK);
        MLV_resize_image(planche, 300, 200);
        MLV_draw_image(planche, 780, 115);
        MLV_draw_text_with_font(875, 145, "TOP 10", font, MLV_COLOR_BLACK);
        MLV_draw_text_with_font(805, 200, "Des meilleurs scores", font, MLV_COLOR_BLACK);
        MLV_update_window();

        MLV_wait_mouse(&x, &y);
        if( 850 < x && x < 1050 && 25 < y && y < 100 ){
            MLV_free_font(font);
            MLV_free_image(planche);
            return 1;
        }else{
            for(i = 0; i < 4; i++){
                if( 780 < x && x < 1080 && 350 + (100 * i) < y && y < 440 + (100 * i)){
                    niveau = i + 1;
                    break;
                }
            }
        }
    }
    MLV_free_font(font);
    MLV_free_image(planche);
}