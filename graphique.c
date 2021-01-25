#include "graphique.h"
#include <MLV/MLV_all.h>
/*defini la longueur et la largeur de la fenetre*/
#define LONG 1300
#define LARG 775



void ouvre_fenetre(){
    MLV_create_window("projet final", "projet_final", LONG, LARG);
}


void affiche_menu(char titre[13], char prempano[13], char deuxpano[13], int fon){
    MLV_Font *fontgros = MLV_load_font("font_titre.ttf", 70), *fontpetit = MLV_load_font("font_titre.ttf", 50);
    MLV_Image *image, *planche_top, *rock, *fond ;

    if(fon){
        fond = MLV_load_image( "fond.png" );
        MLV_resize_image( fond, LONG, LARG);
        MLV_draw_image(fond, 0, 0);
        MLV_free_image(fond);
    }else{

    }
    planche_top = MLV_load_image( "plache_v.png" );
    rock = MLV_load_image( "plaque_fond.png" );

    MLV_resize_image( rock, 400, 500);
    MLV_draw_image(rock, 450, 100);

    image = MLV_load_image( "panneau_titre.png" );
    MLV_resize_image(image, 400, 300);
    MLV_draw_image(image, 450, 100);
    MLV_draw_text_with_font(550, 190, titre, fontgros, MLV_COLOR_BLACK);

    MLV_resize_image( planche_top, 200, 75);
    MLV_draw_image(planche_top, 630, 300);

    if(fon){
        MLV_draw_text_with_font(660, 300, "QUITTER", fontpetit, MLV_COLOR_RED);
    }else{
        MLV_draw_text_with_font(660, 300, "MENU", fontpetit, MLV_COLOR_BLACK);
    }


    MLV_resize_image( planche_top, 300, 100);
    MLV_draw_image(planche_top, 500, 390);
    MLV_draw_text_with_font(550, 390, prempano, fontgros, MLV_COLOR_BLACK);

    MLV_resize_image( planche_top, 300, 100);
    MLV_draw_image(planche_top, 500, 490);
    MLV_draw_text_with_font(560, 490, deuxpano, fontgros, MLV_COLOR_BLACK);

    MLV_free_image(image);
    MLV_free_image(planche_top);
    MLV_free_image(rock);
    MLV_free_font(fontpetit);
    MLV_free_font(fontgros);
}


void monte_charge(int anime){
    MLV_Image *monte;
    monte = MLV_load_image( "monte_charge.png" );
    if(anime == 1){
        MLV_resize_image(monte, 200, 550);
        MLV_draw_image(monte, LONG - 350, 0);
    }else{
        MLV_resize_image(monte, 200, 550);
        MLV_draw_image(monte, LONG - 350, 0);
    }
    MLV_free_image(monte);
}


void affiche_fond_jeux(){
    MLV_Image *fond, *mineur;
    MLV_Font* font;
    MLV_Image *place = MLV_load_image( "plaque_fond.png" );

    font = MLV_load_font("font_titre.ttf", 100);
    fond = MLV_load_image( "fond_jeu.png" );
    mineur = MLV_load_image( "mineur_mine.png" );

    MLV_resize_image(fond, LONG, LARG);
    MLV_draw_image(fond, 0, 0 );

    MLV_resize_image( mineur, 250, 400);
    MLV_draw_image(mineur, 550, 190);

    MLV_resize_image( place, 60, 60);
    MLV_draw_image(place, 470, 270);
    MLV_draw_text_with_font(480, 215, "<", font, MLV_COLOR_BLACK);

    MLV_resize_image( place, 60, 60);
    MLV_draw_image(place, 790, 270);
    MLV_draw_text_with_font(810, 215, ">", font, MLV_COLOR_BLACK);

    monte_charge(1);

    MLV_free_image(fond);
    MLV_free_image(mineur);
    MLV_free_image(place);
    MLV_free_font(font);
}


