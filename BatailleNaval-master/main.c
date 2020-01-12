#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAILLE 11
#define TAILLE_MAX 1000

void initGrille(char [TAILLE][TAILLE]);
void afficheGrille(char nGrille[TAILLE][TAILLE]);
void menu();
void game();
void RemplirGrille(char [TAILLE][TAILLE],int);
void Attaque(char [TAILLE][TAILLE],char [TAILLE][TAILLE],char [TAILLE][TAILLE],int);
void ConditionVictoire(char nGrille[TAILLE][TAILLE],int nPlayer);
void Color(int couleurDuTexte,int couleurDeFond);// fonction d'affichage de couleurs

int main()
{

    menu();
    game();

    return 0;
}

void menu(){
    int a,Game=0;
    printf("------------------------- La Bataille NAVAL -------------------------\n\n");
    printf("1 : Lancer le jeu\n");
    printf("2 : Charger Fichier\n");
    printf("3 : Quitter\n");
    scanf("%d",&a);fflush(stdin);
    while (Game!=1){
    if(a==1){
        Game=1;
        printf("\nCe jeu se joue avec deux joueurs, l'un contre l'autre sur deux grilles.\n 5 navires mis en place par les joueurs.\n");
        printf("Le but etant de faire couler tous les navires de l'adversaire. C'est a la fois un jeu de reflexion et un jeu de hasard.\n\n");
        printf("Au debut du jeu, chaque joueur place à sa guise tous les bateaux sur sa grille de facon strategique.\n");
        printf("Une fois tous les bateaux en jeu, la partie peut commencer.\n\nUn a un, les joueurs se tire dessus pour detruire les navires ennemis.\n");
        printf("Si un joueur tire sur un navire ennemi:\n - Il ne peut pas jouer deux fois de suite et doit attendre le tour de l'autre joueur.\n");
        printf(" - Si le joueur ne touche pas de navire.\n");
        printf(" - Si le navire est entierement touche, le navire est detruit.\n");
        printf("Une partie de bataille navale se termine lorsque l'un des joueurs n'a plus de navires.\n");
        printf("\nVeuillez appuyer sur ENTER pour commencer la partie.\n");
        getchar();
    }
    if(a==2){
        a=0;
        char chaine[TAILLE_MAX] = "";
        printf("Lecture du fichier\n");
        FILE* F;
        F = fopen("bn.bin","rb");
        fread(&chaine,sizeof(char),5,F);
        printf("Victoire Joueur %s",chaine);
        fclose(F);
    }
    if(a==3)exit(0);}
}

void game(){

    int Win=0;
    char nGrilleA[TAILLE][TAILLE],  nGrilleB[TAILLE][TAILLE],   nGrilleAS[TAILLE][TAILLE],  nGrilleBS[TAILLE][TAILLE];
    initGrille(nGrilleA);           initGrille(nGrilleB);       initGrille(nGrilleAS);      initGrille(nGrilleBS);

    afficheGrille(nGrilleA);RemplirGrille(nGrilleA,1);
    afficheGrille(nGrilleB);RemplirGrille(nGrilleB,2);

    while(Win!=1){
    Attaque(nGrilleA,nGrilleB,nGrilleAS,1);
    Attaque(nGrilleB,nGrilleA,nGrilleBS,2);
    }

}


void initGrille(char nGrille[TAILLE][TAILLE])
{
    int i,j;
    for (i=0; i<TAILLE ; i++)
    {
        for(j=0;j<TAILLE;j++)
            {
            nGrille[i][j]='.'; // Initialiser le tableau
            }
    }
    nGrille[0][0]='/';//Initialisation des bordures
    nGrille[1][0]='1';nGrille[0][1]='A';
    nGrille[2][0]='2';nGrille[0][2]='B';
    nGrille[3][0]='3';nGrille[0][3]='C';
    nGrille[4][0]='4';nGrille[0][4]='D';
    nGrille[5][0]='5';nGrille[0][5]='E';
    nGrille[6][0]='6';nGrille[0][6]='F';
    nGrille[7][0]='7';nGrille[0][7]='G';
    nGrille[8][0]='8';nGrille[0][8]='H';
    nGrille[9][0]='9';nGrille[0][9]='I';
    nGrille[10][0]='0';nGrille[0][10]='J';

}

void afficheGrille(char nGrille[TAILLE][TAILLE])
{
    int i,j;
    for (i=0; i<TAILLE ; i++){
        Color(1,0);
        printf("|");
        for(j=0;j<TAILLE;j++){
            if(nGrille[i][j]=='O') {
                Color(10,0);
                printf("%c",nGrille[i][j]);
                Color(1,0);
                }
            if(nGrille[i][j]=='?') {
                Color(15,0);
                printf("%c",nGrille[i][j]);
                Color(1,0);
                }
            if(nGrille[i][j]=='X') {
                Color(12,0);
                printf("%c",nGrille[i][j]);
                Color(1,0);
                }
            if((nGrille[i][j]!='O')&&(nGrille[i][j]!='?')&&(nGrille[i][j]!='X')){printf("%c",nGrille[i][j]);}
            printf("|");// Afficher la grille
            }
            printf("\n");
            Color(15,0);
        }
}

