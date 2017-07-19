#include "Graphe_Matrice.h"
#include "Graphe_Liste.h"
#include "Parcours_Profondeur.h"
#include "Parcours_Largeur.h"

int main()
{
    int i,rep,rep2,rep22,rep3,rep1,rep4;
    char nomFichier[20];
    GRAPHE *gMatrice;
    GRAPHE *gMatrice_2;
    GRAPHE_2 *gListe;
    GRAPHE_2 *gListe_2;


    char *tab2[]={ "\t\##############################################################\n",
                   "\t\#                                                            #\n",
                   "\t\#    1) Aller dans GRAPHE MATRICE & PARCOURS (PROF & LARG)   #\n",   // menu
                   "\t\#    2) Aller dans GRAPHE LISTE   & PARCOURS (PROF & LARG)   #\n",
                   "\t\#    3) Quitter                                              #\n",
                   "\t\#                                                            #\n",
                   "\t\#                ******************************              #\n",
                   "\t\#                                 ***                        #\n",
                   "\t\#                                                            #\n",
                   "\t\#                    **    *****   *   *****         __  __  #\n",
                   "\t\#                  *****     *     *     *          |  ||  | #\n",
                   "\t\#                **    **  *****   *   *****        |  ||  | #\n",
                   "\t\#                                                   |  //  | #\n",
                   "\t\#                   *********************           | //// | #\n",
                   "\t\#                      ***************              | //// | #\n",
                   "\t\#                         *********                 |  //  | #\n",
                   "\t\#                            ***                    |  ||  | #\n",
                   "\t\#                             *                     |__||__| #\n",
                   "\t\#                                                            #\n",
                   "\t\##############################################################\n",
                   "\t\##############################################################\n"
    };

    char *tab3[]={ "\t#############################################\n",
                   "\t#                                           #\n",
                   "\t#       1)  Reservation En Memoire          #\n",
                   "\t#       2)  Afficher Graphe                 #\n",
                   "\t#       3)  Ajouter Connection              #\n",
                   "\t#       4)  Retirer Connection              #\n",
                   "\t#       5)  Est Adjacent                    #\n",
                   "\t#       6)  Recupere Sommet_adjacent        #\n",
                   "\t#       7)  Copie Graphe                    #\n",
                   "\t#       8)  Lire Graphe                     #\n",
                   "\t#       9)  Ecrit Graphe                    #\n",
                   "\t# ***** 10) PARCOURS EN LARGEUR *********** #\n",
                   "\t# ***** 11) PARCOURS EN PROFONDEUR ******** #\n",
                   "\t#       12) Retour au Menu Principal        #\n",
                   "\t#                                           #\n",
                   "\t#############################################\n",
                   "\t#############################################\n"
    };

    printf("\n\t\t/°(o_o)°\\Welcome to Leopold Aziz Gueye Programm's!\n\n");
    printf("Veuillez choisir une operation svp ...\n\n");

    for(i=0;i<21;i++){
        printf("%s",tab2[i]);                   // affichage du menu
    }

    printf("\nVotre Choix : ");                // choix
    scanf("%d",&rep);
    printf("\n");

     if(rep != 3){
        rep3=rep;
        do{
            if(rep3==1){
                system("cls");                                                           /// Representation par Matrice d'ajacent ///
                printf("\n\n\t\\\\\\\__VOUS ETES DANS GRAPHE MATRICE__///\n\n");
                for(i=0;i<17;i++){
                    printf("%s",tab3[i]);                   // affichage du menu
                }
                printf("\nVotre Choix : ");                // choix
                scanf("%d",&rep1);
                printf("\n\n");

                if(rep1 != 12){
                rep4=rep1;
                    do{
                        if(rep4==1){
                            printf("\t\\\\\\\__Reservation Memoire du graphe:__///\n\n");
                            printf("Veuillez entrer le nombre d'element du graphe: ");
                            scanf("%d",&rep2);
                            reservation_en_memoire (rep2, &gMatrice);                             // reservation memoire
                            printf("initialisation du graphe ... \n");
                            cree_graphe_vide (gMatrice);
                            //afficher_graphe(gMatrice);                                           // graphe vide
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 2){
                            printf("\t\\\\\\\__Affichage detaille du graphe:__///\n\n");
                            afficher_graphe(gMatrice);                                            // affichage graphe
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 3){
                            rep2=rep22=0;
                            printf("\t\\\\\\\__Ajouter Connection au graphe:__///\n\n");
                            printf("Pour arreter saisie, tapez: 9999\n\n");
                            while((rep2!=9999)&&(rep22!=9999)){
                                printf("Veuillez entrer le 1er Noeud: \t");
                                scanf("%d",&rep2);
                                if(rep2!=9999){
                                    printf("Veuillez entrer le 2eme Noeud:\t ");
                                    scanf("%d",&rep22);
                                    printf("\n");
                                    if(rep22!=9999){
                                        ajouter_connection (gMatrice,rep2,rep22);            // ajout connection
                                        printf("  /  Pour arreter saisie, tapez: 9999\n\n");
                                    }
                                }
                                else
                                    rep22=9999;
                            };
                            /*ajouter_connection (gMatrice,0,2);
                            ajouter_connection (gMatrice,0,3);
                            ajouter_connection (gMatrice,1,0);
                            ajouter_connection (gMatrice,2,3);
                            ajouter_connection (gMatrice,3,1);
                            ajouter_connection (gMatrice,3,2);*/
                            printf("\n\n##########################################################\n\n");
                        }
                        else if(rep4 == 4){
                            printf("\t\\\\\\\__Retirer Connection:__///\n\n");
                            printf("Veuillez entrer le 1er Noeud: \t");
                            scanf("%d",&rep2);
                            printf("Veuillez entrer le 2eme Noeud:\t ");
                            scanf("%d",&rep22);
                            retirer_connection (gMatrice,rep2,rep22);                     // retirer connection
                            printf("l'arc M[%d,%d] = 0\n\n",rep2,rep22);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 5){
                            printf("\t\\\\\\\__Verifier si est Adjacent:__///\n\n");
                            printf("Veuillez entrer le 1er Noeud:\t ");
                            scanf("%d",&rep2);
                            printf("Veuillez entrer le 2eme Noeud:\t ");
                            scanf("%d",&rep22);
                            printf("l'arc M[%d,%d] = %d\n\n",rep2,rep22,est_adjacent (gMatrice,rep2,rep22));                   // est adjacent
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 6){
                            printf("\t\\\\\\\__Recupere Sommet Adjacent:__///\n\n");
                            SID *adj= malloc(gMatrice->n * sizeof(int*));
                            int *ndadj= malloc(gMatrice->n * sizeof(int*));
                            printf("Veuillez entrer le Noeud Sommet:  ");
                            scanf("%d",&rep2);
                            recupere_sommet_adjacent (gMatrice, rep2, adj, ndadj);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 7){
                            printf("\t\\\\\\\__Copie Graphe dans Graphe2__///\n\n");
                            copie_graphe(gMatrice, &gMatrice_2);
                            printf("Affichage du graphe2 Copie:\t \n\n");
                            afficher_graphe(gMatrice_2);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 8){
                            printf("\t\\\\\\\__Lecture Graphe a partir du fichier__///\n\n");
                            reservation_en_memoire (2, &gMatrice);
                            cree_graphe_vide (gMatrice);
                            printf("Veuillez entrer le nom du fichier EX:/par defaut (fichierLu.txt): \n\n");
                            scanf("%s",nomFichier);
                            lire_graphe(nomFichier, gMatrice);
                            printf("affichage du fichier Lu \n\n");
                            afficher_graphe(gMatrice);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 9){
                            printf("\t\\\\\\\__Ecrire Graphe dans un fichier__///\n\n");
                            printf("Veuillez entrer le nom du fichier EX:/par defaut (fichierEcrit.txt): \n\n");
                            scanf("%s",nomFichier);
                            ecrit_graphe(nomFichier, gMatrice);
                            printf("Graphe insere dans le fichier %s \n\n",nomFichier);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 10){
                            printf("\t\\\\\\\__PARCOURS EN LARGEUR :__///\n\n");
                            printf("Veuillez entrer le Noeud de dpart:  ");
                            scanf("%d",&rep2);
                            parcours_en_largeur_Matrice (gMatrice, rep2);                                           /// Parcours en Profondeur ///
                            printf("\n\n##########################################################\n\n");
                        }
                        else if(rep4 == 11){
                            printf("\t\\\\\\\__PARCOURS EN PROFONDEUR :__///\n\n");
                            printf("Veuillez entrer le Noeud de dpart:  ");
                            scanf("%d",&rep2);
                            parcours_en_profondeur(gMatrice, rep2);                                              /// Parcours en Largeur ///
                            printf("\n\n##########################################################\n\n");
                        }
                        //
                        for(i=0;i<17;i++){
                            printf("%s",tab3[i]);                   // affichage du menu
                        }
                        printf("\nVotre Choix : ");
                        scanf("%d",&rep4);
                        printf("\n\n");

                    }while (rep4 !=12);
                }
            }
            else if(rep3==2){                                                   /// Representation par liste d'ajacent ///
                system("cls");
                printf("\n\n\t\\\\\\\__VOUS ETES DANS GRAPHE LISTE__///\n\n");
                for(i=0;i<17;i++){
                    printf("%s",tab3[i]);                   // affichage du menu
                }
                printf("\nVotre Choix : ");                // choix
                scanf("%d",&rep1);
                printf("\n\n");

                if(rep1 != 12){
                rep4=rep1;
                    do{
                        if(rep4==1){
                            printf("\t\\\\\\\__Reservation Memoire du graphe:__///\n\n");
                            printf("Veuillez entrer le nombre d'element du graphe: ");
                            scanf("%d",&rep2);
                            reservation_en_memoire_Liste(rep2, &gListe);                             // reservation memoire
                            printf("initialisation du graphe ... \n\n");
                            cree_graphe_vide_Liste (gListe);
                            //afficher_graphe(gListe);                                           // graphe vide
                            printf("##########################################################\n\n");
                        }
                         else if(rep4 == 2){
                            printf("\t\\\\\\\__Affichage detaille du graphe:__///\n\n");
                            afficher_graphe_Liste(gListe);                                            // affichage graphe
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 3){
                            rep2=rep22=0;
                            printf("\t\\\\\\\__Ajouter Connection au graphe:__///\n\n");
                            printf("Pour arreter saisie, tapez: 9999\n\n");
                            while((rep2!=9999)&&(rep22!=9999)){
                                printf("Veuillez entrer le 1er Noeud: \t");
                                scanf("%d",&rep2);
                                if(rep2!=9999){
                                    printf("Veuillez entrer le 2eme Noeud:\t ");
                                    scanf("%d",&rep22);
                                    printf("\n");
                                    if(rep22!=9999){
                                        ajouter_connection_Liste (gListe,rep2,rep22);            // ajout connection
                                        printf("  /  Pour arreter saisie, tapez: 9999\n\n");
                                    }
                                }
                                else
                                    rep22=9999;
                            };
                            /*ajouter_connection_Liste(gListe,0,2);
                            ajouter_connection_Liste(gListe,0,3);
                            ajouter_connection_Liste(gListe,0,4);
                            ajouter_connection_Liste(gListe,1,0);
                            ajouter_connection_Liste(gListe,3,0);
                            ajouter_connection_Liste(gListe,2,3);
                            ajouter_connection_Liste(gListe,3,1);
                            ajouter_connection_Liste(gListe,3,2);*/
                            printf("\n\n##########################################################\n\n");
                        }
                        else if(rep4 == 4){
                            printf("\t\\\\\\\__Retirer Connection:__///\n\n");
                            printf("Veuillez entrer le 1er Noeud: \t");
                            scanf("%d",&rep2);
                            printf("Veuillez entrer le 2eme Noeud:\t ");
                            scanf("%d",&rep22);
                            retirer_connection_Liste(gListe,rep2,rep22);                     // retirer connection
                            printf("l'arc (%d , %d) = 0\n\n",rep2,rep22);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 5){
                            printf("\t\\\\\\\__Verifier si est Adjacent:__///\n\n");
                            printf("Veuillez entrer le 1er Noeud:\t ");
                            scanf("%d",&rep2);
                            printf("Veuillez entrer le 2eme Noeud:\t ");
                            scanf("%d",&rep22);
                            printf("l'arc (%d , %d) = %d\n\n",rep2,rep22,est_adjacent_Liste (gListe, rep2, rep22));                   // est adjacent
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 6){
                            printf("\t\\\\\\\__Recupere Sommet Adjacent:__///\n\n");
                            SID_2 *adj_2[]= {0};//= malloc(gListe->n * sizeof(MAILLON*));
                            int *ndadj_2[]= {0};//= malloc(gListe->n * sizeof(MAILLON*));
                            printf("Veuillez entrer le Noeud Sommet:  ");
                            scanf("%d",&rep2);
                            recupere_sommet_adjacent_Liste (gListe, rep2, adj_2, ndadj_2);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 7){
                            printf("\t\\\\\\\__Copie Graphe dans Graphe2__///\n\n");
                            copie_graphe_Liste(gListe, &gListe_2);
                            printf("Affichage du graphe2 Copie:\t \n\n");
                            afficher_graphe_Liste(gListe_2);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 8){
                            printf("\t\\\\\\\__Lecture Graphe a partir du fichier__///\n\n");
                            reservation_en_memoire_Liste (2, &gListe);
                            cree_graphe_vide_Liste (gListe);
                            printf("Veuillez entrer le nom du fichier EX:/par defaut (fichierLu.txt): \n\n");
                            scanf("%s",nomFichier);
                            lire_graphe_Liste (nomFichier, gListe);
                            printf("\naffichage du fichier Lu \n\n");
                            afficher_graphe_Liste(gListe);
                            printf("##########################################################\n\n");
                        }
                         else if(rep4 == 9){
                            printf("\t\\\\\\\__Ecrire Graphe dans un fichier__///\n\n");
                            printf("Veuillez entrer le nom du fichier EX:/par defaut (fichierEcrit.txt): \n\n");
                            scanf("%s",nomFichier);
                            ecrit_graphe_Liste (nomFichier, gListe);
                            printf("Graphe insere dans le fichier %s \n\n",nomFichier);
                            printf("##########################################################\n\n");
                        }
                        else if(rep4 == 10){
                            printf("\t\\\\\\\__PARCOURS EN LARGEUR :__///\n\n");
                            printf("Veuillez entrer le Noeud de dpart:  ");
                            scanf("%d",&rep2);
                            parcours_en_largeur_Liste(gListe, rep2);                                           /// Parcours en Profondeur ///
                            printf("\n\n##########################################################\n\n");
                        }
                        else if(rep4 == 11){
                            printf("\t\\\\\\\__PARCOURS EN PROFONDEUR :__///\n\n");
                            printf("Veuillez entrer le Noeud de dpart:  ");
                            scanf("%d",&rep2);
                            parcours_en_profondeur_Liste(gListe, rep2);                                              /// Parcours en Largeur ///
                            printf("\n\n##########################################################\n\n");
                        }
                        //
                        for(i=0;i<17;i++){
                            printf("%s",tab3[i]);                   // affichage du menu
                        }
                        printf("\nVotre Choix : ");
                        scanf("%d",&rep4);
                        printf("\n\n");

                    }while (rep4 !=12);
                }
            }

    //printf("\n\n");
            system("cls");
            printf("\t\\\\\\\__VOUS ETES DANS LE MENU PRINCIPAL__///\n\n");
            for(i=0;i<21;i++){
                printf("%s",tab2[i]);                   // affichage du menu
            }
            printf("\nVotre Choix : ");
            scanf("%d",&rep3);

        }while (rep3 !=3);
    }
   printf("\n\n\t\\\\\\\__Vous quittez deja ? ok Bye Bye ...__///\n\n");

    return 0;
}
