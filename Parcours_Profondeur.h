#ifndef PARCOURS_PROFONDEUR_H_INCLUDED
#define PARCOURS_PROFONDEUR_H_INCLUDED
#include "Graphe_Matrice.h"
#include "Graphe_Liste.h"

#define BLANC 0
#define GRIS 1
#define NOIR 2

typedef struct {
    SID *p;
    int ptr;
}PILE;

void allouer_pile(PILE *p, int n);
void libere_pile(PILE *p);
void initialiser_pile(PILE *p);
void empiler (PILE *p, SID s);
void depiler(PILE *p);
SID sommet(PILE *p);
void parcours_en_profondeur (GRAPHE *g, SID s);
void visiterPep (GRAPHE *g, int s, int temps);
void parcours_en_profondeur_Liste (GRAPHE_2 *g, SID s);
void visiterPep_Liste (GRAPHE_2 *g, int s, int temps);


#endif // PARCOURS_PROFONDEUR_H_INCLUDED
