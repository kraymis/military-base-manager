#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Tpsfsd.h"
#include <conio.h>
#include <windows.h>
#include "conio2.h"
#include "display.h"
#include <string.h>
#ifdef _WIN32
#include <io.h>
#define ACCESS _access
#define F_OK 0
#else
#include <unistd.h>
#define ACCESS access
#endif


void  contor() // Une proc�dure pour dessiner un contour sur l'�cran avec le nom de l'ESI au coin .
{
    int i;
    gotoxy(2,2);
    printf("%c",201);
    for(i=3;i<156;i++)
    {
        gotoxy(i,2);
        printf("%c",205);
        gotoxy(i,40);
        printf("%c",205);

    }
    gotoxy(156,2);
    printf("%c",187);

    for(i=3;i<40;i++)
    {
        gotoxy(2,i);
        printf("%c",186);
        gotoxy(156,i);
        printf("%c",186);
    }
    gotoxy(2,40);
    printf("%c",200);

    gotoxy(156,40);
    printf("%c",188);
    gotoxy(145,3);
    printf("%c%c%c %c%c%c %c",201,205,187,201,205,187,203);
    gotoxy(145,4);
    printf("%c%c%c %c%c%C %c",204,205,188,200,205,187,186);
    gotoxy(145,5);
    printf("%c%c%c %c%c%c %c",200,205,205,200,205,188,202);
}

void menu_affichage(int *choice){
    int y=16,cpt=1;
    char c;
gotoxy(30,y);blanct();printf("               Afficher tout les paires                  \n");
y++;
gotoxy(30,y);blanct();printf("        Afficher les paires avec une seule taille        \n");
y++;
do{
       y=16;
    c=getch();
        if(c==up){cpt%=2;cpt++;}
        if(c==down){cpt--;if(cpt==0)cpt=2;}
gotoxy(30,y);noire();if(cpt==1) bleu();blanct();printf("               Afficher tout les paires                  \n");
y++;
gotoxy(30,y);noire();if(cpt==2) bleu();blanct();printf("        Afficher les paires avec une seule taille        \n");
y++;
}while(c!=13);
noire();
if(c==13){
    *choice=cpt;
}
}
void bienvenue_disppear(){
    gotoxy(38,7);
    noire();printf("                                                                                                                          ");
    gotoxy(38,8);        printf("                                                                                                              ");
      gotoxy(38,9);      printf("                                                                                                              ");
     gotoxy(38,10);       printf("                                                                                                             ");
}


void bienvenue(){
vert();
    gotoxy(63,7);
    printf("%c",186);
    gotoxy(63,8);
   printf("%c%c%c%c %c %c%c%c %c%c%c %c%c %c%c %c%c%c %c%c%c %c %c %c%c%c ",204,205,205,187,203,201,205,187,201,205,187,205,187,201,187,201,205,187,201,205,187,203,203,201,205,187,201,205,187,186,201,205,187,201,205,187,186,201,205,187,186,203,201,205,187,201,205,187);
   gotoxy(63,9);                                                          
blanct();  printf("%c  %c %c %c%c%c %c %c  %c %c%c %c%c%c %c %c %c %c %c%c%c  ",186,186,186,204,205,188,186,186,186,200,204,204,205,188,186,186,186,186,204,205,188,201,205,185,186,201,205,185,200,205,187,205,206,205,201,205,185,205,206,205,186,186,186,186,186);
   gotoxy(63,10);
 vert();   printf("%c%c%c%c %c %c%c%c %c %c  %c%c%c%c %c%c%c %c %c %c%c%c %c%c%c",200,205,205,188,202,200,205,188,202,202,200,205,205,188,200,205,188,202,202,200,205,188,200,205,188,200,205,188,200,205,205,200,205,188,200,205,188,200,205,200,205,188,200,205,202,200,205,188,202,202);
//center_text("  ____  _____  ______  _   _ __      __ ______  _   _  _    _  ______              _                   _____  _______      _______  _____  ____   _   _ \n");,
//center_text(" |  _ \\|_   _||  ____|| \\ | |\\ \\    / /|  ____|| \\ | || |  | ||  ____|     /\\     | |         /\\      / ____||__   __| /\\ |__   __||_   _|/ __ \\ | \\ | |\n");
//center_text(" | |_) | | |  | |__   |  \\| | \\ \\  / / | |__   |  \\| || |  | || |__       /  \\    | |        /  \\    | (___     | |   /  \\   | |     | | | |  | ||  \\| |\n");
//center_text(" |  _ <  | |  |  __|  | . ` |  \\ \\/ /  |  __|  | . ` || |  | ||  __|     / /\\ \\   | |       / /\\ \\    \\___ \\    | |  / /\\ \\  | |     | | | |  | || . ` |\n");
//center_text(" | |_) |_| |_ | |____ | |\\  |   \\  /   | |____ | |\\  || |__| || |____   / ____ \\  | |____  / ____ \\   ____) |   | | / ____ \\ | |    _| |_| |__| || |\\  |\n");
//center_text(" |____/|_____||______||_| \\_|    \\/    |______||_| \\_| \\____/ |______| /_/    \\_\\ |______|/_/    \\_\\ |_____/    |_|/_/    \\_\\|_|   |_____|\\____/ |_| \\_|\n");
}

