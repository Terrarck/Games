#ifndef DBLIST_H_INCLUDED
#define DBLIST_H_INCLUDED

 /*  Structure repr�santant un �l�ment de la Liste. */

        typedef struct elem
        {
                int value;
                struct elem *prev;
                struct elem *next;
        } elem ;

 /*  Structure d'acc�s � la Liste. */

        typedef struct
        {
          elem *first;
          elem *last;
        }dblist;

 /*  Initialisation de la Liste. */

        void Init(dblist *List);

 /*  Ajout d'une valeur en fin de Liste. */

        void Ins_fin(dblist *List, int val);

 /*  Ajout d'une valeur en d�but de Liste. */

        void Ins_debut(dblist *List, int val);

 /*  Retrait d'une valeur en fin de Liste. */

        int Supp_fin(dblist *List);

 /*  Retrait d'une valeur en d�but de Liste. */

        int Supp_debut(dblist *List);

 /*  Affichage de toute la Liste. */

        void Affiche(dblist List);

 /*  Vider toute la Liste. */

        void Clear(dblist *List);


#endif
