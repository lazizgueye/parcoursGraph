#ifndef GRAPHE_MATRICE_H_INCLUDED
#define GRAPHE_MATRICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        int *d;         /*date de decouverte*/
        int *f;         /* date de fin de traitement */
        int *pred;      /*Predecesseur sur le chemin */
        int couleur;   /*couleur du sommet */
}Aziz;

typedef int SID;  /* Renommage des entiers pour nommer les sommets */
typedef struct {
        int n;    /* Nombre de sommets */
        int **M;  /* Matrice d'Adjacence */
        Aziz *tabSom;
        /// ajouter

        ///
    }GRAPHE;     /* M[i][j] == 1 s'il y'a un arc de i vers j, 0 sinon */


void reservation_en_memoire (int n, GRAPHE **g);
/* Reserver l'espace memoire nécéssaire pour representer un graphe comportant n sommets */

void liberation_memoire (GRAPHE *g);
/* Liberation de la memoire occupée par le graphe g */

void cree_graphe_vide (GRAPHE *g);
/* Initialiser la structure de telle sorte qu'elle represente un graphe sans arc */

void afficher_graphe(GRAPHE *g);
/* afficher le graphe */

void ajouter_connection (GRAPHE *g, SID i, SID j);
/* Ajouter un arc entre les sommets i et j dans le graphe g */

void retirer_connection (GRAPHE *g, SID i, SID j);
/* Retirer l'arc entre les sommets i et j s'il existe dans le graphe g */

int est_adjacent (GRAPHE *g, SID i, SID j);
/* Retourner i si j est un successeur de i dans le grapheg, 0 sinon */

void recupere_sommet_adjacent (GRAPHE *g, SID i, SID *adj, int *ndadj);
/* Recupere dans un tableau adj les sommets adjacents à i dans g et fournit egalement le nombre de sommets adjacents dans ndadj */

void copie_graphe(GRAPHE *g, GRAPHE **g2);
/* Copie le graphe g dans le graphe g2 */

void lire_graphe(char *nomfichier, GRAPHE *g);
/* Lit et range dans g le graphe contenu dans le fichier nom */

void ecrit_graphe(char *nom, GRAPHE *g);
/* Ecrit le graphe g dans le fichier nom */

#endif // GRAPHE_MATRICE_H_INCLUDED
