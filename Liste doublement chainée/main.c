#include <stdlib.h>
#include <stdio.h>

#include "dblist.c"

int main()
{
        dblist *pdbListe = malloc(sizeof(dblist));

        Init(pdbListe);

        Ins_debut(pdbListe,10);
        Ins_fin(pdbListe,20);
        Ins_fin(pdbListe,40);
        Ins_debut(pdbListe,50);

        Affiche(*pdbListe);
        puts("--------------");

        printf("%d\n",Supp_debut(pdbListe));
        printf("%d\n",Supp_debut(pdbListe));
        printf("%d\n",Supp_fin(pdbListe));
        puts("--------------");

        Ins_fin(pdbListe,30);

        printf("%d\n",Supp_debut(pdbListe));
        printf("%d\n",Supp_debut(pdbListe));
        puts("--------------");

        Clear(pdbListe);

        free(pdbListe);

        return 0;
}