void affiche_fenetre_depart(){
    MLV_Image *image, *place;
    MLV_Font* font;
    image = MLV_load_image( "fond.png" );
    place = MLV_load_image( "plaque_fond.png" );
    font = MLV_load_font("font_titre.ttf", 160);
    MLV_resize_image( image, LONG, LARG);
    MLV_draw_image(image, 0, 0);
    MLV_resize_image( place, 600, 200);
    MLV_draw_image(place, 375, 300);
    MLV_draw_text_with_font(420, 300, "Three to go", font, MLV_COLOR_BLACK);
    MLV_update_window();
    MLV_wait_seconds(1);

    MLV_free_image(image);
    MLV_free_image(place);
    MLV_free_font(font);
}



void token_rectangle(int x, int y, int taille, MLV_Color couleur){
	MLV_draw_filled_rectangle(x , y, 4*taille, 4*taille, couleur);
}


void token_cercle(int x, int y, int taille, MLV_Color couleur){
	MLV_draw_filled_circle(x+((4*taille)/2), y+((4*taille)/2), taille*2, couleur);
}


void token_triangle(int x, int y, int taille, MLV_Color couleur){
	int coordonne_x[3] = {x, x+((4*taille)/2), x+(4*taille)};
	int coordonne_y[3] = {y+(4*taille), y, y+(4*taille)};
	MLV_draw_filled_polygon(coordonne_x, coordonne_y, 3, couleur);
}


void token_diam(int x, int y, int taille, MLV_Color couleur){
	int coordonne_x[4] = {x, x+((4*taille)/2), x+(4*taille), x+((4*taille)/2)};
	int coordonne_y[4] = {y+((4*taille)/2), y, y+((4*taille)/2), y+(4*taille)};
	MLV_draw_filled_polygon(coordonne_x, coordonne_y, 4, couleur);
}


void token_etoile(int x, int y, int taille, MLV_Color couleur, int fond){

    int coordonne_x1[3] = {x, x+(4*taille), x+((4*taille)/2)};
	int coordonne_y1[3] = {y+((4*taille)/4), y+((4*taille)/4), y+(4*taille)};

	int coordonne_x2[3] = {x, x+(4*taille), x+((4*taille)/2)};
	int coordonne_y2[3] = {y+(3*(4*taille)/4), y+(3*(4*taille)/4), y};
    if(fond){
    	MLV_draw_filled_polygon(coordonne_x1, coordonne_y1, 3, couleur);
	    MLV_draw_filled_polygon(coordonne_x2, coordonne_y2, 3, couleur);
    }else{
    	MLV_draw_polygon(coordonne_x1, coordonne_y1, 3, couleur);
	    MLV_draw_polygon(coordonne_x2, coordonne_y2, 3, couleur);
    }
}


void affiche_graf_token(int x, int y, int couleur, int forme, int fond, int taille){
    MLV_Color lstmlvcoul[6] = { MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_PINK, MLV_COLOR_DARKVIOLET};
    if(fond == 1){
        token_rectangle(x, y, taille+1, MLV_COLOR_BLACK);
    }
    switch(forme){
        case 0:
            token_cercle(x, y, taille, lstmlvcoul[couleur]);
            break;
        case 1:
            token_rectangle(x, y, taille, lstmlvcoul[couleur]);
            break;
        case 2:
            token_triangle(x, y, taille, lstmlvcoul[couleur]);
            break;
        case 3:
            token_diam(x, y, taille, lstmlvcoul[couleur]);
            break;
        case 4:
            token_etoile(x, y, taille, lstmlvcoul[couleur], 1);
            break;
        default:
            fprintf(stderr, "erreur affichage token\n");
    }
}


void affiche_token_attente_graphique(int lstcoula[], int lstforma[]){
    int coordo[4][2] = {{104, 58}, {284, 196}, {198, 328}, {423, 405}}, i;
    for(i=0; i<4; i++){
        affiche_graf_token(coordo[i][0], coordo[i][1], lstcoula[i], lstforma[i], 1, 10);
    }
}


void affiche_liste_graphique(Liste lst, int taille){
    Tokens *tok_a_aff = lst;
    MLV_Image *place = MLV_load_image( "plaque_fond.png" );
    int nbr, debut = 670, hauteur = LARG - 100, i;
    nbr = nombre_token(lst);
    MLV_resize_image( place, LONG, 150);
    MLV_draw_image(place, 0, LARG - 150);
    if(nbr != 0){
        debut -= (nbr*2*(taille+5));
        for(i = 0; i<nbr; i++){
            affiche_graf_token(debut, hauteur, tok_a_aff->couleur, tok_a_aff->forme, 0, taille);
            debut +=  (4*(taille+5));
            tok_a_aff = tok_a_aff -> suivant;
        }
    }
    MLV_free_image(place);
}


