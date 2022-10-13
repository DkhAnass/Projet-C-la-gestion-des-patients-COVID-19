#include "header.h"

listepatient add(patient *d,listepatient l) {
    fflush(stdin);
    printf("\n Le nom complet : \t");
    gets(d->nom_complet);
    fflush(stdin);
    printf("\n L'etat du patient (Normal,Critique,Besoin aide respiratoire): \t");
    gets(d->etat);
    fflush(stdin);
    printf("\n L'age: \t");
    scanf("%d",&(d->age));
    fflush(stdin);
    printf("\n Ville: \t");
    gets(d->ville);
    fflush(stdin);
    printf("\n Type de chambre: \t");
    gets(d->typechambre);
    fflush(stdin);
    printf("\n CIN: \t");
    gets(d->CIN);
    fflush(stdin);
    printf("\n Num de Chambre: \t");
    scanf("%d",&(d->chambre));
    fflush(stdin);
    printf("\n Occupation de lit (0 si non, 1 si oui):  \t");
    scanf("%d",&(d->occupelit));
    fflush(stdin);
    printf("\n Le jour d'infection (Lundi,Mardi...,Dimanche):\t");
    gets(d->jourinfection);
    fflush(stdin);
    noeud* nouveau = Malloc(noeud);
    nouveau->info=d;
    noeud* p;    
    if (l==NULL){
                nouveau->next= NULL;
                l=nouveau;
                return l;
            }
            p=l;
            while(p->next!=NULL)
            {p=p->next;}
            p->next=nouveau;
            nouveau->next=NULL;
return l;
}

listepatient supprimer(patient *d,listepatient l) {
    fflush(stdin);
    printf("L'element a supprimer:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listepatient p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {
        l=p->next;
        free(p);
        return l;
    }
    while(p->next!=0)
    {
        if((strcmp(d->CIN,p->next->info->CIN)==0))
        {
            listepatient q=p->next;
            p->next=p->next->next;
            free(q);
            return l;
        }
        p=p->next;
    }
    return l;
}

void afficher(listepatient l){
if(l==NULL)
    {
        printf("la liste est vide\n");
    }
else {
      listepatient p;
      p=l;
      while(p)
        {
            printf("\nNom complet:%s   Age:%d   CIN:%s   Etat:%s   Num Chambre:%d   Type Chambre:%s   Ville:%s   Occupation de lit:%d   Jour d'infection:%s \n",p->info->nom_complet,p->info->age,p->info->CIN,p->info->etat,p->info->chambre,p->info->typechambre,p->info->ville,p->info->occupelit,p->info->jourinfection);
            p=p->next;
        }
    }        
}

void afficheretat(listepatient l){
int c;
char etat[50]="Normal";
char etat1[50]="Critique";
char etat2[50]="Besoin aide respiratoire";
if(l==NULL)
    {
        printf("la liste est vide\n");
    }
else {
      listepatient p;
      p=l;
      printf("\n L'etat desiree (1=Normal ,2=Critique ,3=Besoin aide respiratoire): \t");
      scanf("%d",&c);
      switch (c)
       {
       case 1: 
            while(p){
            if (strcmp(p->info->etat,etat)==0) {
            printf("\nNom complet:%s   Age:%d   CIN:%s   Num Chambre:%d   Type Chambre:%s   Ville:%s   Occupation de lit:%d   Jour d'infection:%s \n",p->info->nom_complet,p->info->age,p->info->CIN,p->info->chambre,p->info->typechambre,p->info->ville,p->info->occupelit,p->info->jourinfection);
            }
            p=p->next;
            }
           break;
        case 2:
         while(p){
         if (strcmp(p->info->etat,etat1)==0) {
            printf("\nNom complet:%s   Age:%d   CIN:%s   Num Chambre:%d   Type Chambre:%s   Ville:%s   Occupation de lit:%d   Jour d'infection:%s \n",p->info->nom_complet,p->info->age,p->info->CIN,p->info->chambre,p->info->typechambre,p->info->ville,p->info->occupelit,p->info->jourinfection);
            }
            p=p->next;
            }
            break;
        case 3: 
        while(p){
        if (strcmp(p->info->etat,etat2)==0) {
            printf("\nNom complet:%s   Age:%d   CIN:%s   Num Chambre:%d   Type Chambre:%s   Ville:%s   Occupation de lit:%d   Jour d'infection:%s \n",p->info->nom_complet,p->info->age,p->info->CIN,p->info->chambre,p->info->typechambre,p->info->ville,p->info->occupelit,p->info->jourinfection);
            }
            p=p->next;
            }
            break;
        default: printf("Ce choix n'existe pas.\n");   
        break;
       }
    }
}        

void modificationmenu(){
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t                     |      Menu de modification:     |                      \n");
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
    printf("\t\t/                Choisir l'information a modifier:                          /\n");
    printf("\t\t/                       Tapez 1 pour le nom complet :                       /\n");
    printf("\t\t/                       Tapez 2 pour l'Age:                                 /\n");
    printf("\t\t/                       Tapez 3 pour l'etat:                                /\n");
    printf("\t\t/                       Tapez 4 pour Num chambre:                           /\n");
    printf("\t\t/                       Tapez 5 pour Type chambre:                          /\n");
    printf("\t\t/                       Tapez 6 pour ville:                                 /\n");
    printf("\t\t/                       Tapez 7 pour Occupation de lit:                     /\n");
    printf("\t\t/                       Tapez 8 pour le jour d'infection:                   /\n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
}

listepatient modifier(patient *d,listepatient l){
    int a;
    patient *q=Malloc(patient);
    fflush(stdin);
    printf("L'element a modifier:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listepatient p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {  modificationmenu();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a){
      case 1: printf("La nouvelle donnee:");
            fflush(stdin);
            scanf("%s",q->nom_complet);
            strcpy(p->info->nom_complet,q->nom_complet);
            return l;
            break;
      case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->info->age=q->age;
              return l;
              break;
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->etat);
              strcpy(p->info->etat,q->etat);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->chambre));
              p->info->chambre=q->chambre;
              return l;
            break; 
        case 5: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->typechambre);
              strcpy(p->info->typechambre,q->typechambre);
              return l;
            break;             
        case 6: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->info->ville,q->ville);
              return l;
            break; 
        case 7: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->occupelit));
              p->info->occupelit=q->occupelit;
              return l;
              break;   
        case 8: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->jourinfection);
              strcpy(p->info->jourinfection,q->jourinfection);
              return l;
            break;             
        default: printf("Element n'exite pas.\n");
        break;
        }
    }   
    while(p->next!=0) {
        if((strcmp(d->CIN,p->next->info->CIN)==0)) {
            modificationmenu();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a) {
        case 1: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->nom_complet);
              strcpy(p->next->info->nom_complet,q->nom_complet);
              return l;
              break;
        case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->next->info->age=q->age;
              return l;
              break;
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->etat);
              strcpy(p->next->info->etat,q->etat);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->chambre));
              p->next->info->chambre=q->chambre;
              return l;
            break; 
        case 5: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->typechambre);
              strcpy(p->next->info->typechambre,q->typechambre);
              return l;
            break;             
        case 6: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->next->info->ville,q->ville);
              return l;
            break;
        case 7: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->occupelit));
              p->next->info->occupelit=q->occupelit;
              return l;
              break;
        case 8: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->jourinfection);
              strcpy(p->next->info->jourinfection,q->jourinfection);
              return l;
            break;            
        default: printf("Element n'exite pas.\n");
        break;
        }
        }
        p=p->next;
    }
    
    return l;     
}

