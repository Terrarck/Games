#include <winsock2.h>
typedef int socklen_t;

#include <stdio.h>
#include <stdlib.h>
#define PORT 23

#include <pthread.h>
#include <time.h>
#include <windows.h>
#define TAILLE 4

void* Reception(void* data);
void my_delay(int i);


void intro();
void enigme1();
void enigme2();
int enigme3();
int enigme4();
void fin();
int Jouer(char nTable_aleatoire[TAILLE],char nMatrice_Joueur[4][12]);
void GenererNombreTable(char nTable_aleatoire[TAILLE]);//Générer un nombre aléatoire
void AfficherTable(char nTable[TAILLE]);// Afficher la table aleatoire
void CalculMatrice(char nMatrice_Joueur[4][12],char nMatriceCode[TAILLE],int j);
void AfficherMatrice(char nMatrice_Joueur[4][12],char nTable_aleatoire[TAILLE],int Tour);// Afficher la matrice
void Joueur(char nMatrice_Joueur[4][12],int j);//Rentrer la valeur du joueur
int VerificationReussi(char nTable_aleatoire[TAILLE],char nMatrice_Joueur[4][12],int j);// Condition Victoire
void Color(int couleurDuTexte,int couleurDeFond);// fonction d'affichage de couleurs



SOCKET sock;

int main(void)
{
#if defined (WIN32)
    WSADATA WSAData;
    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
    int erreur = 0;
#endif
    /**-------pthread-----**/
    pthread_t thread_Reception;
    int END = 0;
    /**-------------------**/

    SOCKADDR_IN sin;
    char address[32];

    printf("Saisir l'adresse : ");
    scanf("%s",address);


    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);

        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr(address);
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);

        /* Si l'on a réussi à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            printf("Connection %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

            /* Si l'on reçoit des informations : on les affiche à l'écran */

            /**--Création thread--**/
            pthread_create(&thread_Reception, NULL, Reception, NULL);

            // Attend la fin du thread créé
            if(END==1)
            {
                pthread_join(thread_Reception, NULL);
            }
            /**/

            /***LE JEU***/
            intro();
            enigme1();
            enigme2();
            enigme3();
            enigme4();
            fin();

            /***LE JEU***/

        }
        /* sinon, on affiche "Impossible de se connecter" */
        else
        {
            printf("Impossible de se connecter\n");
        }

        /* On ferme la socket */
        closesocket(sock);

#if defined (WIN32)
        WSACleanup();
#endif
    }

    /* On attend que l'utilisateur tape sur une touche, puis on ferme */
    getchar();

    return EXIT_SUCCESS;
}

