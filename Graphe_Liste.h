#ifndef GRAPHE_LISTE_H_INCLUDED
#define GRAPHE_LISTE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        int *d;         /*date de decouverte*/
        int *f;         /* date de fin de traitement */
        int *pred;      /*Predecesseur sur le chemin */
        int couleur;   /*couleur du sommet */
}Aziz2;

typedef int SID_2;  /* Renommage des entiers pour nommer les sommets */
typedef struct maillon{
        SID_2 S;    /* Sommet stocké dans le maillon */
        struct maillon *suivant;
    }MAILLON;

typedef struct{
        int n;    /* Nombre de sommets */
        MAILLON **Listes;  /* Liste d'Adjacence */
        Aziz2 *tabSom;
                        /* Listes[i] : Liste chainée contenant les successseurs du sommet */
    }GRAPHE_2;


void reservation_en_memoire_Liste (int n, GRAPHE_2 **g);
/* Reserver l'espace memoire nécéssaire pour representer un graphe comportant n sommets */

void liberation_memoire_Liste (GRAPHE_2 *g);
/* Liberation de la memoire occupée par le graphe g */

void cree_graphe_vide_Liste (GRAPHE_2 *g);
/* Initialiser la structure de telle sorte qu'elle represente un graphe sans arc */

void afficher_graphe_Liste(GRAPHE_2 *g);
/* afficher le graphe */

void ajouter_connection_Liste(GRAPHE_2 *g, SID_2 i, SID_2 j);
/* Ajouter un arc entre les sommets i et j dans le graphe g */

void retirer_connection_Liste (GRAPHE_2 *g, SID_2 i, SID_2 j);
/* Retirer l'arc entre les sommets i et j s'il existe dans le graphe g */

int est_adjacent_Liste(GRAPHE_2 *g, SID_2 i, SID_2 j);
/* Retourner i si j est un successeur de i dans le grapheg, 0 sinon */

void recupere_sommet_adjacent_Liste (GRAPHE_2 *g, SID_2 i, SID_2 *adj, int *ndadj);
/* Recupere dans un tableau adj les sommets adjacents à i dans g et fournit egalement le nombre de sommets adjacents dans ndadj */

void copie_graphe_Liste (GRAPHE_2 *g, GRAPHE_2 **g2);
/* Copie le graphe g dans le graphe g2 */

void lire_graphe_Liste (char *nom, GRAPHE_2 *g);
/* Lit et range dans g le graphe contenu dans le fichier nom */

void ecrit_graphe_Liste (char *nom, GRAPHE_2 *g);
/* Ecrit le graphe g dans le fichier nom */


#endif // GRAPHE_LISTE_H_INCLUDED