void bouton_pause(int x, int y){
    MLV_draw_filled_rectangle(x, y, 40, 40, MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(x+7, y+7, 8, 26, MLV_COLOR_GREY);
    MLV_draw_filled_rectangle(x+25, y+7, 8, 26, MLV_COLOR_GREY);
}


void jeu_barre_info(int temps, int score, int plus, int tps){
    int x[4] = {300, 1000, 950, 350};
    int y[4] = {0, 0, 50, 50};
    char chaine_time[5], chaine_score[6], ajout[5];
    if(plus != 1 && tps != 0){
        ajout[0] = '+';ajout[1] = '0' + (plus/100);
        ajout[2] = '0' + ((plus-(100 * (plus/100)))/10);
        ajout[3] = '0';
        ajout[4] = '\0';
    }else{
        ajout[0] = '\0';
    }
    MLV_Font* font = MLV_load_font("font_titre.ttf", 40);
    transforme_time_char(temps, chaine_time);
    transforme_int_char(score, chaine_score, 6);
    MLV_draw_filled_polygon(x, y, 4, MLV_COLOR_GREY);
    bouton_pause(910, 5);
    MLV_draw_text_with_font(375, -5, "time:", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(450, -5, chaine_time, font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(600, -5, "score:", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(675, -5, chaine_score, font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(800, -5, ajout, font, MLV_COLOR_RED);
	MLV_actualise_window();
	MLV_free_font(font);
}


void affiche_choix_sur_token(int x, int y, int couleur, int forme, int taille){
    int coord_x_tri[3] = {x+2, x+((4*taille)/2), x - 2 + (4*taille)};
	int coord_y_tri[3] = {y+(4*(taille - 1))+6+(4*taille - 1), y+(4*(taille-1))+6, y+(4*(taille - 1))+6+(4*taille - 1)};

	int coordonne_x[4] = {x, x+((4*taille)/2), x+(4*taille), x+((4*taille)/2)};
	int coordonne_y[4] = {y+((4*taille)/2)+(4*(taille - 1))+6, y+(4*(taille - 1))+6, y+((4*taille)/2)+(4*(taille - 1))+6, y+(4*taille)+(4*(taille - 1))+6};

    MLV_Color lstmlvcoul[6] = { MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLUE, MLV_COLOR_YELLOW, MLV_COLOR_PINK, MLV_COLOR_DARKVIOLET};
    MLV_draw_rectangle(x, y, 4*taille, 4*taille , MLV_COLOR_WHITE);
    MLV_draw_rectangle(x, y-(4*(taille-1))-4, 4*taille, 4*taille , MLV_COLOR_WHITE);
    MLV_draw_filled_rectangle(x+2, y-(4*(taille-1))-2, 4*(taille-1), 4*(taille-1) , lstmlvcoul[couleur]);
    switch(forme){
        case 0:
            MLV_draw_circle(x+((4*taille)/2), y+((6*taille)), taille*2, MLV_COLOR_WHITE);
            break;
        case 1:
            MLV_draw_rectangle(x+2, y+(4*(taille-1))+6, 4*(taille-1), 4*(taille-1) , MLV_COLOR_WHITE);
            break;
        case 2:
	        MLV_draw_polygon(coord_x_tri, coord_y_tri, 3, MLV_COLOR_WHITE);
            break;
        case 3:
	        MLV_draw_polygon(coordonne_x, coordonne_y, 4, MLV_COLOR_WHITE);
            break;
        case 4:
            token_etoile(x, y+(4*taille), taille, MLV_COLOR_WHITE, 0);
            break;
        default:
            fprintf(stderr, "erreur affichage circulaire\n");
    }
}


void affiche_niveau(int x, int y, int num, int choix, int top){
    char nom[4][15] = {"Debutant", "Normal", "Intermediaire", "Expert"};
    MLV_Image *planche;
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);
    planche = MLV_load_image( "plache_v.png" );


    if(top){
        MLV_resize_image(planche, 300, 90);
        MLV_draw_image(planche, x, y);
        if(choix){
            MLV_draw_text_with_font(x + 10, y - 5, nom[num], font, MLV_COLOR_YELLOW);
        }else{
            MLV_draw_text_with_font(x + 10, y - 5, nom[num], font, MLV_COLOR_BLACK);
        }
    }else{
        MLV_resize_image(planche, 500, 90);
        MLV_draw_image(planche, x, y);
        if(choix){
            MLV_draw_text_with_font(x + 100, y - 5, nom[num], font, MLV_COLOR_YELLOW);
        }else{
            MLV_draw_text_with_font(x + 100, y - 5, nom[num], font, MLV_COLOR_BLACK);
        }
    }


    MLV_free_font(font);
    MLV_free_image(planche);
}


void chute_pierre(int fin, int anim){
    MLV_Image *rock;
    int i;
    rock = MLV_load_image( "plaque_fond.png" );
    MLV_resize_image(rock, 900, 1000);
    if(anim){
        for(i = -800; i < fin; i+= 10){
            MLV_draw_image(rock, 200, i);
            MLV_update_window();
        }
    }else{
        MLV_draw_image(rock, 200, fin);
        MLV_update_window();
    }
    MLV_free_image(rock);
}


void affiche_avant_jeu(){
    chute_pierre(-300, 1);
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);
    MLV_Image *bout = MLV_load_image("plache_v.png");

    MLV_resize_image(bout, 775, 110);
    MLV_draw_image(bout, 250, 10);
    MLV_draw_text_with_font(300, 5, "Veuillez choisir  le niveau de difficulté", font, MLV_COLOR_BLACK);

    MLV_resize_image(bout, 250, 100);
    MLV_draw_image(bout, 270, 550);
    MLV_draw_image(bout, 550, 550);

    MLV_resize_image(bout, 200, 100);
    MLV_draw_image(bout, 850, 550);
    MLV_draw_text_with_font(900, 550, "MENU", font, MLV_COLOR_BLACK);

    MLV_draw_text_with_font(600, 550, "JOUER", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(300, 550, "TUTORIEL", font, MLV_COLOR_BLACK);

    MLV_free_font(font);
    MLV_update_window();
    MLV_free_image(bout);
}


int affiche_fin_partie(int score, int top[], int nombre){
    char preced[6], sco[6], suiv[6];
    char numav[3] = {'0'+nombre, '\0'}, numsc[3] = {'0'+nombre+1, '\0'}, numap[3] = {'0', '\0'};
    int i;
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);
    MLV_Image *planche;
    planche = MLV_load_image( "plache_v.png" );
    chute_pierre(-400, 1);

    MLV_resize_image(planche, 600, 150);
    MLV_draw_image(planche, 350, 25);
    MLV_draw_text_with_font(420, 50, "FIN DE LA PARTIE", font, MLV_COLOR_BLACK);
    MLV_update_window();
    MLV_wait_seconds(1);
    MLV_draw_text_with_font(300, 225, "SCORE :", font, MLV_COLOR_BLACK);
    transforme_int_char(score, sco, 5);
    MLV_draw_text_with_font(475, 225, sco, font, MLV_COLOR_BLACK);
    if(score > top[nombre - 1] || nombre == 0){
        if(score > top[0] || nombre == 0){
            if(nombre != 0){
                transforme_int_char(top[0], suiv, 5);
                numap[0] = '2';
                MLV_draw_text_with_font(700, 300, numap, font, MLV_COLOR_BLACK);
                MLV_draw_text_with_font(875, 300, suiv, font, MLV_COLOR_BLACK);
            }
            numsc[0] = '1';
            MLV_draw_text_with_font(700, 225, numsc, font, MLV_COLOR_YELLOW);
            MLV_draw_text_with_font(875, 225, sco, font, MLV_COLOR_YELLOW);
            MLV_draw_text_with_font(275, 475, "Vous etes le nouveau meilleur score", font, MLV_COLOR_BLACK);
            MLV_update_window();
            MLV_free_font(font);
            MLV_free_image(planche);
            return 1;
        }else{
            for(i = 1; i <= nombre; i++){
                if(top[i - 1] < score){
                    transforme_int_char(top[ i - 1 ], preced, 5);
                    transforme_int_char(top[ i - 2 ], suiv, 5);
                    numav[0] = '0' + i - 1;
                    numsc[0] = '0' + i ;
                    numap[0] = '0' + i + 1;
                    MLV_draw_text_with_font(700, 375, numap, font, MLV_COLOR_BLACK);
                    MLV_draw_text_with_font(875, 375, preced, font, MLV_COLOR_BLACK);

                    MLV_draw_text_with_font(700, 300, numsc, font, MLV_COLOR_YELLOW);
                    MLV_draw_text_with_font(875, 300, sco, font, MLV_COLOR_YELLOW);

                    MLV_draw_text_with_font(700, 225, numav, font, MLV_COLOR_BLACK);
                    MLV_draw_text_with_font(875, 225, suiv, font, MLV_COLOR_BLACK);
                    MLV_draw_text_with_font(275, 475, "Vous etes dans le top 10", font, MLV_COLOR_BLACK);
                    MLV_update_window();
                    MLV_free_font(font);
                    MLV_free_image(planche);
                    return i;
                }
            }
        }
    }else{
        transforme_int_char(top[nombre - 1], preced, 5);

        MLV_draw_text_with_font(875, 375, sco, font, MLV_COLOR_YELLOW);
        MLV_draw_text_with_font(875, 300, preced, font, MLV_COLOR_BLACK);
        MLV_update_window();
        if(nombre < 10){
            MLV_draw_text_with_font(700, 300, numav, font, MLV_COLOR_BLACK);
            MLV_draw_text_with_font(700, 375, numsc, font, MLV_COLOR_YELLOW);
            MLV_draw_text_with_font(275, 475, "Vous etes dans le top 10", font, MLV_COLOR_BLACK);
            MLV_update_window();
            MLV_free_font(font);
            MLV_free_image(planche);
            return nombre+1;
        }
        MLV_draw_text_with_font(700, 300, "10", font, MLV_COLOR_BLACK);
        MLV_resize_image(planche, 250, 100);
        MLV_draw_image(planche, 350, 475);
        MLV_draw_text_with_font(415, 475, "Menu", font, MLV_COLOR_BLACK);

        MLV_resize_image(planche, 250, 100);
        MLV_draw_image(planche, 700, 475);
        MLV_draw_text_with_font(740, 475, "QUITTER", font, MLV_COLOR_RED);
        MLV_update_window();
    }
    MLV_free_font(font);
    MLV_free_image(planche);
    return -1;
}


void tuto_un(){
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);
    MLV_draw_text_with_font(400, 615, "Voici le décors de la partie", font, MLV_COLOR_BLACK);
    MLV_free_font(font);
    font = MLV_load_font("font_titre.ttf", 35);
    MLV_draw_text_with_font(550, 700, "cliquer pour continuer", font, MLV_COLOR_BLACK);
    MLV_update_window();
    MLV_free_font(font);
}


void tuto_deux(){
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);

    MLV_draw_text_with_font(90, 615, "ici l'affichage du temps restant et votre score", font, MLV_COLOR_BLACK);
    MLV_free_font(font);
    font = MLV_load_font("font_titre.ttf", 35);
    MLV_draw_text_with_font(550, 700, "Cliquer pour continuer", font, MLV_COLOR_BLACK);

    MLV_draw_ellipse(430, 20, 100, 40, MLV_COLOR_RED);
    MLV_draw_ellipse(430, 20, 99, 39, MLV_COLOR_RED);
    MLV_draw_ellipse(430, 20, 98, 38, MLV_COLOR_RED);

    MLV_draw_ellipse(680, 20, 100, 40, MLV_COLOR_RED);
    MLV_draw_ellipse(680, 20, 99, 39, MLV_COLOR_RED);
    MLV_draw_ellipse(680, 20, 98, 38, MLV_COLOR_RED);

    MLV_update_window();
    MLV_free_font(font);
}


void tuto_trois(){
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);

    MLV_draw_text_with_font(200, 615, "veuillez choisir un coté pour ", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(100, 680, "mettre les tokens soit au debut ou a la fin ", font, MLV_COLOR_BLACK);

    MLV_draw_ellipse(500, 300, 35, 35, MLV_COLOR_RED);
    MLV_draw_ellipse(500, 300, 34, 34, MLV_COLOR_RED);
    MLV_draw_ellipse(500, 300, 33, 33, MLV_COLOR_RED);

    MLV_draw_ellipse(819, 300, 35, 35, MLV_COLOR_RED);
    MLV_draw_ellipse(819, 300, 34, 34, MLV_COLOR_RED);
    MLV_draw_ellipse(819, 300, 33, 33, MLV_COLOR_RED);

    MLV_update_window();
    MLV_free_font(font);
}


void tuto_quatre(){
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);

    MLV_draw_text_with_font(200, 615, "voici l'ordre des tokens a placer dans la liste", font, MLV_COLOR_BLACK);

    MLV_draw_text_with_font(400, 315, "1", font, MLV_COLOR_RED);
    MLV_draw_text_with_font(200, 380, "2", font, MLV_COLOR_RED);
    MLV_draw_text_with_font(300, 110, "3", font, MLV_COLOR_RED);
    MLV_draw_text_with_font(70, 15, "4", font, MLV_COLOR_RED);

    MLV_update_window();
    MLV_free_font(font);
}


