#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define Malloc(type) (type*)malloc(sizeof(type))

typedef struct patient{
    char nom_complet[30]; //Sous la forme: Prénom_Nom
    char etat[30];// L'état du patient: Normal,Critique,Besoin aide respiratoire
    char typechambre[30];//Type de chambre occupée: Normal,Reanimation
    char ville[30];
    char CIN[30];//CIN unique
    char jourinfection[30]; //le jour de l'infection (Lundi,...,Dimanche)
    int age;
    int chambre;// Le nombre du chambre occupée
    int occupelit; // 0 s'il n'occupe pas un lit 1 sinon          
}patient;

typedef struct contact_patient{
    char nom_complet[30]; //Sous la forme: Prénom_Nom
    char ville[30];
    char secteur[30];
    char CIN[30]; //CIN unique
    char tel[30]; //Une chaine de caractére pour conserver le 0 au début
    int age;
}contactpatient;

typedef struct patient_gueri{
    char nom_complet[30]; //Sous la forme: Prénom_Nom
    char ville[30];
    char secteur[30];
    char CIN[30]; //CIN unique
    char jourgueri[30]; //le jour de guérison (Lundi,...,Dimanche)
    char tel[30]; //Une chaine de caractére pour conserver le 0 au début
    int age;
}patientgueri;

typedef struct patient_mort{
    char nom_complet[30]; //Sous la forme: Prénom_Nom
    char ville[30];
    char secteur[30]; 
    char CIN[30]; //CIN unique
    char jourmort[30];//le jour de décés (Lundi,...,Dimanche)
    char tel[30];//Une chaine de caractére pour conserver le 0 au début
    int age;
}patientmort;

typedef struct noeud3{
    patientmort *info;
    struct noeud3 *next;
}noeud3;

typedef struct noeud2{
    patientgueri *info;
    struct noeud2 *next;
}noeud2;

typedef struct noeud{
    patient *info;
    struct noeud *next;
}noeud;

typedef struct noeud1{
    contactpatient *info;
    struct noeud1 *next;
}noeud1;

typedef noeud* listepatient;
typedef noeud1* listecontactpatient;
typedef noeud2* listepatientgueri;
typedef noeud3* listepatientmort;

typedef struct _ville{
char nomville[30];
}ville;

typedef struct _secteur{
char nomsecteur[30];
}secteur;

//Fonctions patient:

listepatient add(patient *d,listepatient l);
listepatient supprimer(patient *d,listepatient l);
void afficher(listepatient l);
void afficheretat(listepatient l);
listepatient modifier(patient *d,listepatient l);
int length(listepatient l);
void writeListePatientToFile(listepatient l);
listepatient Chargerpatient(listepatient l);
void afficherparville(listepatient l, char choixville[30]);
void tauxoccuplit(listepatient l);
void nbcascritiqueparville(listepatient l);
void nbcasparville(listepatient l);

//Fonctions contact:

listecontactpatient ajoutercontact(contactpatient *d,listecontactpatient l);
listecontactpatient supprimercontact(contactpatient *d,listecontactpatient l);
void affichercontact(listecontactpatient l);
listecontactpatient modifiercontact(contactpatient *d,listecontactpatient l);
int lengthcontact(listecontactpatient l);
void writeListeContacttToFile(listecontactpatient l);
listecontactpatient Chargercontact(listecontactpatient l);
void affichercontactparville(listecontactpatient l, char choixville1[30]);
void affichercontactparsecteur(listecontactpatient l, char choixsecteur[30]);
void nbcontactparville(listecontactpatient l);

//Fonctions guéri:

listepatientgueri ajoutergueri(patientgueri *d,listepatientgueri l);
listepatientgueri supprimergueri(patientgueri *d,listepatientgueri l);
void affichergueri(listepatientgueri l);
listepatientgueri modifiergueri(patientgueri *d,listepatientgueri l);
int lengthgueri(listepatientgueri l);
void tauxdeguerisontot(listepatientgueri l,listepatient plist);
void writeListegueriToFile(listepatientgueri l);
listepatientgueri Chargergueri(listepatientgueri l);
void tauxgueriparjour(listepatientgueri l,listepatient plist);
void affichergueriparville(listepatientgueri l, char choixville2[30]);
void affichergueriparsecteur(listepatientgueri l, char choixsecteur2[30]);
void nbgueriettauxparville(listepatientgueri l,listepatient plist,char choixville2[30]);

//Fonctions morts:

listepatientmort ajoutermort(patientmort *d,listepatientmort l);
listepatientmort supprimermort(patientmort *d,listepatientmort l);
void affichermort(listepatientmort l);
listepatientmort modifiermort(patientmort *d,listepatientmort l);
int lengthmort(listepatientmort l);
void tauxdemortsontot(listepatientmort l,listepatient plist);
void writeListemortToFile(listepatientmort l);
listepatientmort Chargermort(listepatientmort l);
void tauxmortparjour(listepatientmort l,listepatient plist1);
void affichermortparville(listepatientmort l, char choixville3[30]);
void affichermortparsecteur(listepatientmort l, char choixsecteur3[30]);
void nbmortettauxparville(listepatientmort l,listepatient plist1,char choixville3[30]);

//Fonctions menu:

void menuaffichagegueri();
void menu3();
void menuaffichagemort();
void menu4();
void modificationmenumort();
void modificationmenugueri();
void menuaffichagecontact();
void modificationmenucontact();
void menuaffichage();
void menu();
void menu2();
void modificationmenu();
void menu1();

//Fonction commune:
float division(int A,int B);