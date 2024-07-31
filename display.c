#include "./display.h"

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#ifdef __linux__
#include <unistd.h>
#else
#include <time.h>
#endif
#endif


// efface une line de l'ecran
void clrline() {
    printf("\e[2K");
    printf("\e[A");
}

// efface les menus de l'ecran
void clrmenu(int length) {
    for (int i = 0; i < length; i++) {
        gotoxy(55, 25+i);
        printf("                                                   ");
    }
}

void entete() {
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\e[7;40m    Date: %02d/%02d/%04d                                    Ecole nationale Superieure d'Informatique (ALGER)                                          TP1 ALSDD    \e[0m", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
}

void pied() {
    printf("\e[7;40m    MAACHI MOHAMED ISLAM AYMEN                                        UNE COLLABORATION EN 2023                                                 ABOUD Ibrahim    \e[0m");
}

// animation d'ecriture des chaines sur l'ecran ( typing-animation )
void strprintAnimate(char* str,int ms) {
#ifdef _WIN32
    // Windows-specific sleep function
    Sleep(ms);
#else
    // Unix/Linux usleep function
    #ifdef _POSIX_C_SOURCE
    usleep(ms * 1000);
    #else
    // Use alternative delay method if usleep is not available
    struct timespec ts = {0, ms * 1000};
    nanosleep(&ts, NULL);
    #endif
#endif

    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
        Sleep(ms);
    }
}

// animation d'entr�e d'erreur
void inErrAnimate(char* str) {
    //printf(" ");
    clrline();
    for (int i = 1; i < 3; i++) {
        printf("\e[91m%s ", str);
        Sleep(100);
        printf("\r");
        printf("  %s", str);
        Sleep(100);
        printf("\r");
    }
    printf("\e[0m%s", str);
}

