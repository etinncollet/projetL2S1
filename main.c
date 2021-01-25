#include "main.h"
#include <time.h>


/*permet de faire ce que l'ont veut dans l'interface*/
int main(void){
    int menu, jeu;
    initia();
    ouvre_fenetre();
    affiche_fenetre_depart();
    while(1){
        menu = click_menu("Three to go", "Jouer", "TOP 10", 1);
        if(menu == 0){
            return 0;
        }else if(menu == 1){
            jeu = jeu_graphique(time(NULL), 0, 4);
            if(jeu == 1){
                continue;
            }else{
                return 0;
            }
        }else if(menu == 2){
            top_dix_score();
        }
    }
    MLV_free_window();
    return 0;
}