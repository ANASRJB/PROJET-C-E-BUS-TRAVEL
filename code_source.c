#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 100
 typedef struct {
    char Nom_complet[MAX_LENGTH ];
    int numtel;
    char matricule[MAX_LENGTH ];
    char adresse_mail[MAX_LENGTH ];
}VOYAGEUR;
typedef struct {
    char nom[MAX_LENGTH ];
    long numtelf;
    int numbus;
}conducteur;
typedef struct {
    char etat[MAX_LENGTH ];
    char ligne[MAX_LENGTH ];
    int  diponibilite;
    int num;
    int nbplaces;
    conducteur chauff;
}BUS;
typedef struct {
    char destination[MAX_LENGTH ];
    char date[MAX_LENGTH ];
    char mail[MAX_LENGTH ];
}Reservation;
typedef struct{
    VOYAGEUR val;
    struct noeud*suiv;
}noeud;
typedef struct{
    noeud *tete;
}liste;

//**************FONCTIONS********************
void CREATIONCOMPTE(VOYAGEUR *voy){
    printf("\n********************************************************************\n");
    printf("************************BIENVENUE**********************************\n");
    printf("Veuillez saisir votre nom complet:");
    scanf("%s",voy->Nom_complet);
    printf("Veuillez saisir votre numero de telephone:");
    scanf("%d", &voy->numtel);
    printf("Veuillez saisir votre matricule:");
    scanf("%s",voy->matricule);
    printf("Veuillez saisir votre adresse mail:");
    scanf("%s",voy->adresse_mail);
}
void ajoutercond(conducteur *cond,int x){
    printf("Saisir le nom de conducteur:");
    scanf("%s",cond->nom);
    printf("Saisir le numero de telephone du conducteur:");
    scanf("%ld",&cond->numtelf);
    cond->numbus=x;
}
void AJOUTERBUS(BUS *bus){
    printf("Donner l etat du bus:");
    scanf("%s",bus->etat);
    printf("Donner la ligne:");
    scanf("%s",bus->ligne);
    printf("Donner la disponibilite:");
    scanf("%d",&bus->diponibilite);
    printf("Donner le numero:");
    scanf("%d",&bus->num);
    printf("Donner le nombre de places:");
    scanf("%d",&bus->nbplaces);
    ajoutercond(&bus->chauff, bus->num);
}
void AFFICHERDETAILS(BUS bus){
    printf("l'état du bus est:%s\n",bus.etat),
    printf("le ligne est:%s\n",bus.ligne);
    if(bus.diponibilite==1){
        printf("le bus est disponible\n");
    }else{printf("le bus n'est pas disponible\n");}
    printf("le numero du bus est:%d\n",bus.num);
    printf("le nombre de places disponibles est:%d\n",bus.nbplaces);
}
void append(liste *L,VOYAGEUR voy){
    noeud *nvelement = malloc(sizeof(*nvelement));
    if(L==NULL || nvelement==NULL ){
        exit(EXIT_FAILURE);
    }else{
        nvelement->val=voy;
        nvelement->suiv=L->tete;
        L->tete=nvelement;
    }
    free(nvelement);
}
int exist(liste *L,const char *s){
    noeud *aux=L->tete;;
    int t=0;
    while(aux!=NULL && t==0){
        if(strcmp(aux->val.adresse_mail, s) == 0){
            t=1;
            break;
        }else{aux=aux->suiv;}
    }
    return t;

}