void menu(int *choix){
    int y=16,cpt=1;
    char c;
gotoxy(margin,y);blanct();bleu();printf("               Chargement du fichier               \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                Afficher le fichier                \n");
y++;
gotoxy(margin,y);blanct();noire();printf("     Sauvgrade d'index dans MATRICULE_INDEX.idx    \n");
y++;
gotoxy(margin,y);blanct();noire();printf("     Chargement d'index de MATRICULE_INDEX.idx     \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                Ajouter un militaire               \n");
y++;
gotoxy(margin,y);blanct();noire();printf("              Recherche d'un militaire             \n");
y++;
gotoxy(margin,y);blanct();noire();printf("               Supprimer un militaire              \n");
y++;
gotoxy(margin,y);blanct();noire();printf("       Modification de la région militaire         \n");
y++;
gotoxy(margin,y);blanct();noire();printf("       Affichage par intervalle de matricules      \n");
y++;
gotoxy(margin,y);blanct();noire();printf("        Suppression des militaires d'une force     \n");
y++;
gotoxy(margin,y);blanct();noire();printf(" Affichage des militaires ayant age entre M1 et M2 \n");
y++;
gotoxy(margin,y);blanct();noire();printf("    Affichage de tout les militaires du meme grade \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                       Quitter                     \n");
y++;
do{
        y=16;
    c=getch();
        if(c==up){cpt%=13;cpt++;}
        if(c==down){cpt--;if(cpt==0)cpt=13;}
gotoxy(margin,y);noire();if(cpt==1) bleu();blanct();printf("               Chargement du fichier               \n");
y++;
gotoxy(margin,y);noire();if(cpt==2) bleu();blanct();printf("                Afficher le fichier                \n");
y++;
gotoxy(margin,y);noire();if(cpt==3) bleu();blanct();printf("     Sauvgrade d'index dans MATRICULE_INDEX.idx    \n");
y++;
gotoxy(margin,y);noire();if(cpt==4) bleu();blanct();printf("     Chargement d'index de MATRICULE_INDEX.idx     \n");
y++;
gotoxy(margin,y);noire();if(cpt==5) bleu();blanct();printf("                Ajouter un militaire               \n");
y++;
gotoxy(margin,y);noire();if(cpt==6) bleu();blanct();printf("              Recherche d'un militaire             \n");
y++;
gotoxy(margin,y);noire();if(cpt==7) bleu();blanct();printf("               Supprimer un militaire              \n");
y++;
gotoxy(margin,y);noire();if(cpt==8) bleu();blanct();printf("       Modification de la région militaire         \n");
y++;
gotoxy(margin,y);noire();if(cpt==9) bleu();blanct();printf("       Affichage par intervalle de matricules      \n");
y++;
gotoxy(margin,y);noire();if(cpt==10) bleu();blanct();printf("        Suppression des militaires d'une force     \n");
y++;
gotoxy(margin,y);noire();if(cpt==11) bleu();blanct();printf(" Affichage des militaires ayant age entre M1 et M2 \n");
y++;
gotoxy(margin,y);noire();if(cpt==12) bleu();blanct();printf("    Affichage de tout les militaires du meme grade \n");
y++;
gotoxy(margin,y);noire();if(cpt==13) bleu();blanct();printf("                       Quitter                     \n");
y++;


}while(c!=13);
noire();
if(c==13){
    *choix=cpt;
}
}
void menu_disappear(){
  int  y=16;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
gotoxy(margin,y);blanct();noire();printf("                                                   \n");
y++;
}