void menu1() {
printf("\t\t                   |-----------------------------------------------|         \n");
printf("\t\t                   |                Gestion des patients:          |         \n");
printf("\t\t                   |-----------------------------------------------|         \n");
printf("\t\t/---------------------------------------------------------------------------/\n");
printf("\t\t/                     Tapez 1 pour l'insertion:                             /\n");
printf("\t\t/                     Tapez 2 pour l'affichage:                             /\n");
printf("\t\t/                     Tapez 3 pour la suppression:                          /\n");
printf("\t\t/                     tapez 4 pour Modifier:                                /\n");
printf("\t\t/                     tapez 5 pour le retour au menu principal:             /\n");
printf("\t\t/---------------------------------------------------------------------------/\n");
}
void menu2() {
printf("\t\t                   |-----------------------------------------------|         \n");
printf("\t\t                   |                Gestion des contacts:          |         \n");
printf("\t\t                   |-----------------------------------------------|         \n");
printf("\t\t/---------------------------------------------------------------------------/\n");
printf("\t\t/                     Tapez 1 pour l'insertion:                             /\n");
printf("\t\t/                     Tapez 2 pour l'affichage:                             /\n");
printf("\t\t/                     Tapez 3 pour la suppression:                          /\n");
printf("\t\t/                     tapez 4 pour Modifier:                                /\n");
printf("\t\t/                     tapez 5 pour le retour au menu principal:             /\n");
printf("\t\t/---------------------------------------------------------------------------/\n");
}
void menu(){ 
printf("\t\t                     |--------------------------------|                      \n");
printf("\t\t                     |         Menu principal:        |                      \n");
printf("\t\t                     |--------------------------------|                      \n");
printf("\t\t/---------------------------------------------------------------------------/\n");
printf("\t\t/                     Tapez 1 pour la gestion des patients:                 /\n");
printf("\t\t/                     Tapez 2 pour la gestion des contacts:                 /\n");
printf("\t\t/                     Tapez 3 pour la gestion des gueris:                   /\n");
printf("\t\t/                     tapez 4 pour la gestion des deces:                    /\n");
printf("\t\t/                     tapez 5 pour Quitter:                                 /\n");
printf("\t\t/---------------------------------------------------------------------------/\n");
}
int length(listepatient l){
    int len = 0;
    while(l){
        len++;
        l = l->next;
    }
    return len;

}

void writeListePatientToFile(listepatient l){    
    FILE * file;
    remove("ListePatients.data");
    file = fopen("ListePatients.data", "w");
    if(length(l)){
        while(l){
            fwrite(l->info,sizeof(patient),1,file);
            l = l->next;
        }
        fclose(file);
    }
    else{ printf("Auncun patient a sauvegarder.\n");
    }
    fclose(file);   
}

listepatient Chargerpatient(listepatient l){
    FILE *file = fopen("ListePatients.data", "r");
    if (file == NULL)
    {
        return l;
    }
    while (1)
    {
        patient *pat;
        pat = Malloc(patient);
        fread(pat, sizeof(patient), 1, file);
        if (feof(file))
            break;
        noeud* nouveau = Malloc(noeud);
        nouveau->info=pat;
        noeud* p;
        p=l;    
        if (p == NULL){
           nouveau->next = l;
           l = nouveau;
        }
        else{
            while (p->next != NULL)
                {
                    p = p->next;
                }
            nouveau->next = p->next;
            p->next = nouveau;
        }
    }
    fclose(file);
    return l;
}

void afficherparville(listepatient l, char choixville[30]){
    int j=0;
    int n,i,k;
    int o;
    listepatient p=l;
    n=length(l);
    ville T[n];
    while(p)
    {   
            strcpy(T[j].nomville,p->info->ville);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomville,T[i].nomville)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomville,T[k + 1].nomville);
            }
            n--;
         } else
            o++;
      }
   }
   listepatient q=l;  
   for (i = 0; i < n; i++) { 
       while(q){
            if (strcmp(q->info->ville,choixville)==0) {
            printf("\nNom complet:%s   Age:%d   CIN:%s   Etat:%s   Num Chambre:%d   Type Chambre:%s   Occupation de lit:%d   Jour d'infection:%s \n",q->info->nom_complet,q->info->age,q->info->CIN,q->info->etat,q->info->chambre,q->info->typechambre,q->info->occupelit,q->info->jourinfection);
            }
            else{
            }
            q=q->next;
            }
   }
}

float division(int A,int B)
{ 
	return A/(float)B;
}

void tauxoccuplit(listepatient l){
    char choixville[50];
    fflush(stdin);
    printf("Choisir la ville:");
    gets(choixville);
    int nblit;
    fflush(stdin);
    printf("Entrer le nombre de lit disponibles dans la ville:");
    scanf("%d",&nblit); 
    listepatient q=l;
    int occlit=0;
    float taux;
    while(q){
        if (strcmp(q->info->ville,choixville)==0 && q->info->occupelit==1) {
                occlit++;
                q=q->next; 
            }
        else{
             q=q->next; 
        }    
        }
    printf("Ville:%s \t Taux d'occupation de lit:%.2f%%\n",choixville,division(occlit,nblit)*100);
}

void nbcascritiqueparville(listepatient l){
    int j=0;
    int n,i,k;
    int o,m,h;
    listepatient p=l;
    n=length(l);
    int nbcas=0;
    ville T[n];
    listepatient q=l;
    while(p)
    {   
            strcpy(T[j].nomville,p->info->ville);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomville,T[i].nomville)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomville,T[k + 1].nomville);
            }
            n--;
         } else
            o++;
      }
   }   
    for (i = 0; i < n; i++){  
           nbcas=0;
           q=l;
           char etat1[50]="Critique";
           while (q){
               if (strcmp(q->info->ville,T[i].nomville)==0){
                   if (strcmp(q->info->etat,etat1)==0){ 
                   nbcas++;
                   }
                q=q->next;
               }
               else {
                       q=q->next;
                   }
               }
           printf("Ville: %s \t Nombre de cas critiques: %d\n",T[i].nomville,nbcas);
           }
}

