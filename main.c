#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>



//***********************  les structures ************************//

typedef struct Programme {
    int Taille;
    char Nom[50];
    struct Programme* prog_suiv;
}Programme;

typedef struct Pages {
    int adresse;
    struct Pages * page_suiv;
    Programme * ProgMem;
}Page;



//******************************* Prototypes functions **********************//


Programme *creer_liste_programme(int Taille, char Nom[50]);
Programme *ajouter_programme(Programme *Prec, Programme *ProgrammeAjouter);
Page *initilaiser_page(Page * Prec,int adresse);
void afficher_programme(Programme *s);
void afficher_page(Page *s);
void SupprimerProg(Programme *s,char *nom);
int ViderPage(Page * s,char *nom);
void AfficherPageOccuper(Page *s);
void RechercherProg(Page*Debut,char nom[50]);
void afficher_memoire(Page * Debut);
int Taille_Pages(int a);
int trouver_prog(Programme *s, char *nom);
void color(int t,int f);


//*************************** Main *******************************//


int main(void)
{
    system("cls");
    system("COLOR 1E");
    system("COLOR 1e");
    system("cls");

    int choix,TailleProgramme;
    char NomProgramme[50];
    Programme * PrecedentProg = malloc(sizeof(Programme));
    Programme * ProgAjouter = malloc(sizeof(Programme));
    Programme * DebutProg = malloc(sizeof(Programme));
    PrecedentProg = NULL;
    int adresse;
    Page * Prec, * DebutPage;
    Prec = malloc(sizeof(Page));
    DebutPage = malloc(sizeof(Page));
    DebutPage = initilaiser_page(NULL,1);
    Prec = DebutPage;
    for(adresse=2; adresse <=25; adresse++) {
        Prec = initilaiser_page(Prec,adresse);
    }
    int espacevide_memoire = 2500;
        printf("           **************************************************\n");
        printf("           ******        Mini-projet ASE               ******\n");
        printf("           ******                                      ******\n");
        printf("           ***      Gestion de memoire par pagination     ***\n");
        printf("           **************************************************\n");
        printf("           *****                                        *****\n");
        printf("           *****   Encadre par :                        *****\n");
        printf("           *****      * Mme.TOUHAMI OUAZZANI Khadija    *****\n");
        printf("           *****                                        *****\n");
        printf("           *****   Realise par :                        *****\n");
        printf("           *****      * AHNICH Nouhayla                 *****\n");
        printf("           *****      * EL KASMI Soukaina               *****\n");
        printf("           *****      * FAKIHI Mostapha                 *****\n");
        printf("           *****      * FELLAK Fatima zehrae            *****\n");
        printf("           *****      * KHATIB Firdaouss                *****\n");
        printf("           *****      * LAAROUSSI Ikram                 *****\n");
        printf("           **************************************************\n\n\n");
        printf("\t\t\t   *** BIENVENUE ***  ");
        printf("\n\t\t       \n\n");

    while (choix != 8) {



        printf("      ษอออออออออออออออออออออออ MENU GENERALE ออออออออออออออออออออออออออออออป\n");
        printf("      บ   ---------------------------------------------------------------  บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 1 | Charge un nouveau programme dans la MC                 ) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 2 | Afficher la liste des pages libres en MC               ) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 3 | Afficher tous les programmes en memoire                ) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 4 | Afficher la liste des pages et la taille d'un programme) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 5 | Afficher la liste des pages pour tous les programmes   ) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 6 | Supprimer un programme                                 ) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 7 | Afficher l'etat de la Memoire                          ) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ  (  | 8 | Quitter                                                ) บ\n");
        printf("      บ                                                                    บ\n");
        printf("      บ   -------------------------------------------------------------    บ\n");
        printf("      ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

          printf("\n\tDonnez votre choix svp: \t");
          scanf("%d", &choix);
        if (choix == 1) {


            printf("\n\tDonnez le nom du programme :\t");
            scanf("%s",&NomProgramme);
            printf("\n\tDonnez la taille du programme :\t");
            scanf("%d",&TailleProgramme);
            if (TailleProgramme<=espacevide_memoire){
                int x = trouver_prog(DebutProg, NomProgramme);
                    if (x==0){
                        Page * TempPage = malloc(sizeof(Page));
                        TempPage = DebutPage;
                        int NbrPages = Taille_Pages(TailleProgramme);
                        espacevide_memoire= espacevide_memoire-NbrPages*100;
                        ProgAjouter = creer_liste_programme(TailleProgramme,NomProgramme);
                        ajouter_programme(PrecedentProg,ProgAjouter);
                        if(PrecedentProg==NULL){
                            DebutProg= ProgAjouter;
                        }
                        PrecedentProg = ProgAjouter;
                        while(NbrPages!=0)
                        {
                            if (TempPage->ProgMem==NULL){
                                TempPage->ProgMem = PrecedentProg;
                                NbrPages = NbrPages-1;
                            }
                            TempPage=TempPage->page_suiv;
                        }
                        printf("\n\n\tProgramme ajoute ! \n\n\n");
                    }
                    else{
                        printf("\tCe Programme deja existe\n\n");
                    }
            }


            else{
                printf("\n\n\tEspace Insuffisant.\n\n");

            }
        }
         else if(choix ==2){
            printf("\n");
            afficher_page(DebutPage);
        }
        else if(choix ==3){
            printf("\n\n\tVoila la liste des programmes en memoire : \n\n");
            afficher_programme(DebutProg);
            printf("\n\n");
        }
        else if(choix ==4){
            printf("\n\n\tDonnez le Nom du programme que vous voulez afficher :    ");
            scanf("%s",NomProgramme);
            int test = trouver_prog(DebutProg, NomProgramme);
            if(test==1){
                printf("\n\t--->le programme occupe les pages suivante  :\n\n");
            }
            RechercherProg(DebutPage,NomProgramme);
        }
        else if(choix ==5){
            AfficherPageOccuper(DebutPage);
        }

        else if(choix ==6){
            printf("\n\tDonnez le nom du programme que vous voulez supprimer:\t");
            scanf("%s",NomProgramme);
            int test = trouver_prog(DebutProg, NomProgramme);
            if (test==1)
            {
                        Programme * tmp;
                        int x=0;
                        if (strcmp(DebutProg->Nom,NomProgramme)==0)
                        {
                            tmp =DebutProg->prog_suiv;
                            x=1;
                        }
                        TailleProgramme = ViderPage(DebutPage, NomProgramme);
                        SupprimerProg(DebutProg, NomProgramme);
                        espacevide_memoire=espacevide_memoire+Taille_Pages(TailleProgramme)*100;
                        if(x==1)
                        {
                            DebutProg = tmp;
                        }
            }
            else{
                         printf("\n\n\tProgramme n'existe pas!!\n\n\n");
                }

        }


        else if(choix ==7){
            printf("\n");
            color(15, 1);
            afficher_memoire(DebutPage);
            printf("\n\tL'espace qui reste :  |%d| pages \n\n",Taille_Pages(espacevide_memoire));
            color(14, 1);
        }

        else if(choix==8){
            printf("\n\tMerci, A la prochaine !!");
        }
        else
        {
            printf("\n\tVerifier votre choix svp! \n\n");
        }
    }
}


//************************* Functions *************************************//
int Taille_Pages(int size){
    int nbr_page;
    nbr_page = size/100;
    if(size%100!=0){
        nbr_page+=1;
    }
    return nbr_page;
}


//****************Creation de la liste des  programmes***********************/

Programme *creer_liste_programme(int Taille, char Nom[50]) {

    Programme *liste = malloc(sizeof(Programme));

    liste->Taille = Taille;

    strcpy(liste->Nom, Nom);

    liste->prog_suiv = NULL;

    return liste;
}

//**********************Ajout d'un programme**********************//

Programme *ajouter_programme(Programme *Prec, Programme *ProgrammeAjouter) {
    if(Prec!=NULL){
        Prec->prog_suiv = ProgrammeAjouter;
    }
    return ProgrammeAjouter;
}

//***********************Initier les Pages***********************//

Page *initilaiser_page(Page * Prec,int adresse){
    Page * PageLibre = malloc(sizeof(Page));
    PageLibre->adresse = adresse;
    PageLibre->page_suiv = NULL;
    PageLibre->ProgMem= NULL;
    if(Prec!=NULL){
        Prec->page_suiv = PageLibre;
    }
    return PageLibre;
}

//***************Affichage des Programmes*****************//

void afficher_programme(Programme *s) {
    Programme *tmp = s;
    while (tmp != NULL) {
        printf("\t%s\t\t", tmp->Nom);

        tmp = tmp->prog_suiv;
    }
    printf("\n");
}
//***************Affichage des Pages Libres dans la memoire **************

void afficher_page(Page *s) {
    int i=1;
    Page *tmp =s;
    printf("\t-->Liste des pages vide\n\n");
    printf("[");
    while (i<=25) {

        if(tmp->ProgMem==NULL){

            printf(" |%d| ,  ", tmp->adresse);

        }
        tmp = tmp->page_suiv;
        i=i+1;

    }
    printf("]");
    printf("\n\n");
}

//***************color**************************//

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}