void my_delay(int i)    /*Pause l'application pour i ms*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=((i*CLOCKS_PER_SEC)/1000));
}

void* Reception(void* data)
{
    while (1)
    {
        char buffer[32]= {0};
        if(recv(sock,buffer,32,0)!= SOCKET_ERROR)
            printf("Abyss(IA): %s",buffer);
    }
    return NULL;
}

void intro()
{
    system("cls");
    printf(" 19 decembre 2014, c'est dans un petit appartement miteux de Los Angeles que\n");
    my_delay(1000);
    printf("l'agent Harry Lambart, se reveille apres une nuit agite,  entre vie de paria et descente\n");
    my_delay(1000);
    printf("d'alcool dans le bar du coin.\n\n");
    my_delay(1000);

    printf("Harry : Qu'est-ce que j'ai mal a la tete j'aurais jamais du boire autant, encore une affaire\n");
    my_delay(1000);
    printf("dont je dois regler avant  ma retraite anticipe.\n");
    my_delay(1000);
    printf("Le decoupeur de main, quel genre de cretin prendrait ce nom idiot\n");
    my_delay(1000);
    printf("il doit etre  completement fou ... on l'est peut etre un peux tous au fond.\n\n");
    my_delay(1000);

    printf("*votre abyss-glass s'active* \n");
    my_delay(1000);
    printf("Abyss : alors, toujours pas reveille ?\n");
    my_delay(1000);
    printf("Harry : oof qu'est ce que tu me veux ? technologie de con\n");
    my_delay(1000);
    printf("Abyss : vous avez recu un nouvel appel, inspecteur\n");
    my_delay(1000);
    printf("Harry : ouvre appel\n");
    my_delay(1000);
    printf("Vanalo : on a du nouveau au sujet de l'affaire du decoupeur de main, il a encore tue cette fois-ci\n");
    my_delay(1000);
    printf("une jeune femme en prenant ses deux mains avec lui\n");
    my_delay(1000);
    printf("Harry : ok j'arrive tout de suite.\n");
    my_delay(1000);
    printf("Abyss : je vous appel un taxi, monsieur ?\n");
    my_delay(1000);
    printf("Harry : oui ,merci !\n\n");
    my_delay(1000);

    printf("Vous arrivez sur le palier d'une maison en plein centre-ville, vous entrez dans la maison\n");
    my_delay(1000);
    printf("et vous apercevez le corps sans vie d'une jeune femme blonde dans la cuisine,\n");
    my_delay(1000);
    printf("vous voyez qu'elle n'a plus ses main, cela vous choque un peu, mais,\n");
    my_delay(1000);
    printf("Apres tout vous avez l'habitude des scenes de crimes maintenant\n");
    my_delay(1000);
    printf("Vanalo : Bonjour inspecteur je n'avais pas remarque que vous etiez la, tenez, regardez, le\n");
    my_delay(1000);
    printf("meurtre a l'air encore recent, il n'y a pas de trace de bagarre, ni de lutte, on dirait que la\n");
    my_delay(1000);
    printf("personne a ete drogue ou alors empoisonnee et ensuite on lui a couper les mains.\n");
    my_delay(1000);
    printf("On attendra les reponses du laboratoire dans pas longtemps pour avoir de l'adn, mais ca semble mal partie.\n");
    my_delay(1000);
    printf("Harry : est-ce que vous avez des temoins du moins\n");
    my_delay(1000);
    printf("est-ce que des voisins ont une declaration a faire ?\n");
    my_delay(1000);
    printf("vanalo : non pour l'instant aucune, j'ai l'impression que tout ca s'est passe dans un silence\n");
    my_delay(1000);
    printf("total personne ne s'est rendu compte de quoi que ce soit ni aucune intrusion n'a ete detecte\n");
    my_delay(1000);
    printf("par l'alarme on dirait presque que la victime attendais quelqu'un justement, et on a ete\n");
    my_delay(1000);
    printf("contacte par le voisin qui a vu la porte ouverte des le matin et qui a trouver le corps.\n");
    my_delay(1000);
    printf("Harry : merci lieutenant\n");
    my_delay(1000);
    printf("Abyss : je percois les voisin de la victimes ,un etage plus bas, vous devriez leur posez des questions !\n");
    my_delay(1000);

    printf("Vous allez interroger les voisins et apres avoir pose plusieurs questions et demander quel\n");
    my_delay(1000);
    printf("etait l'etat de la victime avant de l'avoir trouve,\n");
    my_delay(1000);
    printf("Vous comprenez ensuite qu'elle preparait un rendez-vous galant,\n");
    my_delay(1000);
    printf("sans plus de detail , vous vous diriger vers la piece principale et trouver\n");
    my_delay(1000);
    printf("une boite scellee avec un code dessus vous poser un peu plus de question au voisin, il vous dit\n");
    my_delay(1000);
    printf("qu'il n'as jamais vue ca \n");
    my_delay(1000);
    printf("vous notez qu'il a aide a demenager la victime il y a pas longtemps.\n\n");
    my_delay(1000);

    printf("Vous decidez donc de prendre la boite avec vous et d'essayer de l'ouvrir\n");
    my_delay(1000);
    printf("Cette boite a l'air de s'inspirer du tres celebre jeu du Mastermind.\n");
    my_delay(1000);
    printf("Vous vous rendez compte que vous pouvez utiliser cette vieille dont on vous a parle qui\n");
    my_delay(1000);
    printf("permet de collecter des informations precieuses des indices ou meme de dechiffrer\n");
    my_delay(1000);
    printf("certains enigme qui pourrait se presenter  devant vous\n");
    my_delay(1000);
    printf("Vous etes *l'inspecteur et devez resoudre les enigmes.\n");
    getchar();

}

/********************************************************************************************************************************/
/*******************************************************ENIGME*1*****************************************************************/
/********************************************************************************************************************************/

