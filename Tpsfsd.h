#ifndef TPSFSD_H_INCLUDED
#define TPSFSD_H_INCLUDED

#define MAX 1024
#define MAXINDEX 100000
#define MAX_BLOC_INDEX 1024

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <string.h>
#include "conio2.h"
#include <conio.h>
#include "MachineAbstraiteFichier.h"
#include "MachineAbstraiteIndex.h"
#include "tpsfsdREGION.h"
#include "tpsfsdGRADE.h"



typedef struct {
    int taille;
    int force;
    Pointeur_Matricule TeteListeforce; // Utilisation du type Pointeur_Matricule
} EnregforceIndex;

typedef struct {
    EnregforceIndex tab[8];
} IndexFour;



//Fonction pour inserer dans la liste de "force armée"
void InsertionDansForce(IndexFour *index, int matricule, int force,int age) {

    if (force < 1 || force > 8) {
        printf("Invalid region number.\n");
        return;
    }
    //previous version
     // Inserer_Matricule_Triee(&(index->tab[force-1].TeteListeforce),matricule);
    int *tailleListe = &(index->tab[force-1].taille);
    Inserer_Matricule_Triee(&(index->tab[force-1].TeteListeforce), matricule, tailleListe,age);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LES FONCTIONS DU FICHIER TA2 JONDIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Module de chargement initial d'un fichier T/OF et aussi dans la table d'index
void chargerFichier(char* nomFichier, int N,index *leIndex,IndexSecondaire *IndexRegion,IndexThird *IndexGRADE,IndexFour *IndexFORCE) {
    // indexOthers* leIndex2
    TNOF file;
    bool trouv;
    Tenreg personne;
    caseIndexPrimaire val;
    // caseOthers val2;
    leIndex->taille=0;

    // leIndex2->taille=0;
    printf("\n");
    center_text("-----La creation commence ... ");
    printf("\n");


    int i1;
    Ouvrir(&file, nomFichier, 'N');
    // Aff_Entete(&file,1,1);
    Aff_Entete(&file,1,0);
    Aff_Entete(&file,2,0);

    Buffer buffer;
    buffer.nb=0;
    int i;
    int iFAKE=1;
    int cpt2,cpt3;
    int cout=0;

    for (int k = 0; k < N; ++k) {
        trouv = true;
        while (trouv)
        {
        personne = personnel();
        rechDichoTab(personne.matricule, leIndex->tab, leIndex->taille, &trouv, &i1);
        }
        // // Ajouter la personne au buffer
        buffer.tab[buffer.nb] = personne;

        buffer.nb++;

        // // Ajouter la personne à l'index (leIndex) si elle n'existe pas déjà
        if (!trouv) {
            val = (caseIndexPrimaire){.matricule = personne.matricule, .bloc = iFAKE, .dep = buffer.nb-1};
            insererIndex(val, leIndex->tab, leIndex->taille);
            leIndex->taille++;
            int age = calculerAge(personne.dateNaissance);
            InsertionDansRegion(IndexRegion, personne.matricule, personne.regionMillitaire,age);
            InsertionDansGrade(IndexGRADE, personne.matricule, personne.grade,age);
            InsertionDansForce(IndexFORCE, personne.matricule, personne.forceArmee,age);
            
        }


        if (buffer.nb == MAX) {
            // Si le buffer est plein, écrire dans le fichier
            int numBloc = Alloc_Bloc(&file);
            i=numBloc;
            iFAKE++;
            EcrireDir(&file, numBloc, &buffer);
            cout++;
            buffer.nb = 0;  // Réinitialiser le buffer
        }

        }

    // Écrire les données restantes dans le fichier (si le buffer n'est pas vide)
        if (buffer.nb > 0) {
        int numBloc = Alloc_Bloc(&file);
        EcrireDir(&file, numBloc, &buffer);
        cout++;
        }

    Fermer(&file);
    printf("\n");
    printf("                                            Le cout de cette operation de chargement dans fichier T/OF : %d ecritures .\n",cout);
    printf("                                            Fichier créé avec succès.");
    printf("\n");

}


//Module pour laffichage des informations d'un militaire
void afficherInfo(Tenreg personne) {
        printf("           =========================================\n");
        printf("           ||             Informations              \n");
        printf("           =========================================\n");
        printf("           || Matricule: %d\n", personne.matricule);
        printf("           || Nom: %s\n", personne.nom);
        printf("           || Prénom: %s\n", personne.prenom);
        printf("           || Date de Naissance: %d-%d-%d\n", personne.dateNaissance.jour, personne.dateNaissance.mois, personne.dateNaissance.annee);
        printf("           || Wilaya: %s\n", wilayas[personne.wilaya].nom);
        printf("           || Groupe Sanguin: %s\n", groupesSanguins[personne.groupeSanguin].nom );
        printf("           || Grade: %s\n", grades[personne.grade].nom);
        printf("           || Force Armée: %s\n", forcesArmees[personne.forceArmee].nom);
        printf("           || Région Militaire: %s\n", regionsMilitaires[personne.regionMillitaire].nom );
        printf("           =========================================\n");
}


//Module d'affichage d'un fichier T/OF
void afficherFichier(char* nomFichier) {
    Buffer buffer;
    TNOF file;
    int cout=0;
    Ouvrir(&file, nomFichier, 'A');

    for (int i = 1; i <= TNOF_Entete(&file, 1); ++i) {
        LireDir(&file, i, &buffer);
        cout++;
        int cpt=1;
        for (int j = 0; j < buffer.nb; ++j) {
            Tenreg personne = buffer.tab[j];
            // printf("%d || %d .",i,j);
            afficherInfo(personne);
            cpt++;
        }
    }
    vert();
    printf("           Le cout de cette operation est : %d lectures.\n",cout);
    Fermer(&file);
}


//Module de chargement initial d'un fichier T/OF a partir de N personnes, il charge aussi les tables d'index
void chargementInitial(char *nomFichier,index *leIndex,IndexSecondaire *IndexREGION,IndexThird *IndexGRADE,IndexFour *IndexFORCE)
{
        char nomIndex[25];
    int N,confirm;
    gotoxy(20, 10);
    printf("On va charger un fichier avec N enregistrements,Et puis on le sauvgrade dans un fichier d'index :");
    gotoxy(20, 12);
    printf("--Veuillez entrer le nom du fichier : ");
    scanf("%s", nomFichier);
    gotoxy(20, 14);
    printf("Veuillez entrer le nombre de personnes : ");
    scanf("%d", &N);

    gotoxy(20, 16);
    printf("Veuillez entrer le nom du fichier index a sauvgarder : ");
    scanf("%s", &nomIndex);

    chargerFichier(nomFichier,N,leIndex,IndexREGION,IndexGRADE,IndexFORCE);
    ChargementIndexToDisk(leIndex,nomIndex);
    printf("\n");
    center_text("Voulez vous afficher le fichier? (1 : yes/0 : non) : ");
    scanf("%d", &confirm);
    // gotoxy(20, 10);
    printf("\n");
    if (confirm == 1)
    {
        afficherFichier(nomFichier);
    }
    else{
        gotoxy(20, 20);
        ("OKAY MERCI ! \n");
    }
    


}


//Module d'insertion d'une personne dans un fichier T/OF et aussi dans la table d'index
void insererPersonne(char* nomFichier, Tenreg personne, index *leIndex) {
    TNOF file;
    Tbloc buff;
    bool trouv;
    caseIndexPrimaire val;

    // Open the file in append mode
    Ouvrir(&file, nomFichier, 'A');

    // Search for the person in the index
    int indexPosition;
    rechDichoTab(personne.matricule, leIndex->tab, leIndex->taille, &trouv, &indexPosition);

    // Check if the person already exists
    if (!trouv) {
        // Person doesn't exist, add to the index
        int i=TNOF_Entete(&file,1);
        int j;
        LireDir(&file,i,&buff);
        if (buff.nb < MAX)
        {
            buff.nb++;
            buff.tab[buff.nb-1]=personne;
            j=buff.nb-1;
        }
        else{
            int numBloc = Alloc_Bloc(&file);
            i=numBloc;
            buff.nb=1;
            buff.tab[0]=personne;
            j=0;
            Aff_Entete(&file,1,i);
        }
        EcrireDir(&file,i,&buff);
        val = (caseIndexPrimaire){.matricule = personne.matricule, .bloc = i, .dep = j};
        
        insererIndex(val, leIndex->tab, leIndex->taille);
        leIndex->taille++;

        // Update the file with the new person
       printf("\n");
       gotoxy(17,34);
       vert();
       printf("-----------------Le cout de l'operation est 1 ecriture.-----------------");
       printf("\n");
       gotoxy(17,36);
       vert();
       printf("-----------------insertion avec succes-----------------");
    } else {
        // Person already exists, you can handle this case as needed
        gotoxy(17,34);
        printf("Person with matricule already exists.");
    }

    Fermer(&file);
}


//Module de suppresion d'une personne de fichier T/OF
void Supp_personne(char *fileName, int matricule, index *lind) {
    TNOF File;
    bool trouv = false;
    int i, j, k;
    Tbloc buf1, buf2;
    int cout=0,cout2=0;

    rechDichoTab(matricule, lind->tab, lind->taille, &trouv, &k);
    // printf("apres la rech\n");
    // system("pause");

    
    if (trouv) {
        i = lind->tab[k].bloc;
        j = lind->tab[k].dep;

        Ouvrir(&File, fileName, 'A');
        int N = TNOF_Entete(&File, 1);

        if (i != N) {
            LireDir(&File, i, &buf1);
            LireDir(&File, N, &buf2);
            cout++;
            cout++;

            buf1.tab[j] = buf2.tab[buf2.nb - 1];
            buf2.nb = buf2.nb - 1;

            EcrireDir(&File, i, &buf1);
            cout2++;
            if (buf2.nb > 0) {
                EcrireDir(&File, N, &buf2);
                cout2++;
            } else {
                Aff_Entete(&File, 1, N - 1);
            }
        } else {
            LireDir(&File, N, &buf1);
            cout++;
            buf1.tab[j] = buf1.tab[buf1.nb];
            buf1.nb--;

            if (buf1.nb > 0) {
                EcrireDir(&File, N, &buf1);
                cout2++;
            } else {
                Aff_Entete(&File, 1, N - 1);
            }
        }
        // system("pause");
        suppTabOrd(lind,&lind->taille,k);
        rouget();
        printf("\n              Le Cout de chaque operation est de : %d lectures et %d ecritures\n",cout,cout2);
        rouget();
        printf("\n              Suppresion Avec succées\n");
        Fermer(&File);
    }
    else{
        rouget();
        printf("\n              La personne n'existe pas");
    }
}




//Module de recherche d'un militaire dans un fichier T/OF
void rechercheMilitaire(char* fileName,int matricule,index *lindex,bool *trouv) //doesnt work for now
{
  TNOF file;
  Buffer buff;
  int k;
  printf("\n");
  // system("pause");
  Ouvrir(&file,fileName,'A');

  rechDichoTab(matricule,lindex->tab,lindex->taille,trouv,&k);
  // printf("la matrcicul est : %d et le dep et offset est : %d || %d\n ",matricule,lindex->tab[k].bloc,lindex->tab[k].dep);
  // system("pause");
  
  if (*trouv)
  {
    int i= lindex->tab[k].bloc;
    int j= lindex->tab[k].dep;
    LireDir(&file,i,&buff);
    center_text("la personne existe et ses informations : \n");
    // printf("matrciule : %d -- %d || %d",buff.tab[j].matricule,i,j);
    afficherInfo(buff.tab[j]);

  }
  else{
    center_text("ce soldier n'existe pas\n");
  }
  Fermer(&file);
}


//Module pour chercher toutes les personnes ayant une matricule entre M1 et M2
void  chercher_M1M2(char* fileName,index *leIndex,int M1,int M2)
{
    TNOF File;
    bool trouv = false;
    int z1,z2;
    int i,j;
    Buffer buff;
    int cout=0;

    rechDichoTab(M1, leIndex->tab, leIndex->taille, &trouv, &z1);
    rechDichoTab(M2, leIndex->tab, leIndex->taille, &trouv, &z2);

    Ouvrir(&File,fileName,'A');
    
    int cpt=0;
    
    if (!((z1 == 0) && (z2 == 0)))
    {
    for (int w = z1; w <z2; w++)
    {
    i=leIndex->tab[w].bloc;
    j=leIndex->tab[w].dep;  
    LireDir(&File,i,&buff);
    cout++;
    afficherInfo(buff.tab[j]);
    cpt=w;
    }
    printf("\n");
    printf("           Le cout de l'operation est : %d lectures.\n",cout);
    printf("\n");
    printf("           Le nombre de militaires entre M1 et M2 est : %d\n",cpt);
    }
    Fermer(&File);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
















///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// LES FONCTIONS DE LAFFICHAGE 
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Module pour affichage des matricules dans la table d'index
void afficherMatriculesIndex(index* leIndex) {
    if (leIndex->taille == 0) {
        printf("L'index est vide.\n");
    } else {
        printf("Matricules in the Index:\n");

        for (int i = 0; i < leIndex->taille; ++i) {
            if (i!=0)
            {
            if (leIndex->tab[i].matricule <= leIndex->tab[i-1].matricule){
                break;
            };
            }
            printf("\n  %d .  || Matricule :  %d et position dans le fichier %d,%d ||\n", i + 1, leIndex->tab[i].matricule, leIndex->tab[i].bloc, leIndex->tab[i].dep);
        }

        printf("\n");
    }
}



//AFFICHAGE du contenu d'un buffer
void afficherBuffer(const Buffer* buffer) {
    for (int i = 0; i < buffer->nb; ++i) {
        printf("=========================================\n");
        printf("               Informations              \n");
        printf("=========================================\n");
        printf("|| Matricule: %d\n", buffer->tab[i].matricule);
        printf("|| Nom: %s\n", buffer->tab[i].nom);
        printf("|| Prénom: %s\n", buffer->tab[i].prenom);
        printf("|| Date de Naissance: %d -%d -%d \n", buffer->tab[i].dateNaissance.jour,buffer->tab[i].dateNaissance.mois,buffer->tab[i].dateNaissance.annee);
        printf("|| Wilaya: %d\n", buffer->tab[i].wilaya);
        printf("|| Groupe Sanguin: %d\n", buffer->tab[i].groupeSanguin);
        printf("|| Grade: %d\n", buffer->tab[i].grade);
        printf("|| Force Armée: %d\n", buffer->tab[i].forceArmee);
        printf("|| Région Militaire: %d\n", buffer->tab[i].regionMillitaire);
        printf("=========================================\n");
    }
}



//Module D Affichage du contenu d'un fichier d'index
void DisplayIndexFileContents(char *fileName) {
    fIndex file;
    bufferIndex buffer;
    
    // Open the index file in read mode
    if (Ouvrir_Index(&file, fileName, 'A') != 0) {
        printf("Error opening the index file.\n");
        return;
    }
    // Read and display each block in the index file
    for (int i = 1; i <= fIndex_Entete(&file,1); i++) {
        // Read the block from the index file
        if (LireDir_Index(&file, i, &buffer) != 0) {
            printf("Error reading block %d from the index file.\n", i);
            break;
        }

        // Display the content of the block
        printf("Block %d:\n", i);
        for (int j = 0; j < buffer.NB; j++) {
            printf("%d .Matricule: %d, Bloc: %d, Dep: %d\n",j, buffer.tab[j].matricule, buffer.tab[j].bloc, buffer.tab[j].dep);
        }
        printf("------------------------------\n");
    }

    // Close the index file
    Fermer_Index(&file);
}



//Module d'affichage d'une liste linaire chainée
void printList(char* nomFichier,Pointeur_Matricule head, index *INDEX_PRIM) {
    Pointeur_Matricule current = head;
    bool trouv;
    int num;
    int cpt=0;
    int cout=0;
        vert();
        printf("               Tu veux afficher Toutes les informations (1) ou Matricule+Age(0) ?  (1/0) :");
        while (num != 1 && num !=0)
        {
        scanf("%d",&num);
        }  
        printf("\n");

    system("cls");
    center_text(" XVXVXV ici debut de la fonction recherche militaire XVXVXV\n");
    for (int i = 0; i < 3; i++) {
    delay(500);
    }

    while (current != NULL) {
        if (num==1)
        {
        rechercheMilitaire(nomFichier, Valeur_Matricule(current), INDEX_PRIM,&trouv);
        cout++;
        }
        else{
            printf("           Matricule : %d || Age : %d\n",Valeur_Matricule(current),Valeur_Age(current));
        }
        cpt++;
        current = Suivant_Matricule(current);
        }
    printf("\n           Le cout de l'operation est : %d lectures.", cout);
    printf("\n           Nombre de militaires : %d", cpt);


    printf("\n");
    }



//Module d'affichage d'une liste concu pour les personnes avec memes grades
void printGradeList(char* nomFichier,IndexThird *indexthird, int grade, index *indexPRIMAIRE) {
    // Check if grade is within the valid range
    if (grade < 1 || grade > 19) {
        printf("Invalid region number.\n");
        return;
    }

    printf("                Grade :%d\n ", grade);

    printList(nomFichier,indexthird->tab[grade - 1].TeteListeGRADE, indexPRIMAIRE);
}


//Module d'affichages des matricules des personnes ayant un age entre A1 et A2
void printMatriculesInAgeInterval(char* nomFichier,index *indexPRIMAIRE,Pointeur_Matricule head, int lowerAge, int upperAge) {
    Pointeur_Matricule current = head;
    bool trouv;
    int num;
    int cout=0;
    int cpt=0;
        vert();
        printf("           Tu veux afficher Toutes les informations (1) ou Matricule+Age(0) ?  (1/0) : ");
        while (num != 1 && num !=0)
        {
        scanf("%d",&num);
        }  
        printf("\n");
  system("cls");
  center_text(" XVXVXV ici debut de la fonction recherche militaire XVXVXV\n");
  for (int i = 0; i < 3; i++) {
  delay(500);
  }
    while (current != NULL) {
        // Check if the age is within the specified interval
        if (current->age >= lowerAge && current->age <= upperAge) {
      
        if (num==1)
        {
        rechercheMilitaire(nomFichier, Valeur_Matricule(current),indexPRIMAIRE,&trouv);
        cout++;
        }
        else{
            printf("           Matricule : %d || Age : %d\n",Valeur_Matricule(current),Valeur_Age(current));
        }
        cpt++;
                }
        current = Suivant_Matricule(current);

    }
    printf("\n           Nombre de militaires : %d", cpt);
    printf("\n           Le cout de l'operation est de : %d lectures.", cout);


    printf("\n");
}

// Module pour affichage d'une liste de personnes qui appartient a la meme region et ayant age entre M1 et M2
void printRegionListInAgeInterval(char* nomFichier,index* indexPRIMAIRE,IndexSecondaire *index, int regionNumber, int lowerAge, int upperAge) {
    // Check if regionNumber is within the valid range
    if (regionNumber < 1 || regionNumber > 6) {
        printf("Invalid region number.\n");
        return;
    }
    vert();
    printf("           Region %d (Age Interval %d-%d): \n", regionNumber, lowerAge, upperAge);
    printMatriculesInAgeInterval(nomFichier,indexPRIMAIRE,index->tab[regionNumber - 1].TeteListeRegion, lowerAge, upperAge);
}


//Module de complementaire de suppresion de les personnes d'une liste qui appartient a la meme force
void DeleteForceListByHead(char* fileName,Pointeur_Matricule head,index *INDEX_PRIM) {
    Pointeur_Matricule current = head;
   
    while (current != NULL) {
        // rechercheMilitaire("kray.dat", Valeur_Matricule(current), INDEX_PRIM);
        Supp_personne(fileName,Valeur_Matricule(current),INDEX_PRIM);
        current = Suivant_Matricule(current);
    }

    printf("\n");
}

//Module de suppresion de les personnes d'une liste qui appartient a la meme force

void DeleteForceListByIndex(char* fileName,IndexFour *indexFOUR, int force,index *indexPRIMAIRE) {
    // Check if regionNumber is within the valid range
    
    printf("           Number de personnes dans cette force : %d",indexFOUR->tab[force-1].taille);
    printf("\n           Appuyer sur une touche pour continuer ... ");
    getch();
    if (force < 1 || force > 8) {
        printf("Invalid region number.\n");
        return;
    }
    if (indexFOUR->tab[force-1].taille !=0)
    {
    DeleteForceListByHead(fileName,indexFOUR->tab[force - 1].TeteListeforce, indexPRIMAIRE);
    printf("\n           Toute personne appartenant a la force sont supprimées !!! ");
    }
    else{
    printf("\n           Aucune personne dans cette force"); 
    }
    indexFOUR->tab[force-1].taille=0;
}



//Module pour modification de la region d'une personne donnée par matricule
void ModifierRegionPersonne(char* fileName,index *lindex,int matricule,int newRegion){
    TNOF File;
    bool trouv = false;
    int i, j, k;
    Tbloc buf1;
    int cout=0,cout2=0;

  rechDichoTab(matricule,lindex->tab,lindex->taille,&trouv,&k);

    if (trouv) {
        i = lindex->tab[k].bloc;
        j = lindex->tab[k].dep;

        Ouvrir(&File, fileName, 'A');

            LireDir(&File, i, &buf1);
            cout++;
            buf1.tab[j].regionMillitaire=newRegion;
            EcrireDir(&File, i, &buf1);
            cout2++;
        Fermer(&File);
    }
                        bleut();
                        gotoxy(17,36);
                        printf("Le cout de l'operation est de : %d lectures et %d ecritures ",cout,cout2);
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#endif