//******************Supprimer ******************//

void SupprimerProg(Programme *s,char *nom){
    Programme *tmp = s;
    Programme *tmp2 = NULL;

    if((strcmp(nom, s->Nom) == 0)){
        tmp = s;
        s = s->prog_suiv;
        free(tmp);
    }
    else {
        while ((strcmp(tmp->Nom, nom)!=0)) {

            tmp2=tmp;
            tmp = tmp->prog_suiv;
        }
        if((strcmp(tmp->Nom, nom)==0)) {
            tmp2->prog_suiv = tmp->prog_suiv;
            free(tmp);
        }

        //tmp = NULL;
    }
    printf("\tLe programme est supprime.\n\n");
}
//*******************Vider page***********************

int ViderPage(Page * s,char *nom){
    int i=1;
    Page * tmp = s;
    int taille = 0;
    while (i<=25) {
        if((tmp->ProgMem!=NULL) && (strcmp(tmp->ProgMem->Nom, nom)==0)){
            taille=tmp->ProgMem->Taille;
            tmp->ProgMem=NULL;
        }
        tmp = tmp->page_suiv;
        i=i+1;
    }
    return taille;
}
//*****************affichage des pages occupees************//

void AfficherPageOccuper(Page *s) {
    int i=1;
    Page *tmp = s;
    printf("\n\n\tles pages occupees sont:\n\n");
    while (i<=25) {
        if(tmp->ProgMem!=NULL){
            printf("\t%d", tmp->adresse);
            printf(" -----> %s\t\n",tmp->ProgMem->Nom);
        }
        tmp = tmp->page_suiv;
        i=i+1;
    }
    printf("\n");
}
//****************** Recherche Par Page***********//