void enigme1()
{

    char nTable_aleatoire[TAILLE]= {0};
    char nMatrice_Joueur[4][12]= {0};

    GenererNombreTable(nTable_aleatoire); //On génère le codes secret
    //AfficherTable(nTable_aleatoire); // On affiche le résultat

    Jouer(nTable_aleatoire,nMatrice_Joueur);

    printf("\nLe caneda s'ouvre\n");
}

int Jouer(char nTable_aleatoire[TAILLE],char nMatrice_Joueur[4][12])
{
    int Cadena=0,j=0;
    char nMatriceCode[TAILLE]= {0};
    while(Cadena!=1)
    {
        send(sock, nTable_aleatoire, TAILLE, 0);
        for (j=0; j<12; j++) //Nombre Essai = 12
        {
            Joueur(nMatrice_Joueur,j);//Le joueur rentre ses valeurs
            system("cls");

            AfficherMatrice(nMatrice_Joueur,nTable_aleatoire,j+1);//afficher la matrice des données du joueur
            Cadena=VerificationReussi(nTable_aleatoire,nMatrice_Joueur,j);

            CalculMatrice(nMatrice_Joueur,nMatriceCode,j);
            send(sock, nMatriceCode, TAILLE,0);
            if(Cadena==1)
            {
                return 0;
            }
        }
        GenererNombreTable(nTable_aleatoire);
        printf("Le decodage a echoue, vous devez reessayer ,le cadena semble avoir change de code.");
        getchar();
    }
    return 0;
}

void GenererNombreTable(char nTable_aleatoire[TAILLE])  //Générer un nombre aléatoire
{

    srand(time(NULL));
    int doublon=0; //

    for(int i=0; i<TAILLE; i++) // On vérifie qu'il n y a pas de doublon
    {
        do
        {
            nTable_aleatoire[i] = rand()%10; // on génère un nombre aléatoire
            doublon=0;
            //printf("Nombre Generer Table: %d\n",nTable_aleatoire[i]);
            for(int j=0; j<i; j++)
            {
                if (nTable_aleatoire[i]== nTable_aleatoire[j])  //si  aucun doublon, on sort de la boucle
                {
                    doublon=1;
                }
            }
        }
        while(doublon==1);
    }
}

void AfficherTable(char nTable[TAILLE])  // Afficher la table aleatoire
{
    printf("Tableau aleatoire :\n");
    for(int i=0; i<TAILLE; i++)
    {
        printf("%d",nTable[i]);
    }
    printf("\n");
}

void CalculMatrice(char nMatrice_Joueur[4][12],char nMatriceCode[TAILLE],int j) // Afficher la matrice
{

    for (int i=0; i<TAILLE; i++)
    {
        nMatriceCode[i]=nMatrice_Joueur[i][j];
    }

}

void AfficherMatrice(char nMatrice_Joueur[4][12],char nTable_aleatoire[TAILLE],int Tour) // Afficher la matrice
{

    printf("Tableau Matrice :");
    int j=0;
    while (j!=Tour)
    {
        printf("\n");
        for (int i=0; i<TAILLE; i++)
        {
            printf("%d",nMatrice_Joueur[i][j]);
        }
        j++;
    }
    printf("\n");
}

