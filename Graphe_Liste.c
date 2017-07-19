#include "Graphe_Liste.h"

void reservation_en_memoire_Liste (int n, GRAPHE_2 **g){
    int i;
    *g = malloc( sizeof(GRAPHE_2));
    (*g)->n = n;

    (*g)->Listes =  malloc(n * sizeof(MAILLON*));

    for (i=0; i<n ; i++)
        (*g)->Listes[i] = malloc(n * sizeof(MAILLON));
}

void liberation_memoire_Liste (GRAPHE_2 *g){
     free(g);
     printf("liberation de la memoire du graphe\n\n");
}

void cree_graphe_vide_Liste (GRAPHE_2 *g){
    int i;
    for(i=0;i<g->n;i++)
        g->Listes[i]->S=0;
    printf("\n");
}

void afficher_graphe_Liste(GRAPHE_2 *g){
    int i;
    for (i = 0; i < g->n; ++i)
    {
        MAILLON* pCrawl ;
        pCrawl= g->Listes[i]->S;
        printf("La Liste d'Adjacent a %d est : ( ", i);
        while (pCrawl)
        {
            printf("%d ", pCrawl->S);
            pCrawl = pCrawl->suivant;
        }
        printf(")\n");
    }
    printf("\n\n");
}

MAILLON *ajoutNoeud(SID_2 i){
    MAILLON* newNode = (struct maillon*) malloc(sizeof(struct maillon));
    newNode->S = i;
    newNode->suivant = NULL;
    return newNode;
}

void ajouter_connection_Liste(GRAPHE_2 *g, SID_2 i, SID_2 j){
    MAILLON *gListe = ajoutNoeud(j);
    gListe->suivant=g->Listes[i]->S;
    g->Listes[i]->S= gListe;
    printf("Ajout Connection a l'arc (%d , %d)", i, j);
}

void retirer_connection_Liste (GRAPHE_2 *g, SID_2 i, SID_2 j){
    MAILLON* newNoeud ;
    newNoeud= g->Listes[i]->S;

    while (newNoeud){
        if(newNoeud->S==j)
            newNoeud->S = newNoeud->suivant;
        newNoeud = newNoeud->suivant;
    }
}

int est_adjacent_Liste (GRAPHE_2 *g, SID_2 i, SID_2 j){
    MAILLON* newNoeud ;
    newNoeud= g->Listes[i]->S;

    while (newNoeud){
        if(newNoeud->S==j)
            printf(" 1 ");
        newNoeud = newNoeud->suivant;
    }
}

void recupere_sommet_adjacent_Liste (GRAPHE_2 *g, SID_2 i, SID_2 *adj, int *ndadj){
    int j,k=0;

    MAILLON* newNoeud ;
        newNoeud= g->Listes[i]->S;

    while (newNoeud){
        adj[k]=newNoeud->S;
        k++;
        ndadj[i]=k;
        newNoeud = newNoeud->suivant;
    }

    printf("Le(s) Sommet(s) adj a %d sont : ",i);
    for(j=0;j<k;j++){
        printf("%d, ",adj[j]);
    }
    printf("  et le nombre de Sommets est : %d\n\n",ndadj[i]);
}

void copie_graphe_Liste (GRAPHE_2 *g, GRAPHE_2 **g2){
    int i;

    printf("La Copie du GRAPHE g dans g2\n");
    reservation_en_memoire_Liste (g->n, &(*g2));
    cree_graphe_vide_Liste (*g2);
    for(i=0;i<g->n;i++)
        (*g2)->Listes[i]->S=g->Listes[i]->S;
}

void lire_graphe_Liste (char *nom, GRAPHE_2 *g){
    int i,j;
    int k[2];
    int pValeur=1;
    int l_entier;
    printf("\nLecture du fichier et insertion dans graphe\n\n");

    FILE*fichier;
    fichier=fopen(nom,"r");
    if (fichier!=NULL){
        i=0,j=0;
        while(fscanf(fichier, "%d", &l_entier) !=EOF){
            if ((l_entier != '\n')&&(l_entier != ' ')){
                if(pValeur==1){
                    free(g);
                    reservation_en_memoire_Liste (l_entier, &g);
                    cree_graphe_vide_Liste (g);
                    pValeur=0;
                }
                else{
                    k[i]=l_entier;
                    i++;
                    if(i == 2){
                        ajouter_connection_Liste(g, k[0], k[1]);
                        printf("\n");
                        for(j=0;j<i;j++){
                            k[j]='\0';
                            i=0;
                        }
                    }
                }
            }
        }
    }
    fclose(fichier);
}

void ecrit_graphe_Liste (char *nom, GRAPHE_2 *g){
    int i;
    MAILLON* newNoeud ;
    printf("\nEcriture du graphe dans le fichier ''fichierEcrit.txt'' allez verifier \n\n");

    FILE*fichier=NULL;
    fichier=fopen(nom,"w");

    fprintf (fichier, "%d\n", g->n);

    for(i=0;i<g->n;i++){
        newNoeud= g->Listes[i]->S;

        while (newNoeud)
            {
               fprintf (fichier, "%d %d\n", i,newNoeud->S);
                newNoeud = newNoeud->suivant;
            }
    }
}
