#include <stdio.h>
#include <stdlib.h>
#include "sauvegarde.h"


/*initialise les fichier*/
void initia(){
    FILE *fichier1 = fopen("score1.txt", "a");
    FILE *fichier2 = fopen("score2.txt", "a");
    FILE *fichier3 = fopen("score3.txt", "a");
    FILE *fichier4 = fopen("score4.txt", "a");
    fclose(fichier1);
    fclose(fichier2);
    fclose(fichier3);
    fclose(fichier4);
}

/*permet de remplir un fichier avec la liste des scores accompagnées des noms*/
void remplie(int score[], char lstj[10][25], int nombre, int niv){
    int i;
    FILE *fichier = NULL;
    switch(niv){
        case 1:
            fichier = fopen("score1.txt", "w");
            break;
        case 2:
            fichier = fopen("score2.txt", "w");
            break;
        case 3:
            fichier = fopen("score3.txt", "w");
            break;
        case 4:
            fichier = fopen("score4.txt", "w");
            break;
    }
    for(i=0; i < nombre; i++){
        fprintf(fichier, "%s#%d\n", lstj[i], score[i]);
    }
    fclose(fichier);
}


/*transforme un char en un int*/
int transforme_char_int(int tail, char chiffre[]){
  int chif = 0, i;
  for(i = 0; i < tail; i++){
    chif += (chiffre[tail - 1 - i] - '0')*puissance(10, i);
  }
  return chif;
}


/*
 *permet de lire un fichier et renvoie en parametre la liste des score et des nom
*/
void lit_sauv(int score[10], char lstj[][25], int *nombre, int niv){
    FILE *fichier = NULL;
    char caracter, sco[10][7], tail[10];
    int choix = 0, place = 0, i;
    (*nombre) = 0;
    switch(niv){
        case 1:
            fichier = fopen("score1.txt", "r");
            break;
        case 2:
            fichier = fopen("score2.txt", "r");
            break;
        case 3:
            fichier = fopen("score3.txt", "r");
            break;
        case 4:
            fichier = fopen("score4.txt", "r");
            break;
    }
    do{
        caracter = fgetc (fichier);
        if(caracter == '#'){
            lstj[(*nombre)][place] = '\0';
            tail[(*nombre)] = 0;
            place = 0;
            choix = 1;
        }else if(caracter == '\n' || caracter == EOF){
            sco[(*nombre)][place] = '\0';
            place = 0;
            choix = 0;
            (*nombre) += 1;
        }else{
            if(choix == 0){
                lstj[(*nombre)][place] = caracter;
                place += 1;
            }else{
                sco[(*nombre)][place] = caracter;
                tail[(*nombre)] += 1;
                place += 1;
            }
        }
    }while(caracter != EOF);
    (*nombre) -= 1;
    for(i=0; i<(*nombre); i++){
        score[i] = transforme_char_int(tail[i], sco[i]);
    }
    fclose(fichier);
}