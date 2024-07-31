#ifndef TPSFSDREGION_H_INCLUDED
#define TPSFSDREGION_H_INCLUDED

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

typedef struct Maillon_Matricule *Pointeur_Matricule;

typedef struct Maillon_Matricule {
    int age;
    int matricule;
    struct Maillon_Matricule *Suiv;
} Maillon_Matricule;




//MACHINE ABSTRAITE DUNE LISTE LINAIRE CHAINEEE POUR LES PERSONNES QUI APPARTIENT A LA MEME REGION
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void Allouer_Matricule(Pointeur_Matricule *P) {
    *P = (Pointeur_Matricule)malloc(sizeof(Maillon_Matricule));
    if (*P == NULL) {
        printf("Erreur d'allocation de memoire.\n");
        exit(1);
    }
}

void Liberer_Matricule(Pointeur_Matricule P) {
    free(P);
}

Pointeur_Matricule Suivant_Matricule(Pointeur_Matricule P) {
    return P->Suiv;
}

int Valeur_Matricule(Pointeur_Matricule P) {
    return P->matricule;
}
int Valeur_Age(Pointeur_Matricule P) {
    return P->age;
}
void Aff_Val_Matricule(Pointeur_Matricule P, int matricule) {
    P->matricule = matricule;
}

void Aff_Suiv_Matricule(Pointeur_Matricule P, Pointeur_Matricule Q) {
    P->Suiv = Q;
}

void Inserer_Matricule_Triee(Pointeur_Matricule *liste, int nouveauMatricule, int *tailleListe,int age) {
    Pointeur_Matricule nouveauMaillon, courant, precedent;

    // Allouer un nouveau maillon
    Allouer_Matricule(&nouveauMaillon);
    Aff_Val_Matricule(nouveauMaillon, nouveauMatricule);
    nouveauMaillon->age = age;
    // Cas où la liste est vide ou le nouveau matricule est inférieur au premier matricule
    if (*liste == NULL || Valeur_Matricule(*liste) > nouveauMatricule) {
        Aff_Suiv_Matricule(nouveauMaillon, *liste);
        *liste = nouveauMaillon;
        (*tailleListe)++;
        return;
    }

    // Recherche de l'endroit où insérer le nouveau maillon
    precedent = NULL;
    courant = *liste;
    while (courant != NULL && Valeur_Matricule(courant) < nouveauMatricule) {
        precedent = courant;
        courant = Suivant_Matricule(courant);
    }

    // Insertion du nouveau maillon
    Aff_Suiv_Matricule(nouveauMaillon, courant);
    Aff_Suiv_Matricule(precedent, nouveauMaillon);
    (*tailleListe)++;

}


typedef struct {
    int taille;
    int regionMilitaire;
    Pointeur_Matricule TeteListeRegion; // Utilisation du type Pointeur_Matricule
} EnregRegionIndex;

typedef struct {
    EnregRegionIndex tab[6];
} IndexSecondaire;


void InsertionDansRegion(IndexSecondaire *index, int matricule, int regionNumber,int age) {

    if (regionNumber < 1 || regionNumber > 6) {
        printf("Invalid region number.\n");
        return;
    }
    //previous version
     // Inserer_Matricule_Triee(&(index->tab[regionNumber-1].TeteListeRegion),matricule);
    int *tailleListe = &(index->tab[regionNumber-1].taille);
    Inserer_Matricule_Triee(&(index->tab[regionNumber-1].TeteListeRegion), matricule, tailleListe,age);

}




#endif