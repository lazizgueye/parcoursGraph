#ifndef PARCOURS_LARGEUR_H_INCLUDED
#define PARCOURS_LARGEUR_H_INCLUDED
#include "Graphe_Matrice.h"
#include "Graphe_Liste.h"

#define BLANC 0
#define GRIS 1
#define NOIR 2

typedef struct {
    SID *f;
    int tete;
    int queue;
}FILES;

void allouer_file(FILES *f, int n);
void libere_file(FILES *f);
void initialiser_file(FILES *f);
void enfiler (FILES *f, SID s);
void defiler(FILES *f);
SID tete(FILES *f);
void parcours_en_largeur_Matrice (GRAPHE *g, SID s);
void parcours_en_largeur_Liste (GRAPHE_2 *g, SID s);


#endif // PARCOURS_LARGEUR_H_INCLUDED