void erreur(){
    system("cls");
     gotoxy(margin+10,14);
    rouget();
    printf("ERREUR : VEUILLEZ CREER LE FICHIER");
    delay(25);
    gotoxy(margin+7,16);
    noire();
    printf("                                               ");
    gotoxy(margin +12,18);
    rouget();
    printf("ERREUR : VEUILLEZ CREER LE FICHIER");
    delay(25);
    gotoxy(margin+7,20);
    noire();
    printf("                                               ");
    gotoxy(margin+7,22);
    rouget();
    printf("ERREUR : VEUILLEZ CREER LE FICHIER");
    delay(25);
    noire();
    gotoxy(margin+7,24);
    printf("                                               ");
    gotoxy(margin+10,26);
    rouget();
    printf("ERREUR : VEUILLEZ CREER LE FICHIER");
    gotoxy(margin+10,28);
    printf("Appuyer sur une touche pour continuer ...");
    getch();
}

void erreur_fichier_non_existant(){
    system("cls");
    gotoxy(margin +10,14);
    rouget();
    printf("ERREUR : LE FICHIER D INDEX N EXISTE PAS");
    delay(25);
    gotoxy(margin+7,16);
    noire();
    printf("                                               ");
    gotoxy(margin +12,18);
    rouget();
    printf("ERREUR : LE FICHIER D INDEX N EXISTE PAS");
    delay(25);
    gotoxy(margin+7,20);
    noire();
    printf("                                               ");
    gotoxy(margin+7,22);
    rouget();
    printf("ERREUR : LE FICHIER D INDEX N EXISTE PAS");
    delay(25);
    noire();
    gotoxy(margin+7,24);
    printf("                                               ");
    gotoxy(margin+10,26);
    rouget();
    printf("ERREUR : LE FICHIER D INDEX N EXISTE PAS");
    gotoxy(margin+10,28);
    printf("Appuyer sur une touche pour continuer ...");
    getch();
}

void erreur_cree(){
    system("cls");
    gotoxy(margin +10,14);
    rouget();
    printf("ERREUR : LA STRUCTURE EST DEJA CREE !!");
    delay(25);
    gotoxy(margin+7,16);
    noire();
    printf("                                                ");
    gotoxy(margin +12,18);
    rouget();
    printf("ERREUR : LA STRUCTURE EST DEJA CREE !!");
    delay(25);
    gotoxy(margin+7,20);
    noire();
    printf("                                                ");
    gotoxy(margin+7,22);
    rouget();
    printf("ERREUR : LA STRUCTURE EST DEJA CREE !!");
    delay(25);
    noire();
    gotoxy(margin+7,24);
    printf("                                                ");
    gotoxy(margin+10,26);
    rouget();
    printf("ERREUR : LA STRUCTURE EST DEJA CREE !!");
    gotoxy(margin+10,28);
    printf("Appuyer sur une touche pour continuer ...");
    getch();
}

