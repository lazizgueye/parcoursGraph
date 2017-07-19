#include "Parcours_Largeur.h"


void allouer_file(FILES *f, int n){
    f->f=(SID*)malloc(n*sizeof(SID));
}

void libere_file(FILES *f){
    free(f->f);
}

void initialiser_file(FILES *f){
    f->tete=f->queue=0;
}

void enfiler (FILES *f, SID s){
    f->f[f->queue++]=s;
}

void defiler(FILES *f){
    if(f->tete < f->queue)
        f->tete++;
}

SID tete(FILES *f){
    return (f->tete < f->queue) ? f->f[f->tete] : -1;
}

int estVide(FILES *f){
    return (f->tete == NULL) ? 1 : 0;
}

void parcours_en_largeur_Matrice (GRAPHE *g, SID s){            // parcours largeur matrice
    FILES F;
    int i;

    allouer_file(&F,(g)->n);
    initialiser_file (&F);

    g->tabSom=malloc(g->n * sizeof(Aziz));
    for(i=0;i<g->n;i++)
       g->tabSom[i].couleur=BLANC;

    g->tabSom[s].pred = NULL;
    g->tabSom[s].d = 0;
    g->tabSom[s].couleur= GRIS;

    enfiler(&F, s);

    while (tete(&F) != -1){
        s = tete(&F);
        printf(" %d ",s);

        for(i=0;i<g->n;i++){
            if((g->M[s][i] == 1)&&(g->tabSom[i].couleur == BLANC)){
                g->tabSom[i].couleur=GRIS;
                g->tabSom[i].d= g->tabSom[s].d + 1;
                g->tabSom[i].pred = s;
                enfiler(&F, i);
            }
        }

        defiler(&F);
        g->tabSom[s].couleur=NOIR;
    }
}

void parcours_en_largeur_Liste (GRAPHE_2 *g, SID s){            // parcours largeur Liste
    FILES F;
    int i;

    allouer_file(&F,(g)->n);
    initialiser_file (&F);

    g->tabSom=malloc(g->n * sizeof(Aziz));
    for(i=0;i<g->n;i++)
       g->tabSom[i].couleur=BLANC;

    g->tabSom[s].pred = NULL;
    g->tabSom[s].d = 0;
    g->tabSom[s].couleur= GRIS;

    enfiler(&F, s);

    while (tete(&F) != -1){
        s = tete(&F);
        printf(" %d ",s);

        for(i=0;i<g->n;i++){
            if((g->Listes[s]== i)&&(g->tabSom[i].couleur == BLANC)){
                g->tabSom[i].couleur=GRIS;
                g->tabSom[i].d= g->tabSom[s].d + 1;
                g->tabSom[i].pred = s;
                s=g->Listes[i]->suivant;
                enfiler(&F, s);
            }
        }

        defiler(&F);
        g->tabSom[s].couleur=NOIR;
    }
}