void nbcasparville(listepatient l){
    int j=0;
    int n,i,k;
    int o,m,h;
    listepatient p=l;
    n=length(l);
    int nbcas=0;
    ville T[n];
    listepatient q=l;
    while(p)
    {   
            strcpy(T[j].nomville,p->info->ville);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomville,T[i].nomville)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomville,T[k + 1].nomville);
            }
            n--;
         } else
            o++;
      }
   }   
    for (i = 0; i < n; i++){  
           nbcas=0;
           q=l;
           while (q){
               if (strcmp(q->info->ville,T[i].nomville)==0){
                   nbcas++;
                   q=q->next;
               }
               else {
                       q=q->next;
                   }
               }
           printf("Ville: %s \t Nombre de cas: %d\n",T[i].nomville,nbcas);
           }
}

void menuaffichage(){
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t                     |         Menu d'affichage:      |                           \n");
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
    printf("\t\t/                    Choisir le critere d'affichage:                             /\n");
    printf("\t\t/             Tapez 1 pour afficher tous les patients :                          /\n");
    printf("\t\t/             Tapez 2 pour afficher selon l'etat:                                /\n");
    printf("\t\t/             Tapez 3 pour afficher selon la ville:                              /\n");
    printf("\t\t/             Taper 4 pour afficher le Nombre des cas par ville:                 /\n");
    printf("\t\t/             Taper 5 pour afficher le taux d'occupation des lit par ville:      /\n");
    printf("\t\t/             Taper 6 pour afficher le Nombre des cas critiques par ville:       /\n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
}

listecontactpatient ajoutercontact(contactpatient *d,listecontactpatient l){
    fflush(stdin);
    printf("\n Le nom complet : \t");
    gets(d->nom_complet);
    fflush(stdin);
    printf("\n L'age: \t");
    scanf("%d",&(d->age));
    fflush(stdin);
    printf("\n CIN: \t");
    gets(d->CIN);
    fflush(stdin);
    printf("\n Ville: \t");
    gets(d->ville);
    fflush(stdin);
    printf("\n Secteur: \t");
    gets(d->secteur);
    fflush(stdin);
    printf("\n Telephone (Chaine de caractere pour conserver le 0 au debut): \t");
    gets(d->tel);
    fflush(stdin);
    noeud1* nouveau = Malloc(noeud1);
    nouveau->info=d;
    noeud1* p;    
    if (l==NULL){
                nouveau->next= NULL;
                l=nouveau;
                return l;
            }
            p=l;
            while(p->next!=NULL)
            {p=p->next;}
            p->next=nouveau;
            nouveau->next=NULL;
return l;
}

listecontactpatient supprimercontact(contactpatient *d,listecontactpatient l){
    fflush(stdin);
    printf("L'element a supprimer:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listecontactpatient p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {
        l=p->next;
        free(p);
        return l;
    }
    while(p->next!=0)
    {
        if((strcmp(d->CIN,p->next->info->CIN)==0))
        {
            listecontactpatient q=p->next;
            p->next=p->next->next;
            free(q);
            return l;
        }
        p=p->next;
    }
    return l;
}

void affichercontact(listecontactpatient l){
if(l==NULL)
    {
        printf("la liste est vide\n");
    }
else {
      listecontactpatient p;
      p=l;
      while(p)
        {
            printf("\nNom complet:%s   Age:%d   CIN:%s  Ville:%s   Secteur:%s   Telephone:%s \n",p->info->nom_complet,p->info->age,p->info->CIN,p->info->ville,p->info->secteur,p->info->tel);
            p=p->next;
        }
    }        
}

void modificationmenucontact(){
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t                     |      Menu de modification:     |                      \n");
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
    printf("\t\t/                Choisir l'information a modifier:                          /\n");
    printf("\t\t/                       Tapez 1 pour le nom complet :                       /\n");
    printf("\t\t/                       Tapez 2 pour l'Age:                                 /\n");
    printf("\t\t/                       Tapez 3 pour Ville:                                 /\n");
    printf("\t\t/                       Tapez 4 pour Secteur:                               /\n");
    printf("\t\t/                       Tapez 5 pour Telephone:                             /\n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
}

listecontactpatient modifiercontact(contactpatient *d,listecontactpatient l){
    int a;
    contactpatient *q=Malloc(contactpatient);
    fflush(stdin);
    printf("L'element a modifier:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listecontactpatient p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {  modificationmenucontact();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a){
      case 1: printf("La nouvelle donnee:");
            fflush(stdin);
            scanf("%s",q->nom_complet);
            strcpy(p->info->nom_complet,q->nom_complet);
            return l;
            break;
      case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->info->age=q->age;
              return l;
              break;
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->info->ville,q->ville);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->secteur);
              strcpy(p->info->secteur,q->secteur);
              return l;
            break;             
        case 5:printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->tel);
              strcpy(p->info->tel,q->tel);
              return l;
            break; 
        }
    }   
    while(p->next!=0) {
        if((strcmp(d->CIN,p->next->info->CIN)==0)) {
            modificationmenucontact();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a) {
        case 1: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->nom_complet);
              strcpy(p->next->info->nom_complet,q->nom_complet);
              return l;
              break;
        case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->next->info->age=q->age;
              return l;
              break;    
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->next->info->ville,q->ville);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->secteur);
              strcpy(p->next->info->secteur,q->secteur);
              return l;
            break;             
        case 5:printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->tel);
              strcpy(p->next->info->tel,q->tel);
              return l;
            break; 
        }
        }
        p=p->next;
    }
    
    return l;     
}

int lengthcontact(listecontactpatient l){
    int len = 0;
    while(l){
        len++;
        l = l->next;
    }
    return len;
}

void writeListeContacttToFile(listecontactpatient l){    
    FILE * file;
    remove("Listecontactpatients.data");
    file = fopen("ListeContactpatients.data", "w");
    if(lengthcontact(l)){
        while(l){
            fwrite(l->info,sizeof(contactpatient),1,file);
            l = l->next;
        }
        fclose(file);
    }
    else{ printf("Auncun patient a sauvegarder.\n");
    }
    fclose(file);   
}

listecontactpatient Chargercontact(listecontactpatient l){
    FILE *file = fopen("Listecontactpatients.data", "r");
    if (file == NULL)
    {
        return l;
    }
    while (1)
    {
        contactpatient *pat;
        pat = Malloc(contactpatient);
        fread(pat, sizeof(contactpatient), 1, file);
        if (feof(file))
            break;
        noeud1* nouveau = Malloc(noeud1);
        nouveau->info=pat;
        noeud1* p;
        p=l;    
        if (p == NULL){
           nouveau->next = l;
           l = nouveau;
        }
        else{
            while (p->next != NULL)
                {
                    p = p->next;
                }
            nouveau->next = p->next;
            p->next = nouveau;
        }
    }
    fclose(file);
    return l;
}