void RechercherProg(Page*Debut,char nom[20]){
    int i=1;
    int x=0;
    Page * tmp=Debut;
    while (i<=25) {
        if((tmp->ProgMem!=NULL) && (strcmp(tmp->ProgMem->Nom, nom)==0)){
            printf(" \tpage %d\t",tmp->adresse);
            x=tmp->ProgMem->Taille;
        }
        tmp = tmp->page_suiv;
        i=i+1;
    }
    if (x==0){
        printf("\tAucune page de la memoire");
    }
    else{
        printf("\n\n\n\tEt sa taille est    %d",x);
    }
    printf("\n\n\n");

}
//****************** Affichage de la memoire**************************************//
void afficher_memoire(Page * Debut){
        int i,j;
        Page * tmp = Debut;

    printf("        ษอออออออออออออออMemoireอออออออออออป\n");
    printf("        บ                                 บ\n");
    printf("        บ                                 บ\n");
    for (i=1 ; i<=25; i++)
            {
                    if (tmp->ProgMem!=NULL)
                    {
                       printf("        บ                                 บ\n");
                       printf("    \t\tpage %d\t %s\n",i,tmp->ProgMem->Nom);
                       printf("        บ=================================บ \n");

                    }
                    else {

                    printf("        บ                                 บ\n");
                    printf("      \t\tpage\t %d\n   ",i);
                    printf("     บ=================================บ \n");

                   }
                   tmp=tmp->page_suiv;
            }

    printf("        บ                                 บ\n");
    printf("        ศอออออออออออออออออออออออออออออออออผ\n");
}
//************** Trouver un programme************//
int trouver_prog(Programme *s, char *nom) {
    int x=0;
    Programme *tmp = s;
    while (tmp !=NULL) {
        if(strcmp(tmp->Nom, nom)==0){
            x=1;
        }
        tmp = tmp->prog_suiv;
    }
    return x;
}
