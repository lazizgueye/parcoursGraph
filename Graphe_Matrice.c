#include "Graphe_Matrice.h"


void reservation_en_memoire (int n, GRAPHE **g){
    int i;
    *g = malloc( sizeof(GRAPHE));
    (*g)->n = n;

    (*g)->M =  malloc(n * sizeof(int*));

    for (i=0; i<n ; i++)
        (*g)->M[i] = malloc(n * sizeof(int));
}

void liberation_memoire (GRAPHE *g){
     free(g);
     printf("liberation de la memoire du graphe\n");
}

void cree_graphe_vide (GRAPHE *g){
    int i, j;
    for(i=0;i<g->n;i++)
         for(j=0;j<g->n;j++)
            g->M[i][j]=0;
    printf("\n");
}

void afficher_graphe(GRAPHE *g){
    int i, j;
    for(i=0;i<g->n;i++)
        for(j=0;j<g->n;j++)
            printf("l'arc M[%d,%d] = %d\n",i,j,g->M[i][j]);
    printf("\n");
}

void ajouter_connection (GRAPHE *g, SID i, SID j){
     g->M[i][j] = 1;
    printf("Ajout Connection a l'arc M[%d][%d] = %d", i, j, g->M[i][j]);
}

void retirer_connection (GRAPHE *g, SID i, SID j){
     g->M[i][j] = 0;
     printf("\n");
}

int est_adjacent (GRAPHE *g, SID i, SID j){
    if(g->M[i][j] == 1)
       return 1;
    return 0;
}

void recupere_sommet_adjacent (GRAPHE *g, SID i, SID *adj, int *ndadj){
    int j,k=0;
    for(j=0;j < g->n;j++){
        if(g->M[i][j] == 1){
            adj[k]=j;
            k++;
            ndadj[i]=k;
        }
    }
    printf("Le(s) Sommet(s) adj a %d sont : ",i);
    for(j=0;j<k;j++){
        printf("%d, ",adj[j]);
    }
    printf("  et le nombre de Sommets est : %d\n\n",ndadj[i]);
}

void copie_graphe(GRAPHE *g, GRAPHE **g2){
    int i,j;

    printf("La Copie du GRAPHE g dans g2\n");
    reservation_en_memoire(g->n, &(*g2));
    cree_graphe_vide(*g2);
    for(i=0;i<g->n;i++){
        for(j=0; j<g->n; j++){
           (*g2)->M[i][j]=g->M[i][j];
        }
    }
}

void lire_graphe(char *nomfichier, GRAPHE *g){
    int i,j;
    int k[2];
    int pValeur=1;
    int l_entier;
    printf("\nLecture du fichier et insertion dans graphe\n");

    FILE*fichier;
    fichier=fopen(nomfichier,"r");
    if (fichier!=NULL){
        i=0,j=0;
        while(fscanf(fichier, "%d", &l_entier) !=EOF){
            if ((l_entier != '\n')&&(l_entier != ' ')){
                if(pValeur==1){
                    free(g);
                    reservation_en_memoire(l_entier, &g);
                    cree_graphe_vide(g);
                    pValeur=0;
                }
                else{
                    k[i]=l_entier;
                    i++;
                    if(i == 2){
                        g->M[k[0]][k[1]]=1;
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

void ecrit_graphe(char *nom, GRAPHE *g){
    int i,j;
    printf("\nEcriture du graphe dans le fichier ''fichierEcrit.txt'' allez verifier \n\n");

    FILE*fichier=NULL;
    fichier=fopen(nom,"w");

    fprintf (fichier, "%d\n", g->n);
    for(i=0;i<g->n;i++)
        for(j=0;j<g->n;j++)
             fprintf (fichier, "%d %d\n", i,j);
}
