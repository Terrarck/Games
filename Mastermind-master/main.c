////*********************************************************////
///                     Travail entre aide
///     Jérémy FAIVRE   - Neil FEDDA - Nicolas BAUER
///
///*********************************************************////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAILLE 4

void GenererNombreTable(int nTable_aleatoire[TAILLE]);//Générer un nombre aléatoire
void AfficherTable(int nTable[TAILLE]);// Afficher la table aleatoire
void AfficherMatrice(int nMatrice_Joueur[4][12],int nTable_aleatoire[TAILLE],int Tour);// Afficher la matrice
void Joueur(int nMatrice_Joueur[4][12],int j);//Rentrer la valeur du joueur
void Verification(int nTable_aleatoire[TAILLE],int nMatrice_Joueur[4][12],int j);//Vérification
void VerificationReussi(int nTable_aleatoire[TAILLE],int nMatrice_Joueur[4][12],int j);// Condition Victoire
void Color(int couleurDuTexte,int couleurDeFond);// fonction d'affichage de couleurs

int main(){

    int nTable_aleatoire[TAILLE]={0};
    int nMatrice_Joueur[4][12]={0};

    GenererNombreTable(nTable_aleatoire); //On génère le codes secret
    AfficherTable(nTable_aleatoire); // On affiche le résultat

    for (int j=0;j<12;j++){ //Nombre Essai = 12
    Joueur(nMatrice_Joueur,j);//Le joueur rentre ses valeurs
    system("cls");
    AfficherTable(nTable_aleatoire);//Mettre en commentaire pour cacher
    AfficherMatrice(nMatrice_Joueur,nTable_aleatoire,j+1);//afficher la matrice des données du joueur
    }

    printf("\nYou lose");
    AfficherTable(nTable_aleatoire); //Affiche le code secret
    return 0;
}

void GenererNombreTable(int nTable_aleatoire[TAILLE]){ //Générer un nombre aléatoire

        srand(time(NULL));
        int doublon=0; //

        for(int i=0;i<TAILLE;i++){ // On vérifie qu'il n y a pas de doublon
            do{
                nTable_aleatoire[i] = rand()%10; // on génère un nombre aléatoire
                doublon=0;
                printf("Nombre Generer Table: %d\n",nTable_aleatoire[i]);
                for(int j=0;j<i;j++){
                    if (nTable_aleatoire[i]== nTable_aleatoire[j]){ //si  aucun doublon, on sort de la boucle
                        doublon=1;
                        }
                    }
            }while(doublon==1);
        }
}

void AfficherTable(int nTable[TAILLE]){ // Afficher la table aleatoire
    printf("Tableau aleatoire :\n");
    for(int i=0;i<TAILLE;i++){
        printf("%d",nTable[i]);
    }
    printf("\n");
}

void AfficherMatrice(int nMatrice_Joueur[4][12],int nTable_aleatoire[TAILLE],int Tour){// Afficher la matrice

    printf("Tableau Matrice");
    int j=0;
    while (j!=Tour){
        Verification(nTable_aleatoire,nMatrice_Joueur,j); // on lance la vérification pour y implémenter les couleurs et afficher la matrice
        j++;
    }
    printf("\n");
}

void Joueur(int nMatrice_Joueur[4][12],int j){ //Rentrer la valeur du joueur

    int valeur_Joueur=0;

    printf("\nTour Suivant %d\n",j+1);
    printf("Votre choix\n");

    scanf("%d",&valeur_Joueur); // le joueur entre un nombre de 4 chiffres
    printf("\n");

    //Conversion en modulo dans la matrice du joueur
    nMatrice_Joueur[0][j]=valeur_Joueur%10000/1000;
    nMatrice_Joueur[1][j]=valeur_Joueur%1000/100;
    nMatrice_Joueur[2][j]=valeur_Joueur%100/10;
    nMatrice_Joueur[3][j]=valeur_Joueur%10;

}

void Verification(int nTable_aleatoire[TAILLE],int nMatrice_Joueur[4][12],int j){//Vérification

    printf("\n");
    for (int i=0;i<TAILLE;i++){

        if(( nTable_aleatoire[i]== nMatrice_Joueur[0][j] )||( nTable_aleatoire[i]== nMatrice_Joueur[1][j] )
        || ( nTable_aleatoire[i]== nMatrice_Joueur[2][j] )||( nTable_aleatoire[i]== nMatrice_Joueur[3][j])){
        //On est dans un cas où un chiffre du code secret est trouvé égale à un chiffre du joueur

            if( nTable_aleatoire[i]== nMatrice_Joueur[i][j]){
            //On est dans un cas où un chiffre du joueur est bien placé.
            Color(12,0);
            printf("%d",nMatrice_Joueur[i][j]); //affiche en rouge
            Color(15, 0);
            }
            else{
            //On est dans un cas où un chiffre du joueur est mal placé.
            Color(5,0);
            printf("%d",nMatrice_Joueur[i][j]); //affiche en violet
            Color(15, 0);
            }
        }
        else {
        //On est dans un cas où un chiffre du code secret est différent du chiffre du joueur
        Color(15,0);
        printf("%d",nMatrice_Joueur[i][j]); //affiche en gris
        Color(15,0);
        }
    }

    VerificationReussi(nTable_aleatoire,nMatrice_Joueur,j);// on regarde si le joueur a gagné

}

void VerificationReussi(int nTable_aleatoire[TAILLE],int nMatrice_Joueur[4][12],int j){ // Condition Victoire

    if((nMatrice_Joueur[0][j]== nTable_aleatoire[0])&&(nMatrice_Joueur[1][j]== nTable_aleatoire[1])&&(nMatrice_Joueur[2][j]==nTable_aleatoire[2])&&(nMatrice_Joueur[3][j]== nTable_aleatoire[3])){
    //Les valeurs du code secret sont exactement les même que le joueur.

      printf("\nCode secret :");
      for (int i=0;i<TAILLE;i++){
      Color(4,0);
      printf("%d",nMatrice_Joueur[i][j]);
      Color(15,0);
      }

      printf("\nYou win\n");
      exit(0); // on sort du programme
    }
}

void Color(int couleurDuTexte,int couleurDeFond){ // fonction d'affichage de couleurs
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}




