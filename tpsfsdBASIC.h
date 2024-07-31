#ifndef TPSFSBASIC_H_INCLUDED
#define TPSFSDBASIC_H_INCLUDED

#define MAX 1024
#define MAXINDEX 100000
#define MAX_BLOC_INDEX 1024

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <conio.h>


//DES MODULES POUR CENTER UN TEXT


void center_text(char* text) {
    int padding = (160 - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) {
        putchar(' ');
    }
    printf("%s", text);
}
void center_textcol(char* text) {
    int padding = (160 - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) {
        putchar(' ');
    }
     printf("\033[37;44m");
    printf("%s", text);
}
void center_textcol2(char* text) {
    int padding = (160 - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) {
        putchar(' ');
    }
     printf("\033[37;41m");
    printf("%s", text);
}
void center_textcol3(char* text) {
    int padding = (160 - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) {
        putchar(' ');
    }
     printf("\033[37;102m");
    printf("%s", text);
}
int up=80,down=72,margin=54;

//DES MODULES DE COULEURS
void bleu(){textbackground(GREEN);}
void vert(){textcolor(GREEN);}
void noire(){textbackground(BLACK);}
void jaunet(){textcolor(BROWN);}
void blanct(){textcolor(WHITE);}
void bleut(){textcolor(BLUE);}
void rouget(){textcolor(RED);}
typedef struct {
    int numero;
    char nom[50];
} Wilaya;

Wilaya wilayas[] = {
        {0,"NULL"},
        {1, "Adrar"},
        {2, "Chlef"},
        {3, "Laghouat"},
        {4, "Oum El Bouaghi"},
        {5, "Batna"},
        {6, "Béjaïa"},
        {7, "Biskra"},
        {8, "Béchar"},
        {9, "Blida"},
        {10, "Bouira"},
        {11, "Tamanrasset"},
        {12, "Tébessa"},
        {13, "Tlemcen"},
        {14, "Tiaret"},
        {15, "Tizi Ouzou"},
        {16, "Alger"},
        {17, "Djelfa"},
        {18, "Jijel"},
        {19, "Sétif"},
        {20, "Saïda"},
        {21, "Skikda"},
        {22, "Sidi Bel Abbès"},
        {23, "Annaba"},
        {24, "Guelma"},
        {25, "Constantine"},
        {26, "Médéa"},
        {27, "Mostaganem"},
        {28, "M'Sila"},
        {29, "Mascara"},
        {30, "Ouargla"},
        {31, "Oran"},
        {32, "El Bayadh"},
        {33, "Illizi"},
        {34, "Bordj Bou Arréridj"},
        {35, "Boumerdès"},
        {36, "El Tarf"},
        {37, "Tindouf"},
        {38, "Tissemsilt"},
        {39, "El Oued"},
        {40, "Khenchela"},
        {41, "Souk Ahras"},
        {42, "Tipaza"},
        {43, "Mila"},
        {44, "Aïn Defla"},
        {45, "Naâma"},
        {46, "Aïn Témouchent"},
        {47, "Ghardaïa"},
        {48, "Relizane"},
        {49, "El M'Ghair"},
        {50, "El Menia"},
        {51, "Ouled Djellal"},
        {52, "Bordj Baji Mokhtar"},
        {53, "In Salah"},
        {54, "In Guezzam"},
        {55, "Timimoun"},
        {56, "Béni Abbès"},
        {57, "Touggourt"},
        {58, "Djanet"}
    };
    typedef struct {
        int numero;
        char nom[50];
    } Grade;
    
    Grade grades[] = {
        {0,"NULL"},
        {1, "Général d'Armée"},
        {2, "Général de corps d’armée"},
        {3, "Général-Major"},
        {4, "Général"},
        {5, "Colonel"},
        {6, "Lieutenant-colonel"},
        {7, "Commandant"},
        {8, "Capitaine"},
        {9, "Lieutenant"},
        {10, "Sous-lieutenant"},
        {11, "Aspirant"},
        {12, "Adjudant-Major"},
        {13, "Adjudant-Chef"},
        {14, "Adjudant"},
        {15, "Sergent-Chef"},
        {16, "Sergent"},
        {17, "Caporal-Chef"},
        {18, "Caporal"},
        {19, "Djoundi"}
    };

    typedef struct {
        int numero;
        char nom[50];
    } ForceArme;


    ForceArme forcesArmees[] = {
        {0,"NULL"},
        {1, "Armée de terre"},
        {2, "Armée de l’air"},
        {3, "Marine nationale"},
        {4, "Défense aérienne du territoire"},
        {5, "Gendarmerie nationale"},
        {6, "Garde républicaine"},
        {7, "Département du renseignement et de la sécurité"},
        {8, "Santé militaire"}
    };

    typedef struct {
    int numero;
    char nom[50];
    } RegionMilitaire;


    RegionMilitaire regionsMilitaires[] = {
        {0,"NULL"},
        {1, "1RM-Blida"},
        {2, "2RM-Oran"},
        {3, "3RM-Béchar"},
        {4, "4RM-Ouargla"},
        {5, "5RM-Constantine"},
        {6, "6RM-Tamanrasset"}
    };
    
    typedef struct {
    int numero;
    char nom[5]; // Le groupe sanguin est représenté par quelques caractères, par exemple "O+", "A-", etc.
    } GroupeSanguin;
    
    GroupeSanguin groupesSanguins[] = {
        {0,"NULL"},
        {1, "O+"},
        {2, "A+"},
        {3, "B+"},
        {4, "O-"},
        {5, "A-"},
        {6, "AB+"},
        {7, "B-"},
        {8, "AB-"}
    };
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*DECLARATION DE LA STRECTURE TNOF*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct date
{
    int jour;
    int mois;
    short int annee;
} date;