// un logo anim� personalis� de l'esi, pour le demarrage du programme
void esi_logo() {






    printf("\t\t\t\t\t    ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("             ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("           ");printf("\033[107m");printf("                   \n");
    printf("\033[0m");printf("\t\t\t\t\t  ");printf("\033[104m");printf("                     ");printf("\033[0m");printf("        ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[107m");printf("                     \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("          ");printf("\033[107m");printf("                 \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("          ");printf("\033[0m");printf("                          ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("          ");printf("\033[0m");printf("                           ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("          ");printf("\033[0m");printf("                           ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("           ");printf("\033[0m");printf("                          ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[104m");printf("                   ");printf("\033[0m");printf("                  ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                       ");printf("\033[0m");printf("       ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("               ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                       ");printf("\033[0m");printf("         ");printf("\033[104m");printf("                     ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                      ");printf("\033[0m");printf("            ");printf("\033[104m");printf("                   ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                              ");printf("\033[104m");printf("           ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                               ");printf("\033[104m");printf("          ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("            ");printf("\033[0m");printf("                             ");printf("\033[104m");printf("           ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("       ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("           ");printf("\033[107m");printf("                 \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t  ");printf("\033[104m");printf("                     ");printf("\033[0m");printf("       ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("         ");printf("\033[107m");printf("                     \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t    ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("           ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("             ");printf("\033[107m");printf("                   \n");Sleep(50);
    printf("\033[0m");
}

// meme logo precedant, anim� en inverse, pour la fermeture du programme
void reverse_esi_logo(int y) {
    gotoxy(0, y);
    printf("\t\t\t\t\t    ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("             ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("           ");printf("\033[107m");printf("                   \n");
    printf("\033[0m");printf("\t\t\t\t\t  ");printf("\033[104m");printf("                     ");printf("\033[0m");printf("        ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[107m");printf("                     \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("          ");printf("\033[107m");printf("                 \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("          ");printf("\033[0m");printf("                          ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("          ");printf("\033[0m");printf("                           ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("          ");printf("\033[0m");printf("                           ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[104m");printf("           ");printf("\033[0m");printf("                          ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[104m");printf("                   ");printf("\033[0m");printf("                  ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                       ");printf("\033[0m");printf("       ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("               ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                       ");printf("\033[0m");printf("         ");printf("\033[104m");printf("                     ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("                      ");printf("\033[0m");printf("            ");printf("\033[104m");printf("                   ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                              ");printf("\033[104m");printf("           ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[104m");printf("            ");printf("\033[0m");printf("                               ");printf("\033[104m");printf("          ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("            ");printf("\033[0m");printf("                             ");printf("\033[104m");printf("           ");printf("\033[0m");printf("              ");printf("\033[107m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("       ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("           ");printf("\033[107m");printf("                 \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t  ");printf("\033[104m");printf("                     ");printf("\033[0m");printf("       ");printf("\033[104m");printf("                      ");printf("\033[0m");printf("         ");printf("\033[107m");printf("                     \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t    ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("           ");printf("\033[104m");printf("                 ");printf("\033[0m");printf("             ");printf("\033[107m");printf("                   \n");Sleep(50);
    printf("\033[0m");

    gotoxy(0, y);
    printf("\t\t\t\t\t    ");printf("\033[100m");printf("                 ");printf("\033[0m");printf("             ");printf("\033[100m");printf("                 ");printf("\033[0m");printf("           ");printf("\033[100m");printf("                   \n");
    printf("\033[0m");printf("\t\t\t\t\t  ");printf("\033[100m");printf("                     ");printf("\033[0m");printf("        ");printf("\033[100m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[100m");printf("                     \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[100m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[100m");printf("                      ");printf("\033[0m");printf("          ");printf("\033[100m");printf("                 \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[100m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[100m");printf("          ");printf("\033[0m");printf("                          ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[100m");printf("          ");printf("\033[0m");printf("                           ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[100m");printf("          ");printf("\033[0m");printf("                           ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("            ");printf("\033[0m");printf("                  ");printf("\033[100m");printf("           ");printf("\033[0m");printf("                          ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("                      ");printf("\033[0m");printf("        ");printf("\033[100m");printf("                   ");printf("\033[0m");printf("                  ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("                       ");printf("\033[0m");printf("       ");printf("\033[100m");printf("                      ");printf("\033[0m");printf("               ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("                       ");printf("\033[0m");printf("         ");printf("\033[100m");printf("                     ");printf("\033[0m");printf("              ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("                      ");printf("\033[0m");printf("            ");printf("\033[100m");printf("                   ");printf("\033[0m");printf("              ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("            ");printf("\033[0m");printf("                              ");printf("\033[100m");printf("           ");printf("\033[0m");printf("              ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t");printf("\033[100m");printf("            ");printf("\033[0m");printf("                               ");printf("\033[100m");printf("          ");printf("\033[0m");printf("              ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[100m");printf("            ");printf("\033[0m");printf("                             ");printf("\033[100m");printf("           ");printf("\033[0m");printf("              ");printf("\033[100m");printf("        \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t ");printf("\033[100m");printf("                      ");printf("\033[0m");printf("       ");printf("\033[100m");printf("                      ");printf("\033[0m");printf("           ");printf("\033[100m");printf("                 \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t  ");printf("\033[100m");printf("                     ");printf("\033[0m");printf("       ");printf("\033[100m");printf("                      ");printf("\033[0m");printf("         ");printf("\033[100m");printf("                     \n");Sleep(50);
    printf("\033[0m");printf("\t\t\t\t\t    ");printf("\033[100m");printf("                 ");printf("\033[0m");printf("           ");printf("\033[100m");printf("                 ");printf("\033[0m");printf("             ");printf("\033[100m");printf("                   \n");Sleep(50);
    printf("\033[0m");

    for (int i = 0; i < 17; i++) {
        gotoxy(0, y+i);
        printf("                                                                                                                                                                 ");
        Sleep(60);
    }

}

// logo titre: "gestion de master"
void titre_logo() {

    printf("\t\t\t\t\t              \e[104m      \e[0m  \e[104m       \e[0m \e[104m       \e[0m \e[104m        \e[0m \e[104m  \e[0m  \e[104m      \e[0m  \e[104m   \e[0m    \e[104m  \e[0m  \n");
    printf("\t\t\t\t\t             \e[104m  \e[0m       \e[104m  \e[0m      \e[104m  \e[0m         \e[104m  \e[0m    \e[104m  \e[0m \e[104m  \e[0m    \e[104m  \e[0m \e[104m    \e[0m   \e[104m  \e[0m \n");
    printf("\t\t\t\t\t             \e[104m  \e[0m   \e[104m   \e[0m \e[104m     \e[0m   \e[104m       \e[0m    \e[104m  \e[0m    \e[104m  \e[0m \e[104m  \e[0m    \e[104m  \e[0m \e[104m  \e[0m \e[104m  \e[0m  \e[104m  \e[0m \n");
    printf("\t\t\t\t\t             \e[104m  \e[0m    \e[104m  \e[0m \e[104m  \e[0m           \e[104m  \e[0m    \e[104m  \e[0m    \e[104m  \e[0m \e[104m  \e[0m    \e[104m  \e[0m \e[104m  \e[0m  \e[104m  \e[0m \e[104m  \e[0m \n");
    printf("\t\t\t\t\t              \e[104m      \e[0m  \e[104m       \e[0m \e[104m       \e[0m    \e[104m  \e[0m    \e[104m  \e[0m  \e[104m      \e[0m  \e[104m  \e[0m   \e[104m    \e[0m \n\n\n");
    printf("\t\t\t\t\t    \e[104m       \e[0m  \e[104m       \e[0m     \e[104m   \e[0m    \e[104m   \e[0m  \e[104m     \e[0m  \e[104m       \e[0m \e[104m        \e[0m \e[104m       \e[0m \e[104m      \e[0m \n");
    printf("\t\t\t\t\t    \e[104m   \e[0m   \e[104m  \e[0m \e[104m  \e[0m          \e[104m    \e[0m  \e[104m    \e[0m \e[104m  \e[0m   \e[104m  \e[0m \e[104m  \e[0m         \e[104m  \e[0m    \e[104m  \e[0m      \e[104m  \e[0m   \e[104m  \e[0m \n");
    printf("\t\t\t\t\t    \e[104m   \e[0m   \e[104m  \e[0m \e[104m     \e[0m       \e[104m  \e[0m \e[104m    \e[0m \e[104m  \e[0m \e[104m       \e[0m \e[104m       \e[0m    \e[104m  \e[0m    \e[104m     \e[0m   \e[104m      \e[0m \n");
    printf("\t\t\t\t\t    \e[104m   \e[0m   \e[104m  \e[0m \e[104m  \e[0m          \e[104m  \e[0m  \e[104m  \e[0m  \e[104m  \e[0m \e[104m  \e[0m   \e[104m  \e[0m      \e[104m  \e[0m    \e[104m  \e[0m    \e[104m  \e[0m      \e[104m  \e[0m   \e[104m  \e[0m \n");
    printf("\t\t\t\t\t    \e[104m       \e[0m  \e[104m       \e[0m     \e[104m  \e[0m      \e[104m  \e[0m \e[104m  \e[0m   \e[104m  \e[0m \e[104m       \e[0m    \e[104m  \e[0m    \e[104m       \e[0m \e[104m  \e[0m   \e[104m  \e[0m \n\n");

    printf("_______________________________________________________________________________________________________________________________________________________________");

}

// animation du texte clignotant sur l'ecran
void strprintblink (char* word, int blink_number, int blink_rate) {
    while( (blink_number != 1 )){
        Sleep(blink_rate*10);
        printf("\r");
        printf("\033[1;90m");
        printf("%s",word);

        Sleep(100);
        printf("\r");
        printf("\033[0m");

        printf("%s",word);

        Sleep(100);
        printf("\r");
        printf("\033[1;37m");

        printf("%s",word);

        Sleep(blink_rate*10/2);
        printf("\r");
        printf("\033[0m");

        printf("%s",word);

        Sleep(100);
        printf("\r");
        printf("\033[1;90m");

        printf("%s",word);

        Sleep(100);
        printf("\r");
        for (int i = 1 ; i <= strlen(word); i++) {
            printf(" ");
        }
        blink_number = blink_number - 1 ;
    }
    printf("\033[0m");

}

// meme animation pr�c�dante + l'option de l'arreter suite a une frappe du clavier (keyboard hit)
void strprintblinkkbhit(char* word, int blink_number, int blink_rate) {

    while((!kbhit()) && (blink_number != 1 )){
        Sleep(blink_rate*5);
        printf("\r");
        printf("\033[1;90m");
        printf("%s",word);
        if (kbhit()) {break;}
        Sleep(100);
        printf("\r");
        printf("\033[0m");

        printf("%s",word);
        if (kbhit()) {break;}
        Sleep(100);
        printf("\r");
        printf("\033[1;37m");

        printf("%s",word);
        if (kbhit()) {break;}
        Sleep(blink_rate*10/2);
        printf("\r");
        printf("\033[0m");

        printf("%s",word);
        if (kbhit()) {break;}
        Sleep(100);
        printf("\r");
        printf("\033[1;90m");

        printf("%s",word);
        if (kbhit()) {break;}
        Sleep(100);
        printf("\r");
        for (int i = 1 ; i <= strlen(word); i++) {
            printf(" ");
        }
        blink_number = blink_number - 1 ;
    }
    printf("\033[0m");
}

// page d'introduction du projet
void intro() {
#ifdef _WIN32
    // Windows-specific sleep function
    Sleep(2000);
#else
    // Unix/Linux sleep function
    sleep(2);
#endif

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    strprintblinkkbhit("                                                           MAACHI Mohamed Islam Aymen presente ...                                             ",2,500);
    strprintblinkkbhit("                                                        Sous la supervision du Professeur KERMI Adel                                          ",2,500);
    strprintblinkkbhit("                                                                    Retenez vos souffles !!!                                                       ",2,500);
    Sleep(2000);
}

// fonction tres utilis�e pour deplacer le curseur sur l'ecran


// animation du texte (fade-in)
void fade_in(char* word , int speed_ms, char* space) {
    Sleep(speed_ms);
    printf("\r");
    printf("%s", space);
    printf("\033[1;90m");
    printf("%s",word);
    printf("\t\t\t\t\t\t\t");

    Sleep(100);
    printf("\r");
    printf("%s", space);
    printf("\033[0m");

    printf("%s",word);
    printf("\t\t\t\t\t\t\t");

    Sleep(100);
    printf("\r");
    printf("%s", space);
    printf("\033[1;37m");

    printf("%s",word);
    printf("\t\t\t\t\t\t\t");

    Sleep(speed_ms);
    printf("\r");
    printf("%s", space);
    printf("\033[0m");

    printf("%s",word);
    printf("\t\t\t\t\t\t\t");
}

// animation du text (fade-out)
void fade_out(char* word, int speed_ms) {
        printf("\e[0m");

        printf("%s",word);

        Sleep(200);
        printf("\r");
        printf("\e[1;90m");

        printf("%s",word);

        Sleep(speed_ms);
        printf("\r");
        for (int i = 1 ; i <= strlen(word); i++) {
            printf(" ");
        }
        printf("\e[0m");
}
void loading_page() {
    srand(time(NULL));
    int nombre = rand()%7;                                    // nombre aleatoire entre 0 et 5 pour choisir une astuce aleatoire (ci-dessous)
    char* astuce[10] =  {"                                         Ne vous fatiguez pas a regler la taille de la fenetre, on l'a fait pour vous !",
                         "                                             Sur une echelle de 0 a 10, combien notez-vous cet ecran de chargement ?",
                         "                         Vous pouvez utiliser l'option <Quitter l'application> au lieu du X en haut de la fenetre, c'est plus securisee!",
                         "                                                            Ce TP n'est pas pour les ames sensible !",
                         "                                        Vous pouvez sauter l'introduction du programme en appuyant sur la touche <entrer>",
                         "                                  Saviez vous que notre bibliotheque graphique est constituee de 95% de procedures faites maison !",
                         "                    Ne soyez pas timide, vous pouvez demander a notre moteur de recherche - jury - tous ce que vous voulez !( presque tout )"};


    clrscr();                                                 // mise en page
    printf("\n\n\n");
    esi_logo();
    printf("\n\n\n\n\n\n");
    Sleep(1000);
    for ( int j = 0 ; j <= 100 ; j++) {

        printf("                                                                       Chargement");
        for (int i =1 ; i <= j % 15 ; i=i+5) {                // affichage : "Chargement.", "Chargement..",  "Chargement...", ...
            printf(".");
        }
        for (int i =0 ; i <= 15 - j % 15; i=i+5) {
            printf(" ");
        }

        printf("  %d%%  ",j);
        printf("\n\n");
        printf("                             ____________________________________________________________________________________________________");
        printf("\n                             ");
        printf("\033[107m");
        printf("\033[97m");

        for (int k = 1 ; k <= j ; k++){                       // barre de chargement
            printf("#");
        }
         printf("\033[0m");

        for (int f = 1 ; f <= 100 - j ; f ++) {
            printf("_");
        }
        printf("|");

        printf("\n\n\n\n\n\n");
        printf("\e[93m");
        printf("%s\n",astuce[nombre]);
        printf("\033[0m");

        Sleep(50);
        clrline();
        clrline();
        clrline();
        clrline();
        clrline();
        clrline();
        clrline();
        clrline();
        clrline();
        clrline();
        printf("\033[0m");


    }
    clrline();
    clrline();
    clrline();
    clrline();
    printf("\033[0m");
    printf("\033[93m");
    printf("\n\n\n\n                                                                            TERMIN%c!                                                     ", 144);
    printf("\e[0m");
    Sleep(1000);
}