void menuaffichagecontact(){
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t                     |         Menu d'affichage:      |                           \n");
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
    printf("\t\t/                    Choisir le critere d'affichage:                             /\n");
    printf("\t\t/             Tapez 1 pour afficher tous les contacts :                          /\n");
    printf("\t\t/             Tapez 2 pour afficher selon la ville:                              /\n");
    printf("\t\t/             Taper 3 pour afficher selon le secteur                             /\n");
    printf("\t\t/             Taper 4 pour afficher le nombre de contacts par ville:             /\n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
}

void affichercontactparville(listecontactpatient l, char choixville1[30]){
    int j=0;
    int n,i,k;
    int o;
    listecontactpatient p=l;
    n=lengthcontact(l);
    ville T[n];
    while(p)
    {   
            strcpy(T[j].nomville,p->info->ville);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomville,T[i].nomville)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomville,T[k + 1].nomville);
            }
            n--;
         } else
            o++;
      }
   }
   listecontactpatient q=l;
   for (i = 0; i < n; i++) { 
       while(q){
            if (strcmp(q->info->ville,choixville1)==0) {
             printf("\nNom complet:%s   Age:%d   CIN:%s  Secteur:%s   Telephone:%s \n",q->info->nom_complet,q->info->age,q->info->CIN,q->info->secteur,q->info->tel);
            }
            else{
            }
            q=q->next;
            }
   }
}

void affichercontactparsecteur(listecontactpatient l, char choixsecteur[30]){
    int j=0;
    int n,i,k;
    int o;
    listecontactpatient p=l;
    n=lengthcontact(l);
    secteur T[n];
    while(p)
    {   
            strcpy(T[j].nomsecteur,p->info->secteur);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomsecteur,T[i].nomsecteur)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomsecteur,T[k + 1].nomsecteur);
            }
            n--;
         } else
            o++;
      }
   }
   listecontactpatient q=l;  
   for (i = 0; i < n; i++) { 
       while(q){
            if (strcmp(q->info->secteur,choixsecteur)==0) {
             printf("\nNom complet:%s   Age:%d   CIN:%s  Ville:%s   Telephone:%s \n",q->info->nom_complet,q->info->age,q->info->CIN,q->info->ville,q->info->tel);
            }
            else{
            }
            q=q->next;
            }
   }
}

void nbcontactparville(listecontactpatient l){
    int j=0;
    int n,i,k;
    int o,m,h;
    listecontactpatient p=l;
    n=lengthcontact(l);
    int nbcont=0;
    ville T[n];
    listecontactpatient q=l;
    while(p)
    {   
            strcpy(T[j].nomville,p->info->ville);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomville,T[i].nomville)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomville,T[k + 1].nomville);
            }
            n--;
         } else
            o++;
      }
   }   
    for (i = 0; i < n; i++){  
           nbcont=0;
           q=l;
           while (q){
               if (strcmp(q->info->ville,T[i].nomville)==0){
                   nbcont++;
                   q=q->next;
               }
               else {
                       q=q->next;
                   }
               }
           printf("Ville: %s \t Nombre de contact: %d\n",T[i].nomville,nbcont);
           }
}

listepatientgueri ajoutergueri(patientgueri *d,listepatientgueri l){ 
    fflush(stdin);
    printf("\n Le nom complet : \t");
    gets(d->nom_complet);
    fflush(stdin);
    printf("\n L'age: \t");
    scanf("%d",&(d->age));
    fflush(stdin);
    printf("\n CIN: \t");
    gets(d->CIN);
    fflush(stdin);
    printf("\n Ville: \t");
    gets(d->ville);
    fflush(stdin);
    printf("\n Secteur: \t");
    gets(d->secteur);
    fflush(stdin);
    printf("\n Telephone (Chaine de caractere pour conserver le 0 au debut): \t");
    gets(d->tel);
    fflush(stdin);
    printf("\n Jour de guerison(Lundi,Mardi,...,Dimanche): \t");
    gets(d->jourgueri);
    fflush(stdin);
    noeud2* nouveau = Malloc(noeud2);
    nouveau->info=d;
    noeud2* p;    
    if (l==NULL){
                nouveau->next= NULL;
                l=nouveau;
                return l;
            }
            p=l;
            while(p->next!=NULL)
            {p=p->next;}
            p->next=nouveau;
            nouveau->next=NULL;
return l;
}

listepatientgueri supprimergueri(patientgueri *d,listepatientgueri l){
    fflush(stdin);
    printf("L'element a supprimer:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listepatientgueri p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {
        l=p->next;
        free(p);
        return l;
    }
    while(p->next!=0)
    {
        if((strcmp(d->CIN,p->next->info->CIN)==0))
        {
            listepatientgueri q=p->next;
            p->next=p->next->next;
            free(q);
            return l;
        }
        p=p->next;
    }
    return l;
}

void affichergueri(listepatientgueri l){
if(l==NULL)
    {
        printf("la liste est vide\n");
    }
else {
      listepatientgueri p;
      p=l;
      while(p)
        {
            printf("\nNom complet:%s   Age:%d   CIN:%s  Ville:%s   Secteur:%s   Telephone:%s   Jour de guerison:%s \n",p->info->nom_complet,p->info->age,p->info->CIN,p->info->ville,p->info->secteur,p->info->tel,p->info->jourgueri);
            p=p->next;
        }
    }        
}

void modificationmenugueri(){
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t                     |      Menu de modification:     |                      \n");
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
    printf("\t\t/                Choisir l'information a modifier:                          /\n");
    printf("\t\t/                       Tapez 1 pour le nom complet :                       /\n");
    printf("\t\t/                       Tapez 2 pour l'Age:                                 /\n");
    printf("\t\t/                       Tapez 3 pour Ville:                                 /\n");
    printf("\t\t/                       Tapez 4 pour Secteur:                               /\n");
    printf("\t\t/                       Tapez 5 pour Telephone:                             /\n");
    printf("\t\t/                       Tapez 6 pour jour de guerison:                      /\n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
}

listepatientgueri modifiergueri(patientgueri *d,listepatientgueri l){
    int a;
    patientgueri *q=Malloc(patientgueri);
    fflush(stdin);
    printf("L'element a modifier:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listepatientgueri p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {  modificationmenugueri();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a){
      case 1: printf("La nouvelle donnee:");
            fflush(stdin);
            scanf("%s",q->nom_complet);
            strcpy(p->info->nom_complet,q->nom_complet);
            return l;
            break;
      case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->info->age=q->age;
              return l;
              break;
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->info->ville,q->ville);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->secteur);
              strcpy(p->info->secteur,q->secteur);
              return l;
            break;             
        case 5:printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->tel);
              strcpy(p->info->tel,q->tel);
              return l;
            break;
        case 6: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->jourgueri);
              strcpy(p->info->jourgueri,q->jourgueri);
              return l;
            break;             
        default: printf("Element n'exite pas.\n");
        break;     
        }
    }   
    while(p->next!=0) {
        if((strcmp(d->CIN,p->next->info->CIN)==0)) {
            modificationmenugueri();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a) {
        case 1: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->nom_complet);
              strcpy(p->next->info->nom_complet,q->nom_complet);
              return l;
              break;
        case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->next->info->age=q->age;
              return l;
              break;    
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->next->info->ville,q->ville);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->secteur);
              strcpy(p->next->info->secteur,q->secteur);
              return l;
            break;             
        case 5:printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->tel);
              strcpy(p->next->info->tel,q->tel);
              return l;
            break; 
        case 6: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->jourgueri);
              strcpy(p->next->info->jourgueri,q->jourgueri);
              return l;
            break;            
        default: printf("Element n'exite pas.\n");
        break;    
        }
        }
        p=p->next;
    }
    
    return l;     
}