typedef struct {
    int matricule;
    char nom[50];
    char prenom[50];
    date dateNaissance;
    int wilaya;
    int groupeSanguin;
    int grade;
    int forceArmee;
    int regionMillitaire;

} Tenreg;

typedef struct {
    Tenreg tab[MAX];
    int nb;
} Tbloc, Buffer;

typedef struct {
    int numBlocs;
    int cmptInsertion;
} Entete;

typedef struct {
    FILE *f;
    Entete entete;
} TNOF;



int matricule()
{
    //il s'agit d'une concatenation de  deux nombre aleatoire entre [111-999]
    return (rand() % (889) + 111) * 1000 + (rand() % (889) + 111);
}

char *nom() {
    int nbCh = rand() % (30 - 4 + 1) + 4;
    char *nom = (char *)malloc((nbCh + 1) * sizeof(char));
    char aleaNombre;
    if (nom)
    {
        //generation d'un caractere alphabitique  aleatoire pour chaque case du mot (nom)
        for (int i = 0; i < nbCh; i++)
        {
            aleaNombre = rand() % (26) + 1;
            nom[i] = aleaNombre + 64; //majuscule
        }
        nom[nbCh] = '\0';
    }
    return nom; // fin de nom
}


char *prenom()
{
    int nbCh = rand() % (30 - 4 + 1) + 4;             // nombre de caractère aléatoire entre [4 - 30]
    char *prenom = (char *)malloc((nbCh + 1) * sizeof(char)); // allocation dynamique du prénom
    char aleaNombre;

    // génération d'une première lettre majuscule
    if (prenom)
    {
        prenom[0] = rand() % (26) + 65; 

        // génération d'un caractère alphabétique aléatoire pour chaque case du prénom
        for (int i = 1; i < nbCh; i++)
        {
            aleaNombre = rand() % (26) + 1;
            prenom[i] = aleaNombre + 96;
        }
        prenom[nbCh] = '\0'; // fin de prenom
    }
    return prenom;
}


// 4- verifier si l'annee est bissextile
char bissextile(short int annee)
{

    if ((annee % 4) == 0)
    {
        if ((annee % 100) == 0)
        {
            if ((annee % 400) == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    };
}

// 6- genere une date de naissance aleatoire d'une personne qui un age entre minAge et maxAge

date dateNaissance()
{
    char jrMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    short int minAnnee = 1942;  // Adjusted minimum birth year
    short int maxAnnee = 2005;  // Adjusted maximum birth year
    char maxJour;
    date dateNaissance;

    dateNaissance.annee = rand() % (maxAnnee - minAnnee + 1) + minAnnee;
    dateNaissance.mois = rand() % 12 + 1;

    if (bissextile(dateNaissance.annee) && (dateNaissance.mois == 2))
    {
        maxJour = 29;
    }
    else
    {
        maxJour = jrMois[dateNaissance.mois - 1];
    }
    dateNaissance.jour = rand() % maxJour + 1;

    return dateNaissance;
}


Tenreg personnel()
{

    Tenreg e1;
    e1.matricule = matricule();
    strcpy(e1.nom, nom()); // Copy the generated name
    strcpy(e1.prenom, prenom()); // Copy the generated prenom
    e1.dateNaissance = dateNaissance();
    e1.wilaya = rand() % (58) + 1;
    e1.groupeSanguin = rand() % (8) + 1;
    e1.grade = rand() % (17) + 1;
    e1.forceArmee = rand() % (8) + 1;
    e1.regionMillitaire = rand() % (6) + 1;

    return e1;
}

int calculerAge(date dateNaissance) {
    // Obtenir la date actuelle
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Calculer l'âge en utilisant la différence entre les années
    int age = tm_info->tm_year + 1900 - dateNaissance.annee;

    // Ajuster l'âge si la date de naissance n'est pas encore passée cette année
    if (tm_info->tm_mon + 1 < dateNaissance.mois ||
        (tm_info->tm_mon + 1 == dateNaissance.mois && tm_info->tm_mday < dateNaissance.jour)) {
        age--;
    }

    return age;
}
Tenreg createRecordFromUserInput() {
    Tenreg newRecord;
  
    // Get user input for each field
    gotoxy(17,16);
    printf("Enter Matricule: ");
    scanf("%d", &newRecord.matricule);
    
    gotoxy(17,18);
    printf("Enter Nom: ");
    scanf("%s", newRecord.nom);
    
    gotoxy(17,20);
    printf("Enter Prenom: ");
    scanf("%s", newRecord.prenom);

    gotoxy(17,22);
    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %hd", &newRecord.dateNaissance.jour, &newRecord.dateNaissance.mois, &newRecord.dateNaissance.annee);
    
    gotoxy(17,24);
    printf("Enter Wilaya (NUMERO DE WILAYA) : ");
    scanf("%d", &newRecord.wilaya);

    gotoxy(17,26);
    printf("Enter Groupe Sanguin (NUMERO DU GROUPE SANGUIN) : ");
    scanf("%d", &newRecord.groupeSanguin);

    gotoxy(17,28);
    printf("Enter Grade (NUMERO DU GRADE) : ");
    scanf("%d", &newRecord.grade);

    gotoxy(17,30);
    printf("Enter Force Armee (NUMERO DE LA FORCE ARMEE) : ");
    scanf("%d", &newRecord.forceArmee);
     
    gotoxy(17,32);
    printf("Enter Region Militaire (NUMERO DE LA REGION MILITAIRE) : ");
    scanf("%d", &newRecord.regionMillitaire);

    return newRecord;
}






#endif