void traitementApresChargement(index * indexPRIMAIRE){
    int aff;
    system("cls");
    contor();
    gotoxy(17, 14);
    printf("Est ce que vous voulez afficher la table d'index? (1/0) : ");
    while ((aff != 0) && (aff != 1))
    {
    scanf("%d",&aff);
    }
    system("cls");
    if (aff == 1)
    {
    gotoxy(17, 14);
    printf("On va afficher la table d'index : (Matricule) ...");
    for (int i = 0; i < 3; i++) {
    delay(500);
    }

    afficherMatriculesIndex(indexPRIMAIRE);
    }
    else{
        gotoxy(17, 16);
        bleut();
        printf("OKAY MERCI\n");
    }

}
int isFileExists(const char *fileName) {
    return ACCESS(fileName, F_OK) == 0;
}

void main_menu()
{
      char nom[25];
  int struct_cree = 0, taille;
  char nomFichier[25];
  index indexPRIMAIRE;
  IndexSecondaire indexREGION;
  IndexThird indexGRADE;
  IndexFour indexFORCE;
  bool trouv=false;
  Tenreg personne;
  int choix,matricule,matriculeToDelete,matriculeToModify,newRegion,M1,M2,forceTodelete,maxAge,minAge,regionNumber,gradeCategory;
    // intro();
    // loading_page();
      while (1) {
        menu:
            system("cls");
            vert();
            contor();
            bienvenue();
            menu(&choix);
            gotoxy(155, 40);
            system("pause");
            switch (choix) {
                case 1: {
                        if (struct_cree == 0) {
                            menu_disappear();
                            bienvenue_disppear();
                            system("cls");
                            contor();
                            gotoxy(20, 10);
                            vert();
                            printf("La fichier est en train de créer. Attendez s'il vous plaît ");
                            for (int i = 0; i < 3; i++) {
                                delay(500);
                                gotoxy(20+i,12);
                                printf(".");
                            }

                            chargementInitial(nomFichier,&indexPRIMAIRE,&indexREGION,&indexGRADE,&indexFORCE);
                            for (int i = 0; i < 3; i++) {
                                delay(500);
                            }
                            // printf("\n");
                            system("cls");

                            // Clear the screen before displaying the success message
                            contor();
                            gotoxy(30, 15);
                            vert();
                            printf("La fichier a été réalisé !!!\n");
                            struct_cree = 1;
                            delay(100);
                            blanct();
                            gotoxy(30, 18);
                            printf("Appuyer sur une touche pour continuer ...");
                            getch();
                            goto menu;
                        } else {
                            erreur_cree();
                            getch();
                            blanct();
                            goto menu;
                        }
                        break;
                } 
                    //              personne = createRecordFromUserInput();
    //             insererPersonne(nomFichier,personne,&indexPRIMAIRE);
                
                case 2: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        ("On va faire afficher tout le fichier  %s\n",nomFichier);
                        gotoxy(5,16);
                        vert();
                        printf("------------------AFFICHAGE :------------------  \n");
                        for (int i = 0; i < 3; i++) {
                        delay(700);
                        printf(".");
                        }
                        system("cls");
                        afficherFichier(nomFichier);
                        printf("\n");
                        vert();
                        printf("           Affichage terminée Terminée !!! \n");
                        printf("\n");
                        vert();
                        printf("           Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }               
                case 3: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        printf("On va faire le sauvgrade du fichier de la table d'index dans le fichier MATRICULE_INDEX.idx \n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17+i, 15);
                            printf(".");
                            }
                        ChargementIndexToDisk(&indexPRIMAIRE, "MATRICULE_INDEX.idx");
                        gotoxy(17, 20);
                        vert();
                        printf("Chargement Terminée !!! \n");
                        gotoxy(17, 22);
                        printf("Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }
                case 4: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (isFileExists("MATRICULE_INDEX.idx")) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        printf("On va faire le chargemenet de la table d'index depuis le fichier MATRICULE_INDEX.idx \n");
                        
                        for (int i = 0; i < 3; i++) {
                        delay(500);
                        gotoxy(17+i,16);
                        printf(".");
                        }
                        
                        ChargementIndexFromDisk(&indexPRIMAIRE,"MATRICULE_INDEX.idx");

                        traitementApresChargement(&indexPRIMAIRE);
                        
                        
                        gotoxy(17, 50);
                        vert();
                        printf("Operation Terminée !!! \n");
                        gotoxy(17, 52);
                        printf("\nAppuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    
                    } else {
                        contor();
                        erreur_fichier_non_existant();
                        blanct();

                        goto menu;
                    }
                    break;
                }
                case 5: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        vert();
                        printf("Pour linsertion vous allez rentrez les informations de la personne à inserer \n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17+i,15);
                            printf(".");
                            }
                        personne = createRecordFromUserInput();
                        insererPersonne(nomFichier,personne,&indexPRIMAIRE);
                        vert();
                        gotoxy(17,38);
                        printf("Chargement Terminée !!! ");
                        gotoxy(17,40);
                        printf("Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }
                case 6: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        printf("On va chercher une personne par sa matricule \n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17+i,16);
                            printf(".");
                            }
                        gotoxy(17,18);
                        vert();
                        printf("Veuillez entrez la matricule à rechercher : ");
                        scanf("%d",&matricule);

                        gotoxy(17,20);
                        vert();
                        printf("\n------------------------------------\n");
                        system("cls");
                        center_text(" XVXVXV ici debut de la fonction recherche militaire XVXVXV\n"); 
                        for (int i = 0; i < 3; i++) {
                        delay(500);
                        }  
                        rechercheMilitaire(nomFichier,matricule,&indexPRIMAIRE,&trouv);
                        if (trouv)
                        {
                         center_text("Le cout de l'operation est de : 1 lectures\n");
                        }
                        else{
                         center_text("Le cout de l'operation est de : 0 lectures\n");
                        }
                        
                        vert();
                        gotoxy(17,36);
                        printf("Recherche terminée !!! ");
                        gotoxy(17,38);
                        printf("Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }




                case 7: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        printf("On va supprimer une persoones à partir de sa matricule \n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17,16);
                            printf(".");
                            }
                        gotoxy(17,18);
                        rouget();
                        printf("Veuillez entrer le matricule à supprimer : ");
                        scanf("%d",&matriculeToDelete);

                        gotoxy(17,20);
                        rouget();
                        printf("\n              ------------------------------------\n");
                        
                        Supp_personne(nomFichier,matriculeToDelete,&indexPRIMAIRE);
                        
                        rouget();
                        gotoxy(17,36);
                        printf("Operation terminée terminée !!! ");
                        gotoxy(17,38);
                        printf("Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }



                case 8: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        printf("On va modifier la region militaire d'une personne \n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17+i,16);
                            printf(".");
                            }
                        gotoxy(17,18);
                       bleut();
                       printf("Veuillez entrer le matricule à modifier : ");
                       scanf("%d", &matriculeToModify);
                        gotoxy(17,20);
                        bleut();
                        printf("------------------------------------\n");
                        gotoxy(17,22);
                        bleut();
                        printf("On va effectuer une operation de recherche pour la personne\n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17+i,24);
                            printf(".");
                            }
                        trouv=false;
                        system("cls");
                       center_text(" XVXVXV ici debut de la fonction recherche militaire XVXVXV\n");
                       for (int i = 0; i < 3; i++) {
                        delay(500);
                        }
                       rechercheMilitaire(nomFichier,matriculeToModify,&indexPRIMAIRE,&trouv);
                        if (trouv)
                        {
                        printf("\n           Veuillez entrer la nouvelle région : ");
                        scanf("%d", &newRegion);
                        ModifierRegionPersonne(nomFichier,&indexPRIMAIRE,matriculeToModify,newRegion);
                        }
                        
                        bleut();
                        gotoxy(17,38);
                        printf("Modification terminée !!! ");
                        gotoxy(17,40);
                        printf("Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }



                case 9: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        printf("On recherche des militaires a partir d in interval M1,M2 \n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17+i,16);
                            printf(".");
                            }
                        gotoxy(17,18);
                        bleut();
                        printf("Veuillez entrer l'intervalle [M1, M2] : ");
                        scanf("%d %d", &M1, &M2);                // ...
                        gotoxy(17,20);
                        bleut();
                        printf("------------------------------------\n");

                        gotoxy(17,22);
                        bleut();
                        printf("On va afficher ...\n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17,24);
                            printf(".");
                            }
                        system("cls");
                        chercher_M1M2(nomFichier,&indexPRIMAIRE,M1,M2);

                        
                        bleut();
                        gotoxy(17,45);
                        printf("           Recherche terminée !!! \n");
                        gotoxy(17,47);
                        printf("           Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }
                case 10: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        
                        gotoxy(17, 14);
                        
                        printf("On va Supprimmer de tous les enregistrements relatifs à une force armée donnée \n");
                        for (int i = 0; i < 3; i++) {
                        delay(500);
                        gotoxy(17,16);
                        printf(".");
                        }
                        
                        gotoxy(17,18);
                        vert();
                        printf("Veuillez entrer la force armée à supprimer : ");
                        scanf("%d", &forceTodelete);
                        gotoxy(17,20);
                        vert();
                        printf("\n           ------------------------------------\n");
                        
                        DeleteForceListByIndex(nomFichier,&indexFORCE,forceTodelete,&indexPRIMAIRE);
                        
                        vert();
                        // gotoxy(17,36);
                        printf("\n           Operation Successfully");
                        // gotoxy(17,38);
                        printf("\n           Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }

                case 11: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        
                        gotoxy(17, 14);
                        
                        printf("On affichage de tout les personnes dans une région militaire ayant un âge entre deux valeurs données\n");

                        for (int i = 0; i < 3; i++) {
                        delay(500);
                        gotoxy(17+i,16);
                        printf(".");
                        }

                        
                        gotoxy(17,18);
                        vert();
                    printf("Enter the military region number (1-6): ");
                    scanf("%d", &regionNumber);

                    gotoxy(17,20);
                    vert();
                    printf("Enter the minimum age: ");
                    scanf("%d", &minAge);
              
                       gotoxy(17,22);
                        vert();
                    printf("Enter the maximum age: ");
                    scanf("%d", &maxAge);
                       gotoxy(17,24);
                        vert();
                    printf("------------------------------------\n");
                    system("cls");

                    printRegionListInAgeInterval(nomFichier,&indexPRIMAIRE,&indexREGION,regionNumber,minAge,maxAge);                        
                    
                        vert();
                        printf("\n           Operation Successfully");
                        vert();
                        printf("\n           Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }
                case 12: {
                        menu_disappear();
                        bienvenue_disppear();
                    int sous_choix;
                    if (struct_cree == 1) {
                        system("cls");
                        contor();
                        gotoxy(17, 14);
                        printf("On affiche les personnes du meme grade \n");
                            for (int i = 0; i < 3; i++) {
                            delay(500);
                            gotoxy(17+i,16);
                            printf(".");
                            }

                        gotoxy(17,18);
                        vert();
                        printf("Enter the grade category (1-19):");
                        scanf("%d", &gradeCategory);
                        gotoxy(17,20);
                        vert();
                        printf("------------------------------------\n");

                        printGradeList(nomFichier,&indexGRADE,gradeCategory,&indexPRIMAIRE);
                           
                        
                        vert();
                        printf("\n           Operation Successfully");
                        vert();
                        printf("\n           Appuyer sur une touche pour continuer ... ");
                        getch();
                        goto menu;
                    } else {
                        erreur();
                        blanct();

                        goto menu;
                    }
                    break;
                }



                case 13: 
                {
                system("cls");
                exit(0);
                break;
                }

    }
    }
}






int main()
{
  srand(time(NULL));
  intro();
  loading_page();
  main_menu();
    return 0;
}
