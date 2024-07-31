#ifndef TPSFSDGRADE_H_INCLUDED
#define TPSFSDGRADE_H_INCLUDED

#define MAX 1024
#define MAXINDEX 100000
#define MAX_BLOC_INDEX 1024

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <string.h>
#include "Tpsfsd.h"
#include "tpsfsdREGION.h"


//MACHINE ABSTRAITE DUNE LISTE LINAIRE CHAINEEE POUR LES PERSONNES QUI ONT LE MEME GRADE
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
    int taille;
    int grade;
    Pointeur_Matricule TeteListeGRADE; // Utilisation du type Pointeur_Matricule
} EnregGradeIndex;

typedef struct {
    EnregGradeIndex tab[19];
} IndexThird;


//INSERTION DANS LLC DE PERSONNES AVEC MEME GRADE
void InsertionDansGrade(IndexThird *index, int matricule, int grade,int age) {

    if (grade < 1 || grade > 19) {
        printf("Invalid region number.\n");
        return;
    }
    //previous version
     // Inserer_Matricule_Triee(&(index->tab[grade-1].TeteListeGRADE),matricule);
    int *tailleListe = &(index->tab[grade-1].taille);
    Inserer_Matricule_Triee(&(index->tab[grade-1].TeteListeGRADE), matricule, tailleListe,age);

}

#endif