void menu3() {
printf("\t\t                     |--------------------------------|                      \n");
printf("\t\t                     |       Gestion des gueris       |                      \n");
printf("\t\t                     |--------------------------------|                      \n");
printf("\t\t/---------------------------------------------------------------------------/\n");
printf("\t\t/                     Tapez 1 pour l'insertion:                             /\n");
printf("\t\t/                     Tapez 2 pour l'affichage:                             /\n");
printf("\t\t/                     Tapez 3 pour la suppression:                          /\n");
printf("\t\t/                     tapez 4 pour Modifier:                                /\n");
printf("\t\t/                     tapez 5 pour Quitter:                                 /\n");
printf("\t\t/---------------------------------------------------------------------------/\n");
}

int lengthgueri(listepatientgueri l){
    int len = 0;
    while(l){
        len++;
        l = l->next;
    }
    return len;
}
 
void tauxdeguerisontot(listepatientgueri l,listepatient plist){
int a=lengthgueri(l);
int b =length(plist);

if (b!=0){ 
printf("\nLe taux de guerison total:%.2f%%\n",division(a,b)*100);
}
else { 
printf("\nLe taux de guerison total:0%%\n");
}
}

void writeListegueriToFile(listepatientgueri l){    
    FILE * file;
    remove("Listepatientsgueri.data");
    file = fopen("Listepatientsgueri.data", "w");
    if(lengthgueri(l)){
        while(l){
            fwrite(l->info,sizeof(patientgueri),1,file);
            l = l->next;
        }
        fclose(file);
    }
    else{ printf("Auncun patient a sauvegarder.\n");
    }
    fclose(file);   
}

listepatientgueri Chargergueri(listepatientgueri l){
    FILE *file = fopen("Listepatientsgueri.data", "r");
    if (file == NULL)
    {
        return l;
    }
    while (1)
    {
        patientgueri *pat;
        pat = Malloc(patientgueri);
        fread(pat, sizeof(patientgueri), 1, file);
        if (feof(file))
            break;
        noeud2* nouveau = Malloc(noeud2);
        nouveau->info=pat;
        noeud2* p;
        p=l;    
        if (p == NULL){
           nouveau->next = l;
           l = nouveau;
        }
        else{
            while (p->next != NULL)
                {
                    p = p->next;
                }
            nouveau->next = p->next;
            p->next = nouveau;
        }
    }
    fclose(file);
    return l;
}

void menuaffichagegueri(){
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t                     |         Menu d'affichage:      |                           \n");
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
    printf("\t\t/                    Choisir le critere d'affichage:                             /\n");
    printf("\t\t/             Tapez 1 pour afficher tous les gueris:                             /\n");
    printf("\t\t/             Tapez 2 pour afficher selon la ville:                              /\n");
    printf("\t\t/             Taper 3 pour afficher selon le secteur:                            /\n");
    printf("\t\t/    Taper 4 pour afficher le nombre de gueri et taux de guerison par ville:     /\n");
    printf("\t\t/             Taper 5 pour afficher le taux de guerison total:                   /\n");
    printf("\t\t/             Taper 6 pour afficher le taux de guerison par jour:                /\n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
}

void tauxgueriparjour(listepatientgueri l,listepatient plist){
int c;
char jour[30];
int nbgueri=0;
fflush(stdin);
printf("Choisir le jour:");
gets(jour);
if(l==NULL)
    {
        printf("\nla liste est vide\n");
    }
else {
      listepatientgueri p;
      p=l;

            while(p){
            if (strcmp(p->info->jourgueri,jour)==0) {
            nbgueri++;
            }
            p=p->next;
            }    
}
int n=length(plist);
if (n!=0){ 
printf("\nTaux de guerison du jour %s est %.2f%%\n",jour,division(nbgueri,n)*100);
}
else {
    printf("\nTaux de guerison du jour %s est 0%%",jour);
}
}

void affichergueriparville(listepatientgueri l, char choixville2[30]){
    int j=0;
    int n,i,k;
    int o;
    listepatientgueri p=l;
    n=lengthgueri(l);
    ville T[n];
    while(p)
    {   
            strcpy(T[j].nomville,p->info->ville);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomville,T[i].nomville)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomville,T[k + 1].nomville);
            }
            n--;
         } else
            o++;
      }
   }
   listepatientgueri q=l;
   for (i = 0; i < n; i++) { 
       while(q){
            if (strcmp(q->info->ville,choixville2)==0) {
             printf("\nNom complet:%s   Age:%d   CIN:%s  Secteur:%s   Telephone:%s   Jour de guerison:%s\n",q->info->nom_complet,q->info->age,q->info->CIN,q->info->secteur,q->info->tel,q->info->jourgueri);
            }
            else{
            }
            q=q->next;
            }
   }
}

void affichergueriparsecteur(listepatientgueri l, char choixsecteur2[30]){
    int j=0;
    int n,i,k;
    int o;
    listepatientgueri p=l;
    n=lengthgueri(l);
    secteur T[n];
    while(p)
    {   
            strcpy(T[j].nomsecteur,p->info->secteur);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomsecteur,T[i].nomsecteur)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomsecteur,T[k + 1].nomsecteur);
            }
            n--;
         } else
            o++;
      }
   }
   listepatientgueri q=l;  
   for (i = 0; i < n; i++) { 
       while(q){
            if (strcmp(q->info->secteur,choixsecteur2)==0) {
             printf("\nNom complet:%s   Age:%d   CIN:%s  Ville:%s   Telephone:%s   Jour de guerison:%s \n",q->info->nom_complet,q->info->age,q->info->CIN,q->info->ville,q->info->tel,q->info->jourgueri);
            }
            else{
            }
            q=q->next;
            }
   }
}