void Joueur(char nMatrice_Joueur[4][12],int j)  //Rentrer la valeur du joueur
{

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


int VerificationReussi(char nTable_aleatoire[TAILLE],char nMatrice_Joueur[4][12],int j)  // Condition Victoire
{

    if((nMatrice_Joueur[0][j]== nTable_aleatoire[0])&&(nMatrice_Joueur[1][j]== nTable_aleatoire[1])&&(nMatrice_Joueur[2][j]==nTable_aleatoire[2])&&(nMatrice_Joueur[3][j]== nTable_aleatoire[3]))
    {
        //Les valeurs du code secret sont exactement les même que le joueur.

        printf("\nCode secret :");
        for (int i=0; i<TAILLE; i++)
        {
            Color(4,0);
            printf("%d",nMatrice_Joueur[i][j]);
            Color(15,0);
        }
        return 1;
    }
    return 0;
}

void Color(int couleurDuTexte,int couleurDeFond)  // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

/********************************************************************************************************************************/
/*******************************************************ENIGME*2*****************************************************************/
/********************************************************************************************************************************/

void enigme2()
{
    char complete[32];

    printf("Finalement vous avez reussi a ouvrir la boite et vous y trouvez un bout de papier avec une\n");
    my_delay(1000);
    printf("inscription dessus.\n");
    my_delay(1000);
    printf("Bonjour inspecteur, je sais que ca va faire plus de 10 ans que vous essayez de me chercher et\n");
    my_delay(1000);
    printf("surtout que vous essayer en vain, alors j'ai decide de rendre ca un peu plus amusant\n");
    my_delay(1000);
    printf("j'espere que vous avez aime mon premier jeu car ce ne sera pas le dernier, \n");
    my_delay(1000);
    printf(" en attendant je vous donne rendez-vous devant le panneau de la rue Saint-Clair\n");
    my_delay(1000);
    printf("Harry : putain je savais que c'etait un tordu mais a ce point-la il se paie notre tête , si\n");
    my_delay(1000);
    printf("seulement je le trouve…\n");
    my_delay(1000);
    printf("Abyss : calmez vous inspecteur je sens votre pou monte en fleche!\n");
    my_delay(1000);
    printf("Vanalo : je pense qu'on devrait envoyer toutes nos unites la-bas.\n");
    my_delay(1000);
    printf("Harry : non laissez j'ai l'impression que ce jeu est fait pour moi, apres tout c'est moi qu'il\n");
    my_delay(1000);
    printf("veut et c'est moi qu'il l'aura.\n");
    my_delay(1000);
    printf("Vanalo : sje vous fais confiance mais faites attention a vous..\n");
    my_delay(1000);
    printf("Harry : ne vous inquietez pas\n");
    my_delay(1000);
    printf("Abyss : je prepare un appel d'urgence au cas ou\n\n");
    my_delay(1000);

    printf("Vous vous rendez a la rue Saint-Clair et vous voyez un panneau representant toutes les rues\n");
    my_delay(1000);
    printf("Aux alentours de la place centrale , avec des LED accroche qui ont tout l'air d'avoir la même\n");
    my_delay(1000);
    printf("couleur et vous voyez un bout de papier accrocher dessus , avec marque :\n");
    my_delay(1000);
    printf("«  croyez-moi que de loin je vous observe et vous surveille et je ne doutais pas de vous je vois\n");
    my_delay(1000);
    printf("vous alliez venir seul en tout cas c'est ce que j'espere, de plus que vous n'avez pas peur\n");
    my_delay(1000);
    printf("d'avoir une arme braquee sur vous en tout cas a distance car c'est ma seule facon d'etre sur\n");
    my_delay(1000);
    printf("que vous soyez vraiment seul. Maintenant voyez un peu ce jeu que j'ai moi-meme\n");
    my_delay(1000);
    printf("confectionner pour vous et vous allez devoir deviner ou est le prochain cadavre que j'ai\n");
    my_delay(1000);
    printf("cache ,vous allez devoir, dechiffrer l'enigme ,bien qu'il ressemble a un jeu assez connu avec\n");
    my_delay(1000);
    printf("des petits bateaux. »\n");
    my_delay(1000);
    printf("Harry : IL SE PAIE MA TETE ! le salaud, bon .. je n'ai pas le choix ..\n");
    my_delay(1000);
    printf("Mais ..c'est une bataille navale , il se paye vraiment ma tete ..\n");
    my_delay(1000);
    printf("Abyss :faites attention a vous monsieur, je ne percois pas sa localisation..\n\n");
    my_delay(1000);

    printf("Vous laissez l'Abyss de se charger de la seconde enigme et vous examine le corps en attendant");


    recv(sock,complete,32,0);


}


/********************************************************************************************************************************/
/*******************************************************ENIGME*3*****************************************************************/
/********************************************************************************************************************************/
#define TAILLE_Mot 10

void afficheGrille(char nGrille[TAILLE_Mot][TAILLE_Mot]);

int enigme3()
{
    printf("Une fois que la bonne LED c'est allume une petite boite pas loin de la s'ouvre a distance avec\n");
    my_delay(1000);
    printf("une petite lettre dedans d'ou est note\n");
    my_delay(1000);
    printf("«bravo je vois que vous avez reussi je vous laisse maintenant appeler vos petits camarades\n");
    my_delay(1000);
    printf("pendant ce temps-la je preparerai notre prochain jeu, inspecteur j'espere vous voir vite »\n\n");
    my_delay(1000);

    printf("Harry : Appelle a toute les unites , il y a un tireur cacher quelque part non loins des batiments aux\n");
    my_delay(1000);
    printf("Alentours il n'est pas loin et un cadavre dans la rue que je vais vous indiquer\n");
    my_delay(1000);
    printf("Vanalo : ok chef on est sur le coup\n");
    my_delay(1000);
    printf("Abyss : voici un itineraire plus court pour vous rendre à l'addresse\n\n");
    my_delay(1000);

    printf("Une fois dans la rue principale vous decouvrez le cadavre d'une jeune femme cachee dans un\n");
    my_delay(1000);
    printf("sac-poubelle avec cette fois-ci un mot .\n");
    my_delay(1000);
    printf("Il est marque «  mots croises »\n\n");
    my_delay(1000);

    printf("Abyss : je detecte des empreintes inconnues sur le journal\n");
    my_delay(1000);
    printf("Harry : je n'y crois pas, il y a vraiment un message cache dans les mots croises?\n");
    my_delay(1000);
    printf("s'il n'a mit des mots c'est-a-dire que ce qu'on doit chercher est un nom..\n");
    my_delay(1000);
    printf("Vanalo : ok mais ou est ce fameux mots croise\n");
    my_delay(1000);
    printf("Harry :  ca je l'ignore mais on va pas tarder a le decouvrir\n");
    my_delay(1000);
    printf("Abyss : commencons par identifier la victime\n");
    my_delay(1000);
    printf("Harry : oui !\n");
    my_delay(1000);
    printf("Lorsque vous decouvrez l'identite de la femme tuee et une fois encore cette femme n'a\n");
    my_delay(1000);
    printf("plus de mains\n");
    my_delay(1000);
    printf("Une fois entre a l'interieur vous decouvrirai que rien n'a ete casse rien n'a ete vole tout\n");
    my_delay(1000);
    printf("comme la premiere morte et que vous devinez quel est le mode operatoire du tueur.\n");
    my_delay(1000);
    printf("Harry : ce tare et au final un vrai sadique il trouve des femmes les drague se fait inviter par\n");
    my_delay(1000);
    printf("elles et ensuite les tues en douceur avec un poison pour ensuite decouper leur main et joue\n");
    my_delay(1000);
    printf("Avec la police.\n");
    my_delay(1000);
    printf("Vanalo : tiens c'est bizarre ce corps a l'air beaucoup plus vieux que l'autre qu'on avait vu\n");
    my_delay(1000);
    printf("Avant on dirait qu'il a ete tu es il y a au moins 3 jours\n");
    my_delay(1000);
    printf("Harry : pourquoi il a fait ça \n");
    my_delay(1000);
    printf("Abyss : on dirait qu'il preparait ça depuis un moment \n");
    my_delay(1000);
    printf("Harry : ce cingle ne veux pas juste se faire \n");
    my_delay(1000);
    printf("Arreter ni meme juste jouer avec nous j'ai l'impression qu'il a un compte a regler avec moi et \n");
    my_delay(1000);
    printf("c'est pour cela que je vais le trouver et regler son compte. \n\n");
    my_delay(1000);

    printf("Vous trouvez sur la table de la salle a manger une vieille page de journal avec un mot croise a\n");
    my_delay(1000);
    printf("l'interieur on dirait qu'il a ete fait main oui, sans doute par le tueur en serie lui-meme\n");
    my_delay(1000);
    printf("Harry : je crois que il veut jouer avec nous encore une fois mais qu'est-ce que je suis cense\n");
    my_delay(1000);
    printf("trouver.\n");
    my_delay(1000);
    printf("*Le telephone sonne*\n");
    my_delay(1000);
    printf(" le tueur en serie :Allo cher  j'espere que notre petit je vous amuser je voulais appeler pour essayer de voir\n");
    my_delay(1000);
    printf("dans quel etat etes-vous en ce moment je n'aimerais pas que mon patient prefere se sente\n");
    my_delay(1000);
    printf("un petit peu trop stresse par notre chat rendez-vous.\n");
    my_delay(1000);
    printf("Abyss : je ne peux pas trasser le lieu de l'appelle\n");
    my_delay(1000);
    printf("Harry : ecoute-moi bien petite saloperie, arrete tout de suite tes conneries tu rentres\n");
    my_delay(1000);
    printf("maintenant donne-moi un rendez-vous n'importe ou on parlera et j'essayerai d'alleger ta peine\n");
    my_delay(1000);
    printf("Le tueur en serie : J'espere que vous plaisantez c'est trop tard pour ma peine ce que je veux\n");
    my_delay(1000);
    printf("c'est d'abord jouer avec vous ou vous tester, vous etes mon patient et de toute facon c'est\n");
    my_delay(1000);
    printf("trop tard pour ma peine comme dit je sais que je vais en avoir pour tres longtemps alors\n");
    my_delay(1000);
    printf("Autant finir en beaute, vous trouverez dans ce mot croise mon emplacement .\n");
    my_delay(1000);
    printf("A tres vite cher inspecteur\n");
    my_delay(1000);
    printf("Harry : le nom de la rue est un homme connue, pour qui il se prend \n");
    my_delay(1000);
    getchar();

    printf("Le mot croisee:\n");
    printf("Press Enter!\n");
    getchar();
    char nGrille[TAILLE_Mot][TAILLE_Mot]= {  {'S','Q','N','T','B','M','N','Y','O','F'},
        {'W','C','Z','W','N','O','N','Q','X','Y'},
        {'F','Q','E','B','X','Z','I','U','B','N'},
        {'C','I','S','I','F','A','J','K','W','N'},
        {'M','P','L','Q','Z','R','I','P','V','U'},
        {'S','K','N','S','U','T','G','S','I','R'},
        {'P','J','E','F','F','E','R','S','O','N'},
        {'Z','O','E','H','R','B','T','R','R','T'},
        {'J','C','H','O','P','I','N','S','G','B'},
        {'Q','T','K','E','N','N','E','D','Y','Z'}
    };
    afficheGrille(nGrille);

    char Word[32],test[32]= {'0'};
    char Jefferson[11],Nixon[7],Kennedy[9],Mozart[8],Chopin[8];
    int R_Jefferson,R_Nixon,R_Kennedy,R_Mozart,R_Chopin;

    while(1)
    {
        system("cls");
        afficheGrille(nGrille);
        printf("Ecrivez la reponse en majuscule\n");
        fgets(Word,32,stdin);

        strcpy(Jefferson, "JEFFERSON\n");
        R_Jefferson = strncmp(Word, Jefferson, 11);
        if (R_Jefferson == 0)
            printf("Ce n'est pas la bonne rue essayons autre chose!\n");

        strcpy(Nixon, "NIXON\n");
        R_Nixon = strncmp(Word, Nixon, 11);
        if (R_Nixon == 0)
        {
            printf("Vous avez trouve\n");
            send(sock,test,32,0);
            return 0;
        }

        strcpy(Kennedy, "KENNEDY\n");
        R_Kennedy = strncmp(Word, Kennedy, 11);
        if (R_Kennedy == 0)
            printf("Ce n'est pas la bonne rue essayons autre chose!\n");

        strcpy(Mozart, "MOZART\n");
        R_Mozart = strncmp(Word, Mozart, 11);
        if (R_Mozart == 0)
            printf("Ce n'est pas la bonne rue essayons autre chose!\n");

        strcpy(Chopin, "CHOPIN\n");
        R_Chopin = strncmp(Word, Chopin, 11);
        if (R_Chopin == 0)
            printf("Ce n'est pas la bonne rue essayons autre chose!\n");
    }
}


void afficheGrille(char nGrille[TAILLE_Mot][TAILLE_Mot])
{
    int i,j;
    for (i=0; i<TAILLE_Mot ; i++)
    {
        Color(2,0);
        printf("|");
        for(j=0; j<TAILLE_Mot; j++)
        {
            printf("%c",nGrille[i][j]);
            printf("|");// Afficher la grille
        }
        printf("\n");
        Color(15,0);
    }
}

int enigme4()
{
    printf("Apres avoir visite les deux rues, et n'avoir rien trouve, vous decidez de vous rendre a la\n");
    my_delay(1000);
    printf("derniere rue une ruelle un peu connu des gangs et des vendeur de drogue, vous y emmener\n");
    my_delay(1000);
    printf("seul car c'est votre ultime et dernier espoir de voir ce que tu as ramene des renforts vous\n");
    my_delay(1000);
    printf("semble un petit peu trop risque au cas ou il y a des tiendrai une otage, ou encore s'il lui\n");
    my_delay(1000);
    printf("prenait de s'enfuir\n");
    my_delay(1000);
    printf("Harry : bon alors ou es-tu espece de salopard\n");
    my_delay(1000);
    printf("Le tueur en serie : oh mais qui voila c'est notre cher inspecteur\n");
    my_delay(1000);
    printf("Vous pointez votre arme vers lui mais soudain vous voyez que il tient quelqu'un en otage\n");
    my_delay(1000);
    printf("donc sa tete est cache par un sac ah, vous ne voyez pas la tete du tueur en serie car il fait\n");
    my_delay(1000);
    printf("trop sombre.\n");
    my_delay(1000);
    printf("Abyss : je detecte un pou cette femme est vivante mais inconsciente\n");
    my_delay(1000);
    printf("Harry : espece de salopard qu'est-ce que tu veux au final\n");
    my_delay(1000);
    printf("Le tueur en serie : premierement j'aimerais vous deposer votre arme, ensuite, admirer le\n");
    my_delay(1000);
    printf("merveilleux travail que j'ai fait sur cette page\n");
    my_delay(1000);
    printf("Apres avoir lance votre arme par terre vous voyez l'horreur cafe cet homme sur ce qui\n");
    my_delay(1000);
    printf("semble etre une jeune femme.\n");
    my_delay(1000);
    printf("Harry: oh mon dieu mais qu'est-ce que vous avez fait\n");
    my_delay(1000);
    printf("Le tueur en serie : tout simplement ce que mon pere m'a toujours appris a force\n");
    my_delay(1000);
    printf("de me priver  d'amour et de tolerance j'ai fini par devenir fou maintenant regarder la\n");
    my_delay(1000);
    printf("ou j'en suis-je croyais que je devrais plaindre qui le monde, ce n'est pas de ma faute si je suis\n");
    my_delay(1000);
    printf("devenu enfin j'espere que c'est ce que vous pensez car de toute facon\n");
    my_delay(1000);
    printf("c'est ce que pense tout le monde.\n");
    my_delay(1000);
    printf("Harry : ecouter je ne sais pas ce qu'a fait votre pere\n");
    my_delay(1000);
    printf("Le tueur en serie : evidemment que vous ne le savez pas vous avez ete juste aveugle comme\n");
    my_delay(1000);
    printf("tous ceux qui ont essaye de m'aider\n");
    my_delay(1000);
    printf("Harry : ecoutez je sais que vous avez eu une enfance tres douloureuse et tres dur mais\n");
    my_delay(1000);
    printf("laissez-moi vous aider a avoir une meilleure vie maintenant je peux essayer de vous aider\n");
    my_delay(1000);
    printf("Le tueur en serie : je vous l'ai deja dit il est deja trop tard pour moi mais pas trop tard pour\n");
    my_delay(1000);
    printf("cette jeune et magnifique personne et encore moins pour vous apres tout j'essaie un peu\n");
    my_delay(1000);
    printf("de vous rendre fier..\n");
    my_delay(1000);
    printf("Harry : comment ca ?\n");
    my_delay(1000);
    printf("Le tueur en serie : vous allez devoir repondre a une petite enigme de ma part que j'ai\n");
    my_delay(1000);
    printf("moi-meme confectionner rien que pour vous avec tout un amour special, vous allez devoir\n");
    my_delay(1000);
    printf("trouver qui je suis avec tous les indices que vous avez trouve, ca ne doit pas etre trop dur et a\n");
    my_delay(1000);
    printf("la limite si vous n'avez pas vraiment trouve d'indices sur moi, je vous donnerai qu'une petite\n");
    my_delay(1000);
    printf("phrase pour vous aidez\n");
    my_delay(1000);
    printf("Harry : ok alors balance ta phrase  qu'on en finisse\n");
    my_delay(1000);
    printf("? : Pour roi on dit même que je suis son digne successeur ,je me situe entre le pere et le saint esprit,\n ");
    my_delay(1000);
    printf("on dit meme que je suis le reflet du premier, dans l'arbre je suis celui en dessous mais je represente male \n ");
    my_delay(1000);
    getchar();

    char Word[32];
    char Fils[6];
    int Reponse;
    printf("Ecrivez la reponse en majuscule");
    while(1)
    {
        fgets(Word,32,stdin);
        strcpy(Fils, "FILS\n");
        Reponse = strncmp(Word, Fils, 11);
        if (Reponse == 0)
            {
                send(sock, Word, 32, 0);
                return 0;
            }
    }
}


void fin()
{
    printf("Harry : Je ne vois toujours pas qui vous pouvez etre je n'ai aucun fils, il est mort depuis un\n");
    my_delay(1000);
    printf("moment\n");
    my_delay(1000);
    printf("Le tueur en serie : ah c'est ce que vous croyez ce que l'on vous a raconte c'est bien que le\n");
    my_delay(1000);
    printf("foyer ou on arrete que il votre fils apres l'avoir battu a ete brule par un individu suspect qui a\n");
    my_delay(1000);
    printf("ete  enferme par vous-meme non, on vous a meme dit que c'etait l'un des employes de ce\n");
    my_delay(1000);
    printf("foyer. Qui vous dit que ce n'etait pas un pensionnaire lui-meme et\n");
    my_delay(1000);
    printf("qui aurait remplace son\n");
    my_delay(1000);
    printf("cadavre par celui d'un de ses petits camarades, et qu'on lui aurait pas briser les dents pour\n");
    my_delay(1000);
    printf(" ne pas reconnaitre les empreintes de dents mais qu'on lui aurait mis a côte de lui\n");
    my_delay(1000);
    printf("le jouer qui avait offert sa jeune mere mort dans un accident de voiture, ceux-ci sont\n");
    my_delay(1000);
    printf("tellement bien comme histoire vous ne trouvez pas, mais bon comme vous etes trop aveugle\n");
    my_delay(1000);
    printf("pour comprendre cette realite alors je devrais  tuer cette personne et toi avec, papa…\n");
    my_delay(1000);
    printf("Le tueur en serie mettez d'autre que votre fils vous en rendez compte au moment\n");
    my_delay(1000);
    printf("une voiture passe et que les phares aveugle presque le visage de votre 'fils' ce qui n'empeche\n");
    my_delay(1000);
    printf("pas de charger son son arme et de viser la tete de la pauvre jeune fille…");
    my_delay(1000);
    printf("Abyss: vite inspecteur");
    my_delay(1000);
    printf("vous vous precipiter tres\n");
    my_delay(1000);
    printf("vite sur votre arme et voulu tirer dessus pour l'immobiliser, mais comme il fait noir vous\n");
    my_delay(1000);
    printf("visez la tete sans le vouloir ce qui resulte la mort de ce tueur en serie qui n'etait d'autre que\n");
    my_delay(1000);
    printf("votre fils…\n");
    my_delay(1000);
    printf("Apres l'arrivee de la police, et l'embarcation du corps de votre fils et de la fille qui detenait\n");
    my_delay(1000);
    printf("on vous donne une lettre qui a ete dans l'une des poches de la veste du tueur disant tres\n");
    my_delay(1000);
    printf("clairement qu'il esperait que vous lui pardonner pour tout ce qu'il a fait mais que c'etait la\n");
    my_delay(1000);
    printf("seule facon pour lui de vous donner ce que vous voulez une grande affaire qui merite toute\n");
    my_delay(1000);
    printf("votre attention l'attention qu'il n'a jamais eu, et a la fin de cette lettre un petit mot disant\n");
    my_delay(1000);
    printf("bonne retraite cher inspecteur.\n");
    my_delay(1000);
    printf("fin…");
    my_delay(1000);
    printf("----------------THANK-FOR-PLAYING---------------------");
    exit(0);

}
