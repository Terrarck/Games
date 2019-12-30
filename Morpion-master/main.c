#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Les tableaux 2 dimension , et fonction procédure

#define TAILLE 3
#define TAILLECHOIX 255
#define TAILLEMATRICE 9

//Prototypes
void afficheMatrice(char [][TAILLE]);
void initMatrice(char [][TAILLE],char);
int joueurXetO(char [][TAILLE],int);
int conditionVictoire(char [][TAILLE]);

int main()
{
    char nMatriceEntier[TAILLE][TAILLE];
    int nFinirProg=0;

    initMatrice(nMatriceEntier,'.'); // Initialiser le tableau avec des '.'

    joueurXetO(nMatriceEntier,nFinirProg); // Faire jouer les Joueurs et effectuer les conditions de Victoire

    afficheMatrice(nMatriceEntier); // Afficher la matrice

    return 0;
}

//initialisation

void initMatrice(char nMatriceEntier[TAILLE][TAILLE],char nValInit)
{
    int i,j;

    for (i=0; i<TAILLE ; i++)
    {
        for(j=0;j<TAILLE;j++)
            {
            nMatriceEntier[i][j]=nValInit; // Initialiser le tableau
            }
    }
}
void afficheMatrice(char nMatriceEntier[TAILLE][TAILLE]){

    printf("Affichage\n");
    int i,j;
    for (i=0; i<TAILLE ; i++){
        for(j=0;j<TAILLE;j++){
           printf("%c",nMatriceEntier[i][j]); // Afficher la matrice
        }
        printf("\n");
     }
}

int conditionVictoire(char nMatriceEntier[TAILLE][TAILLE]){
    int i,j,nFinirProg;

    for (j=0;j<3;j++){ // Vérifier les colonnes
        if (((nMatriceEntier[0][j]== 'O')&&(nMatriceEntier[1][j]== 'O')&&(nMatriceEntier[2][j]== 'O'))||((nMatriceEntier[0][0]== 'O')&&(nMatriceEntier[1][1]== 'O')&&(nMatriceEntier[2][2]== 'O'))){
                    printf("Player O win\n");
                    nFinirProg=1;
                    return nFinirProg;} // variable retourner pour forcer un arrêt du programme
        if (((nMatriceEntier[0][j]== 'X')&&(nMatriceEntier[1][j]== 'X')&&(nMatriceEntier[2][j]== 'X'))||((nMatriceEntier[0][0]== 'X')&&(nMatriceEntier[1][1]== 'X')&&(nMatriceEntier[2][2]== 'X'))){
                    printf("Player X win\n");
                    nFinirProg=1;
                    return nFinirProg;} // variable retourner pour forcer un arrêt du programme
    }
    for (i=0;i<3;i++){ //Vérifier les lignes
        if (((nMatriceEntier[i][0]== 'O')&&(nMatriceEntier[i][1]== 'O')&&(nMatriceEntier[i][2]== 'O'))||((nMatriceEntier[0][2]== 'O')&&(nMatriceEntier[1][1]== 'O')&&(nMatriceEntier[2][0]== 'O'))){
                    printf("Player O win\n");
                    nFinirProg=1;
                    return nFinirProg;} // variable retourner pour forcer un arrêt du programme
        if (((nMatriceEntier[i][0]== 'X')&&(nMatriceEntier[i][1]== 'X')&&(nMatriceEntier[i][2]== 'X'))||((nMatriceEntier[0][2]== 'X')&&(nMatriceEntier[1][1]== 'X')&&(nMatriceEntier[2][0]== 'X'))){
                    printf("Player X win\n");
                    nFinirProg=1;
                    return nFinirProg;}// variable retourner pour forcer un arrêt du programme
    }
    return 0;
}

int joueurXetO(char nMatriceEntier[TAILLE][TAILLE],int nFinirProg){

    char cChooseX = 'X';
    char cChooseO = 'O';

    int i=0,j=0,nA=0;

    while (nA!=9){ // Boucle pour remplir les 9 cases du tableau

    afficheMatrice(nMatriceEntier); // afficher la matrice

    if((nA==0)||(nA%2==0)){
        printf("Choisir Joueur O position X et Y:\n");
        printf("Position  ligne entre 1 et 3:");scanf("%d",&i);fflush(stdin); // Entrer une valeur dans les lignes

        if((i==1)||(i==2)||(i==3)){
            i-=1;
            printf("Position  colonne entre 1 et 3:");scanf("%d",&j);fflush(stdin); // Entrer une valeur dans les colonnes

            if((j==1)||(j==2)||(j==3)){
                j-=1;

                if ((nMatriceEntier[i][j]== '.')){ //vérifier  si l'emplacement est déja utilisé
                    nMatriceEntier[i][j]= cChooseO; // écrire un O
                    nA++; // Incrémenter
                    }
                }
            }
            nFinirProg=conditionVictoire(nMatriceEntier); //vérifier les conditions de victoire à chaque tour
            if(nFinirProg==1){return 0;} // Terminer le programme
        }



    else {
        printf("Choisir Joueur X position X et Y:\n");
        printf("Position  ligne entre 1 et 3:");scanf("%d",&i);fflush(stdin); // Entrer une valeur dans les lignes
        if((i==1)||(i==2)||(i==3)){
            i-=1;
            printf("Position  colonne entre 1 et 3:");scanf("%d",&j);fflush(stdin); // Entrer une valeur dans les colonnes

            if((j==1)||(j==2)||(j==3)){
                j-=1;

                if ((nMatriceEntier[i][j]== '.')){ //vérifier  si l'emplacement est déja utilisé
                    nMatriceEntier[i][j]= cChooseX;// écrire un X
                    nA++; // Incrémenter

                    }
                }
            }
            nFinirProg=conditionVictoire(nMatriceEntier);// vérifier à chaque tour les conditions
            if(nFinirProg==1){return 0;} //Terminer le programme
        }

    }
return 0;
}

