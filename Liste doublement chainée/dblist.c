#include <stdio.h>
#include <stdlib.h>

#include "dblist.h"

void Init(dblist *List)
{
   List->first = NULL;
   List->last = NULL;
}
/******************************************************************************/

void Ins_fin(dblist *List, int val)
{
   elem *nouv = malloc(sizeof(elem));
   if(!nouv) exit(EXIT_FAILURE);
   nouv->value = val;
   nouv->prev = List->last;
   nouv->next = NULL;
   if(List->last) List->last->next = nouv;
   else List->first = nouv;
   List->last = nouv;
}
/******************************************************************************/

void Ins_debut(dblist *List, int val)
{
   elem *nouv = malloc(sizeof(elem));
   if(!nouv) exit(EXIT_FAILURE);
   nouv->value = val;
   nouv->next = List->first;
   nouv->prev = NULL;
   if(List->first) List->first->prev = nouv;
   else List->last = nouv;
   List->first = nouv;
}
/******************************************************************************/

int Supp_fin(dblist *List)
{
   int val;
   elem *tmp = List->last;
   if(!tmp) return -1;
   val = tmp->value;
   List->last = tmp->prev;
   if(List->last) List->last->next = NULL;
   else List->first = NULL;
   free(tmp);
   return val;
}
/******************************************************************************/

int Supp_debut(dblist *List)
{
   int val;
   elem *tmp = List->first;
   if(!tmp) return -1;
   val = tmp->value;
   List->first = tmp->next;
   if(List->first)List->first->prev = NULL;
   else List->last = NULL;
   free(tmp);
   return val;
}
/******************************************************************************/

void Affiche(dblist List)
{
   elem *pelem = List.first;
   while(pelem)
   {
     printf("%d\n",pelem->value);
     pelem = pelem->next;
   }
}
/******************************************************************************/

void Clear(dblist *List)
{
   elem *tmp;
   elem *pelem = List->first;
   while(pelem)
   {
     tmp = pelem;
     pelem = pelem->next;
     free(tmp);
   }
   List->first = NULL;
   List->last = NULL;
}