void nbgueriettauxparville(listepatientgueri l,listepatient plist,char choixville2[30]){
    int nbpat=0;
    int n;
    n=lengthgueri(l);
    int nbguer=0;
    listepatientgueri q=l;
    while(plist){
                       if (strcmp(plist->info->ville,choixville2)==0) {
                        nbpat++;
               plist=plist->next;
            }
        else{
             plist=plist->next; 
        }
        }   
           while (q){
               if (strcmp(q->info->ville,choixville2)==0){
            
                   nbguer++;
                   q=q->next;
               }
               else {
                       q=q->next;
                   }
               }
        if(nbpat!=0){  
           printf("Ville: %s \t Nombre de gueri: %d \t Taux de guerison:%.2f%%\n",choixville2,nbguer,division(nbguer,nbpat)*100);
           }
        else{
            printf("Ville:%s \t Nombre de gueri: 0 \t Taux de guerison: 0.00%%\n",choixville2);
        }
           
}

listepatientmort ajoutermort(patientmort *d,listepatientmort l){ 
    fflush(stdin);
    printf("\n Le nom complet : \t");
    gets(d->nom_complet);
    fflush(stdin);
    printf("\n L'age: \t");
    scanf("%d",&(d->age));
    fflush(stdin);
    printf("\n CIN: \t");
    gets(d->CIN);
    fflush(stdin);
    printf("\n Ville: \t");
    gets(d->ville);
    fflush(stdin);
    printf("\n Secteur: \t");
    gets(d->secteur);
    fflush(stdin);
    printf("\n Telephone (Chaine de caractere pour conserver le 0 au debut): \t");
    gets(d->tel);
    fflush(stdin);
    printf("\n Jour de décès(Lundi,Mardi,...,Dimanche): \t");
    gets(d->jourmort);
    fflush(stdin);
    noeud3* nouveau = Malloc(noeud3);
    nouveau->info=d;
    noeud3* p;    
    if (l==NULL){
                nouveau->next= NULL;
                l=nouveau;
                return l;
            }
            p=l;
            while(p->next!=NULL)
            {p=p->next;}
            p->next=nouveau;
            nouveau->next=NULL;
return l;
}

listepatientmort supprimermort(patientmort *d,listepatientmort l){
    fflush(stdin);
    printf("L'element a supprimer:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listepatientmort p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {
        l=p->next;
        free(p);
        return l;
    }
    while(p->next!=0)
    {
        if((strcmp(d->CIN,p->next->info->CIN)==0))
        {
            listepatientmort q=p->next;
            p->next=p->next->next;
            free(q);
            return l;
        }
        p=p->next;
    }
    return l;
}

void affichermort(listepatientmort l){
if(l==NULL)
    {
        printf("la liste est vide\n");
    }
else {
      listepatientmort p;
      p=l;
      while(p)
        {
            printf("\nNom complet:%s   Age:%d   CIN:%s  Ville:%s   Secteur:%s   Telephone:%s   Jour de deces:%s \n",p->info->nom_complet,p->info->age,p->info->CIN,p->info->ville,p->info->secteur,p->info->tel,p->info->jourmort);
            p=p->next;
        }
    }        
}

void modificationmenumort(){
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t                     |      Menu de modification:     |                      \n");
    printf("\t\t                     |--------------------------------|                      \n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
    printf("\t\t/                Choisir l'information a modifier:                          /\n");
    printf("\t\t/                       Tapez 1 pour le nom complet :                       /\n");
    printf("\t\t/                       Tapez 2 pour l'Age:                                 /\n");
    printf("\t\t/                       Tapez 3 pour Ville:                                 /\n");
    printf("\t\t/                       Tapez 4 pour Secteur:                               /\n");
    printf("\t\t/                       Tapez 5 pour Telephone:                             /\n");
    printf("\t\t/                       Tapez 6 pour jour de deces:                         /\n");
    printf("\t\t/---------------------------------------------------------------------------/\n");
}

listepatientmort modifiermort(patientmort *d,listepatientmort l){
    int a;
    patientmort *q=Malloc(patientmort);
    fflush(stdin);
    printf("L'element a modifier:\n");             
    printf("\n CIN: \t");
    gets(d->CIN); 
    fflush(stdin);
    if(l==NULL)
    {
        printf("la liste est vide\n");
        return l;
    }
    listepatientmort p=l;
    if ((strcmp(d->CIN,p->info->CIN)==0))
    {  modificationmenumort();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a){
      case 1: printf("La nouvelle donnee:");
            fflush(stdin);
            scanf("%s",q->nom_complet);
            strcpy(p->info->nom_complet,q->nom_complet);
            return l;
            break;
      case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->info->age=q->age;
              return l;
              break;
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->info->ville,q->ville);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->secteur);
              strcpy(p->info->secteur,q->secteur);
              return l;
            break;             
        case 5:printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->tel);
              strcpy(p->info->tel,q->tel);
              return l;
            break;
        case 6: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->jourmort);
              strcpy(p->info->jourmort,q->jourmort);
              return l;
            break;             
        default: printf("Element n'exite pas.\n");
        break;     
        }
    }   
    while(p->next!=0) {
        if((strcmp(d->CIN,p->next->info->CIN)==0)) {
            modificationmenumort();
      printf("Entrer votre choix:");
      scanf("%d",&a);
      switch (a) {
        case 1: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->nom_complet);
              strcpy(p->next->info->nom_complet,q->nom_complet);
              return l;
              break;
        case 2: printf("La nouvelle donnee:");
              fflush(stdin);
              scanf("%d",&(q->age));
              p->next->info->age=q->age;
              return l;
              break;    
        case 3: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->ville);
              strcpy(p->next->info->ville,q->ville);
              return l;
            break;   
        case 4: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->secteur);
              strcpy(p->next->info->secteur,q->secteur);
              return l;
            break;             
        case 5:printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->tel);
              strcpy(p->next->info->tel,q->tel);
              return l;
            break; 
        case 6: printf("La nouvelle donnee:");
              fflush(stdin);
              gets(q->jourmort);
              strcpy(p->next->info->jourmort,q->jourmort);
              return l;
            break;            
        default: printf("Element n'exite pas.\n");
        break;    
        }
        }
        p=p->next;
    }
    
    return l;     
}

void menu4() {
printf("\t\t                     |--------------------------------|                      \n");
printf("\t\t                     |         Gestion des morts:     |                      \n");
printf("\t\t                     |--------------------------------|                      \n");
printf("\t\t/---------------------------------------------------------------------------/\n");
printf("\t\t/                     Tapez 1 pour l'insertion:                             /\n");
printf("\t\t/                     Tapez 2 pour l'affichage:                             /\n");
printf("\t\t/                     Tapez 3 pour la suppression:                          /\n");
printf("\t\t/                     tapez 4 pour Modifier:                                /\n");
printf("\t\t/                     tapez 5 pour Quitter:                                 /\n");
printf("\t\t/---------------------------------------------------------------------------/\n");
}

