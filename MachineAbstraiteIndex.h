#ifndef MACHINEABSTRAITEINDEX_H_INCLUDED
#define MACHINEABSTRAITEINDEX_H_INCLUDED

#define MAX 1024
#define MAXINDEX 100000
#define MAX_BLOC_INDEX 1024

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <string.h>

typedef struct
{
    int matricule;
    int bloc;
    int dep;

} caseIndexPrimaire;

typedef struct
{
    caseIndexPrimaire tab[MAXINDEX];
    int taille;

} index;

typedef struct {
    caseIndexPrimaire tab[MAX_BLOC_INDEX];
    int NB;
} tBlocIndex, bufferIndex;


typedef struct iEntete {
    int nbBloc;
} iEntete;

typedef struct fIndex {
    FILE *f;
    iEntete entete;
} fIndex;
///////////////////////////////////////////////////////////////////////////////
// INDEX DEUUUUUUUUUUUUUUUUXIEME 
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// MACHINE ABSTRAITE DE LINDEX
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int EcrireDir_Index(fIndex *File, int numBloc, tBlocIndex *buf) {
    fseek(File->f, sizeof(File->entete) + sizeof(tBlocIndex) * (numBloc - 1), SEEK_SET);
    fwrite(buf, sizeof(tBlocIndex), 1, File->f);
    fflush(File->f);
    return 0;
}
int LireDir_Index(fIndex *File, int numBloc, bufferIndex *buf) {
    fseek(File->f, sizeof(File->entete) + sizeof(tBlocIndex) * (numBloc - 1), SEEK_SET);
    fread(buf, sizeof(tBlocIndex), 1, File->f);
    fflush(File->f);
    return 0;
}

void Aff_Entete_Index(fIndex *fi, int n) {
        (fi->entete.nbBloc) = n;
        fseek(fi->f, 0, SEEK_SET);
        fwrite(&fi->entete.nbBloc, 1, sizeof(int), fi->f);
}


int Ouvrir_Index(fIndex *fii, char fileName[32], char mode) {
    if (mode != 'A' && mode != 'a' && mode != 'N' && mode != 'n') {
        printf("Error in accessing mode, try with 'A' for open an existing file or 'N' for a new one ");
        return 1;
    } else {
        if (mode == 'A' || mode == 'a') {
            (*fii).f = fopen(fileName, "rb+");
        } else if (mode == 'N' || mode == 'n') {
            (*fii).f = fopen(fileName, "wb");
            if (fii->f != NULL) {
                Aff_Entete_Index(fii,0);
            }
        }
    }
    
    if ((*fii).f == NULL) {
        printf("Error in opening the file");
        return 1;
    }

    // printf("File opened successfully\n");
    return 0;
}



int Fermer_Index(fIndex *File) {
    fclose(File->f) ;

}
int fIndex_Entete(fIndex *File, int i) {
        fseek(File->f, 0, SEEK_SET);
        fread(&File->entete.nbBloc, sizeof(int), 1, File->f);
        return File->entete.nbBloc;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         INDEX STUFF  ////////////////////////://///////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void indexTOzero(index *ind) {
    ind->taille = 0;  // Set the integer to zero
    memset(ind->tab, 0, sizeof(ind->tab));  // Set all elements of the array to zero
}


//Fonction de recherche dichotomique dans la tabel d'index
void rechDichoTab(int valeur, caseIndexPrimaire *tab, int taille, bool *trouv, int *k)
{
    int bi = 0, bs = taille - 1;
    *trouv = false;

    while (bi <= bs && !(*trouv))
    {
        *k = (bi + bs) / 2;

        if (tab[*k].matricule == valeur)
        {
            *trouv = true;
        }
        else if (valeur < tab[*k].matricule)
        {
            bs = *k - 1;
        }
        else
        {
            bi = *k + 1;
        }
    }

    if (!(*trouv))
    {
        *k = bi;
    }

}


//Fonction pour inserer une valeur dans une table d'index
void insererIndex(caseIndexPrimaire valeur, caseIndexPrimaire *tab, int taille)
{

    char stop = 0;
    int k = taille - 1;

    while (k >= 0 && !stop)
    {
        if (valeur.matricule < tab[k].matricule)
        {
            tab[k + 1] = (caseIndexPrimaire){.matricule = tab[k].matricule, .bloc = tab[k].bloc, .dep = tab[k].dep};
            k = k - 1;
        }
        else
        {
            tab[k + 1] = (caseIndexPrimaire){.matricule = valeur.matricule, .bloc = valeur.bloc, .dep = valeur.dep};
            stop = 1;
        }
    }
    if (!stop)
    {
        tab[0] = (caseIndexPrimaire){.matricule = valeur.matricule, .bloc = valeur.bloc, .dep = valeur.dep};
    }
}


// 3- une supression par decalage d'une position dans un tableau ordonne (table d'index)
void suppTabOrd(index *ind, int *taille, int pos)
{
    while (pos < *taille - 1)
    {
        ind->tab[pos] = ind->tab[pos + 1];
        pos++;
    }
    (*taille)--;
}


//Fonction pour chargement de la table d'index dans un fichier TOF d'index
void ChargementIndexToDisk(index *ind, char *nomFichier) {
    // printf("la taille d'index est : %d",ind->taille);
    tBlocIndex buffInd;
    fIndex ifichier;
    buffInd.NB=0;
    int cout=0;

    int i = 1, j = 0;
    int k = 0;
    Ouvrir_Index(&ifichier, nomFichier, 'N');

    while (k < (*ind).taille) {
        if (j < MAX_BLOC_INDEX) {
            buffInd.tab[j]=ind->tab[k];
            j++;
        } 
        else
        {
            buffInd.NB = j;
            EcrireDir_Index(&ifichier, i, &buffInd);
            cout++;
            i++;
            buffInd.tab[0]=ind->tab[k];
            j = 1;
        }
    k++;
    }

    buffInd.NB = j;
    EcrireDir_Index(&ifichier, i, &buffInd);
    cout++;
    Aff_Entete_Index(&ifichier, i);
    vert();
    printf("\n");
    printf("                                            Le cout de operation de chargement dans fichier index est : %d ecritures\n",cout);
    Fermer_Index(&ifichier);
}




// Fonction pour Chargement de l'index depuis le disk dur
void ChargementIndexFromDisk(index *ind, char *nomFichier) {
    tBlocIndex buffInd;
    fIndex ifichier;
    int i = 1, j = 0;
    int cout=0;
    
    Ouvrir_Index(&ifichier, nomFichier, 'A'); // Open the file in read mode
        int taille=0;
        for (int i = 1; i <= fIndex_Entete(&ifichier,1); i++) {
        // Read the block from the index file
        if (LireDir_Index(&ifichier, i, &buffInd) != 0) {
            printf("Error reading block %d from the index file.\n", i);
            break;
        }
        cout++;
        // Display the content of the block
        // printf("Block %d:\n", i);
        for (int j = 0; j < buffInd.NB; j++) {
            ind->tab[taille] = buffInd.tab[j];
            taille++;
        }
        // printf("------------------------------\n");
    }

    ind->taille = taille; // Update the size of the index
    gotoxy(17, 18);
    vert();
    printf("Le cout de l'operation est de : %d lectures\n",cout);
    gotoxy(17, 20);
    vert();
    printf("Chargement avec succées\n");
    gotoxy(17, 22);
    printf("\nAppuyer sur une touche pour continuer ... ");
    getch();
    Fermer_Index(&ifichier);
}


#endif