void tuto_cinq(){
    MLV_Font* font = MLV_load_font("font_titre.ttf", 75);

    MLV_draw_text_with_font(200, 625, "voici le bouton pour mettre en pause le jeu", font, MLV_COLOR_BLACK);

    MLV_draw_ellipse(930, 25, 35, 35, MLV_COLOR_RED);
    MLV_draw_ellipse(930, 25, 34, 34, MLV_COLOR_RED);
    MLV_draw_ellipse(930, 25, 33, 33, MLV_COLOR_RED);
    affiche_menu("Pause", "Recommencer", "Continuer", 0);
    MLV_update_window();
    MLV_free_font(font);
}


/*sixieme etape du tutoriel*/
void tuto_six(){
    MLV_Font *font = MLV_load_font("font_titre.ttf", 40);
    MLV_Image *bout = MLV_load_image("plaque_fond.png");

    MLV_resize_image(bout, 800, 110);
    MLV_draw_image(bout, 250, 150);

    MLV_draw_text_with_font(290, 150, "Lorsque vous cliquer sur un token vous pouvez faire un decalage", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(320, 200, "soit selon la forme du token soit selon sa couleur", font, MLV_COLOR_BLACK);

    MLV_update_window();
    MLV_free_image(bout);
    MLV_free_font(font);
}


/*etape final permet d'afficher le choix*/
void tuto_fin(){
    MLV_Font *font = MLV_load_font("font_titre.ttf", 75);
    MLV_Image *bout = MLV_load_image("plache_v.png");
    chute_pierre(-300, 1);

    MLV_resize_image(bout, 775, 110);
    MLV_draw_image(bout, 250, 10);
    MLV_draw_text_with_font(500, 5, "Fin du tutoriel", font, MLV_COLOR_BLACK);

    MLV_resize_image(bout, 250, 100);
    MLV_draw_image(bout, 300, 550);
    MLV_draw_image(bout, 700, 550);
    MLV_draw_text_with_font(750, 550, "JOUER", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(330, 550, "MENU", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(500, 350, "BONNE CHANCE", font, MLV_COLOR_YELLOW);

    MLV_free_font(font);
    font = MLV_load_font("font_titre.ttf", 35);
    MLV_draw_text_with_font(320, 150, "Le but de ce jeu est de faire le score le plus grand.", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(320, 200, "Pour cela vous devez reunir trois pierre de meme couleur ou de meme forme.", font, MLV_COLOR_BLACK);
    MLV_draw_text_with_font(320, 250, "Au bout de 2 minutes la partie s'arrete et le score s'affiche", font, MLV_COLOR_BLACK);

    MLV_update_window();
    MLV_free_font(font);
    MLV_free_image(bout);
}


/*affiche quand il est impossible d'ajouter un token*/
void affiche_impossible(){
    MLV_Font* font = MLV_load_font("font_titre.ttf", 25);
    MLV_draw_filled_rectangle(100, 730, LONG - 200, 40, MLV_COLOR_RED);
    MLV_draw_text_with_font(200, 735, "Impossible il y a trop de tokens faite des rotaion pour en enlever", font, MLV_COLOR_BLACK);
    MLV_update_window();
    MLV_free_font(font);
}