int lengthmort(listepatientmort l){
    int len = 0;
    while(l){
        len++;
        l = l->next;
    }
    return len;
}

void tauxdemortsontot(listepatientmort l,listepatient plist){
int a=lengthmort(l);
int b =length(plist);
if (b!=0){ 
printf("\nLe taux de mortalite total:%.2f%%\n",division(a,b)*100);
}
else { 
printf("\nLe taux de mortalite total:0%%\n");
}
}

void writeListemortToFile(listepatientmort l){    
    FILE * file;
    remove("Listepatientsmort.data");
    file = fopen("Listepatientsmort.data", "w");
    if(lengthmort(l)){
        while(l){
            fwrite(l->info,sizeof(patientmort),1,file);
            l = l->next;
        }
        fclose(file);
    }
    else{ printf("Auncun patient a sauvegarder.\n");
    }
    fclose(file);   
}

listepatientmort Chargermort(listepatientmort l){
    FILE *file = fopen("Listepatientsmort.data", "r");
    if (file == NULL)
    {
        return l;
    }
    while (1)
    {
        patientmort *pat;
        pat = Malloc(patientmort);
        fread(pat, sizeof(patientmort), 1, file);
        if (feof(file))
            break;
        noeud3* nouveau = Malloc(noeud3);
        nouveau->info=pat;
        noeud3* p;
        p=l;    
        if (p == NULL){
           nouveau->next = l;
           l = nouveau;
        }
        else{
            while (p->next != NULL)
                {
                    p = p->next;
                }
            nouveau->next = p->next;
            p->next = nouveau;
        }
    }
    fclose(file);
    return l;
}

void menuaffichagemort(){
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t                     |         Menu d'affichage:      |                           \n");
    printf("\t\t                     |--------------------------------|                           \n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
    printf("\t\t/                    Choisir le critere d'affichage:                             /\n");
    printf("\t\t/             Tapez 1 pour afficher tous les morts                               /\n");
    printf("\t\t/             Tapez 2 pour afficher selon la ville:                              /\n");
    printf("\t\t/             Taper 3 pour afficher selon le secteur                             /\n");
    printf("\t\t/       Taper 4 pour afficher le nombre de mort et taux mortalite par ville:     /\n");
    printf("\t\t/             Taper 5 pour afficher le taux de mortalite total:                  /\n");
    printf("\t\t/             Taper 6 pour afficher le taux de mortalite par jour:               /\n");
    printf("\t\t/--------------------------------------------------------------------------------/\n");
}

void tauxmortparjour(listepatientmort l,listepatient plist1){
int c;
char jour[30];
int nbmort=0;
fflush(stdin);
printf("Choisir le jour:");
gets(jour);
if(l==NULL)
    {
        printf("la liste est vide\n");
    }
else {
      listepatientmort p;
      p=l;

            while(p){
            if (strcmp(p->info->jourmort,jour)==0) {
            nbmort++;
            }
            p=p->next;
            }    
}
int n=length(plist1);
if (n!=0){ 
printf("\nTaux de mortalite du jour %s est %.2f%%\n",jour,division(nbmort,n)*100);
}
else {
    printf("\nTaux de mortalite du jour %s est 0%%",jour);
}
}
void affichermortparville(listepatientmort l, char choixville3[30]){
    int j=0;
    int n,i,k;
    int o;
    listepatientmort p=l;
    n=lengthmort(l);
    ville T[n];
    while(p)
    {   
            strcpy(T[j].nomville,p->info->ville);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomville,T[i].nomville)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomville,T[k + 1].nomville);
            }
            n--;
         } else
            o++;
      }
   }
   listepatientmort q=l;
   for (i = 0; i < n; i++) { 
       while(q){
            if (strcmp(q->info->ville,choixville3)==0) {
             printf("\nNom complet:%s   Age:%d   CIN:%s  Secteur:%s   Telephone:%s   Jour de deces:%s\n",q->info->nom_complet,q->info->age,q->info->CIN,q->info->secteur,q->info->tel,q->info->jourmort);
            }
            else{
            }
            q=q->next;
            }
   }
}

void affichermortparsecteur(listepatientmort l, char choixsecteur3[30]){
    int j=0;
    int n,i,k;
    int o;
    listepatientmort p=l;
    n=lengthmort(l);
    secteur T[n];
    while(p)
    {   
            strcpy(T[j].nomsecteur,p->info->secteur);
            p=p->next;
            j++;
        }
    for (i=0; i<n;i++) {
      for (o=i+1;o<n;) {
         if (strcmp(T[o].nomsecteur,T[i].nomsecteur)==0) {
            for (k=o;k<n;k++) {
               strcpy(T[k].nomsecteur,T[k + 1].nomsecteur);
            }
            n--;
         } else
            o++;
      }
   }
   listepatientmort q=l;  
   for (i = 0; i < n; i++) { 
       while(q){
            if (strcmp(q->info->secteur,choixsecteur3)==0) {
             printf("\nNom complet:%s   Age:%d   CIN:%s  Ville:%s   Telephone:%s   Jour de deces:%s \n",q->info->nom_complet,q->info->age,q->info->CIN,q->info->ville,q->info->tel,q->info->jourmort);
            }
            else{
            }
            q=q->next;
            }
   }
}

void nbmortettauxparville(listepatientmort l,listepatient plist1,char choixville3[30]){
int nbpat=0;
    int n;
    n=lengthmort(l);
    int nbmort=0;
    listepatientmort q=l;
    while(plist1){
                       if (strcmp(plist1->info->ville,choixville3)==0) {
                        nbpat++;
               plist1=plist1->next;
            }
        else{
             plist1=plist1->next; 
        }
        }   
           while (q){
               if (strcmp(q->info->ville,choixville3)==0){
            
                   nbmort++;
                   q=q->next;
               }
               else {
                       q=q->next;
                   }
               }
        if(nbpat!=0){  
           printf("Ville: %s \t Nombre de deces: %d \t Taux de mortalite:%.2f%%\n",choixville3,nbmort,division(nbmort,nbpat)*100);
           }
        else{
            printf("Ville:%s \t Nombre de deces: 0 \t Taux de mortalite: 0.00%%\n",choixville3);
        }

}

