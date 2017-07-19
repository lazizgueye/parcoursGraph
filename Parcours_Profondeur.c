#include "Parcours_Profondeur.h"


void allouer_pile(PILE *p, int n){
    p->p=(SID*)malloc(sizeof(SID));
}

void libere_pile(PILE *p){
    free(p->p);
}

void initialiser_pile(PILE *p){
    p->ptr=0;
}

void empiler (PILE *p, SID s){
    p->p[p->ptr++]=s;
}

void depiler(PILE *p){
    if(p->ptr)
        p->ptr--;
}

SID sommet(PILE *p){
    return (p->ptr) ? p->p[p->ptr-1] : -1;
}

void parcours_en_profondeur (GRAPHE *g, SID s){            // parcours profondeur matrice
    //PILE P;
    int i, temps;

    /*allouer_file(&P,(g)->n);
    initialiser_file (&P);*/

    g->tabSom=malloc(g->n * sizeof(Aziz));
    g->tabSom[s].couleur=BLANC;

    for(i=0;i<g->n;i++){
        if(g->M[s][i] == 1){
            g->tabSom[i].couleur=BLANC;
            g->tabSom[i].pred = NULL;
        }
    }
    temps = 0;
    for(i=0;i<g->n;i++){
        if(g->tabSom[i].couleur == BLANC)
            visiterPep (g, s, temps);
    }
}

void visiterPep (GRAPHE *g, int s, int temps){
    int i;
    g->tabSom[s].couleur=GRIS;
    temps++;
    g->tabSom[s].d=temps;

    for(i=0;i<g->n;i++){
        if((g->M[s][i] == 1)&&(g->tabSom[i].couleur == BLANC)){
            printf(" %d ", s);
            g->tabSom[i].pred  = s;
            visiterPep(g,i,temps);
        }
        temps++;
        g->tabSom[s].f= temps;
        g->tabSom[s].couleur = NOIR;
    }
}

void parcours_en_profondeur_Liste (GRAPHE_2 *g, SID s){            // parcours profondeur liste
    //PILE P;
    int i, temps;

    /*allouer_file(&P,(g)->n);
    initialiser_file (&P);*/

    g->tabSom=malloc(g->n * sizeof(Aziz));
    g->tabSom[s].couleur=BLANC;

    for(i=0;i<g->n;i++){
        if(g->Listes[s]==i){
            g->tabSom[i].couleur=BLANC;
            g->tabSom[i].pred = NULL;
        }
    }
    temps = 0;
    for(i=0;i<g->n;i++){
        if(g->tabSom[i].couleur == BLANC)
            visiterPep_Liste (g, s, temps);
    }
}

void visiterPep_Liste(GRAPHE_2 *g, int s, int temps){
    int i;
    g->tabSom[s].couleur=GRIS;
    temps++;
    g->tabSom[s].d=temps;

    for(i=0;i<g->n;i++){
        if((g->Listes[s]==i)&&(g->tabSom[i].couleur == BLANC)){
            printf(" %d ", s);
            g->tabSom[i].pred  = s;
            visiterPep(g,i,temps);
        }
        temps++;
        g->tabSom[s].f= temps;
        g->tabSom[s].couleur = NOIR;
    }
}

