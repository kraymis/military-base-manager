#ifndef MACHINEABSTRAITEFICHIER_H_INCLUDED
#define MACHINEABSTRAITEFICHIER_H_INCLUDED

#define MAX 1024
#define MAXINDEX 100000
#define MAX_BLOC_INDEX 1024

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <string.h>
#include "tpsfsdBASIC.h"

//MACHINE ABSTRAITE DU FICHIER T/OF PRINCIPAL

int Aff_Entete(TNOF *File , int i , int n) {
    if (i == 1){
        (File->entete.numBlocs) = n ;
        fseek(File->f , 0 ,SEEK_SET ) ;
        fwrite(&File->entete.numBlocs ,1 , sizeof(int) , File->f );
    }
    else if (i == 2) {
        (File->entete.cmptInsertion) = n ;
        fseek(File->f , sizeof(int) ,SEEK_SET ) ;
        fwrite(&File->entete.cmptInsertion ,1 , sizeof(int) , File->f );
    }
    else {
        printf("The input is invalid") ;
        return 1 ;
    }
    return 0 ;
}

int Ouvrir(TNOF *File , char fileName[32] ,  char mode ) {
    if (mode != 'A' && mode != 'a' && mode != 'N' && mode != 'n'  )
    {
        printf("Error in accessing mode , try with 'A' for open an exesting file or 'N' for a new one ") ;
        return 1 ;
    }
    else {
        if(mode == 'A' || mode == 'a') {
                (*File).f = fopen(fileName , "rb+") ;
        }
        else if(mode == 'N' || mode == 'n') {
            (*File).f = fopen(fileName , "wb") ;
            Aff_Entete(File , 1 , 1) ;
            Aff_Entete(File , 2 , 1) ;
        }
    }
    if ((*File).f == NULL){
        printf("Error in opening the file") ;
        return 1 ;
    }
    // printf("File opned successfully\n");
    return 0 ;
}


int Fermer (TNOF *File) {
    fclose(File->f) ;
}

int LireDir(TNOF *File , int numBloc , Buffer *buf) {
    fseek( File->f , sizeof(File->entete)+sizeof(Tbloc)*(numBloc-1) , SEEK_SET ) ;
    fread(buf, sizeof(Tbloc), 1, File->f);
    fflush(File->f) ;
    return 0 ;
}

int EcrireDir(TNOF *File , int numBloc , Buffer *buf ) {
    fseek(File->f , sizeof(File->entete)+sizeof(Tbloc)*(numBloc-1) , SEEK_SET ) ;
    fwrite(buf, sizeof(Tbloc), 1, File->f);
    fflush(File->f) ;
    return 0 ;
}

int TNOF_Entete(TNOF *File ,int i) {
    if (i == 1) {
        fseek(File->f , 0 ,SEEK_SET ) ;
        fread(&File->entete.numBlocs, sizeof(int), 1, File->f);
        return File->entete.numBlocs ;
}
    else if (i == 2) {
        fseek(File->f , sizeof(int) ,SEEK_SET ) ;
        fread(&File->entete.cmptInsertion, sizeof(int), 1, File->f);
        return File->entete.cmptInsertion ;
    }
    else {
        printf("The input is invalid") ;
        return 0 ;
    }
}


int Alloc_Bloc(TNOF *File) {
    int numLastBloc = TNOF_Entete( File , 1) + 1 ;
    Aff_Entete(File , 1 , numLastBloc) ;
    return numLastBloc ;

}

void TNOF_Init(char* fileName)
{
    TNOF File;
    Ouvrir(&File,fileName,'N');
    Aff_Entete(&File,1,0);
    Aff_Entete(&File,2,0);
    Fermer(&File);

}

#endif