int main(){
int a=1;
int choixprincipal;
do
{
menu();   
scanf("%d",&choixprincipal);        
  switch (choixprincipal){
        case 1: fflush(stdin);
                int b=1,choix1; 
                char choixville[30];
                listepatient l=NULL;
                l=Chargerpatient(l);
                do{
                   patient *d=Malloc(patient);
                   menu1();   
                   scanf("%d",&choix1);        
                   switch (choix1){
                   case 1: l=add(d,l);
                           writeListePatientToFile(l);
                        break;
                   case 2: menuaffichage();
                           int z;
                           printf("Entrer votre choix: ");
                           scanf("%d",&z);
                           switch (z){
                                case 1: afficher(l);
                                    break;               
                                case 2: afficheretat(l);
                                    break;
                                case 3: fflush(stdin);
                                        printf("Choisir la ville:");
                                        gets(choixville);                 
                                        afficherparville(l,choixville);
                                    break;
                                case 4: nbcasparville(l);
                                    break;
                                case 5: fflush(stdin);
                                        tauxoccuplit(l);
                                    break;
                                case 6: nbcascritiqueparville(l);
                                    break;        
                                default: printf("Ce choix n'existe pas.\n");
                                    break;

                            }
                        break;
                   case 3: l=supprimer(d,l);
                writeListePatientToFile(l);
                        break;
                   case 4:l=modifier(d,l);
                writeListePatientToFile(l);
                        break;    
                   case 5: b=0;
                        break;
                   default: printf("Ce choix n'existe pas.\n");
                        break;    
                   }
                }while (b!=0);

            break;
        case 2: fflush(stdin);
                int f=1,choix2; 
                char choixville1[30];
                char choixsecteur[30];
                listecontactpatient lcont=NULL;
                lcont=Chargercontact(lcont);
                do{
                contactpatient *qcont=Malloc(contactpatient);
                menu2();   
                scanf("%d",&choix2);        
                  switch (choix2){
                        case 1: lcont=ajoutercontact(qcont,lcont);
                                writeListeContacttToFile(lcont);
                                break;
                        case 2: menuaffichagecontact();
                                int z;
                                printf("Entrer votre choix: ");
                                scanf("%d",&z);
                                switch (z){
                                    case 1: affichercontact(lcont);
                                        break;               
                                    case 2: fflush(stdin);
                                            printf("Choisir la ville:");
                                            gets(choixville1);                 
                                            affichercontactparville(lcont,choixville1);
                                        break;
                                    case 3: fflush(stdin);
                                            printf("Choisir la secteur:");
                                            gets(choixsecteur);                 
                                            affichercontactparsecteur(lcont,choixsecteur);
                                        break;
                                    case 4: nbcontactparville(lcont);
                                        break;     
                                    default: printf("Ce choix n'existe pas.\n");
                                        break;
                                        }
                                    break;
                        case 3: lcont=supprimercontact(qcont,lcont);
                                writeListeContacttToFile(lcont);
                                    break;
                        case 4: lcont=modifiercontact(qcont,lcont);
                                writeListeContacttToFile(lcont);
                                    break;    
                        case 5: f=0;
                                    break;
                        }
                        }while (f!=0);
                    break;
        case 3: fflush(stdin);
                int v=1,choix3; 
                listepatient plist=NULL;
                plist=Chargerpatient(plist);
                char choixville2[30];
                char choixsecteur2[30];
                listepatientgueri glist=NULL;
                glist=Chargergueri(glist);
                        do{
                            patientgueri *qguer=Malloc(patientgueri);
                            menu3();   
                            scanf("%d",&choix3);        
                                switch (choix3){
                                    case 1: glist=ajoutergueri(qguer,glist);
                                            writeListegueriToFile(glist);
                                        break;
                                    case 2: menuaffichagegueri();
                                            int z;
                                            printf("Entrer votre choix: ");
                                            scanf("%d",&z);
                                                switch (z){
                                                    case 1: affichergueri(glist);
                                                        break;               
                                                    case 2: fflush(stdin);
                                                            printf("Choisir la ville:");
                                                            gets(choixville2);                 
                                                            affichergueriparville(glist,choixville2);
                                                        break;
                                                    case 3: fflush(stdin);
                                                            printf("Choisir la secteur:");
                                                            gets(choixsecteur2);                 
                                                            affichergueriparsecteur(glist,choixsecteur2);
                                                        break;
                                                    case 4:fflush(stdin);
                                                           printf("Choisir la ville:");
                                                           gets(choixville2);  
                                                           nbgueriettauxparville(glist,plist,choixville2);
                                                        break;     
                                                    case 5:   
                                                    tauxdeguerisontot(glist,plist);
                                                        break;
                                                    case 6: tauxgueriparjour(glist,plist);
                                                        break;
                                                    default: printf("Ce choix n'existe pas.\n");
                                                        break;
                                                    }
                                        break;
                                    case 3: glist=supprimergueri(qguer,glist);
                                            writeListegueriToFile(glist);
                                        break;
                                    case 4: glist=modifiergueri(qguer,glist);
                                            writeListegueriToFile(glist);
                                        break;    
                                    case 5: v=0;
                                        break;
                                    }
                                }while (v!=0);
                                break;
        case 4: fflush(stdin);
                int t=1,choix4; 
                listepatient plist1=NULL;
                plist1=Chargerpatient(plist1);
                char choixville3[30];
                char choixsecteur3[30];
                listepatientmort mlist=NULL;
                mlist=Chargermort(mlist);
               do
{
patientmort *qmort=Malloc(patientmort);
menu4();  
scanf("%d",&choix4);        
  switch (choix4){
        case 1: mlist=ajoutermort(qmort,mlist);
                writeListemortToFile(mlist);
                break;
        case 2: menuaffichagemort();
                int z;
                printf("Entrer votre choix: ");
                scanf("%d",&z);
                switch (z)
                {
                case 1: affichermort(mlist);
                    break;               
                case 2: fflush(stdin);
                        printf("Choisir la ville:");
                        gets(choixville3);                 
                        affichermortparville(mlist,choixville3);
                    break;
                case 3: fflush(stdin);
                        printf("Choisir la secteur:");
                        gets(choixsecteur3);                 
                        affichermortparsecteur(mlist,choixsecteur3);
                    break;
                case 4: fflush(stdin);
                        printf("Choisir la ville:");
                        gets(choixville3);
                nbmortettauxparville(mlist,plist1,choixville3);
                    break;     
                case 5: tauxdemortsontot(mlist,plist1);
                        break;
                case 6: tauxmortparjour(mlist,plist1);
                        break;
                default: printf("Ce choix n'existe pas.\n");
                break;

                }
            break;
        case 3: mlist=supprimermort(qmort,mlist);
                writeListemortToFile(mlist);
            break;
        case 4: mlist=modifiermort(qmort,mlist);
                writeListemortToFile(mlist);
            break;    
        case 5: t=0;
            break;
    }
}while (t!=0);
                 break;                        
        case 5: a=0;
            break;
        default: printf("Ce choix n'existe pas.\n");
        break;    
    }
}while (a!=0);
}