void RESERVER(Reservation *res){
    printf("Resaisir votre E-mail:");
    scanf("%s",res->mail);
    printf("Quelle est votre destination?");
    scanf("%s",res->destination);
    printf("Saisir la date de voyage:");
    scanf("%s",res->date);
}
void CONDUCTEURDET(conducteur cond){
    printf("Le nom du conducteur est:%s\n",cond.nom);
    printf("Le numero du telephone du conducteur est:%ld\n", cond.numtelf);
    printf("le bus que ce conducteur conduit est le bus numero:%d\n",cond.numbus);
}
//*******DECLARATION DES FONCTION***********//
void CREATIONCOMPTE(VOYAGEUR *voy);
void AJOUTERBUS(BUS *bus);
void AFFICHERDETAILS(BUS bus);
void append(liste *L,VOYAGEUR voy);
int  exist(liste *L,const char *s);
void RESERVER(Reservation *res);
void CONDUCTEURDET(conducteur cond);
void main(){
    liste *v;
    v = malloc(sizeof(liste));
    v->tete = NULL;
    BUS bus[50];
    Reservation res[100];
    int choice;
    int i=0;
    int j=0;
    do{
        printf("\n********************************************************************\n");
        printf("\n*****************E-BUS-Travel MENU PRINCIPALE***********************\n");
        printf("\n1.Creer un compte\n");
        printf("2.Creer une nouvelle reservation\n");
        printf("3.Ajouter bus\n");
        printf("4.Afficher details des bus\n");
        printf("5.Afficher les details d'une reservation\n");
        printf("6.Modifier les details d'une reservation\n");
        printf("7.Afficher les details des conducteurs\n");
        printf("8.Quitter\n");
        printf("\n********************************************************************\n");
        printf("Choix :" );
        scanf("%d",&choice);
        switch(choice){
          case 1:
                 {
                   VOYAGEUR voy;
                   CREATIONCOMPTE(&voy);
                   append(v,voy);
                   break;
                   }
          case 2:
                 {if(i<100){
                    Reservation R;
                    char s[MAX_LENGTH];
                    printf("Saisir votre E-mail:");
                    scanf("%s",s);
                    if(exist(v,s)){
                    RESERVER(&R);
                    res[i]=R;
                    i++;
                    printf("Bonne voyage\n");}

                    else{
                        printf("VOUS DEVEZ CREER UN COMPTE PUIS RESERVER MERCI!!!\n");
                        VOYAGEUR voy;
                        CREATIONCOMPTE(&voy);
                        append(v,voy);
                        RESERVER(&R);
                        printf("Bonne voyage\n");
                        res[i]=R;
                        i++;

                    }
                 }else{printf("COMPLET");}
                 break;
                 }

          case 3:
                 {if(j<100){
                    BUS b;
                    AJOUTERBUS(&b);
                    b.diponibilite=1;
                    bus[j]=b;
                    j++;}
                    break;
                 }
          case 4:
                 {  int n;
                    int k=0;
                    int t=0;
                    printf("Donner le numero de bus:");
                    scanf("%d",&n);
                    while(k<100 && t==0){
                    if(bus[k].num==n){
                         AFFICHERDETAILS(bus[k]);
                         t=1;
                    }else{k++;}
                 }if(t==0){
                    printf("Le bus est introuvable");
                 }
                 break;
                 }
          case 5:
                 {  char s[MAX_LENGTH];
                    int k=0;
                    int t=0;
                    printf("Donner votre E-mail:");
                    scanf("%s",s);
                    while(k<100 && t==0){
                     if(strcmp(res[k].mail, s) == 0){
                        printf("La destination est: %s\n",res[k].destination);
                        printf("La date de voyage est: %s\n",res[k].date);
                        printf("Votre E-mail est: %s\n",res[k].mail);
                         t=1;
                     }else{k++;}
                    }if(t==0){
                    printf("Reservation introuvable\n");
                 }
                 break;
                 }
          case 6:
                 {  char s[MAX_LENGTH];
                    int k=0;
                    int t=0;
                    printf("Donner votre E-mail:");
                    scanf("%s",s);
                    while(k<100 && t==0){
                    if(res[k].mail==s){
                        printf("Entrer la nouvelle destination:");
                        scanf("%s",res[k].destination);
                        printf("Saisir la nouvelle date de voyage:");
                        scanf("%s",res[k].date);
                        t=1;
                    }else{k++;}
                    }if(t==0){
                    printf("Reservation introuvable");
                 }
                 break;
                 }
          case 7:
                 {  int n;
                    int k=0;
                    int t=0;
                    printf("Donner le numero de bus:");
                    scanf("%d",&n);
                    while(k<100 && t==0){
                    if(bus[k].num==n){
                         CONDUCTEURDET(bus[k].chauff);
                         t=1;
                    }else{k++;}
                 }if(t==0){
                    printf("Conducteur est introuvable");
                 }
                 break;
                 }
          case 8:
                 { printf("Au revoir !\n");
                   printf("******************************************************\n");
                   exit(0);
                 }
          default:
                 {printf("Choix invalide!Veuillez ressayer.\n");
                 break;
                 }
                 }

    }while(choice!=8);


//return 0;
}