void RemplirGrille(char nGrille[TAILLE][TAILLE],int nPlayer){

    int i=0,j=0,k=0,nBateauPoser=0;

    char cBateau='O';
    int nBateau[5]={5,4,3,3,2};
    //Bateau=0  porte avion (5 cases)
    //Bateau=1  croiseur (4 cases)
    //Bateau=2  contre torpilleur (3 cases)
    //Bateau=3  sous-marin (3 cases)
    //Bateau=4  torpilleur (2 cases)

    while (nBateauPoser!=5){// Boucle pour poser les 5 bateaux
        system("cls");
        printf("Tour du Joueur :%d\n",nPlayer);
        afficheGrille(nGrille);
        printf("Choisir la position Bateau de %d cases\n",nBateau[nBateauPoser]);
        printf("Bateau %d \n",nBateauPoser);
        printf("Position  ligne entre 1 et 10: ");scanf("%d",&i);fflush(stdin); // Entrer une valeur dans les lignes
        if((i>0&&i<11)){
            printf("Position  colonne entre 1 et 10:  ");scanf("%d",&j);fflush(stdin); // Entrer une valeur dans les colonnes
            if((j>0)&&(j<11)){
                if ((nGrille[i][j]== '.')){ //vérifier  si l'emplacement est déja utilisé
                        printf("Positionnement du bateau 1-Haut 2-Bas 3-Droite 4-Gauche : ");scanf("%d",&k);fflush(stdin);//choisir la position

                        //Haut
                        if((k==1)&&(nGrille[i-(nBateau[nBateauPoser]-1)][j]=='.')&&(nGrille[i-(nBateau[nBateauPoser]-2)][j]!=cBateau)&&(nGrille[i-(nBateau[nBateauPoser]-3)][j]!=cBateau)&&((i-(nBateau[nBateauPoser]-1))>=0)){
                            for(int ni=0;ni<nBateau[nBateauPoser];ni++){
                            nGrille[i-ni][j]= cBateau;}
                            nBateauPoser++;
                        }
                        //Bas
                        if((k==2)&&(nGrille[i+(nBateau[nBateauPoser]-1)][j]=='.')&&(nGrille[i+(nBateau[nBateauPoser]-2)][j]!=cBateau)&&(nGrille[i+(nBateau[nBateauPoser]-3)][j]!=cBateau)&&((i+(nBateau[nBateauPoser]-1))<11)){
                            for(int ni=0;ni<nBateau[nBateauPoser];ni++){
                            nGrille[i+ni][j]= cBateau;}
                            nBateauPoser++;
                        }

                        //Droite
                        if((k==3)&&(nGrille[i][j+(nBateau[nBateauPoser]-1)]=='.')&&(nGrille[i][j+(nBateau[nBateauPoser]-2)]!=cBateau)&&(nGrille[i][j+(nBateau[nBateauPoser]-3)]!=cBateau)&&((j+(nBateau[nBateauPoser]-1))<11)){
                            for(int ni=0;ni<nBateau[nBateauPoser];ni++){
                            nGrille[i][j+ni]= cBateau;}
                            nBateauPoser++;
                        }

                        //Gauche
                        if((k==4)&&(nGrille[i][j-(nBateau[nBateauPoser]-1)]=='.')&&(nGrille[i][j-(nBateau[nBateauPoser]-2)]!=cBateau)&&(nGrille[i][j-(nBateau[nBateauPoser]-3)]!=cBateau)&&((j-(nBateau[nBateauPoser]-1))>=0)){
                           for(int ni=0;ni<nBateau[nBateauPoser];ni++){
                            nGrille[i][j-ni]= cBateau;}
                            nBateauPoser++;
                        }
                    }
                }
            }
        }printf("\nGrille Final.\n");afficheGrille(nGrille);printf("\nVeuillez appuyer sur ENTER pour continuer.\n");getchar();system("cls");
}
//fonction pour la seconde phase du jeu
void Attaque(char nGrille1[TAILLE][TAILLE],char nGrille2[TAILLE][TAILLE],char nGrilleS[TAILLE][TAILLE],int nPlayer){
        int i=0,j=0,nTire=0;
        while (nTire!=1){
            printf("Tour du Joueur %d\n\n",nPlayer);
            printf("Grille de tire\n");
            afficheGrille(nGrilleS);
            //printf("Votre grille\n");
            //afficheGrille(nGrille1);
            printf("Joueur %d doit cibler un emplacement\n",nPlayer);
            printf("Position  ligne entre 1 et 10: ");scanf("%d",&i);fflush(stdin); // Entrer une valeur dans les lignes
            if((i>0&&i<11)){
                printf("Position  colonne entre 1 et 10:");scanf("%d",&j);fflush(stdin); // Entrer une valeur dans les colonnes
                if((j>0)&&(j<11)){
                    //Condition Tire rate
                    if((nGrilleS[i][j]=='.')&&(nGrille2[i][j]=='.')){
                        nGrilleS[i][j]='?';
                        nGrille2[i][j]='?';
                        nTire=1;}
                    //Condition Tire bien
                    if((nGrilleS[i][j]=='.')&&(nGrille2[i][j]=='O')){
                        nGrilleS[i][j]='X';
                        nGrille2[i][j]='X';
                        //vérification de la condition de victoire
                        ConditionVictoire(nGrille2,nPlayer);}
               }

            }
        }
}
//condition de victoire
void ConditionVictoire(char nGrille[TAILLE][TAILLE],int nPlayer){
     int i,j,NombreTire=0;
     for (i=0; i<TAILLE ; i++)
     {
        for(j=0;j<TAILLE;j++)
            {
            if(nGrille[i][j]=='X'){NombreTire++;}
            }
     }
     printf("Tire toucher %d\n",NombreTire);
     if (NombreTire==17){

        //ecriture dans un fichier binaire
        printf("Joueur %d a gagne\n",nPlayer);
        FILE* F;
        printf("Enregistrement du score");
        F = fopen("bn.bin","ab");
        fprintf(F,"%d\n",nPlayer);
        fclose(F);

         exit(0);
     }
}

void Color(int couleurDuTexte,int couleurDeFond){ // fonction d'affichage de couleurs
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}



